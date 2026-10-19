#ifndef PSEL_TYPES_H
#define PSEL_TYPES_H

/*
 * Shared types for the psel object (ov223). psel.c allocates and drives the
 * work object; psel_graphic.c draws it. Both include this header so there is
 * one owner struct.
 */

#include "../types.h"

struct Obj;

/* One palette fade slot (0x94 bytes). */
typedef struct {
    u16 src[16];
    u16 dst[16];
    u16 out[16];
    u16 state;
    u16 step;
    u8 pad[0x30];
} Fade;

/*
 * The psel work object: one 2168-byte record allocated by psel.c PSEL_Init.
 * The three 0x94-byte palette-fade slots and the actor handles at 0x210..0x224
 * and the menu-selection words at 0x228/0x22C share the 0x74..0x230 region, so
 * they are a union (the fade slots never touch their own tail padding, which is
 * where the actor handles and the selection words live).
 */
struct PselWork {
    u16 heapId; u16 pad02;            /* 0x00 */
    void *config;                     /* 0x04 */
    u32 fadeSpeed;                    /* 0x08 */
    u32 subState;                     /* 0x0C */
    u32 frame;                        /* 0x10 */
    void *graphicSys;                 /* 0x14 */
    void *font;                       /* 0x18 */
    u32 printQue;                     /* 0x1C */
    void *vblankNode;                 /* 0x20 */
    u32 flags;                        /* 0x24 */
    void *g3dUtil;                    /* 0x28 */
    u16 unitId; u16 unitId2;          /* 0x2C, 0x2E */
    u16 recBase; u16 selIndex;        /* 0x30, 0x32 */
    u16 recIndex1; u16 recIndex2;     /* 0x34, 0x36 */
    u16 recIndex3;                    /* 0x38 */
    u16 recordCount;                  /* 0x3A */
    void *records;                    /* 0x3C */
    void *animStream;                 /* 0x40 */
    u32 animTableIndex;               /* 0x44 */
    u32 animReverse;                  /* 0x48 */
    u32 animTarget;                   /* 0x4C */
    u32 animFrame;                    /* 0x50 */
    u8 pad54[0x20];                   /* 0x54..0x74 */
    union {
        Fade slots[3];                /* 0x74..0x230 */
        struct {
            u8 pad[0x19C];
            int fadeAlpha;            /* 0x210: fade-unit alpha counter */
            int fadeState;            /* 0x214: fade-unit state */
            u32 charHandle;           /* 0x218: CLACT_RegisterCharacter */
            u32 palHandle;            /* 0x21C: CLACT_RegisterPaletteEx */
            u32 cellAnimHandle;       /* 0x220: CLACT_RegisterCellAnim */
            void *actor;              /* 0x224: CLACT_CreateActor */
            u32 menuSelected;         /* 0x228 */
            u32 currentIndex;         /* 0x22C */
        } state;
    } fade;
    u32 voicePending;                 /* 0x230 */
    void *msgBank;                    /* 0x234 */
    void *winMain;                    /* 0x238 */
    void *winSub;                     /* 0x23C */
    void *winExtra;                   /* 0x240 */
    u32 winFlag;                      /* 0x244 */
    u8 pad248[8];
    void *printStream;                /* 0x250 */
    void *tcbl;                       /* 0x254 */
    void *strbuf;                     /* 0x258 */
    void *taskRes;                    /* 0x25C */
    void *win;                        /* 0x260 */
    void *taskMenu;                   /* 0x264 */
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
    u32 clactBank;                    /* 0x04 */
    u32 camera;                       /* 0x08 */
    u32 vblankNode;                   /* 0x0C */
};

/* A loaded archive member: its payload pointer sits at 0x0C. */
struct PselResMember {
    u8 pad0[0x0C];
    u8 *data;
};

/* A single 32-bit CLACT/G3D handle the graphic helpers receive by address. */
struct PselHandle {
    u32 value;
};

/*
 * One unit record (stride 0x94, base p + i*0x94): the registered POKEGRA and
 * CLACT handles of a selection unit. Only the handle block at 0x54..0x70 is
 * modelled here; the words at 0xD8..0xE4 are touched as raw offsets in psel.c.
 */
struct PselUnit {
    u8 pad0[0x54];
    u32 cgr;              /* 0x54: POKEGRA_RegisterCgr result */
    u32 palette;          /* 0x58: POKEGRA_RegisterPalette result */
    u32 cellAnim;         /* 0x5C: POKEGRA_RegisterCellAnim result */
    u32 charHandle;       /* 0x60: CLACT_RegisterCharacter result */
    u8 pad64[4];
    u32 affineCellAnim;   /* 0x68: CLACT_RegisterCellAnim result */
    u32 actor;            /* 0x6C: CLACT_CreateActor result */
    u32 affineActor;      /* 0x70: CLACT_CreateAffineActor result */
};

#endif
