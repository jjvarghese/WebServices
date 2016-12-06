//
//  SEPInternalServices
//  
//
//  Created by Joshua J Varghese on 17/02/2016.
//  Copyright © 2016 Joshua J Varghese. All rights reserved.
//

#import "SEPInternalServices.h"
#import "SEPParameters.h"
#import "SEPParametersInternal.h"
#import "SEPCore.h"
#import "SEPDefinitions.h" 
#import "SEPAuthenticator.h"
#import <Security/Security.h>

@implementation SEPInternalServices

#pragma mark -
#pragma mark Public
#pragma mark -

+ (NSString *)getOperationType:(SEPOperationType)type {
    switch (type) {
        case SEPOperationTypeRegister2:
            return @"Register2";
        case SEPOperationTypeGetAuthDetailsForUser:
            return @"GetAuthDetailsForUser";
        case SEPOperationTypeGetRegistrationDetails:
            return @"GetRegistrationDetails";
        case SEPOperationTypeVerifyLogin2:
            return @"VerifyLogin2";
        case SEPOperationTypeVerifyLoginByAuthToken:
            return @"VerifyLoginByAuthToken";
        case SEPOperationTypeForgotPassword2:
            return @"ForgotPassword2";
        case SEPOperationTypeUpdateDetails:
            return @"UpdateDetails";
        case SEPOperationTypeUpdateGPSLocation3:
            return @"UpdateGPSLocation3";
        case SEPOperationTypeAddMyGroups:
            return @"AddMyGroups";
        case SEPOperationTypeGetGroupsList:
            return @"GetGroupsList";
        case SEPOperationTypeRemoveMyGroups:
            return @"RemoveMyGroups";
        case SEPOperationTypeGetGroupsListLite:
            return @"GetGroupsListLite";
        case SEPOperationTypeGetAlertsList:
            return @"GetAlertsList";
        case SEPOperationTypeAddUpdateLocation:
            return @"AddUpdateLocation";
        case SEPOperationTypeGetAlertsListWithDistances:
            return @"GetAlertsListWithDistances";
        case SEPOperationTypeGetLocations:
            return @"GetLocations";
        case SEPOperationTypeRemoveLocation:
            return @"RemoveLocation";
        case SEPOperationTypeVerifyLoginByAuthToken4:
            return @"VerifyLoginByAuthToken4";
        case SEPOperationTypeGetAlertContent:
            return @"GetAlertContent";
        case SEPOperationTypeDeleteAlerts:
            return @"DeleteAlerts";
        case SEPOperationTypeUploadImageEncoded:
            return @"UploadImageEncoded";
        case SEPOperationTypeSetCheckIn:
            return @"SetCheckin";
        case SEPOperationTypeUploadVideoEncoded:
            return @"UploadVideoEncoded";
        case SEPOperationTypeGetEmergencyDirectoryForApp:
            return @"GetEmergencyDirectoryForApp";
        case SEPOperationTypeUploadComment:
            return @"UploadComment";
        case SEPOperationTypeCheckAppGroupCode:
            return @"CheckAppGroupCode";
        case SEPOperationTypeApplyAppGroupCode:
            return @"ApplyAppGroupCode";
        case SEPOperationTypeCheckStatus:
            return @"CheckStatus";
        case SEPOperationTypeGetSEQCurrentDamLevels:
            return @"GetSEQCurrentDamLevels";
        case SEPOperationTypeGetAuthDetailsForUser2:
            return @"GetAuthDetailsForUser2";
        case SEPOperationTypeAddUpdateLocation2:
            return @"AddUpdateLocation2";
        case SEPOperationTypeGetLocationTypes:
            return @"GetLocationTypes";
        default:
            return kSEPServices_unknown_operation;
    }
}

+ (id)retrieveAssignedValueForKey:(NSString * const)key {
    if ([key isEqualToString:kSEPServices_internal_param_appId]) {
        return [self getAppId];
    } else if ([key isEqualToString:kSEPServices_internal_param_regoKey]) {
        return [SEPCore getCurrentUser].userRegoKey;
    } else if ([key isEqualToString:kSEPServices_internal_param_installationId]) {
        return [SEPCore getCurrentUser].userInstallationId;
    } else if ([key isEqualToString:kSEPServices_internal_param_authToken]) {
        NSString *authToken = [SEPAuthenticator getAuthTokenFromKeychain];
        
        if (authToken.length == 0) {
            NSLog(@"[SEPInternalServices] authentication Token unable to be obtained. Logging out.");
            
            [SEPError showSEPErrorForErrorType:SEPErrorTypeTokenFailed];
            
            [SEPAuthenticator logout];
        }
        
        return authToken;
    } else if ([key isEqualToString:kSEPServices_internal_param_deviceId]) {
        return [SEPCore getDeviceUniqueIdentifier];
    } else if ([key isEqualToString:kSEPServices_internal_param_deviceBytes]) {
        return [SEPCore getDeviceBytes];
    } else if ([key isEqualToString:kSEPServices_internal_param_mobileNumber]) {
        return [SEPCore getCurrentUser].userMobileNumber;
    } else if ([key isEqualToString:kSEPServices_internal_param_appVersion]) {
        return [self getAppVersion];
    } else if ([key isEqualToString:kSEPServices_internal_param_handset]) {
        return [self getHandset];
    } else if ([key isEqualToString:kSEPServices_internal_param_osVersion]) {
        return [self getOsVersion];
    } else if ([key isEqualToString:kSEPServices_internal_param_supportEmail]) {
        return SUPPORT_EMAIL;
    } else if ([key isEqualToString:kSEPServices_internal_param_regoLocationKey]) {
        return @"0";
    } else if ([key isEqualToString:kSEPServices_internal_param_alertGroupKey]) {
        return @"0";
    } else if ([key isEqualToString:kSEPServices_internal_param_startRow]) {
        return @"0";
    } else if ([key isEqualToString:kSEPServices_internal_param_endRow]) {
        return @"100";
    } else {
        return nil;
    }
}

+ (NSMutableDictionary *)attachAssignedInternalParameters:(NSArray *)parameterValuesToRetrieve
                                           toExistingParams:(NSMutableDictionary *)params {
    for (NSString *parameter in parameterValuesToRetrieve) {
        if (![params objectForKey:parameter]) {
            NSString *value = [SEPInternalServices retrieveAssignedValueForKey:parameter];
            
            if (value) {
                [params setObject:value forKey:parameter];
            } else {
                NSLog(@"[SEPInternalServices] Error: [%@] was nil and couldn't be passed as a parameter.", parameter);
            }
        }
    }
    
    return params;
}

+ (NSArray *)retrieveInternalParametersForOperationType:(SEPOperationType)type {
    switch (type) {
        case SEPOperationTypeGetGroupsList:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_installationId];
        case SEPOperationTypeRemoveLocation:
        case SEPOperationTypeAddUpdateLocation:
        case SEPOperationTypeAddUpdateLocation2:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_installationId,
                     kSEPServices_internal_param_regoKey];
        case SEPOperationTypeDeleteAlerts:
            return @[kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_installationId];
        case SEPOperationTypeUpdateDetails:
        case SEPOperationTypeGetAlertContent:
        case SEPOperationTypeGetRegistrationDetails:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_installationId];
        case SEPOperationTypeRegister2:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_deviceId,
                     kSEPServices_internal_param_deviceBytes];
        case SEPOperationTypeForgotPassword2:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_supportEmail];
        case SEPOperationTypeUpdateGPSLocation3:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_deviceId,
                     kSEPServices_internal_param_deviceBytes,
                     kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_mobileNumber,
                     kSEPServices_internal_param_installationId,
                     kSEPServices_internal_param_osVersion,
                     kSEPServices_internal_param_appVersion,
                     kSEPServices_internal_param_handset];
        case SEPOperationTypeVerifyLoginByAuthToken:
        case SEPOperationTypeVerifyLoginByAuthToken4:
            return @[kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_deviceBytes,
                     kSEPServices_internal_param_deviceId,
                     kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_osVersion,
                     kSEPServices_internal_param_appVersion,
                     kSEPServices_internal_param_handset];
        case SEPOperationTypeGetAlertsList:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_installationId,
                     kSEPServices_internal_param_startRow,
                     kSEPServices_internal_param_endRow];
        case SEPOperationTypeGetLocations:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_regoLocationKey,
                     kSEPServices_internal_param_installationId,
                     kSEPServices_internal_param_regoKey];
        case SEPOperationTypeGetAlertsListWithDistances:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_alertGroupKey,
                     kSEPServices_internal_param_startRow,
                     kSEPServices_internal_param_endRow,
                     kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_installationId,
                     kSEPServices_internal_param_regoKey];
        case SEPOperationTypeGetGroupsListLite:
        case SEPOperationTypeRemoveMyGroups:
        case SEPOperationTypeAddMyGroups:
        case SEPOperationTypeUploadComment:
        case SEPOperationTypeUploadVideoEncoded:
        case SEPOperationTypeApplyAppGroupCode:
        case SEPOperationTypeCheckStatus:
            return @[kSEPServices_internal_param_appId,
                     kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_regoKey];
        case SEPOperationTypeUploadImageEncoded:
            return @[kSEPServices_internal_param_authToken,
                     kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_installationId,
                     kSEPServices_internal_param_appId];
        case SEPOperationTypeGetEmergencyDirectoryForApp:
        case SEPOperationTypeSetCheckIn:
            return @[kSEPServices_internal_param_regoKey,
                     kSEPServices_internal_param_appId];
        case SEPOperationTypeCheckAppGroupCode:
        case SEPOperationTypeGetAuthDetailsForUser2:
        case SEPOperationTypeGetLocationTypes:
            return @[kSEPServices_internal_param_appId];
        case SEPOperationTypeVerifyLogin2:
        default:
            return @[];
    }
}

+ (NSMutableDictionary *)addInternalParams:(NSMutableDictionary *)params forType:(SEPOperationType)type {
    if (!params) {
        params = [[NSMutableDictionary alloc] init];
    }
    
    return [self attachAssignedInternalParameters:[self retrieveInternalParametersForOperationType:type]
                                 toExistingParams:params];
}

+ (void)displayGenericError {
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Oops!"
                                                            message:[NSString stringWithFormat:@"Something went wrong. If the problem persists, please contact %@", SUPPORT_EMAIL]
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil, nil];
        
        [alertView show];
    });
}

#pragma mark -
#pragma mark Private
#pragma mark -

/*!
 * @discussion Add the parameter to the dictionary unless the parameter already exists
 * @param params    The existing dictionary of parameters
 * @param key       The key of the parameter to be added
 * @param value     The value of the parameter to be added
 */
+ (void)addParamUnlessOverridden:(NSMutableDictionary *)params
                             key:(NSString *)key
                           value:(NSString *)value {
    if (![params objectForKey:key]) {
        if (value) {
            [params setObject:value forKey:key];
        } else {
            NSLog(@"[SEPServices] ERROR: Couldn't assign parameter [%@], value was nil!", key);
            [SEPError showSEPErrorForErrorType:SEPErrorTypeGeneric];
        }
    }
}

/*!
 * @return The application ID defined in the global settings for this SEP application.
 */
+ (NSString *)getAppId {
    return [NSString stringWithFormat:@"%d", APP_ID];
}

/*!
 * @return The version of iOS running on the device.
 */
+ (NSString *)getOsVersion {
    return [NSString stringWithFormat:@"%f", [[[UIDevice currentDevice] systemVersion] floatValue]];
}

/*!
 * @return The current version of the app defined in the project settings.
 */
+ (NSString *)getAppVersion {
    return [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
}

/*!
 * @return The type of iOS device, i.e. iPhone or iPad
 */
+ (NSString *)getHandset {
    return [UIDevice currentDevice].model;
}

/*!
 * @brief For making some operations fail silently without notifying the user with a popup that something went wrong.
 */
+ (BOOL)isSilentOperation:(SEPOperationType)type {
    switch (type) {
        case SEPOperationTypeUpdateGPSLocation3:
        case SEPOperationTypeCheckAppGroupCode:
        case SEPOperationTypeApplyAppGroupCode:
            return YES;
        default:
            return NO;
    }
}

@end
