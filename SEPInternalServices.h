//
//  SEPInternalServices
//
//
//  Created by Joshua J Varghese on 17/02/2016.
//  Copyright © 2016 Joshua J Varghese. All rights reserved.
//

/*
 * Handles internal SEPServices helper functions.
 */

#import <Foundation/Foundation.h>
#import "SEPOperations.h"

@interface SEPInternalServices : NSObject

/*!
 * @discussion Returns the exact name of the operation on the backend
 * @param type A SEPOperationType declared in SEPOperations.h
 * @return The name of the operation corresponding to that operation type.
 */
+ (NSString *)getOperationType:(SEPOperationType)type;

/*!
 * @discussion A convenience method for setting common parameters that don't need to be explicitly called when you call the operation. These can be overriden if desired by setting the parameters beforehand.
 * @param params    The prepopulated parameter dictionary previously populated with explicit parameters
 * @param type      The SEPOperationType you want to set internal parameters for. Each type has differently allocated internal parameters.
 */
+ (NSMutableDictionary *)addInternalParams:(NSMutableDictionary *)params forType:(EWNOperationType)type;

/*!
 * @brief Presents a generic error message on the main thread to the user.
 */
+ (void)displayGenericError;

/*!
 * @brief The operation doesn't present generic errors to the user, and doesn't present the loading spinner whilst working.
 @ param type   The operation type to check for silence.
 */
+ (BOOL)isSilentOperation:(EWNOperationType)type;

@end
