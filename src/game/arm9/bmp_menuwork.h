#ifndef GAME_ARM9_BMP_MENUWORK_H
#define GAME_ARM9_BMP_MENUWORK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bmp_menuwork.c, prototypes copied from their definitions. */

struct BmpWin;
struct MsgBank;
struct U16Vec;

#include "../types.h"
#include "../arm9/bmp_menuwork_shared_types.h"

u8 BMP_MENUWORK_GetCharFileId(int index);
u8 BMP_MENUWORK_GetPlttFileId(int index);
void BMP_MENUWORK_LoadChar(u32 layer, u32 tileOffset, u32 frameId, u32 heapId);
void BMP_MENUWORK_LoadPltt(u32 layer, u32 palSlot, u32 frameId, u16 heapId);
void BMP_MENUWORK_LoadCharAndPltt(u32 layer, u32 tileOffset, u32 palSlot, u32 frameId, u16 heapId);
void *BMP_MENUWORK_LoadFrameGfx(u32 layer, u32 palSlot, u32 frameId, u16 heapId);
void BMP_MENUWORK_FreeTileRun(int layer, u32 packedOffsets);
void BMP_MENUWORK_DrawFrame(u16 bgId, u8 x, u8 y, u8 width, u8 height, u32 palette, u16 tileBase);
void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int commitMode, u16 tileBase, u32 palette);
void BMP_MENUWORK_DrawWindowEx(struct BmpWin *desc, u32 commitMode, u32 tileBase, u32 palette);
void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, u32 commitMode);
void *BMP_MENUWORK_Create(u32 count, u32 heapId);
u32 BMP_MENUWORK_Delete(void *items);
void BMP_MENUWORK_AddMsgItem(BmpMenuWork *items, struct MsgBank *bank, u32 msgId, u32 param, u32 heapId);
void BMP_MENUWORK_AddStrItem(BmpMenuWork *items, const struct U16Vec *src, u32 param, u32 heapId);
BmpMenuWork *BMP_MENUWORK_FindFreeEntry(BmpMenuWork *items, u32 *outTerminatorValue);
void BMP_MENUWORK_ReleaseItems(BmpMenuWork *items);
u32 BMP_MENUWORK_CountItems(BmpMenuWork *items);
/* END mkheaders: generated region */

#endif
