/*
 * file:     event_gameclear.c
 * unit:     yes
 * function: EVENT_GAMECLEAR_Main, EVENT_GAMECLEAR_Create, EVENT_GAMECLEAR_InitHallOfFameParam, EVENT_GAMECLEAR_InitStaffRollParam, EVENT_GAMECLEAR_InitStepSequence, EVENT_GAMECLEAR_GetCommExitKind, EVENT_GAMECLEAR_AdvanceStep, EVENT_GAMECLEAR_SetGatePoints
 * address:  0x0215F734
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_network.c by tools/splitfile.py.
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_CreateCommExitEvent  0x02161B90  thumb  ov010
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent  0x02014554  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   SCRIPT_SYS_RunRecoverScript  0x02158A20  thumb  ov010
 *   ov180_id       0x000000B4  data
 *   ov181_id       0x000000B5  data
 *   ov205_id       0x000000CD  data
 *   ov182_id       0x000000B6  data
 *   d_021B800C     0x021B800C  data  ov180
 *   d_021BAB24     0x021BAB24  data  ov181
 *   d_021B9E54     0x021B9E54  data  ov205
 *   d_021B9BA0     0x021B9BA0  data  ov182
 *   MOVE_POKEMON_SpawnPendingEntries  0x0215E580  thumb  ov010
 *   GAME_DATA_GetMyParty   0x02012934  thumb
 *   GAME_DATA_GetPlayTime   0x02012FCC  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   CONFIG_GetTextLanguage  0x020083E4  thumb
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_SetGatePoints  0x0200C3B8  thumb
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_network_shared_types.h"
#include "event_gameclear_shared_types.h"

struct PokeParty;

struct Config;

struct MiscSave;

/* Parameter blocks that the game clear event passes to its screens (Hall of Fame, staff roll, The End, save screen). */
typedef struct GameClearSaveScreenParam {
    struct GameSystem *gameSystem;  /* 0x00 */
    u32 mode;                       /* 0x04 */
} GameClearSaveScreenParam;

typedef struct GameClearHallOfFameParam {
    struct PokeParty *myParty;      /* 0x00 */
    struct MyStatus *myStatus;      /* 0x04 */
    u32 playTime;                   /* 0x08 */
} GameClearHallOfFameParam;

typedef struct GameClearStaffRollParam {
    u32 isMode1;                    /* 0x00 */
    u32 configApplied;              /* 0x04 */
} GameClearStaffRollParam;

/* Steps of the game clear event; the order comes from the sequence table. */
enum {
    GAME_CLEAR_STEP_PREPARE,
    GAME_CLEAR_STEP_FIELD_PREPARE_EVENT,
    GAME_CLEAR_STEP_REQUEST_COMM_IDLE,
    GAME_CLEAR_STEP_WAIT_COMM_IDLE,
    GAME_CLEAR_STEP_CLOSE_FIELD,
    GAME_CLEAR_STEP_CALL_HALL_OF_FAME,
    GAME_CLEAR_STEP_WAIT_HALL_OF_FAME,
    GAME_CLEAR_STEP_CALL_STAFF_ROLL,
    GAME_CLEAR_STEP_WAIT_STAFF_ROLL,
    GAME_CLEAR_STEP_COMM_EXIT_EVENT,
    GAME_CLEAR_STEP_SET_SCRIPT_STATE,
    GAME_CLEAR_STEP_CALL_SAVE_SCREEN,
    GAME_CLEAR_STEP_WAIT_FRAMES,
    GAME_CLEAR_STEP_CALL_THE_END,
    GAME_CLEAR_STEP_DONE,
    GAME_CLEAR_STEP_ABORT
};

/* Work of the game clear event (0x7C bytes). */
typedef struct GameClearWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameData *gameData;      /* 0x04 */
    u32 mode;                       /* 0x08: 1 selects the second step sequence */
    u8 pad0C[4];
    struct MyStatus *myStatus;      /* 0x10 */
    GameClearSaveScreenParam saveScreenParam;/* 0x14 */
    GameClearHallOfFameParam hallOfFameParam;/* 0x1C */
    GameClearStaffRollParam staffRollParam;/* 0x28 */
    u32 theEndParam;                 /* 0x30: configApplied again */
    u32 step;                       /* 0x34: seq[current index] */
    u32 seq[16];                    /* 0x38 */
    int frameCount;                 /* 0x78 */
} GameClearWork;

#include "script_sys.h"
struct GameEvent;

/* game system, game event, game data */
#include "../arm9/game_event.h"




#include "../arm9/gamesystem.h"






#include "../arm9/game_data.h"


struct PlayTime;



/* game comm, config, misc */
#include "../arm9/game_comm.h"


#include "../arm9/system_data.h"

#include "../arm9/config.h"

#include "../arm9/beacon.h"

#include "../arm9/gpower.h"

#include "../arm9/gfl_use.h"

/* field events and field */
#include "../ov021/event_fieldmap_control.h"

#include "../arm9/field_status.h"

#include "event_field_proclink.h"

#include "move_pokemon.h"

extern u8 ov180_id[];

extern u8 ov181_id[];

extern u8 ov205_id[];

extern u8 ov182_id[];

extern u8 d_021B800C[];

extern u8 d_021BAB24[];

extern u8 d_021B9E54[];

extern u8 d_021B9BA0[];

int EVENT_GAMECLEAR_Main(struct GameEvent *event, u32 *seq, void *workArg);

struct GameEvent *EVENT_GAMECLEAR_Create(struct GameSystem *gameSystem, int mode);

void EVENT_GAMECLEAR_InitHallOfFameParam(GameClearWork *work);

int EVENT_GAMECLEAR_InitStaffRollParam(GameClearWork *work);

void EVENT_GAMECLEAR_InitStepSequence(GameClearWork *work);

int EVENT_GAMECLEAR_GetCommExitKind(void);

void EVENT_GAMECLEAR_AdvanceStep(GameClearWork *work, u32 *seq);

void EVENT_GAMECLEAR_SetGatePoints(GameClearWork *work);

/*
 * Step machine of the game clear event (Hall of Fame, staff roll, save, The End): the step comes from work->seq[*seq]
 * through EVENT_GAMECLEAR_AdvanceStep, loading ov180/ov181 as procs and ov205/ov182 as
 * tasks. Byte-correct first draft.
 * Former blocker (MATCH): ov205_id and ov182_id reach r1 of GAME_EVENT_CallProc, which
 * is not in match.py's OVERLAY_ID_CONSUMERS; d_021B9BA0 then fails its
 * ov182 hint for want of that overlay_id site. Same blocker as
 * EVENT_WIFI_PROC_EventMain.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int EVENT_GAMECLEAR_Main(struct GameEvent *event, u32 *seq, void *workArg)
{
    GameClearWork *work = workArg;
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameComm *gameComm;
    struct FieldMap *fieldMap;

    GAME_DATA_GetSaveControl(work->gameData);
    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSystem);
    gameComm = GAMESYSTEM_GetGameComm(work->gameSystem);
    switch (work->step) {
    case GAME_CLEAR_STEP_PREPARE:
        if (work->mode == 1)
            EVENT_GAMECLEAR_SetGatePoints(work);
        GFL_USE_FadeOutBgm(30);
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_FIELD_PREPARE_EVENT:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_REQUEST_COMM_IDLE:
        if (GAME_COMM_GetKind(gameComm))
            GAME_COMM_RequestExitNoCallback(gameComm);
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_WAIT_COMM_IDLE:
        if (GAME_COMM_GetKind(gameComm) == 0)
            EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_CLOSE_FIELD:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(gameSystem, fieldMap));
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_CALL_HALL_OF_FAME:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov180_id, d_021B800C, &work->hallOfFameParam);
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_WAIT_HALL_OF_FAME:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_CALL_STAFF_ROLL:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov181_id, d_021BAB24, &work->staffRollParam);
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_WAIT_STAFF_ROLL:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_COMM_EXIT_EVENT:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateCommExitEvent(gameSystem, event, EVENT_GAMECLEAR_GetCommExitKind(), 0, 0));
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_SET_SCRIPT_STATE:
        SCRIPT_SYS_RunRecoverScript(gameSystem, 4);
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_CALL_SAVE_SCREEN:
        GAME_EVENT_CallProc(event, (uptr)ov205_id, d_021B9E54, &work->saveScreenParam);
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_WAIT_FRAMES:
        if (work->frameCount > 60) {
            work->frameCount = 0;
            EVENT_GAMECLEAR_AdvanceStep(work, seq);
        }
        work->frameCount++;
        break;
    case GAME_CLEAR_STEP_CALL_THE_END:
        GAME_EVENT_CallProc(event, (uptr)ov182_id, d_021B9BA0, &work->theEndParam);
        GAMESYSTEM_SetAlwaysNetFlag(gameSystem, 0);
        EVENT_GAMECLEAR_AdvanceStep(work, seq);
        break;
    case GAME_CLEAR_STEP_DONE:
        return 1;
    case GAME_CLEAR_STEP_ABORT:
        return 0;
    }
    return 0;
}

struct GameEvent *EVENT_GAMECLEAR_Create(struct GameSystem *gameSystem, int mode)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_GAMECLEAR_Main, 0x7C);
    GameClearWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->gameData = gameData;
    work->mode = mode;
    work->myStatus = GAME_DATA_GetMyStatus(gameData);
    work->frameCount = 0;
    work->saveScreenParam.gameSystem = gameSystem;
    work->saveScreenParam.mode = mode;
    MOVE_POKEMON_SpawnPendingEntries(gameData);
    EVENT_GAMECLEAR_InitHallOfFameParam(work);
    EVENT_GAMECLEAR_InitStaffRollParam(work);
    EVENT_GAMECLEAR_InitStepSequence(work);
    return event;
}

/* Caches the party, status and play time of the game data for the Hall of Fame screen. */
void EVENT_GAMECLEAR_InitHallOfFameParam(GameClearWork *work)
{
    work->hallOfFameParam.myParty = GAME_DATA_GetMyParty(work->gameData);
    work->hallOfFameParam.myStatus = GAME_DATA_GetMyStatus(work->gameData);
    work->hallOfFameParam.playTime = (uptr)GAME_DATA_GetPlayTime(work->gameData);
}

/* Fills the staff roll and The End parameters from the config applied flag. */
int EVENT_GAMECLEAR_InitStaffRollParam(GameClearWork *work)
{
    struct SaveControl *saveControl;
    struct Config *config;
    int configApplied;

    if (work->mode == 1)
        work->staffRollParam.isMode1 = 1;
    else
        work->staffRollParam.isMode1 = 0;
    saveControl = GAME_DATA_GetSaveControl(work->gameData);
    config = SYSTEM_DATA_GetConfig(saveControl);
    configApplied = CONFIG_GetTextLanguage(config);
    work->staffRollParam.configApplied = configApplied;
    work->theEndParam = configApplied;
    return configApplied;
}

/*
 * Picks the step sequence from the mode and loads its first step.
 * Addresses are Black-image addresses.
 */
void EVENT_GAMECLEAR_InitStepSequence(GameClearWork *work)
{
    if (work->mode == 0 || work->mode != 1) {
        work->seq[0] = GAME_CLEAR_STEP_PREPARE;
        work->seq[1] = GAME_CLEAR_STEP_REQUEST_COMM_IDLE;
        work->seq[2] = GAME_CLEAR_STEP_WAIT_COMM_IDLE;
        work->seq[3] = GAME_CLEAR_STEP_CLOSE_FIELD;
        work->seq[4] = GAME_CLEAR_STEP_CALL_STAFF_ROLL;
        work->seq[5] = GAME_CLEAR_STEP_WAIT_STAFF_ROLL;
        work->seq[6] = GAME_CLEAR_STEP_WAIT_FRAMES;
        work->seq[7] = GAME_CLEAR_STEP_COMM_EXIT_EVENT;
        work->seq[8] = GAME_CLEAR_STEP_WAIT_FRAMES;
        work->seq[9] = GAME_CLEAR_STEP_SET_SCRIPT_STATE;
        work->seq[10] = GAME_CLEAR_STEP_CALL_SAVE_SCREEN;
        work->seq[11] = GAME_CLEAR_STEP_WAIT_FRAMES;
        work->seq[12] = GAME_CLEAR_STEP_CALL_THE_END;
        work->seq[13] = GAME_CLEAR_STEP_DONE;
    } else {
        work->seq[0] = GAME_CLEAR_STEP_PREPARE;
        work->seq[1] = GAME_CLEAR_STEP_REQUEST_COMM_IDLE;
        work->seq[2] = GAME_CLEAR_STEP_FIELD_PREPARE_EVENT;
        work->seq[3] = GAME_CLEAR_STEP_WAIT_COMM_IDLE;
        work->seq[4] = GAME_CLEAR_STEP_CLOSE_FIELD;
        work->seq[5] = GAME_CLEAR_STEP_CALL_HALL_OF_FAME;
        work->seq[6] = GAME_CLEAR_STEP_WAIT_HALL_OF_FAME;
        work->seq[7] = GAME_CLEAR_STEP_SET_SCRIPT_STATE;
        work->seq[8] = GAME_CLEAR_STEP_CALL_SAVE_SCREEN;
        work->seq[9] = GAME_CLEAR_STEP_CALL_STAFF_ROLL;
        work->seq[10] = GAME_CLEAR_STEP_WAIT_STAFF_ROLL;
        work->seq[11] = GAME_CLEAR_STEP_CALL_THE_END;
        work->seq[12] = GAME_CLEAR_STEP_DONE;
    }
    work->step = work->seq[0];
}

/*
 * Kind passed to the comm exit event: 7 for power 0x15, else 8. The 0x14
 * test is redundant but is in the bytes.
 */
int EVENT_GAMECLEAR_GetCommExitKind(void)
{
    int powerId = GPOWER_GetSpecialPowerId();

    if (powerId == 0x14 || powerId != 0x15)
        return 8;
    return 7;
}

/*
 * Advance the step counter and load the next step from the sequence.
 */
void EVENT_GAMECLEAR_AdvanceStep(GameClearWork *work, u32 *seq)
{
    (*seq)++;
    work->step = work->seq[*seq];
}

void EVENT_GAMECLEAR_SetGatePoints(GameClearWork *work)
{
    struct MiscSave *miscSave = GAME_DATA_GetMiscSave(work->gameData);

    MISC_SetGatePoints(miscSave, 0x5a0);
}
