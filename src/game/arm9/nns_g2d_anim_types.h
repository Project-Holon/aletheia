#ifndef GAME_ARM9_NNS_G2D_ANIM_TYPES_H
#define GAME_ARM9_NNS_G2D_ANIM_TYPES_H

#include "../types.h"

/*
 * The NNS G2D cell-animation types: animation frames and sequences, the
 * controller that walks a sequence, the cell and multi-cell banks, and the
 * cell and multi-cell animation instances.  One definition for
 * nns_g2d_anim_bank.c, nns_g2d_load.c, nns_g2d_cell_animation.c,
 * nns_g2d_multi_cell_animation.c, nns_g2d_srt_control.c and the callers.
 */

struct AnimBank;

/* One animation frame (stride 8). */
typedef struct AnimFrameData {
    void *pContent;             /* +0x00  offset into the frame-data pool, a pointer once unpacked */
    u16 frames;                 /* +0x04 */
    u16 pad;
} AnimFrameData;

/* One animation sequence (stride 0x10). */
typedef struct AnimSequenceData {
    u16 numFrames;              /* +0x00 */
    u16 loopStartFrameIdx;      /* +0x02 */
    u32 animType;               /* +0x04 */
    u32 playMode;               /* +0x08 */
    AnimFrameData *pAnmFrameArray; /* +0x0c */
} AnimSequenceData;

/* Per-frame callback functor. */
typedef struct AnimCallBack {
    u32 type;
    u32 param;
    void *pFunc;
    u16 frameIdx;
    u16 pad;
} AnimCallBack;

/* The controller that walks one sequence (0x30 bytes). */
typedef struct AnimCtrl {
    const AnimFrameData *pCurrent;          /* +0x00  current frame cursor */
    const AnimFrameData *pActiveCurrent;    /* +0x04  last frame with a non-zero length */
    BOOL bReverse;                          /* +0x08  reverse playback */
    BOOL bActive;                           /* +0x0C  controller active */
    fx32 currentTime;                       /* +0x10  elapsed time in FX (12.12) units */
    fx32 speed;                             /* +0x14  playback speed in FX units */
    u32 overriddenPlayMode;                 /* +0x18  play-mode override, 0 = use sequence */
    const AnimSequenceData *pAnimSequence;  /* +0x1C  selected animation sequence */
    AnimCallBack callBack;                  /* +0x20  per-frame callback functor */
} AnimCtrl;                                 /* 0x30 */

/* The per-node SRT control block (0x14 bytes). */
typedef struct NNSG2dSRTControl {
    u32 mode;
    fx32 scaleX;
    fx32 scaleY;
    s16 transX;
    s16 transY;
    u16 rotZ;
    u16 dirtyFlags;
} SRTControl;

/* One animation frame's content: the SRT variant, or the translate-only
 * variant whose x and y share the word at +0x04 with scaleX. */
typedef struct NodeRec {
    u16 index;          /* +0x00 */
    u16 rotZ;           /* +0x02 */
    union {
        fx32 scaleX;    /* +0x04 */
        struct { s16 transOnlyX; s16 transOnlyY; };
    };
    fx32 scaleY;        /* +0x08 */
    s16 transX;         /* +0x0C */
    s16 transY;         /* +0x0E */
} NodeRec;

typedef struct CellVramTransferData {
    u32 szByteMax;
    u8 *pTransferDataArray;
} CellVramTransferData;

typedef struct VramTransferEntry {
    u32 srcOffset;
    u32 szByte;
} VramTransferEntry;

/* Cell bank; the first words are the header the unpack code reads. */
typedef struct CellDataBank {
    u16 numCells;                           /* +0x00 */
    u16 bankAttr;                           /* +0x02  bit 0: cells carry a bounding box */
    void *pCells;                           /* +0x04 */
    u32 reserved08;                         /* +0x08 */
    CellVramTransferData *pVramTransferData; /* +0x0C */
} CellDataBank;

/* One cell animation instance (0x58 bytes). */
typedef struct CellAnim {
    AnimCtrl animCtrl;                      /* +0x00 */
    const void *pCurrentCell;               /* +0x30 */
    CellDataBank *pCellDataBank;            /* +0x34 */
    s32 transferStateHandle;                /* +0x38 */
    SRTControl srtCtrl;                     /* +0x3C */
    u8 pad50[8];
} CellAnim;                                 /* 0x58 */

typedef struct MCCellAnimation { CellAnim cellAnim; BOOL bInited; } MCCellAnimation;

typedef struct Node { void *pContent; u32 type; BOOL bVisible; SRTControl srtCtrl; u8 pad20[8]; } Node;

typedef struct HierData { u16 animSequenceIdx; s16 posX; s16 posY; u16 nodeAttr; } HierData;

typedef struct MultiCellData {
    u16 numNodes;                           /* +0x00 */
    u16 numCellAnim;                        /* +0x02 */
    HierData *pHierDataArray;               /* +0x04  offset from nodeBase until unpacked */
} MultiCellData;

typedef struct MultiCellBank {
    u16 numMultiCell;                       /* +0x00 */
    u16 pad02;
    MultiCellData *pArray;                  /* +0x04 */
    u32 nodeBase;                           /* +0x08 */
    u32 reserved0C;
    u8 *pAnimBank;                          /* +0x10 */
} MultiCellBank;

typedef struct MCInstance {
    const MultiCellData *pCurrentMultiCell;
    const struct AnimBank *pAnimDataBank;
    u32 mcType;
    void *pCellAnimInstasnces;
} MCInstance;

typedef struct MultiCellAnim {
    AnimCtrl animCtrl;                      /* +0x00 */
    u16 totalFrames;                        /* +0x30 */
    u8 pad32[2];
    MCInstance mc;                          /* +0x34 */
    MultiCellBank *pMultiCellBank;          /* +0x44 */
    SRTControl srtCtrl;                     /* +0x48 */
} MultiCellAnim;                            /* 0x5C */

#endif
