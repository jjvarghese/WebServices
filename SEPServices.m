//
//  SEPServices.m
//
//
//  Created by Joshua J Varghese on 11/02/2016.
//  Copyright © 2016 Joshua J Varghese. All rights reserved.
//

#import "SEPServices.h"
#import "SEPDefinitions.h"
#import "SEPInternalServices.h"
#import "SEPError.h"
#import "SVProgressHUD.h"

const char * kSEPServices_backgroundQueue = "com.sep.au.background";

@interface SEPServices ()

@property (strong, nonatomic) NSOperationQueue *SEPOperationQueue;

@end

@implementation SEPServices

#pragma mark -
#pragma mark PUBLIC
#pragma mark -

+ (void)performSEPOperation:(SEPOperationType)type
                 parameters:(NSMutableDictionary *)params
                withSuccess:(void (^)(id responseDict, BOOL success))response {
    __block NSMutableDictionary *_params = params;
    
    if (![SEPInternalServices isSilentOperation:type]) {
        [SVProgressHUD show];
    }
    
    dispatch_async(dispatch_queue_create(kSEPServices_backgroundQueue, NULL), ^{
        _params = [SEPInternalServices addInternalParams:params forType:type];
        
        NSString *operationType = [SEPInternalServices getOperationType:type];
        
        if ([operationType isEqualToString:kSEPServices_unknown_operation]) {
            NSLog(@"[SEPServices] ERROR: SEPOperationType [%@] is not defined as a valid SEP Operation. Check SEPOperations.h", operationType);
            
            if (![SEPInternalServices isSilentOperation:type]) {
                [SEPInternalServices displayGenericError];
            }
            
            return;
        }
        
        NSLog(@"[SEPServices] Now performing SEP Web Service operation <%@>", operationType);
        
        NSURLRequest *theRequest = [self generateJSONURLRequest:operationType
                                                         params:[self generateJSONForDictionary:_params]];
        
        [NSURLConnection sendAsynchronousRequest:theRequest
                                           queue:[NSOperationQueue mainQueue]
                               completionHandler:^(NSURLResponse *urlResponse,
                                                    NSData *data, NSError *connectionError) {
                                   if (data.length > 0 && connectionError == nil) {
                                       NSDictionary *rootObject = [NSJSONSerialization JSONObjectWithData:data
                                                                                                  options:NSJSONReadingAllowFragments
                                                                                                    error:nil];
                                       
                                       NSData *objectData = [[rootObject objectForKey:@"d"] dataUsingEncoding:NSUTF8StringEncoding];
                                       
                                       NSDictionary *responseDict = [[NSDictionary alloc] init];
                                       
                                       if (objectData) {
                                           responseDict = [NSJSONSerialization JSONObjectWithData:objectData
                                                                                          options:NSJSONReadingAllowFragments
                                                                                            error:nil];
                                       } else {
                                           NSLog(@"[SEPServices] ERROR: No data returned from URL connection. URL Response: %@", urlResponse);
                                           
                                           if (![SEPInternalServices isSilentOperation:type]) {
                                               [SEPInternalServices displayGenericError];
                                           }
                                       }
                                       
                                       BOOL success = NO;
                                       
                                       if (responseDict.count > 0) {
                                           if ([responseDict isKindOfClass:[NSDictionary class]]) {
                                               if ([[responseDict objectForKey:@"IsSuccess"] boolValue]) {
                                                   success = YES;
                                               } else {
                                                   if (![SEPInternalServices isSilentOperation:type]) {
                                                       [SEPError showServerError:responseDict];
                                                   }
                                               }
                                           } else {
                                               success = YES;
                                           }
                                       }
                                       
                                       success = ((NSHTTPURLResponse *) urlResponse).statusCode == 200;
                                       
                                       dispatch_async(dispatch_get_main_queue(), ^{
                                           [SVProgressHUD dismiss];

                                           response (responseDict, success);
                                       });
                                   } else {
                                       NSLog(@"[SEPServices] ERROR returned from URL connection: %@", [connectionError localizedDescription]);
                                       
                                       dispatch_async(dispatch_get_main_queue(), ^{
                                           [SVProgressHUD dismiss];
                                           
                                           if (![SEPInternalServices isSilentOperation:type]) {
                                               [SEPInternalServices displayGenericError];
                                           }
                                           
                                       });
                                       
                                       return;
                                   }
                               }];
    });
}

#pragma mark -
#pragma mark INTERNAL
#pragma mark -

/*!
 * Singleton constructor for initialising the SEP Services operation queue.
 * @return Internally accessible singleton
 */
+ (SEPServices *)sharedInstance {
    static dispatch_once_t p = 0;
    
    __strong static SEPServices *_sharedObject = nil;
    
    dispatch_once(&p, ^{
        _sharedObject = [[self alloc] init];
        _sharedObject.SEPOperationQueue = [[NSOperationQueue alloc] init];
        _sharedObject.SEPOperationQueue.name = @"com.SEP.au.services";
    });
    
    return _sharedObject;
}

/*!
 * Generates the URL Request for the web service call.
 * @param type      The name of the SEP web service call.
 * @param params    The dictionary of parameters to pass into the SEP call.
 * @return          The URL request for the SEP web service call, set up and ready to use.
 */
+ (NSMutableURLRequest *)generateJSONURLRequest:(NSString *)type
                                         params:(NSString *)params {
    NSMutableURLRequest *theRequest = [[NSMutableURLRequest alloc] init];
    
    [theRequest setURL:[NSURL URLWithString:[WEB_SERVICE_URL stringByAppendingString:[NSString stringWithFormat:@"phoneapp4JSON.asmx/%@", type]]]];
    
    NSString *msgLength = [NSString stringWithFormat:@"%lu", (unsigned long)[params length]];
    
    [theRequest addValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [theRequest setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [theRequest addValue:msgLength forHTTPHeaderField:@"Content-Length"];
    [theRequest setHTTPMethod:@"POST"];
    [theRequest setHTTPBody:[params dataUsingEncoding:NSUTF8StringEncoding]];
    [theRequest setTimeoutInterval:kTimeoutInterval];
    
    return theRequest;
}

/*!
 * Serialises a dictionary of parameters into a JSON formatted string.
 * @param params    The dictionary of parameters to be serialised.
 * @return          JSON formatted string.
 */
+ (NSString *)generateJSONForDictionary:(NSDictionary *)params {
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params
                                                       options:NSJSONWritingPrettyPrinted
                                                         error:&error];
    if (!jsonData) {
        NSLog(@"[SEPServices] - ERROR GENERATING JSON PARAMS: [%@]", error);
        
        return @"";
    } else {
        NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        NSLog(@"[SEPServices] - JSON input parameters: %@", jsonString);
        return jsonString;
    }
}

@end
