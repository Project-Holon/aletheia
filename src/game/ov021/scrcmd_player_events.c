/*
 * file:     scrcmd_player_events.c
 * unit:     yes
 * function: SCRCMD_PLAYER_GRID_EVENT_WaitHop, SCRCMD_PLAYER_GRID_EVENT_StartHop, SCRCMD_PLAYER_GRID_EVENT_WaitJump, SCRCMD_PLAYER_GRID_EVENT_StartJump, SCRCMD_IAIGIRI_StartOnPlayer, SCRCMD_SAVEANIME_Start, RAIL_SLIPDOWN_StartAtPlayer, RAIL_SLIPDOWN_Start, RAIL_SLIPDOWN_UpdateTask
 * address:  0x021C457C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): cut from fldeff_ripple.c at 021C457C..021C47B3: script commands that start player grid hop and jump events, the iai-giri effect and the save animation, plus the rail slip-down starter. The __FILE__ anchor fldeff_ripple.c is FLDEFF_RIPPLE_Create 021C47B4, so this code lies before the anchored file; module prefix changes there. Original file name unknown.
 *
 * symbols:
 *   FIELD_PLAYER_GRID_EVENT_IsHopDone  0x021C1094  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_DeleteHopTask  0x021C10A0  thumb  ov021
 *   SCRCMD_WORK_GetTargetObject  0x0215A64C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb  ov021
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_CreateHopTask  0x021C1024  thumb  ov021
 *   SCRCMD_WORK_SetTargetObject  0x0215A644  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   FIELD_PLAYER_GRID_EVENT_IsJumpDone  0x021C12C4  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_DeleteJumpTask  0x021C12D0  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_PLAYER_GRID_EVENT_CreateJumpTask  0x021C1228  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_IAIGIRI_Start  0x021C9550  thumb  ov021
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLDEFF_RIPPLE_CreateZoneStartWarpTask  0x021D2418  thumb  ov021
 *   FLDEFF_RIPPLE_CreateSpecialLocationWarpTask  0x021D2440  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   FIELD_PLAYER_SetDirDisp  0x021A305C  thumb  ov021
 *   RAIL_SLIPDOWN_Create  0x021F36C0  thumb  ov063
 *   ov063_id       0x0000003F  data
 *   RAIL_SLIPDOWN_Delete  0x021F3758  thumb  ov063
 *   RAIL_SLIPDOWN_IsDone  0x021F376C  thumb  ov063
 *   GF_OVERLAY_Unload  0x02034A5C  arm  arm9
 */
#include "../arm9/billboard_act_types.h"

#include "../ov010/scrcmd_work.h"

#include "field_player_grid_event.h"

struct ScrcmdWork;
struct GameSystem;


#include "../arm9/gamesystem.h"
struct FieldMap;
struct FieldPlayer;

#include "fieldmap.h"
struct Mmdl;

#include "field_player.h"

#include "../ov010/fldmmdl.h"
struct FieldG3dMapper;




#include "map_attr.h"



#include "../arm9/vm.h"



struct ScriptVm;

#include "../ov010/script_work_cmd.h"

struct FieldEffectSys;

struct FieldEffectSys;

#include "fldeff_iaigiri.h"
struct ScriptWork;

struct GameEvent;

#include "scrcmd_misc.h"


#include "../ov010/script_sys.h"

#include "../arm9/game_event.h"


#include "../arm9/gf_overlay.h"

struct RailSlipdown;

#include "../ov063/rail_slipdown.h"




int SCRCMD_PLAYER_GRID_EVENT_WaitHop(struct ScriptVm *vm, void *scriptWork);

u32 SCRCMD_PLAYER_GRID_EVENT_StartHop(struct ScriptVm *vm, void *scriptWork);

int SCRCMD_PLAYER_GRID_EVENT_WaitJump(struct ScriptVm *vm, void *scriptWork);

u32 SCRCMD_PLAYER_GRID_EVENT_StartJump(struct ScriptVm *vm, void *scriptWork);

int SCRCMD_IAIGIRI_StartOnPlayer(void *vm, void *scriptWork);

int SCRCMD_SAVEANIME_Start(void *vm, void *scriptWork);

struct GameEvent *RAIL_SLIPDOWN_StartAtPlayer(struct GameSystem *a, struct FieldMap *b, u32 c);

void *RAIL_SLIPDOWN_Start(void *a, struct FieldMap *b, struct Mmdl *c);

int RAIL_SLIPDOWN_UpdateTask(struct GameEvent *task, int *seq, void *work);

extern unsigned char ov063_id[];

/*
 * Script wait callback of the first grid event command: done once
 * FIELD_PLAYER_GRID_EVENT_IsHopDone reports 1.
 */
int SCRCMD_PLAYER_GRID_EVENT_WaitHop(struct ScriptVm *vm, void *scriptWork)
{
    void *gridEvent = SCRCMD_WORK_GetTargetObject(scriptWork);

    if (FIELD_PLAYER_GRID_EVENT_IsHopDone(gridEvent) == 1) {
        FIELD_PLAYER_GRID_EVENT_DeleteHopTask((struct TcbTask *)gridEvent);
        return 1;
    }
    return 0;
}

/*
 * First grid event script command: starts the event on the player's grid
 * position and installs SCRCMD_PLAYER_GRID_EVENT_WaitHop as the wait callback.
 */
u32 SCRCMD_PLAYER_GRID_EVENT_StartHop(struct ScriptVm *vm, void *scriptWork)
{
    VecFx32 pos;
    u16 playerWork;
    u32 effectId, result;
    struct TcbTask *task;
    void *fieldMap;
    void *player;

    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)scriptWork));
    player = FIELDMAP_GetFieldPlayer((void *)fieldMap);
    playerWork = FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(player));
    fieldMap = (void *)FIELDMAP_GetG3dMapper(fieldMap);
    effectId = SCRCMD_WORK_GetHeapId((void *)scriptWork);
    FIELD_PLAYER_GetPosInDir(player, playerWork, &pos);
    result = MAP_ATTR_GetAt(fieldMap, &pos);
    task = FIELD_PLAYER_GRID_EVENT_CreateHopTask(player, playerWork, result, effectId);
    SCRCMD_WORK_SetTargetObject((void *)scriptWork, task);
    VM_SetWait(vm, SCRCMD_PLAYER_GRID_EVENT_WaitHop);
    return 1;
}

/*
 * Script wait callback of the second grid event command.
 */
int SCRCMD_PLAYER_GRID_EVENT_WaitJump(struct ScriptVm *vm, void *scriptWork)
{
    void *gridEvent = SCRCMD_WORK_GetTargetObject(scriptWork);

    if (FIELD_PLAYER_GRID_EVENT_IsJumpDone(gridEvent) == 1) {
        FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(gridEvent);
        return 1;
    }
    return 0;
}

/*
 * Second grid event script command (see SCRCMD_PLAYER_GRID_EVENT_StartHop).
 */
u32 SCRCMD_PLAYER_GRID_EVENT_StartJump(struct ScriptVm *vm, void *scriptWork)
{
    u32 effectId;
    u16 playerWork;
    u32 result;
    struct TcbTask *task;
    void *player;

    effectId = SCRCMD_WORK_GetHeapId(scriptWork);
    player = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)scriptWork)));
    playerWork = FIELD_PLAYER_GetDirDisp(player);
    result = SCRIPT_WORK_ReadWorkValue(vm, (void *)scriptWork);
    task = FIELD_PLAYER_GRID_EVENT_CreateJumpTask(player, playerWork, result, effectId);
    SCRCMD_WORK_SetTargetObject((void *)scriptWork, task);
    VM_SetWait(vm, SCRCMD_PLAYER_GRID_EVENT_WaitJump);
    return 1;
}

/*
 * Script command: starts the Cut effect on the player's field object.
 */
int SCRCMD_IAIGIRI_StartOnPlayer(void *vm, void *scriptWork)
{
    void *fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scriptWork));
    void *playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)fieldMap));

    FLDEFF_IAIGIRI_Start((struct Mmdl *)playerMmdl, (struct FieldEffectSys *)FIELDMAP_GetEffect(fieldMap));
    return 0;
}

/*
 * Script command: starts a saved animation chosen by the type SCRIPT_WORK_ReadWorkValue
 * returns. The shared SCRIPT_SYS_CallEvent call is written out in every arm and
 * cross-jumped by the compiler; a result local merged after the if chain
 * spills the script object instead of scriptWork.
 */
int SCRCMD_SAVEANIME_Start(void *vm, void *scriptWork)
{
    u32 type;
    void *fieldMap;
    void *saveAnimeArg;
    void *scriptObj;

    saveAnimeArg = SCRCMD_WORK_GetGameSystem(scriptWork);
    fieldMap = GAMESYSTEM_GetFieldMap(saveAnimeArg);
    scriptObj = SCRCMD_WORK_GetScriptWork(scriptWork);
    type = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    if (type == 0)
        SCRIPT_SYS_CallEvent(scriptObj, FLDEFF_RIPPLE_CreateZoneStartWarpTask(saveAnimeArg, (struct FieldMap *)fieldMap));
    else if (type == 1)
        SCRIPT_SYS_CallEvent(scriptObj, FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(saveAnimeArg, (struct FieldMap *)fieldMap, 0));
    else
        SCRIPT_SYS_CallEvent(scriptObj, FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(saveAnimeArg, (struct FieldMap *)fieldMap, 1));
    return 1;
}

/*
 * Starts the ov063 effect for the player's grid event with the player's
 * data and spawns the task that drives it.
 */
struct GameEvent *RAIL_SLIPDOWN_StartAtPlayer(struct GameSystem *a, struct FieldMap *b, u32 c)
{
    struct GameEvent *task = GAME_EVENT_Create(a, 0, RAIL_SLIPDOWN_UpdateTask, 4);
    void **effectSlot = GAME_EVENT_GetWork(task);
    struct FieldPlayer *fieldMap;
    struct Mmdl *player;

    GF_OVERLAY_Load((sptr)ov063_id);
    fieldMap = FIELDMAP_GetFieldPlayer(b);
    player = FIELD_PLAYER_GetMmdl(fieldMap);
    FIELD_PLAYER_SetDirDisp(fieldMap, c);
    *effectSlot = RAIL_SLIPDOWN_Create(a, b, player, 1);
    return task;
}

/*
 * Loads ov063 and spawns the task that drives its effect.
 */
void *RAIL_SLIPDOWN_Start(void *a, struct FieldMap *b, struct Mmdl *c)
{
    void *task = GAME_EVENT_Create(a, 0, RAIL_SLIPDOWN_UpdateTask, 4);
    void **effectSlot = GAME_EVENT_GetWork(task);

    GF_OVERLAY_Load((uptr)ov063_id);
    *effectSlot = RAIL_SLIPDOWN_Create(a, b, c, 0);
    return task;
}

/*
 * Task callback: when the ov063 effect reports done, frees it and unloads
 * ov063.
 */
int RAIL_SLIPDOWN_UpdateTask(struct GameEvent *task, int *seq, void *work)
{
    void **effectSlot = GAME_EVENT_GetWork(task);

    if (RAIL_SLIPDOWN_IsDone(*effectSlot) != 0) {
        RAIL_SLIPDOWN_Delete(*effectSlot);
        GF_OVERLAY_Unload((uptr)ov063_id);
        return 1;
    }
    return 0;
}
