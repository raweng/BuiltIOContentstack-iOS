//
//  AssetLibrary.h
//  contentstack
//
//  Created by Priyanka Mistry on 05/10/16.
//  Copyright © 2016 Built.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ContentstackDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface AssetLibrary : NSObject

/**----------------------------------------------------------------------------------------
 * @name Properties
 *-----------------------------------------------------------------------------------------
 */

/**
 *  property to assign cache policy like CACHE_THEN_NETWORK, NETWORK_ELSE_CACHE, NETWORK_ONLY, etc.
 */
@property (nonatomic, assign) CachePolicy cachePolicy;

//MARK: Fetch Assets -
/**---------------------------------------------------------------------------------------
 * @name Fetch Assets
 *  ---------------------------------------------------------------------------------------
 */

/**
 This method provides all the assets.
 
 //Obj-C
 [assetLib fetchAll:^(ResponseType type, NSArray *result, NSError *error) {
 //error for any error description
 //result for reponse data
 }];
 
 //Swift
 assetLib.fetchAll { (responseType, result!, error!) -> Void in
 //error for any error description
 //result for reponse data
 }
 
 @param completionBlock block to be called once operation is done. The result data contains all the assets.
 */

- (void)fetchAll:(void (^) (ResponseType type,NSArray * BUILT_NULLABLE_P result,NSError * BUILT_NULLABLE_P error))completionBlock;
@end

BUILT_ASSUME_NONNULL_END
