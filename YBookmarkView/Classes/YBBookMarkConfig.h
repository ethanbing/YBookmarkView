//
//  YBBookMarkConfig.h
//  YBookmarkView
//
//  Created by htbing on 2019/5/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YBBookMarkConfig : NSObject

#pragma mark - TopView config
/** *  顶部Mark高度  默认50.0 */
@property (nonatomic, assign) CGFloat topViewHeight;
/** *  顶部view内边距 默认UIEdgeInsetsMake(0, 0, 0, 0) */
@property (nonatomic) UIEdgeInsets topViewInset;
//@property (nonatomic, assign) CGFloat bottomMarkHeight;
/** *  顶部Mark背景色  默认白色 */
@property (nonatomic, strong) UIColor * topViewBgColor;
/** *  topView右侧view*/
@property (nonatomic, strong) UIView * topViewRightView;
/** *  topView底部分割线*/
@property (nonatomic, assign) CGFloat topViewBottomLineHeight;
@property (nonatomic, strong) UIColor * topViewBottomLineColor;
@property (nonatomic, strong) UIImage * topViewShadowImage;

#pragma mark - TopMark config


/** *  title 最小间距 (minimumLineSpacing,minimumInteritemSpacing)
 默认CGSizeMake(10, 10) */
@property (nonatomic) CGSize titleCellSpacingSize;
/** *  顶部Mark内边距 默认UIEdgeInsetsMake(0, 10, 0, 10) */
@property (nonatomic) UIEdgeInsets topMarkInset;
/** *  顶部Mark内边距 默认UIEdgeInsetsMake(0, 10, 0, 10) */
@property (nonatomic) UIEdgeInsets topMarkCellInset;
/** *  顶部的Mark滚动手势激活  默认 YES 激活 */
@property (nonatomic, assign) BOOL topMarkScrollEnabled;
/** *  topView底部 滑块   topViewSidelineSize 宽度设置0  就是自动宽度*/
@property (nonatomic, assign) CGSize topMarkSidelineSize;
@property (nonatomic, strong) UIColor * topMarkSidelineColor;


#pragma mark - TopTitle config
/** *  最大标题宽度 */
@property (nonatomic, assign) CGFloat maxTitleWidth;
/** *  固定标题宽度 默认0 自动宽度*/
@property (nonatomic, assign) CGFloat fixedTitleWidth;
/** *  标题字体*/
@property (nonatomic, strong) UIFont * titleLabelFont;
@property (nonatomic, strong) UIFont * titleSelectFont;
/** *  标题颜色*/
@property (nonatomic, strong) UIColor * titleColor;
/** *  标题选中颜色*/
@property (nonatomic, strong) UIColor * titleSelectColor;

#pragma mark - BottomMark config
/** *  下面的Mark滚动手势激活  默认 YES 激活 */
@property (nonatomic, assign) BOOL bottomMarkScrollEnabled;


/** 映射titleCell 就是继承YBookmarkTitleCell 的类名 */
@property (nonatomic, copy) NSString * actualTitleCell;

@end

NS_ASSUME_NONNULL_END
