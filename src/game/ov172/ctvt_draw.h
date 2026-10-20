#ifndef GAME_OV172_CTVT_DRAW_H
#define GAME_OV172_CTVT_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctvt_draw.c, prototypes copied from their definitions. */

#include "../ov172/ctvt_types.h"
#include "../ov172/ctvt_types.h"
#include "../types.h"

CtvtDrawScene *CTVT_DRAW_Create(CtvtWork *work, u16 heapId);
void CTVT_DRAW_Free(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_Init(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_Exit(CtvtWork *work, CtvtDrawScene *scene);
int CTVT_DRAW_Main(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdateCanvasMode(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdatePanelMode(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdateCanvasTouch(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_SlidePanel(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_UpdateToolButtons(CtvtWork *work, CtvtDrawScene *scene);
void CTVT_DRAW_ShowHelp(CtvtWork *work, CtvtDrawScene *scene, int page);
int CTVT_DRAW_CheckLeave(CtvtWork *work, int *out);
void CTVT_DRAW_ShowMessage(CtvtWork *work, CtvtDrawScene *scene, int msgId);
void CTVT_DRAW_ClosePickers(CtvtWork *work, CtvtDrawScene *scene);
/* END mkheaders: generated region */

#endif
