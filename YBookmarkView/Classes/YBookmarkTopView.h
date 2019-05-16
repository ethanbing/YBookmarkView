//
//  YBookmarkTopView.h
//  YBookmarkView
//
//  Created by yinbing on 2018/6/14.
//  Copyright © 2018年 yinbing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YBookmarkContentCell.h"

@class YBookmarkTopView;
@protocol YBookmarkTopViewDelegate <NSObject>

- (NSMutableArray *)bookmarkTopViewDataArray;
- (CGFloat)bookmarkTopView:(YBookmarkTopView *)bookmarkTopView title:(NSString *)title width:(CGFloat)width;
@optional
- (void)bookmarkTopViewCurrentIndex:(CGFloat)index;
- (void)bookmarkTopView:(YBookmarkTopView *)bookmarkTopView titleCell:(YBookmarkTitleCell *)cell index:(NSInteger)index;

@end

@class YBBookMarkConfig;
@interface YBookmarkTopView : UIView

@property (nonatomic, weak) id <YBookmarkTopViewDelegate> delegate;
@property (nonatomic, strong) YBBookMarkConfig *configItem;
@property (nonatomic, assign) NSInteger currentIndex;
@property (nonatomic, strong) UIView * bottomLine;
@property (nonatomic, strong) UICollectionView * titleGridView;


- (void)reloadData;

- (void)scrollToIndex:(CGFloat)index;

- (void)dropShadowWithOffset:(CGSize)offset radius:(CGFloat)radius color:(UIColor *)color opacity:(CGFloat)opacity;

@end
