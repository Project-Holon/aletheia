#ifndef GAME_ARM9_PMS_DRAW_H
#define GAME_ARM9_PMS_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pms_draw.c, prototypes copied from their definitions. */

struct PmsDraw;
struct BeaconDetailGraQuad;
struct BmpWin;
struct PmsPos;
struct PmsDrawRes;
struct Descriptor;
struct PmsElem;
struct Unit;
struct PrintQueue;
struct GfFont;

#include "../types.h"

struct PmsDraw *PMS_DRAW_Create(struct Unit *clunit, u32 drawType, struct PrintQueue *printQue, struct GfFont *font, u8 plttOffset, u8 elemMax, u16 heapId);
void PMS_DRAW_Main(struct PmsDraw *wk);
void PMS_DRAW_Delete(struct PmsDraw *wk);
void PMS_DRAW_Print(struct PmsDraw *wk, void *bmpWin, struct BeaconDetailGraQuad *pms, u32 id);
void PMS_DRAW_PrintOffset(struct PmsDraw *wk, void *bmpWin, void *pms, u32 id, const void *offset);
u32 PMS_DRAW_IsPrintEnd(struct PmsDraw *wk);
void PMS_DRAW_Clear(struct PmsDraw *wk, int id, u32 isTrans);
void PMS_DRAW_SetVisible(struct PmsDraw *wk, int id, u32 visible);
u32 PMS_DRAW_IsActive(const struct PmsDraw *wk, u32 id);
void PMS_DRAW_SetDecoVisible(struct PmsDraw *wk, u32 id, u32 visible);
void PMS_DRAW_SetDecoPriority(struct PmsDraw *wk, u32 id, u32 priority);
void PMS_DRAW_Copy(struct PmsDraw *wk, u32 srcId, u32 dstId);
void PMS_DRAW_SetNullColorPalette(struct PmsDraw *wk, u8 palette);
void PMS_DRAW_SetPrintColor(struct PmsDraw *wk, u16 color);
void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *wk, u32 follow);
void PMS_DRAW_CalcDecoPos(struct BmpWin *bmpWin, u32 charX, u32 line, const struct PmsPos *offset, struct PmsPos *out);
u32 PMS_DRAW_GetDecoCgrIndex(u32 engine);
u32 PMS_DRAW_GetDecoCelIndex(u32 engine);
u32 PMS_DRAW_GetDecoAnmIndex(u32 engine);
void PMS_DRAW_LoadResources(struct PmsDrawRes *res, u32 plttOffset, u16 heapId);
void PMS_DRAW_ReleaseResources(struct PmsDrawRes *res);
void *PMS_DRAW_CreateDecoActor(struct PmsDrawRes *res, u16 heapId);
void PMS_DRAW_PlaceDecoActor(void *actor, struct Descriptor *bmpWin, u32 charX, u32 line, u32 wordId, const struct PmsPos *offset);
void PMS_DRAW_InitElem(struct PmsElem *elem, struct PmsDrawRes *res, u16 heapId);
void PMS_DRAW_DeleteElem(struct PmsElem *elem);
int PMS_DRAW_UpdateElem(struct PmsElem *elem, void *printQue, int followBgScroll);
void PMS_DRAW_ClearElem(struct PmsElem *elem, u32 isTrans);
void PMS_DRAW_SetElemVisible(struct PmsElem *elem, u32 visible);
u32 PMS_DRAW_GetFrameSurface(u32 frame);
void PMS_DRAW_ClearWork(void *p);
u32 ITEM_GetRegisterFlagId(u32 id);
/* END mkheaders: generated region */

#endif
