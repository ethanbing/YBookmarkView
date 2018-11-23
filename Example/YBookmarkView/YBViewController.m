//
//  YBViewController.m
//  YBookmarkView
//
//  Created by 380711712@qq.com on 11/23/2018.
//  Copyright (c) 2018 380711712@qq.com. All rights reserved.
//

#import "YBViewController.h"
#import "YBookmarkView.h"
#import "YBFirstViewController.h"
#import "YBSecondViewController.h"
#import "YBThirdViewController.h"
#import "YBMoreViewController.h"

@interface YBViewController ()<YBookMarkViewDataSource,YBookMarkViewDelegate>

@property (nonatomic, strong) YBookmarkView * bookmarkView;

@end

@implementation YBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"YBookmarkView Demo";
    [self.view addSubview:self.bookmarkView];
    [self.bookmarkView reloadData];
}

- (NSInteger)numberOfItemInBookMarkView:(YBookmarkView *)bookMarkView
{
    return 15;
}

- (NSString *)bookMarkView:(YBookmarkView *)bookMarkView titleAtIndex:(NSInteger)index
{
    return [NSString stringWithFormat:@"标签%d",(int)index+1];
}

- (UIViewController *)bookMarkView:(YBookmarkView *)bookMarkView viewAtIndex:(NSInteger)index viewRect:(CGRect)viewRect
{
    UIViewController * vc = nil;
    switch (index) {
        case 0:
        {
            vc = [YBFirstViewController new];
        }
            break;
        case 2:
        {
            vc = [YBThirdViewController new];
        }
            break;
            
        default:{
           YBMoreViewController * moreVC = [YBMoreViewController new];
            moreVC.index = index;
            return moreVC;
        }
            break;
    }
    if (vc) {
        return vc;
    }
    return [UIViewController new];
}

- (void)bookMarkView:(YBookmarkView *)bookMarkView didSelectTitleAtIndex:(NSInteger)index
{
    NSLog(@"点击了标题");
}

- (void)bookMarkView:(YBookmarkView *)bookMarkView didScrollToIndex:(NSInteger)index
{
    NSLog(@"滚动到  第 %d 个标签页",(int)index);
}

- (void)bookMarkView:(YBookmarkView *)bookMarkView willDisplayingVC:(__kindof UIViewController *)vc index:(NSInteger)index
{
    NSLog(@"第 %d 标签页将要显示",(int)index);
}

- (void)bookMarkView:(YBookmarkView *)bookMarkView didEndDisplayingVC:(__kindof UIViewController *)vc index:(NSInteger)index
{
    NSLog(@"第 %d 标签页结束显示，就是页面不显示了",(int)index);
}

- (YBookmarkView *)bookmarkView
{
    if (!_bookmarkView) {
        _bookmarkView = [[YBookmarkView alloc] initWithFrame:self.view.frame];
        _bookmarkView.dataSource = self;
        _bookmarkView.delegate = self;
        _bookmarkView.topMarkHeight = 50;
        _bookmarkView.titleSelectFont = [UIFont systemFontOfSize:17];
//        _bookmarkView.fixedTitleWidth = 100; //如果标题固定宽度设置
        //还有很多参数可以设置，自己体会吧 😊
        
    }
    return _bookmarkView;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
