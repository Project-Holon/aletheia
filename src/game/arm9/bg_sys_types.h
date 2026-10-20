#ifndef GAME_ARM9_BG_SYS_TYPES_H
#define GAME_ARM9_BG_SYS_TYPES_H

#include "../types.h"
#include "../sdk_gx.h"

typedef struct DispConfig DispConfig;
typedef struct BgTemplate BgTemplate;

struct DispConfig {
    u32 dispMode;    /* +0x00 GX_SetGraphicsMode display mode */
    u32 bgMode;      /* +0x04 GX_SetGraphicsMode BG mode */
    u32 subBgMode;   /* +0x08 sub engine mode, GXS_SetGraphicsMode */
    u32 bg0As;       /* +0x0c GX_SetGraphicsMode BG0 area */
};

struct BgTemplate {
    u32 scrollX;        /* +0x00 BGxOFS horizontal scroll */
    u32 scrollY;        /* +0x04 BGxOFS vertical scroll */
    u32 bufSize;        /* +0x08 */
    u32 baseTile;       /* +0x0c tile data offset for LoadTileLayer */
    u8  screenSize;     /* +0x10 BGxCNT screen size code */
    u8  colorMode;      /* +0x11 BGxCNT bit 7 color mode */
    u8  screenBase;     /* +0x12 BGxCNT screen base block */
    u8  charBase;       /* +0x13 BGxCNT character base block */
    u32 tileDataSize;   /* +0x14 layer tile data size in bytes */
    u8  extPltt;        /* +0x18 BGxCNT bit 13 extended palette, text layers */
    u8  priority;       /* +0x19 BGxCNT bits 0-1 priority */
    u8  areaOver;       /* +0x1a BGxCNT bit 13 display area overflow, affine layers */
    u8  pad_1b;         /* +0x1b never read */
    u32 mosaic;         /* +0x1c BGxCNT bit 6 mosaic enable */
};

struct DispVram {
    GXVRam main_bg;             /* +0x00 */
    GXVRam main_bg_expltt;      /* +0x04 */
    GXVRam sub_bg;              /* +0x08 */
    GXVRam sub_bg_expltt;       /* +0x0C */
    GXVRam main_obj;            /* +0x10 */
    GXVRam main_obj_expltt;     /* +0x14 */
    GXVRam sub_obj;             /* +0x18 */
    GXVRam sub_obj_expltt;      /* +0x1C */
    GXVRam teximage;            /* +0x20 */
    GXVRam texpltt;             /* +0x24 */
    GXOBJVRamModeChar main_mapping;     /* +0x28 */
    GXOBJVRamModeChar sub_mapping;      /* +0x2C */
};

#endif
