//
//  Stack.h
//  Contentstack
//
//  Created by Reefaq on 11/07/15.
//  Copyright (c) 2015 Built.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ContentstackDefinitions.h"

@class Config;
@class ContentType;
@class AssetLibrary;
@class Assets;

BUILT_ASSUME_NONNULL_BEGIN

@interface Stack : NSObject
/**----------------------------------------------------------------------------------------
 * @name Properties
 *-----------------------------------------------------------------------------------------
 */

/**
 *  Readonly property to check value of apikey
 */
@property (nonatomic, copy, readonly) NSString *apiKey;

/**
 *  Readonly property to check value of access token
 */
@property (nonatomic, copy, readonly) NSString *accessToken;

/**
 *  Readonly property to check value of environment provided
 */
@property (nonatomic, copy, readonly) NSString *environment;

/**
 *  Readonly property to check value of config provided
 */
@property (nonatomic, copy, readonly) Config *config;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

//MARK: ContentType -
/**---------------------------------------------------------------------------------------
 * @name ContentType
 *  ---------------------------------------------------------------------------------------
 */

/**
 Gets the new instance of ContentType object with specified name.

    //Obj-C
    ContentType *contentTypeObj = [stack contentTypeWithName:@"blog"];

    //Swift
    var contentTypeObj:ContentType = stack.contentTypeWithName("blog")

 @param contentTypeName name of the contentType to perform action.
 @return instance of ContentType.
 */
- (ContentType*)contentTypeWithName:(NSString*)contentTypeName;

//MARK: Manually set headers -
/**---------------------------------------------------------------------------------------
 * @name Manually set headers
 *  ---------------------------------------------------------------------------------------
 */

/**
 Set a header for Stack
 
    //Obj-C
    [stack setHeader:@"MyValue" forKey:@"My-Custom-Header"];

    //Swift
    stack.setHeader("MyValue", forKey: "My-Custom-Header")
 
 @param headerValue  The header key
 @param headerKey    The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
 Set a header for Stack
 
    //Obj-C
    [stack addHeadersWithDictionary:@{@"My-Custom-Header": @"MyValue"}];

    //Swift
    stack.addHeadersWithDictionary(["My-Custom-Header":"MyValue"])
 
 @param headers The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
 Removes a header from this Stack.
 
    //Obj-C
    [stack removeHeaderForKey:@"My-Custom-Header"];

    //Swift
    stack.removeHeaderForKey("My-Custom-Header")
 
 @param headerKey The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;

/**----------------------------------------------------------------------------------------
 * @name Last Activity
 *-----------------------------------------------------------------------------------------
 */

/**
 fetch last activity of content type
 
     //Obj-C
      [stack fetchLastActivity:^(ResponseType responseType, NSDictionary *lastActivity, NSError *error) {
        //lastActivity
     }];
     
     //Swift
     stack.fetchLastActivity { (responseType, lastActivity!, error!) -> Void in
        //lastActivity
     }

 
 @param headers The headers as dictionary which needs to be added to the application
 */
- (void)fetchLastActivity:(void (^)(ResponseType responseType, NSDictionary *lastActivity, NSError *error))completionBlock;

/**----------------------------------------------------------------------------------------
 * @name Fetch Schema
 *-----------------------------------------------------------------------------------------
 */
/**
 Gets the schema of content types
  
 //Obj-C
 [stack fetchSchema:^(ResponseType responseType, NSArray *schema, NSError *error) {
 
 }];
 
 //Swift
 stack.fetchSchema { (responseType, schema, error) -> Void in
 
 }
 
 @param completionBlock Completion block with params (ResponseType responseType, NSArray *schema, NSError *error)
 */
- (void)fetchSchema:(void (^)(ResponseType responseType, NSArray * BUILT_NULLABLE_P schema, NSError * BUILT_NULLABLE_P error))completionBlock;

//MARK: Assets -
/**---------------------------------------------------------------------------------------
 * @name Assets
 *  ---------------------------------------------------------------------------------------
 */

/**
 Represents a Asset on 'Stack' which can be executed to get AssetLibrary object
 
     //Obj-C
     AssetLibrary *assetLib = [stack assetLibrary];
     
     //Swift
     var assetLib: AssetLibrary = stack.assetLibrary()
 
 @return Returns new AssetLibrary instance
 */

-(AssetLibrary*)assetLibrary;

/**
 Represents a Asset on 'Stack' which can be executed to get Asset object
 
     //Obj-C
     Assets *assetObj = [stack assets];
     
     //Swift
     var assetObj:Assets = stack.assets()
 
 @return Returns new Asset instance
 */

-(Assets*)asset;

/**
 Gets the new instance of Asset object with specified UID.
 
     //Obj-C
     Assets *assetObj = [contentTypeObj assetWithUID:@"bltf4fsamplec851db"];
     
     //Swift
     var assetObj:Assets = contentTypeObj.assetWithUID("bltf4fsamplec851db")
 
 @param uid uid of the Asset object to fetch.
 @return new instance of Asset with uid.
 */
- (Assets *)assetWithUID:(NSString *)uid;


@end

BUILT_ASSUME_NONNULL_END
