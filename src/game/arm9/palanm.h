#ifndef GAME_ARM9_PALANM_H
#define GAME_ARM9_PALANM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of palanm.c, prototypes copied from their definitions. */

typedef struct PaletteFadeParam PaletteFadeParam;
typedef struct PaletteFadeWork PaletteFadeWork;
typedef struct PaletteFade PaletteFade;

#include "../types.h"

int ITEM_IsBerry(u32 colorCode);
u32 PALANM_IsOutsideReservedIdRange(u16 id);
u16 PALANM_LookupPairedCode(int value, int column);
unsigned short PALANM_GetPairedCodeForFirst(int value);
void PALANM_StopTimer(void);
void PALANM_StartTimer(void);
void PALANM_UpdateTimer(u8 *target);
void *PALANM_Create(u32 heapId);
u32 PALANM_Delete(void *ctx);
void PALANM_SetSlotBuffers(PaletteFade *fade, u32 slotIdx, void *rawBuf, void *workBuf, u32 size);
void PALANM_AllocSlotBuffers(PaletteFade *fade, u32 slotIdx, u32 size, u32 heapId);
void PALANM_FreeSlotBuffers(PaletteFade *fade, u32 slotIdx);
void PALANM_CopyToSlot(PaletteFade *fade, const void *src, u32 slotIdx, u32 dstOffset, u16 size);
void PALANM_LoadArcPaletteToSlotAt(PaletteFade *fade, u32 arcId, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset);
void PALANM_LoadArcPaletteToSlot(PaletteFade *fade, u32 arcId, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset);
void PALANM_LoadHandlePaletteToSlotAt(PaletteFade *fade, void *arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset);
void PALANM_LoadHandlePaletteToSlot(PaletteFade *fade, void *arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset);
void PALANM_CopyHwPaletteToSlot(PaletteFade *fade, u32 bank, u32 dstOffset, u32 size);
int PALANM_GetDefaultWork(char *p, int i);
int PALANM_GetTransWork(char *p, int i);
u8 PALANM_CheckBit(u32 val, int bit);
void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);
void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);
int PALANM_RequestFade(PaletteFade *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
int PALANM_RequestFadeOverwrite(PaletteFade *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
void PALANM_ForceStopFade(PaletteFade *o);
void PALANM_TransferPalettes(PaletteFade *p);
u32 PALANM_GetFadeRequestBits(const PaletteFade *ptr);
void PALANM_SetAutoTransfer(PaletteFade *o, int v);
void PALANM_BlendChannel(PaletteFadeWork *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
void PALANM_BlendChannelMask(PaletteFadeWork *p, u32 idx, u16 m, u8 weight, u16 color);
/* END mkheaders: generated region */

/* Transitional: callers still holding the old slot-array name (removed once tools/palfix.py has run on them). */
#define PalAnmSlot PaletteFade

#endif
