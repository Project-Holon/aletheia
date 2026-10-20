#ifndef GAME_OV010_REPORT_EVENT_H
#define GAME_OV010_REPORT_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of report_event.c, prototypes copied from their definitions. */

#include "../ov010/field_event_types.h"
#include "../types.h"

int REPORT_EVENT_Main(ReportEventWork *w, u32 *state);
void REPORT_EVENT_Free(ReportEventWork *w);
void REPORT_EVENT_CreateMessageWindow(ReportEventWork *w);
void REPORT_EVENT_DeleteMessageWindow(ReportEventWork *w);
void REPORT_EVENT_PrintMessage(ReportEventWork *w, u32 msgIndex);
void REPORT_EVENT_StartPrintStream(ReportEventWork *w);
int REPORT_EVENT_UpdatePrintStream(ReportEventWork *w);
int REPORT_EVENT_UpdateMessage(ReportEventWork *w);
void REPORT_EVENT_QueueMessage(ReportEventWork *w, u32 msgIndex);
int REPORT_EVENT_UpdateMessageQueue(ReportEventWork *w);
void REPORT_EVENT_CreateMenuResources(ReportEventWork *w);
void REPORT_EVENT_DeleteMenuResources(ReportEventWork *w);
void REPORT_EVENT_OpenYesNoMenu(ReportEventWork *w);
int REPORT_EVENT_UpdateYesNoMenu(ReportEventWork *w);
void REPORT_EVENT_BeginAvatarAnim(ReportEventWork *w);
void REPORT_EVENT_EndAvatarAnim(ReportEventWork *w);
int REPORT_EVENT_IsAvatarRequestDone(ReportEventWork *w);
int REPORT_EVENT_IsAvatarReady(ReportEventWork *w);
void REPORT_EVENT_StartSaveEffect(ReportEventWork *w);
int REPORT_EVENT_StopSaveEffect(ReportEventWork *w);
/* END mkheaders: generated region */

#endif
