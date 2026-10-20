#ifndef GAME_ARM9_TOUCHPANEL_H
#define GAME_ARM9_TOUCHPANEL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of touchpanel.c, prototypes copied from their definitions. */

#include "../arm9/touchpanel_shared_types.h"
#include "../types.h"

TouchPanelWork *TOUCHPANEL_GetWork(void);
u16 TOUCHPANEL_ReadPointX(UiCtx *ui);
u16 TOUCHPANEL_ReadPointY(UiCtx *ui);
int TOUCHPANEL_ReadCont(UiCtx *ui);
u16 TOUCHPANEL_ReadTrg(UiCtx *ui);
TouchPanelWork *TOUCHPANEL_Create(u32 heapId);
void TOUCHPANEL_MainSys(UiCtx *ui);
void TOUCHPANEL_Main(void);
u32 TOUCHPANEL_HitCircle(const TouchHitTable *hit, s32 x, s32 y);
u32 TOUCHPANEL_HitRect(const TouchHitTable *hit, u32 x, u32 y);
int TOUCHPANEL_SearchHitTable(const TouchHitTable *tbl, u32 x, u32 y);
int TOUCHPANEL_HitContSys(UiCtx *ui, const TouchHitTable *tbl);
int TOUCHPANEL_HitCont(const TouchHitTable *tbl);
int TOUCHPANEL_HitTrgSys(UiCtx *ui, const TouchHitTable *tbl);
int TOUCHPANEL_HitTrg(const TouchHitTable *tbl);
int TOUCHPANEL_GetContSys(UiCtx *ui);
int TOUCHPANEL_GetCont(void);
u16 TOUCHPANEL_GetTrgSys(UiCtx *ui);
int TOUCHPANEL_GetTrg(void);
u32 TOUCHPANEL_GetPointContSys(UiCtx *ui, u32 *x, u32 *y);
u32 TOUCHPANEL_GetPointCont(u32 *x, u32 *y);
u32 TOUCHPANEL_GetPointTrgSys(UiCtx *ui, u32 *x, u32 *y);
u32 TOUCHPANEL_GetPointTrg(u32 *x, u32 *y);
u32 TOUCHPANEL_HitPoint(const TouchHitTable *tbl, u32 x, u32 y);
u32 TOUCHPANEL_RequestAutoSamplingStop(TouchPanelWork *tp);
void TOUCHPANEL_AutoSamplingRestartSys(UiCtx *ui);
void TOUCHPANEL_AutoSamplingRestart(void);
void TOUCHPANEL_AutoSamplingStopSys(UiCtx *ui);
void TOUCHPANEL_AutoSamplingStop(void);
u32 TOUCHPANEL_RequestAutoSamplingStart(TouchPanelWork *tp);
void TOUCHPANEL_ClearFrameRateWork(UiCtx *ui);
void TOUCHPANEL_SetPoint(UiCtx *ui, u16 x, u16 y, u16 x30, u16 y30);
void TOUCHPANEL_SetTrg(UiCtx *ui, int trg, int trg30);
void TOUCHPANEL_SetCont(UiCtx *ui, int cont, int cont30);
/* END mkheaders: generated region */

#endif
