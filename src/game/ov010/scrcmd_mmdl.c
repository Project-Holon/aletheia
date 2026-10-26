/*
 * file:     scrcmd_mmdl.c
 * unit:     yes
 * function: SCRCMD_MMDL_StartRise, SCRCMD_MMDL_RiseEventMain, SCRCMD_MMDL_StartOrbit, SCRCMD_MMDL_OrbitEventMain
 * address:  0x0216A7A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_trialhouse.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FX_SinCosTable_  0x020A1B38  data
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "script_work_types.h"
#include "formchange_shaymin_shared_types.h"
#include "scrcmd_trialhouse_shared_types.h"
#include "scrcmd_mmdl_shared_types.h"

#include "../types.h"

/* Rise of a field model over a number of frames (0x18 bytes). */
typedef struct MmdlRiseWork {
    int totalRise;              /* 0x00: fx32 distance to cover */
    u16 frames;                 /* 0x04 */
    u16 frame;                  /* 0x06 */
    struct Mmdl *mmdl;          /* 0x08 */
    VecFx32 startPos;           /* 0x0C */
} MmdlRiseWork;

/* Spiral and circle motion of a field model around its start position (0x14 bytes). */
typedef struct MmdlOrbitWork {
    u32 frame;                  /* 0x00 */
    struct Mmdl *mmdl;          /* 0x04 */
    VecFx32 centerPos;          /* 0x08 */
} MmdlOrbitWork;

/* ScriptWork, ScrcmdWork and game structure accessors. */
#include "scrcmd_work.h"



#include "script_work_cmd.h"

#include "script_sys.h"

#include "../arm9/gamesystem.h"

/* Game events. */
#include "../arm9/game_event.h"


/* Field models and the field map. */
#include "../ov021/fieldmap.h"

#include "fldmmdl.h"
struct VecFx32;




extern const s16 FX_SinCosTable_[];

int SCRCMD_MMDL_StartRise(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_MMDL_RiseEventMain(struct GameEvent *event, int *state, void *work);

int SCRCMD_MMDL_StartOrbit(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_MMDL_OrbitEventMain(struct GameEvent *event, int *mode, void *work);

#define MMDL_MOVE_BIT_RISE 0x8000

/* Script command: raises a field model to a height over a number of frames. */
int SCRCMD_MMDL_StartRise(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int objId;
    int height;
    int frames;
    struct GameEvent *event;
    MmdlRiseWork *work;
    struct Mmdl *mmdl;

    SCRCMD_WORK_GetGameData(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    height = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    frames = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_MMDL_RiseEventMain, sizeof(MmdlRiseWork));
    work = GAME_EVENT_GetWork(event);
    work->frames = frames;
    work->frame = 0;
    mmdl = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap(gameSystem)), objId);
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&work->startPos));
    work->mmdl = mmdl;
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVE_BIT_RISE);
    work->totalRise = (height << 15) - work->startPos.y;
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

int SCRCMD_MMDL_RiseEventMain(struct GameEvent *event, int *state, void *work)
{
    MmdlRiseWork *rise = work;
    VecFx32 pos;

    rise->frame = rise->frame + 1;
    pos = rise->startPos;
    pos.y += (rise->totalRise * rise->frame) / rise->frames;
    FLDMMDL_SetPos(rise->mmdl, (struct VecFx32 *)(&pos));
    if (rise->frame >= rise->frames) {
        return 1;
    }
    return 0;
}

/* Script command: moves a field model in a spiral and circle around its position. */
int SCRCMD_MMDL_StartOrbit(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int objId;
    struct GameEvent *event;
    struct Mmdl *mmdl;
    MmdlOrbitWork *work;

    SCRCMD_WORK_GetGameData(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_MMDL_OrbitEventMain, sizeof(MmdlOrbitWork));
    work = GAME_EVENT_GetWork(event);
    work->frame = 0;
    mmdl = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap(gameSystem)), objId);
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&work->centerPos));
    work->mmdl = mmdl;
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

/*
 * Three-phase orbit step: spiral out over 110 frames, circle at radius 3
 * for 80, spiral in for 80, returning 1 when done. FX_Mul must be the
 * inline function with the table value first (the macro, or the radius
 * first, puts the radius in r0:r1 and spills its sign word: 368 out).
 */
int SCRCMD_MMDL_OrbitEventMain(struct GameEvent *event, int *mode, void *work)
{
    MmdlOrbitWork *orbit = work;
    VecFx32 pos;
    u32 frame;
    int index;
    fx32 radius;

    pos = orbit->centerPos;
    frame = ++orbit->frame;
    switch (*mode) {
    case 0:
        index = (frame << 17) / 110;
        if (index >= 0x10000)
            index %= 0x10000;
        index = (index >> 4) * 2;
        radius = (frame * 3 << 16) / 110;
        pos.x += FX_Mul(FX_SinCosTable_[index + 1], radius);
        pos.z += FX_Mul(FX_SinCosTable_[index], radius);
        FLDMMDL_SetPos(orbit->mmdl, (struct VecFx32 *)(&pos));
        if (orbit->frame >= 110) {
            orbit->frame = 0;
            *mode = 1;
        }
        break;
    case 1:
        index = (frame << 16) / 80;
        if (index >= 0x10000)
            index %= 0x10000;
        index = (index >> 4) * 2;
        pos.x += FX_Mul(FX_SinCosTable_[index + 1], 0x30000);
        pos.z += FX_Mul(FX_SinCosTable_[index], 0x30000);
        FLDMMDL_SetPos(orbit->mmdl, (struct VecFx32 *)(&pos));
        if (orbit->frame >= 80) {
            orbit->frame = 0;
            *mode = 2;
        }
        break;
    case 2:
        index = (frame << 16) / 80;
        if (index >= 0x10000)
            index %= 0x10000;
        index = (index >> 4) * 2;
        radius = ((80 - frame) * 3 << 16) / 80;
        pos.x += FX_Mul(FX_SinCosTable_[index + 1], radius);
        pos.z += FX_Mul(FX_SinCosTable_[index], radius);
        FLDMMDL_SetPos(orbit->mmdl, (struct VecFx32 *)(&pos));
        if (orbit->frame >= 80)
            return 1;
        break;
    }
    return 0;
}
