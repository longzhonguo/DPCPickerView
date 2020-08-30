//
//  DPCPickerView.h
//  DPCPickerViewDemo
//
//  Created by Jared on 2020/8/30.
//  Copyright © 2020 Jared. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, DPCPickerViewLineType) {
    DPCPickerViewLineTypeline,
    DPCPickerViewLineTypelineSegment,
    DPCPickerViewLineTypelineVertical,
};
@protocol DPCPickerViewDataSource, DPCPickerViewDelegate;

@interface DPCPickerView : UIView
@property(nonatomic, assign) DPCPickerViewLineType type;
@property(nonatomic,weak) id<DPCPickerViewDataSource> dataSource;    // default is nil. weak reference
@property(nonatomic,weak) id<DPCPickerViewDelegate>   delegate;      // default is nil. weak reference

@property(nonatomic, strong) UIColor *lineBackgroundColor;          // default is [UIColor grayColor]
@property (nonatomic, assign) CGFloat lineHeight;                   // default is 0.5

@property(nonatomic, strong) UIColor *verticalLineBackgroundColor; // default is [UIColor grayColor] type3 vertical line
@property (nonatomic, assign) CGFloat verticalLineWidth; // default is 0.5

@property (nonatomic, strong)UIColor *textColorOfSelectedRow;     // [UIColor blackColor]
@property(nonatomic, strong) UIFont *textFontOfSelectedRow;

@property (nonatomic, strong)UIColor *textColorOfOtherRow;        // default is [UIColor grayColor]
@property(nonatomic, strong) UIFont *textFontOfOtherRow;

// info that was fetched and cached from the data source and delegate
@property(nonatomic,readonly) NSInteger numberOfComponents;

@property (nonatomic) CGFloat rowHeight;             // default is 44

@property(nonatomic, assign) BOOL isHiddenMiddleText; // default is true  true -> hidden
@property(nonatomic, strong) UIColor *middleTextColor;
@property(nonatomic, strong) UIFont *middleTextFont;

@property(nonatomic, assign) BOOL isHiddenWheels; // default is true  true -> hidden
@property(nonatomic, assign) BOOL isCycleScroll; //default is false

- (NSInteger)numberOfRowsInComponent:(NSInteger)component;

// selection. in this case, it means showing the appropriate row in the middle
- (void)selectRow:(NSInteger)row inComponent:(NSInteger)component animated:(BOOL)animated;// scrolls the specified row to center.

- (NSInteger)selectedRowInComponent:(NSInteger)component;// returns selected row. -1 if nothing selected
- (NSString *)textOfSelectedRowInComponent:(NSInteger)component;
// Reloading whole view or single component
- (void)reloadAllComponents;
- (void)reloadComponent:(NSInteger)component;
- (void)reloadComponent:(NSInteger)component refresh:(BOOL)refresh;
@end

@protocol DPCPickerViewDataSource<NSObject>
@required
// returns the number of 'columns' to display.
- (NSInteger)numberOfComponentsInPickerView:(DPCPickerView *)pickerView;

// returns the # of rows in each component..
- (NSInteger)pickerView:(DPCPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component;
@end

@protocol DPCPickerViewDelegate<NSObject>
@optional
// these methods return either a plain NSString, a NSAttributedString, or a view (e.g UILabel) to display the row for the component.
// for the view versions, we cache any hidden and thus unused views and pass them back for reuse.
// If you return back a different object, the old one will be released. the view will be centered in the row rect
- (NSString *)pickerView:(DPCPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component;
- (NSAttributedString *)pickerView:(DPCPickerView *)pickerView attributedTitleForRow:(NSInteger)row forComponent:(NSInteger)component; // attributed title is favored if both methods are implemented
- (UIColor *)pickerView:(DPCPickerView *)pickerView viewBackgroundColorForRow:(NSInteger)row forComponent:(NSInteger)component;

- (void)pickerView:(DPCPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
- (void)pickerView:(DPCPickerView *)pickerView title:(NSString *)title didSelectRow:(NSInteger)row inComponent:(NSInteger)component;

- (CGFloat)rowHeightInPickerView:(DPCPickerView *)pickerView forComponent:(NSInteger)component;

- (NSString *)pickerView:(DPCPickerView *)pickerView middleTextForcomponent:(NSInteger)component;
- (CGFloat)pickerView:(DPCPickerView *)pickerView middleTextSpaceForcomponent:(NSInteger)component;

// type is DPCPickerViewLineTypelineVertical vertical line
- (UIColor *)pickerView:(DPCPickerView *)pickerView verticalLineBackgroundColorForComponent:(NSInteger)component;
- (CGFloat)pickerView:(DPCPickerView *)pickerView verticalLineWidthForComponent:(NSInteger)component;

- (UIColor *)pickerView:(DPCPickerView *)pickerView upLineBackgroundColorForComponent:(NSInteger)component;
- (UIColor *)pickerView:(DPCPickerView *)pickerView downLineBackgroundColorForComponent:(NSInteger)component;

- (CGFloat)pickerView:(DPCPickerView *)pickerView upLineHeightForComponent:(NSInteger)component;
- (CGFloat)pickerView:(DPCPickerView *)pickerView downLineHeightForComponent:(NSInteger)component;

- (UIFont *)pickerView:(DPCPickerView *)pickerView textFontOfSelectedRowInComponent:(NSInteger)component;
- (UIFont *)pickerView:(DPCPickerView *)pickerView textFontOfOtherRowInComponent:(NSInteger)component;

- (UIColor *)pickerView:(DPCPickerView *)pickerView textColorOfSelectedRowInComponent:(NSInteger)component;
- (UIColor *)pickerView:(DPCPickerView *)pickerView textColorOfOtherRowInComponent:(NSInteger)component;

- (UIFont *)pickerView:(DPCPickerView *)pickerView textFontOfOtherRow:(NSInteger)row InComponent:(NSInteger)component;
- (UIColor *)pickerView:(DPCPickerView *)pickerView textColorOfOtherRow:(NSInteger)row InComponent:(NSInteger)component;
@end
