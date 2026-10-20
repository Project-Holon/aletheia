#ifndef GAME_OV110_PMSIV_EDIT_H
#define GAME_OV110_PMSIV_EDIT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pmsiv_edit.c, prototypes copied from their definitions. */

struct PmsivEdit;
struct PmsInputView;
struct PmsInputState;
struct BmpWin;
struct PmsivTextParser;
struct U16Vec;

#include "../types.h"

struct PmsivEdit *PMSIV_EDIT_Create(struct PmsInputView *view, struct PmsInputState *input, void *param);
void PMSIV_EDIT_Delete(struct PmsivEdit *p);
void PMSIV_EDIT_Setup(struct PmsivEdit *p, void *arcHandle);
vu16 GX_GetVCount(void);
void PMSIV_EDIT_UpdateFramePosition(void *task, struct PmsivEdit *p);
void PMSIV_EDIT_StartPanelScroll(struct PmsivEdit *p, u8 closing);
int PMSIV_EDIT_StepPanelScroll(struct PmsivEdit *p);
void PMSIV_EDIT_LoadPalette(struct PmsivEdit *p, void *arcHandle);
void PMSIV_EDIT_ApplyPalette(struct PmsivEdit *p);
void PMSIV_EDIT_InitSlotPositions(struct PmsivEdit *p);
void PMSIV_EDIT_CreateWordIcons(struct PmsivEdit *p);
void PMSIV_EDIT_CreateCursors(struct PmsivEdit *p);
void PMSIV_EDIT_Redraw(struct PmsivEdit *p);
void PMSIV_EDIT_GetSlotRect(struct PmsivEdit *p, unsigned char *rect, int slot);
int PMSIV_EDIT_DrawFreeText(struct PmsivEdit *p, struct BmpWin *window, u8 screen);
void PMSIV_EDIT_ParserInit(struct PmsivTextParser *parser, struct PmsivEdit *p);
void PMSIV_EDIT_ParserFree(struct PmsivTextParser *parser);
int PMSIV_EDIT_ParserNext(struct PmsivTextParser *parser, struct U16Vec *out);
void PMSIV_EDIT_SlotPosToBoxOrigin(const short *pos, short *boxOrigin);
void PMSIV_EDIT_BoxOriginToSlotPos(const short *boxOrigin, short *pos);
void PMSIV_EDIT_SetCursorPressed(struct PmsivEdit *p, int pressed);
u32 PMSIV_EDIT_IsSubScreenLayer(u32 layer);
unsigned int PMSIV_EDIT_GetSlotCount(struct PmsivEdit *p);
u16 PMSIV_EDIT_GetSlotWordId(struct PmsivEdit *p, int slot);
void PMSIV_EDIT_ReleaseCursor(struct PmsivEdit *p);
void PMSIV_EDIT_PressCursor(struct PmsivEdit *p);
void PMSIV_EDIT_SetCursorsVisible(struct PmsivEdit *p, u32 visible);
void PMSIV_EDIT_NoopA(struct PmsivEdit *p);
void PMSIV_EDIT_NoopB(struct PmsivEdit *p);
void PMSIV_EDIT_PlaceCursorAtSlot(struct PmsivEdit *p, int slot);
/* END mkheaders: generated region */

#endif
