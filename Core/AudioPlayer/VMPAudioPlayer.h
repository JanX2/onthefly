//
//  AudioPlayer.h
//  OnTheFly
//
//  Created by cboy on 10/02/25.
//  Copyright 2010 sumiisan (aframasda.com). All rights reserved.
//

#import <Foundation/Foundation.h>
#include "MultiPlatform.h"
#import "VMPrimitives.h"

#import <AudioToolbox/AudioQueue.h>
#import <AudioToolbox/AudioFile.h>
#import "VMPlayerBase.h"

typedef enum {
	pp_idle = 0,					//	isBusy = NO		isPlaying = NO		didPlay = YES
	
	//	here starts the lifecycle:
	pp_warmUp,						//	isBusy = YES	isPlaying = NO		didPlay = NO
	pp_fileOpened,					//	isBusy = YES	isPlaying = NO		didPlay = NO
	pp_preLoad,						//	isBusy = YES	isPlaying = NO		didPlay = NO
    pp_prime,						//	isBusy = YES	isPlaying = NO		didPlay = NO
	pp_waitCue,						//	isBusy = YES	isPlaying = NO		didPlay = NO
	pp_play,						//	isBusy = YES	isPlaying = YES		didPlay = YES
	//	..and when playback has ended, the processphase is set to pp_idle.
	
	//	a special status while locked.
    pp_locked = 999					//	isBusy = YES	isPlaying = NO		didPlay = NO
} vmpAudioPlayerProcessPhase;

@interface VMPAudioPlayer : VMPlayerBase {
	int								playerId;
	
//	temporary var
	vmpAudioPlayerProcessPhase		processPhase;
	BOOL							trackClosed;	
    NSTimeInterval                  shiftTime;  	//  shift preload timing intended to distribute HD/CPU impact
    
//  props
	VMTime							fileDuration;
    VMTime							fragDuration;
	VMTime							offset;

//  audio file    
	NSString						*filePathToRead;
	NSString						*fragId;
    
//  Core Audio file info
	AudioFileID						audioFile;
	AudioStreamBasicDescription		dataFormat;
	AudioQueueRef					queue;
	UInt64							packetIndex;
	UInt32							numPacketsToRead;
	AudioStreamPacketDescription	*packetDescs;
    AudioChannelLayout              *channelLayout;
    UInt32                          channelLayoutSize;
	
//	audio buffer
	AudioQueueBufferRef				buffers[kNumberOfQueueBuffers];
    UInt64                          numTotalPackets;
	
//	waveform cache
//	double							waveformCache[kWaveFormCacheFrames];
//	double							waveformSampleInterval;
}

@property (nonatomic,   VMStrong)				NSString *fragId;
@property (readonly)						int playerId;
@property (readonly)						NSTimeInterval fileDuration;
@property (nonatomic)						NSTimeInterval fragDuration;
@property (nonatomic)						NSTimeInterval offset;		//	not used internally.

- (id)initWithId:(int)identifier;
- (void)preloadAudio:(NSString *)path atTime:(float)inTime;
- (void)setVolume:(Float32)volume;
- (void)play;
- (void)pause;
- (void)stop;

- (BOOL)isBusy;			//	not idling( playing or doing some warm-up procedure )
- (BOOL)isPlaying;		//	playback
- (BOOL)didPlay;

- (Float32)loadedRatio;	//	for displaying purpose


@end
