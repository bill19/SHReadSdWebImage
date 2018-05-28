/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <UIKit/UIKit.h>
#import "SDWebImageCompat.h"
#import "SDWebImageManager.h"

//UIImageView+HighlightedWebCache    和 UIImageView+WebCache 功能相似，用于加载 highlighted 状态的图片
/**
 * Integrates SDWebImage async downloading and caching of remote images with UIImageView for highlighted state.
 */
@interface UIImageView (HighlightedWebCache)

/**
 用“URL”设置UIView高亮显示”。异步操作

 @param url 图片的url连接
 */
- (void)sd_setHighlightedImageWithURL:(NSURL *)url;


/**
 用“URL”设置UIView高亮显示”。异步操作

 @param url 图片的url连接
 @param options 下载时候的选项设置
 */
- (void)sd_setHighlightedImageWithURL:(NSURL *)url options:(SDWebImageOptions)options;


/**
 用“URL”设置UIView高亮显示”。异步操作

 @param url 图片的url连接
 @param completedBlock 此块没有返回值
 并将请求的uIVIAS作为第一个参数。在错误的情况下，图像参数
 *是nil，第二个参数可以包含NSerror。第三个参数是布尔值。
 *指示图像是否从本地高速缓存或从网络检索。
 *第四个参数是原始图像URL。
 */
- (void)sd_setHighlightedImageWithURL:(NSURL *)url completed:(SDWebImageCompletionBlock)completedBlock;


/**
 用“URL”设置UIView高亮显示”。异步操作

 @param url 图片的url连接
 @param options 下载时候的选项设置
 @param completedBlock 此块没有返回值
 并将请求的uIVIAS作为第一个参数。在错误的情况下，图像参数
 *是nil，第二个参数可以包含NSerror。第三个参数是布尔值。
 *指示图像是否从本地高速缓存或从网络检索。
 *第四个参数是原始图像URL。
 */
- (void)sd_setHighlightedImageWithURL:(NSURL *)url options:(SDWebImageOptions)options completed:(SDWebImageCompletionBlock)completedBlock;

/**
 用“URL”设置UIView高亮显示”。异步操作

 @param url 图片的url连接
 @param options 下载时候的选项设置
 @param completedBlock 此块没有返回值
 进度展示
 并将请求的uIVIAS作为第一个参数。在错误的情况下，图像参数
 *是nil，第二个参数可以包含NSerror。第三个参数是布尔值。
 *指示图像是否从本地高速缓存或从网络检索。
 *第四个参数是原始图像URL。
 */
- (void)sd_setHighlightedImageWithURL:(NSURL *)url options:(SDWebImageOptions)options progress:(SDWebImageDownloaderProgressBlock)progressBlock completed:(SDWebImageCompletionBlock)completedBlock;

/**
 * 取消下载
 */
- (void)sd_cancelCurrentHighlightedImageLoad;

@end


@interface UIImageView (HighlightedWebCacheDeprecated)

- (void)setHighlightedImageWithURL:(NSURL *)url __deprecated_msg("Method deprecated. Use `sd_setHighlightedImageWithURL:`");
- (void)setHighlightedImageWithURL:(NSURL *)url options:(SDWebImageOptions)options __deprecated_msg("Method deprecated. Use `sd_setHighlightedImageWithURL:options:`");
- (void)setHighlightedImageWithURL:(NSURL *)url completed:(SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setHighlightedImageWithURL:completed:`");
- (void)setHighlightedImageWithURL:(NSURL *)url options:(SDWebImageOptions)options completed:(SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setHighlightedImageWithURL:options:completed:`");
- (void)setHighlightedImageWithURL:(NSURL *)url options:(SDWebImageOptions)options progress:(SDWebImageDownloaderProgressBlock)progressBlock completed:(SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setHighlightedImageWithURL:options:progress:completed:`");

- (void)cancelCurrentHighlightedImageLoad __deprecated_msg("Use `sd_cancelCurrentHighlightedImageLoad`");

@end
