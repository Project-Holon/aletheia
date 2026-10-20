/*
 * file:     fld_faceup.c
 * unit:     yes
 * function: FLD_FACEUP_ScrCmdStart, FLD_FACEUP_ScrCmdPrepareField, FLD_FACEUP_ScrCmdWaitEnd, FLD_FACEUP_Finish, FLD_FACEUP_EndEvent
 * address:  0x02164910
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
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   VM_ReadU16  0x02011330  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb ov010
 *   FLD_FACEUP_Create  0x021F5260  thumb ov082
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb ov010
 *   ov_id_52       0x00000052  data
 *   FLD_FACEUP_ResumeLipSync  0x021F558C  thumb
 *   FLD_FACEUP_Delete 0x021F5578 thumb ov082
 *   SCRIPT_WORK_ResetCheckFlag 0x02159168 thumb ov010
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLD_FACEUP_StartClose  0x021F5550  thumb  ov082
 */
#include "field_skill_check_shared_types.h"
#include "scrcmd_bridge_gimmick_shared_types.h"

struct ScriptSystem;

#define OVERLAY_ID_52 ((int)ov_id_52)

typedef struct FaceUpEndWork {
    struct GameSystem *gameSystem;
} FaceUpEndWork;

#include "../arm9/gamesystem.h"

#include "../arm9/game_event.h"
struct ScrcmdWork;

#include "scrcmd_work.h"

#include "../arm9/gf_overlay.h"

struct ScriptWork;


#include "../arm9/vm.h"

#include "script_work.h"

#include "../ov082/fld_faceup.h"

#include "script_sys.h"







extern u8 ov_id_52[];

int FLD_FACEUP_ScrCmdStart(struct ScriptVm *vm, struct ScrcmdWork *work);

int FLD_FACEUP_ScrCmdPrepareField(struct ScriptVm *vm, struct ScrcmdWork *work);

int FLD_FACEUP_ScrCmdWaitEnd(struct ScriptVm *vm, struct ScrcmdWork *work);

int FLD_FACEUP_Finish(FaceUpEndWork *work);

int FLD_FACEUP_EndEvent(struct GameEvent *event, int *seq);

/*
 * Script command: reads three values off the script, loads overlay 82 and
 * starts the face-up scene; waits for it when a task was created.
 */
int FLD_FACEUP_ScrCmdStart(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    struct ScriptSystem *scriptSystem = (struct ScriptSystem *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)work);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)work);
    u8 type = VM_ReadU16(vm);
    u8 variant = VM_ReadU16(vm);
    u32 option = VM_ReadU16(vm);
    void *task;

    SCRIPT_WORK_SetCheckFlag(7);
    GF_OVERLAY_Load(OVERLAY_ID_52);
    task = FLD_FACEUP_Create(type, variant, option, gameSystem, work);
    if (task == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/* Script command: finishes the face-up scene on the field map. */
int FLD_FACEUP_ScrCmdPrepareField(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)work);
    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)work);
    FLD_FACEUP_ResumeLipSync(GAMESYSTEM_GetFieldMap(gameSystem));
    return 0;
}

/* Script command: creates the face-up wait event and waits for it. */
int FLD_FACEUP_ScrCmdWaitEnd(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    struct ScriptSystem *scriptSystem = (struct ScriptSystem *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)work);
    struct GameEvent *event = GAME_EVENT_Create(SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)work), 0, (void *)FLD_FACEUP_EndEvent, 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptSystem, event);
    return 1;
}

/* Ends the face-up scene: releases the field map part, the script state and overlay 82. */
int FLD_FACEUP_Finish(FaceUpEndWork *work)
{
    FLD_FACEUP_Delete(GAMESYSTEM_GetFieldMap(work->gameSystem));
    SCRIPT_WORK_ResetCheckFlag(7);
    GF_OVERLAY_Unload(OVERLAY_ID_52);
    return 1;
}

/* Event: step 0 starts the face-up end request, step 1 releases it and the overlay. */
int FLD_FACEUP_EndEvent(struct GameEvent *event, int *seq)
{
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, FLD_FACEUP_StartClose(gameSystem));
        (*seq)++;
        break;
    case 1:
        SCRIPT_WORK_ResetCheckFlag(7);
        GF_OVERLAY_Unload(OVERLAY_ID_52);
        return 1;
    }
    return 0;
}
