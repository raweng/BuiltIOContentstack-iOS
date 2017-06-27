# Contentstack SDK for iOS
Built.io Contentstack is a headless CMS with an API-first approach that puts content at the centre. It is designed to simplify the process of publication by separating code from content.  For more information see the [website](https://contentstackdocs.built.io/developer).

#### Installation Options
##### Manual

1. Download the [Latest iOS SDK release](https://github.com/raweng/BuiltIOContentstack-iOS/releases) and extract the zip file to your local disk.

2. Drag and drop Contentstack.framework into your project folder in Xcode. 
  
    A window will appear, prompting you to choose one of the options for adding files. Click the ‘Destination’ checkbox to copy items into the destination group’s folder. This will add  the SDK to your project.

3. In the project editor, select your app under `TARGETS`. Under the `General` tab, open `Linked Frameworks and Libraries` and add the following libraries:
  - CoreGraphics.framework
  - MobileCoreServices.framework
  - Security.framework
  - SystemConfiguration.framework

4. In your target app, click on the `Build Settings` tab and add the `-ObjC` flag to `Other Linker Flags`.

##### **[CocoaPods](https://cocoapods.org)**

Add the following line to your Podfile:
```sh
pod 'Contentstack'
```
Run `pod install`, and you should now have the latest Contentstack release.

#### Import Header/Module
You can import header file in Objective-C project as:
```sh
#import <Contentstack/Contentstack.h>
```
You can also import as a Module:

```sh
//Objc
@import Contentstack

//Swift
import Contentstack
```
#### Other Links
- [QuickStart](https://contentstackdocs.built.io/developer/ios/quickstart)
- [Developer Guide](https://contentstackdocs.built.io/developer/guides)
- [API Docs](https://contentstackdocs.built.io/ios/api) 

## License
```
Copyright (c) 2017, Contentstack.io.
All rights reserved.
```
