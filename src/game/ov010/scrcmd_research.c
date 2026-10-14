/*
 * file:     scrcmd_research.c
 * unit:     yes
 * function: SCRCMD_RESEARCH_CmdGetResearchRank, SCRCMD_RESEARCH_CmdRaiseResearchRank, SCRCMD_RESEARCH_CmdGetMissionIndex, SCRCMD_RESEARCH_CmdGetMissionTargets, SCRCMD_RESEARCH_CmdGetMissionElapsedHours, SCRCMD_RESEARCH_CmdStartMission, SCRCMD_RESEARCH_CmdClearMission, SCRCMD_RESEARCH_CmdGetTopTallyEntry, SCRCMD_RESEARCH_CmdSetSurveyAnswer, SCRCMD_RESEARCH_CmdStartResearchReport, SCRCMD_RESEARCH_CmdGetMissionStatus, SCRCMD_RESEARCH_CmdGetMissionProgress, SCRCMD_RESEARCH_GetCurrentMissionStatus, SCRCMD_RESEARCH_GetMissionStatus, SCRCMD_RESEARCH_GetTallyTotal, SCRCMD_RESEARCH_AreMissionTargetsAtGoal, SCRCMD_RESEARCH_IsMissionTimeUp, SCRCMD_RESEARCH_AreAllTargetValuesRecorded, SCRCMD_RESEARCH_AreMissionTargetsAtCap, SCRCMD_RESEARCH_GetMissionShortfall, SCRCMD_RESEARCH_GetMissionHoursLeft, SCRCMD_RESEARCH_GetMissionElapsedHours, SCRCMD_RESEARCH_GetMissionKind, SCRCMD_RESEARCH_GetMissionTargetCount, SCRCMD_RESEARCH_GetMissionTargetIds, SCRCMD_RESEARCH_GetMissionGoal, SCRCMD_RESEARCH_GetMissionTimeLimitHours
 * address:  0x0216B504
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_0216B24C.c by tools/splitfile.py.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C22C  0x0200C22C  thumb
 *   GAME_BEACON_SetResearchTeamRank  0x02027138  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0200C33C  0x0200C33C  thumb
 *   func_0200E394  0x0200E394  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 *   func_0200C358  0x0200C358  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_0200E4F8  0x0200E4F8  thumb
 *   func_0200E4B0  0x0200E4B0  thumb
 *   sTallyCategoryEntryCount     0x0217219C  data  ov010  a1
 *   sTallyCategoryEntryIds     0x021721BC  data  ov010  a1
 *   func_0200E3A0  0x0200E3A0  thumb
 *   func_0200E3E8  0x0200E3E8  thumb
 *   GAME_BEACON_SetQuestionnaire  0x02027100  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   EVENT_RESEARCH_RADAR_CreateReportTask  0x021670F8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200E458 0x0200E458 thumb
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200C34C 0x0200C34C thumb
 *   func_0200C37C  0x0200C37C  thumb
 *   func_020891E0  0x020891E0  arm
 *   sMissionKind 0x021723BC data a1
 *   sMissionTargetCount 0x021723BD data a1
 *   sMissionTargetId0 0x021723BE data a1
 *   sMissionTargetId1 0x021723BF data a1
 *   sMissionTargetId2 0x021723C0 data a1
 *   sMissionGoal 0x021723C1 data a1
 *   sMissionTimeLimitHours 0x021723C2 data a1
 */
#include "field_intrude_event_shared_types.h"
#include "scrcmd_research_shared_types.h"

struct BeaconSave;

struct RTCDate;

struct RTCTime;

typedef unsigned long long u64;

typedef struct { u32 year, month, day, week; } RTCDateFields;

typedef struct { u32 hour, minute, second; } RTCTimeFields;

extern void *SCRCMD_WORK_GetScriptWork(struct ScrCmdWork *work);

extern void *SCRCMD_WORK_GetGameData(struct ScrCmdWork *work);

extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern struct BeaconSave *func_0200C0F0(void *saveControl);

extern u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptContext *ctx, struct ScrCmdWork *work);

extern u8 func_0200C224(struct BeaconSave *beacon);

extern int func_0200C22C();

extern int GAME_BEACON_SetResearchTeamRank();

extern u8 func_0200C32C(struct BeaconSave *beacon);

extern int func_0200C33C(struct BeaconSave *beacon, u32 index);

extern void *func_0200E394(void *saveControl);

extern unsigned int SCRIPT_WORK_ReadWorkValue(struct ScriptContext *ctx, struct ScrCmdWork *work);

extern void func_0200C334(struct BeaconSave *beacon, u8 missionIndex);

extern void func_0200C344(struct BeaconSave *beacon, u8 slot, u8 targetId);

extern void func_0200C358(struct BeaconSave *beacon, u32 slot, int value);

extern u64 func_0203F524();

extern void func_0200C384(struct BeaconSave *beacon, u32 lo, u32 hi);

extern int func_0200E4F8(int tally, int category, int entry);

extern u32 func_0200E4B0(u8 *tally, u32 category, u32 entry);

extern void *func_0200E3A0(void *survey);

extern void func_0200E3E8(u8 *answers, int questionId, u32 answer);

extern void GAME_BEACON_SetQuestionnaire(const void *answers);

extern void *SCRCMD_WORK_GetGameSystem(struct ScrCmdWork *work);

extern void *EVENT_RESEARCH_RADAR_CreateReportTask(void *gameSystem);

extern int SCRIPT_SYS_CallEvent(void *scriptSystem, void *event);

extern void *func_0200C0E8(void *saveControl);

extern u16 func_0200E458(const u16 *tally, int id);

extern u32 func_0200E47C(u8 *tally, int id);

extern u16 func_0200C34C(struct BeaconSave *beacon, u32 slot);

extern unsigned long long func_0200C37C(struct BeaconSave *beacon);

extern void func_020891E0(struct RTCDate *date, struct RTCTime *time, long long sec);

extern u8 sTallyCategoryEntryCount[];

extern u8 sTallyCategoryEntryIds[];

extern const u8 sMissionKind[];

extern const u8 sMissionTargetCount[];

extern const u8 sMissionTargetId0[], sMissionTargetId1[], sMissionTargetId2[];

extern const u8 sMissionGoal[];

extern const u8 sMissionTimeLimitHours[];

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

/* Script command: writes the research team rank to a work variable. */
int SCRCMD_RESEARCH_CmdGetResearchRank(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    void *saveControl;
    struct BeaconSave *beacon;
    u16 *dst;

    SCRCMD_WORK_GetScriptWork(scrWork);
    gameData = SCRCMD_WORK_GetGameData(scrWork);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    beacon = func_0200C0F0(saveControl);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    *dst = func_0200C224(beacon);
    return 0;
}

/* Script command: raises the research team rank by one (up to 5). */
int SCRCMD_RESEARCH_CmdRaiseResearchRank(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    struct BeaconSave *beacon;
    int rank;

    SCRCMD_WORK_GetScriptWork(scrWork);
    gameData = SCRCMD_WORK_GetGameData(scrWork);
    beacon = func_0200C0F0(GAME_DATA_GetSaveControl(gameData));
    rank = func_0200C224(beacon);
    if (rank >= 5)
        return 0;
    func_0200C22C(beacon, rank + 1);
    GAME_BEACON_SetResearchTeamRank((u8)(rank + 1));
    return 0;
}

/* Script command: writes the current mission index to a work variable. */
int SCRCMD_RESEARCH_CmdGetMissionIndex(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    void *saveControl;
    struct BeaconSave *beacon;
    u16 *dst;

    SCRCMD_WORK_GetScriptWork(scrWork);
    gameData = SCRCMD_WORK_GetGameData(scrWork);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    beacon = func_0200C0F0(saveControl);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    *dst = func_0200C32C(beacon);
    return 0;
}

/* Script command: writes the three mission target ids to three work variables. */
int SCRCMD_RESEARCH_CmdGetMissionTargets(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct BeaconSave *beacon;
    u16 *dst0;
    u16 *dst1;
    u16 *dst2;

    SCRCMD_WORK_GetScriptWork(scrWork);
    beacon = func_0200C0F0(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork)));
    dst0 = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    dst1 = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    dst2 = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    *dst0 = func_0200C33C(beacon, 0);
    *dst1 = func_0200C33C(beacon, 1);
    *dst2 = func_0200C33C(beacon, 2);
    return 0;
}

/* Script command: writes the hours elapsed since the mission started (at most 24). */
int SCRCMD_RESEARCH_CmdGetMissionElapsedHours(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    void *saveControl;
    u16 *dst;

    SCRCMD_WORK_GetScriptWork(scrWork);
    gameData = SCRCMD_WORK_GetGameData(scrWork);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    *dst = SCRCMD_RESEARCH_GetMissionElapsedHours(saveControl);
    return 0;
}

/* Script command: starts a mission (index and three target ids), zeroes the progress and stamps the time. */
int SCRCMD_RESEARCH_CmdStartMission(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct BeaconSave *beacon;
    u16 targetId[3];
    int i;
    void *saveControl;
    int missionIndex;
    int zero;
    u64 now;

    SCRCMD_WORK_GetScriptWork(scrWork);
    saveControl = GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork));
    beacon = func_0200C0F0(saveControl);
    func_0200E394(saveControl);
    missionIndex = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    targetId[0] = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    targetId[1] = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    targetId[2] = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    func_0200C334(beacon, missionIndex);
    zero = 0;
    for (i = 0; i < 3; i++) {
        func_0200C344(beacon, i, targetId[i]);
        func_0200C358(beacon, (u8)i, zero);
    }
    now = func_0203F524();
    func_0200C384(beacon, (u32)now, (u32)(now >> 32));
    return zero;
}

/* Script command: clears the mission (index 0, target ids 0xFF). */
int SCRCMD_RESEARCH_CmdClearMission(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *saveControl;
    struct BeaconSave *beacon;
    int i;

    SCRCMD_WORK_GetScriptWork(scrWork);
    saveControl = GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork));
    beacon = func_0200C0F0(saveControl);
    func_0200E394(saveControl);
    func_0200C334(beacon, 0);
    for (i = 0; i < 3; i++)
        func_0200C344(beacon, (u8)i, 0xFF);
    return 0;
}

/* Script command: writes the id of the entry with the highest tally (both counters summed) in a category. */
int SCRCMD_RESEARCH_CmdGetTopTallyEntry(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    int i;
    int category;
    void *tally;
    int best;
    u16 *dst;
    int entryId;
    int entryCount;

    SCRCMD_WORK_GetScriptWork(scrWork);
    tally = func_0200E394(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork)));
    category = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    entryCount = sTallyCategoryEntryCount[category];
    best = -1;
    for (i = 0; i < entryCount; i++) {
        int countA = func_0200E4F8((int)tally, category, i + 1);
        int countB = func_0200E4B0(tally, category, i + 1);
        int score = countA + countB;
        if (best < score) {
            best = score;
            entryId = sTallyCategoryEntryIds[category * 17 + i];
        }
    }
    *dst = entryId;
    return 0;
}

/* Script command: stores one answer of the survey. */
int SCRCMD_RESEARCH_CmdSetSurveyAnswer(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *answers;
    int questionId;
    int answer;

    SCRCMD_WORK_GetScriptWork(scrWork);
    answers = func_0200E3A0(func_0200E394(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork))));
    questionId = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    answer = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    func_0200E3E8(answers, (u8)questionId, answer);
    GAME_BEACON_SetQuestionnaire(answers);
    return 0;
}

/* Script command: starts the research report event. */
int SCRCMD_RESEARCH_CmdStartResearchReport(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem;
    void *gameSystem;
    void *reportEvent;

    scriptSystem = SCRCMD_WORK_GetScriptWork(scrWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    reportEvent = EVENT_RESEARCH_RADAR_CreateReportTask(gameSystem);
    SCRIPT_SYS_CallEvent(scriptSystem, reportEvent);
    return 1;
}

/* Script command: writes the status of a mission (current one or another by index). */
int SCRCMD_RESEARCH_CmdGetMissionStatus(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *saveControl;
    void *beacon;
    int missionIndex;
    u16 *dst;

    saveControl = GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork));
    beacon = func_0200C0E8(saveControl);
    missionIndex = (u8)SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    if (missionIndex == func_0200C32C(beacon)) {
        SCRCMD_RESEARCH_GetCurrentMissionStatus(saveControl, dst);
    } else {
        SCRCMD_RESEARCH_GetMissionStatus(saveControl, missionIndex, dst);
    }
    return 0;
}

/* Script command: writes the progress of the current mission (shortfall or hours left, by kind). */
int SCRCMD_RESEARCH_CmdGetMissionProgress(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    u16 *dst;
    void *saveControl;
    void *beacon;
    int progress;
    u8 kind;

    saveControl = GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork));
    beacon = func_0200C0E8(saveControl);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    kind = SCRCMD_RESEARCH_GetMissionKind(func_0200C32C(beacon));
    if (kind != 0) {
        if (kind == 1) {
            progress = SCRCMD_RESEARCH_GetMissionHoursLeft(saveControl);
        }
    } else {
        progress = SCRCMD_RESEARCH_GetMissionShortfall(saveControl);
    }
    *dst = progress;
    return 0;
}

/* Status of the current mission: 1 done, 2 not yet (kind 0), 3 running, 4 failed (kind 1). */
int SCRCMD_RESEARCH_GetCurrentMissionStatus(void *saveControl, u16 *status)
{
    const u16 *tally;
    void *beacon;
    int missionIndex;
    int kind;

    tally = func_0200E394(saveControl);
    beacon = func_0200C0E8(saveControl);
    missionIndex = func_0200C32C(beacon);
    kind = (u8)SCRCMD_RESEARCH_GetMissionKind(missionIndex);
    if (kind == 0) {
        if (SCRCMD_RESEARCH_AreMissionTargetsAtGoal(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 2;
        return 2;
    }
    if (kind == 1) {
        if (SCRCMD_RESEARCH_IsMissionTimeUp(saveControl) != 0) {
            if (SCRCMD_RESEARCH_AreAllTargetValuesRecorded(saveControl) != 0) {
                *status = 1;
                return 1;
            }
            *status = 4;
            return 4;
        }
        *status = 3;
        return 3;
    }
    return kind;
}

/* Status of the mission given by index (kind 0: 1 done, 2 not yet; kind 1: 1 done, 3 running). */
int SCRCMD_RESEARCH_GetMissionStatus(void *saveControl, int missionIndex, u16 *status)
{
    const u16 *tally;
    int kind;

    tally = func_0200E394(saveControl);
    func_0200C0E8(saveControl);
    kind = (u8)SCRCMD_RESEARCH_GetMissionKind(missionIndex);
    if (kind == 0) {
        if (SCRCMD_RESEARCH_AreMissionTargetsAtGoal(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 2;
        return 2;
    }
    if (kind == 1) {
        if (SCRCMD_RESEARCH_AreMissionTargetsAtCap(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 3;
        return 3;
    }
    return kind;
}

/* Tally of an id: both counters summed, capped at 999999. */
u32 SCRCMD_RESEARCH_GetTallyTotal(const u16 *tally, int id)
{
    u32 total = func_0200E458(tally, id);
    total += func_0200E47C((u8 *)tally, id);
    if (total > 999999) total = 999999;
    return total;
}

/* 1 when every target of the mission reached its goal. */
int SCRCMD_RESEARCH_AreMissionTargetsAtGoal(const u16 *tally, int missionIndex)
{
    int i;
    u8 targetId[4];
    int targetCount;
    u32 goal;

    SCRCMD_RESEARCH_GetMissionTargetIds(missionIndex, targetId);
    targetCount = (u8)SCRCMD_RESEARCH_GetMissionTargetCount(missionIndex);
    goal = SCRCMD_RESEARCH_GetMissionGoal(missionIndex);
    for (i = 0; i < targetCount; i++) {
        if (SCRCMD_RESEARCH_GetTallyTotal(tally, targetId[i]) < goal) {
            return 0;
        }
    }
    return 1;
}

/* 1 when the time limit of the current mission is used up. */
int SCRCMD_RESEARCH_IsMissionTimeUp(void *saveControl)
{
    int missionIndex;
    int elapsedHours;
    void *beacon;

    func_0200E394(saveControl);
    beacon = func_0200C0E8(saveControl);
    missionIndex = func_0200C32C(beacon);
    elapsedHours = SCRCMD_RESEARCH_GetMissionElapsedHours(saveControl);
    if (SCRCMD_RESEARCH_GetMissionTimeLimitHours((u8)missionIndex) > elapsedHours)
        return 0;
    return 1;
}

/* 1 when every target slot of the current mission holds a recorded value. */
int SCRCMD_RESEARCH_AreAllTargetValuesRecorded(void *saveControl)
{
    void *beacon;
    int i, targetCount;
    beacon = func_0200C0E8(saveControl);
    targetCount = (u8)SCRCMD_RESEARCH_GetMissionTargetCount(func_0200C32C(beacon));
    for (i = 0; i < targetCount; i++) {
        if (func_0200C34C(beacon, (u8)i) == 0) return 0;
    }
    return 1;
}

/* 1 when every target of the mission is at the cap of 999999. */
int SCRCMD_RESEARCH_AreMissionTargetsAtCap(const u16 *tally, int missionIndex)
{
    int i;
    u8 targetId[4];
    int targetCount;

    SCRCMD_RESEARCH_GetMissionTargetIds(missionIndex, targetId);
    targetCount = (u8)SCRCMD_RESEARCH_GetMissionTargetCount(missionIndex);
    SCRCMD_RESEARCH_GetMissionGoal(missionIndex);
    for (i = 0; i < targetCount; i++) {
        if (SCRCMD_RESEARCH_GetTallyTotal(tally, targetId[i]) < 999999) {
            return 0;
        }
    }
    return 1;
}

/* Goal minus the smallest target tally of the current mission. */
u16 SCRCMD_RESEARCH_GetMissionShortfall(void *saveControl)
{
    int i;
    u8 targetId[4];
    int targetCount;
    u32 goal;
    u32 smallest;
    void *tally;
    int missionIndex;

    tally = func_0200E394(saveControl);
    missionIndex = func_0200C32C(func_0200C0E8(saveControl));
    goal = SCRCMD_RESEARCH_GetMissionGoal(missionIndex);
    targetCount = (u8)SCRCMD_RESEARCH_GetMissionTargetCount(missionIndex);
    SCRCMD_RESEARCH_GetMissionTargetIds(missionIndex, targetId);
    smallest = 1009998;
    for (i = 0; i < targetCount; i++) {
        u32 value = SCRCMD_RESEARCH_GetTallyTotal(tally, targetId[i]);
        if (value < smallest) {
            smallest = value;
        }
    }
    return goal - smallest;
}

/*
 * Hours left of the current mission (0 when used up).
 * arithmetic: subtract in u32, then interpret the resulting sign bit as
 * target int before the BPL clamp; this preserves SUB wrapping without bounds.
 * interface: this caller loads saveControl into r0 at 0216BAFC and
 * SCRCMD_RESEARCH_GetMissionElapsedHours forwards entry r0 to 0200C0F0; preserve that input.
 */
u16 SCRCMD_RESEARCH_GetMissionHoursLeft(void *saveControl)
{
    int missionIndex, elapsedHours, hoursLeft;
    func_0200E394(saveControl);
    missionIndex = func_0200C32C(func_0200C0E8(saveControl));
    elapsedHours = SCRCMD_RESEARCH_GetMissionElapsedHours(saveControl);
    hoursLeft = (int)((u32)SCRCMD_RESEARCH_GetMissionTimeLimitHours((u8)missionIndex) - (u32)elapsedHours);
    if (hoursLeft < 0) hoursLeft = 0;
    return (u16)hoursLeft;
}

/* Hours since the mission started, 24 when a day or more passed, 0 when no mission runs. */
int SCRCMD_RESEARCH_GetMissionElapsedHours(void *saveControl)
{
    struct {
        RTCTimeFields time;
        RTCDateFields date;
    } elapsed;
    struct BeaconSave *beacon;
    u64 startTime;

    beacon = func_0200C0F0(saveControl);
    if (func_0200C32C(beacon) == 0) {
        return 0;
    }
    startTime = func_0200C37C(beacon);
    func_020891E0((struct RTCDate *)&elapsed.date, (struct RTCTime *)&elapsed.time, func_0203F524() - startTime);
    if (elapsed.date.year != 0 || elapsed.date.month > 1 || elapsed.date.day > 1) {
        return 24;
    }
    return (u16)elapsed.time.hour;
}

/*
 * The mission table is an array of 7-byte records: kind, target count,
 * three target ids, goal, time limit in hours (one symbol per field).
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 */
int SCRCMD_RESEARCH_GetMissionKind(int missionIndex)
{
    return *(const u8 *)((u32)sMissionKind + (u32)missionIndex * 7u);
}

int SCRCMD_RESEARCH_GetMissionTargetCount(int missionIndex)
{
    return *(const u8 *)((u32)sMissionTargetCount + (u32)missionIndex * 7u);
}

/*
 * arithmetic: unsigned 32-bit address/stride arithmetic preserves original
 * MUL/ADD wrapping; each byte load remains ordered before its output store.
 */
void SCRCMD_RESEARCH_GetMissionTargetIds(int missionIndex, u8 *targetIds)
{
    targetIds[0] = *(const u8 *)((u32)sMissionTargetId0 + (u32)missionIndex * 7u);
    targetIds[1] = *(const u8 *)((u32)sMissionTargetId1 + (u32)missionIndex * 7u);
    targetIds[2] = *(const u8 *)((u32)sMissionTargetId2 + (u32)missionIndex * 7u);
}

int SCRCMD_RESEARCH_GetMissionGoal(int missionIndex)
{
    return *(const u8 *)((u32)sMissionGoal + (u32)missionIndex * 7u);
}

int SCRCMD_RESEARCH_GetMissionTimeLimitHours(int missionIndex)
{
    return *(const u8 *)((u32)sMissionTimeLimitHours + (u32)missionIndex * 7u);
}
