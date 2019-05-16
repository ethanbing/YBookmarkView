//
//  YBookmarkViewCell.h
//  YBookmarkView
//
//  Created by yinbing on 2018/6/14.
//  Copyright © 2018年 yinbing. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YBBookMarkConfig;
@interface YBookmarkContentCell : UICollectionViewCell

//@property (nonatomic, strong, readonly) UIViewController *cellVC;
@property (nonatomic, weak) UIViewController *topVC;

- (void)updateDataForVC:(UIViewController *)vc;

@end

@interface YBookmarkTitleCell : UICollectionViewCell

@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, strong) YBBookMarkConfig *configItem;

@end
