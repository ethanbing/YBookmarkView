# YBookmarkView

[![CI Status](https://img.shields.io/travis/380711712@qq.com/YBookmarkView.svg?style=flat)](https://travis-ci.org/380711712@qq.com/YBookmarkView)
[![Version](https://img.shields.io/cocoapods/v/YBookmarkView.svg?style=flat)](https://cocoapods.org/pods/YBookmarkView)
[![License](https://img.shields.io/cocoapods/l/YBookmarkView.svg?style=flat)](https://cocoapods.org/pods/YBookmarkView)
[![Platform](https://img.shields.io/cocoapods/p/YBookmarkView.svg?style=flat)](https://cocoapods.org/pods/YBookmarkView)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

YBookmarkView is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'YBookmarkView'
```

## Usage

### 1、创建初始化BookmarkView

```objective-c
- (YBookmarkView *)bookmarkView
{
    if (!_bookmarkView) {
        _bookmarkView = [[YBookmarkView alloc] initWithFrame:self.view.frame];
        _bookmarkView.dataSource = self;
        _bookmarkView.delegate = self;
        _bookmarkView.topMarkHeight = 50;
        _bookmarkView.titleSelectFont = [UIFont systemFontOfSize:17];
//        _bookmarkView.fixedTitleWidth = 100; //如果标题是固定宽度设置
        //还有很多参数可以设置，自己体会吧 😊
    }
    return _bookmarkView;
}
```

### 2、实现几个DataSource方法

```objective-c
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
```

### 3、装载数据

```objective-c
[self.bookmarkView reloadData];
```



#### 4、YBookMarkViewDelegate 回调

```objective-c
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
```

## Author

Ethanbing, 380711712@qq.com

## License

YBookmarkView is available under the MIT license. See the LICENSE file for more info.
