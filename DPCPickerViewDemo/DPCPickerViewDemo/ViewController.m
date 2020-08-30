//
//  ViewController.m
//  DPCPickerViewDemo
//
//  Created by Jared on 2020/8/30.
//  Copyright © 2020 Jared. All rights reserved.
//

#import "ViewController.h"
#import "DPCPickerView.h"

#define UIColorFromRGBA(rgbValue, alphaValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0x0000FF))/255.0 \
alpha:alphaValue]

@interface ViewController ()<DPCPickerViewDelegate, DPCPickerViewDataSource>
//@property (nonatomic, weak) IBOutlet DPCPickerView *pickerView;
@property (nonatomic, strong) DPCPickerView *pickerView;
@property (nonatomic, strong) NSString *string;
@property (nonatomic, strong) NSArray *datas1;
@property (nonatomic, strong) NSArray *datas2;
@property (nonatomic, strong) NSArray *datas3;
@end

#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.pickerView = [[DPCPickerView alloc] initWithFrame:CGRectMake(16, 200, kScreenWidth-32, 238)];
    self.pickerView.backgroundColor = UIColor.whiteColor;
    [self.view addSubview:self.pickerView];
    self.datas1 = @[@"北京", @"上海", @"天津", @"重庆", @"四川", @"贵州", @"云南", @"西藏", @"河南", @"湖北"];
    self.datas2 = @[@"东城区",@"西城区",@"崇文区",@"宣武区",@"朝阳区",@"丰台区",@"石景山区",@"海淀区",@"门头沟区",@"房山区"];
    self.datas3 = @[@"黄浦区",@"卢湾区",@"徐汇区",@"长宁区",@"静安区",@"普陀区",@"闸北区",@"虹口区",@"杨浦区",@"宝山区"];
    self.pickerView.delegate = self;
    self.pickerView.dataSource = self;
    self.pickerView.type = DPCPickerViewLineTypelineSegment;
    
    [self.pickerView selectRow:5 inComponent:0 animated:true];
//    [self.pickerView selectRow:7 inComponent:1 animated:true];
    self.pickerView.rowHeight = 45;
    self.pickerView.isHiddenMiddleText = true;
    
//    self.pickerView.verticalLineWidth = 1;
    //设置线条的颜色
    self.pickerView.lineBackgroundColor = UIColorFromRGBA(0xF0F0F0, 1);
    //设置选中行的字体颜色
    self.pickerView.textColorOfSelectedRow = UIColorFromRGBA(0x0CB65B, 1);
    //设置未选中行的字体颜色
    self.pickerView.textColorOfOtherRow = UIColorFromRGBA(0x969696, 1);
    self.pickerView.textFontOfSelectedRow = [UIFont systemFontOfSize:18 weight:UIFontWeightMedium];
    self.pickerView.textFontOfOtherRow = [UIFont systemFontOfSize:14 weight:UIFontWeightRegular];
}

#pragma UIPickerViewDataSource
- (NSInteger)numberOfComponentsInPickerView:(DPCPickerView *)pickerView {
    return 3;
}

- (NSInteger)pickerView:(DPCPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return self.datas1.count;
}
#pragma UIPickerViewDelegate
- (nullable NSString *)pickerView:(DPCPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
//    return self.datas1[row];
    if (component == 0) {
        return self.datas1[row];
    }
    if (component == 1) {
        return self.datas2[row];
    }
    return self.datas3[row];
}

- (void)pickerView:(DPCPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    NSLog(@"row = %ld component = %ld", row, component);
}

@end

