//
//  YBookmarkView.h
//  YBookmarkView
//
//  Created by yinbing on 2018/6/14.
//  Copyright © 2018年 yinbing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YBookmarkContentCell.h"
#import "YBookmarkTopView.h"
#import "YBookmarkBottomView.h"
#import "YBBookMarkConfig.h"

@class YBookmarkView;
@protocol YBookMarkViewDataSource <NSObject>

@required 

/**
 bookMarkView 数据来源

 @param bookMarkView bookMarkView
 @return 控制器数量
 */
- (NSInteger)numberOfItemInBookMarkView:(YBookmarkView *)bookMarkView;

/**
 top title 标签

 @param bookMarkView bookMarkView
 @param index 第几个标签
 @return title
 */
- (NSString *)bookMarkView:(YBookmarkView *)bookMarkView titleAtIndex:(NSInteger)index;

/**
 控制器  数据来源
 说明：每个控制器不会重复调用
 @param bookMarkView bookMarkView
 @param index 第几个标签
 @param viewRect 控制器的CGRect 大小
 @return 控制器
 */
- (UIViewController *)bookMarkView:(YBookmarkView *)bookMarkView viewAtIndex:(NSInteger)index viewRect:(CGRect)viewRect;

@optional
//可以自定义TitleCell 样式 默认不需要实现
- (void)bookMarkView:(YBookmarkView *)bookMarkView titleCell:(YBookmarkTitleCell *)cell index:(NSInteger)index;

/**
 父类控制器
 @return 基本是带有导航栏的控制器
 */
- (UIViewController *)bookMarkViewTopVC:(YBookmarkView *)bookMarkView;
///** *  右侧角标 */
//- (NSString *)bookMarkView:(YBookmarkView *)bookMarkView markAtIndex:(NSInteger)index;

@end

@protocol YBookMarkViewDelegate <NSObject>

@optional

//** 点击 title 回调 */
- (void)bookMarkView:(YBookmarkView *)bookMarkView didSelectTitleAtIndex:(NSInteger)index;
//** 滚动到第几个标签回调 */
- (void)bookMarkView:(YBookmarkView *)bookMarkView didScrollToIndex:(NSInteger)index;
//** bottomMark 滑动结束 回调*/
- (void)bookMarkView:(YBookmarkView *)bookMarkView didEndDecelerating:(NSInteger)index;
- (void)bookMarkView:(YBookmarkView *)bookMarkView updateLayoutIndex:(NSInteger)index viewController:(UIViewController *)vc;
//** bottomMark 将要显示 回调*/
- (void)bookMarkView:(YBookmarkView *)bookMarkView bottomMarkWillDisplayCell:(UICollectionViewCell *)cell atIndex:(NSInteger)index;
//** 第index个子控制器 将要显示 回调*/
- (void)bookMarkView:(YBookmarkView *)bookMarkView willDisplayingVC:(__kindof UIViewController *)vc index:(NSInteger)index;
//** 第index个子控制 结束显示 回调*/
- (void)bookMarkView:(YBookmarkView *)bookMarkView didEndDisplayingVC:(__kindof UIViewController *)vc index:(NSInteger)index;

@end

@interface YBookmarkView : UIView

@property (nonatomic, weak) id<YBookMarkViewDataSource> dataSource;
@property (nonatomic, weak) id<YBookMarkViewDelegate> delegate;
@property (nonatomic, strong) YBookmarkTopView *topView;
@property (nonatomic, strong) YBookmarkBottomView * bottomView;

/** *  当前索引 */
@property (nonatomic, assign) NSInteger currentIndex;

/**
 配置bookmark参数
 @param block 回调
 */
- (void)configMake:(void(^)(YBBookMarkConfig * config))block;
/**
 *  赋完值后  必须刷新数据
 */
- (void)reloadData;

- (void)reloadLayout;

- (void)reloadTitles;

//- (void)reloadDataForIndex:(NSInteger)index;

- (void)setBookMarkViewIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

- (__kindof UIViewController *)viewControllerForIndex:(NSInteger)index;

- (__kindof UIViewController *)currentViewController;

- (NSString *)titleForIndex:(NSInteger)index;

- (__kindof UIViewController *)viewControllerForClass:(Class)clss;

- (NSArray *)bookMarkViewTitles;

- (NSArray *)bookMarkViewControllers;

- (void)dropTopViewShadowWithOffset:(CGSize)offset radius:(CGFloat)radius color:(UIColor *)color opacity:(CGFloat)opacity;

@end
