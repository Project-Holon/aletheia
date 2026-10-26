#ifndef GAME_OV034_REPORT_H
#define GAME_OV034_REPORT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of report.c, prototypes copied from their definitions. */

struct Task;

#include "../ov034/report_types.h"
#include "../types.h"

ReportWork *REPORT_Create(void *gameSystem, int heapId);
void REPORT_Delete(ReportWork *work);
void REPORT_ShowPartyIcons(ReportWork *work);
void REPORT_UpdateWindows(ReportWork *work);
int REPORT_IsReady(ReportWork *work);
void REPORT_PrepareSave(ReportWork *work);
unsigned REPORT_CheckSaveCounter(ReportWork *work);
void REPORT_StartSaveAnim(ReportWork *work);
int REPORT_IsSaveAnimDone(ReportWork *work);
void REPORT_StopSaveAnim(ReportWork *work);
void REPORT_InitBgs(u32 heapId);
void REPORT_ExitBgs(void);
void REPORT_LoadBgGraphics(u16 heapId);
void REPORT_InitWindows(ReportWork *work);
void REPORT_ExitWindows(ReportWork *work);
void REPORT_InitActors(ReportWork *work);
void REPORT_ExitActors(ReportWork *work);
void REPORT_UpdateSaveAnim(struct TcbTask * taskArg, void * workArg);
/* END mkheaders: generated region */

#endif
