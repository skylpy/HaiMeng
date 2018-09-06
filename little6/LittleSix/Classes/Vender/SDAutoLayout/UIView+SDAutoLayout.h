//
//  UIView+SDAutoLayout.h
//  LittleSix
//
//  Created by GMAR on 2017/3/6.
//  Copyright © 2017年 ZhiHua Shen. All rights reserved.
//

// 如果需要用“断言”调试程序请打开此宏
//#define SDDebugWithAssert

#import <UIKit/UIKit.h>

@class SDAutoLayoutModel, SDUIViewCategoryManager;

typedef SDAutoLayoutModel * (^MarginToView)(UIView *toView, CGFloat value);
typedef SDAutoLayoutModel * (^Margin)(CGFloat value);
typedef SDAutoLayoutModel * (^MarginEqualToView)(UIView *toView);
typedef SDAutoLayoutModel * (^WidthHeight)(CGFloat value);
typedef SDAutoLayoutModel * (^WidthHeightEqualToView)(UIView *toView, CGFloat ratioValue);
typedef SDAutoLayoutModel * (^AutoHeight)(CGFloat ratioValue);
typedef SDAutoLayoutModel * (^SameWidthHeight)();
typedef void (^SpaceToSuperView)(UIEdgeInsets insets);

@interface SDAutoLayoutModel : NSObject

/*
 *************************说明************************

 方法名中带有“SpaceToView”的需要传递2个参数：（UIView）参照view 和 （CGFloat）间距数值
 方法名中带有“RatioToView”的需要传递2个参数：（UIView）参照view 和 （CGFloat）倍数
 方法名中带有“EqualToView”的需要传递1个参数：（UIView）参照view
 方法名中带有“Is”的需要传递1个参数：（CGFloat）数值

 *****************************************************
 */

/* 设置距离其它view的间距 */

/** 左边到其参照view之间的间距，参数为“(View, CGFloat)”  */
@property (nonatomic, copy, readonly) MarginToView leftSpaceToView;
/** 右边到其参照view之间的间距，参数为“(View, CGFloat)”  */
@property (nonatomic, copy, readonly) MarginToView rightSpaceToView;
/** 顶部到其参照view之间的间距，参数为“(View, CGFloat)”  */
@property (nonatomic, copy, readonly) MarginToView topSpaceToView;
/** 底部到其参照view之间的间距，参数为“(View, CGFloat)”  */
@property (nonatomic, copy, readonly) MarginToView bottomSpaceToView;

/* 设置x、y、width、height、centerX、centerY 值 */

/** x值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) Margin xIs;
/** y值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) Margin yIs;
/** centerX值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) Margin centerXIs;
/** centerY值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) Margin centerYIs;
/** 宽度值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) WidthHeight widthIs;
/** 高度值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) WidthHeight heightIs;

/* 设置最大宽度和高度、最小宽度和高度 */

/** 最大宽度值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) WidthHeight maxWidthIs;
/** 最大高度值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) WidthHeight maxHeightIs;
/** 最小宽度值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) WidthHeight minWidthIs;
/** 最小高度值，参数为“(CGFloat)”  */
@property (nonatomic, copy, readonly) WidthHeight minHeightIs;

/* 设置和某个参照view的边距相同 */

/** 左间距与参照view相同，参数为“(View)”  */
@property (nonatomic, copy, readonly) MarginEqualToView leftEqualToView;
/** 右间距与参照view相同，参数为“(View)”  */
@property (nonatomic, copy, readonly) MarginEqualToView rightEqualToView;
/** 顶部间距与参照view相同，参数为“(View)”  */
@property (nonatomic, copy, readonly) MarginEqualToView topEqualToView;
/** 底部间距与参照view相同，参数为“(View)”  */
@property (nonatomic, copy, readonly) MarginEqualToView bottomEqualToView;
/** centerX与参照view相同，参数为“(View)”  */
@property (nonatomic, copy, readonly) MarginEqualToView centerXEqualToView;
/** centerY与参照view相同，参数为“(View)”  */
@property (nonatomic, copy, readonly) MarginEqualToView centerYEqualToView;

/*  设置宽度或者高度等于参照view的多少倍 */

/** 宽度是参照view宽度的多少倍，参数为“(View, CGFloat)” */
@property (nonatomic, copy, readonly) WidthHeightEqualToView widthRatioToView;
/** 高度是参照view高度的多少倍，参数为“(View, CGFloat)” */
@property (nonatomic, copy, readonly) WidthHeightEqualToView heightRatioToView;
/** 设置一个view的宽度和它的高度相同，参数为空“()” */
@property (nonatomic, copy, readonly) SameWidthHeight widthEqualToHeight;
/** 设置一个view的高度和它的宽度相同，参数为空“()” */
@property (nonatomic, copy, readonly) SameWidthHeight heightEqualToWidth;
/** 自适应高度，传入高宽比值，label可以传0实现文字高度自适应 */
@property (nonatomic, copy, readonly) AutoHeight autoHeightRatio;

/* 填充父view(快捷方法) */

/** 传入UIEdgeInsetsMake(top, left, bottom, right)，可以快捷设置view到其父view上左下右的间距  */
@property (nonatomic, copy, readonly) SpaceToSuperView spaceToSuperView;

@property (nonatomic, weak) UIView *needsAutoResizeView;

@end

@interface UIView (SDAutoHeightWidth)

/** 设置Cell的高度自适应，也可用于设置普通view内容高度自适应 */
- (void)setupAutoHeightWithBottomView:(UIView *)bottomView bottomMargin:(CGFloat)bottomMargin;

/** 用于设置普通view内容宽度自适应 */
- (void)setupAutoWidthWithRightView:(UIView *)rightView rightMargin:(CGFloat)rightMargin;

/**
 * 设置Cell的高度自适应，也可用于设置普通view内容自适应（应用于当你不确定哪个view在自动布局之后会排布在最下方最为bottomView的时候可以调用次方法将所有可能在最下方的view都传过去）
 */
- (void)setupAutoHeightWithBottomViewsArray:(NSArray *)bottomViewsArray bottomMargin:(CGFloat)bottomMargin;

/** 主动刷新布局（如果你需要设置完布局代码就获得view的frame请调用此方法） */
- (void)updateLayout;

- (void)clearAutoHeigtSettings;
- (void)clearAutoWidthSettings;

@property (nonatomic) CGFloat autoHeight;

@property (nonatomic, readonly) SDUIViewCategoryManager *sd_categoryManager;

@property (nonatomic, readonly) NSMutableArray *sd_bottomViewsArray;
@property (nonatomic) CGFloat sd_bottomViewBottomMargin;

@property (nonatomic) NSArray *sd_rightViewsArray;
@property (nonatomic) CGFloat sd_rightViewRightMargin;

@end

@interface UIView (SDLayoutExtention)

/** 自动布局完成后的回调block，可以在这里获取到view的真实frame  */
@property (nonatomic) void (^didFinishAutoLayoutBlock)(CGRect frame);

/** 添加一组子view  */
- (void)sd_addSubviews:(NSArray *)subviews;

/* 设置圆角 */

/** 设置圆角半径值  */
@property (nonatomic, strong) NSNumber *sd_cornerRadius;
/** 设置圆角半径值为view宽度的多少倍  */
@property (nonatomic, strong) NSNumber *sd_cornerRadiusFromWidthRatio;
/** 设置圆角半径值为view高度的多少倍  */
@property (nonatomic, strong) NSNumber *sd_cornerRadiusFromHeightRatio;

/** 设置等宽子view（子view需要在同一水平方向） */
@property (nonatomic, strong) NSArray *sd_equalWidthSubviews;

@end

@interface UIView (SDAutoLayout)

/** 开始自动布局  */
- (SDAutoLayoutModel *)sd_layout;

/** 清空之前的自动布局设置，重新开始自动布局(重新生成布局约束并使其在父view的布局序列数组中位置保持不变)  */
- (SDAutoLayoutModel *)sd_resetLayout;

/** 清空之前的自动布局设置，重新开始自动布局(重新生成布局约束并添加到父view布局序列数组中的最后一个位置)  */
- (SDAutoLayoutModel *)sd_resetNewLayout;

/** 清空之前的自动布局设置  */
- (void)sd_clearAutoLayoutSettings;

/** 将自身frame清零（一般在cell内部控件重用前调用）  */
- (void)sd_clearViewFrameCache;

/** 将自己的需要自动布局的subviews的frame清零（一般在cell内部控件重用前调用）  */
- (void)sd_clearSubviewsAutoLayoutFrameCaches;

/** 设置固定宽度保证宽度不在自动布局过程再做中调整  */
@property (nonatomic, strong) NSNumber *fixedWith;

/** 设置固定高度保证高度不在自动布局过程中再做调整  */
@property (nonatomic, strong) NSNumber *fixedHeight;

/** 所属tableview（目前为cell专用属性，后期会扩展到其他view） */
@property (nonatomic) UITableView *sd_tableView;

/** cell的indexPath（目前为cell专用属性，后期会扩展到cell的其他子view） */
@property (nonatomic) NSIndexPath *sd_indexPath;

// -------------------库内部使用-----------------------
- (NSMutableArray *)autoLayoutModelsArray;
- (void)addAutoLayoutModel:(SDAutoLayoutModel *)model;
@property (nonatomic) SDAutoLayoutModel *ownLayoutModel;
@property (nonatomic, strong) NSNumber *sd_maxWidth;
@property (nonatomic, strong) NSNumber *autoHeightRatioValue;
// -------------------库内部使用-----------------------

@end

@interface UIScrollView (SDAutoContentSize)

/** 设置scrollview内容竖向自适应 */
- (void)setupAutoContentSizeWithBottomView:(UIView *)bottomView bottomMargin:(CGFloat)bottomMargin;

/** 设置scrollview内容横向自适应 */
- (void)setupAutoContentSizeWithRightView:(UIView *)rightView rightMargin:(CGFloat)rightMargin;

@end

@interface UILabel (SDLabelAutoResize)

/** 是否是attributedString */
@property (nonatomic) BOOL isAttributedContent;

/** 设置单行文本label宽度自适应 */
- (void)setSingleLineAutoResizeWithMaxWidth:(CGFloat)maxWidth;

@end

// ----------------- 以下为此库内部需要用到的类和方法（可以不用看）----------------

@interface SDAutoLayoutModelItem : NSObject

@property (nonatomic, strong) NSNumber *value;
@property (nonatomic, weak) UIView *refView;

@end

@interface UIView (SDChangeFrame)

@property (nonatomic) CGFloat left;
@property (nonatomic) CGFloat top;
@property (nonatomic) CGFloat right;
@property (nonatomic) CGFloat bottom;
@property (nonatomic) CGFloat centerX;
@property (nonatomic) CGFloat centerY;

@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat height;

@property (nonatomic) CGPoint origin;
@property (nonatomic) CGSize size;

@end

@interface SDUIViewCategoryManager : NSObject

@property (nonatomic, strong) NSArray *rightViewsArray;
@property (nonatomic, assign) CGFloat rightViewRightMargin;

@property (nonatomic, weak) UITableView *sd_tableView;
@property (nonatomic, strong) NSIndexPath *sd_indexPath;

@end
