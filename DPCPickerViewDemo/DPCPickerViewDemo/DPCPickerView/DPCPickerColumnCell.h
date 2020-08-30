//
//  DPCPickerColumnCell.h
//  DPCPickerViewDemo
//
//  Created by Jared on 2020/8/30.
//  Copyright © 2020 Jared. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DPCPickerColumnCell : UITableViewCell

@property (nonatomic, weak) UILabel *label;
- (void)transformWith:(CGFloat)angle scale:(CGFloat)scale;

@end

NS_ASSUME_NONNULL_END
