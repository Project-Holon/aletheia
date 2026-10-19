/*
 * file:     event_comm_error.c
 * unit:     yes
 * function: EVENT_COMM_ERROR_Create, EVENT_COMM_ERROR_Run, EVENT_COMM_ERROR_RunCommExit, EVENT_COMM_ERROR_SubProcInit, EVENT_COMM_ERROR_SubProcMain, EVENT_COMM_ERROR_SubProcEnd
 * address:  0x021C06CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): cut from event_comm_error_recovery.c at 021C0820. The EVENT_COMM_ERROR_ run (comm error and comm exit events, sub process handlers; called by field_event_check.c and ov018) is a separate module from the EVENT_RECOVERY_ ball and party healing events (called by scrcmd_screeneffects.c). No __FILE__ anchor, no shared statics; the cut rests on module prefix and the different callers.
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   sCommErrorSubProcData  0x021DA08C  data
 *   ov021_id  0x00000015  data
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_COMM_GetLastKind  0x0202647C  thumb
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_NET_ERR_ResetState  0x0200FBA0  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_BEACON_SEARCH_SetStartDelay  0x02164FC4  thumb  ov010
 */
#include "fieldmap_types.h"
#include "event_comm_error_shared_types.h"

struct GameComm;

/* The functions of a sub proc (init, main, end), as the proc runner calls them. */
typedef int (*SubProcFunc)(void *proc, int *seq, void *procWork, void *myWork);

typedef struct SubProcData {
    SubProcFunc init;       /* 0x00 */
    SubProcFunc main;       /* 0x04 */
    SubProcFunc end;        /* 0x08 */
} SubProcData;

/* Steps of the comm error event. */
enum {
    COMM_ERROR_STEP_START,
    COMM_ERROR_STEP_WAIT
};

/* Steps of the comm shutdown event. */
enum {
    COMM_EXIT_STEP_EXIT,
    COMM_EXIT_STEP_WAIT_SESSION_END,
    COMM_EXIT_STEP_AUTO_COMM,
    COMM_EXIT_STEP_SET_SEARCH_DELAY
};

extern GameEvent *GAME_EVENT_Create(GameSystem *gameSystem, GameEvent *parent, GameEventFunc handler, u32 workSize);

extern GameSystem *GAME_EVENT_GetGameSystem(GameEvent *event);

extern FieldMap *GAMESYSTEM_GetFieldMap(GameSystem *gameSystem);

extern struct GameComm *GAMESYSTEM_GetGameComm(GameSystem *gameSystem);

extern struct GameData *GAMESYSTEM_GetGameData(GameSystem *gameSystem);

extern void GAMESYSTEM_SetFieldMapState(GameSystem *gameSystem, u32 state);

extern u32 GAMESYSTEM_TryStartAutoComm(GameSystem *gameSystem);

extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);

extern int GAME_DATA_GetIntrudeCount(struct GameData *gameData);

extern u32 GAME_COMM_GetLastKind(struct GameComm *gameComm);

extern void *GAME_COMM_GetWork(struct GameComm *gameComm);

extern u32 GAME_COMM_GetKind(struct GameComm *gameComm);

extern int GFL_NET_GetRunState(void);

extern int GFL_NET_Exit(int a0);

extern int GFL_NET_IsSessionNull(void);

extern void GFL_NET_ERR_RequestScreen(void);

extern void GFL_NET_ERR_ResetState(void);

extern GameEvent *FIELD_STATUS_CreateSubProcEvent(GameSystem *gameSystem, FieldMap *fieldMap, u8 *overlayId, const SubProcData *procData, GameSystem *procWork);

extern void GAME_BEACON_SEARCH_SetStartDelay(void *searchWork);

extern struct MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);

extern int FIELDMAP_IsReady(FieldMap *fieldMap);

extern void FLDMMDL_SysPauseMove(struct MmdlSys *mmdlSys);

extern u32 *FLDMMDL_SysResumeMove(struct MmdlSys *mmdlSys);

extern u8 ov021_id[];

extern const SubProcData sCommErrorSubProcData;

GameEvent *EVENT_COMM_ERROR_Create(GameSystem *gameSystem, FieldMap *fieldMap);

int EVENT_COMM_ERROR_Run(GameEvent *event, int *seq, void *work);

int EVENT_COMM_ERROR_RunCommExit(GameEvent *event, int *seq, void *work);

int EVENT_COMM_ERROR_SubProcInit(void *proc, int *seq, void *procWork, void *myWork);

int EVENT_COMM_ERROR_SubProcMain(void *proc, int *seq, void *procWork, void *myWork);

int EVENT_COMM_ERROR_SubProcEnd(void *proc, int *seq, void *procWork, void *myWork);

/*
 * Starts the comm error event.
 */
GameEvent *EVENT_COMM_ERROR_Create(GameSystem *gameSystem, FieldMap *fieldMap)
{
    return GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_ERROR_Run, 0);
}

/*
 * Comm error event: pauses the move models, shows the error through the
 * sub proc (or shuts the comm down when the comm is not in the intrude
 * state), and resumes the move models when the field map is ready again.
 */
int EVENT_COMM_ERROR_Run(GameEvent *event, int *seq, void *work)
{
    GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GameEvent *child;

    switch (*seq) {
    case COMM_ERROR_STEP_START:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        if (GAME_COMM_GetLastKind(GAMESYSTEM_GetGameComm(gameSystem)) == 2) {
            if (GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(gameSystem)) == 1) {
                GFL_NET_ERR_RequestScreen();
                child = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, ov021_id, &sCommErrorSubProcData, gameSystem);
            } else {
                child = GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_ERROR_RunCommExit, 0);
            }
        } else {
            GFL_NET_ERR_RequestScreen();
            child = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, ov021_id, &sCommErrorSubProcData, gameSystem);
        }
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case COMM_ERROR_STEP_WAIT:
        if (fieldMap != 0 && FIELDMAP_IsReady(fieldMap) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
            return EVENT_FINISHED;
        }
        break;
    }
    return EVENT_CONTINUE;
}

/*
 * Comm shutdown event: leaves the comm session, resets the field map state,
 * restarts the automatic comm and sets the beacon search delay.
 */
int EVENT_COMM_ERROR_RunCommExit(GameEvent *event, int *seq, void *work)
{
    GameSystem *gameSystem;
    struct GameComm *gameComm;
    void *searchWork;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    switch (*seq) {
    case COMM_EXIT_STEP_EXIT:
        if (GFL_NET_GetRunState()) {
            GFL_NET_Exit(0);
        }
        *seq = *seq + 1;
        break;
    case COMM_EXIT_STEP_WAIT_SESSION_END:
        if (GFL_NET_IsSessionNull() == 1) {
            GFL_NET_ERR_ResetState();
            GAMESYSTEM_SetFieldMapState(gameSystem, 0);
            *seq = *seq + 1;
        }
        break;
    case COMM_EXIT_STEP_AUTO_COMM:
        if (GAMESYSTEM_TryStartAutoComm(gameSystem) == 1) {
            *seq = *seq + 1;
            break;
        }
        return EVENT_FINISHED;
    case COMM_EXIT_STEP_SET_SEARCH_DELAY:
        searchWork = GAME_COMM_GetWork(gameComm);
        if (searchWork && GAME_COMM_GetKind(gameComm)) {
            GAME_BEACON_SEARCH_SetStartDelay(searchWork);
            return EVENT_FINISHED;
        }
        break;
    }
    return EVENT_CONTINUE;
}

/*
 * Init function of the comm error sub proc: nothing to set up.
 */
int EVENT_COMM_ERROR_SubProcInit(void *proc, int *seq, void *procWork, void *myWork)
{
    return 1;
}

/*
 * Main function of the comm error sub proc: ends at once.
 */
int EVENT_COMM_ERROR_SubProcMain(void *proc, int *seq, void *procWork, void *myWork)
{
    return 1;
}

/*
 * End function of the comm error sub proc: resets the field map state of the
 * game system it was started with.
 */
int EVENT_COMM_ERROR_SubProcEnd(void *proc, int *seq, void *procWork, void *myWork)
{
    GAMESYSTEM_SetFieldMapState(procWork, 0);
    return 1;
}
