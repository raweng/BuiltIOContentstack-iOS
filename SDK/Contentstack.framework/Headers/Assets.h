//
//  Assets.h
//  contentstack
//
//  Created by Priyanka Mistry on 19/05/16.
//  Copyright © 2016 Built.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ContentstackDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

@class ContentType;

@interface Assets : NSObject

/**----------------------------------------------------------------------------------------
 * @name Properties
 *-----------------------------------------------------------------------------------------
 */

/**
 *  Readonly property to check  fileName of asset
 */
@property (nonatomic, copy, readonly) NSString *fileName;

/**
 *  Readonly property to check fileSize  of asset
 */
@property (nonatomic, assign, readonly) unsigned int fileSize;

/**
 *  Readonly property to check type of asset
 */
@property (nonatomic, copy, readonly) NSString *assetType;

/**
 *  Readonly property to check ContentType name of asset
 */
@property (nonatomic, copy, readonly) ContentType *contentType;

/**
 *  Readonly property to check value of asset's uid
 */
@property (nonatomic, copy, readonly) NSString *uid;

/**
 *  Readonly property to check value of asset's url
 */
@property (nonatomic, copy, readonly) NSString *url;

/**
 *  Readonly property to check Language of asset
 */
@property (nonatomic, assign, readonly) Language language;

/**
 *  Readonly property to check tags of asset
 */
@property (nonatomic, copy, readonly) NSArray *tags;

/**
 *  Readonly property to check createAt of asset
 */
@property (nonatomic, copy, readonly) NSDate *createdAt;

/**
 *  Readonly property to check createdBy of asset
 */
@property (nonatomic, copy, readonly) NSString *createdBy;

/**
 *  Readonly property to check updatedAt of asset
 */
@property (nonatomic, copy, readonly) NSDate *updatedAt;

/**
 *  Readonly property to check updatedBy of asset
 */
@property (nonatomic, copy, readonly) NSString *updatedBy;

/**
 *  Readonly property to check deletedAt of asset
 */
@property (nonatomic, copy, readonly) NSDate *deletedAt;

/**
 *  Readonly property to check deletedBy of asset
 */
@property (nonatomic, copy, readonly) NSString *deletedBy;

/**
 *  Readonly property to check publish details of asset
 */
@property (nonatomic, copy, readonly) NSDictionary *publishDetails;

/**
 *  property to assign cache policy like CACHE_THEN_NETWORK, NETWORK_ELSE_CACHE, NETWORK_ONLY, etc.
 */
@property (nonatomic, assign) CachePolicy cachePolicy;


- (instancetype)init UNAVAILABLE_ATTRIBUTE;


//MARK: Configuring manually -
/**---------------------------------------------------------------------------------------
 * @name Configuring manually
 *  ---------------------------------------------------------------------------------------
 */

/**
 Configure user properties with built object info.
 
     //Obj-C
     [assetObj configureWithDictionary:@{@"key_name":@"MyValue"}];
     
     //Swift
     assetObj.configureWithDictionary(["key_name":"MyValue"])
 
 @param dictionary User Info
 */
- (void)configureWithDictionary:(NSDictionary*)dictionary;
//MARK: - Fetch -
/**---------------------------------------------------------------------------------------
 * @name Fetch
 *  ---------------------------------------------------------------------------------------
 */

/**
 Fetches an asset asynchronously provided asset UID
 
     //Obj-C
     Stack *stack = [Contentstack stackWithAPIKey:@"blt5d4sample2633b" accessToken:@"blt3esampletokeneb02" environmentName:@"dummy"];
     //'bltf4fsamplec857bk' is uid of an asset
     Assets* assetObj = [stack assetWithUID:@"bltf4fsamplec857bk"];
     [assetObj fetch:^(ResponseType type, NSError *error) {
        //error if exists then use 'error' object for details
     }];
     
     
     //Swift
     var stack:Stack = Contentstack.stackWithAPIKey("blt5d4sample2633b", accessToken:"blt3esampletokeneb02", environmentName:@"dummy")
     //'bltf4fsamplec857bk' is uid of an asset
     var assetObj:Entry = contentTypeObj.entryWithUID("bltf4fsamplec857bk")
     assetObj.fetch { (responseType, error!) -> Void in
        //error if exists then use 'error' object for details
     }
 
 @param callback Completion block with params NSError
 */

- (void)fetch:(void(^)(ResponseType type, NSError * BUILT_NULLABLE_P error))callback;

@end
BUILT_ASSUME_NONNULL_END
