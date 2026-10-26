/*
 * file:     btlv_clact.c
 * unit:     yes
 * function: BTLV_CLACT_Create, BTLV_CLACT_Delete, BTLV_CLACT_Draw, BTLV_CLACT_LoadActorSimple, BTLV_CLACT_LoadActor, BTLV_CLACT_ReleaseActor, BTLV_CLACT_StartPosTween, BTLV_CLACT_StartScaleTween, BTLV_CLACT_SetActorAnimSeq, BTLV_CLACT_RequestPaletteFade, BTLV_CLACT_StartMoveTask, BTLV_CLACT_MoveTaskMain, BTLV_CLACT_MoveTaskEnd, BTLV_CLACT_MoveTaskMainWide, BTLV_CLACT_MoveTaskEndWide
 * address:  0x02201A8C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   FX_Div  0x0207C768  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   PALANM_RequestFade  0x0202173C  thumb
 *   TCBL_GetOwnedWork   0x02030EE8  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gBtlvClactFileName  0x0220AE88  data  a4
 *   CLACT_DrawSystem  0x0204A600  arm
 *   gBtlvClactDefaultActorInit 0x0220A368 data a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   CLACT_SetActorScale  0x0204B5AC  arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 *   BTLV_EFFECT_ComputeVectorStep 0x021F918C thumb ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 */
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_effvm_shared_types.h"
#include "btlv_clact_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/fx_cp.h"
struct TcbSystem;
struct TcbTask;

#include "../arm9/tcb_list.h"

struct TcblSystem;

#include "../arm9/tcbl.h"


#include "../arm9/clact.h"



#include "../arm9/arc_tool.h"





#include "../arm9/palanm.h"












struct Pair32;


#include "btlv_effect.h"






BtlvClact *BTLV_CLACT_Create(void *owner, u16 heap);

void BTLV_CLACT_Delete(BtlvClact *clact);

void BTLV_CLACT_Draw(void *unused);

int BTLV_CLACT_LoadActorSimple(BtlvClact *clact, int archiveId, int firstFile, s16 x, s16 y, int scaleX, int scaleY);

int BTLV_CLACT_LoadActor(BtlvClact *clact, u32 archiveId, int charFile, u32 palFile, int cellFile, int animFile, s16 x, s16 y, u32 scaleX, u32 scaleY);

void BTLV_CLACT_ReleaseActor(BtlvClact *clact, int slot);

void BTLV_CLACT_StartPosTween(BtlvClact *clact, int slot, int mode, s16 *offset, int frames, int waitTicks, int repeats);

void BTLV_CLACT_StartScaleTween(BtlvClact *clact, int slot, int mode, VecFx32 *scaleEnd, int frames, int waitTicks, int repeats);

void BTLV_CLACT_SetActorAnimSeq(BtlvClact *clact, int slot, int seq);

void BTLV_CLACT_RequestPaletteFade(BtlvClact *clact, int slot, u8 b, u8 c, s8 step, u16 d);

void BTLV_CLACT_StartMoveTask(BtlvClact *clact, int slot, u32 mode, VecFx32 *start, VecFx32 *end, int frames, int waitTicks, int repeats,
                   void (*taskMain)(struct TcbTask *, void *), void (*taskEnd)(void *));

void BTLV_CLACT_MoveTaskMain(struct TcbTask *task, void *work);

void BTLV_CLACT_MoveTaskEnd(void *task);

void BTLV_CLACT_MoveTaskMainWide(struct TcbTask *task, void *work);

void BTLV_CLACT_MoveTaskEndWide(void *task);

extern const char gBtlvClactFileName[];

extern const struct ActorInit gBtlvClactDefaultActorInit;

BtlvClact *BTLV_CLACT_Create(void *owner, u16 heap)
{
    BtlvClact *clact = GFL_HEAP_Alloc(heap, sizeof(*clact), 1, gBtlvClactFileName, 0x4f);
    clact->owner = owner;
    clact->heap = heap;
    clact->unit = CLACT_CreateUnit(7, 0, heap);
    return clact;
}

void BTLV_CLACT_Delete(BtlvClact *clact)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (clact->slot[i].actor != 0)
            BTLV_CLACT_ReleaseActor(clact, i);
    }
    CLACT_DeleteUnit(clact->unit);
    GFL_HEAP_Free(clact);
}

void BTLV_CLACT_Draw(void *unused)
{
    CLACT_DrawSystem();
}

int BTLV_CLACT_LoadActorSimple(BtlvClact *clact, int archiveId, int firstFile, s16 x, s16 y, int scaleX, int scaleY)
{
    return BTLV_CLACT_LoadActor(clact, archiveId, firstFile, firstFile + 1, firstFile + 2, firstFile + 3, x, y, scaleX, scaleY);
}

int BTLV_CLACT_LoadActor(BtlvClact *clact, u32 archiveId, int charFile, u32 palFile, int cellFile, int animFile, s16 x, s16 y, u32 scaleX, u32 scaleY)
{
    struct ActorInit init = gBtlvClactDefaultActorInit;
    void *archive = ARC_TOOL_CreateHandle(archiveId, (u16)((clact->heap & 0x7fff) | 0x8000));
    int i;
    PaletteFade *palanm;
    u32 vramAddr;
    for (i = 0; i < 7; i++) {
        if (clact->slot[i].actor == 0) break;
    }
    clact->slot[i].charId = CLACT_RegisterCharacter(archive, charFile, 0, 0, clact->heap);
    clact->slot[i].paletteId = CLACT_RegisterPaletteCompressed(archive, palFile, 0, (u16)(i * 32 + 0x140), clact->heap);
    clact->slot[i].cellId = CLACT_RegisterCellAnim(archive, cellFile, animFile, clact->heap);
    palanm = BTLV_EFFECT_GetPalanm();
    vramAddr = CLACT_GetPaletteVramAddress(clact->slot[i].paletteId, 0);
    PALANM_LoadArcPaletteToSlot(palanm, archiveId, palFile, clact->heap, 2, 32, (vramAddr & 0x3ff) >> 1);
    init.param.x = x;
    init.param.y = y;
    if (scaleX == 0 && scaleY == 0) {
        clact->slot[i].actor = CLACT_CreateActor(clact->unit, clact->slot[i].charId, clact->slot[i].paletteId, clact->slot[i].cellId, &init.param, 0, clact->heap);
    } else {
        init.scale_x = scaleX;
        init.scale_y = scaleY;
        clact->slot[i].actor = CLACT_CreateAffineActor(clact->unit, clact->slot[i].charId, clact->slot[i].paletteId, clact->slot[i].cellId, &init, 0, clact->heap);
    }
    CLACT_SetActorAutoAnim(clact->slot[i].actor, 1);
    ARC_TOOL_DeleteHandle(archive);
    return i;
}

void BTLV_CLACT_ReleaseActor(BtlvClact *clact, int slot)
{
    CLACT_ReleaseCharacter(clact->slot[slot].charId);
    CLACT_ReleasePalette(clact->slot[slot].paletteId);
    CLACT_ReleaseCellAnim(clact->slot[slot].cellId);
    CLACT_DeleteActor(clact->slot[slot].actor);
    clact->slot[slot].actor = 0;
}

void BTLV_CLACT_StartPosTween(BtlvClact *clact, int slot, int mode, s16 *offset, int frames, int waitTicks, int repeats)
{
    VecFx32 current;
    VecFx32 end;
    struct ClactVec2 pos;

    end.x = offset[0] << 12;
    end.y = offset[1] << 12;
    end.z = 0;
    CLACT_GetActorSurfacePos(clact->slot[slot].actor, &pos, 0);
    current.x = pos.x << 12;
    current.y = pos.y << 12;
    current.z = 0;
    if (mode == 1) {
        end.x += current.x;
        end.y += current.y;
        end.z += current.z;
    }
    BTLV_CLACT_StartMoveTask(clact, slot, mode, &current, &end, frames, waitTicks, repeats, BTLV_CLACT_MoveTaskMain, BTLV_CLACT_MoveTaskEnd);
    clact->moveMask |= 1 << slot;
}

/*
 * lever: a brace-initialised VecFx32 local compiles to an @N rodata template; three field stores do not.
 */
void BTLV_CLACT_StartScaleTween(BtlvClact *clact, int slot, int mode, VecFx32 *scaleEnd, int frames, int waitTicks, int repeats)
{
    VecFx32 scaleStart;

    scaleStart.x = 0x1000;
    scaleStart.y = 0x1000;
    scaleStart.z = 0x1000;

    BTLV_CLACT_StartMoveTask(clact, slot, mode, &scaleStart, scaleEnd, frames, waitTicks, repeats, BTLV_CLACT_MoveTaskMainWide, BTLV_CLACT_MoveTaskEndWide);
    clact->scaleMask |= 1 << slot;
}

void BTLV_CLACT_SetActorAnimSeq(BtlvClact *clact, int slot, int seq)
{
    CLACT_SetActorAnimSeq(clact->slot[slot].actor, (u16)seq);
}

void BTLV_CLACT_RequestPaletteFade(BtlvClact *clact, int slot, u8 startLevel, u8 targetLevel, s8 step, u16 color)
{
    u16 mask = 1 << (((u32)CLACT_GetPaletteVramAddress(clact->slot[slot].paletteId, (int)0) & 0x3FF) >> 5);
    PaletteFade *palanm = BTLV_EFFECT_GetPalanm();

    PALANM_RequestFade(palanm, 4, mask, step, startLevel, targetLevel, color, BTLV_EFFECT_GetOwner());
}

static inline int FxFromInt(int x)
{
    if (x > 0) return (int)(0.5f + (float)(x << 12));
    else return (int)((float)(x << 12) - 0.5f);
}

void BTLV_CLACT_StartMoveTask(BtlvClact *clact, int slot, u32 mode, VecFx32 *start, VecFx32 *end, int frames, int waitTicks, int repeats,
                   void (*taskMain)(struct TcbTask *, void *), void (*taskEnd)(void *))
{
    BtlvClactMoveTask *job;
    job = GFL_HEAP_Alloc((u16)((clact->heap & 0x7fff) | 0x8000), sizeof(*job), 0, gBtlvClactFileName, 0x197);
    job->clact = clact;
    job->slot = slot;
    job->pos.x = start->x;
    job->pos.y = start->y;
    job->pos.z = start->z;
    job->mover.mode = mode;
    job->mover.count = frames;
    job->mover.countReset = frames;
    job->mover.wait = 0;
    job->mover.waitReset = waitTicks;
    job->mover.repeat = repeats * 2;
    job->mover.start.x = start->x;
    job->mover.start.y = start->y;
    job->mover.start.z = start->z;
    job->mover.end.x = end->x;
    job->mover.end.y = end->y;
    job->mover.end.z = end->z;
    switch (mode) {
    case 1:
        BTLV_EFFECT_ComputeVectorStep(&job->mover.start, end, &job->mover.step, FxFromInt(frames));
        break;
    case 3:
        job->mover.countReset *= 2;
        job->mover.repeat *= 2;
    case 2:
        job->mover.step.x = FX_Div(end->x, FxFromInt(frames));
        job->mover.step.y = FX_Div(end->y, FxFromInt(frames));
        job->mover.step.z = FX_Div(end->z, FxFromInt(frames));
        break;
    case 0:
    default:
        break;
    }
    BTLV_EFFECT_RegisterTask(TCB_AddTask(clact->owner, taskMain, job, 0), taskEnd, 0);
}

void BTLV_CLACT_MoveTaskMain(struct TcbTask *task, void *work)
{
    BtlvClactMoveTask *job = (BtlvClactMoveTask *)work;
    BtlvClact *clact = job->clact;
    int done = BTLV_EFFECT_StepMover(&job->mover, &job->pos);
    struct ClactVec2 delta;

    delta.x = job->pos.x >> 12;
    delta.y = job->pos.y >> 12;
    CLACT_AddActorSurfacePos(clact->slot[job->slot].actor, &delta, 0);
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_CLACT_MoveTaskEnd(void *task)
{
    BtlvClactMoveTask *job = (BtlvClactMoveTask *)TCBL_GetOwnedWork(task);
    job->clact->moveMask &= (1 << job->slot) ^ -1;
}

void BTLV_CLACT_MoveTaskMainWide(struct TcbTask *task, void *work)
{
    BtlvClactMoveTask *job = (BtlvClactMoveTask *)work;
    BtlvClact *clact = job->clact;
    int done = BTLV_EFFECT_StepMover(&job->mover, &job->pos);
    int scale[2];

    scale[0] = job->pos.x;
    scale[1] = job->pos.y;
    CLACT_SetActorAffineMode(clact->slot[job->slot].actor, 1);
    CLACT_SetActorScale(clact->slot[job->slot].actor, (struct Pair32 *)scale);
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_CLACT_MoveTaskEndWide(void *task)
{
    BtlvClactMoveTask *job = (BtlvClactMoveTask *)TCBL_GetOwnedWork(task);
    job->clact->scaleMask &= (1 << job->slot) ^ -1;
}
