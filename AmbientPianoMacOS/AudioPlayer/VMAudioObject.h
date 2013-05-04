//
//  VMAudioObject.h
//  GotchaP
//
//  Created by sumiisan on 2013/05/03.
//
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import "VMPrimitives.h"

@interface VMAudioObject : NSObject {
	//  Core Audio file info
	ExtAudioFileRef					audioFile;
	AudioStreamBasicDescription		audioFileFormat;
	AudioStreamBasicDescription		cachedAudioFormat;
	void							*waveData;
}

@property (nonatomic)			UInt64 numberOfFrames;

- (OSErr)load:(NSString*)path;
- (int)bytesPerFrame;
- (int)numberOfChannels;
- (int)framesPerSecond;
- (void*)dataAtFrame:(NSInteger)frame;

- (NSImage*)drawWaveImageWithSize:(NSSize)size foreColor:(NSColor*)foreColor backColor:(NSColor*)backColor;

@end