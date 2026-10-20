#ifndef GAME_OV010_EVENT_RESEARCH_RADAR_H
#define GAME_OV010_EVENT_RESEARCH_RADAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_research_radar.c, prototypes copied from their definitions. */

struct ResearchTopTaskWork;
struct ResearchReportWork;
struct MsgBank;
struct WordSet;
typedef struct ResearchTopTaskWork ResearchTopTaskWork;
typedef struct ResearchReportWork ResearchReportWork;

int EVENT_RESEARCH_RADAR_TopTaskMain(void *task, int *state, ResearchTopTaskWork *work);
void *EVENT_RESEARCH_RADAR_CreateTopTask(void *gameSystem, void *transitionArg);
int EVENT_RESEARCH_RADAR_ReportTaskMain(void *task, int *state, ResearchReportWork *work, int extra);
void *EVENT_RESEARCH_RADAR_CreateReportTask(void *gameSystem);
void EVENT_RESEARCH_RADAR_InitReportWork(ResearchReportWork *work, void *gameSystem);
struct MsgBank *EVENT_RESEARCH_RADAR_LoadReportMsgData(ResearchReportWork *work, int stateRef, ResearchReportWork *workCopy, int extra);
int EVENT_RESEARCH_RADAR_DeleteReportMsgData(ResearchReportWork *work);
void EVENT_RESEARCH_RADAR_CreateInfoWindow(ResearchReportWork *work);
int EVENT_RESEARCH_RADAR_DeleteInfoWindow(ResearchReportWork *work);
struct WordSet *EVENT_RESEARCH_RADAR_CreateWordSet(ResearchReportWork *work);
int EVENT_RESEARCH_RADAR_DeleteWordSet(ResearchReportWork *work);
void EVENT_RESEARCH_RADAR_PrintReport(ResearchReportWork *work);
void EVENT_RESEARCH_RADAR_CloseInfoWindow(ResearchReportWork *work);
int EVENT_RESEARCH_RADAR_GetReportKind(ResearchReportWork *work);
int EVENT_RESEARCH_RADAR_GetReportNumberA(ResearchReportWork *work);
int EVENT_RESEARCH_RADAR_GetReportNumberB(ResearchReportWork *work);
int EVENT_RESEARCH_RADAR_GetReportMessageId(unsigned int kind);
/* END mkheaders: generated region */

#endif
