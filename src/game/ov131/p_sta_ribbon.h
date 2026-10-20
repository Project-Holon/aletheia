#ifndef GAME_OV131_P_STA_RIBBON_H
#define GAME_OV131_P_STA_RIBBON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of p_sta_ribbon.c, prototypes copied from their definitions. */

struct PStaRibbonWork;
struct StaRibbonRow;
typedef struct PStaRibbonWork PStaRibbonWork;
typedef struct StaRibbonRow StaRibbonRow;

#include "../ov131/p_status_types.h"
#include "../types.h"

void *P_STA_RIBBON_Create(PStatusWork *wk);
void P_STA_RIBBON_Delete(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Main(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_LoadArcGraphics(PStatusWork *wk, PStaRibbonWork *work, void *arc);
void P_STA_RIBBON_FreeArcGraphics(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_CreateObjects(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_DeleteObjects(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_UpdateInput(PStatusWork *wk, PStaRibbonWork *work);
int P_STA_RIBBON_UpdateKeys(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_UpdateTouch(PStatusWork *wk, PStaRibbonWork *work);
int P_STA_RIBBON_GetTouchedRow(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_SnapCursorToScroll(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_SelectRow(PStatusWork *wk, PStaRibbonWork *work, u8 row);
void P_STA_RIBBON_Scroll(PStatusWork *wk, PStaRibbonWork *work, int delta);
void P_STA_RIBBON_Init(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Show(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Deactivate(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Hide(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_CollectOwned(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_Noop(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_DrawRow(PStatusWork *wk, PStaRibbonWork *work, StaRibbonRow *row);
void P_STA_RIBBON_UpdateRows(PStatusWork *wk, PStaRibbonWork *work);
u32 P_STA_RIBBON_GetOwnedIndex(PStaRibbonWork *work, u32 target);
unsigned int P_STA_RIBBON_GetRowOwnedIndex(PStaRibbonWork *work, unsigned int target);
s16 P_STA_RIBBON_GetRowY(PStaRibbonWork *work, u32 target);
void P_STA_RIBBON_PrintDetail(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_ShowDetail(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_FreeDetailWindows(PStatusWork *wk, PStaRibbonWork *work);
void P_STA_RIBBON_HideDetail(PStatusWork *wk, PStaRibbonWork *work);
/* END mkheaders: generated region */

#endif
