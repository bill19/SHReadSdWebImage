/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "SDWebImageDownloader.h"
#import "SDWebImageOperation.h"

//SDWebImageDownloaderOperation    继承于 NSOperation，用来处理下载任务

extern NSString *const SDWebImageDownloadStartNotification;
extern NSString *const SDWebImageDownloadReceiveResponseNotification;
extern NSString *const SDWebImageDownloadStopNotification;
extern NSString *const SDWebImageDownloadFinishNotification;

@interface SDWebImageDownloaderOperation : NSOperation <SDWebImageOperation>

/**
 The request used by the operation's connection.
 操作连接所使用的请求。
 */
@property (strong, nonatomic, readonly) NSURLRequest *request;


@property (assign, nonatomic) BOOL shouldDecompressImages;

/**
 * Whether the URL connection should consult the credential storage for authenticating the connection. `YES` by default.
 ＊URL连接是否应咨询凭证存储以验证连接。“是”默认情况下。
 *
 * This is the value that is returned in the `NSURLConnectionDelegate` method `-connectionShouldUseCredentialStorage:`.
 *这是在“NSURLCONNECTION委托”方法'-CalutsRouthUsCurrestInalStury:'中返回的值。
 */
@property (nonatomic, assign) BOOL shouldUseCredentialStorage;

/**
 * The credential used for authentication challenges in `-connection:didReceiveAuthenticationChallenge:`.
 * 用于“连接”中的认证挑战的凭证：DIDENCEVIN认证挑战：
 *
 * This will be overridden by any shared credentials that exist for the username or password of the request URL, if present.
 * 如果存在的请求URL的用户名或密码，将被任何共享凭据所覆盖。
 */
@property (nonatomic, strong) NSURLCredential *credential;

/**
 * The SDWebImageDownloaderOptions for the receiver.
 * SDWebImageDownloaderOptions  接收图片的形式
 */
@property (assign, nonatomic, readonly) SDWebImageDownloaderOptions options;

/**
 The expected size of data.
 数据的预期大小。
 */
@property (assign, nonatomic) NSInteger expectedSize;

/**
 * The response returned by the operation's connection.
 *操作连接返回的响应。
 */
@property (strong, nonatomic) NSURLResponse *response;


/**
 * Initializes a `SDWebImageDownloaderOperation` object
 *初始化一个“SDWebIdGoDeNoLoopService操作”对象
 * @see SDWebImageDownloaderOperation
 *@ StdWebIdGieldUnLoad操作
 * @param request the URL request
 *@ PARAM请求URL请求
 * @param options downloader options
 *@ PARAM选项下载器选项
 * @param progressBlock the block executed when a new chunk of data arrives.
 *@ PARAM PraveScript阻止新数据块到达时执行的块。
 * @note the progress block is executed on a background queue
 注意：进度块是在后台队列上执行的
 * @param completedBlock the block executed when the download is done.

 *@ PARAM完成阻止在下载完成后执行的块。

 * @note the completed block is executed on the main queue for success. If errors are found, there is a chance the block will be executed on a background queue

 *完成的块在主队列上执行成功。如果发现错误，则有可能在后台队列上执行该块。

 * @param cancelBlock the block executed if the download (operation) is cancelled

 如果下载（操作）被取消，则*@ PARAM取消块
 * @return the initialized instance

 *@返回初始化实例
 */
- (id)initWithRequest:(NSURLRequest *)request
              options:(SDWebImageDownloaderOptions)options
             progress:(SDWebImageDownloaderProgressBlock)progressBlock
            completed:(SDWebImageDownloaderCompletedBlock)completedBlock
            cancelled:(SDWebImageNoParamsBlock)cancelBlock;

@end
