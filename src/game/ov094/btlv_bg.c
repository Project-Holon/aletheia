/*
 * file:     btlv_bg.c
 * unit:     yes
 * function: BTLV_BG_Create, BTLV_BG_Delete, BTLV_BG_SetScroll, BTLV_BG_StartScroll, BTLV_BG_IsScrolling, BTLV_BG_StartScrollJob, BTLV_BG_ScrollTask, BTLV_BG_OnScrollJobEnd, BTLV_BG_ApplyScrollTask
 * address:  0x0220975C
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
 *   BTLV_BG_Create  0x0220975C  thumb  ov094
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   BTLV_BG_Delete 0x0220977C thumb ov094
 *   TCB_AddTask  0x02030DA8  arm
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   BG_SYS_GetScrollX  0x020407E8  arm
 *   BG_SYS_GetScrollY  0x02040804  arm
 *   BTLV_BG_SetScroll  0x02209784  thumb  ov094
 *   BTLV_BG_StartScroll  0x022097CC  thumb  ov094
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BTLV_BG_IsScrolling 0x0220985C thumb ov094
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 *   sBtlvBgSiteName     0x0220AEF0  data  ov094
 *   BTLV_EFFECT_ComputeVectorStep 0x021F918C thumb ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 */
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_bg_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 BG_SYS_GetScrollX(u32 layer);

extern u32 BG_SYS_GetScrollY(u32 layer);

extern float _fflt(int);

extern float _fadd(float, float);

extern float _fsub(float, float);

extern int _ffix(float);

extern void BTLV_EFFECT_RegisterTask(void *task, void (*onDelete)(void *), int arg);

extern void BTLV_EFFECT_DeleteTask(void *task);

/* One scroll animation job (0x4c bytes). Mode 4 adds mover.end to pos every frame (a per-frame step) and ends when mover.count runs out; the other modes run the mover. */
typedef struct BtlvBgScrollJob {
    BtlvBg *bg;                     /* 0x00 */
    BtlvVec3 pos;                   /* 0x04: current scroll offset, 20.12 fixed */
    BtlvMover mover;                /* 0x10 */
} BtlvBgScrollJob;

/* Two arguments carried to the deferred scroll apply task. */
typedef struct { int scrollX, scrollY; } BtlvBgScrollArgs;

extern u32 GFL_HEAP_Free(void *block);

extern void *TCB_AddTask(void *, void (*)(void *, void *), void *, u32);

extern void *GFL_USE_AddMainTask(void (*callback)(void *), void *context, int priority);

extern u32 FX_Div(u32 value, u32 divisor);

extern void BTLV_EFFECT_ComputeVectorStep(const BtlvVec3 *from, const BtlvVec3 *to, BtlvVec3 *outDelta, int frames);

extern int BTLV_EFFECT_StepMover(BtlvMover *mover, BtlvVec3 *outPos);

extern u32 TCBL_IsDeletePending(void *task);

extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 param, u32 value);

BtlvBg *BTLV_BG_Create(void *taskSystem, u16 heapId);

void BTLV_BG_Delete(BtlvBg *bg);

void BTLV_BG_SetScroll(BtlvBg *bg, u32 scrollX, u32 scrollY);

void BTLV_BG_StartScroll(BtlvBg *bg, int flipFlags, u32 mode, int x, int y, int frames, int phaseFrames, int cycleFrames);

unsigned int BTLV_BG_IsScrolling(BtlvBg *bg);

void BTLV_BG_StartScrollJob(BtlvBg *bg, u32 mode, BtlvVec3 *origin, BtlvVec3 *amount, int frames, int phaseFrames, int cycleFrames, void (*onTick)(void *, void *));

void BTLV_BG_ScrollTask(void *task, void *arg);

void BTLV_BG_OnScrollJobEnd(void *task);

void BTLV_BG_ApplyScrollTask(void *task);

extern char sBtlvBgSiteName[];

BtlvBg *BTLV_BG_Create(void *taskSystem, u16 heapId)
{
    BtlvBg *bg = GFL_HEAP_Alloc(heapId, 0xc, 1, sBtlvBgSiteName, 0x48);
    bg->taskSystem = taskSystem;
    bg->heapId = heapId;
    return bg;
}

void BTLV_BG_Delete(BtlvBg *bg)
{
    GFL_HEAP_Free(bg);
}

void BTLV_BG_SetScroll(BtlvBg *bg, u32 scrollX, u32 scrollY)
{
    BtlvBgScrollArgs *args;

    args = GFL_HEAP_Alloc((u16)((bg->heapId & 0x7fff) | 0x8000), 8, 0, sBtlvBgSiteName, 0x67);
    args->scrollX = scrollX;
    args->scrollY = scrollY;
    BTLV_EFFECT_RegisterTask(GFL_USE_AddMainTask(BTLV_BG_ApplyScrollTask, args, 0), 0, 0);
}

void BTLV_BG_StartScroll(BtlvBg *bg, int flipFlags, u32 mode, int x, int y, int frames, int phaseFrames, int cycleFrames)
{
    BtlvVec3 origin;
    BtlvVec3 amount;

    amount.x = x << 12;
    amount.y = y << 12;
    amount.z = 0;
    origin.x = BG_SYS_GetScrollX(3) << 12;
    origin.y = BG_SYS_GetScrollY(3) << 12;
    origin.z = 0;
    if (mode == 4 && (flipFlags & 1))
        amount.x *= -1;
    if (mode == 1) {
        amount.x += origin.x;
        amount.y += origin.y;
        amount.z += origin.z;
    }
    BTLV_BG_StartScrollJob(bg, mode, &origin, &amount, frames, phaseFrames, cycleFrames, BTLV_BG_ScrollTask);
    bg->scrolling = 1;
}

unsigned int BTLV_BG_IsScrolling(BtlvBg *bg)
{
    return bg->scrolling != 0;
}

static inline int BTLV_BG_ToFixedRounded(int value)
{
    if (value > 0) return _ffix(_fadd(0.5f, _fflt(value << 12)));
    else return _ffix(_fsub(_fflt(value << 12), 0.5f));
}

/*
 * lever: matched twin 02201E04 with its unused idx slot removed; this
 *   caller registers fixed callback 02209A40, not a ninth parameter.
 */
void BTLV_BG_StartScrollJob(BtlvBg *bg, u32 mode, BtlvVec3 *origin, BtlvVec3 *amount, int frames, int phaseFrames, int cycleFrames,
                   void (*onTick)(void *, void *))
{
    BtlvBgScrollJob *job;
    job = GFL_HEAP_Alloc(bg->heapId, 0x4c, 0, sBtlvBgSiteName, 0xb8);
    job->bg = bg;
    job->pos.x = origin->x;
    job->pos.y = origin->y;
    job->pos.z = origin->z;
    job->mover.mode = mode;
    job->mover.count = frames;
    job->mover.countReset = frames;
    job->mover.wait = 0;
    job->mover.waitReset = phaseFrames;
    job->mover.repeat = cycleFrames * 2;
    job->mover.start.x = origin->x;
    job->mover.start.y = origin->y;
    job->mover.start.z = origin->z;
    job->mover.end.x = amount->x;
    job->mover.end.y = amount->y;
    job->mover.end.z = amount->z;
    switch (mode) {
    case 1:
        BTLV_EFFECT_ComputeVectorStep(&job->mover.start, amount, &job->mover.step, BTLV_BG_ToFixedRounded(frames));
        break;
    case 3:
        job->mover.countReset *= 2;
        job->mover.repeat *= 2;
    case 2:
        job->mover.step.x = FX_Div(amount->x, BTLV_BG_ToFixedRounded(frames));
        job->mover.step.y = FX_Div(amount->y, BTLV_BG_ToFixedRounded(frames));
        job->mover.step.z = FX_Div(amount->z, BTLV_BG_ToFixedRounded(frames));
        break;
    case 0:
    default:
        break;
    }
    BTLV_EFFECT_RegisterTask(TCB_AddTask(bg->taskSystem, onTick, job, 0), BTLV_BG_OnScrollJobEnd, 0);
}

void BTLV_BG_ScrollTask(void *task, void *arg)
{
    BtlvBgScrollJob *job = (BtlvBgScrollJob *)arg;
    BtlvBg *bg = job->bg;
    int done;

    if (job->mover.mode == 4) {
        job->pos.x += job->mover.end.x;
        job->pos.y += job->mover.end.y;
        if (job->mover.count == 0) {
            done = 1;
        } else {
            job->mover.count--;
            done = 0;
        }
    } else {
        done = BTLV_EFFECT_StepMover(&job->mover, &job->pos);
    }
    BTLV_BG_SetScroll(bg, job->pos.x >> 12, job->pos.y >> 12);
    if (done == 1)
        BTLV_EFFECT_DeleteTask(task);
}

void BTLV_BG_OnScrollJobEnd(void *task)
{
    BtlvBg *bg = *((BtlvBg **)TCBL_IsDeletePending(task));
    bg->scrolling = 0;
}

/*
 * Task callback passed to GFL_USE_AddMainTask by BTLV_BG_SetScroll (leaf of that
 * caller: its pool word 0x02209A55 names this unlabelled Thumb function).
 * Applies the queued scroll values to BG layer 3, then ends the task.
 */
void BTLV_BG_ApplyScrollTask(void *task)
{
    BtlvBgScrollArgs *args = (BtlvBgScrollArgs *)TCBL_IsDeletePending(task);

    BG_SYS_ChangeScrollImmediate(3, 0, args->scrollX);
    BG_SYS_ChangeScrollImmediate(3, 3, args->scrollY);
    BTLV_EFFECT_DeleteTask(task);
}
