#ifndef GAME_OV208_ZUKAN_DETAIL_COMMON_H
#define GAME_OV208_ZUKAN_DETAIL_COMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_common.c, prototypes copied from their definitions. */

struct Ov208Ctx;
struct Ov208Blend;
struct Ov208PalFade;
struct Ov208Win;

#include "../types.h"

void *ZUKAN_DETAIL_COMMON_CreateContext(u32 heapId, void *blk, void *display, void *font, void *graphics, void *work, void *headbar, unsigned short *speciesTable, unsigned short entryCount, void *cursorPtr);
void ZUKAN_DETAIL_COMMON_DeleteContext(void *ctx);
void *ZUKAN_DETAIL_COMMON_GetSource(struct Ov208Ctx *p);
void *ZUKAN_DETAIL_COMMON_GetDisplay(struct Ov208Ctx *p);
void *ZUKAN_DETAIL_COMMON_GetFont(struct Ov208Ctx *p);
void *ZUKAN_DETAIL_COMMON_GetGraphics(struct Ov208Ctx *p);
void *ZUKAN_DETAIL_COMMON_GetWorkPtr(struct Ov208Ctx *p);
void *ZUKAN_DETAIL_COMMON_GetHeadbar(struct Ov208Ctx *p);
unsigned short ZUKAN_DETAIL_COMMON_GetEntryCount(struct Ov208Ctx *p);
unsigned short ZUKAN_DETAIL_COMMON_GetCurrentEntry(struct Ov208Ctx *p);
void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(struct Ov208Ctx *p);
void ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(struct Ov208Ctx *p);
void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);
void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *blend);
void ZUKAN_DETAIL_COMMON_UpdateBlendFades(struct Ov208Blend *main, struct Ov208Blend *sub);
int ZUKAN_DETAIL_COMMON_IsBlendBusy(struct Ov208Blend *p);
void ZUKAN_DETAIL_COMMON_StartBlendIn(struct Ov208Blend *p);
void ZUKAN_DETAIL_COMMON_StartBlendOut(struct Ov208Blend *p);
void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, struct Ov208Blend *p);
void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, struct Ov208Blend *p);
void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(struct Ov208Blend *p);
void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, struct Ov208Blend *p);
struct Ov208PalFade *ZUKAN_DETAIL_COMMON_CreatePaletteAnim(u32 heap,u16 mask);
void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap);
void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(struct Ov208PalFade *p);
void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(struct Ov208PalFade *p);
void ZUKAN_DETAIL_COMMON_TransferPalettes(struct Ov208PalFade *p);
int ZUKAN_DETAIL_COMMON_IsFadeBusy(struct Ov208PalFade *p);
void ZUKAN_DETAIL_COMMON_StartFadeOut(struct Ov208PalFade *p);
void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(struct Ov208PalFade *p);
void ZUKAN_DETAIL_COMMON_StartFadeIn(struct Ov208PalFade *p);
void ZUKAN_DETAIL_COMMON_LoadPaletteToSlot(struct Ov208PalFade *p, void *arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset);
void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(struct Ov208PalFade *p);
void ZUKAN_DETAIL_COMMON_RequestFade(struct Ov208PalFade *p, short step, unsigned char startLevel, unsigned char endLevel);
struct Ov208Win *ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
void ZUKAN_DETAIL_COMMON_FreeBgPalette(struct Ov208Win *p);
void ZUKAN_DETAIL_COMMON_TickFlashEffect(struct Ov208Win *p);
u32 ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);
void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 layer, u32 packed);
/* END mkheaders: generated region */

#endif
