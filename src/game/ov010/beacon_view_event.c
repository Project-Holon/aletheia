/*
 * file:     beacon_view_event.c
 * unit:     yes
 * function: BEACON_VIEW_EVENT_Sequence, BEACON_VIEW_EVENT_Create
 * address:  0x02164A2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_skill_check.c, calender.c, game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   FIELDMAP_GetSubscreen 0x02188CCC thumb ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPushAndChangeTask  0x020297AC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_SOUND_SYSTEM_StartPopTask  0x02029690  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SUBSCREEN_ChangeModeNow  0x021A0F40  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   ov216_id       0x000000D8  data
 *   d_021BDB40     0x021BDB40  data  a1 ov216
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 */
#include "../ov021/fldmmdl_rail_types.h"
#include "../arm9/game_beacon_types.h"
#include "field_skill_check_shared_types.h"
#include "beacon_view_event_shared_types.h"

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern void MI_CpuFill8(void *dst, u8 val, u32 size);

#define OVERLAY_ID_216 ((u32)ov216_id)

/* Argument block of the overlay 216 process. */
typedef struct BeaconSearchProcArgs {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u8 mode;
    u8 resultFlag;
    u8 pad[2];
} BeaconSearchProcArgs;

/* Work of the beacon search event, 0x1C bytes. */
typedef struct BeaconSearchEventWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    void *saveControl;
    BeaconSearchProcArgs procArgs;
    u8 mode;
} BeaconSearchEventWork;

extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);
struct FieldSubscreen;

extern struct FieldSubscreen *FIELDMAP_GetSubscreen(struct FieldMap *fieldMap);

extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);

extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int mode, int subMode);

extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);

extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(struct GameSystem *gameSystem, u32 soundId, u32 mode, u32 flag);

extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);

extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);

extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPopTask(struct GameSystem *gameSystem, u32 mode, u32 frames);

extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);

extern void FIELD_SUBSCREEN_ChangeModeNow(struct FieldSubscreen *work, u32 mode);

extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int mode, int subMode, int enable, u8 optionA, u8 optionB);

extern struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem);

extern u8 ov216_id[];

extern const u8 d_021BDB40[];


/*
 * Beacon search event: eight steps, each starting one child event or
 * process (the overlay 216 one through GAMESYSTEM_CallProc with a 12-byte
 * argument block), then done. Step 2 falls through into step 3.
 * d_021BDB40 is the process template and lives in overlay 216.
 */
int BEACON_VIEW_EVENT_Sequence(struct GameEvent *event, u32 *seq, BeaconSearchEventWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;

    gameSystem = work->gameSystem;
    GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushAndChangeTask(gameSystem, 0x483, 6, 0));
        (*seq)++;
        /* fall through */
    case 3:
        MI_CpuFill8(&work->procArgs, 0, sizeof(BeaconSearchProcArgs));
        work->procArgs.gameSystem = work->gameSystem;
        work->procArgs.gameData = work->gameData;
        work->procArgs.mode = work->mode;
        GAMESYSTEM_CallProc(gameSystem, OVERLAY_ID_216, (void *)d_021BDB40, &work->procArgs);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopTask(gameSystem, 6, 0x3C));
            (*seq)++;
        }
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 6:
        if (work->procArgs.resultFlag != 0) {
            FIELD_SUBSCREEN_ChangeModeNow(FIELDMAP_GetSubscreen(fieldMap), 0);
        }
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*seq)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}

/* ------------------------------------------------------------------ *
 * calender.c (see misplaced.tsv): the calender event work, 0x1C bytes.
 * ------------------------------------------------------------------ */
typedef struct CalenderEventWork {
    struct GameSystem *gameSystem;      /* 0x00 */
    struct GameData *gameData;          /* 0x04 */
    struct SaveControl *saveControl;    /* 0x08 */
    u8 reserved[12];
    u8 mode;                            /* 0x18 */
} CalenderEventWork;

extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, int (*func)(struct GameEvent *, u32 *, void *), u32 workSize);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

struct GameEvent *BEACON_VIEW_EVENT_Create(struct GameSystem *gameSystem, void *unused, u8 mode);

struct GameEvent *BEACON_VIEW_EVENT_Create(struct GameSystem *gameSystem, void *unused, u8 mode)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, (void *)BEACON_VIEW_EVENT_Sequence, sizeof(CalenderEventWork));
    CalenderEventWork *work = GAME_EVENT_GetWork(event);
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);

    work->gameData = gameData;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameSystem = gameSystem;
    work->mode = mode;
    return event;
}
