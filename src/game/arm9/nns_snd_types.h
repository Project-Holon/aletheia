/*
 * nns_snd_types.h: NitroSystem sound player state (nns_snd_player.c): the
 * player slot table, the sequence player pool, the sequence handle and the
 * per-player heap block.  The sound heap and list types come from
 * nns_snd_arc_types.h.
 */
#ifndef NNS_SND_TYPES_H
#define NNS_SND_TYPES_H

#include "../arm9/nns_snd_arc_types.h"

#include "../types.h"

/* Linear volume fader: step counts up to duration (same layout as nns_snd_fader.c). */
typedef struct SndFader {
    s32 start;
    s32 target;
    s32 step;
    s32 duration;
} SndFader;

/* States of SndSeqPlayer.state. */
#define SND_SEQ_STATE_FREE     0
#define SND_SEQ_STATE_PLAYING  1
#define SND_SEQ_STATE_STOPPING 2

/* Values of SndSeqPlayer.seqType. */
#define SND_SEQ_TYPE_SEQ    1
#define SND_SEQ_TYPE_SEQARC 2

/* One player slot (0x24 bytes): the sequences playing on it, the heaps it owns, its limits. */
typedef struct SndPlayer {
    NNSFndList seqList;
    NNSFndList heapList;
    u32        playableSeqCount;
    u32        allocatableChannelMask;
    u8         volume;
    u8         pad21[3];
} SndPlayer;

struct SndSeqPlayer;

/* Buffer of one heap block a player owns: the sequence data heap created inside it. */
typedef struct SndPlayerHeap {
    NNSFndLink            link;
    NNSSndHeap           *heap;
    struct SndSeqPlayer  *pOwner;
    u32                   playerNo;
    u8                    buffer[1];
} SndPlayerHeap;

struct SndHandle;

/* One sequence player (0x44 bytes), in the pool of 16 and in the active list. */
typedef struct SndSeqPlayer {
    struct SndHandle *pHandle;
    SndPlayer        *pPlayer;
    SndPlayerHeap    *pPlayerHeap;
    NNSFndLink        playerLink;
    NNSFndLink        activeLink;
    SndFader          volumeFader;
    u8                state;
    u8                isPrepared;
    u8                isPaused;
    u8                startPending;
    u32               commandTag;
    u16               seqType;
    u16               pad36;
    u16               seqNo;
    u16               seqArcIndex;
    u8                playerNo;
    u8                priority;
    s16               appliedVolume;
    u8                initialVolume;
    u8                volume;
    u8                pad42[2];
} SndSeqPlayer;

/* What a caller keeps to control the sequence it started. */
typedef struct SndHandle {
    SndSeqPlayer *volatile player;
} SndHandle;

/* Callback that refills the stream buffers: (isTimerCall, channel count,
 * buffer address table, length, format, user data). */
typedef void (*NNSSndStrmCallback)(u32 isTimerCall, s32 numChannels, u32 *bufferTable, u32 length, u32 format, u32 userData);

/* Hardware alarm slot of a stream: handler and its argument, then alarm state. */
typedef struct SndStrmAlarm {
    void (*handler)(void *arg);
    void *arg;
    u8 reserved08[8];
} SndStrmAlarm;

/* One stream (0x58 bytes).  Embedded at offset 0 of each SndTrack slot. */
typedef struct SndStrm {
    NNSFndLink link;
    SndStrmAlarm alarm[2];
    u32 format;
    union {
        u32 flags;
        struct {
            s32 isSetup : 1;
            s32 isStarted : 1;
            u32 reserved : 30;
        };
    };
    u32 bufferSize;
    s32 frames;
    NNSSndStrmCallback callback;
    u32 userData;
    s32 frameIdx;
    s32 volume;
    s32 timerNo;
    u32 channelMask;
    s32 numChannels;
    u8 channel[4];
} SndStrm;

#endif
