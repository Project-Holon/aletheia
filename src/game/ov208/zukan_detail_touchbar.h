#ifndef GAME_OV208_ZUKAN_DETAIL_TOUCHBAR_H
#define GAME_OV208_ZUKAN_DETAIL_TOUCHBAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_touchbar.c, prototypes copied from their definitions. */

struct Ov208Scene;

#include "../types.h"

char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap,unsigned dexFlags);
void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Scene *m);
void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Scene *m);
void ZUKAN_DETAIL_TOUCHBAR_SetMode(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);
int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(struct Ov208Scene *p, int scrollIdx);
void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int scrollIdx);
unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct Ov208Scene *p);
unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(struct Ov208Scene *p, int enable);
void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind);
void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(struct Ov208Scene *p, int visible);
void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int enabled);
int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);
void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on);
int ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(char *p);
void ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(char *p, unsigned char priority);
void ZUKAN_DETAIL_TOUCHBAR_FlushBar(int unused, char *p);
void ZUKAN_DETAIL_TOUCHBAR_LoadResources(struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_ReleaseResources(char *p);
void ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos(char *p,short offset);
void ZUKAN_DETAIL_TOUCHBAR_LoadBarResources(struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources(struct Ov208Scene *e);
void ZUKAN_DETAIL_TOUCHBAR_UpdateInput(struct Ov208Scene *m);
void ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer(u8 *p);
void ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag(struct Ov208Scene *e);
void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft(struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(struct Ov208Scene *p);
s32 ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable(struct Ov208Scene *m);
int ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind(int kind);
unsigned ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette(unsigned n);
unsigned ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(unsigned n);
void ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources(struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources(struct Ov208Scene *e);
void ZUKAN_DETAIL_TOUCHBAR_LoadRightArrowResources(struct Ov208Scene *p);
void ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(char *p);
void ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput(char *p);
/* END mkheaders: generated region */

#endif
