/*
 * file:     event_wifi_proc.c
 * unit:     yes
 * function: EVENT_WIFI_PROC_CreateOv020Event, EVENT_WIFI_PROC_LoadOv020Task, EVENT_WIFI_PROC_LoadOv020, EVENT_WIFI_PROC_UnloadOv020, EVENT_WIFI_PROC_EventMain, EVENT_WIFI_PROC_Create
 * address:  0x0215FA00
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
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   EVENT_MAPCHANGE_CreateByMode 0x02183B6C thumb ov020
 *   EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent      0x0218571C  thumb  ov020
 *   abs_id_14      0x00000014  data
 *   GF_OVERLAY_Unload   0x02034A5C  arm
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   INTRUDE_SUBDISP_CreateTownWarpEvent  0x0217CE08  thumb
 *   INTRUDE_SUBDISP_CreateGuideScriptEvent  0x0217CDBC  thumb
 *   EVENT_COMM_COMMON_CreateReturnPalaceEvent  0x0217FA24  thumb
 *   ov122_id       0x0000007A  data
 *   ov172_id       0x000000AC  data
 *   d_021D5764     0x021D5764  data  ov122
 *   d_021C7240     0x021C7240  data
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   GAME_EVENT_Change  0x0201232C  thumb
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_network_shared_types.h"
#include "event_gameclear_shared_types.h"
#include "event_wifi_proc_shared_types.h"

/* Work of the event that opens the Wi-Fi screens (0x34 bytes). */
typedef struct WifiProcWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameData *gameData;      /* 0x04 */
    struct SaveControl *saveControl;/* 0x08 */
    u8 ov172Param[0x10];            /* 0x0C: parameter block of the ov172 task */
    u32 exitRequest;                /* 0x1C: cleared once the screens closed */
    u32 entryKind;                  /* 0x20: 0 opening, 1 with BGM change */
    u32 savedBgmNo;                 /* 0x24 */
    u32 exitKind;                   /* 0x28: picks the closing screen */
    u8 pad2C[0x34 - 0x2C];
} WifiProcWork;
struct GameComm;
struct IntrudeCommSys;

#include "intrude_comm_query.h"
struct GameEvent;

/* game system, game event, game data */
#include "../arm9/game_event.h"





#include "../arm9/gamesystem.h"





#include "../arm9/game_data.h"


/* game comm, config, misc */
#include "../arm9/game_comm.h"



#include "../arm9/gf_overlay.h"




#include "../arm9/gfl_use.h"



/* field events and field */
#include "../ov021/event_fieldmap_control.h"

#include "../arm9/field_status.h"



#include "../ov018/intrude_subdisp.h"


#include "../ov018/event_comm_common.h"

#include "../ov020/event_mapchange.h"

struct FieldSubscreen;

                                      
#include "../ov021/fieldmap.h"

extern unsigned char ov020_id[];

extern unsigned char abs_id_14[];

extern u8 ov122_id[];

extern u8 ov172_id[];

extern u8 d_021D5764[];

extern u8 d_021C7240[];

struct GameEvent *EVENT_WIFI_PROC_CreateOv020Event(struct GameSystem *gameSystem, u32 initParam);

struct GameEvent *EVENT_WIFI_PROC_LoadOv020Task(struct GameSystem *gameSystem);

void EVENT_WIFI_PROC_LoadOv020(void);

void EVENT_WIFI_PROC_UnloadOv020(void);

int EVENT_WIFI_PROC_EventMain(struct GameEvent *event, u32 *seq, void *workArg);

struct GameEvent *EVENT_WIFI_PROC_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct GameEvent *event, int createNew);

struct GameEvent *EVENT_WIFI_PROC_CreateOv020Event(struct GameSystem *gameSystem, u32 initParam)
{
    GF_OVERLAY_Load((uptr)ov020_id);
    return EVENT_MAPCHANGE_CreateByMode(gameSystem, (struct GameInitWork *)initParam);
}

/*
 * Loads overlay 20 (GF_OVERLAY_Load with the pooled id abs_id_14) and returns
 * the task that ov020 EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent creates for the game system.  The bytes
 * are the same as the TWL DSPi_WaitForPipe (dsp_pipe.o), which named it before.
 */
struct GameEvent *EVENT_WIFI_PROC_LoadOv020Task(struct GameSystem *gameSystem)
{
    GF_OVERLAY_Load((sptr)abs_id_14);
    return EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(gameSystem);
}

/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM GF_OVERLAY_Load with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with EVENT_WIFI_PROC_UnloadOv020 (same id, into GF_OVERLAY_Unload).
 */
void EVENT_WIFI_PROC_LoadOv020(void)
{
    GF_OVERLAY_Load((sptr)abs_id_14);
}

/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM GF_OVERLAY_Unload with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with EVENT_WIFI_PROC_LoadOv020 (same id, into GF_OVERLAY_Load).
 */
void EVENT_WIFI_PROC_UnloadOv020(void)
{
    GF_OVERLAY_Unload((sptr)abs_id_14);
}

/*
 * Event main of the Wi-Fi screens: 11 states that push the child
 * tasks, load ov122 and ov172, and pick the closing screen from
 * work->exitKind.
 * Byte-correct (first draft plus one lever: in state 9 the `exitKind == 2`
 * test and the call share an else block ending in the one `*seq = 10`
 * store, so that store is the copy the other arms cross-jump to).
 * Former blocker (MATCH): the pooled 0xAC is ov172_id passed in r1 to
 * GAME_EVENT_CallProc, which is not in match.py's OVERLAY_ID_CONSUMERS
 * (GAME_EVENT_CallProc stores r1 in a task descriptor, src/matched/GAME_EVENT_CallProc.c),
 * so the ABS32 at +0x190 has no witness.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int EVENT_WIFI_PROC_EventMain(struct GameEvent *event, u32 *seq, void *workArg)
{
    WifiProcWork *work = workArg;
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameComm *gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        *seq = 2;
        break;
    case 2:
        (*seq)++;
    case 3:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov122_id, d_021D5764, work);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        switch (work->entryKind) {
        case 0:
            if (INTRUDE_COMM_GetWorkIfRunning(gameComm) && work->exitKind == 2)
                GAME_DATA_SetSubscreenType(gameData, 3);
            *seq = 6;
            break;
        case 1:
            work->savedBgmNo = GFL_USE_GetBgmNo();
            GAME_EVENT_CallProc(event, (uptr)ov172_id, d_021C7240, work->ov172Param);
            *seq = 5;
            break;
        default:
            *seq = 6;
            break;
        }
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
        GFL_USE_FadeInBgmFull(60);
        *seq = 6;
        break;
    case 6:
        work->exitRequest = 0;
        (*seq)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 9:
        if (work->entryKind == 0) {
            if (work->exitKind == 0) {
                if (GAME_COMM_IsTransition(gameComm))
                    break;
                if (GAME_COMM_GetKind(gameComm)) {
                    GAME_COMM_RequestExitNoCallback(gameComm);
                    break;
                }
                GAME_EVENT_CallEvent(event, INTRUDE_SUBDISP_CreateTownWarpEvent(gameSystem, fieldMap, 0x117, 0));
                *seq = 10;
            } else if (work->exitKind == 3) {
                GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateReturnPalaceEvent(gameSystem));
                *seq = 10;
            } else {
                if (work->exitKind != 2)
                    GAME_EVENT_CallEvent(event, INTRUDE_SUBDISP_CreateGuideScriptEvent(gameSystem));
                *seq = 10;
            }
        } else {
            *seq = 10;
        }
        break;
    case 10:
        return 1;
    }
    return 0;
}

/*
 * Creates the Wi-Fi screens event, or turns the given event into it when
 * createNew is 0.
 */
struct GameEvent *EVENT_WIFI_PROC_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct GameEvent *event, int createNew)
{
    WifiProcWork *work;
    struct GameData *gameData;

    FIELDMAP_GetSubscreen(fieldMap);
    if (createNew != 0) {
        event = GAME_EVENT_Create(gameSystem, 0, EVENT_WIFI_PROC_EventMain, 0x34);
    } else {
        GAME_EVENT_Change(event, EVENT_WIFI_PROC_EventMain, 0x34);
    }
    work = GAME_EVENT_GetWork(event);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->gameData = gameData;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameSystem = gameSystem;
    return event;
}
