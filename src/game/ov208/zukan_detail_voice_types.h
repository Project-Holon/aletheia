/*
 * Work object of the Pokedex detail voice screen (cry and waveform view, ov208).
 * Allocated by ZUKAN_DETAIL_VOICE_Init, size checked below.
 */
#ifndef ZUKAN_DETAIL_VOICE_TYPES_H
#define ZUKAN_DETAIL_VOICE_TYPES_H

#include "zukan_detail_common_shared_types.h"

struct Obj;
struct Bmp;
struct Descriptor;
struct Ov208Win;
struct Ov208PalFade;

/* Number of Pokemon slots (current and next) that are cross-faded. */
#define ZUKAN_DETAIL_VOICE_SLOT_COUNT 2
/* Number of digit and button actors. */
#define ZUKAN_DETAIL_VOICE_ACTOR_COUNT 7

struct ZukanDetailVoice {
    /* 0x00 */ unsigned int clactSys;
    /* 0x04 */ unsigned int font;
    /* 0x08 */ void *printQue;
    /* 0x0C */ struct Descriptor *nameWin;
    /* 0x10 */ int namePending;
    /* 0x14 */ unsigned short *waveTileMap;       /* 31 x 15 map entries, allocated 0x3A2 bytes */
    /* 0x18 */ short scrollSubPixels;             /* pixels into the current 8 pixel column */
    /* 0x1A */ short scrollColumn;                /* first visible tile column of the ring */
    /* 0x1C */ unsigned int waveBgDirty;
    /* 0x20 */ struct Descriptor *waveWin;
    /* 0x24 */ unsigned char waveDelay;
    /* 0x25 */ unsigned char pad25;               /* open item: never read */
    /* 0x26 */ unsigned short shownSpecies;
    /* 0x28 */ unsigned short shownForm;
    /* 0x2A */ unsigned char pad2A[2];            /* open item: never read */
    /* 0x2C */ struct Bmp *waveBmp;               /* 121 x 15 bitmap of the whole cry waveform */
    /* 0x30 */ short waveWidth;                   /* columns of waveBmp that hold waveform */
    /* 0x32 */ short waveCopied;                  /* columns already copied to the window */
    /* 0x34 */ signed char *voiceData;
    /* 0x38 */ unsigned int voiceLengthMs;
    /* 0x3C */ unsigned int palRes[ZUKAN_DETAIL_VOICE_SLOT_COUNT];
    /* 0x44 */ unsigned int charRes[ZUKAN_DETAIL_VOICE_SLOT_COUNT];
    /* 0x4C */ unsigned int cellRes[ZUKAN_DETAIL_VOICE_SLOT_COUNT];
    /* 0x54 */ struct Obj *pokemonActor[ZUKAN_DETAIL_VOICE_SLOT_COUNT];
    /* 0x5C */ int currentSlot;
    /* 0x60 */ unsigned int scaleState;           /* 0 idle, 1 growing, 2 held, 3 shrinking */
    /* 0x64 */ unsigned int voiceHandle;
    /* 0x68 */ int voicePlaying;
    /* 0x6C */ unsigned int startTick[2];         /* 64 bit tick counter at play start */
    /* 0x74 */ unsigned short elapsedMs;
    /* 0x76 */ unsigned short shownMs;
    /* 0x78 */ unsigned int bgPaletteRange;
    /* 0x7C */ struct Ov208Win *headerWin;
    /* 0x80 */ struct Ov208Win *footerWin;
    /* 0x84 */ int gfxRes[6];                     /* char, palette, cell of two actor sets */
    /* 0x9C */ struct Obj *actor[ZUKAN_DETAIL_VOICE_ACTOR_COUNT];
    /* 0xB8 */ unsigned int bgmPhase;             /* 0 none, 1 fading out, 2 pushed, 3 restored */
    /* 0xBC */ void *task;
    /* 0xC0 */ void *blendTop;
    /* 0xC4 */ void *blendBottom;
    /* 0xC8 */ struct Ov208PalFade *palFade;
    /* 0xCC */ unsigned int exitMode;             /* 0 stay, 1 leave, 2 leave with touch bar */
    /* 0xD0 */ unsigned int inputEnabled;
};

typedef char ZukanDetailVoiceSizeCheck[(sizeof(struct ZukanDetailVoice) == 0xD4) ? 1 : -1];

/* Placement of a plain actor, filled from the rows of the actor table. */
struct ZukanDetailVoiceActorPos {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char animSeq;
    unsigned char priority;
};

struct ZukanDetailVoiceAffineDesc {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char animSeq;
    unsigned char priority;
    unsigned short palOffset;
    unsigned short flipMode;
    unsigned int scaleX;
    unsigned int scaleY;
    unsigned short rotation;
    unsigned short drawMode;
};

struct ZukanDetailVoiceDigitSlots {
    unsigned char slot[4];
};

#endif
