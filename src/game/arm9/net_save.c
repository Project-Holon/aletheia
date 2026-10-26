/*
 * file:     net_save.c
 * unit:     yes
 * function: GFL_NET_SAVE_SetStep, GFL_NET_SAVE_Create, GFL_NET_SAVE_CreateWithCallback, GFL_NET_SAVE_CheckFinished, GFL_NET_SAVE_Delete, GFL_NET_SAVE_StepBegin, GFL_NET_SAVE_StepWaitSaveStart, GFL_NET_SAVE_StepWaitSync72, GFL_NET_SAVE_StepDelay, GFL_NET_SAVE_StepWaitSync73, GFL_NET_SAVE_StepProgress, GFL_NET_SAVE_StepFinish, GFL_NET_SAVE_InitWork, GFL_NET_SAVE_Main
 * address:  0x02010888
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * net_save.c: the network save task, the GFL_NET_SAVE_* run at
 * 0x02010888..0x02010B98 that was the tail of the over-merged wih_dwc.c.  Its
 * own __FILE__ anchor names this file: the pool word 0x020A725C points two
 * bytes into the "net_save.c" string at 0x020A7258 (the wih_dwc.c string is at
 * 0x020A7244).  A 0x14-byte task object (NetSaveTask) drives the save state
 * machine: GFL_NET_SAVE_Create/CreateWithCallback allocate it, CheckFinished
 * polls it, and the GFL_NET_SAVE_Step* chain (Begin, WaitSaveStart, WaitSync72,
 * Delay, WaitSync73, Progress, Finish) advances the timing-sync handshake with
 * GAME_DATA_SaveStart/SaveMain.  GFL_NET_SAVE_InitWork and GFL_NET_SAVE_Main
 * are the 0x1D8-byte proc-task side that pushes overlay procs.
 *
 * symbols:
 *   sNetSaveFile     0x020A725C  data
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   GFL_HEAP_Free    0x020307B0  arm
 *   GFL_NET_ERR_GetErrorLevel    0x0200FB24  thumb
 *   GAME_DATA_SaveCancel   0x02012E08  thumb
 *   GAME_DATA_SaveStart    0x02012DAC  thumb
 *   GAME_DATA_SaveMain     0x02012DD0  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle   0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   PROCSYS_PushGlobal     0x020312CC  arm
 *   MI_CpuFill8      0x02082BCC  arm
 *   GAME_DATA_Create     0x020124F4  thumb
 *   GAME_DATA_GetSaveControl     0x02012EBC  thumb
 *   GAME_SYNC_GetBlock     0x02009448  thumb
 *   BLOCK20_SAVEDATA_GetPending  0x020092EC  thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8  thumb
 *   GFL_NET_GetRunState    0x0203CD98  arm
 *   ov115_id         0x00000073  data  a1
 *   ov123_id         0x0000007B  data  a1
 *   gNetSaveMainProc   0x021D6338  data  ov115
 *   gNetSaveCheckProc  0x021DA9A8  data  ov123
 *   gNetSaveRetryProc  0x021D654C  data  ov115
 *   GFL_USE_GetRandom  0x020056EC  thumb
 */

#include "../types.h"

struct Link;
struct SaveControl;
struct GameSyncData;

struct GameData;
/* the 0x14-byte net_save.c task object */
struct NetSaveTask {
    void (*progressCallback)(void *arg);
    void *callbackArg;
    void (*step)(struct NetSaveTask *task);
    struct GameData *gameData;
    s32 delayFrames;
};

#include "net_save_types.h"

#include "gfl_heap_wrap.h"
struct GFLNetHandle;
#include "net_handle.h"
#include "net_err.h"
struct GameData;
#include "game_data.h"
#include "gfl_use.h"
#include "gfl_heap.h"
struct Proc;
#include "procsys.h"
#include "mi_memory.h"
#include "game_sync.h"
struct CgearSaveBlock;
#include "block20_savedata.h"
#include "net.h"

void GFL_NET_SAVE_SetStep(struct NetSaveTask *task, void (*step)(struct NetSaveTask *task));
struct NetSaveTask *GFL_NET_SAVE_Create(u32 heapId, struct GameData *gameData);
struct NetSaveTask *GFL_NET_SAVE_CreateWithCallback(u32 heapId, struct GameData *gameData, void (*callback)(void *arg), void *callbackArg);
u32 GFL_NET_SAVE_CheckFinished(struct NetSaveTask *task);
void GFL_NET_SAVE_Delete(struct NetSaveTask *task);
void GFL_NET_SAVE_StepBegin(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSaveStart(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSync72(struct NetSaveTask *task);
void GFL_NET_SAVE_StepDelay(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSync73(struct NetSaveTask *task);
void GFL_NET_SAVE_StepProgress(struct NetSaveTask *task);
void GFL_NET_SAVE_StepFinish(struct NetSaveTask *task);
int GFL_NET_SAVE_InitWork(void *proc);
int GFL_NET_SAVE_Main(u32 proc, u32 seq, u32 parentWork, struct NetSaveProcWork *work);
extern u8 sNetSaveFile;
extern u8 ov115_id[];
extern u8 ov123_id[];
#include "net_save.h"
extern u8 gNetSaveCheckProc[];

/*
 * Stores the step callback at the task's +8 field.
 */
/*
 * Stores the value at the object's +8 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_SetStep.c \
 *       --func GFL_NET_SAVE_SetStep --addr 0x02010888 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_SetStep(struct NetSaveTask *task, void (*step)(struct NetSaveTask *task))
{
    task->step = step;
}

/*
 * net_save.c task constructors for the 0x14-byte task object, its poll, and
 * the eight-byte tail-call stub GFL_NET_SAVE_Delete (a tail call into the ARM
 * function 0x020307B0).  Both constructors end with the same two statements:
 * the debug allocator GFL_HEAP_Alloc(heap, 0x14, 1, "net_save.c", line)
 * (0x020A725C is two bytes into the "net_save.c" string at 0x020A7258) and
 * GFL_NET_SAVE_SetStep(p, GFL_NET_SAVE_StepBegin).  GFL_NET_SAVE_CheckFinished calls the callback with
 * the object in r0, then tests GFL_NET_ERR_GetErrorLevel()'s result; that call has no
 * argument of its own (r0 still holds the callback's return value).  The
 * two `return 1` arms are written separately and the +0x08 load is re-read
 * after the calls.
 */
/*
 * The whole range 0x0201088C..0x0201093C: two constructors for the same
 * 0x14-byte object, its destructor-or-poll, and the eight-byte tail-call
 * stub that sits between them and GFL_NET_SAVE_StepBegin.
 *
 *   GFL_NET_SAVE_Create   allocator + one stored field (+0x0C)
 *   GFL_NET_SAVE_CreateWithCallback   allocator + three stored fields (+0x00, +0x04, +0x0C)
 *   GFL_NET_SAVE_CheckFinished   fire the +0x08 callback, then two liveness tests
 *   (0x02010934)    `ldr r3, [pc, #0]; bx r3; .word GFL_HEAP_Free`
 *
 * The stub is a real function: `ov119` at 0x021E0C5C and `ov137` at
 * 0x021DF696 both `bl` it.  It carries no label because it has no prologue
 * (disasm.py only labels a function that saves lr), so it is written here as
 * the tail call it is - a void function whose body is one call to the ARM
 * function 0x020307B0 with the object passed through in r0, which is what
 * puts the pool word and the `bx r3` there and what makes the unit's extent
 * end at 0x0201093C.  Since then seeded as a start in
 * layout/function_starts.txt (both callers set r0 to the object at +0xEF8 /
 * their own field before the bl), so the listing labels it GFL_NET_SAVE_Delete.
 *
 * Both constructors end with the same two statements: the SDK debug
 * allocator GFL_HEAP_Alloc(heap, 0x14, 1, "net_save.c", line) - 0x020A725C is
 * two bytes into the "net_save.c" string at 0x020A7258, so the file anchor is
 * net_save.c - and then GFL_NET_SAVE_SetStep(p, GFL_NET_SAVE_StepBegin), which stores the
 * callback into +0x08.  The two pool words per constructor are the file
 * string and that callback address with its Thumb bit, 0x0201093D.
 *
 * GFL_NET_SAVE_CheckFinished calls the callback with the object in r0, then tests
 * GFL_NET_ERR_GetErrorLevel()'s result.  That call is left with no argument of its own:
 * r0 still holds whatever the callback returned, which is what the original
 * does and what a no-argument call in the source produces.  The two `return
 * 1` arms are written separately (two `movs r0, #1` epilogues in the
 * original) and the +0x08 load is re-read after the calls.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201088C.c \
 *       --addr 0x0201088C --thumb
 */
struct NetSaveTask *GFL_NET_SAVE_Create(u32 heapId, struct GameData *gameData)
{
    struct NetSaveTask *task;

    task = GFL_HEAP_Alloc(heapId, sizeof(*task), 1, (const char *)&sNetSaveFile, 0x75);
    task->gameData = gameData;
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8);
    GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepBegin);
    return task;
}

struct NetSaveTask *GFL_NET_SAVE_CreateWithCallback(u32 heapId, struct GameData *gameData, void (*callback)(void *arg), void *callbackArg)
{
    struct NetSaveTask *task;

    task = GFL_HEAP_Alloc(heapId, sizeof(*task), 1, (const char *)&sNetSaveFile, 0x87);
    task->progressCallback = callback;
    task->callbackArg = callbackArg;
    task->gameData = gameData;
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8);
    GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepBegin);
    return task;
}

u32 GFL_NET_SAVE_CheckFinished(struct NetSaveTask *task)
{
    if (task->step != 0)
        task->step(task);
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        if (task->gameData != 0)
            GAME_DATA_SaveCancel(task->gameData);
        return 1;
    }
    if (task->step == 0)
        return 1;
    return 0;
}

void GFL_NET_SAVE_Delete(struct NetSaveTask *task)
{
    GFL_HEAP_Free(task);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepBegin.c \
 *       --func GFL_NET_SAVE_StepBegin --addr 0x0201093C --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepBegin(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8) != 0) {
        GAME_DATA_SaveStart(task->gameData);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepWaitSaveStart);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSaveStart.c \
 *       --func GFL_NET_SAVE_StepWaitSaveStart --addr 0x02010964 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepWaitSaveStart(struct NetSaveTask *task)
{
    if (GAME_DATA_SaveMain(task->gameData) == 1) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x72, 8);
        task->delayFrames = GFL_USE_GetRandom(0x3c);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepWaitSync72);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSync72.c \
 *       --func GFL_NET_SAVE_StepWaitSync72 --addr 0x02010994 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepWaitSync72(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x72, 8) != 0) {
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepDelay);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepDelay.c \
 *       --func GFL_NET_SAVE_StepDelay --addr 0x020109B8 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepDelay(struct NetSaveTask *task)
{
    s32 framesLeft = task->delayFrames - 1;

    task->delayFrames = framesLeft;
    if (framesLeft < 0) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x73, 8);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepWaitSync73);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSync73.c \
 *       --func GFL_NET_SAVE_StepWaitSync73 --addr 0x020109E0 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepWaitSync73(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x73, 8) != 0) {
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepProgress);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepProgress.c \
 *       --func GFL_NET_SAVE_StepProgress --addr 0x02010A04 --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepProgress(struct NetSaveTask *task)
{
    if (task->progressCallback != 0) {
        task->progressCallback(task->callbackArg);
    }
    if (GAME_DATA_SaveMain(task->gameData) == 2) {
        task->gameData = 0;
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x74, 8);
        GFL_NET_SAVE_SetStep(task, GFL_NET_SAVE_StepFinish);
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepFinish.c \
 *       --func GFL_NET_SAVE_StepFinish --addr 0x02010A3C --thumb --cc 1.1p1
 */
void GFL_NET_SAVE_StepFinish(struct NetSaveTask *task)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x74, 8) != 0) {
        GFL_NET_SAVE_SetStep(task, 0);
    }
}

int GFL_NET_SAVE_InitWork(void *proc)
{
    struct NetSaveProcWork *work;
    void *gameData;

    GFL_HEAP_CreateChildHeap(1, 0x67, 0x78000);
    work = PROCSYS_AllocProcWork(proc, sizeof(*work), 0x67);
    MI_CpuFill8(work, 0, sizeof(*work));
    work->heapId = 0x67;
    gameData = GAME_DATA_Create(0x67);
    work->gameData = gameData;
    if (BLOCK20_SAVEDATA_GetPending((struct CgearSaveBlock *)(GAME_SYNC_GetBlock(GAME_DATA_GetSaveControl(gameData)))) != 0) {
        work->state = 1;
        work->skipFinalSave = 1;
    } else {
        work->state = 0;
        work->skipFinalSave = 0;
    }
    return 1;
}

/*
 * The net_save.c save task's per-frame step (state word at +0x1D4): case 0
 * starts overlay 0x73's proc 0x021D6338 on the record, case 1 starts overlay
 * 0x7B's proc on +0x48 unless +0x1C says finished, case 2 hands off to
 * GFL_NET_ERR_ShowScreen(0), case 3 restarts overlay 0x73 with proc 0x021D654C on +0x28
 * or ends the task.  gNetSaveCheckProc lies in the windows of several overlays; the
 * ov123 hint is supported by the proc table bytes there (three Thumb
 * pointers into ov123).
 */
/*
 * history:  was MATCH on evidence only (every concrete byte matched).  Wave 17:
 *           the pooled overlay ids 0x73 / 0x7B (ov115_id, ov123_id) now
 *           resolve as `overlay_id` (id argument of PROCSYS_PushGlobal).  Two
 *           ABS32 sites are left, the overlay-resident proc pointers
 *           0x021D6338 / 0x021D654C, whose only other pool words sit in
 *           GFL_NET_SAVE_ScreenMain's pool (0x02010D84..), which disasm.py prints as
 *           Thumb code, so the literal index misses them.  Seeding those
 *           pools as .word, or a matched referrer, would close both.
 *           Seed round 10: both words are ov115 proc tables (three Thumb
 *           function pointers each, 0x021D6338 -> 0x021D4BFC/4CE4/4D10,
 *           0x021D654C -> 0x021D603C/6104/60D4), loaded with overlay id
 *           0x73 = ov115, not ov021 (docs/sessions/2026-09-23/reports/
 *           wave17_evidence.md).  ov115 declares both starts in
 *           layout/data_objects.txt and the symbols lines carry the ov115
 *           token.  0x021D654C resolves as sole-ref/data (ov115 is the only
 *           overlay with a start there).  0x021D6338 resolves as
 *           sole-ref/self on the ov115 hint; ov021's listing also starts a
 *           block there, so sole-ref/data refuses the contested hint, and the
 *           choice rests on the hint plus the overlay_id 0x73 site in this
 *           same function.  EXACT, seed round 10.
 * evidence: gNetSaveCheckProc lies in the windows of ov016, ov021, ov123, ov125
 *           and ov175, so the ov123 hint needs outside support.  Case 1
 *           passes ov123_id (0x7B, attested `overlay_id`) and this pointer
 *           in one PROCSYS_PushGlobal call; PROCSYS_PushInternal -> PROCSYS_NewProc stores
 *           the id at Proc+4 and the pointer at Proc+0 (ProcData), and
 *           PROCSYS_StepProc loads overlay Proc+4 (GF_OVERLAY_Load) before it
 *           calls any ProcData callback.  So ov123 is resident whenever the
 *           pointer is dereferenced.  Independently, ov123's bytes at
 *           0x021DA9A8 are three Thumb pointers 0x021DA479/0x021DA54D/
 *           0x021DA5D1, each a func_ label in ov123's own listing, while
 *           ov125 has bss there and ov016/ov021/ov175 hold non-pointer
 *           words.  With the hint the site attests as `sole-ref` in ov123.
 *
 * The net_save.c save task's per-frame step (the task record of
 * GFL_NET_SAVE_InitWork; state word at +0x1D4): case 0 starts overlay 0x73's proc
 * 0x021D6338 on the record, case 1 starts overlay 0x7B's proc on +0x48
 * unless +0x1C says finished, case 2 hands off to GFL_NET_ERR_ShowScreen(0), case 3
 * restarts overlay 0x73 with proc 0x021D654C on +0x28 or ends the task.
 * Wave 13: the earlier DIFF read both small pool words as distinct symbols
 * and the size argument as 0x1A8; they are the arguments (0x73, proc, arg).
 */
int GFL_NET_SAVE_Main(u32 proc, u32 seq, u32 parentWork, struct NetSaveProcWork *work)
{
    switch (work->state) {
    case 0:
        work->login.gameData = work->gameData;
        work->login.loginType = 0;
        work->login.loginOption = 1;
        work->login.messageId = 0x32;
        work->login.saveData = work->saveBuf;
        PROCSYS_PushGlobal((uptr)ov115_id, &gNetSaveMainProc, work);
        work->state += 1;
        break;
    case 1:
        if (work->login.result == 1) {
            work->state = 4;
            break;
        }
        work->checkArgs.gameData = work->gameData;
        work->checkArgs.heapId = work->heapId;
        work->checkArgs.saveBuf = work->saveBuf;
        PROCSYS_PushGlobal((uptr)ov123_id, (const ProcData *)gNetSaveCheckProc, &work->checkArgs);
        work->state += 1;
        break;
    case 2:
        if (work->skipFinalSave == 1) {
            work->state = 4;
            break;
        }
        GFL_NET_ERR_ShowScreen(0);
        work->state += 1;
        break;
    case 3:
        if (GFL_NET_GetRunState() == 0 || work->saveFailed == 1) {
            work->login.useSaveData = 1;
            work->state = 0;
            break;
        }
        work->confirm.gameData = work->gameData;
        work->confirm.loginType = 0;
        work->confirm.loginOption = 1;
        PROCSYS_PushGlobal((uptr)ov115_id, &gNetSaveRetryProc, &work->confirm);
        work->state += 1;
        break;
    default:
        return 1;
    }
    return 0;
}
