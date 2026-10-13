#ifndef NNS_SND_MAIN_TYPES_H
#define NNS_SND_MAIN_TYPES_H

#include "nns_snd_arc_types.h"

/* Global sound system state at 0x0214E9FC. */
typedef struct NNSSndSystem {
    u32 initialized;
    u32 mode;
    u8  pad08[4];
    u32 effectBufferL;
    u32 effectBufferR;
    u32 effectBufferSize;
    u8  pad18[4];
    u32 captureActive;
    u32 lockedChannelMask;
    u32 timerChannelMask;
    u32 timerCaptureMask;
    s32 timerAlarmNo;
    u8  pad30[0x0c];
    u8  fader[0x10];
    u32 fadeFinishCheck;
    s32 lastVolume;
} NNSSndSystem;

/* Stream object (NNSSndStrm), the fields this file reads. */
typedef struct NNSSndStrm {
    u8  pad00[0x2c];
    int isSetup : 1;
    int isStarted : 1;
    int flagsRest : 30;
    u8  pad30[0x10];
    u32 pendingFrames;
    u32 pad44;
    u32 alarmNo;
    u32 channelMask;
    u32 channelCount;
} NNSSndStrm;

/* Sound archive (SDAT) FAT block header; records follow at +0x0C. */
typedef struct NNSSndArcFatBlock {
    u32 signature;
    u32 blockSize;
    u32 count;
} NNSSndArcFatBlock;

/* One FAT record (stride 0x10): file offset in the SDAT, size, loaded data pointer. */
typedef struct NNSSndArcFatRecord {
    u32 offset;
    u32 size;
    u32 data;
    u32 reserved;
} NNSSndArcFatRecord;

#endif
