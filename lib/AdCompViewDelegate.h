//
//  AdCompViewDelegate.h
//  KuaiYouAdHello
//
//  Created by adview on 13-12-12.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocationManager.h>

//开屏位置 1居上 2居下
typedef enum{
    AdCompSpreadShowTypeTop = 1,
    AdCompSpreadShowTypeBottom = 2,
}AdCompSpreadShowType;

@class AdCompView;
@protocol AdCompViewDelegate <NSObject>

@optional

#pragma mark - 广告响应回调
/*
 * 广告请求成功
 */
- (void)didReceivedAd:(AdCompView*)adView reuse:(BOOL)isReuse;

/*
 * 广告请求失败
 */
- (void)didFailToReceiveAd:(AdCompView*)adView Error:(NSError*)error;

/*
 * 插屏预备好回调
 */
- (void)adinstlDidReadyToShow:(AdCompView*)adView;

/*
 * 广告网页将要展示回调
 */

- (void)adViewWillPresentScreen:(AdCompView *)adView;

/*
 * 广告网页将要关闭回调
 */

- (void)adViewDidDismissScreen:(AdCompView *)adView;

/*
 * 广告点击之后应用进入后台时回调
 */
- (void)adViewResignActive:(AdCompView *)adView;

/*
 * 开屏将要关闭回调
 */
- (void)adSpreadWillDismissScreen:(AdCompView *)adSpread;

/*
 * 插屏/开屏关闭回调
 */
- (void)adInstlDidDismissScreen:(AdCompView *)adInstl;


#pragma mark - 广告相关设置
/*
 * 设置开屏背景颜色
 */
- (UIColor *)adBackgroundColor;

/*
 * 设置开屏背景图片
 */
- (NSString *)adBackgroundImgName;

/*
 * 设置Banenr自动刷新时间(0:不刷新, <15:15s刷新)
 */
- (int)autoRefreshInterval;

/*
 * 是否使用缓存
 */
- (BOOL)usingCache;

/*
 * 是否打印日志
 */
- (BOOL)logMode;

/*
 * 获取 location 信息
 */
- (CLLocation*)getLocation;

/*
 * 设置插屏广告位置移动 默认为屏幕中心 例子: return 20 即广告中心点向上移动 20
 */
- (float)moveCentr;

/*
 * 设置插屏广告,等比例缩放 有限制范围为 0.8 - 1.2 之间
 */
- (float)scaleProportion;

/*
 * 设置开屏logoView设置(高度不超过屏幕高度25%);
 */
- (UIView *)spreadLogoView;

/*
 * 是否使用应用内打开AppStore(默认为YES)
 */
- (BOOL)usingSKStoreProductViewController;

@required
/*
 * 设置广告SDK-KEY
 */
- (NSString *)appId;

/*
 * 设置广告位ID
 */
- (NSString *)positionID;

/*
 * 设置广告点击,落地页弹出viewController
 */
- (UIViewController *)viewControllerForShowModal;

@end
