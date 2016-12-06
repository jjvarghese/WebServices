//
//  SEPOperations.h
//  
//
//  Created by Joshua J Varghese on 11/02/2016.
//  Copyright © 2016 Joshua J Varghese. All rights reserved.
//

/*
 * This is the list of valid SEPOperations.
 * When adding a new operation, add it to the bottom with a decremented value and then add it to getOperationType in SEPCore.m.
 * Also, try to ensure the headerdoc comments are added and up to date if values are changed.
 */

static NSString * const kSEPServices_unknown_operation = @"UnknownOrUndefinedSEPOperation";

/*!
 * @typedef kSEPOperationType
 * @discussion The type of SEP operation corresponds to the web service call it will make.
 * @see https://ci.SEP.com.au:55556/exo/phoneapp4JSON.asmx contains a full list of available web services.
 */
typedef enum : NSInteger {
    /*!
     * @brief Register2
     * @brief Creates a new user in the database
     
     * @param + (NSString *) kSEPServices_register2_param_email
     * @param + (NSString *) kSEPServices_register2_param_password
     * @param + (NSString *) kSEPServices_register2_param_firstname
     * @param + (NSString *) kSEPServices_register2_param_lastname
     * @param + (NSString *) kSEPServices_register2_param_mobilenumber
     * @param - kSEPServices_internal_param_deviceId
     * @param - kSEPServices_internal_param_deviceBytes
     * @param - kSEPServices_internal_param_appId
     
     * @result (NSString *) AuthToken
     * @result (NSString const *) ErrorMessage
     * @result (NSString const *) Url
     * @result (NSString *) InstallationID
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (long) RegistrationKey
     */
    SEPOperationTypeRegister2                   = 99,
    
    /*!
     * VerifyLogin2 is a deprecated function.
        Use VerifyLoginByAuthToken4 instead.
     */
    SEPOperationTypeVerifyLogin2                = 98,
    
    /*!
     * GetAuthDetailsForUser is a deprecated function.
     Use GetAuthDetailsForUser2 instead.
     */
    SEPOperationTypeGetAuthDetailsForUser       = 97,
    
    /*!
     * @warning VerifyLoginByAuthToken is a deprecated function.
        Use VerifyLoginByAuthToken4 instead!
     */
    SEPOperationTypeVerifyLoginByAuthToken      = 96,
    
    /*!
     * @brief GetRegistrationDetails
     * @brief Obtain the information the given user entered at registration or last detail changing (ie name, mobile number).

     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     
     * @result (NSString *) EmailAddress
     * @result (NSString *) MobileNumber
     * @result (NSString *) NameFirst
     * @result (NSString *) NameLast
     * @result (NSString const *) ErrorMessage
     * @result (NSString const *) Url
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (BOOL) IsSuccess
     */
    SEPOperationTypeGetRegistrationDetails      = 95,
    
    /*!
     * @brief ForgotPassword2
     
     * @param + kSEPServices_forgotPassword2_param_emailAddress
     * @param + kSEPServices_forgotPassword2_param_mobileNumber
     */
    SEPOperationTypeForgotPassword2             = 94,
    
    /*!
     * @brief UpdateDetails
     * @brief Lets the user change their registration details. Requires authentication with their existing password.
     
     * @param + (NSString *) kSEPServices_updateDetails_param_changePassword
     * @param + (NSString *) kSEPServices_updateDetails_param_newPassword
     * @param + (NSString *) kSEPServices_updateDetails_param_newEmailAddress
     * @param + (NSString *) kSEPServices_updateDetails_param_newMobileNumber
     * @param + (NSString *) kSEPServices_updateDetails_param_newFirstName
     * @param + (NSString *) kSEPServices_updateDetails_param_newLastName
     * @param + (NSString *) kSEPServices_updateDetails_param_password
     * @param + (NSString *) kSEPServices_updateDetails_param_emailAddress
     * @param + (NSString *) kSEPServices_updateDetails_param_mobileNumber
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_authToken
     
     * @result (NSString *) ErrorMessage
     * @result (NSString *) IsSuccess
     * @result (NSString const *) Url
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (BOOL) HasNewMessages
     */
    SEPOperationTypeUpdateDetails               = 93,
    
    /*!
     * @brief UpdateGPSLocation3
     * @brief Notify SEP server of previously triangulated position for the given user.
     
     * @param + (NSString *) kSEPServices_updateGpsLocation3_param_latitude
     * @param + (NSString *) kSEPServices_updateGpsLocation3_param_longitude
     * @param - kSEPServices_internal_param_deviceId
     * @param - kSEPServices_internal_param_deviceBytes
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_mobileNumber
     * @param - kSEPServices_internal_param_installationId
     */
    SEPOperationTypeUpdateGPSLocation3          = 92,
    
    /*!
     * @brief AddMyGroups
     * @brief Subscribe the given user with the provided array of alert groups.
     
     * @param + (NSArray *) kSEPServices_addMyGroups_param_alertGroupKeys
     * @param - kSEPServices_addMyGroups_internal_param_appId
     * @param - kSEPServices_addMyGroups_internal_param_authToken
     * @param - kSEPServices_addMyGroups_internal_param_regoKey
     
     * @result (NSString const *) ErrorMessage
     * @result (NSString const *) Url
     * @result (long) ErrorNumber
     * @result (NSArray *) Groups
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     * @result (long) NewMessageCount
     */
    SEPOperationTypeAddMyGroups                 = 91,
    
    /*!
     * @brief GetGroupsList
     
     * @param - kSEPServices_addMyGroups_internal_param_appId
     * @param - kSEPServices_addMyGroups_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     * @param - kSEPServices_addMyGroups_internal_param_authToken
     */
    SEPOperationTypeGetGroupsList               = 90,
    
    /*!
     * @brief RemoveMyGroups
     * @brief Disassociate a user from the specified alert groups.
     
     * @param + (NSArray <NSString *>*) kSEPServices_removeMyGroups_param_alertGroupKeys
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_appId
     
     * @result (NSString const *) ErrorMessage
     * @result (NSString const *) Url
     * @result (long) ErrorNumber
     * @result (NSArray *) Groups
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     * @result (long) NewMessageCount
     */
    SEPOperationTypeRemoveMyGroups              = 89,
    
    /*!
     * @brief GetGroupsListLite
     * @brief View associated alert groups for the given user.
     
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     
     * @result Returns an array of Alert Group dictionaries. These dictionaries each contain PrimaryKey (long), Name (NSString *), and Description (NSString const *).
     */
    SEPOperationTypeGetGroupsListLite           = 88,
    
    /*!
     * @brief GetAlertsList
     
     * @param + kSEPServices_getAlertsList_param_alertGroupKey
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     * @param - kSEPServices_internal_param_startRow
     * @param - kSEPServices_internal_param_endRow
     */
    SEPOperationTypeGetAlertsList               = 87,
    
    /*!
     * SEPOperationTypeAddUpdateLocation is a deprecated function.
     Use SEPOperationTypeAddUpdateLocation2 instead.
     */
    SEPOperationTypeAddUpdateLocation           = 86,
    
    /*!
     * @brief RemoveLocation
     
     * @param + kSEPServices_removeLocation_param_locationKey
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     */
    SEPOperationTypeRemoveLocation              = 85,
    
    /*!
     * @brief GetLocations
     * @brief View severe weather location groups associated with the given user.
     
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_regoLocationKey
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     
     * @result (NSArray <NSString *> *) Alerts
     * @result (NSString *) ErrorMessage
     * @result (NSString const *) Url
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     */
    SEPOperationTypeGetLocations                = 84,
    
    /*!
     * @brief GetAlertsListWithDistances
     * @brief Retrieve alerts with a distance property in meters to the given location.
     
     * @param + kSEPServices_getAlertsListWithDistances_param_latitude
     * @param + kSEPServices_getAlertsListWithDistances_param_longitude
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_installationId
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_startRow
     * @param - kSEPServices_internal_param_endRow
     * @param - kSEPServices_internal_param_alertGroupKey;
     
     * @result (NSArray <NSDictionary *>*) Alerts
     * @result (NSString *) ErrorMessage
     * @result (NSString const *) Url
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     * @result (BOOL) AllowDelete
     */
    SEPOperationTypeGetAlertsListWithDistances  = 83,
    
    /*!
     * @brief VerifyLoginByAuthToken4
     * @brief Authenticate a user with its associated valid authentication token
     
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_deviceId
     * @param - kSEPServices_internal_param_deviceBytes
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_osVersion
     * @param - kSEPServices_internal_param_appVersion
     * @param - kSEPServices_internal_param_handset
     
     * @result (NSString *) AuthToken
     * @result (NSString *) InstallationID
     * @result (NSString const *) ErrorMessage
     * @result (NSString const *) Url
     * @result (BOOL) EnableRatingPrompt
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (long) RatingAfterXDays
     * @result (long) RatingAfterXLaunches
     * @result (long) RatingAfterXPush
     * @result (long) RegistrationKey
     */
    SEPOperationTypeVerifyLoginByAuthToken4     = 82,
    
    /*!
     * @brief GetAlertContent
     
     * @param + kSEPServices_getAlertContent_param_alertKey
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     */
    SEPOperationTypeGetAlertContent             = 81,
    
    /*!
     * @brief DeleteAlerts
     
     * @param + kSEPServices_deleteAlerts_param_alertKeys
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     */
    SEPOperationTypeDeleteAlerts                = 80,
    
    /*!
     * @brief UploadImageEncoded
     
     * @param + kSEPServices_uploadImageEncoded_positionLat
     * @param + kSEPServices_uploadImageEncoded_positionLong
     * @param + kSEPServices_uploadImageEncoded_comment
     * @param + kSEPServices_uploadImageEncoded_fileName
     * @param + kSEPServices_uploadImageEncoded_fileBytesBase64
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     * @param - kSEPServices_internal_param_appId
     */
    SEPOperationTypeUploadImageEncoded         = 79,
    
    /*!
     * @brief SetCheckIn
     
     * @param + (float) kSEPServices_setCheckIn_param_positionLat
     * @param + (float) kSEPServices_setCheckIn_param_positionLong
     * @param + (BOOL) kSEPServices_setCheckIn_param_isCheckIn
     * @param + (long) kSEPServices_setCheckIn_param_alertKey
     * @param + (NSString *) kSEPServices_setCheckIn_param_feedback
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_appId
     */
    SEPOperationTypeSetCheckIn                  = 78,
    
    /*!
     * @brief SEPOperationTypeUploadVideoEncoded
     
     * @param + (float) kSEPServices_uploadVideoEncoded_param_positionLat
     * @param + (float) kSEPServices_uploadVideoEncoded_param_positionLong
     * @param + (NSString *) kSEPServicesEncoded_uploadVideo_param_comment
     * @param + (NSString *) kSEPServicesEncoded_uploadVideo_param_fileName
     * @param + (NSData *) kSEPServices_uploadVideoEncoded_param_fileBytesBase64
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_appId
     */
    SEPOperationTypeUploadVideoEncoded          = 77,
    
    /*!
     * @brief GetEmergencyDirectoryForApp
     
     * @param + (float) kSEPServices_getEmergencyDirectoryForApp_param_positionLat
     * @param + (float) kSEPServices_getEmergencyDirectoryForApp_param_positionLong
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_appId
     */
    SEPOperationTypeGetEmergencyDirectoryForApp = 76,
    
    /*!
     * @brief SEPOperationTypeUploadComment
     
     * @param + (float) kSEPServices_uploadComment_param_positionLat
     * @param + (float) kSEPServices_uploadComment_param_positionLong
     * @param + (NSString *) kSEPServices_uploadComment_param_comment
     * @param + (NSString *) kSEPServices_uploadComment_param_commentTitle
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_appId
     */
    SEPOperationTypeUploadComment               = 75,
    
    /*!
     * @brief SEPOperationTypeCheckAppGroupCode
     
     * @param + (NSString *) kSEPServices_checkAppGroupCode_param_groupCode
     * @param - kSEPServices_internal_param_appId
     */
    SEPOperationTypeCheckAppGroupCode           = 74,
    
    /*!
     * @brief SEPOperationTypeApplyAppGroupCode
     
     * @param + (NSString *) kSEPServices_applyAppGroupCode_param_groupCode
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_authToken
     */
    SEPOperationTypeApplyAppGroupCode           = 73,
    
    /*!
     * @brief SEPOperationTypeCheckStatus
     * @discussion Related to appstore purchase status, not checkin status.
     
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_authToken
     */
    SEPOperationTypeCheckStatus                 = 72,
    
    /*!
     * @brief SEPOperationTypeGetSEQCurrentDamLevels
     * @discussion Get the dam data from SEQ's WISKI database.
     
     * @param + (NSString *) kSEPServices_getSEQCurrentDamLevels_param_selectedDate
     */
    SEPOperationTypeGetSEQCurrentDamLevels      = 71,
    
    /*!
     * @brief GetAuthDetailsForUser2
     * @brief Obtain an authentication token from login credentials. The authentication token is used to authenticate other web service calls.
     
     * @param + (NSString *) kSEPServices_getAuthDetailsForUser_param_email
     * @param + (NSString *) kSEPServices_getAuthDetailsForUser_param_password
     * @param + (NSString *) kSEPServices_getAuthDetailsForUser_param_mobileNumber
     * @param - kSEPServices_internal_param_appId

     * @result (long) ApplicationID
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (long) RegistrationKey
     * @result (NSString *) AuthenticationToken
     * @result (NSString *) InstallationID
     * @result (NSString const *) ErrorMessage
     * @result (NSString const *) Url
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     */
    SEPOperationTypeGetAuthDetailsForUser2      = 70,
    
    /*!
     * @brief AddUpdateLocation2
     * @brief Adds the given location to the given user's severe weather alerts.
     
     * @param + kSEPServices_addUpdateLocation2_param_name
     * @param + kSEPServices_addUpdateLocation2_param_locationNameKey
     * @param + kSEPServices_addUpdateLocation2_param_radiusInMeters
     * @param + kSEPServices_addUpdateLocation_param_country
     * @param + kSEPServices_addUpdateLocation_param_stateAbbreviation
     * @param + kSEPServices_addUpdateLocation_param_postCode
     * @param + kSEPServices_addUpdateLocation_param_suburb
     * @param + kSEPServices_addUpdateLocation_param_streetName
     * @param + kSEPServices_addUpdateLocation_param_streetNumber
     * @param + kSEPServices_addUpdateLocation_param_latitude
     * @param + kSEPServices_addUpdateLocation_param_longitude
     * @param + kSEPServices_addUpdateLocation_param_locationKey
     * @param - kSEPServices_internal_param_appId
     * @param - kSEPServices_internal_param_authToken
     * @param - kSEPServices_internal_param_regoKey
     * @param - kSEPServices_internal_param_installationId
     
     * @result (NSString *) ErrorMessage
     * @result (NSString const *) Url
     * @result (long) ErrorNumber
     * @result (long) NewMessageCount
     * @result (BOOL) HasNewMessages
     * @result (BOOL) IsSuccess
     */
    SEPOperationTypeAddUpdateLocation2          = 69,
    
    /*!
     * @brief GetLocationTypes
     * @brief Obtains available categories for assigning to watch zone alert groups.
     
     * @param - kSEPServices_internal_param_appId
     */
    SEPOperationTypeGetLocationTypes            = 68
    
} SEPOperationType;
