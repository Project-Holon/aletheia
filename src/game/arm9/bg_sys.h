#ifndef GAME_ARM9_BG_SYS_H
#define GAME_ARM9_BG_SYS_H

#include "../arm9/bg_sys_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bg_sys.c, prototypes copied from their definitions. */

struct DispConfig;
struct BgTemplate;
struct BgLayer;
struct DispVram;

#include "../types.h"
#include "../sdk_fx.h"

void BG_SYS_Create(u16 heapId);
void BG_SYS_Delete(void);
u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
u32 BG_SYS_ReserveTileRun(u32 a, u32 b, u32 c);
void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
void BG_SYS_ApplyGraphicsMode(const struct DispConfig *req, u32 which);
void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
void BG_SYS_FreeLayerBuf(u32 i);
void BG_SYS_EnableBg0WithPriority(u32 mode);
void BG_SYS_SetPriority(int idx, unsigned short val);
void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
u32 BG_SYS_GetScrollX(u32 layer);
u32 BG_SYS_GetScrollY(u32 layer);
void BG_SYS_SetScroll(u32 layer, u32 a, u32 b, MtxFx22 *c, u32 d, u32 e);
void BG_SYS_SetScrollRegs(u32 layer, MtxFx22 *a, u32 b, u32 c);
void BG_SYS_SetupMemory(void *dest, const void *src, u32 size);
void BG_SYS_PushTile(u32 index);
void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);
void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode);
void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset);
void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
u32 BG_SYS_CreateTileRun(u32 index, const void *src, u32 size);
void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
void BG_SYS_FreeTiles(u32 idx, u32 count, u32 tile);
void BG_SYS_LoadPltt(u32 bgId, void *src, u16 size, u16 offset);
void BG_SYS_LoadPlttEntry(u32 bgId, u32 color);
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
u8 BG_SYS_GetColorMode(int channel);
u8 BG_SYS_GetTileBytes(int channel);
u8 BG_SYS_GetPriority(u32 layer);
void BG_SYS_Update(void);
void BG_SYS_CommitLayers(void);
void BG_SYS_MarkTileDirty(u32 bit);
void BG_SYS_CommitScroll(void);
void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);
void BG_SYS_ChangeRotation(u32 which, u32 op, u16 value);
void BG_SYS_ChangeScale(u32 which, u32 op, u32 value);
void BG_SYS_ChangeCenter(u32 which, u32 op, u16 value);
u32 BG_SYS_CheckPixelColor(u32 layer, u16 x, u16 y, u16 *flags);
int BG_SYS_ToHwScreenSize(int screenSize, int bgType);
void BG_SYS_GetScreenSizeInTiles(u32 mode, u8 *a, u8 *b);
void BG_SYS_SetScrollField(struct BgLayer *p, u32 op, u32 value);
void BG_SYS_ResetAffineMatrix(u32 layer);
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
void BG_SYS_ClearGraphicsMemory(u32 keepBanks);
void BG_SYS_SetVramBanks(const struct DispVram *banks);
void BG_SYS_ClearMainBgPlanes(void);
void BG_SYS_ClearMainObjPlane(void);
void BG_SYS_ClearMainPlanes(void);
void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
void BG_SYS_SetMainVisiblePlanes(u32 planes);
void BG_SYS_ClearSubBgPlanes(void);
void BG_SYS_ClearSubObjPlane(void);
void BG_SYS_ClearSubPlanes(void);
void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void BG_SYS_SetSubVisiblePlanes(u32 planes);
void BG_SYS_ResetSubDisplay(void);
void BG_SYS_SetLcdSwap(u32 swap);
u32 BG_SYS_GetMainVisiblePlanes(void);
u32 BG_SYS_GetSubVisiblePlanes(void);
/* END mkheaders: generated region */

#endif
