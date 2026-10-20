#ifndef GAME_OV010_SCRCMD_RESEARCH_H
#define GAME_OV010_SCRCMD_RESEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_research.c, prototypes copied from their definitions. */

struct ScriptContext;
struct ScrcmdWork;

#include "../types.h"

int SCRCMD_RESEARCH_CmdGetResearchRank(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdRaiseResearchRank(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdGetMissionIndex(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdGetMissionTargets(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdGetMissionElapsedHours(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdStartMission(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdClearMission(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdGetTopTallyEntry(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdSetSurveyAnswer(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdStartResearchReport(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdGetMissionStatus(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_CmdGetMissionProgress(struct ScriptContext *ctx, struct ScrcmdWork *scrWork);
int SCRCMD_RESEARCH_GetCurrentMissionStatus(void *saveControl, u16 *status);
int SCRCMD_RESEARCH_GetMissionStatus(void *saveControl, int missionIndex, u16 *status);
u32 SCRCMD_RESEARCH_GetTallyTotal(const u16 *tally, int id);
int SCRCMD_RESEARCH_AreMissionTargetsAtGoal(const u16 *tally, int missionIndex);
int SCRCMD_RESEARCH_IsMissionTimeUp(void *saveControl);
int SCRCMD_RESEARCH_AreAllTargetValuesRecorded(void *saveControl);
int SCRCMD_RESEARCH_AreMissionTargetsAtCap(const u16 *tally, int missionIndex);
u16 SCRCMD_RESEARCH_GetMissionShortfall(void *saveControl);
u16 SCRCMD_RESEARCH_GetMissionHoursLeft(void *saveControl);
int SCRCMD_RESEARCH_GetMissionElapsedHours(void *saveControl);
int SCRCMD_RESEARCH_GetMissionKind(int missionIndex);
int SCRCMD_RESEARCH_GetMissionTargetCount(int missionIndex);
void SCRCMD_RESEARCH_GetMissionTargetIds(int missionIndex, u8 *targetIds);
int SCRCMD_RESEARCH_GetMissionGoal(int missionIndex);
int SCRCMD_RESEARCH_GetMissionTimeLimitHours(int missionIndex);
/* END mkheaders: generated region */

#endif
