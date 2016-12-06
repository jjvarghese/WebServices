//
//  SEPParameters.h
//  
//
//  Created by Joshua J Varghese on 12/02/2016.
//  Copyright © 2016 Joshua J Varghese. All rights reserved.
//

#import <Foundation/Foundation.h>

/* 
 * List of public common parameters for SEP web service calls.
 * Use format kSEPServices_operationType_param_parameterName.
 * !Assign ALL non unique parameters to a common macro with the format SEPSERVICES_COMMON_PARAM_PARAMETERNAME!
 */

#define SEPSERVICES_COMMON_PARAM_AUTHTOKEN      @"authToken"
#define SEPSERVICES_COMMON_PARAM_LATITUDE       @"positionLat"
#define SEPSERVICES_COMMON_PARAM_LONGITUDE      @"positionLong"
#define SEPSERVICES_COMMON_PARAM_MOBILENUMBER   @"mobileNumber"
#define SEPSERVICES_COMMON_PARAM_ALERTGROUPKEYS @"alertGroupKeys"
#define SEPSERVICES_COMMON_PARAM_ALERTGROUPKEY  @"alertGroupKey"
#define SEPSERVICES_COMMON_PARAM_LOCATIONKEY    @"regoLocationKey"
#define SEPSERVICES_COMMON_PARAM_EMAILADDRESS   @"emailAddress"
#define SEPSERVICES_COMMON_PARAM_PASSWORD       @"password"
#define SEPSERVICES_COMMON_PARAM_ALERTKEY       @"alertKey"
#define SEPSERVICES_COMMON_PARAM_COMMENT        @"comment"
#define SEPSERVICES_COMMON_PARAM_FBYTES64       @"fileBytesBase64"
#define SEPSERVICES_COMMON_PARAM_FILENAME       @"fileName"
#define SEPSERVICES_COMMON_PARAM_GROUPCODE      @"groupCode"

/* Register2 parameters */
static NSString * const kSEPServices_register2_param_email                              = SEPSERVICES_COMMON_PARAM_EMAILADDRESS;
static NSString * const kSEPServices_register2_param_password                           = SEPSERVICES_COMMON_PARAM_PASSWORD;
static NSString * const kSEPServices_register2_param_firstname                          = @"nameFirst";
static NSString * const kSEPServices_register2_param_lastname                           = @"nameLast";
static NSString * const kSEPServices_register2_param_mobilenumber                       = SEPSERVICES_COMMON_PARAM_MOBILENUMBER;

/* GetAuthDetailsForUser parameters */
static NSString * const kSEPServices_getAuthDetailsForUser_param_email                  = SEPSERVICES_COMMON_PARAM_EMAILADDRESS;
static NSString * const kSEPServices_getAuthDetailsForUser_param_password               = SEPSERVICES_COMMON_PARAM_PASSWORD;
static NSString * const kSEPServices_getAuthDetailsForUser_param_mobileNumber           = SEPSERVICES_COMMON_PARAM_MOBILENUMBER;

/* VerifyLoginByAuthToken parameters */
static NSString * const kSEPServices_verifyLoginByAuthToken_param_authToken             = SEPSERVICES_COMMON_PARAM_AUTHTOKEN;
static NSString * const kSEPServices_verifyLoginByAuthToken_param_password              = SEPSERVICES_COMMON_PARAM_PASSWORD;

/* ForgotPassword2 parameters parameters */
static NSString * const kSEPServices_forgotPassword2_param_emailAddress                 = SEPSERVICES_COMMON_PARAM_EMAILADDRESS;
static NSString * const kSEPServices_forgotPassword2_param_mobileNumber                 = SEPSERVICES_COMMON_PARAM_MOBILENUMBER;

/* UpdateDetails parameters */
static NSString * const kSEPServices_updateDetails_param_changePassword                 = @"changePassword";
static NSString * const kSEPServices_updateDetails_param_newPassword                    = @"newPassword";
static NSString * const kSEPServices_updateDetails_param_newEmailAddress                = @"newEmailAddress";
static NSString * const kSEPServices_updateDetails_param_newMobileNumber                = @"newMobileNumber";
static NSString * const kSEPServices_updateDetails_param_newFirstName                   = @"nSEPameFirst";
static NSString * const kSEPServices_updateDetails_param_newLastName                    = @"nSEPameLast";
static NSString * const kSEPServices_updateDetails_param_password                       = SEPSERVICES_COMMON_PARAM_PASSWORD;
static NSString * const kSEPServices_updateDetails_param_emailAddress                   = SEPSERVICES_COMMON_PARAM_EMAILADDRESS;
static NSString * const kSEPServices_updateDetails_param_mobileNumber                   = SEPSERVICES_COMMON_PARAM_MOBILENUMBER;

/* AddMyGroups parameters */
static NSString * const kSEPServices_addMyGroups_param_alertGroupKeys                   = SEPSERVICES_COMMON_PARAM_ALERTGROUPKEYS;

/* RemoveMyGroups parameters */
static NSString * const kSEPServices_removeMyGroups_param_alertGroupKeys                = SEPSERVICES_COMMON_PARAM_ALERTGROUPKEYS;

/* UpdateGPSLocation3 parameters */
static NSString * const kSEPServices_updateGpsLocation3_param_latitude                  = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_updateGpsLocation3_param_longitude                 = SEPSERVICES_COMMON_PARAM_LONGITUDE;

/* GetGroupsList parameters */
static NSString * const kSEPServices_getGroupsList_param_authToken                      = SEPSERVICES_COMMON_PARAM_AUTHTOKEN;

/* GetAlertsList parameters */
static NSString * const kSEPServices_getAlertsList_param_authToken                      = SEPSERVICES_COMMON_PARAM_AUTHTOKEN;
static NSString * const kSEPServices_getAlertsList_param_alertGroupKey                  = SEPSERVICES_COMMON_PARAM_ALERTGROUPKEY;

/* AddUpdateLocation parameters */

static NSString * const kSEPServices_addUpdateLocation2_param_name                      = @"name";
static NSString * const kSEPServices_addUpdateLocation2_param_locationNameKey           = @"locationNameKey";
static NSString * const kSEPServices_addUpdateLocation2_param_radiusInMeters            = @"radiusInMeters";
static NSString * const kSEPServices_addUpdateLocation_param_authToken                  = SEPSERVICES_COMMON_PARAM_AUTHTOKEN;
static NSString * const kSEPServices_addUpdateLocation_param_country                    = @"country";
static NSString * const kSEPServices_addUpdateLocation_param_stateAbbreviation          = @"stateAbbreviation";
static NSString * const kSEPServices_addUpdateLocation_param_postCode                   = @"postCode";
static NSString * const kSEPServices_addUpdateLocation_param_suburb                     = @"suburb";
static NSString * const kSEPServices_addUpdateLocation_param_streetName                 = @"streetName";
static NSString * const kSEPServices_addUpdateLocation_param_streetNumber               = @"streetNumber";
static NSString * const kSEPServices_addUpdateLocation_param_latitude                   = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_addUpdateLocation_param_longitude                  = SEPSERVICES_COMMON_PARAM_LONGITUDE;
static NSString * const kSEPServices_addUpdateLocation_param_locationKey                = SEPSERVICES_COMMON_PARAM_LOCATIONKEY;

/* RemoveLocation parameters */
static NSString * const kSEPServices_removeLocation_param_locationKey                   = SEPSERVICES_COMMON_PARAM_LOCATIONKEY;

/* GetAlertsListWithDistances parameters */
static NSString * const kSEPServices_getAlertsListWithDistances_param_latitude          = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_getAlertsListWithDistances_param_longitude         = SEPSERVICES_COMMON_PARAM_LONGITUDE;

/* GetAlertContent parameters */
static NSString * const kSEPServices_getAlertContent_param_authToken                    = SEPSERVICES_COMMON_PARAM_AUTHTOKEN;
static NSString * const kSEPServices_getAlertContent_param_alertKey                     = SEPSERVICES_COMMON_PARAM_ALERTKEY;

/* DeleteAlerts parameters */
static NSString * const kSEPServices_deleteAlerts_param_alertKeys                       = @"alertKeys";

/* UploadImageEncoded parameters */
static NSString * const kSEPServices_uploadImageEncoded_positionLat                     = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_uploadImageEncoded_positionLong                    = SEPSERVICES_COMMON_PARAM_LONGITUDE;
static NSString * const kSEPServices_uploadImageEncoded_comment                         = SEPSERVICES_COMMON_PARAM_COMMENT;
static NSString * const kSEPServices_uploadImageEncoded_fileName                        = SEPSERVICES_COMMON_PARAM_FILENAME;
static NSString * const kSEPServices_uploadImageEncoded_fileBytesBase64                 = SEPSERVICES_COMMON_PARAM_FBYTES64;

/* SetCheckIn parameters */
static NSString * const kSEPServices_setCheckIn_param_positionLat                       = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_setCheckIn_param_positionLong                      = SEPSERVICES_COMMON_PARAM_LONGITUDE;
static NSString * const kSEPServices_setCheckIn_param_isCheckIn                         = @"isCheckIn";
static NSString * const kSEPServices_setCheckIn_param_alertKey                          = SEPSERVICES_COMMON_PARAM_ALERTKEY;
static NSString * const kSEPServices_setCheckIn_param_feedback                          = @"feedback";

/* UploadVideoEncoded parameters */
static NSString * const kSEPServices_uploadVideoEncoded_param_positionLat               = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_uploadVideoEncoded_param_positionLong              = SEPSERVICES_COMMON_PARAM_LONGITUDE;
static NSString * const kSEPServices_uploadVideoEncoded_param_comment                   = SEPSERVICES_COMMON_PARAM_COMMENT;
static NSString * const kSEPServices_uploadVideoEncoded_param_fileName                  = SEPSERVICES_COMMON_PARAM_FILENAME;
static NSString * const kSEPServices_uploadVideoEncoded_param_fileBytesBase64           = SEPSERVICES_COMMON_PARAM_FBYTES64;

/* GetEmergencyDirectoryForApp parameters */
static NSString * const kSEPServices_getEmergencyDirectoryForApp_param_positionLat      = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_getEmergencyDirectoryForApp_param_positionLong     = SEPSERVICES_COMMON_PARAM_LONGITUDE;

/* UploadComment parameters */

static NSString * const kSEPServices_uploadComment_param_positionLat                    = SEPSERVICES_COMMON_PARAM_LATITUDE;
static NSString * const kSEPServices_uploadComment_param_positionLong                   = SEPSERVICES_COMMON_PARAM_LONGITUDE;
static NSString * const kSEPServices_uploadComment_param_comment                        = SEPSERVICES_COMMON_PARAM_COMMENT;
static NSString * const kSEPServices_uploadComment_param_commentTitle                   = @"commentTitle";

/* CheckAppGroupCode parameters */
static NSString * const kSEPServices_checkAppGroupCode_param_groupCode                  = SEPSERVICES_COMMON_PARAM_GROUPCODE;

/* ApplyAppGroupCode parameters */
static NSString * const kSEPServices_applyAppGroupCode_param_groupCode                  = SEPSERVICES_COMMON_PARAM_GROUPCODE;

/* GetSEQDamLevels parameters */
static NSString * const kSEPServices_getSEQCurrentDamLevels_param_selectedDate          = @"selectedDate";

