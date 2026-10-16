/*
 * file:     bg_sys.c
 * unit:     yes
 * function: BG_SYS_Create, BG_SYS_Delete, BG_SYS_CreateRun, BG_SYS_ReserveTileRun, BG_SYS_DeleteHalf, BG_SYS_SetGraphicsMode, BG_SYS_ApplyGraphicsMode, BG_SYS_InitBgLayer, BG_SYS_FreeLayerBuf, BG_SYS_SetLowBit, BG_SYS_SetVisibleLayer, BG_SYS_SetPlaneVisible, BG_SYS_FillScrollArea, BG_SYS_GetScrollX, BG_SYS_GetScrollY, BG_SYS_SetScroll, BG_SYS_SetScrollRegs, BG_SYS_SetupMemory, BG_SYS_PushTile, BG_SYS_PushTileSource, BG_SYS_DecodeTile, BG_SYS_DecodeTileSource, BG_SYS_LoadTileData, BG_SYS_CreateTileRun, BG_SYS_InitRun, BG_SYS_Init, BG_SYS_SetTileUnit, BG_SYS_LoadPltt, BG_SYS_LoadPlttEntry, BG_SYS_GetTileMapEntry, BG_SYS_DrawTileRegion, BG_SYS_DrawTile, BG_SYS_DrawTileEx, BG_SYS_DrawTileSub, BG_SYS_SetTileEntry, BG_SYS_FillTileMap, BG_SYS_FreeSlot, BG_SYS_InitSlot, BG_SYS_ClearSlot, BG_SYS_ClearLayer, BG_SYS_ClearLayerEx, BG_SYS_GetGraphics, BG_SYS_GetBuf, BG_SYS_GetChannelScrollX, BG_SYS_GetChannelScrollY, BG_SYS_GetType, BG_SYS_GetField16, BG_SYS_GetField17, BG_SYS_Get, BG_SYS_Update, BG_SYS_CommitLayers, BG_SYS_SetFlagField06, BG_SYS_CommitScroll, BG_SYS_ResetSlot, BG_SYS_SetScrollX, BG_SYS_SetScrollY, BG_SYS_SetAffine, BG_SYS_CheckPixelColor, BG_SYS_ResolveScroll, BG_SYS_GetModeValue, BG_SYS_SetScrollField, BG_SYS_RotScale, BG_SYS_LoadTileLayer, BG_SYS_LoadTileDataEx, BG_SYS_LoadTileLayerEx, BG_SYS_BlitTiles, BG_SYS_BlitPixels, BG_SYS_BlitTilesEx, BG_SYS_BlitTileMap, BG_SYS_BlitPixelsEx, BG_SYS_BlitTileMapEx, BG_SYS_SetupTileScreen, BG_SYS_SetupLayer, BG_SYS_DeleteBlock, BG_SYS_AllocTileBuf, BG_SYS_SetAffineField, BG_SYS_Apply, BG_SYS_ApplyCenterOp
 * address:  0x0203F8F4
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from bg_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   AREAMAN_Delete  0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02033CC0  0x02033CC0  arm
 *   func_02033F64  0x02033F64  arm
 *   func_020341F0  0x020341F0  arm
 *   sub_020416B8   0x020416B8  arm
 *   AREAMAN_Free  0x0203422C  arm
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   func_0207D518  0x0207D518  arm
 *   BG_SYS_ClearMainBgPlanes  0x0204349C  arm
 *   BG_SYS_ClearSubBgPlanes  0x02043558  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_SetScrollField  0x02042360  arm
 *   GFL_NET_SetIrcParams  0x0203D814  arm
 *   BG_SYS_SetScrollRegs  0x02040860  arm
 *   G2x_SetBGyAffine_  0x0207D59C  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   BG_SYS_SetupMemory  0x02040968  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   BG_SYS_GetModeValue  0x020422D4  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *   G2_GetBG0CharPtr  0x0207E1F8  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   G2_GetBG2CharPtr  0x0207E2A0  arm
 *   G2_GetBG3CharPtr  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   G2S_GetBG2CharPtr  0x0207E2F0  arm
 *   G2S_GetBG3CharPtr  0x0207E388  arm
 *   BUTTON_MAN_RotScaleMtx22  0x02051E74  arm
 *   BG_SYS_SetAffineField  0x02043228  arm
 *   func_02043264  0x02043264  arm
 *   func_020432E4  0x020432E4  arm
 *   func_02030734  0x02030734  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E888  0x0207E888  arm
 *   func_0207EA00  0x0207EA00  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   func_0207ECF0  0x0207ECF0  arm
 *   func_0207E944  0x0207E944  arm
 *   func_0207EABC  0x0207EABC  arm
 *   func_0207EC34  0x0207EC34  arm
 *   func_0207EDAC  0x0207EDAC  arm
 *   GX_LoadBG0Char  0x0207EE68  arm
 *   func_0207EF90  0x0207EF90  arm
 *   func_0207F024  0x0207F024  arm
 *   GX_LoadBG2Char  0x0207F0B8  arm
 *   func_0207EEFC  0x0207EEFC  arm
 *   func_0207F14C  0x0207F14C  arm
 *   func_0207F1E0  0x0207F1E0  arm
 *   func_0207F274  0x0207F274  arm
 *   func_02043130_File 0x020A7E5C  data
 *   GX_LoadBGPltt  0x0207E3D0  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 */
#include "gf_standard_shared_types.h"

#define REG_DISPCNT (*(volatile u32 *)0x04000000)

#define REG16(a) (*(volatile u16 *)(a))

#define REG_BG0CNT_A  0x04000008

#define REG_BG1CNT_A  0x0400000A

#define REG_BG2CNT_A  0x0400000C

#define REG_BG3CNT_A  0x0400000E

#define REG_BG0CNT_B  0x04001008

#define REG_BG1CNT_B  0x0400100A

#define REG_BG2CNT_B  0x0400100C

#define REG_BG3CNT_B  0x0400100E

#define W(a) (*(volatile u32 *)(a))

#define R(a) (*(struct BgCnt *)(a))

#define SLOT(i) (g_02146A44->bgs[i])

struct AreaMan;

struct Mtx22;

struct DispConfig {
    u32 dispMode;    /* +0x00 GX_SetGraphicsMode display mode */
    u32 bgMode;      /* +0x04 GX_SetGraphicsMode BG mode */
    u32 subBgMode;   /* +0x08 sub engine mode, func_0207D518 */
    u32 bg0As;       /* +0x0c GX_SetGraphicsMode BG0 area */
};

struct BgLayer {
    void *buf;            /* 0x00 */
    u32   bufSize;        /* 0x04 */
    u32   tileOffset;     /* 0x08  tile data offset, times 2 for LoadTileLayer */
    u32   scrollX;        /* 0x0c */
    u32   scrollY;        /* 0x10 */
    u8    type;           /* 0x14  blit kind: 0 tiles, 1 pixels, 2 tiles ex */
    u8    screenSizeCode; /* 0x15 */
    u8    charBaseCode;   /* 0x16 */
    u8    tileRowBytes;   /* 0x17  0x20 or 0x40 */
    u16   rotation;       /* 0x18  affine angle */
    u16   rotationPad;    /* 0x1a */
    u32   scaleX;         /* 0x1c  0x1000 = 1.0 */
    u32   scaleY;         /* 0x20 */
    u32   centerX;        /* 0x24  rotation and scale center */
    u32   centerY;        /* 0x28 */
};

struct BgSys {
    u16       heapId;           /* +0x00 */
    u16       pad_02;           /* +0x02 never read */
    u16       scrollDirtyMask;  /* +0x04 per-layer bit set when a scroll/affine reg needs a flush */
    u16       tileDirtyMask;    /* +0x06 per-layer bit set when a layer's tile buffer needs a re-upload */
    struct BgLayer bgs[8];      /* +0x08 eight 0x2c-byte layer records */
    void     *mainTileArena;    /* +0x168 AreaMan arena for layers 0-3 */
    void     *subTileArena;     /* +0x16c AreaMan arena for layers 4-7 */
    u32       tileBaseOffset[8];/* +0x170 charBase << 14, per layer */
    u32       mapBaseOffset[8]; /* +0x190 screenBase << 11, per layer */
    u32       tileDataSize[8];  /* +0x1b0 layer tile data size in bytes */
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

/* TwlSDK nitro/gx/gx_bgcnt.h parameter types; only the type matters here */
typedef enum { SS0 = 0 } GXBGScrSizeText;

typedef enum { SA0 = 0 } GXBGScrSizeAffine;

typedef enum { CM0 = 0 } GXBGColorMode;

typedef enum { SB0 = 0 } GXBGScrBase;

typedef enum { CB0 = 0 } GXBGCharBase;

typedef enum { EP0 = 0 } GXBGExtPltt;

typedef enum { AO0 = 0 } GXBGAreaOver;

typedef int BOOL;

typedef signed short       s16;

struct Mtx22 { u32 w[4]; };

/* Offset view of the head of the BgSys block at a layer's 0x2c stride: the
 * single live byte at +0x1C is that layer's BgLayer.type blit kind. */
struct BgConfigLayer {
    char pad_00[0x1C];
    u8 type;
    char pad_1D[0x0F];
};

struct BgCnt { u16 prio : 2; u16 rest : 14; };

/* The first word of a tile-source block: the byte size the tile data occupies
 * sits in the upper 24 bits (size >> 8). */
struct BgTileSource {
    u32 sizeWord;   /* +0x00 */
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);

extern void MI_CpuFill8(void *dst, u32 value, u32 size);

extern u32 func_020307B0(void *p);

extern struct AreaMan *func_02033C00(u32 size, u32 heap);

extern u32 AREAMAN_Delete(void *a);

extern s32 func_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len);

extern u32 func_02033F64(u32 arena, u32 a, u32 b, u32 c);

extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);

extern void AREAMAN_Free(struct AreaMan *p, u32 start, s32 len);

extern u32 GX_SetGraphicsMode(u32 a, u32 b, u32 c);

extern u32 func_0207D518(u32 a);

extern void BG_SYS_ClearMainBgPlanes(void);

extern void BG_SYS_ClearSubBgPlanes(void);

extern void BG_SYS_ClearMainPlanes(u32 handle);

extern void BG_SYS_ClearSubPlanes(u32 handle);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_FillScrollArea(u32 bgId, u32 which, u32 value);

extern void BG_SYS_SetScrollField(struct BgLayer *p, u32 op, u32 value);

extern void BG_SYS_SetupLayer(u32 bgId, u32 offset, u32 size);

extern void MIi_CpuClear16(u32 value, void *dest, u32 size);

extern void GFL_NET_SetIrcParams(u32 x, u32 y);

extern void BG_SYS_SetScrollRegs(u32 layer, struct Mtx22 *a, u32 b, u32 c);

extern void G2x_SetBGyAffine_(void *reg, struct Mtx22 *a, u32 b, u32 c, u32 x, u32 y);

extern void MI_UncompressLZ8(void *dest, const void *src, u32 size);

extern void MIi_CpuCopy32(void *dest, const void *src, u32 size);

extern void MIi_CpuCopy16(void *dest, const void *src, u32 size);


extern void  MIi_CpuClearFast(u32 value, void *dst, u32 size);

extern void DWCi_ScreenDC_FlushRange(void *, u32);

extern void GX_LoadBGPltt(void *, u32, u32);

extern void func_0207E468(void *, u32, u32);

extern void BG_SYS_GetModeValue(u32 mode, u8 *a, u8 *b);

extern void BG_SYS_PushTile(u32 index);

extern void func_02041B6C(u32 bit);

extern void *G2_GetBG0CharPtr(void);

extern void *G2_GetBG1CharPtr(void);

extern void *G2_GetBG2CharPtr(void);

extern void *G2_GetBG3CharPtr(void);

extern u32 func_0207E22C(void);

extern u32 func_0207E280(void);

extern void *G2S_GetBG2CharPtr(void);

extern void *G2S_GetBG3CharPtr(void);

extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);

extern void BG_SYS_SetAffineField(struct BgLayer *p, u32 op, u16 value);

extern void func_02043264(struct BgLayer *p, u32 op, u32 value);

extern void func_020432E4(struct BgLayer *p, u32 op, u32 value);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MI_CpuCopy8(void *dst, const void *src, u32 size);

extern void DC_FlushRange(void *p, u32 size);

extern void func_0207E888(const void *src, u32 offset, u32 size);

extern void func_0207EA00(const void *src, u32 offset, u32 size);

extern void GX_LoadBG2Scr(const void *src, u32 offset, u32 size);

extern void func_0207ECF0(const void *src, u32 offset, u32 size);

extern void func_0207E944(const void *src, u32 offset, u32 size);

extern void func_0207EABC(const void *src, u32 offset, u32 size);

extern void func_0207EC34(const void *src, u32 offset, u32 size);

extern void func_0207EDAC(const void *src, u32 offset, u32 size);

extern void GX_LoadBG0Char(const void *src, u32 offset, u32 size);

extern void func_0207EF90(const void *src, u32 offset, u32 size);

extern void func_0207F024(const void *src, u32 offset, u32 size);

extern void GX_LoadBG2Char(const void *src, u32 offset, u32 size);

extern void func_0207EEFC(const void *src, u32 offset, u32 size);

extern void func_0207F14C(const void *src, u32 offset, u32 size);

extern void func_0207F1E0(const void *src, u32 offset, u32 size);

extern void func_0207F274(const void *src, u32 offset, u32 size);

void BG_SYS_Create(u16 heapId);

void BG_SYS_Delete(void);

u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);

u32 BG_SYS_ReserveTileRun(u32 a, u32 b, u32 c);

void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

void BG_SYS_ApplyGraphicsMode(const struct DispConfig *req, u32 which);

void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

void BG_SYS_FreeLayerBuf(u32 i);

void BG_SYS_SetLowBit(u32 mode);

void BG_SYS_SetVisibleLayer(int idx, unsigned short val);

void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);

u32 BG_SYS_GetScrollX(u32 layer);

u32 BG_SYS_GetScrollY(u32 layer);

void BG_SYS_SetScroll(u32 layer, u32 a, u32 b, struct Mtx22 *c, u32 d, u32 e);

void BG_SYS_SetScrollRegs(u32 layer, struct Mtx22 *a, u32 b, u32 c);

void BG_SYS_SetupMemory(void *dest, const void *src, u32 size);

void BG_SYS_PushTile(u32 index);

void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);

void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode);

void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset);

void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);

u32 BG_SYS_CreateTileRun(u32 index, const void *src, u32 size);

void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);

void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);

void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4);

void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);

u16 BG_SYS_GetTileMapEntry(u8 x, u8 y, u8 code);

u16 BG_SYS_DrawTileRegion(u8 x, u8 y, u8 w, u8 h);

void BG_SYS_DrawTile(u32 index, const void *src, u8 dx, u8 dy, u8 cw, u8 ch);

void BG_SYS_DrawTileEx(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx, u8 sy, u8 sw, u8 sh);

void BG_SYS_DrawTileSub(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx, u8 sy, u8 sw, u8 sh);

void BG_SYS_SetTileEntry(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);

void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

void BG_SYS_FreeSlot(u8 idx);

void BG_SYS_InitSlot(u8 idx);

void BG_SYS_ClearSlot(u32 i);

void BG_SYS_ClearLayer(int channel, u16 val);

void BG_SYS_ClearLayerEx(int channel, u16 val);

u32 BG_SYS_GetGraphics(u32 channel);

u32 BG_SYS_GetBuf(int channel);

u32 BG_SYS_GetChannelScrollX(u8 channel);

u32 BG_SYS_GetChannelScrollY(u8 channel);

u8 BG_SYS_GetType(int channel);

u8 BG_SYS_GetField16(int channel);

u8 BG_SYS_GetField17(int channel);

u8 BG_SYS_Get(u32 layer);

void BG_SYS_Update(void);

void BG_SYS_CommitLayers(void);

void BG_SYS_SetFlagField06(u32 bit);

void BG_SYS_CommitScroll(void);

void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);

void BG_SYS_SetScrollX(u32 which, u32 op, u16 value);

void BG_SYS_SetScrollY(u32 which, u32 op, u32 value);

void BG_SYS_SetAffine(u32 which, u32 op, u16 value);

u32 BG_SYS_CheckPixelColor(u32 layer, u16 x, u16 y, u16 *flags);

int BG_SYS_ResolveScroll(int a0, int a1);

void BG_SYS_GetModeValue(u32 mode, u8 *a, u8 *b);

void BG_SYS_SetScrollField(struct BgLayer *p, u32 op, u32 value);

void BG_SYS_RotScale(u32 layer);

void BG_SYS_LoadTileLayer(u32 layer, const void *src, u32 offset, u32 size);

void BG_SYS_LoadTileDataEx(u32 index, const u32 *src, u32 mode, u32 size);

void BG_SYS_LoadTileLayerEx(u32 layer, const void *src, u32 offset, u32 size);

void BG_SYS_BlitTiles(struct BgLayer *s, u8 dx, u8 dy, u8 cw, u8 ch, const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);

void BG_SYS_BlitPixels(struct BgLayer *s, u8 dx, u8 dy, u8 cw, u8 ch, const u8 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);

void BG_SYS_BlitTilesEx(struct BgLayer *s, u8 dx, u8 dy, u8 cw, u8 ch, const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);

void BG_SYS_BlitTileMap(struct BgLayer *s, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);

void BG_SYS_BlitPixelsEx(struct BgLayer *s, u8 value, u8 x0, u8 y0, u8 w, u8 h);

void BG_SYS_BlitTileMapEx(struct BgLayer *s, u16 value, u8 x0, u8 y0, u8 w, u8 h, u32 mode);

void BG_SYS_SetupTileScreen(u32 idx, u32 x, u32 y, u16 value);

void BG_SYS_SetupLayer(u32 idx, u32 offset, u32 size);

void BG_SYS_DeleteBlock(u32 idx, u32 offset, u32 size);

void BG_SYS_AllocTileBuf(u16 flags, u8 *buf, u32 page);

void BG_SYS_SetAffineField(struct BgLayer *p, u32 op, u16 value);

void BG_SYS_Apply(struct BgLayer *p, u32 op, u32 value);

void BG_SYS_ApplyCenterOp(struct BgLayer *bg, u32 opcode, u32 operand);

extern struct BgSys *g_02146A44;

extern char g_020A7E5C[];

extern u8 func_02043130_File[];

/*
 * TU: bg_sys.c.
 *
 * Constructor for the background system: one 0x1d0-byte allocation, zeroed,
 * with two 0x1000-byte scratch buffers and three parallel eight-entry
 * tables at +0x170, +0x190 and +0x1b0.  Every access after the first goes
 * through a fresh load of the global, because each call in between may
 * write it; only the `MI_CpuFill8` argument is forwarded from the
 * allocator's return value, since nothing has been called since the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_Create.c \
 *       --func BG_SYS_Create --addr 0x0203F8F4 --cc 1.1p1 --arm
 */
void BG_SYS_Create(u16 heapId)
{
    s32 i;

    g_02146A44 = GFL_HEAP_Alloc(heapId, 0x1d0, 0, g_020A7E5C, 134);
    MI_CpuFill8(g_02146A44, 0, 0x1d0);
    g_02146A44->heapId = heapId;
    g_02146A44->scrollDirtyMask = 0;
    g_02146A44->tileDirtyMask = 0;
    g_02146A44->mainTileArena = func_02033C00(0x1000, heapId);
    g_02146A44->subTileArena = func_02033C00(0x1000, heapId);

    for (i = 0; i < 8; i++) {
        g_02146A44->tileBaseOffset[i] = 0;
        g_02146A44->mapBaseOffset[i] = 0;
        g_02146A44->tileDataSize[i] = 0;
    }
}

/*
 * TU: bg_sys.c.
 *
 * Teardown of the background system: free the eight layers one at a time,
 * release the two buffers at +0x168 and +0x16c, free the block itself and
 * null the global.  The counter is a u8, which is what turns `i++` into the
 * `add`/`and #0xff` pair; r4 is recycled from the counter to the global's
 * address once the loop is over, and the global is re-read through it after
 * every call because the callees may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_Delete.c \
 *       --func BG_SYS_Delete --addr 0x0203F9B4 --cc 1.1p1 --arm
 */
void BG_SYS_Delete(void)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        BG_SYS_FreeLayerBuf(i);
    }
    AREAMAN_Delete(g_02146A44->mainTileArena);
    AREAMAN_Delete(g_02146A44->subTileArena);
    func_020307B0(g_02146A44);
    g_02146A44 = 0;
}

/*
 * Allocate a run of tiles for a layer in its arena, bottom-up (top == 0,
 * func_02033CC0) or top-down (func_02033F64), and return the tile index of
 * the run relative to the layer's tile base, or -1.  Closed in wave 11:
 * the arena base is selected into a local BEFORE the direction test, the
 * round-up flag is `f = (size % t != 0)` (remainder taken first, then the
 * quotient), and the tile stride `t` is an int local (tools/permuter.py,
 * type:l(t:u32->int)); every divide stays unsigned because each dividend
 * is u32.
 */
u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top)
{
    int t = BG_SYS_GetField17(layer & 0xff);
    struct BgSys *g = g_02146A44;
    u32 d1 = g->tileBaseOffset[layer] / t;
    u32 d2 = g->tileDataSize[layer] / t;
    u32 f;
    u32 n, r, base;

    f = (size % t != 0);
    n = size / t;
    base = (layer < 4) ? (u32)g->mainTileArena : (u32)g->subTileArena;
    if (top == 0)
        r = func_02033CC0((struct AreaMan *)base, d1, d2, n + f);
    else
        r = func_02033F64(base, d1 + d2 - 1, d2, n + f);
    if (r == 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return (r * t - g_02146A44->tileBaseOffset[layer]) / t;
}

u32 BG_SYS_ReserveTileRun(u32 a, u32 b, u32 c)
{
    u32 d = BG_SYS_GetField17(a & 0xff);

    d = g_02146A44->tileBaseOffset[a] / d;
    return func_020341F0((struct AreaMan *)((a < 4) ? g_02146A44->mainTileArena : g_02146A44->subTileArena),
                  d + b, c);
}

/*
 * TU: bg_sys.c.
 *
 * Release half of the pair whose reserve half is BG_SYS_SetupLayer: same arena
 * selection by layer index (0-3 at +0x168, 4-7 at +0x16c, anything else a
 * no-op) and the same round-up of a byte length to arena units, but the unit
 * here is the layer's own tile stride from sub_020416B8 rather than the
 * constant 32, so both the bias and the round-up are real divisions.
 *
 * Codegen note: the biased start index must be written back into the
 * `offset` parameter rather than into a fresh local.  A fresh local is
 * coalesced onto a different callee-saved register and shuffles the whole
 * r5/r6/r7 assignment (14 bytes wrong, same instructions); see
 * docs/idioms/reassigning-a-parameter-keeps-its-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DeleteHalf.c \
 *       --func BG_SYS_DeleteHalf --addr 0x0203FB44 --cc 1.1p1 --arm
 */
void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size)
{
    u32           unit = BG_SYS_GetField17((u8)layer);
    struct BgSys *p    = g_02146A44;

    offset = (p->tileBaseOffset[layer] + offset * unit) / unit;

    switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
        AREAMAN_Free(p->mainTileArena, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        AREAMAN_Free(p->subTileArena, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    }
}

/*
 * TU: bg_sys.c (the initialiser at 0x0203FCA0 is the next function up).
 *
 * Bring the display back up from a saved four-word config block, then clear
 * REG_DISPCNT's two mode fields.  The two clears are separate read-modify-
 * writes in the original, each reloading through the base kept in r1, so
 * they are two statements in the source and not one masked store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetGraphicsMode.c \
 *       --func BG_SYS_SetGraphicsMode --addr 0x0203FC28 --cc 1.1p1 --arm
 */
void BG_SYS_SetGraphicsMode(struct DispConfig *cfg)
{
    GX_SetGraphicsMode(cfg->dispMode, cfg->bgMode, cfg->bg0As);
    func_0207D518(cfg->subBgMode);
    REG_DISPCNT &= ~0x38000000;
    REG_DISPCNT &= ~0x07000000;
    BG_SYS_ClearMainBgPlanes();
    BG_SYS_ClearSubBgPlanes();
}

/*
 * bg_sys.c, the two-way forwarder that sits immediately above
 * BG_SYS_InitBgLayer.  Both arms are a single nested call whose result is
 * handed straight on and then dropped, so the function is void and
 * needs no callee-saved register: `push {r3, lr}` is the eight-byte
 * stack alignment pad, not a saved argument.
 *
 * The `ldm r2, {r0, r1}` in the first arm is two adjacent fields loaded
 * as two consecutive arguments, not a struct copy; writing the two
 * field reads as separate arguments to the same call is what folds them
 * into the load-multiple.
 */
void BG_SYS_ApplyGraphicsMode(const struct DispConfig *req, u32 which)
{
    if (which == 0) {
        BG_SYS_ClearMainPlanes(GX_SetGraphicsMode(req->dispMode, req->bgMode, req->bg0As));
    } else {
        BG_SYS_ClearSubPlanes(func_0207D518(req->subBgMode));
    }
}

static inline void G2_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}

static inline void G2_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & ~3) | (priority << 0));
}

static inline void G2_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_A) |= 0x40;
    } else {
        REG16(REG_BG0CNT_A) &= ~0x40;
    }
}

static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}

static inline void G2_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & ~3) | (priority << 0));
}

static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_A) |= 0x40;
    } else {
        REG16(REG_BG1CNT_A) &= ~0x40;
    }
}

static inline void G2_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}

static inline void G2_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}

static inline void G2_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}

static inline void G2_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & ~3) | (priority << 0));
}

static inline void G2_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_A) |= 0x40;
    } else {
        REG16(REG_BG2CNT_A) &= ~0x40;
    }
}

static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}

static inline void G2_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}

static inline void G2_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}

static inline void G2_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & ~3) | (priority << 0));
}

static inline void G2_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_A) |= 0x40;
    } else {
        REG16(REG_BG3CNT_A) &= ~0x40;
    }
}

static inline void G2S_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}

static inline void G2S_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & ~3) | (priority << 0));
}

static inline void G2S_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_B) |= 0x40;
    } else {
        REG16(REG_BG0CNT_B) &= ~0x40;
    }
}

static inline void G2S_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}

static inline void G2S_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & ~3) | (priority << 0));
}

static inline void G2S_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_B) |= 0x40;
    } else {
        REG16(REG_BG1CNT_B) &= ~0x40;
    }
}

static inline void G2S_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}

static inline void G2S_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}

static inline void G2S_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}

static inline void G2S_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & ~3) | (priority << 0));
}

static inline void G2S_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_B) |= 0x40;
    } else {
        REG16(REG_BG2CNT_B) &= ~0x40;
    }
}

static inline void G2S_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}

static inline void G2S_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}

static inline void G2S_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}

static inline void G2S_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & ~3) | (priority << 0));
}

static inline void G2S_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_B) |= 0x40;
    } else {
        REG16(REG_BG3CNT_B) &= ~0x40;
    }
}

/*
 * bg_sys.c: initialise one BG layer from its template.  Program BGxCNT of
 * layer bgId (0..3 main, 4..7 sub) through the TwlSDK gx_bgcnt.h inline
 * setters (text layers 0/1/4/5 always; 2/3/6/7 by type: text, affine, or the
 * game's type-2 form, whose OR order is charBase before screenBase and which
 * carries no 0x80 ext-mode bit, so it is not G2_SetBG2Control256x16Pltt),
 * then priority and mosaic, then the layer record in g_02146A44.
 *
 * Closed in wave 16 by the SDK-inline lever with the SDK's ENUM parameter
 * types (GXBGScrSizeText, GXBGColorMode, GXBGScrBase, GXBGCharBase,
 * GXBGExtPltt, GXBGAreaOver).  The same inlines with int parameters give
 * 1860 bytes, 1171 out (the type-0 store cross-jumped into the shared tail);
 * see docs/notes/BG_SYS_InitBgLayer.c.txt for the earlier record.
 */
void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type)
{
    u32 ss = BG_SYS_ResolveScroll(tmpl->screenSize, type);

    switch (bgId) {
    case 0:
        G2_SetBG0Control(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase, tmpl->extPltt);
        G2_SetBG0Priority(tmpl->priority);
        G2_BG0Mosaic(tmpl->mosaic);
        break;
    case 1:
        G2_SetBG1Control(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase, tmpl->extPltt);
        G2_SetBG1Priority(tmpl->priority);
        G2_BG1Mosaic(tmpl->mosaic);
        break;
    case 2:
        switch (type) {
        case 0:
        default:
            G2_SetBG2ControlText(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase);
            break;
        case 1:
            G2_SetBG2ControlAffine(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        case 2:
            G2_SetBG2ControlType2(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        }
        G2_SetBG2Priority(tmpl->priority);
        G2_BG2Mosaic(tmpl->mosaic);
        break;
    case 3:
        switch (type) {
        case 0:
        default:
            G2_SetBG3ControlText(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase);
            break;
        case 1:
            G2_SetBG3ControlAffine(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        case 2:
            G2_SetBG3ControlType2(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        }
        G2_SetBG3Priority(tmpl->priority);
        G2_BG3Mosaic(tmpl->mosaic);
        break;
    case 4:
        G2S_SetBG0Control(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase, tmpl->extPltt);
        G2S_SetBG0Priority(tmpl->priority);
        G2S_BG0Mosaic(tmpl->mosaic);
        break;
    case 5:
        G2S_SetBG1Control(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase, tmpl->extPltt);
        G2S_SetBG1Priority(tmpl->priority);
        G2S_BG1Mosaic(tmpl->mosaic);
        break;
    case 6:
        switch (type) {
        case 0:
        default:
            G2S_SetBG2ControlText(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase);
            break;
        case 1:
            G2S_SetBG2ControlAffine(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        case 2:
            G2S_SetBG2ControlType2(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        }
        G2S_SetBG2Priority(tmpl->priority);
        G2S_BG2Mosaic(tmpl->mosaic);
        break;
    case 7:
        switch (type) {
        case 0:
        default:
            G2S_SetBG3ControlText(ss, tmpl->colorMode, tmpl->screenBase, tmpl->charBase);
            break;
        case 1:
            G2S_SetBG3ControlAffine(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        case 2:
            G2S_SetBG3ControlType2(ss, tmpl->areaOver, tmpl->screenBase, tmpl->charBase);
            break;
        }
        G2S_SetBG3Priority(tmpl->priority);
        G2S_BG3Mosaic(tmpl->mosaic);
        break;
    }

    g_02146A44->bgs[bgId].rotation = 0;
    g_02146A44->bgs[bgId].scaleX = 0x1000;
    g_02146A44->bgs[bgId].scaleY = 0x1000;
    g_02146A44->bgs[bgId].centerX = 0;
    g_02146A44->bgs[bgId].centerY = 0;

    if (tmpl->bufSize != 0) {
        g_02146A44->bgs[bgId].buf = GFL_HEAP_Alloc(g_02146A44->heapId,
                                                 tmpl->bufSize, 0,
                                                 g_020A7E5C, 0x231);
        MIi_CpuClear16(0, g_02146A44->bgs[bgId].buf, tmpl->bufSize);
        g_02146A44->bgs[bgId].bufSize = tmpl->bufSize;
        g_02146A44->bgs[bgId].tileOffset = tmpl->baseTile;
    } else {
        g_02146A44->bgs[bgId].buf = 0;
        g_02146A44->bgs[bgId].bufSize = 0;
        g_02146A44->bgs[bgId].tileOffset = 0;
    }

    g_02146A44->bgs[bgId].screenSizeCode = tmpl->screenSize;
    g_02146A44->bgs[bgId].type = (u8)type;
    g_02146A44->bgs[bgId].charBaseCode = tmpl->colorMode;

    if (type == 0 && tmpl->colorMode == 0) {
        g_02146A44->bgs[bgId].tileRowBytes = 0x20;
    } else {
        g_02146A44->bgs[bgId].tileRowBytes = 0x40;
    }

    BG_SYS_FillScrollArea(bgId, 0, tmpl->scrollX);
    BG_SYS_FillScrollArea(bgId, 3, tmpl->scrollY);
    BG_SYS_RotScale(bgId);

    g_02146A44->tileBaseOffset[bgId] = tmpl->charBase << 14;
    g_02146A44->mapBaseOffset[bgId] = tmpl->screenBase << 11;
    g_02146A44->tileDataSize[bgId] = tmpl->tileDataSize;

    BG_SYS_SetupLayer(bgId, 0, tmpl->bufSize);
}

/*
 * Release the payload of one entry of the 0x2c-byte table hanging off the
 * singleton pointer at 0x02146A44: if the pointer at +8 is set,
 * unregister it through BG_SYS_DeleteBlock (passing the slot index and the
 * cookie at +0xc), free it, and NULL the slot.
 *
 * The slot index arrives in r0 and is never moved, so it is still there
 * as BG_SYS_DeleteBlock's first argument after the multiply.  The zero used for
 * BG_SYS_DeleteBlock's second argument and for the final store is materialised
 * once in r6 and shared
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 * Everything after the first call re-reads the global and re-indexes,
 * because the calls may store to it.
 *
 * Byte-correct, capped at MATCH: BG_SYS_DeleteBlock is called from this one
 * site and nowhere else in the image, so its PC24 has no outside witness
 * of any class.  --suggest-split cannot help, the site is inside the one
 * function.  It unsticks when 0x02043094 is itself decompiled to EXACT
 * or a second caller turns up in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_FreeLayerBuf.c \
 *       --func BG_SYS_FreeLayerBuf --addr 0x020403F4 --cc 1.1p1 --arm
 */
void BG_SYS_FreeLayerBuf(u32 i)
{
    if (g_02146A44->bgs[i].buf == 0) {
        return;
    }
    BG_SYS_DeleteBlock(i, 0, g_02146A44->bgs[i].bufSize);
    func_020307B0(g_02146A44->bgs[i].buf);
    g_02146A44->bgs[i].buf = 0;
}

/*
 * Set the two low bits of DISPCNT (0x04000008) to the incoming mode, after
 * asking BG_SYS_SetMainPlaneVisible for the display to be brought up in mode 1.  The
 * register is a cast constant, not a relocation: its address is the pool
 * word at the end of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetLowBit.c \
 *       --func BG_SYS_SetLowBit --addr 0x0204044C --cc 1.1p1 --arm
 */
void BG_SYS_SetLowBit(u32 mode)
{
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile u16 *)0x04000008 =
        (*(volatile u16 *)0x04000008 & ~3) | mode;
}

/*
 * Unlabelled ARM leaf: a two-to-four entry register write-back.  idx 0..7
 * selects one of eight volatile 16-bit MMIO registers (two banks of four,
 * 0x04000008..0x0400000E and 0x04001008..0x0400100E); each case clears the
 * low two bits of the register and ORs in the low bits of val.  idx > 7 is a
 * no-op (`bx lr` / `pop {r3,pc}` in the follower).
 *
 * The constants are absolute hardware addresses, so they are plain pool words
 * with no relocation.
 */
void BG_SYS_SetVisibleLayer(int idx, unsigned short val)
{
    volatile unsigned short *p;

    switch (idx) {
    case 0:
        p = (volatile unsigned short *)0x04000008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 1:
        p = (volatile unsigned short *)0x0400000A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 2:
        p = (volatile unsigned short *)0x0400000C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 3:
        p = (volatile unsigned short *)0x0400000E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 4:
        p = (volatile unsigned short *)0x04001008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 5:
        p = (volatile unsigned short *)0x0400100A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 6:
        p = (volatile unsigned short *)0x0400100C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 7:
        p = (volatile unsigned short *)0x0400100E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    }
}

/*
 * Eight-way dispatch turning a small selector into a one-hot plane mask for
 * one of the two 2D engines: selectors 0..3 go to the engine-A visible-plane
 * toggle at BG_SYS_SetMainPlaneVisible with masks 1/2/4/8 and selectors 4..7 to the
 * engine-B toggle at BG_SYS_SetSubPlaneVisible with the same four.  The on/off flag is
 * the second parameter and is forwarded untouched in r1, which is why no
 * argument setup other than the mask appears in any arm.  The ARM form
 * of the dense switch is `cmp #7` plus `addls pc, pc, r0, lsl #2` over a
 * run of eight branches, with the out-of-range case falling straight into
 * the epilogue.
 */
void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable)
{
    switch (which) {
    case 0:
        BG_SYS_SetMainPlaneVisible(1, enable);
        break;
    case 1:
        BG_SYS_SetMainPlaneVisible(2, enable);
        break;
    case 2:
        BG_SYS_SetMainPlaneVisible(4, enable);
        break;
    case 3:
        BG_SYS_SetMainPlaneVisible(8, enable);
        break;
    case 4:
        BG_SYS_SetSubPlaneVisible(1, enable);
        break;
    case 5:
        BG_SYS_SetSubPlaneVisible(2, enable);
        break;
    case 6:
        BG_SYS_SetSubPlaneVisible(4, enable);
        break;
    case 7:
        BG_SYS_SetSubPlaneVisible(8, enable);
        break;
    }
}

/*
 * The per-layer scroll register flush.  Closed in wave 11 by two facts:
 * GFL_NET_SetIrcParams takes the layer's scroll pair (x, y) as its two arguments
 * (the case-1 arm keeps r0/r1 live across the register write for the call,
 * as in BG_SYS_CommitScroll), and scrollX is read before scrollY.  The star is the
 * unlabelled follower BG_SYS_GetScrollX (already EXACT in unit_020407E8.c); the
 * true extent is 464 bytes, ending at 0x020407E8.
 */
void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b)
{
    u32 mask = 0x1ff;
    u32 hmask = mask << 16;
    u32 x, y;

    BG_SYS_SetScrollField(&g_02146A44->bgs[layer], a, b);

    x = g_02146A44->bgs[layer].scrollX;
    y = g_02146A44->bgs[layer].scrollY;

    switch (layer) {
    case 0:
        W(0x04000010) = (x & mask) | (hmask & (y << 16));
        break;
    case 1:
        W(0x04000014) = (x & mask) | (hmask & (y << 16));
        GFL_NET_SetIrcParams(x, y);
        break;
    case 2:
        if (g_02146A44->bgs[2].type == 0) {
            W(0x04000018) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(2);
        }
        break;
    case 3:
        if (g_02146A44->bgs[3].type == 0) {
            W(0x0400001c) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(3);
        }
        break;
    case 4:
        W(0x04001010) = (x & mask) | (hmask & (y << 16));
        break;
    case 5:
        W(0x04001014) = (x & mask) | (hmask & (y << 16));
        break;
    case 6:
        if (g_02146A44->bgs[6].type == 0) {
            W(0x04001018) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(6);
        }
        break;
    case 7:
        if (g_02146A44->bgs[7].type == 0) {
            W(0x0400101c) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(7);
        }
        break;
    }
}

/*
 * The two scroll-register accessors for the BG configuration table, both of
 * them leaf functions that save nothing and therefore carry no `func_` label
 * in the listing at all: they print as an anonymous run of `.word`s between
 * the literal pool of BG_SYS_FillScrollArea and the next labelled function at
 * 0x02040820 (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * They were found by sweeping the address range, not by reading labels.
 *
 * Both index the same 0x2C-byte per-layer record hanging off the single
 * pointer at 0x02146A44, and return the horizontal (+0x14) and vertical
 * (+0x18) scroll values that BG_SYS_FillScrollArea flushes to the hardware.  The
 * `mla r1, r0, r1, r2` is the array subscript: 0x2C is not a shift, so the
 * scale is a real multiply folded into the base add.
 *
 * Kept as one unit rather than two files because the pair is contiguous and
 * the whole 56-byte range, both literal pools included, reproduces exactly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020407E8.c \
 *       --addr 0x020407E8 --arm --cc 1.1p1
 */
u32 BG_SYS_GetScrollX(u32 layer)
{
    return g_02146A44->bgs[layer].scrollX;
}

u32 BG_SYS_GetScrollY(u32 layer)
{
    return g_02146A44->bgs[layer].scrollY;
}

void BG_SYS_SetScroll(u32 layer, u32 a, u32 b, struct Mtx22 *c, u32 d, u32 e)
{
    BG_SYS_SetScrollField(&g_02146A44->bgs[layer], a, b);
    BG_SYS_SetScrollRegs(layer, c, d, e);
}

/*
 * The affine half of the BG scroll module: push a layer's transform, plus
 * its current scroll position, into that layer's hardware parameter block.
 * Only the four affine-capable layers have one, so only cases 2, 3, 6 and 7
 * do anything: main engine BG2 and BG3 at 0x04000020 and 0x04000030, sub
 * engine BG2 and BG3 at 0x04001020 and 0x04001030.  Cases 0, 1, 4, 5 and
 * everything above 7 share the exit.
 *
 * The empty arms are load-bearing, not decoration: the dense jump table
 * only exists because the case labels run from 0 without gaps
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Written as
 * four cases the compiler would emit a comparison chain instead.
 *
 * Unlike BG_SYS_FillScrollArea, the subscript here stays the variable `layer` in
 * every arm rather than the arm's own case constant.  That is what the
 * `mla lr, r0, ip, lr` inside each arm says: the multiply is still live,
 * so the index cannot have been a literal.  The four arms therefore differ
 * only in one pooled register address, which is also why all four share the
 * single 0x02146A44 pool word at the end of the function.
 *
 * The transform arguments are this function's own parameters 2 to 4, passed
 * straight through untouched (nothing in any arm writes r1, r2 or r3), and
 * the scroll pair goes on the stack as arguments 5 and 6.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetScrollRegs.c \
 *       --func BG_SYS_SetScrollRegs --addr 0x02040860 --cc 1.1p1 --arm
 */
void BG_SYS_SetScrollRegs(u32 layer, struct Mtx22 *a, u32 b, u32 c)
{
    switch (layer) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        G2x_SetBGyAffine_((void *)0x04000020, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 3:
        G2x_SetBGyAffine_((void *)0x04000030, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        G2x_SetBGyAffine_((void *)0x04001020, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 7:
        G2x_SetBGyAffine_((void *)0x04001030, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    }
}

void BG_SYS_SetupMemory(void *dest, const void *src, u32 size)
{
    if (size == 0) {
        MI_UncompressLZ8(dest, src, size);
        return;
    }

    if (((u32)dest & 3) == 0 && ((u32)src & 3) == 0 && ((u16)size % 4) == 0) {
        MIi_CpuCopy32(dest, src, size);
        return;
    }

    MIi_CpuCopy16(dest, src, size);
}

/*
 * Indexes the 0x2c-byte entry array reached through the pointer at
 * 0x02146A44 and tail-calls the worker at 0x020409E0 with three fields of
 * that entry plus the index itself.  The tail call is the usual pool word
 * and `bx ip`; ip rather than r3 is used so all four argument registers
 * survive.
 */
void BG_SYS_PushTile(u32 index)
{
    

    BG_SYS_PushTileSource(index, g_02146A44->bgs[index].buf, g_02146A44->bgs[index].bufSize, g_02146A44->bgs[index].tileOffset);
}

/*
 * Push a tile source into slot `index` of the 0x2c-byte table behind
 * 0x02146A44.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_PushTileSource.c \
 *       --func BG_SYS_PushTileSource --addr 0x020409E0 --cc 1.1p1 --arm
 */
void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset)
{
    if (mode == 0) {
        void *tiles = g_02146A44->bgs[index].buf;

        if (tiles != 0) {
            BG_SYS_SetupMemory((void *)src, tiles, mode);
            BG_SYS_LoadTileLayer(index, tiles, g_02146A44->bgs[index].tileOffset * 2,
                          g_02146A44->bgs[index].bufSize);
        } else {
            u32   size = ((const struct BgTileSource *)src)->sizeWord >> 8;
            void *buf = GFL_HEAP_Alloc(
                (u16)((g_02146A44->heapId & 0x7fff) | 0x8000), size, 0,
                g_020A7E5C, 1252);

            BG_SYS_SetupMemory((void *)src, buf, mode);
            BG_SYS_LoadTileLayer(index, buf, offset * 2, size);
            func_020307B0(buf);
        }
    } else {
        BG_SYS_LoadTileLayer(index, src, offset * 2, mode);
    }
}

/*
 * A four-instruction forwarder that binds the tile offset of BG_SYS_DecodeTileSource
 * to zero.  It has no label in the listing: the prologue saves nothing, so
 * disasm.py's rule does not see it and the whole function reads as part of
 * BG_SYS_PushTileSource's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  This is
 * also why BG_SYS_PushTileSource verifies EXACT*, its inferred extent running on
 * to 0x02040AF0; 0x02040AE0 wants seeding into
 * layout/function_starts.txt.
 *
 * The tail call is the usual pool word and `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), through ip rather than
 * r3 so the fourth argument register is still free to carry the zero
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DecodeTile.c \
 *       --func BG_SYS_DecodeTile --addr 0x02040AE0 --cc 1.1p1 --arm
 */
void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode)
{
    BG_SYS_DecodeTileSource(index, src, mode, 0);
}

/*
 * Decode a tile source straight into slot `index`'s tile buffer at a tile
 * offset.  The offset scales by two, so the buffer is addressed in
 * halfwords here even though BG_SYS_PushTileSource treats the same field as an
 * opaque destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DecodeTileSource.c \
 *       --func BG_SYS_DecodeTileSource --addr 0x02040AF0 --cc 1.1p1 --arm
 */
void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset)
{
    BG_SYS_SetupMemory((void *)src, (u16 *)g_02146A44->bgs[index].buf + offset, mode);
}

/*
 * Forward a tile upload, scaling the destination tile index by the slot's
 * tile size: the byte at +0x1e of the 0x2c-byte slot record is zero for
 * 4bpp tiles (32 bytes each, shift 5) and non-zero for 8bpp (64 bytes,
 * shift 6).  The zero arm is the fall-through, so it is the `if` body
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_LoadTileData.c \
 *       --func BG_SYS_LoadTileData --addr 0x02040B1C --cc 1.1p1 --arm
 */
void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile)
{
    if (g_02146A44->bgs[index].charBaseCode == 0) {
        BG_SYS_LoadTileDataEx(index, src, size, tile * 32);
    } else {
        BG_SYS_LoadTileDataEx(index, src, size, tile * 64);
    }
}

/*
 * Reserve a run of tiles for slot `index`, then upload into it and hand the
 * caller the tile index it got.  The reservation is in tiles and the upload
 * offset in bytes, hence the fixed 32-byte (4bpp) scale; unlike
 * BG_SYS_LoadTileData this one does not consult the slot's depth byte.
 *
 * The `and r0, r7, #0xff` is the truncation at the second call, not a cast
 * in this function's own arithmetic: BG_SYS_LoadTileDataEx takes the slot index as
 * u8 while this function takes it as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_CreateTileRun.c \
 *       --func BG_SYS_CreateTileRun --addr 0x02040B58 --cc 1.1p1 --arm
 */
u32 BG_SYS_CreateTileRun(u32 index, const void *src, u32 size)
{
    u32 tile = BG_SYS_CreateRun(index, size, 0);

    BG_SYS_LoadTileDataEx((u8)index, src, size, tile * 32);
    return tile;
}

/*
 * TU: bg_sys.c.
 *
 * Fill a run of the layer's tilemap with zeroes: take a scratch buffer of
 * `size` bytes off the heap (the heap id arrives as a plain argument here,
 * not out of the background system object, so it is masked and re-tagged the
 * same way the constructor's own allocation is), zero it, hand it to the
 * tilemap writer and release it again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_InitRun.c \
 *       --func BG_SYS_InitRun --addr 0x02040B94 --cc 1.1p1 --arm
 */
void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId)
{
    void *buf = GFL_HEAP_Alloc((u16)((heapId & 0x7fff) | 0x8000), size, 0,
                             g_020A7E5C, 1362);

    MI_CpuFill8(buf, 0, size);
    BG_SYS_LoadTileLayerEx(layer, buf, offset, size);
    func_020307B0(buf);
}

/*
 * TU: bg_sys.c.
 *
 * Fill `count` tiles of layer `layer` starting at tile `index` with the
 * pixel value `value`.  The per-layer byte at +0x1f of the 0x2c-byte slot is
 * the tile stride: 0x20 for a 4bpp layer, anything else (0x40) for 8bpp.
 * The range is first reserved in the arena that owns the layer (+0x168 for
 * layers 0-3, +0x16c for 4-7, nothing at all for an out-of-range layer),
 * with both the offset and the length expressed in 32-byte units, then a
 * scratch buffer of count*stride bytes is filled with the replicated pixel
 * value and pushed to the layer.
 *
 * Two codegen notes.  The reserve arm must be spelled as an if/else with the
 * whole call written out in each arm, not as a ternary on the length
 * argument: the ternary hoists `count * 2` to the compare and cross-jumps the
 * `mla`, while the original shares only the `lsr` and the `bl`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The two
 * pixel-replication chains have to be written right-associated with the two
 * operands of each inner pair reversed; see
 * docs/idioms/a-four-term-or-chain-is-right-associated-in-arm.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_Init.c \
 *       --func BG_SYS_Init --addr 0x02040C14 --cc 1.1p1 --arm
 */
void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index)
{
    u32   size;
    void *buf;

    switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            struct BgSys *p     = g_02146A44;
            u32           depth = p->bgs[layer].tileRowBytes;

            if (depth == 0x20) {
                func_020341F0(p->mainTileArena,
                              (p->tileBaseOffset[layer] + index * depth) >> 5, count);
            } else {
                func_020341F0(p->mainTileArena,
                              (p->tileBaseOffset[layer] + index * depth) >> 5,
                              count * 2);
            }
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            struct BgSys *p     = g_02146A44;
            u32           depth = p->bgs[layer].tileRowBytes;

            if (depth == 0x20) {
                func_020341F0(p->subTileArena,
                              (p->tileBaseOffset[layer] + index * depth) >> 5, count);
            } else {
                func_020341F0(p->subTileArena,
                              (p->tileBaseOffset[layer] + index * depth) >> 5,
                              count * 2);
            }
        }
        break;
    }

    size = count * g_02146A44->bgs[layer].tileRowBytes;
    buf  = GFL_HEAP_Alloc((u16)((g_02146A44->heapId & 0x7fff) | 0x8000),
                        size, 0, g_020A7E5C, 1421);

    if (g_02146A44->bgs[layer].tileRowBytes == 0x20) {
        u32 t = value | (value << 4 | (value << 12 | value << 8));

        value = t | (t << 16);
    } else {
        value = value | (value << 8 | (value << 24 | value << 16));
    }

    MIi_CpuClearFast(value, buf, size);
    BG_SYS_LoadTileLayerEx((u8)layer, buf, index * g_02146A44->bgs[layer].tileRowBytes,
                  size);
    func_020307B0(buf);
}

/*
 * bg_sys.c.  Release a run of tiles from one layer's arena.  The layer index
 * selects the arena (0-3 at +0x168, 4-7 at +0x16c, anything else a no-op) and
 * the slot's +0x1F bit-depth byte is both the multiplicand that turns a tile
 * index into a byte offset and the 0x20 test that doubles the count for the
 * 4bpp case.  The >> 5 is the arena's fixed 32-byte unit, not a division by
 * the depth.
 *
 * The declaration that closes this function is the depth byte's OFFSET: it is
 * +0x1F, not +0x1E.  Both bytes are live and independently read in this
 * family (BG_SYS_LoadTileData reads the +0x1E flag off the same 0x2C-stride
 * record); putting depth at +0x1E moves a live ldrb and loses the function.
 * See docs/families/bg_sys.h.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_SetTileUnit.c \\
 *       --func BG_SYS_SetTileUnit --addr 0x02040DA8 --cc 1.1p1 --arm
 */
void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile)
{
    u32 unit;

    switch (idx) {
    case 0: case 1: case 2: case 3:
        unit = g_02146A44->bgs[idx].tileRowBytes;
        if (unit == 0x20) {
            AREAMAN_Free(g_02146A44->mainTileArena,
                          (g_02146A44->tileBaseOffset[idx] + tile * unit) >> 5, count);
        } else {
            AREAMAN_Free(g_02146A44->mainTileArena,
                          (g_02146A44->tileBaseOffset[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    case 4: case 5: case 6: case 7:
        unit = g_02146A44->bgs[idx].tileRowBytes;
        if (unit == 0x20) {
            AREAMAN_Free(g_02146A44->subTileArena,
                          (g_02146A44->tileBaseOffset[idx] + tile * unit) >> 5, count);
        } else {
            AREAMAN_Free(g_02146A44->subTileArena,
                          (g_02146A44->tileBaseOffset[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    }
}

void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4)
{
    DWCi_ScreenDC_FlushRange(r6, r5);
    if (r7 < 4) {
        GX_LoadBGPltt(r6, r4, r5);
    } else {
        func_0207E468(r6, r4, r5);
    }
}

void BG_SYS_LoadPlttEntry(u32 a0, u32 a1)
{
    BG_SYS_LoadPltt(a0, &a1, 2, 0);
}

/*
 * The (x, y) to linear screen-entry index helper the whole BG layer uses
 * (src/matched/BG_SYS_SetupTileScreen.c and src/matched/BG_SYS_FillTileMap.c are two of
 * its callers).  The third argument is the slot's screen-size code at +0x1d
 * of the 0x2c-byte slot record, and the six arms spell the DS BG screen
 * layouts out exactly:
 *
 *   0  256x256 text, one 32x32 map:      x + y * 32 is wrong, it is
 *                                        x + y * 16, i.e. a 16-wide map
 *   1  and 2                             x + y * 32, a 32-wide map
 *   3  512x256: the second 32x32 map follows the first, so the high bits
 *      of x select the map and the low five index inside it
 *   4  512x512: four 32x32 maps in a 2x2 grid, map index (y>>5)*2 + (x>>5)
 *      times 0x400 entries, plus (x & 31) + (y & 31) * 32 inside
 *   5  no map
 *
 * Everything is u16 arithmetic: case 4 truncates the scaled map index to
 * sixteen bits before adding the in-map offset, which is what the
 * `lsl #26` / `lsr #16` pair is, so the two partial results have to be u16
 * locals rather than one expression.
 *
 * x and y are signed (the shifts are `asr`, not `lsr`), and the switch has
 * no default arm at all: an out-of-range code falls straight out of the
 * dispatch to `bx lr` with x still in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_GetTileMapEntry.c \
 *       --func BG_SYS_GetTileMapEntry --addr 0x02040EE0 --cc 1.1p1 --arm
 */
u16 BG_SYS_GetTileMapEntry(u8 x, u8 y, u8 code)
{
    u16 map;
    u16 off;

    switch (code) {
    case 0:
        return x + y * 16;
    case 1:
    case 2:
        return x + y * 32;
    case 3:
        return (x & 0x1f) + (y + (x & ~0x1f)) * 32;
    case 4:
        map = (y >> 5) * 2 + (x >> 5);
        off = (x & 0x1f) + (y & 0x1f) * 32;
        map = map * 0x400;
        return off + map;
    case 5:
        return 0;
    }
}

/*
 * The arbitrary-size cousin of src/matched/BG_SYS_GetTileMapEntry.c: linear screen
 * entry index for (x, y) in a map that is `w` by `h` tiles, laid out as up to
 * four 32-wide/32-tall blocks.  The block is selected by `(x >> 5)` and
 * `(y >> 5)` folded into a single u8 selector, and the switch has cases 0..3
 * only, so the out-of-range dispatch falls straight through to `return base`
 * with base still zero.
 *
 * `w - 32` and `h - 32` are s16 locals, and they double as both the guard and
 * the stride of the right-hand and bottom blocks: a negative value means the
 * map is narrower (shorter) than one block, so block 0 uses `w` (`h`) as its
 * stride and the trailing blocks never exist.  Everything accumulates through
 * u16, which is what every `lsl #16` / `lsr #16` pair in the original is.
 *
 * Three shape notes, each of which cost bytes to find:
 *
 *  - `base += idx;` has to be written out inside both arms of the if/else in
 *    cases 0 and 2 (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *    Factored out after the if/else, the arms become one instruction each and
 *    the compiler if-converts them to `addge`/`mlalt`, which is four bytes
 *    shorter than the original's real branches.  Case 1's if/else really is
 *    predicated, and that is the contrast that names the shape.
 *  - `base` must be the first declaration, or it does not get ip
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 *    with w2 first the whole function comes out with ip, lr and r4 rotated.
 *  - but `base` must be *assigned* zero after `sel`, as a statement rather
 *    than an initialiser, because the original materialises the zero into
 *    sel's register and copies it into base's (`mov r6, #0` then
 *    `mov ip, r6`), not the other way round.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DrawTileRegion.c \
 *       --func BG_SYS_DrawTileRegion --addr 0x02040F84 --cc 1.1p1 --arm
 */
u16 BG_SYS_DrawTileRegion(u8 x, u8 y, u8 w, u8 h)
{
    u16 base;
    s16 w2 = w - 32;
    s16 h2 = h - 32;
    u8  sel = 0;
    u16 idx;

    base = 0;

    if ((u32)x >> 5) {
        sel += 1;
    }
    if ((u32)y >> 5) {
        sel += 2;
    }

    switch (sel) {
    case 0:
        if (w2 >= 0) {
            idx = x + y * 32;
            base += idx;
        } else {
            idx = x + y * w;
            base += idx;
        }
        break;
    case 1:
        if (h2 >= 0) {
            base += 32 * 32;
        } else {
            base += h * 32;
        }
        idx = (x & 0x1f) + y * w2;
        base += idx;
        break;
    case 2:
        base += w * 32;
        if (w2 >= 0) {
            idx = x + (y & 0x1f) * 32;
            base += idx;
        } else {
            idx = x + (y & 0x1f) * w;
            base += idx;
        }
        break;
    case 3:
        base += (w + h2) * 32;
        idx = (x & 0x1f) + (y & 0x1f) * w2;
        base += idx;
        break;
    }
    return base;
}

/*
 * The short public entry point in front of src/matched/BG_SYS_DrawTileEx.c: it
 * drops the caller's second argument out of the register block, shifts the
 * third and fourth down into r1/r2, and rebuilds the ten-argument call with
 * the two u8 tail arguments duplicated and a pair of zeroes in between.
 *
 * Reading the callee's argument list back, this is the "no clip rectangle"
 * form: arguments 7 and 8 of BG_SYS_DrawTileEx are the clip origin and are passed
 * as zero, while arguments 9 and 10 repeat the size pair given here, so the
 * clip box is the whole destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DrawTile.c \
 *       --func BG_SYS_DrawTile --addr 0x02041090 --cc 1.1p1 --arm
 */
void BG_SYS_DrawTile(u32 index, const void *src, u8 dx, u8 dy, u8 cw, u8 ch)
{
    BG_SYS_DrawTileEx(index, dx, dy, cw, ch, src, 0, 0, cw, ch);
}

/*
 * The ten-argument sibling of src/pending/BG_SYS_SetTileEntry.c: fan out on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44 and forward
 * the whole argument list, plus a trailing zero, to one of three blitters.
 * All three arms are byte-identical in their argument marshalling; only the
 * callee differs.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/BG_SYS_SetTileEntry.c: `&g_02146A44[index].tileOffset` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DrawTileEx.c \
 *       --func BG_SYS_DrawTileEx --addr 0x020410D0 --cc 1.1p1 --arm
 */
void BG_SYS_DrawTileEx(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx,
                   u8 sy, u8 sw, u8 sh)
{
    u8 kind = g_02146A44->bgs[index].type;

    if (kind == 0) {
        BG_SYS_BlitTiles(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 0);
    } else if (kind == 1) {
        BG_SYS_BlitPixels(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 0);
    } else {
        BG_SYS_BlitTilesEx(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 0);
    }
}

/*
 * The twin of src/matched/BG_SYS_DrawTileEx.c, differing only in the trailing
 * constant it appends to the blitter's argument list: 1 here, 0 there.  Fan
 * out on the bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44
 * and forward the whole argument list to one of three blitters.  All three
 * arms are byte-identical in their argument marshalling; only the callee
 * differs.  The pair reads as a "transparent" flag threaded through the two
 * public entry points of the same fill.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/BG_SYS_SetTileEntry.c: `&g_02146A44[index].tileOffset` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DrawTileSub.c \
 *       --func BG_SYS_DrawTileSub --addr 0x020411E8 --cc 1.1p1 --arm
 */
void BG_SYS_DrawTileSub(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx,
                   u8 sy, u8 sw, u8 sh)
{
    u8 kind = g_02146A44->bgs[index].type;

    if (kind == 0) {
        BG_SYS_BlitTiles(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 1);
    } else if (kind == 1) {
        BG_SYS_BlitPixels(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 1);
    } else {
        BG_SYS_BlitTilesEx(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 1);
    }
}

/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void BG_SYS_SetTileEntry(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode)
{
    u32 offset = layer * 0x2C;
    struct BgConfigLayer *bg = (struct BgConfigLayer *)((u8 *)g_02146A44 + offset);

    if (bg->type == 0) {
        BG_SYS_BlitTileMap((struct BgLayer *)((u8 *)g_02146A44 + 8 + offset), value, x0, y0, w, h, mode);
    } else if (bg->type == 1) {
        BG_SYS_BlitPixelsEx((struct BgLayer *)((u8 *)g_02146A44 + 8 + offset), (u8)value, x0, y0, w, h);
    } else {
        BG_SYS_BlitTileMapEx((struct BgLayer *)((u8 *)g_02146A44 + 8 + offset), value, x0, y0, w, h, mode);
    }
}

/*
 * Recolour a rectangle of the screen buffer of table slot `index`: for every
 * tile entry in the (x0, y0, w, h) box, replace the palette nibble in bits
 * 12..15 with `pal` and leave the low twelve bits alone.
 *
 * BG_SYS_GetModeValue turns the slot's screen-size code at +0x1d into the layer's
 * width and height in tiles, returned through two u8 out-parameters; the
 * later declaration gets the lower stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md), so `width` at
 * sp+9 has to be declared before `height` at sp+8.  The box is clipped
 * against those two: running off the right edge breaks the row, running off
 * the bottom returns outright.  BG_SYS_GetTileMapEntry is the same (x, y, size_code)
 * to linear-index helper src/matched/BG_SYS_SetupTileScreen.c uses.
 *
 * Two loop-shape notes, each worth twelve bytes:
 *
 *  - The y bound must be only the `for` condition.  Writing the equivalent
 *    `if (y0 >= yEnd) return;` in front of the loop as well emits the
 *    predicated return twice: the compiler's own loop-rotation entry test
 *    already is that guard.
 *  - The x bound must stay an expression in the inner condition,
 *    `x < x0 + w`, not a local computed before the nest.  As an expression
 *    it is loop-invariant and gets hoisted into the outer loop's preheader,
 *    which is after the y guard; as a local it is computed before the guard,
 *    which is where the original does not have it.
 *
 * Both bounds are signed compares (bge/blt) because each is a sum of two u8
 * values and so has type int, while the two clip tests against width and
 * height are unsigned (bhs): there both sides are u8 and the front end knows
 * the range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_FillTileMap.c \
 *       --func BG_SYS_FillTileMap --addr 0x020413B0 --cc 1.1p1 --arm
 */
void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal)
{
    u8   width;
    u8   height;
    u16 *screen;
    u8   x;
    int  yEnd;

    screen = (u16 *)g_02146A44->bgs[index].buf;
    if (screen == 0) {
        return;
    }

    BG_SYS_GetModeValue(g_02146A44->bgs[index].screenSizeCode, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }
            i = BG_SYS_GetTileMapEntry(x, y0, g_02146A44->bgs[index].screenSizeCode);
            screen[i] = (u16)((screen[i] & 0xfff) | (pal << 12));
        }
    }
}

void BG_SYS_FreeSlot(u8 idx)
{
    BG_SYS_InitSlot(idx);
    BG_SYS_ClearSlot(idx);
}

void BG_SYS_InitSlot(u8 idx)
{
    BG_SYS_InitRun(idx, (u32)g_02146A44->tileDataSize[idx], 0, g_02146A44->heapId);
}

/*
 * Clear slot `i` of the 0x2c-byte slot table behind 0x02146A44: if the
 * buffer pointer at +8 is unset there is nothing to do, otherwise zero the
 * buffer over its +0xc length and notify BG_SYS_PushTile.  Same table and
 * same guard shape as src/matched/BG_SYS_FreeLayerBuf.c, which frees the buffer
 * instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_ClearSlot.c \
 *       --func BG_SYS_ClearSlot --addr 0x020414EC --cc 1.1p1 --arm
 */
void BG_SYS_ClearSlot(u32 i)
{
    if (g_02146A44->bgs[i].buf == 0) {
        return;
    }
    MIi_CpuClear16(0, g_02146A44->bgs[i].buf, g_02146A44->bgs[i].bufSize);
    BG_SYS_PushTile(i);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Channel clear and audio dispatcher functions.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204152C.c \
 *       --addr 0x0204152C --arm
 */
void BG_SYS_ClearLayer(int channel, u16 val)
{

    if (g_02146A44->bgs[channel].buf == 0) {
        return;
    }
    MIi_CpuClear16(val, g_02146A44->bgs[channel].buf, g_02146A44->bgs[channel].bufSize);
    BG_SYS_PushTile(channel);
}

void BG_SYS_ClearLayerEx(int channel, u16 val)
{

    if (g_02146A44->bgs[channel].buf == 0) {
        return;
    }
    MIi_CpuClear16(val, g_02146A44->bgs[channel].buf, g_02146A44->bgs[channel].bufSize);
    func_02041B6C(channel);
}

u32 BG_SYS_GetGraphics(u32 channel)
{
    switch (channel) {
    case 0: return (u32)G2_GetBG0CharPtr();
    case 1: return (u32)G2_GetBG1CharPtr();
    case 2: return (u32)G2_GetBG2CharPtr();
    case 3: return (u32)G2_GetBG3CharPtr();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (u32)G2S_GetBG2CharPtr();
    case 7: return (u32)G2S_GetBG3CharPtr();
    default: return 0;
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           BG_SYS_GetField16, BG_SYS_GetField17
 *
 * Channel state struct member accessors.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204162C.c \
 *       --addr 0x0204162C --arm
 */
u32 BG_SYS_GetBuf(int channel)
{
    return (u32)g_02146A44->bgs[channel].buf;
}

u32 BG_SYS_GetChannelScrollX(u8 channel)
{
    return g_02146A44->bgs[channel].scrollX;
}

u32 BG_SYS_GetChannelScrollY(u8 channel)
{
    return g_02146A44->bgs[channel].scrollY;
}

u8 BG_SYS_GetType(int channel)
{
    return g_02146A44->bgs[channel].type;
}

u8 BG_SYS_GetField16(int channel)
{
    return g_02146A44->bgs[channel].charBaseCode;
}

u8 BG_SYS_GetField17(int channel)
{
    return g_02146A44->bgs[channel].tileRowBytes;
}

/*
 * The BG priority getter: returns the 2-bit priority field of the layer's
 * BGxCNT register.  Layers 0/1/4/5 read their register directly; layers
 * 2/3/6/7 first consult the slot's +0x1c mode byte, which selects one of
 * three otherwise identical reads of the SAME register (only the stack
 * slot the raw halfword spills to differs).
 *
 * Three declarations carry the whole function and none is optional:
 *
 *  1. The return is a 2-BIT BITFIELD of a struct COPIED from the register,
 *     not a masked read.  `struct BgCnt { u16 prio : 2; u16 rest : 14; }`
 *     assigned into a local is what emits the `lsl #0x1e / lsr #0x1e` pair
 *     AND the `strh r1, [sp, #N]` spill of the raw halfword together.  A
 *     plain `(x & 3)` loses both; a plain u16 local loses the spill.
 *  2. Each read needs its OWN local (c0..c15).  The sixteen distinct
 *     locals are what place the spills at the descending slots 0x1e, 0x1c,
 *     0x1a, ...; one reused local collapses them all onto [sp].
 *  3. The return type is u8, which is the trailing `and r0, r0, #0xff`.
 *
 * WHAT CLOSED THE LAST 303 BYTES (wave 2 of this family).  The four
 * sub-dispatch arms must emit the FULL unfused comparison chain
 *     cmp r0,#0 ; beq A ; cmp r0,#1 ; beq B ; cmp r0,#2 ; beq C ; <fall>
 * where the mode==0 branch target IS the fall-through address, so the
 * mode==0 body is reached both by its own beq and by falling off the end
 * of the chain.  No if/else-if chain reproduces that: the compiler fuses
 * the first test into `cmp r0,#0 / bne`.  An inner `switch` builds a jump
 * table and comes out 16 bytes short.  Only an explicit goto chain
 *     if (m == 0) goto L_0;  if (m == 1) goto L_1;  if (m == 2) goto L_2;
 *     L_0: ...  L_1: ...  L_2: ...
 * with the labels following in source order emits the three separate
 * cmp/beq pairs and lets L_0 double as the fall-through, which is the
 * shape docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * describes.  Caching the mode in a `u8 m` local is part of it: reading
 * `g_02146A44[layer].mode` three times re-emits the mla address
 * computation before each test.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_Get.c \
 *       --func BG_SYS_Get --addr 0x020416D4 --arm --cc 1.1p1
 */
u8 BG_SYS_Get(u32 layer)
{
    struct BgCnt c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15;

    switch (layer) {
    case 0:
        c0 = R(0x04000008);
        return c0.prio;
    case 1:
        c1 = R(0x0400000a);
        return c1.prio;
    case 2:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L0_0;
            if (m == 1) goto L0_1;
            if (m == 2) goto L0_2;
        L0_0:
            c2 = R(0x0400000c);
            return c2.prio;
        L0_1:
            c3 = R(0x0400000c);
            return c3.prio;
        L0_2:
            c4 = R(0x0400000c);
            return c4.prio;
        }
    case 3:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L1_0;
            if (m == 1) goto L1_1;
            if (m == 2) goto L1_2;
        L1_0:
            c5 = R(0x0400000e);
            return c5.prio;
        L1_1:
            c6 = R(0x0400000e);
            return c6.prio;
        L1_2:
            c7 = R(0x0400000e);
            return c7.prio;
        }
    case 4:
        c8 = R(0x04001008);
        return c8.prio;
    case 5:
        c9 = R(0x0400100a);
        return c9.prio;
    case 6:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L2_0;
            if (m == 1) goto L2_1;
            if (m == 2) goto L2_2;
        L2_0:
            c10 = R(0x0400100c);
            return c10.prio;
        L2_1:
            c11 = R(0x0400100c);
            return c11.prio;
        L2_2:
            c12 = R(0x0400100c);
            return c12.prio;
        }
    case 7:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L3_0;
            if (m == 1) goto L3_1;
            if (m == 2) goto L3_2;
        L3_0:
            c13 = R(0x0400100e);
            return c13.prio;
        L3_1:
            c14 = R(0x0400100e);
            return c14.prio;
        L3_2:
            c15 = R(0x0400100e);
            return c15.prio;
        }
    }

    return 0;
}

void BG_SYS_Update(void)
{
    if (g_02146A44 == 0) {
        return;
    }

    BG_SYS_CommitScroll();
    BG_SYS_CommitLayers();

    g_02146A44->scrollDirtyMask = 0;
    g_02146A44->tileDirtyMask = 0;
}

/*
 * Flush the eight tile slots of the 0x2c-byte table behind 0x02146A44 whose
 * dirty bit is set in the u16 at +6: each selected slot re-uploads its tile
 * buffer at the same argument triple BG_SYS_PushTileSource uses (index, tiles,
 * tileOffset * 2, bufSize).  The global is re-read once per arm because the call
 * may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_CommitLayers.c \
 *       --func BG_SYS_CommitLayers --addr 0x02041A1C --cc 1.1p1 --arm
 */
void BG_SYS_CommitLayers(void)
{
    if (g_02146A44->tileDirtyMask & 0x01)
        BG_SYS_LoadTileLayer(0, g_02146A44->bgs[0].buf, g_02146A44->bgs[0].tileOffset * 2,
                      g_02146A44->bgs[0].bufSize);
    if (g_02146A44->tileDirtyMask & 0x02)
        BG_SYS_LoadTileLayer(1, g_02146A44->bgs[1].buf, g_02146A44->bgs[1].tileOffset * 2,
                      g_02146A44->bgs[1].bufSize);
    if (g_02146A44->tileDirtyMask & 0x04)
        BG_SYS_LoadTileLayer(2, g_02146A44->bgs[2].buf, g_02146A44->bgs[2].tileOffset * 2,
                      g_02146A44->bgs[2].bufSize);
    if (g_02146A44->tileDirtyMask & 0x08)
        BG_SYS_LoadTileLayer(3, g_02146A44->bgs[3].buf, g_02146A44->bgs[3].tileOffset * 2,
                      g_02146A44->bgs[3].bufSize);
    if (g_02146A44->tileDirtyMask & 0x10)
        BG_SYS_LoadTileLayer(4, g_02146A44->bgs[4].buf, g_02146A44->bgs[4].tileOffset * 2,
                      g_02146A44->bgs[4].bufSize);
    if (g_02146A44->tileDirtyMask & 0x20)
        BG_SYS_LoadTileLayer(5, g_02146A44->bgs[5].buf, g_02146A44->bgs[5].tileOffset * 2,
                      g_02146A44->bgs[5].bufSize);
    if (g_02146A44->tileDirtyMask & 0x40)
        BG_SYS_LoadTileLayer(6, g_02146A44->bgs[6].buf, g_02146A44->bgs[6].tileOffset * 2,
                      g_02146A44->bgs[6].bufSize);
    if (g_02146A44->tileDirtyMask & 0x80)
        BG_SYS_LoadTileLayer(7, g_02146A44->bgs[7].buf, g_02146A44->bgs[7].tileOffset * 2,
                      g_02146A44->bgs[7].bufSize);
}

/*
 * Sets one bit of the 16-bit request mask at +6 of the singleton reached
 * through the pointer at 0x02146A44.  The lsl #16 / lsr #16 pair is the
 * u16 truncation of `1 << bit`, not a mask written in the source.
 */
void BG_SYS_SetFlagField06(u32 bit)
{
    g_02146A44->tileDirtyMask |= 1 << bit;
}

/*
 * The per-frame scroll/affine flush for the whole BG system: eight
 * independent blocks, one per layer, each guarded by its own bit of the
 * dirty mask at +0x04 of the singleton (the mask unit_02041F28 ORs
 * (1 << layer) into after every register write).  Nothing loops; all eight
 * blocks are written out, which is why the function is 848 bytes of almost
 * entirely repeated code.
 *
 * Layers 0, 1, 4 and 5 have only the plain path: pack scroll_x (+0x14) and
 * scroll_y (+0x18) into one word, low 9 bits and bits 16..24, and store it
 * to the layer's BGxOFS pair.  Layer 1 additionally tail-calls
 * GFL_NET_SetIrcParams with that same scroll pair.
 *
 * Layers 2, 3, 6 and 7 are affine-capable and first read the record's +0x1c
 * flag: zero takes the same plain path, non-zero builds a 16-byte matrix on
 * the stack with BUTTON_MAN_RotScaleMtx22 and hands it to G2x_SetBGyAffine_ along with the
 * layer's affine register block.
 *
 * THREE DECLARATIONS CARRY THE FUNCTION, all three established by this pass
 * (it was untouched before):
 *
 *  1. THE RECORD REACHES PAST ITS OWN STRIDE.  The stride is 0x2c, but the
 *     affine arms read two words at slot-relative +0x2c and +0x30 -- for
 *     layer 2 those are the absolute offsets 0x84 and 0x88, which lie in the
 *     head of layer 3's record.  Declaring the record as exactly 0x2c bytes
 *     and indexing an array of them cannot express that, so the record is
 *     declared out to +0x34 and the array indexing is done explicitly with a
 *     0x2c byte stride (the SLOT macro).  The image's constant offsets, with
 *     no `mla` anywhere, are what show the indices are all compile-time.
 *
 *  2. THE MATRIX IS 16 BYTES, NOT 32.  The four stack temporaries sit at
 *     sp+0x38, +0x28, +0x18 and +0x08: a stride of 0x10.  With a 32-byte
 *     matrix the frame comes out `sub sp, #0x88` instead of `#0x48`.
 *
 *  3. G2x_SetBGyAffine_ TAKES THE AFFINE PAIR IN r2/r3 AND THE SCROLL PAIR ON
 *     THE STACK.  That is arguments 3 and 4 being +0x2c/+0x30 and arguments
 *     5 and 6 being scroll_x/scroll_y, not the other way round.  The
 *     reversed order compiles and is the same size; it differs only in which
 *     two values are spilled to [sp] and [sp,#4], which is how the diff
 *     names it.
 *
 * GFL_NET_SetIrcParams's parameter list is also pinned here: it takes the scroll
 * pair (two u32), which the image shows as the two loads of +0x40/+0x44
 * immediately before the `bl`.  A void declaration leaves those two loads
 * with no reason to exist and loses them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_CommitScroll.c \
 *       --func BG_SYS_CommitScroll --addr 0x02041B94 --arm --cc 1.1p1
 */
void BG_SYS_CommitScroll(void)
{
    u32 m  = 0x1ff;
    u32 hm = m << 16;

    if (g_02146A44->scrollDirtyMask & 0x01) {
        W(0x04000010) = (SLOT(0).scrollX & m)
                      | (hm & (SLOT(0).scrollY << 16));
    }
    if (g_02146A44->scrollDirtyMask & 0x02) {
        W(0x04000014) = (SLOT(1).scrollX & m)
                      | (hm & (SLOT(1).scrollY << 16));
        GFL_NET_SetIrcParams(SLOT(1).scrollX,
                      SLOT(1).scrollY);
    }
    if (g_02146A44->scrollDirtyMask & 0x04) {
        if (SLOT(2).type == 0) {
            W(0x04000018) = (SLOT(2).scrollX & m)
                          | (hm & (SLOT(2).scrollY << 16));
        } else {
            struct Mtx22 t;
            BUTTON_MAN_RotScaleMtx22(&t, SLOT(2).rotation,
                          (const void *)SLOT(2).scaleX,
                          (const void *)SLOT(2).scaleY, 2);
            G2x_SetBGyAffine_((void *)0x04000020, &t,
                          SLOT(2).centerX, SLOT(2).centerY,
                          SLOT(2).scrollX, SLOT(2).scrollY);
        }
    }
    if (g_02146A44->scrollDirtyMask & 0x08) {
        if (SLOT(3).type == 0) {
            W(0x0400001c) = (SLOT(3).scrollX & m)
                          | (hm & (SLOT(3).scrollY << 16));
        } else {
            struct Mtx22 t;
            BUTTON_MAN_RotScaleMtx22(&t, SLOT(3).rotation,
                          (const void *)SLOT(3).scaleX,
                          (const void *)SLOT(3).scaleY, 2);
            G2x_SetBGyAffine_((void *)0x04000030, &t,
                          SLOT(3).centerX, SLOT(3).centerY,
                          SLOT(3).scrollX, SLOT(3).scrollY);
        }
    }
    if (g_02146A44->scrollDirtyMask & 0x10) {
        W(0x04001010) = (SLOT(4).scrollX & m)
                      | (hm & (SLOT(4).scrollY << 16));
    }
    if (g_02146A44->scrollDirtyMask & 0x20) {
        W(0x04001014) = (SLOT(5).scrollX & m)
                      | (hm & (SLOT(5).scrollY << 16));
    }
    if (g_02146A44->scrollDirtyMask & 0x40) {
        if (SLOT(6).type == 0) {
            W(0x04001018) = (SLOT(6).scrollX & m)
                          | (hm & (SLOT(6).scrollY << 16));
        } else {
            struct Mtx22 t;
            BUTTON_MAN_RotScaleMtx22(&t, SLOT(6).rotation,
                          (const void *)SLOT(6).scaleX,
                          (const void *)SLOT(6).scaleY, 2);
            G2x_SetBGyAffine_((void *)0x04001020, &t,
                          SLOT(6).centerX, SLOT(6).centerY,
                          SLOT(6).scrollX, SLOT(6).scrollY);
        }
    }
    if (g_02146A44->scrollDirtyMask & 0x80) {
        if (SLOT(7).type == 0) {
            W(0x0400101c) = (SLOT(7).scrollX & m)
                          | (hm & (SLOT(7).scrollY << 16));
        } else {
            struct Mtx22 t;
            BUTTON_MAN_RotScaleMtx22(&t, SLOT(7).rotation,
                          (const void *)SLOT(7).scaleX,
                          (const void *)SLOT(7).scaleY, 2);
            G2x_SetBGyAffine_((void *)0x04001030, &t,
                          SLOT(7).centerX, SLOT(7).centerY,
                          SLOT(7).scrollX, SLOT(7).scrollY);
        }
    }
}

/*
 * Reset slot `index` of the module's 0x2C-byte slot array and mark it live
 * in the halfword bitmask at +4.  The slot address is one `mla`: the base
 * pointer plus 8 plus index * 0x2C.
 *
 * The second parameter is real, not a leftover: the original steps over both r1
 * and r2 and uses r3 for the slot-address temporary.  Each register the
 * body skips is an argument still live for the forwarding call: with one
 * parameter the temporary lands in r1, with two in r2, and only with three
 * in r3.
 *
 * The bit is narrowed to sixteen bits before the `orr` (the `lsl #16` /
 * `lsr #16` pair), which is what says the mask is a u16 field and the
 * shift is done in int width first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_ResetSlot.c \
 *       --func BG_SYS_ResetSlot --addr 0x02041EE4 --cc 1.1p1 --arm
 */
void BG_SYS_ResetSlot(u32 index, u32 a, u32 b)
{
    BG_SYS_SetScrollField(&g_02146A44->bgs[index], a, b);
    g_02146A44->scrollDirtyMask |= (u16)(1 << index);
}

/*
 * Three consecutive "bring one video slot up" entry points, 68 bytes each
 * and no padding between them, differing only in the helper they call:
 * each hands the slot record (base +8, stride 0x2c) to its helper and then
 * sets that slot's own bit in the halfword at +4 of the same context.
 *
 * Each helper is the three-argument set/add/sub family matched as
 * src/matched/BG_SYS_SetAffineField.c and its siblings, so `op` and `value` pass
 * straight through in r1/r2 and the call site prepares only r0.  That is
 * what pins the register the context value lands in: written as a
 * one-argument call every instruction of the body is still right but the
 * context load comes out in r1, four bytes per function; with the two
 * pass-through parameters declared, r1/r2 are live across the address
 * computation and the scratch goes to r3.  See
 * docs/idioms/arguments-left-in-place-keep-the-low-registers-out-of-the-scratch-pool.md.
 *
 * The bit set is the u16 truncation idiom, not a mask: `1 << which` is
 * materialised and then narrowed with the lsl #0x10 / lsr #16 pair the
 * `orr` takes as a shifted operand, which only a `u16` lvalue produces.
 * The context pointer is re-read from its own slot after the call, because
 * the callee may store it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02041F28.c \
 *       --addr 0x02041F28 --arm
 */
void BG_SYS_SetScrollX(u32 which, u32 op, u16 value)
{
    BG_SYS_SetAffineField(&g_02146A44->bgs[which], op, value);
    g_02146A44->scrollDirtyMask |= (u16)(1 << which);
}

void BG_SYS_SetScrollY(u32 which, u32 op, u32 value)
{
    func_02043264(&g_02146A44->bgs[which], op, value);
    g_02146A44->scrollDirtyMask |= (u16)(1 << which);
}

void BG_SYS_SetAffine(u32 which, u32 op, u16 value)
{
    func_020432E4(&g_02146A44->bgs[which], op, value);
    g_02146A44->scrollDirtyMask |= (u16)(1 << which);
}

/*
 * bg_sys.c: does the pixel under (x, y) on a layer match the caller's
 * colour list?  4bpp layers (flag_1e == 0) decode the tile into a scratch
 * 0x40-byte nibble buffer and test bit v of *flags; 8bpp layers copy the
 * tile (or, for mode 1, read the affine byte map directly) and scan a
 * 0xFFFF-terminated list.
 *
 * WHAT CLOSED IT (wave 12, 42 -> 0): the sub-tile coordinates px/py are
 * FUNCTION-SCOPE u8 locals declared first and assigned after the two
 * calls (the block-scoped `u8 px = x & 7; u16 py = y & 7;` of the wave-11
 * source kept x/y and px/py in separate registers: 42); the nibble loop
 * counter i is also function-scope (15 -> 9); and i must be declared
 * before tbl, tbl before buf (9 -> 0).  All other facts (u16 first
 * parameter of BG_SYS_AllocTileBuf, shared fail exit, mode != 1 arm first) are
 * from docs/notes/pkt_02041FF4.c.txt.
 */
u32 BG_SYS_CheckPixelColor(u32 layer, u16 x, u16 y, u16 *flags)
{
  u8 px;
  u8 py;
  u16 key;
  u8 *chr;
  u8 i;
  u16 *tbl;
  u8 *buf;
  u8 v;
  if (g_02146A44->bgs[layer].buf == 0)
    return 0;
  key = BG_SYS_GetTileMapEntry((u8) (x >> 3), (u8) (y >> 3), g_02146A44->bgs[layer].screenSizeCode);
  chr = (u8 *)BG_SYS_GetGraphics(layer);
  px = x & 7;
  py = y & 7;
  if (g_02146A44->bgs[layer].charBaseCode == 0)
  {
    u8 *src;
    tbl = g_02146A44->bgs[layer].buf;
    buf = func_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa77);
    src = chr + (((u32) (tbl[key] << 22)) >> 17);
    for (i = 0; i < 0x20; i++)
    {
      buf[i * 2] = src[i] & 0xf;
      buf[(i * 2) + 1] = src[i] >> 4;
    }

    BG_SYS_AllocTileBuf((tbl[key] >> 10) & 3, buf, g_02146A44->heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
    if (((*flags) & (1 << v)) == 0)
      goto fail;
    return 1;
  }
  if (g_02146A44->bgs[layer].type != 1)
  {
    tbl = g_02146A44->bgs[layer].buf;
    buf = func_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa8f);
    MI_CpuCopy8(buf, chr + (((u32) (tbl[key] << 22)) >> 16), 0x40);
    BG_SYS_AllocTileBuf((tbl[key] >> 10) & 3, buf, g_02146A44->heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
  }
  else
  {
    v = chr[((((u8 *) g_02146A44->bgs[layer].buf)[key] << 6) + px) + (py << 3)];
  }
  for (;;)
  {
    if ((*flags) == 0xffff)
      goto fail;
    if (v == ((*flags) & 0xff))
      return 1;
  }
  fail:
  return 0;

}

/*
 * Two-dimensional table: the first argument picks a row, the second a column,
 * and each cell is a two- or three-bit index.  Rows 0 and 1 both fall through
 * to the shared `return 0` (a `break` out of the switch), so mwcc if-converts
 * every arm but the last of those two rows -- which is exactly the bne/mov/bx
 * shape the original shows -- while row 2, being the final case, keeps its
 * last arm if-converted too.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_ResolveScroll.c \
 *       --func BG_SYS_ResolveScroll --addr 0x02042218 --cc 1.1p1 --arm
 */
int BG_SYS_ResolveScroll(int a0, int a1)
{
    switch (a1) {
    case 0:
        if (a0 == 1)
            return 0;
        if (a0 == 2)
            return 2;
        if (a0 == 3)
            return 1;
        if (a0 == 4)
            return 3;
        break;
    case 1:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    case 2:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    }
    return 0;
}

/*
 * The two register values a layer's window mode implies: six modes, each
 * writing one byte into each of the two output pointers, and nothing at all
 * for a mode above five (`addls` over a bare `bx lr`).  Modes 0, 1, 4 and 5
 * write the same constant twice, so the compiler materialises it once and
 * reuses r0 for both stores; modes 2 and 3 write two different ones in the
 * order they are given.  The arms are byte stores, so the values are `u8`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_GetModeValue.c \
 *       --func BG_SYS_GetModeValue --addr 0x020422D4 --cc 1.1p1 --arm
 */
void BG_SYS_GetModeValue(u32 mode, u8 *a, u8 *b)
{
    switch (mode) {
    case 0:
        *a = 0x10;
        *b = 0x10;
        break;
    case 1:
        *a = 0x20;
        *b = 0x20;
        break;
    case 2:
        *a = 0x20;
        *b = 0x40;
        break;
    case 3:
        *a = 0x40;
        *b = 0x20;
        break;
    case 4:
        *a = 0x40;
        *b = 0x40;
        break;
    case 5:
        *a = 0x80;
        *b = 0x80;
        break;
    }
}

/*
 * The 32-bit member of the set / add / subtract family whose 16-bit
 * counterpart is src/matched/BG_SYS_SetAffineField.c: opcodes 0..2 on the word at
 * +0xc of the record in r0, opcodes 3..5 on the word at +0x10, and nothing
 * at all above 5.  Each arm loads, combines and stores the field spelled
 * out as two statements of one expression, which is what keeps a single
 * `ldr` per arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetScrollField.c \
 *       --func BG_SYS_SetScrollField --addr 0x02042360 --cc 1.1p1 --arm
 */
void BG_SYS_SetScrollField(struct BgLayer *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
        p->scrollX = value;
        break;
    case 1:
        p->scrollX = p->scrollX + value;
        break;
    case 2:
        p->scrollX = p->scrollX - value;
        break;
    case 3:
        p->scrollY = value;
        break;
    case 4:
        p->scrollY = p->scrollY + value;
        break;
    case 5:
        p->scrollY = p->scrollY - value;
        break;
    }
}

/*
 * One layer's affine setup: fill a scratch parameter block on the stack,
 * then push it into the layer through BG_SYS_SetScrollRegs with a zero transform.
 * The block is 0x10 bytes at sp+4 and the first call's fifth argument is
 * the word at sp+0, which is why the frame is `sub sp, sp, #0x14`: four
 * bytes of outgoing argument plus sixteen of local.
 *
 * The first call's third and fourth arguments are the same literal, so the
 * compiler materialises 0x1000 once in r2 and copies it to r3; the zero is
 * shared the same way and survives into the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_RotScale.c \
 *       --func BG_SYS_RotScale --addr 0x020423D4 --cc 1.1p1 --arm
 */
void BG_SYS_RotScale(u32 layer)
{
    struct Mtx22 p;

    BUTTON_MAN_RotScaleMtx22(&p, 0, (const void *)0x1000, (const void *)0x1000, 0);
    BG_SYS_SetScrollRegs(layer, &p, 0, 0);
}

/*
 * One screen-base upload for the layer in r0: flush the source range and
 * then dispatch on the layer index 0..7.  The eight callees are consecutive
 * entries of the same SDK object (gx_load2d.o, 188 bytes each, 0x0207E888
 * first), four for the main engine then four for the sub engine, and
 * layout/symbols_sdk.txt gives all eight the same recovered name, so they
 * are named by address here rather than by a guess at the BG number.
 *
 * The three transform arguments are passed straight through in r1/r2/r3
 * (nothing in any arm writes r1 or r3) and every arm repeats the same
 * `mov r0, r1, r2` trio before its call; the flush gets the source and the
 * size, the arms get source, offset and size.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_LoadTileLayer.c \
 *       --func BG_SYS_LoadTileLayer --addr 0x0204241C --cc 1.1p1 --arm
 */
void BG_SYS_LoadTileLayer(u32 layer, const void *src, u32 offset, u32 size)
{
    DC_FlushRange((void *)src, size);

    switch (layer) {
    case 0:
        func_0207E888(src, offset, size);
        break;
    case 1:
        func_0207EA00(src, offset, size);
        break;
    case 2:
        GX_LoadBG2Scr(src, offset, size);
        break;
    case 3:
        func_0207ECF0(src, offset, size);
        break;
    case 4:
        func_0207E944(src, offset, size);
        break;
    case 5:
        func_0207EABC(src, offset, size);
        break;
    case 6:
        func_0207EC34(src, offset, size);
        break;
    case 7:
        func_0207EDAC(src, offset, size);
        break;
    }
}

/*
 * bg_sys.c.  Upload tile data to a layer, decompressing first when the
 * caller asks for mode 0.  The mode parameter does double duty: it is the
 * conversion selector on the mode-0 path and, on the direct path, it is
 * passed straight through to BG_SYS_LoadTileLayerEx as that call's own fourth
 * argument, which is why "movs r6, r2" tests it and keeps it live.
 *
 * Three declarations carry this function, all of them from the family
 * header (docs/families/bg_sys.h):
 *   - the allocator's signature, GFL_HEAP_Alloc(heapId, size, clear, site,
 *     tag), with the u16 heap id first and the __FILE__ anchor fourth;
 *   - the scratch heap id spelling (g_02146A44->heapId & 0x7fff) | 0x8000,
 *     the same masked form BG_SYS_InitRun and BG_SYS_Init use;
 *   - the source's first word being a header whose top 24 bits are the
 *     decompressed byte count, hence "lsr r4, r2, #8" on *src.
 * The allocator tag is 2963 and the site string is the bg_sys.c anchor at
 * 0x020A7E5C.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_LoadTileDataEx.c \
 *       --func BG_SYS_LoadTileDataEx --addr 0x02042508 --cc 1.1p1 --arm
 */
void BG_SYS_LoadTileDataEx(u32 index, const u32 *src, u32 mode, u32 size)
{
    if (mode == 0) {
        u32   n = *src >> 8;
        void *buf;

        buf = GFL_HEAP_Alloc((u16)((g_02146A44->heapId & 0x7fff) | 0x8000),
                           n, 0, g_020A7E5C, 2963);
        BG_SYS_SetupMemory((void *)src, buf, mode);
        BG_SYS_LoadTileLayerEx(index, buf, size, n);
        func_020307B0(buf);
    } else {
        BG_SYS_LoadTileLayerEx(index, src, size, mode);
    }
}

/*
 * The character-base twin of BG_SYS_LoadTileLayer, byte for byte the same shape
 * over the next eight entries of the same SDK object (0x0207EE68 first,
 * 0x94 bytes each): flush, then dispatch on the layer index 0..7 with the
 * source, offset and size passed through in r1/r2/r3.  The sub-engine
 * callees are the second group of four, which is why the case order is not
 * the address order; see the symbol note in BG_SYS_LoadTileLayer.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_LoadTileLayerEx.c \
 *       --func BG_SYS_LoadTileLayerEx --addr 0x020425B4 --cc 1.1p1 --arm
 */
void BG_SYS_LoadTileLayerEx(u32 layer, const void *src, u32 offset, u32 size)
{
    DC_FlushRange((void *)src, size);

    switch (layer) {
    case 0:
        GX_LoadBG0Char(src, offset, size);
        break;
    case 1:
        func_0207EF90(src, offset, size);
        break;
    case 2:
        GX_LoadBG2Char(src, offset, size);
        break;
    case 3:
        func_0207F1E0(src, offset, size);
        break;
    case 4:
        func_0207EEFC(src, offset, size);
        break;
    case 5:
        func_0207F024(src, offset, size);
        break;
    case 6:
        func_0207F14C(src, offset, size);
        break;
    case 7:
        func_0207F274(src, offset, size);
        break;
    }
}

/*
 * The u16 tile-to-tile copier, sibling of BG_SYS_BlitPixels (u8 cells) and
 * BG_SYS_BlitTilesEx (linear destination).  mode 0 clips each row and cell
 * with u8-wrapped coordinates and skips; any other mode clips with int
 * sums, stops at the first miss and indexes the source through
 * BG_SYS_DrawTileRegion.  Written in wave 11 straight from the two siblings'
 * settled declarations (u8 ch/sw/sh stack parameters, u8 w/h for
 * BG_SYS_DrawTileRegion, `u8 w, h;` and `u8 y, x;`); EXACT at the first compile.
 */
void BG_SYS_BlitTiles(struct BgLayer *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = (u16 *)s->buf;
    if (dst == 0)
        return;

    BG_SYS_GetModeValue(s->screenSizeCode, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[BG_SYS_GetTileMapEntry(dx + x, dy + y, s->screenSizeCode)] =
                            src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[BG_SYS_GetTileMapEntry(dx + x, dy + y, s->screenSizeCode)] =
                    src[BG_SYS_DrawTileRegion(sx + x, sy + y, sw, sh)];
            }
        }
    }
}

/*
 * Tile-to-tile copier: copies a cw x ch block of a source tilemap
 * (row stride sw, height sh, origin sx/sy) into the screen's tilemap at
 * dx/dy, clipped to the screen size BG_SYS_GetModeValue reports.  mode 0 reads
 * the source linearly, any other mode through BG_SYS_DrawTileRegion's index.
 *
 * Closed in wave 11.  Three declarations carry it: ch, sw and sh are u8
 * stack parameters even though the image loads each with a full `ldr`
 * (a u8 stack argument still occupies and is read as a word; the narrow
 * type is what moves the prologue's parameter homes, as with
 * BG_SYS_BlitTileMap's seventh parameter), BG_SYS_DrawTileRegion is called with u8
 * w/h, and the two out-bytes are declared `u8 w, h;` so w lands at
 * sp+0x29 and h at sp+0x28.  The callers (BG_SYS_DrawTileEx, BG_SYS_DrawTileSub)
 * already declare the fifth parameter (ch) as u8.
 */
void BG_SYS_BlitPixels(struct BgLayer *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u8 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u8 *dst;
    u8 w, h;
    u8 x, y;

    dst = (u8 *)s->buf;
    if (dst == 0)
        return;

    BG_SYS_GetModeValue(s->screenSizeCode, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[BG_SYS_GetTileMapEntry(dx + x, dy + y, s->screenSizeCode)] =
                    src[sw * (sy + y) + sx + x];
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[BG_SYS_GetTileMapEntry(dx + x, dy + y, s->screenSizeCode)] =
                    src[BG_SYS_DrawTileRegion(sx + x, sy + y, sw, sh)];
            }
        }
    }
}

/*
 * The halfword sibling of BG_SYS_BlitPixels: copies a cw x ch block of u16
 * source cells into a linear w-wide screen buffer at dx/dy.  mode 0 clips
 * each row and cell with u8-wrapped coordinates and skips (the source row
 * index itself is the unwrapped sy + y); any other mode clips with plain
 * int sums, stops at the first miss, and indexes the source through
 * BG_SYS_DrawTileRegion.  Closed in wave 11 with the same declarations as
 * BG_SYS_BlitPixels (ch, sw, sh are u8 stack parameters; BG_SYS_DrawTileRegion takes
 * u8 w/h; `u8 w, h;` puts w at sp+0x1d) and the loop counters declared
 * `u8 y, x;`.
 */
void BG_SYS_BlitTilesEx(struct BgLayer *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = (u16 *)s->buf;
    if (dst == 0)
        return;

    BG_SYS_GetModeValue(s->screenSizeCode, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[dx + x + w * (dy + y)] = src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[dx + x + w * (dy + y)] = src[BG_SYS_DrawTileRegion((u8)(sx + x), (u8)(sy + y), sw, (u8)sh)];
            }
        }
    }
}

/*
 * The third of the three tilemap blitters BG_SYS_SetTileEntry dispatches to on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot.  Its two siblings are
 * src/matched/BG_SYS_BlitPixelsEx.c (8bpp pixel fill, tiled addressing, u8 buffer)
 * and src/matched/BG_SYS_BlitTileMapEx.c (text fill, linear addressing, u16 buffer);
 * this one is BG_SYS_BlitTileMapEx's three write modes over BG_SYS_BlitPixelsEx's tiled
 * addressing, into a u16 buffer.  Like both of those it is handed the slot's
 * sub-object (slot + 8), so the buffer pointer is at +0x00 and the
 * screen-size code at +0x15, i.e. slot +0x08 and slot +0x1d.
 *
 * The three write modes, on the seventh argument:
 *     0x11     entry = value
 *     0x10     entry = value + (entry & 0xf000)      keep the palette nibble
 *     other    entry = (u16)(value + (mode << 12))   fold the mode in
 * The third form is loop-invariant and is materialised once in the preheader.
 * BG_SYS_GetTileMapEntry is called once per cell, before the dispatch, so its result
 * has to be bound to a local; writing the call out in each arm emits it three
 * times.
 *
 * WHAT CLOSED IT (wave 2 of this family).  docs/notes/BG_SYS_BlitTileMap.c.txt
 * recorded an 11-byte plateau at +0x10..+0x18, three mutually independent
 * prologue instructions issued in a different order:
 *     +0010  orig mov sb, r1          got ldr r7, [sp, #0x38]
 *     +0014  orig str r2, [sp]        got mov sb, r1
 *     +0018  orig ldr r7, [sp, #0x38] got str r2, [sp]
 * and concluded it was the instruction scheduler, hence unreachable from C.
 * That conclusion was wrong, and so was the premise it rested on: the note
 * argued the seventh parameter must be u32 because it arrives by `ldr` and
 * not `ldrb`.  A u8 stack argument also occupies a full word of the argument
 * area and is also loaded with `ldr`, so the load width says nothing about
 * the declared type.  Declaring
 *     u8 mode
 * instead of u32 is the whole fix, and it closes all 11 bytes at once: the
 * narrower type gives the value a different spill cost, which moves its home
 * load behind the other two prologue instructions.  Nothing else in the body
 * changed.  tools/permuter.py found it with --types (mutation
 * `type:p(mode:u32->u8)`); the earlier permute.py pass recorded in the note
 * had no type mutation and so could not reach it.
 *
 * All seven parameter types are pinned by the diff: `s` pointer, `u16 value`,
 * `u8 x0`, `u8 y0`, `u8 w`, `u8 h`, `u8 mode`.  Every other choice blows the
 * function up: value as u32 costs 157 bytes, x0 as u32 170, y0 as u32 190,
 * the helper result as u16 107.
 *
 * This unblocks src/pending/BG_SYS_SetTileEntry.c (fan-in 224), which needed all
 * three blitters as `matched` witnesses and now has them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_BlitTileMap.c \
 *       --func BG_SYS_BlitTileMap --addr 0x02042D2C --arm --cc 1.1p1
 */
void BG_SYS_BlitTileMap(struct BgLayer *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u8 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = (u16 *)s->buf;
    if (entries == 0) {
        return;
    }

    BG_SYS_GetModeValue(s->screenSizeCode, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }

            i = BG_SYS_GetTileMapEntry(x, y, s->screenSizeCode);

            if (mode == 0x11) {
                entries[i] = value;
            } else if (mode == 0x10) {
                entries[i] = value + (entries[i] & 0xf000);
            } else {
                entries[i] = (u16)(value + (mode << 12));
            }
        }
    }
}

/*
 * The 8bpp-screen fill of the three blitters BG_SYS_SetTileEntry dispatches to on
 * the bit-depth byte at +0x1c of the 0x2c-byte slot.  It takes the slot's
 * sub-object (slot + 8) rather than the slot index, so the buffer pointer is
 * at +0x00 and the screen-size code at +0x15, which are slot +0x08 and
 * +0x1d, the same two fields src/matched/BG_SYS_FillTileMap.c reaches through the
 * table.
 *
 * Same clip-and-scan shape as BG_SYS_FillTileMap, and the same two loop-shape
 * rules apply here: the y bound is only the `for` condition (the compiler's
 * loop-rotation entry test is the guard), and the x bound stays the
 * expression `x < x0 + w` so that it is hoisted into the outer preheader,
 * after the y guard rather than before it.  Both bounds are signed compares
 * (a sum of two u8 has type int); both clip tests against width and height
 * are unsigned, because there both sides are u8.
 *
 * The screen-size code is re-read from the object on every store, since the
 * store through the buffer pointer may alias it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_BlitPixelsEx.c \
 *       --func BG_SYS_BlitPixelsEx --addr 0x02042E34 --cc 1.1p1 --arm
 */
void BG_SYS_BlitPixelsEx(struct BgLayer *s, u8 value, u8 x0, u8 y0, u8 w, u8 h)
{
    u8  width;
    u8  height;
    u8 *pixels;
    u8  x;
    int yEnd;

    pixels = (u8 *)s->buf;
    if (pixels == 0) {
        return;
    }

    BG_SYS_GetModeValue(s->screenSizeCode, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            pixels[BG_SYS_GetTileMapEntry(x, y0, s->screenSizeCode)] = value;
        }
    }
}

/*
 * The text-screen fill of the three blitters BG_SYS_SetTileEntry dispatches to.
 * Like BG_SYS_BlitPixelsEx it takes the slot's sub-object (slot + 8), so the
 * buffer pointer is at +0x00 and the screen-size code at +0x15, but the
 * buffer is a linear u16 screen here: the row base is `width * y`, not the
 * tiled BG_SYS_GetTileMapEntry mapping.
 *
 * The seventh argument is the write mode and decides what lands in the
 * entry: 0x11 writes the value as it stands, 0x10 keeps the existing palette
 * nibble and adds the value to it, and anything else folds the mode itself
 * into bits 12-15.  That last form is loop-invariant, so the compiler
 * materialises it once in the outer preheader (the `lsl #0x10 / lsr #0x10`
 * pair at +0x54 is the u16 narrowing of it); writing it as a local computed
 * before the nest would instead put it ahead of the y guard.
 *
 * Loop shape.  Both bounds are expressions in their own `for` condition,
 * `y < y0 + h` and `x < x0 + w`, over loop variables distinct from the two
 * origin parameters, and the row base is the subscript `entries[width * y +
 * x]` rather than a hoisted row pointer.  Every other arrangement is right
 * to within a register permutation and wrong by eleven bytes: binding either
 * bound to a local before the nest moves it ahead of the guard it belongs
 * behind and rotates the four scratch registers holding the bounds, the
 * width and the height.  The subscript form is also what puts the scaled x
 * in the base slot of the store, `strh r7, [sl, r1]` rather than
 * `[r3, sl]`.
 *
 * The mode arrives on the stack as a full word (`ldr`, not `ldrb`), so it is
 * `u32` here even though BG_SYS_SetTileEntry hands it a value that fits in a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_BlitTileMapEx.c \
 *       --func BG_SYS_BlitTileMapEx --addr 0x02042ED8 --cc 1.1p1 --arm
 */
void BG_SYS_BlitTileMapEx(struct BgLayer *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u32 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = (u16 *)s->buf;
    if (entries == 0) {
        return;
    }

    BG_SYS_GetModeValue(s->screenSizeCode, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            if (mode == 0x11) {
                entries[width * y + x] = value;
            } else if (mode == 0x10) {
                entries[width * y + x] =
                    value + (entries[width * y + x] & 0xf000);
            } else {
                entries[width * y + x] = (u16)(value + (mode << 12));
            }
        }
    }
}

/*
 * Poke one tile entry into the screen buffer of table slot `idx`.  The
 * table is the 0x2c-byte-per-slot array hanging off the singleton pointer
 * at 0x02146A44 (the same one BG_SYS_FreeLayerBuf tears down): +8 is the screen
 * buffer and +0x1d the screen-size code that tells BG_SYS_GetTileMapEntry how to
 * fold (x, y) into a linear index.  A slot with no buffer is skipped.
 *
 * The three `and rN, rM, #0xff` are the truncations at the call, not casts
 * in this function's own arithmetic; BG_SYS_GetTileMapEntry takes three u8.
 */
void BG_SYS_SetupTileScreen(u32 idx, u32 x, u32 y, u16 value)
{

    u16 *screen = (u16 *)g_02146A44->bgs[idx].buf;
    u32 code = g_02146A44->bgs[idx].screenSizeCode;

    if (screen == 0) {
        return;
    }

    screen[(u32)BG_SYS_GetTileMapEntry((u8)x, (u8)y, (u8)code)] = value;
}

/*
 * The reserve half of the pair whose release half is BG_SYS_DeleteBlock: same
 * arena selection by slot index (0..3 at +0x168, 4..7 at +0x16c, anything
 * else a no-op), same bias by the per-slot base at +0x190 and the same
 * round-up of the byte length to 32-byte units, but handed to
 * func_020341F0 instead of AREAMAN_Free.
 *
 * Codegen note: the round-up flag must be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`; see BG_SYS_DeleteBlock.c for why the relational form
 * reschedules.
 */
void BG_SYS_SetupLayer(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->mainTileArena,
                          (offset + g_02146A44->mapBaseOffset[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->subTileArena,
                          (offset + g_02146A44->mapBaseOffset[idx]) >> 5, count);
        }
        break;
    }
}

/*
 * Release one block back to whichever of the two arenas the slot index
 * names.  Slots 0..3 belong to the arena at +0x168 of the singleton hanging
 * off 0x02146A44, slots 4..7 to the one at +0x16c, and any other index is a
 * no-op.  The byte offset is biased by the per-slot base at +0x190 and the
 * byte length rounded up, both converted to 32-byte units before
 * AREAMAN_Free sees them.  The index is not rebased for the second arena:
 * both arms read mapBaseOffset[idx] with the raw index.
 *
 * Codegen note: the round-up flag has to be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`, not as the relational `(size & 0x1f) != 0`.
 * Both are `tst`/`movne`/`moveq`, but the relational form is folded into
 * the argument expression and the scheduler then hoists the global load
 * above it, spilling the flag into lr; the ternary is materialised as its
 * own value first, which keeps ip free and reproduces the original order.
 */
void BG_SYS_DeleteBlock(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            AREAMAN_Free(g_02146A44->mainTileArena,
                          (offset + g_02146A44->mapBaseOffset[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            AREAMAN_Free(g_02146A44->subTileArena,
                          (offset + g_02146A44->mapBaseOffset[idx]) >> 5, count);
        }
        break;
    }
}

/*
 * Reorder an 8x8 tile in place, using one 0x40-byte scratch tile from the
 * heap the caller names in `page` (its low 15 bits, with bit 15 set).
 *
 *  - bit 0 of `flags` mirrors every 8-byte row horizontally: the scratch
 *    tile is filled with the row's bytes taken in reverse and copied back
 *    over the original, so the tile is transformed through the scratch.
 *  - bit 1 rotates the eight rows by reversing their order, one memcpy per
 *    row straight into the scratch tile, then one memcpy back.
 * `flags` is tested with `tst`/`beq`, so 0 means "nothing to do" and the
 * early `popeq` is the whole prologue.
 *
 * Shape notes:
 *  - The heap id is a u16 local, not a cast expression: the original
 *    truncates `page` to u16 *before* the mask (`lsl #0x10` /
 *    `and r0, r1, r0, lsr #16`) and truncates again after the `orr`, which
 *    only falls out of `heap = (u16)page; heap = (heap & 0x7FFF) | 0x8000;`.
 *  - Both loop counters are u8: the increments carry the `and #0xff` that
 *    an int counter does not.
 *  - The two memcpy pairs through `tmp` are what make this a three-call
 *    shape; the helper at 0x02082D44 is the project's 8-bit copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_AllocTileBuf.c \
 *       --func BG_SYS_AllocTileBuf --addr 0x02043130 --cc 1.1p1 --arm
 */
void BG_SYS_AllocTileBuf(u16 flags, u8 *buf, u32 page)
{
    u8 *tmp;
    u16 heap;
    u8 i;
    u8 j;

    if (flags == 0) {
        return;
    }

    heap = (u16)page;
    heap = (heap & 0x7FFF) | 0x8000;

    tmp = func_02030734(heap, 0x40, 0,
                        (const char *)func_02043130_File, 0xD48);

    if (flags & 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                tmp[i * 8 + j] = buf[i * 8 + (7 - j)];
            }
        }
        MI_CpuCopy8(buf, tmp, 0x40);
    }

    if (flags & 2) {
        for (i = 0; i < 8; i++) {
            MI_CpuCopy8(tmp + i * 8, buf + (7 - i) * 8, 8);
        }
        MI_CpuCopy8(buf, tmp, 0x40);
    }

    func_020307B0(tmp);
}

/*
 * The 16-bit member of the set / add / subtract family that BG_SYS_Apply
 * and BG_SYS_ApplyCenterOp cover for the 32-bit registers: opcodes 0..2 on the
 * halfword at +0x18.  Three comparisons rather than a table, because the
 * arms are too few to be worth one; the last arm is folded into predicated
 * `ldrheq`/`subeq`/`strheq` in the fall-through block and only the first
 * two get out-of-line bodies.
 */
void BG_SYS_SetAffineField(struct BgLayer *p, u32 op, u16 value)
{
    switch (op) {
    case 0:
        p->rotation = value;
        break;
    case 1:
        p->rotation = p->rotation + value;
        break;
    case 2:
        p->rotation = p->rotation - value;
        break;
    }
}

/*
 * Apply one of three operations (set / add / subtract) to one of two
 * 32-bit scroll registers of the object, at +0x1c and +0x20, selected by
 * the opcode in r1.  Opcodes 0..2 are live case labels with empty bodies:
 * they are what makes the dispatch table start at zero and therefore what
 * makes it exist at all
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Their table
 * slots hold a bare `bx lr` rather than a branch, same as the out-of-range
 * default.
 *
 * The companion BG_SYS_ApplyCenterOp handles opcodes 9..14 on the two registers
 * at +0x24 and +0x28; nothing in this packet covers 15 and above.
 */
void BG_SYS_Apply(struct BgLayer *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        p->scaleX = value;
        break;
    case 4:
        p->scaleX = p->scaleX + value;
        break;
    case 5:
        p->scaleX = p->scaleX - value;
        break;
    case 6:
        p->scaleY = value;
        break;
    case 7:
        p->scaleY = p->scaleY + value;
        break;
    case 8:
        p->scaleY = p->scaleY - value;
        break;
    }
}

/* Opcode numbers; 0..8 belong to the rotation and scale versions. */
enum {
    BG_CENTER_X_SET = 9,
    BG_CENTER_X_ADD = 10,
    BG_CENTER_X_SUB = 11,
    BG_CENTER_Y_SET = 12,
    BG_CENTER_Y_ADD = 13,
    BG_CENTER_Y_SUB = 14
};

void BG_SYS_ApplyCenterOp(struct BgLayer *bg, u32 opcode, u32 operand)
{
    switch (opcode) {
    case BG_CENTER_X_SET:
        bg->centerX = operand;
        break;
    case BG_CENTER_X_ADD:
        bg->centerX = bg->centerX + operand;
        break;
    case BG_CENTER_X_SUB:
        bg->centerX = bg->centerX - operand;
        break;
    case BG_CENTER_Y_SET:
        bg->centerY = operand;
        break;
    case BG_CENTER_Y_ADD:
        bg->centerY = bg->centerY + operand;
        break;
    case BG_CENTER_Y_SUB:
        bg->centerY = bg->centerY - operand;
        break;
    }
}
