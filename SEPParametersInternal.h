//
//  SEPParametersInternal.h
//  
//
//  Created by Joshua J Varghese on 11/02/2016.
//  Copyright © 2016 Joshua J Varghese. All rights reserved.
//

/*
 * This is a list of internal, common parameters.
 * Not necessary to explicitly specify when the call is made, they are automatically added unless overriden.
 * If an internal parameter has a non unique parameter name, assign it to the common macro declared in SEPParameters.h unless it's internal only then declare it here
 * Use format kSEPServices_internal_param_parameterName
 */

static NSString * const kSEPServices_internal_param_appId           = @"appId";
static NSString * const kSEPServices_internal_param_startRow        = @"startRow";
static NSString * const kSEPServices_internal_param_endRow          = @"endRow";
static NSString * const kSEPServices_internal_param_appVersion      = @"appVersion";
static NSString * const kSEPServices_internal_param_handset         = @"handset";
static NSString * const kSEPServices_internal_param_osVersion       = @"osVersion";
static NSString * const kSEPServices_internal_param_deviceId        = @"deviceId";
static NSString * const kSEPServices_internal_param_deviceBytes     = @"deviceBytes";
static NSString * const kSEPServices_internal_param_regoKey         = @"regoKey";
static NSString * const kSEPServices_internal_param_installationId  = @"installationId";
static NSString * const kSEPServices_internal_param_authToken       = @"authToken";
static NSString * const kSEPServices_internal_param_mobileNumber    = @"mobileNumber";
static NSString * const kSEPServices_internal_param_alertGroupKey   = SEPSERVICES_COMMON_PARAM_ALERTGROUPKEY;
static NSString * const kSEPServices_internal_param_supportEmail    = @"supportEmail";
static NSString * const kSEPServices_internal_param_regoLocationKey = @"regoLocationKey";
