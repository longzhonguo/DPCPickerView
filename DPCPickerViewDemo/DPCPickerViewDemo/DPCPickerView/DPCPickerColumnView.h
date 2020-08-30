//
//  DPCPickerColumnView.h
//  DPCPickerViewDemo
//
//  Created by Jared on 2020/8/30.
//  Copyright © 2020 Jared. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol DPCPickerColumnViewDelegate;

@interface DPCPickerColumnView : UIView
@property (nonatomic, weak) id<DPCPickerColumnViewDelegate> delegate;
@property (nonatomic, strong) NSArray *datas;
@property (nonatomic, assign) NSUInteger component;
@property (nonatomic, assign) NSUInteger selectedRow;
@property (nonatomic, strong) NSArray<UIColor *> *viewBackgroundColors;
@property (nonatomic, assign) BOOL refresh;

@property (nonatomic, copy) NSString *textOfSelectedRow;
@property (nonatomic, strong)UIColor *textColorOfSelectedRow;
@property(nonatomic, strong) UIFont *textFontOfSelectedRow;

@property (nonatomic, strong)UIColor *textColorOfOtherRow;
@property(nonatomic, strong) UIFont *textFontOfOtherRow;

@property(nonatomic, assign) BOOL isHiddenWheels;
@property(nonatomic, assign) BOOL isCycleScroll;

- (instancetype)initWithFrame:(CGRect)frame rowHeight:(CGFloat)rowHeight upLineHeight:(CGFloat)upLineHeight downLineHeight:(CGFloat)downLineHeight isCycleScroll:(BOOL)isCycleScroll datas:(NSArray *)datas;
- (void)selectRow:(NSInteger)row animated:(BOOL)animated;
@end

@protocol DPCPickerColumnViewDelegate<NSObject>
@optional
- (void)pickerColumnView:(DPCPickerColumnView *)pickerColumnView didSelectRow:(NSInteger)row;
- (void)pickerColumnView:(DPCPickerColumnView *)pickerColumnView title:(NSString *)title didSelectRow:(NSInteger)row;

- (UIFont *)pickerColumnView:(DPCPickerColumnView *)pickerColumnView textFontOfOtherRow:(NSInteger)row InComponent:(NSInteger)component;
- (UIColor *)pickerColumnView:(DPCPickerColumnView *)pickerColumnView textColorOfOtherRow:(NSInteger)row InComponent:(NSInteger)component;
@end
