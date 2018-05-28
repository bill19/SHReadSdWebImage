//
//  UIImage+MultiFormat.h
//  SDWebImage
//
//  Created by Olivier Poitrey on 07/06/13.
//  Copyright (c) 2013 Dailymotion. All rights reserved.
//

#import <UIKit/UIKit.h>

//UIImage+MultiFormat    根据不同格式的二进制数据转成 UIImage 对象

@interface UIImage (MultiFormat)

+ (UIImage *)sd_imageWithData:(NSData *)data;

@end
