#ifndef GAME_SDK_GX_H
#define GAME_SDK_GX_H

#include "types.h"

/*
 * Graphics engine (gx module) of the SDK: the enumerations that select VRAM
 * banks, background layouts, texture formats and polygon attributes.
 */

typedef enum GXVRam {
    GX_VRAM_NONE = 0x0000,
    GX_VRAM_A = 0x0001,
    GX_VRAM_B = 0x0002,
    GX_VRAM_C = 0x0004,
    GX_VRAM_D = 0x0008,
    GX_VRAM_E = 0x0010,
    GX_VRAM_F = 0x0020,
    GX_VRAM_G = 0x0040,
    GX_VRAM_H = 0x0080,
    GX_VRAM_I = 0x0100
} GXVRam;

typedef enum GXDispSelect {
    GX_DISP_SELECT_SUB_MAIN = 0,
    GX_DISP_SELECT_MAIN_SUB = 1
} GXDispSelect;

typedef enum GXBGColorMode {
    GX_BG_COLORMODE_16 = 0,
    GX_BG_COLORMODE_256 = 1
} GXBGColorMode;

typedef enum GXBGAreaOver {
    GX_BG_AREAOVER_REPEAT = 0,
    GX_BG_AREAOVER_XLU = 1
} GXBGAreaOver;

typedef enum GXBGExtPltt {
    GX_BG_EXTPLTT_01 = 0,
    GX_BG_EXTPLTT_23 = 1
} GXBGExtPltt;

typedef enum GXBGCharBase {
    GX_BG_CHARBASE_0x00000 = 0,
    GX_BG_CHARBASE_0x04000,
    GX_BG_CHARBASE_0x08000,
    GX_BG_CHARBASE_0x0c000,
    GX_BG_CHARBASE_0x10000,
    GX_BG_CHARBASE_0x14000,
    GX_BG_CHARBASE_0x18000,
    GX_BG_CHARBASE_0x1c000,
    GX_BG_CHARBASE_0x20000,
    GX_BG_CHARBASE_0x24000,
    GX_BG_CHARBASE_0x28000,
    GX_BG_CHARBASE_0x2c000,
    GX_BG_CHARBASE_0x30000,
    GX_BG_CHARBASE_0x34000,
    GX_BG_CHARBASE_0x38000,
    GX_BG_CHARBASE_0x3c000
} GXBGCharBase;

typedef enum GXBGScrBase {
    GX_BG_SCRBASE_0x0000 = 0,
    GX_BG_SCRBASE_0x0800,
    GX_BG_SCRBASE_0x1000,
    GX_BG_SCRBASE_0x1800,
    GX_BG_SCRBASE_0x2000,
    GX_BG_SCRBASE_0x2800,
    GX_BG_SCRBASE_0x3000,
    GX_BG_SCRBASE_0x3800,
    GX_BG_SCRBASE_0x4000,
    GX_BG_SCRBASE_0x4800,
    GX_BG_SCRBASE_0x5000,
    GX_BG_SCRBASE_0x5800,
    GX_BG_SCRBASE_0x6000,
    GX_BG_SCRBASE_0x6800,
    GX_BG_SCRBASE_0x7000,
    GX_BG_SCRBASE_0x7800,
    GX_BG_SCRBASE_0x8000,
    GX_BG_SCRBASE_0x8800,
    GX_BG_SCRBASE_0x9000,
    GX_BG_SCRBASE_0x9800,
    GX_BG_SCRBASE_0xa000,
    GX_BG_SCRBASE_0xa800,
    GX_BG_SCRBASE_0xb000,
    GX_BG_SCRBASE_0xb800,
    GX_BG_SCRBASE_0xc000,
    GX_BG_SCRBASE_0xc800,
    GX_BG_SCRBASE_0xd000,
    GX_BG_SCRBASE_0xd800,
    GX_BG_SCRBASE_0xe000,
    GX_BG_SCRBASE_0xe800,
    GX_BG_SCRBASE_0xf000,
    GX_BG_SCRBASE_0xf800
} GXBGScrBase;

typedef enum GXBGScrSizeText {
    GX_BG_SCRSIZE_TEXT_256x256 = 0,
    GX_BG_SCRSIZE_TEXT_512x256,
    GX_BG_SCRSIZE_TEXT_256x512,
    GX_BG_SCRSIZE_TEXT_512x512
} GXBGScrSizeText;

typedef enum GXOBJVRamModeChar {
    GX_OBJVRAMMODE_CHAR_2D = 0x00000000,
    GX_OBJVRAMMODE_CHAR_1D_32K = 0x00000010,
    GX_OBJVRAMMODE_CHAR_1D_64K = 0x00100010,
    GX_OBJVRAMMODE_CHAR_1D_128K = 0x00200010,
    GX_OBJVRAMMODE_CHAR_1D_256K = 0x00300010
} GXOBJVRamModeChar;

typedef enum GXPolygonMode {
    GX_POLYGONMODE_MODULATE = 0,
    GX_POLYGONMODE_DECAL = 1,
    GX_POLYGONMODE_TOON = 2,
    GX_POLYGONMODE_SHADOW = 3
} GXPolygonMode;

typedef enum GXCull {
    GX_CULL_ALL = 0,
    GX_CULL_FRONT = 1,
    GX_CULL_BACK = 2,
    GX_CULL_NONE = 3
} GXCull;

typedef enum GXShading {
    GX_SHADING_TOON = 0,
    GX_SHADING_HIGHLIGHT = 1
} GXShading;

typedef enum GXFogBlend {
    GX_FOGBLEND_COLOR_ALPHA = 0,
    GX_FOGBLEND_ALPHA = 1
} GXFogBlend;

typedef enum GXFogSlope {
    GX_FOGSLOPE_0x0400 = 0,
    GX_FOGSLOPE_0x0200,
    GX_FOGSLOPE_0x0100,
    GX_FOGSLOPE_0x0080,
    GX_FOGSLOPE_0x0040,
    GX_FOGSLOPE_0x0020,
    GX_FOGSLOPE_0x0010,
    GX_FOGSLOPE_0x0008,
    GX_FOGSLOPE_0x0004,
    GX_FOGSLOPE_0x0002,
    GX_FOGSLOPE_0x0001
} GXFogSlope;

typedef enum GXTexFmt {
    GX_TEXFMT_NONE = 0,
    GX_TEXFMT_A3I5 = 1,
    GX_TEXFMT_PLTT4 = 2,
    GX_TEXFMT_PLTT16 = 3,
    GX_TEXFMT_PLTT256 = 4,
    GX_TEXFMT_COMP4x4 = 5,
    GX_TEXFMT_A5I3 = 6,
    GX_TEXFMT_DIRECT = 7
} GXTexFmt;

typedef enum GXTexSizeS {
    GX_TEXSIZE_S8 = 0,
    GX_TEXSIZE_S16,
    GX_TEXSIZE_S32,
    GX_TEXSIZE_S64,
    GX_TEXSIZE_S128,
    GX_TEXSIZE_S256,
    GX_TEXSIZE_S512,
    GX_TEXSIZE_S1024
} GXTexSizeS;

typedef enum GXTexSizeT {
    GX_TEXSIZE_T8 = 0,
    GX_TEXSIZE_T16,
    GX_TEXSIZE_T32,
    GX_TEXSIZE_T64,
    GX_TEXSIZE_T128,
    GX_TEXSIZE_T256,
    GX_TEXSIZE_T512,
    GX_TEXSIZE_T1024
} GXTexSizeT;

typedef enum GXTexRepeat {
    GX_TEXREPEAT_NONE = 0,
    GX_TEXREPEAT_S = 1,
    GX_TEXREPEAT_T = 2,
    GX_TEXREPEAT_ST = 3
} GXTexRepeat;

typedef enum GXTexFlip {
    GX_TEXFLIP_NONE = 0,
    GX_TEXFLIP_S = 1,
    GX_TEXFLIP_T = 2,
    GX_TEXFLIP_ST = 3
} GXTexFlip;

typedef enum GXTexGen {
    GX_TEXGEN_NONE = 0,
    GX_TEXGEN_TEXCOORD = 1,
    GX_TEXGEN_NORMAL = 2,
    GX_TEXGEN_VERTEX = 3
} GXTexGen;

typedef enum GXTexPlttColor0 {
    GX_TEXPLTTCOLOR0_USE = 0,
    GX_TEXPLTTCOLOR0_TRNS = 1
} GXTexPlttColor0;

typedef union GXOamAttr {
    struct {
        u16 attr0;
        u16 attr1;
        u16 attr2;
        u16 attr3;
    };
    struct {
        u32 attr01;
        u32 attr23;
    };
    struct {
        u32 y : 8;
        u32 rsMode : 2;
        u32 objMode : 2;
        u32 mosaic : 1;
        u32 colorMode : 1;
        u32 shape : 2;
        u32 x : 9;
        u32 rsParam : 5;
        u32 size : 2;
        u32 charNo : 10;
        u32 priority : 2;
        u32 cParam : 4;
        u32 _3 : 16;
    };
    struct {
        u32 _0 : 28;
        u32 flipH : 1;
        u32 flipV : 1;
        u32 _1 : 2;
        u32 _2 : 2;
        u32 _4 : 16;
    };
} GXOamAttr;

typedef struct GX_VRAMCnt_ {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GX_VRAMCnt_;

typedef struct GX_State {
    GX_VRAMCnt_ vramCnt;
} GX_State;

#endif
