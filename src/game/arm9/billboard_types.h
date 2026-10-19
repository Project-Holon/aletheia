#ifndef GAME_ARM9_BILLBOARD_TYPES_H
#define GAME_ARM9_BILLBOARD_TYPES_H

/* billboard.c: a board owns an array of texture images and an array of
 * billboard elements. Each element names the image it draws. */

#include "../types.h"

#include "../sdk_fx.h"

#define BB_ELEM_FREE 0x3FFF

/* One texture image slot (0x28 bytes). */
struct BbImage {
    u32 handle;       /* 0x00 payload handle, 0 = empty */
    u16 texWidth;     /* 0x04 */
    u16 texHeight;    /* 0x06 */
    u8  cellWidth;    /* 0x08 */
    u8  cellHeight;   /* 0x09 */
    u8  cellColumns;  /* 0x0a texWidth / cellWidth */
    u8  cellRows;     /* 0x0b texHeight / cellHeight */
    u32 vramAddr;     /* 0x0c texture VRAM address */
    u32 plttAddr;     /* 0x10 palette VRAM address */
    u32 texFmt;       /* 0x14 GXTexFmt, 5 = free */
    u32 sizeS;        /* 0x18 GXTexSizeS */
    u32 sizeT;        /* 0x1c GXTexSizeT */
    u32 texKey;       /* 0x20 texture address key (vramAddr = key << 3) */
    u32 plttKey;      /* 0x24 palette address key */
};

/* One billboard element (0x1c bytes). */
struct BbElem {
    u16 imageIndex : 14;  /* 0x00 BB_ELEM_FREE = unused element */
    u16 facingMode : 2;   /* 0x00 index of the rotation matrix */
    u16 reserved02;       /* 0x02 */
    VecFx32 pos;          /* 0x04 */
    u16 cell;             /* 0x10 cell index inside the image */
    s16 scaleX;           /* 0x12 */
    s16 scaleY;           /* 0x14 */
    u16 rotZ;             /* 0x16 */
    u16 alpha : 5;        /* 0x18 */
    u16 polyId : 4;
    u16 visible : 1;
    u16 flipS : 1;
    u16 flipT : 1;
    u16 light : 4;
    u16 reserved1a;       /* 0x1a */
};

struct BbBoard {
    u16 heapId;           /* 0x00 */
    u16 reserved02;
    struct BbImage *images;  /* 0x04 */
    struct BbElem *elems;    /* 0x08 */
    u16 imageCount;       /* 0x0c */
    u16 elemCount;        /* 0x0e */
    fx32 scale;           /* 0x10 */
    u32 initExtraA;       /* 0x14 */
    u32 initExtraB;       /* 0x18 */
    u16 diffuse;          /* 0x1c */
    u16 ambient;          /* 0x1e */
    u16 specular;         /* 0x20 */
    u16 emission;         /* 0x22 */
    u8  polyIdBase;       /* 0x24 */
    u8  quadShape;        /* 0x25 */
    u16 reserved26;
    u32 lookAtMode;       /* 0x28 */
    u32 useFixedNormal;   /* 0x2c */
    fx16 normalX;         /* 0x30 */
    fx16 normalY;         /* 0x32 */
    fx16 normalZ;         /* 0x34 */
    s16 offsetS;          /* 0x36 */
    s16 offsetT;          /* 0x38 */
};

#endif
