#ifndef GAME_ARM9_PALANM_H
#define GAME_ARM9_PALANM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of palanm.c, prototypes copied from their definitions. */

struct PalAnmSlot;

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
void PALANM_SetSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx, void *rawBuf, void *workBuf, u32 size);
void PALANM_AllocSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx, u32 size, u32 heapId);
void PALANM_FreeSlotBuffers(struct PalAnmSlot *palSlots, u32 slotIdx);
void PALANM_CopyToSlot(struct PalAnmSlot *palSlots, const void *src, u32 slotIdx, u32 dstOffset, u16 size);
void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *palSlots, u32 arcId, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset);
void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *palSlots, u32 arcId, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset);
void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *palSlots, void *arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset, u16 srcOffset);
void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *palSlots, void *arcHandle, u32 fileId, u32 heapId, u32 slotIdx, u32 byteSize, u16 dstOffset);
void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *palSlots, u32 bank, u32 dstOffset, u32 size);
int PALANM_GetDefaultWork(char *p, int i);
int PALANM_GetTransWork(char *p, int i);
u8 PALANM_CheckBit(u32 val, int bit);
void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);
void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);
/* END mkheaders: generated region */

#endif
