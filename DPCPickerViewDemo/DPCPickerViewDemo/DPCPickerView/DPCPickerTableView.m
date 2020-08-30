//
//  DPCPickerTableView.m
//  DPCPickerViewDemo
//
//  Created by Jared on 2020/8/30.
//  Copyright © 2020 Jared. All rights reserved.
//

#import "DPCPickerTableView.h"

@implementation DPCPickerTableView

- (instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style {
    if (self = [super initWithFrame:frame style:style]) {
        self.separatorInset = UIEdgeInsetsMake(0, 0, 0, 0);
        self.tableFooterView = [UIView new];
        self.separatorStyle = UITableViewCellSeparatorStyleNone;
        self.backgroundColor = [UIColor clearColor];
        self.scrollsToTop = false;
    }
    return self;
}

@end
