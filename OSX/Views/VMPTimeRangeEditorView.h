//
//  VMPTimeRangeEditorView.h
//  OnTheFly
//
//  Created by sumiisan on 2013/04/28.
//
//

#import <Cocoa/Cocoa.h>
#import "VMPCanvas.h"
#import "VMPrimitives.h"

typedef enum {
	VMPTimeUnit_msec,
	VMPTimeUnit_beat,
	VMPTimeUnit_bar44,
	VMPTimeUnit_bar34
} VMPTimeUnitType;


@interface VMPTimeRangeEditorView : NSViewController <NSControlTextEditingDelegate> {
	VMTime value1;
	VMTime value2;
}
- (void)setTitle:(VMString*)title caption1:(VMString*)caption1 caption2:(VMString*)caption2;
- (VMString*)time1;
- (VMString*)time2;
- (void)setTime1:(VMString*)time1 time2:(VMString*)time2;

- (IBAction)unitSelected:(id)sender;

@property (nonatomic, VMWeak) IBOutlet NSTextField			*titleLabel;
@property (nonatomic, VMWeak) IBOutlet NSTextField			*time1Label;
@property (nonatomic, VMWeak) IBOutlet NSTextField			*time2Label;
@property (nonatomic, VMWeak) IBOutlet NSTextField			*bpmLabel;

@property (nonatomic, VMWeak) IBOutlet NSTextField			*time1Field;
@property (nonatomic, VMWeak) IBOutlet NSTextField			*time2Field;
@property (nonatomic, VMWeak) IBOutlet NSTextField			*bpmField;
@property (nonatomic, VMWeak) IBOutlet NSPopUpButton		*unitSelector1;
@property (nonatomic, VMWeak) IBOutlet NSPopUpButton		*unitSelector2;

@end
