/*
 * file:     unit_0216B24C.c
 * unit:     yes
 * function: FIELD_G3D_MAP_CreateIntrudeRequestEvent, FIELD_G3D_MAP_IntrudeRequestEventMain, FIELD_G3D_MAP_GetEdgePosition, FIELD_G3D_MAP_CreateSymbolEntryEvent, FIELD_G3D_MAP_StartSymbolEntry, FIELD_G3D_MAP_SymbolEntryEventMain, FIELD_G3D_MAP_CmdGetResearchRank, FIELD_G3D_MAP_CmdRaiseResearchRank, FIELD_G3D_MAP_CmdGetMissionIndex, FIELD_G3D_MAP_CmdGetMissionTargets, FIELD_G3D_MAP_CmdGetMissionElapsedHours, FIELD_G3D_MAP_CmdStartMission, FIELD_G3D_MAP_CmdClearMission, FIELD_G3D_MAP_CmdGetTopTallyEntry, FIELD_G3D_MAP_CmdSetSurveyAnswer, FIELD_G3D_MAP_CmdStartResearchReport, FIELD_G3D_MAP_CmdGetMissionStatus, FIELD_G3D_MAP_CmdGetMissionProgress, FIELD_G3D_MAP_GetCurrentMissionStatus, FIELD_G3D_MAP_GetMissionStatus, FIELD_G3D_MAP_GetTallyTotal, FIELD_G3D_MAP_AreMissionTargetsAtGoal, FIELD_G3D_MAP_IsMissionTimeUp, FIELD_G3D_MAP_AreAllTargetValuesRecorded, FIELD_G3D_MAP_AreMissionTargetsAtCap, FIELD_G3D_MAP_GetMissionShortfall, FIELD_G3D_MAP_GetMissionHoursLeft, FIELD_G3D_MAP_GetMissionElapsedHours, FIELD_G3D_MAP_GetMissionKind, FIELD_G3D_MAP_GetMissionTargetCount, FIELD_G3D_MAP_GetMissionTargetIds, FIELD_G3D_MAP_GetMissionGoal, FIELD_G3D_MAP_GetMissionTimeLimitHours, FIELD_G3D_MAP_CmdStartSpPokeGimmickTask, FIELD_G3D_MAP_CmdMoveSpPokeGimmick, FIELD_G3D_MAP_CmdStartSpPokeGimmickStepA, FIELD_G3D_MAP_CmdStartSpPokeGimmickStepB, FIELD_G3D_MAP_CmdFindEventMonInParty, FIELD_G3D_MAP_FindEventMonInParty, FIELD_G3D_MAP_CmdClearEventMonFlag
 * address:  0x0216B24C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SendValueNow  0x02176850  thumb  ov011
 *   INTRUDE_COMM_IsRecordReceived  0x02176870  thumb  ov011
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   func_0201210C  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   SYMBOL_MAP_GetSelectedCellTile  0x021665D0  thumb  ov010
 *   GAME_DATA_SetSymbolMapFlag  0x02012FA4  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb
 *   FLDMMDL_BLACT_IsReservePending  0x0219C630  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
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
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GIMMICK45_SecondarySwitchEventProc  0x021F39B8  thumb  ov045
 *   SP_POKE_GIMMICK_ShowAndPlay  0x021F3AA0  thumb  ov059
 *   SP_POKE_GIMMICK_StartWaitAnimeEnd 0x021F3B68 thumb ov059
 *   SP_POKE_GIMMICK_StartWaitAnimeProgress 0x021F3B40 thumb ov059
 *   func_02012934  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_0202F488  0x0202F488  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202F630  0x0202F630  thumb
 */
struct GameSystem;
struct GameData;
struct GameEvent;
struct SaveControl;
struct BeaconSave;
struct ScriptContext;
struct ScrCmdWork;
struct RTCDate;
struct RTCTime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct { int x, y, z; } FxVec3;

typedef struct { u32 year, month, day, week; } RTCDateFields;
typedef struct { u32 hour, minute, second; } RTCTimeFields;

/* Work of the intrude request event: the word to report into and the request. */
typedef struct {
    u16 *result;        /* 0x00 */
    u8 requestType;     /* 0x04 */
    u8 padding[3];
} IntrudeRequestWork;

/* Work of the symbol entry event (0x24 bytes). */
typedef struct {
    u16 *result;        /* 0x00 */
    u16 tileId;         /* 0x04 */
    u8 padding06[2];
    FxVec3 position;    /* 0x08 */
    u16 edge;           /* 0x14 */
    u8 cellId;          /* 0x16 */
    u8 padding17;
    u16 accepted;       /* 0x18 */
    u8 padding1A[2];
    u32 playSe;         /* 0x1C */
    u32 solo;           /* 0x20 */
} SymbolEntryWork;

extern void *func_020120F4(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(void *owner, void *parent, void *proc, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern void MI_CpuFill8(void *dest, int value, int size);
extern void *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void *func_02012138(const struct GameSystem *gameSystem);
extern u8 *INTRUDE_COMM_GetWorkIfRunning(void *gameComm);
extern int INTRUDE_COMM_SendValueNow(u8 *intrudeComm, u8 requestType);
extern u32 INTRUDE_COMM_IsRecordReceived(u8 *intrudeComm);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *gameComm, void *gameData);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void *FIELD_PLAYER_GetMmdl(void *player);
extern void *FLDMMDL_GetPosPtr(void *player);
extern void *FIELDMAP_GetMmdlSys(void *fieldMap);
extern void FLDMMDL_SysPauseMove(void *mmdlSys);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSystem, void *fieldMap, u32 a, u32 b);
extern int SYMBOL_MAP_GetSelectedCellTile(int gameSystem, int cellId);
extern void GAME_DATA_SetSymbolMapFlag(void *gameData, unsigned char cellId);
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *gameSystem, void *fieldMap, u32 tileId, void *position, u32 edge);
extern int FLDMMDL_BLACT_IsReservePending(void *mmdlSys);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSystem, void *fieldMap, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 *FLDMMDL_SysResumeMove(void *mmdlSys);
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
extern void FIELD_PLAYER_GetPos(void *player, FxVec3 *out);
extern void *GIMMICK45_SecondarySwitchEventProc(void *gameSystem, int fromPlayer, FxVec3 *from, FxVec3 *to, int height, int frames);
extern void SP_POKE_GIMMICK_ShowAndPlay(void *gameSystem, int mode, FxVec3 *position);
extern void *SP_POKE_GIMMICK_StartWaitAnimeEnd(void *gameSystem, u32 value);
extern void *SP_POKE_GIMMICK_StartWaitAnimeProgress(void *gameSystem, u32 value);
extern void *func_02012934(const struct GameData *gameData);
extern u32 POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern int func_0202F488(void *mon, int kind);
extern u32 func_02017E1C(void *mon, u32 paramId, u32 arg);
extern void func_0202F630(void *mon, u32 kind);
extern u8 sTallyCategoryEntryCount[];
extern u8 sTallyCategoryEntryIds[];
extern const u8 sMissionKind[];
extern const u8 sMissionTargetCount[];
extern const u8 sMissionTargetId0[], sMissionTargetId1[], sMissionTargetId2[];
extern const u8 sMissionGoal[];
extern const u8 sMissionTimeLimitHours[];

int FIELD_G3D_MAP_IntrudeRequestEventMain(struct GameEvent *event, int *state, IntrudeRequestWork *work);
void FIELD_G3D_MAP_GetEdgePosition(FxVec3 *src, int edge, FxVec3 *dst);
struct GameEvent *FIELD_G3D_MAP_CreateSymbolEntryEvent(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId);
int FIELD_G3D_MAP_SymbolEntryEventMain(struct GameEvent *event, u32 *state, SymbolEntryWork *work);
int FIELD_G3D_MAP_GetCurrentMissionStatus(void *saveControl, u16 *status);
int FIELD_G3D_MAP_GetMissionStatus(void *saveControl, int missionIndex, u16 *status);
u32 FIELD_G3D_MAP_GetTallyTotal(const u16 *tally, int id);
int FIELD_G3D_MAP_AreMissionTargetsAtGoal(const u16 *tally, int missionIndex);
int FIELD_G3D_MAP_IsMissionTimeUp(void *saveControl);
int FIELD_G3D_MAP_AreAllTargetValuesRecorded(void *saveControl);
int FIELD_G3D_MAP_AreMissionTargetsAtCap(const u16 *tally, int missionIndex);
u16 FIELD_G3D_MAP_GetMissionShortfall(void *saveControl);
u16 FIELD_G3D_MAP_GetMissionHoursLeft(void *saveControl);
int FIELD_G3D_MAP_GetMissionElapsedHours(void *saveControl);
int FIELD_G3D_MAP_GetMissionKind(int missionIndex);
int FIELD_G3D_MAP_GetMissionTargetCount(int missionIndex);
void FIELD_G3D_MAP_GetMissionTargetIds(int missionIndex, u8 *targetIds);
int FIELD_G3D_MAP_GetMissionGoal(int missionIndex);
int FIELD_G3D_MAP_GetMissionTimeLimitHours(int missionIndex);
int FIELD_G3D_MAP_FindEventMonInParty(void *party, int species, int move, int kind, u16 *outIndex);

/* Starts the intrude request event: sends requestType and reports 0 or 1 into *result. */
struct GameEvent *FIELD_G3D_MAP_CreateIntrudeRequestEvent(struct GameSystem *gameSystem, u16 *result, int requestType)
{
    struct GameEvent *event;
    IntrudeRequestWork *work;
    func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, FIELD_G3D_MAP_IntrudeRequestEventMain, 8);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 8);
    work->result = result;
    work->requestType = requestType;
    return event;
}

int FIELD_G3D_MAP_IntrudeRequestEventMain(struct GameEvent *event, int *state, IntrudeRequestWork *work)
{
    u8 *intrudeComm;
    u16 *result;

    intrudeComm = INTRUDE_COMM_GetWorkIfRunning(func_02012138(GAME_EVENT_GetGameSystem(event)));
    if (intrudeComm == 0) {
        result = work->result;
        if (result != 0)
            *result = 0;
        return 1;
    }
    switch (*state) {
    case 0:
        if (INTRUDE_COMM_SendValueNow(intrudeComm, work->requestType) == 1)
            (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_IsRecordReceived(intrudeComm) == 1)
            (*state)++;
        break;
    case 2:
        result = work->result;
        if (result != 0)
            *result = 1;
        return 1;
    }
    return 0;
}

/*
 * Copies a 12-byte position, then moves one component to the map border
 * named by edge 0-3 (edges 4-9 keep it as copied).
 */
void FIELD_G3D_MAP_GetEdgePosition(FxVec3 *src, int edge, FxVec3 *dst)
{
    *dst = *src;
    switch (edge) {
    case 0:
        dst->z = 0x62 << 14;
        break;
    case 1:
        dst->z = 0x26 << 14;
        break;
    case 2:
        dst->x = 0x6A << 14;
        break;
    case 3:
        dst->x = 0x16 << 14;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}

struct GameEvent *FIELD_G3D_MAP_CreateSymbolEntryEvent(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId)
{
    void *gameData;
    struct GameEvent *event;
    SymbolEntryWork *work;

    gameData = func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, FIELD_G3D_MAP_SymbolEntryEventMain, 0x24);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 0x24);
    work->position = *position;
    work->edge = edge;
    work->result = 0;
    work->cellId = cellId;
    work->playSe = playSe;
    if (INTRUDE_COMM_GetPartnerSlot(func_02012138(gameSystem), gameData) == 4)
        work->solo = 1;
    return event;
}

struct GameEvent *FIELD_G3D_MAP_StartSymbolEntry(struct GameSystem *gameSystem, int edge, int cellId)
{
    FxVec3 position;
    void *fieldMap;

    fieldMap = func_0201210C(gameSystem);
    func_020120F4(gameSystem);
    FIELD_G3D_MAP_GetEdgePosition(FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap))), edge, &position);
    return FIELD_G3D_MAP_CreateSymbolEntryEvent(gameSystem, edge != 9, &position, edge, cellId);
}

/*
 * Seven-state proc of the symbol entry: ask the intrude partner (unless
 * playing solo), fade out, show the symbol cell's tile, fade back in, and
 * write 0 or 1 to the caller's result word.
 */
int FIELD_G3D_MAP_SymbolEntryEventMain(struct GameEvent *event, u32 *state, SymbolEntryWork *work)
{
    void *gameSystem = GAME_EVENT_GetGameSystem(event);
    void *gameData;
    void *fieldMap;

    func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        if (work->solo == 1) {
            *state = 2;
        } else {
            GAME_EVENT_CallEvent(event, FIELD_G3D_MAP_CreateIntrudeRequestEvent(gameSystem, &work->accepted, work->cellId));
            (*state)++;
        }
        break;
    case 1:
        if (work->accepted == 0) {
            if (work->result != 0)
                *work->result = 0;
            *state = 6;
        } else {
            (*state)++;
        }
        break;
    case 2:
        if (work->playSe != 0)
            GFL_USE_PlaySeDefaultVolume(1369);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 9, 0));
        (*state)++;
        break;
    case 3:
        work->tileId = SYMBOL_MAP_GetSelectedCellTile((int)gameSystem, work->cellId);
        GAME_DATA_SetSymbolMapFlag(gameData, work->cellId);
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(gameSystem, fieldMap, work->tileId, &work->position, work->edge));
        (*state)++;
        break;
    case 4:
        if (FLDMMDL_BLACT_IsReservePending(FIELDMAP_GetMmdlSys(func_0201210C(gameSystem))) == 1)
            break;
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 9, 0, 0, 0, 0));
        (*state)++;
        break;
    case 5:
        if (work->result != 0)
            *work->result = 1;
        *state = 6;
        break;
    case 6:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        return 1;
    }
    return 0;
}

/* Script command: writes the research team rank to a work variable. */
int FIELD_G3D_MAP_CmdGetResearchRank(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdRaiseResearchRank(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdGetMissionIndex(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdGetMissionTargets(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdGetMissionElapsedHours(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    struct GameData *gameData;
    void *saveControl;
    u16 *dst;

    SCRCMD_WORK_GetScriptWork(scrWork);
    gameData = SCRCMD_WORK_GetGameData(scrWork);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    *dst = FIELD_G3D_MAP_GetMissionElapsedHours(saveControl);
    return 0;
}

/* Script command: starts a mission (index and three target ids), zeroes the progress and stamps the time. */
int FIELD_G3D_MAP_CmdStartMission(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdClearMission(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdGetTopTallyEntry(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdSetSurveyAnswer(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdStartResearchReport(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
int FIELD_G3D_MAP_CmdGetMissionStatus(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
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
        FIELD_G3D_MAP_GetCurrentMissionStatus(saveControl, dst);
    } else {
        FIELD_G3D_MAP_GetMissionStatus(saveControl, missionIndex, dst);
    }
    return 0;
}

/* Script command: writes the progress of the current mission (shortfall or hours left, by kind). */
int FIELD_G3D_MAP_CmdGetMissionProgress(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    u16 *dst;
    void *saveControl;
    void *beacon;
    int progress;
    u8 kind;

    saveControl = GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(scrWork));
    beacon = func_0200C0E8(saveControl);
    dst = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    kind = FIELD_G3D_MAP_GetMissionKind(func_0200C32C(beacon));
    if (kind != 0) {
        if (kind == 1) {
            progress = FIELD_G3D_MAP_GetMissionHoursLeft(saveControl);
        }
    } else {
        progress = FIELD_G3D_MAP_GetMissionShortfall(saveControl);
    }
    *dst = progress;
    return 0;
}

/* Status of the current mission: 1 done, 2 not yet (kind 0), 3 running, 4 failed (kind 1). */
int FIELD_G3D_MAP_GetCurrentMissionStatus(void *saveControl, u16 *status)
{
    const u16 *tally;
    void *beacon;
    int missionIndex;
    int kind;

    tally = func_0200E394(saveControl);
    beacon = func_0200C0E8(saveControl);
    missionIndex = func_0200C32C(beacon);
    kind = (u8)FIELD_G3D_MAP_GetMissionKind(missionIndex);
    if (kind == 0) {
        if (FIELD_G3D_MAP_AreMissionTargetsAtGoal(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 2;
        return 2;
    }
    if (kind == 1) {
        if (FIELD_G3D_MAP_IsMissionTimeUp(saveControl) != 0) {
            if (FIELD_G3D_MAP_AreAllTargetValuesRecorded(saveControl) != 0) {
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
int FIELD_G3D_MAP_GetMissionStatus(void *saveControl, int missionIndex, u16 *status)
{
    const u16 *tally;
    int kind;

    tally = func_0200E394(saveControl);
    func_0200C0E8(saveControl);
    kind = (u8)FIELD_G3D_MAP_GetMissionKind(missionIndex);
    if (kind == 0) {
        if (FIELD_G3D_MAP_AreMissionTargetsAtGoal(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 2;
        return 2;
    }
    if (kind == 1) {
        if (FIELD_G3D_MAP_AreMissionTargetsAtCap(tally, missionIndex) != 0) {
            *status = 1;
            return 1;
        }
        *status = 3;
        return 3;
    }
    return kind;
}

/* Tally of an id: both counters summed, capped at 999999. */
u32 FIELD_G3D_MAP_GetTallyTotal(const u16 *tally, int id)
{
    u32 total = func_0200E458(tally, id);
    total += func_0200E47C((u8 *)tally, id);
    if (total > 999999) total = 999999;
    return total;
}

/* 1 when every target of the mission reached its goal. */
int FIELD_G3D_MAP_AreMissionTargetsAtGoal(const u16 *tally, int missionIndex)
{
    int i;
    u8 targetId[4];
    int targetCount;
    u32 goal;

    FIELD_G3D_MAP_GetMissionTargetIds(missionIndex, targetId);
    targetCount = (u8)FIELD_G3D_MAP_GetMissionTargetCount(missionIndex);
    goal = FIELD_G3D_MAP_GetMissionGoal(missionIndex);
    for (i = 0; i < targetCount; i++) {
        if (FIELD_G3D_MAP_GetTallyTotal(tally, targetId[i]) < goal) {
            return 0;
        }
    }
    return 1;
}

/* 1 when the time limit of the current mission is used up. */
int FIELD_G3D_MAP_IsMissionTimeUp(void *saveControl)
{
    int missionIndex;
    int elapsedHours;
    void *beacon;

    func_0200E394(saveControl);
    beacon = func_0200C0E8(saveControl);
    missionIndex = func_0200C32C(beacon);
    elapsedHours = FIELD_G3D_MAP_GetMissionElapsedHours(saveControl);
    if (FIELD_G3D_MAP_GetMissionTimeLimitHours((u8)missionIndex) > elapsedHours)
        return 0;
    return 1;
}

/* 1 when every target slot of the current mission holds a recorded value. */
int FIELD_G3D_MAP_AreAllTargetValuesRecorded(void *saveControl)
{
    void *beacon;
    int i, targetCount;
    beacon = func_0200C0E8(saveControl);
    targetCount = (u8)FIELD_G3D_MAP_GetMissionTargetCount(func_0200C32C(beacon));
    for (i = 0; i < targetCount; i++) {
        if (func_0200C34C(beacon, (u8)i) == 0) return 0;
    }
    return 1;
}

/* 1 when every target of the mission is at the cap of 999999. */
int FIELD_G3D_MAP_AreMissionTargetsAtCap(const u16 *tally, int missionIndex)
{
    int i;
    u8 targetId[4];
    int targetCount;

    FIELD_G3D_MAP_GetMissionTargetIds(missionIndex, targetId);
    targetCount = (u8)FIELD_G3D_MAP_GetMissionTargetCount(missionIndex);
    FIELD_G3D_MAP_GetMissionGoal(missionIndex);
    for (i = 0; i < targetCount; i++) {
        if (FIELD_G3D_MAP_GetTallyTotal(tally, targetId[i]) < 999999) {
            return 0;
        }
    }
    return 1;
}

/* Goal minus the smallest target tally of the current mission. */
u16 FIELD_G3D_MAP_GetMissionShortfall(void *saveControl)
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
    goal = FIELD_G3D_MAP_GetMissionGoal(missionIndex);
    targetCount = (u8)FIELD_G3D_MAP_GetMissionTargetCount(missionIndex);
    FIELD_G3D_MAP_GetMissionTargetIds(missionIndex, targetId);
    smallest = 1009998;
    for (i = 0; i < targetCount; i++) {
        u32 value = FIELD_G3D_MAP_GetTallyTotal(tally, targetId[i]);
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
 * FIELD_G3D_MAP_GetMissionElapsedHours forwards entry r0 to 0200C0F0; preserve that input.
 */
u16 FIELD_G3D_MAP_GetMissionHoursLeft(void *saveControl)
{
    int missionIndex, elapsedHours, hoursLeft;
    func_0200E394(saveControl);
    missionIndex = func_0200C32C(func_0200C0E8(saveControl));
    elapsedHours = FIELD_G3D_MAP_GetMissionElapsedHours(saveControl);
    hoursLeft = (int)((u32)FIELD_G3D_MAP_GetMissionTimeLimitHours((u8)missionIndex) - (u32)elapsedHours);
    if (hoursLeft < 0) hoursLeft = 0;
    return (u16)hoursLeft;
}

/* Hours since the mission started, 24 when a day or more passed, 0 when no mission runs. */
int FIELD_G3D_MAP_GetMissionElapsedHours(void *saveControl)
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
int FIELD_G3D_MAP_GetMissionKind(int missionIndex)
{
    return *(const u8 *)((u32)sMissionKind + (u32)missionIndex * 7u);
}

int FIELD_G3D_MAP_GetMissionTargetCount(int missionIndex)
{
    return *(const u8 *)((u32)sMissionTargetCount + (u32)missionIndex * 7u);
}

/*
 * arithmetic: unsigned 32-bit address/stride arithmetic preserves original
 * MUL/ADD wrapping; each byte load remains ordered before its output store.
 */
void FIELD_G3D_MAP_GetMissionTargetIds(int missionIndex, u8 *targetIds)
{
    targetIds[0] = *(const u8 *)((u32)sMissionTargetId0 + (u32)missionIndex * 7u);
    targetIds[1] = *(const u8 *)((u32)sMissionTargetId1 + (u32)missionIndex * 7u);
    targetIds[2] = *(const u8 *)((u32)sMissionTargetId2 + (u32)missionIndex * 7u);
}

int FIELD_G3D_MAP_GetMissionGoal(int missionIndex)
{
    return *(const u8 *)((u32)sMissionGoal + (u32)missionIndex * 7u);
}

int FIELD_G3D_MAP_GetMissionTimeLimitHours(int missionIndex)
{
    return *(const u8 *)((u32)sMissionTimeLimitHours + (u32)missionIndex * 7u);
}

/* Script command: starts a special Pokemon gimmick task between the player and a grid position. */
int FIELD_G3D_MAP_CmdStartSpPokeGimmickTask(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem;
    void *gameSystem;
    void *fieldMap;
    int fromPlayer;
    int gridX;
    int height;
    int gridZ;
    int speed;
    int frames;
    FxVec3 playerPos;
    FxVec3 targetPos;
    FxVec3 *from;
    FxVec3 *to;
    void *gimmickTask;

    scriptSystem = SCRCMD_WORK_GetScriptWork(scrWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    fieldMap = func_0201210C(gameSystem);
    fromPlayer = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridX = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    height = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    speed = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    frames = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &playerPos);
    targetPos.x = (gridX << 16) + 0x8000;
    targetPos.y = height << 15;
    targetPos.z = (gridZ << 16) + 0x8000;
    if (fromPlayer == 0) {
        from = &playerPos;
        to = &targetPos;
    } else {
        from = &targetPos;
        to = &playerPos;
    }
    gimmickTask = GIMMICK45_SecondarySwitchEventProc(gameSystem, fromPlayer, from, to, speed << 15, frames);
    if (gimmickTask == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptSystem, gimmickTask);
    return 1;
}

/* Script command: moves the special Pokemon gimmick to a grid position. */
int FIELD_G3D_MAP_CmdMoveSpPokeGimmick(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *gameSystem;
    int mode;
    int gridX;
    int height;
    int gridZ;
    FxVec3 position;

    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    mode = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridX = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    height = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    position.x = (gridX << 16) + 0x8000;
    position.y = height << 15;
    position.z = (gridZ << 16) + 0x8000;
    SP_POKE_GIMMICK_ShowAndPlay(gameSystem, mode, &position);
    return 0;
}

/* Script command: starts the first special Pokemon gimmick step task and waits on it. */
int FIELD_G3D_MAP_CmdStartSpPokeGimmickStepA(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem, *gameSystem, *task;
    scriptSystem = SCRCMD_WORK_GetScriptWork(scrWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    task = SP_POKE_GIMMICK_StartWaitAnimeEnd(gameSystem, SCRIPT_WORK_ReadWorkValue(ctx, scrWork));
    if (task == 0) return 1;
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/* Script command: starts the second special Pokemon gimmick step task and waits on it. */
int FIELD_G3D_MAP_CmdStartSpPokeGimmickStepB(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *scriptSystem, *gameSystem, *task;
    scriptSystem = SCRCMD_WORK_GetScriptWork(scrWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scrWork);
    task = SP_POKE_GIMMICK_StartWaitAnimeProgress(gameSystem, SCRIPT_WORK_ReadWorkValue(ctx, scrWork));
    if (task == 0) return 1;
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/*
 * Script command: reads a species, a signature-move flag and two result
 * variables, maps the event species (243-245, 251, 492, 647-649) to a flag
 * kind and, for 647/648, a signature move (548/547, dropped when the flag
 * is 0), and stores FIELD_G3D_MAP_FindEventMonInParty's answer in the second variable; any other
 * species stores 0.
 */
int FIELD_G3D_MAP_CmdFindEventMonInParty(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *party = func_02012934(SCRCMD_WORK_GetGameData(scrWork));
    int species = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    unsigned int useSignatureMove = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    u16 *outIndex = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    u16 *outFound = SCRIPT_WORK_ReadWorkPointer(ctx, scrWork);
    int kind;
    int move;

    switch (species) {
    case 647:
        kind = 4;
        move = 548;
        break;
    case 648:
        kind = 5;
        move = 547;
        break;
    case 251:
        kind = 0;
        move = 0;
        break;
    case 243:
    case 244:
    case 245:
        kind = 2;
        move = 0;
        break;
    case 649:
        kind = 6;
        move = 0;
        break;
    case 492:
        kind = 7;
        move = 0;
        break;
    default:
        *outFound = 0;
        return 0;
    }
    if (useSignatureMove == 0) {
        move = 0;
    }
    *outFound = FIELD_G3D_MAP_FindEventMonInParty(party, species, move, kind, outIndex);
    return 0;
}

/* Finds the first party member of the species that has the event flag and does not know the move. */
int FIELD_G3D_MAP_FindEventMonInParty(void *party, int species, int move, int kind, u16 *outIndex)
{
    int found;
    int count;
    int i;
    void *mon;

    count = POKEPARTY_GetCount(party);
    found = 0;
    *outIndex = 0;
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (func_0202F488(mon, kind) == 0) {
            continue;
        }
        if (species != func_02017E1C(mon, 5, 0)) {
            continue;
        }
        if (move != 0) {
            if (move == func_02017E1C(mon, 0x36, 0)
                || move == func_02017E1C(mon, 0x37, 0)
                || move == func_02017E1C(mon, 0x38, 0)
                || move == func_02017E1C(mon, 0x39, 0)) {
                continue;
            }
        }
        found = 1;
        *outIndex = i;
        break;
    }
    return found;
}

/* Script command: clears the event flag of the party member at an index when its species has one. */
int FIELD_G3D_MAP_CmdClearEventMonFlag(struct ScriptContext *ctx, struct ScrCmdWork *scrWork)
{
    void *party;
    int species;
    int partyIndex;
    int kind;
    void *mon;

    party = func_02012934(SCRCMD_WORK_GetGameData(scrWork));
    species = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    partyIndex = SCRIPT_WORK_ReadWorkValue(ctx, scrWork);
    switch (species) {
    case 0xFB:
        kind = 0;
        break;
    case 0xF3:
    case 0xF4:
    case 0xF5:
        kind = 2;
        break;
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    default:
        return 0;
    }
    mon = POKEPARTY_GetMember(party, partyIndex);
    if (func_0202F488(mon, kind) == 0) {
        return 0;
    }
    func_0202F630(mon, kind);
    return 0;
}
