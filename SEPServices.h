//
//  SEPServices.h
//  
//
//  Created by Joshua J Varghese on 11/02/2016.
//  Copyright © 2016 Joshua J Varghese. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SEPParameters.h"
#import "SEPOperations.h"

static NSTimeInterval const kTimeoutInterval = 15;

/* 
 * This is the primary SEP web services class to call upon from the app.
 * Use its solitary public method, performSEPOperation, for all SEP web service calls.
 */

@interface SEPServices : NSObject

/*!
 * Performs a JSON input/output SEP Web Service call of specified SEPOperationType
 * @see https://ci.SEP.com.au:55556/exo/phoneapp4.asmx for an overview of available methods.
 * @param SEPOperationType  An SEPOperationType declared in SEPOperations.h
 * @param params (optional) The dictionary of parameters to pass into the SEP call. Key names defined as kSEPServices_xxx_param_xxx in SEPParameters.h. If there are no public parameters associated with the call, you can pass in nil here.
 * @param withSuccess       The asynchronous return block that signals the call has completed. Contains a dictionary of the server's response and a boolean indicating whether the call was successful or not.
 */
+ (void)performSEPOperation:(SEPOperationType)SEPOperationType
                 parameters:(NSDictionary *)params
                withSuccess:(void (^)(id responseDict, BOOL success))response;

@end
