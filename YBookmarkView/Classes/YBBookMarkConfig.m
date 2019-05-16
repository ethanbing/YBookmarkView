//
//  YBBookMarkConfig.m
//  YBookmarkView
//
//  Created by htbing on 2019/5/15.
//

#import "YBBookMarkConfig.h"

@implementation YBBookMarkConfig

- (instancetype)init
{
    self = [super init];
    if (self) {
        [self defaultConfig];
    }
    return self;
}

- (void)defaultConfig
{
    _topViewHeight = 50;
    _fixedTitleWidth = 0;
    _maxTitleWidth = 0;
    _topViewInset = UIEdgeInsetsMake(0, 0, 0, 0);
    _titleLabelFont = [UIFont systemFontOfSize:15.0];
    _topMarkInset = UIEdgeInsetsMake(0, 10, 0, 10);
    _topMarkCellInset = UIEdgeInsetsMake(0, 10, 0, 10);
    _titleCellSpacingSize = CGSizeMake(10, 10);
    _titleColor = [UIColor blackColor];
    _titleSelectColor = [UIColor redColor];
    _topMarkSidelineSize = CGSizeMake(0, 1);
    _topViewBottomLineColor = [UIColor lightGrayColor];
    _topViewBottomLineHeight = 0.5;
    _topViewBgColor = [UIColor clearColor];
    _topMarkScrollEnabled = YES;
    _bottomMarkScrollEnabled = YES;
    _topMarkSidelineColor = [UIColor redColor];
    _titleSelectFont = _titleLabelFont;
}

@end
