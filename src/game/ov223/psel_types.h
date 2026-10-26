#ifndef PSEL_TYPES_H
#define PSEL_TYPES_H

/*
 * Shared types for the psel object (ov223). psel.c allocates and drives the
 * work object; psel_graphic.c draws it. Both include this header so there is
 * one owner struct.
 */

#include "../types.h"

struct ClactActor;
struct Unit;
struct G3dCamera;
struct TcbTask;
struct TextPrinter;
struct TcblSystem;
struct TaskMenuWork;
struct PselGraphicSystem;

/*
 * One selection unit (0x94 bytes on the DS): the registered POKEGRA and CLACT
 * handles, the actors, the palette fade slot and the move animation state.
 */
struct PselUnit {
    u32 cgr;              /* 0x00: POKEGRA_RegisterCgr result */
    u32 palette;          /* 0x04: POKEGRA_RegisterPalette result */
    u32 cellAnim;         /* 0x08: POKEGRA_RegisterCellAnim result */
    u32 charHandle;       /* 0x0C: CLACT_RegisterCharacter result */
    u8 pad10[4];
    u32 affineCellAnim;   /* 0x14: CLACT_RegisterCellAnim result */
    struct ClactActor *actor;            /* 0x18: CLACT_CreateActor result */
    struct ClactActor *affineActor;      /* 0x1C: CLACT_CreateAffineActor result */
    u16 src[16];          /* 0x20: fade source palette */
    u16 dst[16];          /* 0x40: fade target palette */
    u16 out[16];          /* 0x60: fade output palette */
    u16 state;            /* 0x80: fade state */
    u16 step;             /* 0x82: fade step */
    u16 frame;            /* 0x84: move animation frame */
    u16 pad86;
    u32 phase;            /* 0x88: move animation phase */
    int direction;        /* 0x8C */
    int animHold;         /* 0x90 */
};

/*
 * The psel work object: one 2168-byte record allocated by psel.c PSEL_Init.
 * It holds the three selection units, then the fade-unit actor handles at
 * 0x210..0x224 and the menu-selection words at 0x228/0x22C.
 */
struct PselWork {
    u16 heapId; u16 pad02;            /* 0x00 */
    void *config;                     /* 0x04 */
    u32 fadeSpeed;                    /* 0x08 */
    u32 subState;                     /* 0x0C */
    u32 frame;                        /* 0x10 */
    struct PselGraphicSystem *graphicSys; /* 0x14 */
    struct GfFont *font;              /* 0x18 */
    struct PrintQueue *printQue;                     /* 0x1C */
    struct TcbTask *vblankNode;       /* 0x20 */
    u32 flags;                        /* 0x24 */
    void *g3dUtil;                    /* 0x28 */
    u16 unitId; u16 unitId2;          /* 0x2C, 0x2E */
    u16 recSlots[5];                  /* 0x30: base, selected, then the three unit records */
    u16 recordCount;                  /* 0x3A */
    void *records;                    /* 0x3C */
    void *animStream;                 /* 0x40 */
    u32 animTableIndex;               /* 0x44 */
    u32 animReverse;                  /* 0x48 */
    u32 animTarget;                   /* 0x4C */
    u32 animFrame;                    /* 0x50 */
    struct PselUnit units[3];         /* 0x54..0x210 */
    int fadeAlpha;                    /* 0x210: fade-unit alpha counter */
    int fadeState;                    /* 0x214: fade-unit state */
    u32 charHandle;                   /* 0x218: CLACT_RegisterCharacter */
    u32 palHandle;                    /* 0x21C: CLACT_RegisterPaletteEx */
    u32 cellAnimHandle;               /* 0x220: CLACT_RegisterCellAnim */
    void *actor;                      /* 0x224: CLACT_CreateActor */
    u32 menuSelected;                 /* 0x228 */
    u32 currentIndex;                 /* 0x22C */
    u32 voicePending;                 /* 0x230 */
    void *msgBank;                    /* 0x234 */
    void *windows[3];                 /* 0x238: main, sub, extra BMP windows */
    u32 winFlags[3];                  /* 0x244: per-window flag */
    struct TextPrinter *printStream;  /* 0x250 */
    struct TcblSystem *tcbl;          /* 0x254 */
    void *strbuf;                     /* 0x258 */
    void *taskRes;                    /* 0x25C */
    void *win;                        /* 0x260 */
    struct TaskMenuWork *taskMenu;    /* 0x264 */
    u8 alpha; u8 pad269;              /* 0x268 */
    u16 palBuf[4][128];               /* 0x26A..0x66A */
    u16 palSrc[128];                  /* 0x66A..0x76A */
    u16 palDst[128];                  /* 0x76A..0x86A */
    u16 pad86A;
    u32 fadeActive;                   /* 0x86C */
    u8 fadeWeight;                    /* 0x870 */
    u8 fadeSrcIndex;                  /* 0x871 */
    u16 pad872;
    u32 savedFadeSpeed;               /* 0x874 */
};

/* The 16-byte graphics system handle returned by PSEL_GRAPHIC_Create. */
struct PselGraphicSystem {
    u32 unused0;                      /* 0x00 */
    struct Unit *clact;               /* 0x04 */
    struct G3dCamera *camera;         /* 0x08 */
    struct TcbTask *vblankNode;       /* 0x0C */
};

/* A single 32-bit CLACT/G3D handle the graphic helpers receive by address. */
struct PselHandle {
    struct Unit *value;
};

#endif
