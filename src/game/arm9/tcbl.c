/*
 * file:     tcbl.c
 * unit:     yes
 * function: TCBL_GetOwnedWork, TCBL_GetTaskSlot, TCBL_PopFreeTask, TCBL_PushFreeTask, TCBL_InitTaskLinks, TCBL_FreeTask, TCBL_GetTaskWork, TCBL_BuildFreeList, TCBL_Create, TCBL_Main, TCBL_Destroy, TCBL_DeleteAllTasks, TCBL_DeleteTask, TCBL_AddTask, TCBL_SetTaskFunc, TCBL_GetWork
 * address:  0x02030EE8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from tcbl.c by tools/splitfile.py.
 *
 * symbols:
 *   tcbl_File              0x020A7834 data
 *   GFL_HEAP_Alloc 0x02030734 arm arm9
 *   GFL_HEAP_Free 0x020307B0 arm arm9
 */
#include "../types.h"

struct TcblSystem;

struct TcblTask;

/* Task list with a work area per task (the "tcbl" system proper). */
typedef void (*TcblFunc)(struct TcblTask *task, void *work);

struct TcblTask {
    struct TcblSystem *owner;
    struct TcblTask   *prev;
    struct TcblTask   *next;
    u32                priority;
    void              *work;
    TcblFunc           func;
};

struct TcblSystem {
    u32                taskCount;
    u32                workSize;
    u16                workHeapId;
    u16                pad_0a;
    u32                reserved0C;
    u32                deletePending;   /* set when the running task asks to be deleted */
    void              *taskTable;
    struct TcblTask    sentinel;
    struct TcblTask   *current;
    struct TcblTask   *freeList;
};

#include "gfl_heap_wrap.h"


u32 TCBL_GetOwnedWork(struct TcblSystem *tcbl);

struct TcblTask *TCBL_GetTaskSlot(struct TcblSystem *tcbl, u32 index);

struct TcblTask *TCBL_PopFreeTask(struct TcblSystem *tcbl);

void TCBL_PushFreeTask(struct TcblSystem *tcbl, struct TcblTask *task);

void TCBL_InitTaskLinks(struct TcblSystem *tcbl, struct TcblTask *task);

void TCBL_FreeTask(struct TcblTask *task);

void *TCBL_GetTaskWork(struct TcblTask *task);

void TCBL_BuildFreeList(struct TcblSystem *tcbl);

struct TcblSystem *TCBL_Create(u16 heapId, u16 workHeapId, u32 taskCount, u32 workSize);

void TCBL_Main(struct TcblSystem *tcbl);

void TCBL_Destroy(struct TcblSystem *tcbl);

void TCBL_DeleteAllTasks(struct TcblSystem *tcbl);

void TCBL_DeleteTask(struct TcblTask *task);

struct TcblTask *TCBL_AddTask(struct TcblSystem *tcbl, TcblFunc func, u32 workSize, u32 priority);

void TCBL_SetTaskFunc(struct TcblTask *task, TcblFunc func);

void *TCBL_GetWork(struct TcblTask *task);

extern const char tcbl_File[];

/*
 * A plain word accessor at offset 0x10. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_GetOwnedWork.c \
 *       --func TCBL_GetOwnedWork --addr 0x02030EE8 --cc 1.1p1
 */
u32 TCBL_GetOwnedWork(struct TcblSystem *tcbl)
{
    return tcbl->deletePending;
}

/*
 * Row address of a stride-`workSize + 0x18` table: `index * (tcbl->workSize + 0x18)
 * + tcbl->taskTable`, the `mla` idiom for an index times a runtime stride plus a
 * base. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_GetTaskSlot.c \
 *       --func TCBL_GetTaskSlot --addr 0x02030EF0 --cc 1.1p1
 */
struct TcblTask *TCBL_GetTaskSlot(struct TcblSystem *tcbl, u32 index)
{
    return (struct TcblTask *)(index * (tcbl->workSize + 0x18) + (uptr)tcbl->taskTable);
}

struct TcblTask *TCBL_PopFreeTask(struct TcblSystem *tcbl)
{
    struct TcblTask *task = tcbl->freeList;

    if (task == 0) {
        return 0;
    }
    tcbl->freeList = task->next;
    if (task->next != 0) {
        task->next->prev = 0;
    }
    return task;
}

/*
 * Doubly linked list push-front: clears the new node's prev, chains it in
 * front of the current head, fixes the old head's back pointer if there
 * was one, and stores the new node as the head. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_PushFreeTask.c \
 *       --func TCBL_PushFreeTask --addr 0x02030F34 --cc 1.1p1
 */
void TCBL_PushFreeTask(struct TcblSystem *tcbl, struct TcblTask *task)
{
    struct TcblTask *oldHead = tcbl->freeList;

    task->prev = 0;
    task->next = oldHead;
    if (oldHead != 0) {
        oldHead->prev = task;
    }
    tcbl->freeList = task;
}

/*
 * Reset one task-callback node to the "not in the live list" state: owner
 * back-pointer, both links parked on the manager's sentinel at +0x18, and
 * the three payload words cleared.  It is the shape TCB_FreeTask has for the
 * TCB task pool in src/matched/unit_02030C44.c, one layer up.
 *
 * A leaf: no lr is saved, so disasm.py gives it no label of its own and the
 * function is only visible by address
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md does not apply
 * here only because the callers name it).
 *
 * The owner and the prev link are one `stm r1, {r0, r3}`, which is what two
 * adjacent word stores of two already-live registers collapse to; the zero is
 * materialised between them, filling the load slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_InitTaskLinks.c \
 *       --func TCBL_InitTaskLinks --addr 0x02030F50 --cc 1.1p1 --arm
 */
void TCBL_InitTaskLinks(struct TcblSystem *tcbl, struct TcblTask *task)
{
    task->owner = tcbl;
    task->prev = &tcbl->sentinel;
    task->next = &tcbl->sentinel;
    task->priority = 0;
    task->work = 0;
    task->func = 0;
}

/*
 * Destroy one task-callback node: release the work block the registrar
 * allocated for it at +0x10 (if it owns one), clear the callback so a walk
 * already inside TCBL_Main cannot call it again, unlink it from the
 * manager's circular list and push it back on the free list.
 *
 * The callback is cleared before the free rather than after, which is what
 * fixes the `mov r1, #0` / `str r1, [r4, #0x14]` ahead of the guard: written
 * after the call, the store lands past the branch and the zero is
 * rematerialised.
 *
 * The unlink is `ldmib r4, {r0, r2}` for the first store and then two fresh
 * loads of the same two fields for the second: the store through r0 may
 * alias the node's own links, so the compiler reloads
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md read the
 * other way round).  Writing the pair into locals first collapses the
 * reloads and loses eight bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_FreeTask.c \
 *       --func TCBL_FreeTask --addr 0x02030F70 --cc 1.1p1 --arm
 */
void TCBL_FreeTask(struct TcblTask *task)
{
    task->func = 0;
    if (task->work != 0) {
        GFL_HEAP_Free(task->work);
    }
    task->prev->next = task->next;
    task->next->prev = task->prev;
    TCBL_PushFreeTask(task->owner, task);
}

/*
 * Returns a stored pointer at +0x10, or the address of an embedded object
 * at +0x18 when that pointer is null: the "owned or embedded" accessor
 * shape. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_GetTaskWork.c \
 *       --func TCBL_GetTaskWork --addr 0x02030FB4 --cc 1.1p1
 */
void *TCBL_GetTaskWork(struct TcblTask *task)
{
    void *work = task->work;

    if (work == 0) {
        work = task + 1;
    }
    return work;
}

/*
 * Build the free list of the task-control-block pool: walk every row of the
 * stride table, self-link it (TCBL_InitTaskLinks) and push it on the free list
 * (TCBL_PushFreeTask).  The row address comes from TCBL_GetTaskSlot, already matched
 * as `index * (tcbl->workSize + 0x18) + tcbl->taskTable`.
 *
 * The count is re-read from +0x00 at the bottom of the loop, which is what
 * a plain field read in the loop condition compiles to; a cached local
 * would have kept it in a register and cost a push.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_BuildFreeList.c \
 *       --func TCBL_BuildFreeList --addr 0x02030FC8 --cc 1.1p1 --arm
 */
void TCBL_BuildFreeList(struct TcblSystem *tcbl)
{
    u32 i;

    for (i = 0; i < tcbl->taskCount; i++) {
        struct TcblTask *task = TCBL_GetTaskSlot(tcbl, i);
        TCBL_InitTaskLinks(tcbl, task);
        TCBL_PushFreeTask(tcbl, task);
    }
}

/*
 * Constructor of the task-callback list (tcbl.c).  A 0x38-byte manager is
 * allocated first, then the row table: stride is the work size rounded up
 * to a word plus the 0x18-byte node header, times the row count, which is
 * the same stride TCBL_GetTaskSlot recomputes when indexing the table.
 *
 * The rounded stride is derived from the parameter, not re-read from the
 * field just stored at +0x04: the original stores r6 unchanged and then
 * does `add r1, r6, #3 / bic r1, r1, #3` on the same register, with no
 * reload in between.
 *
 * TCBL_BuildFreeList builds the free list out of the table, and TCBL_InitTaskLinks
 * self-links the sentinel node embedded at +0x18, after which +0x30 (the
 * walk cursor) is cleared.
 *
 * 0x020A7834 is the allocation-site pointer this translation unit passes as
 * the allocator's fourth argument, the tcbl.c anchor in
 * layout/file_anchors.txt; the fifth argument is the u16 tag, here 199 and
 * 207.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_Create.c \
 *       --func TCBL_Create --addr 0x0203101C --cc 1.1p1 --arm
 */
struct TcblSystem *TCBL_Create(u16 heapId, u16 workHeapId, u32 taskCount, u32 workSize)
{
    struct TcblSystem *tcbl;

    tcbl = GFL_HEAP_Alloc(heapId, sizeof(struct TcblSystem), 0, tcbl_File, 199);
    tcbl->taskCount = taskCount;
    tcbl->workSize = workSize;
    tcbl->workHeapId = workHeapId;
    tcbl->reserved0C = 0;
    tcbl->deletePending = 0;
    tcbl->taskTable = GFL_HEAP_Alloc(heapId, (((workSize + 3) & ~3) + 0x18) * taskCount, 0,
                                   tcbl_File, 207);
    tcbl->freeList = 0;
    TCBL_BuildFreeList(tcbl);
    TCBL_InitTaskLinks(tcbl, &tcbl->sentinel);
    tcbl->current = 0;
    return tcbl;
}

/*
 * Run one pass over the task-callback list: for every node still linked to
 * the sentinel at +0x18, clear the manager's "current node was destroyed"
 * flag at +0x10, invoke the node's callback at +0x14 with the node and its
 * work area (TCBL_GetTaskWork, the "owned or embedded" accessor), then advance.
 * If the callback set the flag, the node is unlinked and returned to the
 * free list by TCBL_FreeTask, so its successor has to be read out before the
 * call.
 *
 * The walk cursor lives in the manager at +0x30 rather than in a local, so
 * a callback that destroys a *different* node can fix it up; it is cleared
 * on both exits, which is why this is a `while` and not a `do`/`while`: the
 * empty-list arm branches to the same tail.
 *
 * The loop is carried by a local that is refreshed from +0x30 at the bottom
 * of the body, *and* the body re-reads +0x30 into its own local at the top.
 * Written as a bare `while (p->cursor != s)` with `n = p->cursor` inside,
 * the compiler common-subexpressions the two reads and the body top becomes
 * a register copy, four bytes short; see
 * docs/idioms/a-loop-carried-local-beside-a-re-read-field-keeps-both-loads.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_Main.c \
 *       --func TCBL_Main --addr 0x020310C4 --cc 1.1p1 --arm
 */
void TCBL_Main(struct TcblSystem *tcbl)
{
    struct TcblTask *sentinel = &tcbl->sentinel;
    struct TcblTask *cur;

    cur = sentinel->next;
    tcbl->current = cur;
    while (cur != sentinel) {
        struct TcblTask *task = tcbl->current;

        tcbl->deletePending = 0;
        task->func(task, TCBL_GetTaskWork(task));
        if (tcbl->deletePending == 0) {
            tcbl->current = tcbl->current->next;
        } else {
            struct TcblTask *next = tcbl->current->next;
            TCBL_FreeTask(tcbl->current);
            tcbl->current = next;
        }
        cur = tcbl->current;
    }
    tcbl->current = 0;
}

/*
 * Destructor of the task-callback manager: free the task table at +0x14,
 * then the manager block itself, both through the heap free
 * GFL_HEAP_Free.  (layout/symbols_sdk.json offers the name
 * ENV_SetResourceSet for 0x020307B0; it is a signature-matcher guess and the
 * role here is the heap free, so the call goes to the local definition.)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_Destroy.c \
 *       --func TCBL_Destroy --addr 0x02031140 --cc 1.1p1
 */
void TCBL_Destroy(struct TcblSystem *tcbl)
{
    GFL_HEAP_Free(tcbl->taskTable);
    GFL_HEAP_Free(tcbl);
}

/*
 * Destroy every node still registered with the manager.  The walk cursor at
 * +0x30 is published on each step for the same reason TCBL_Main publishes
 * it: a callback destroying itself through TCBL_DeleteTask compares against it.
 *
 * The successor is read out before the call because TCBL_FreeTask unlinks the
 * node and pushes it on the free list, so its own +0x08 is no longer the
 * list's.  The cursor store follows the advance rather than preceding it,
 * which is what puts `mov r0, r5` before `str r5, [r6, #0x30]`.
 *
 * Unlike TCBL_Main the cursor is not cleared on exit: the loop leaves the
 * sentinel's own address parked there.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_DeleteAllTasks.c \
 *       --func TCBL_DeleteAllTasks --addr 0x0203115C --cc 1.1p1 --arm
 */
void TCBL_DeleteAllTasks(struct TcblSystem *tcbl)
{
    struct TcblTask *sentinel;
    struct TcblTask *cur;
    struct TcblTask *next;

    sentinel = &tcbl->sentinel;
    cur = sentinel->next;
    tcbl->current = cur;
    while (cur != sentinel) {
        next = cur->next;
        TCBL_FreeTask(cur);
        cur = next;
        tcbl->current = next;
    }
}

/*
 * The public "unregister this node" entry.  A node that asks to be destroyed
 * while the dispatcher is standing on it cannot be unlinked here, because
 * TCBL_Main still has to read its successor: the request is deferred by
 * setting the manager's flag at +0x10, which the dispatcher tests after every
 * callback and turns into the TCBL_FreeTask call itself.  Any other node goes
 * straight through.
 *
 * The owner is reached through the node's own +0x00 back-pointer, which is
 * what TCBL_InitTaskLinks planted there, so the caller does not have to know the
 * manager.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_DeleteTask.c \
 *       --func TCBL_DeleteTask --addr 0x02031194 --cc 1.1p1 --arm
 */
void TCBL_DeleteTask(struct TcblTask *task)
{
    struct TcblSystem *tcbl;

    tcbl = task->owner;
    if (tcbl->current == task) {
        tcbl->deletePending = 1;
        return;
    }
    TCBL_FreeTask(task);
}

/*
 * The task-callback registrar: take a node off the free list, stamp the
 * callback and its sort key into it, give it a work area and splice it into
 * the manager's circular list in ascending key order.
 *
 * The work area is the row the constructor already reserved unless the caller
 * asks for more than the manager's own stride at +0x04, in which case a block
 * is allocated here and the pointer is parked at +0x10; TCBL_GetTaskWork is the
 * accessor that picks between the two, and TCBL_FreeTask frees exactly the
 * pointer this function may have stored.
 *
 * EXACT*, not EXACT: the eight bytes at 0x02031288 (`str r1, [r0, #0x14]`
 * then `bx lr`, the setter for a node's callback field) save no lr, so
 * disasm.py gives them no label and this function's inferred extent runs past
 * its own two pool words to 0x02031290, where the already-matched veneer
 * src/matched/TCBL_GetWork.c starts
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The extra
 * bytes compare equal; seeding 0x02031288 into layout/function_starts.txt is
 * the integrator's call and the witness is the pool that closes this function
 * at 0x02031288.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_AddTask.c \
 *       --func TCBL_AddTask --addr 0x020311B8 --cc 1.1p1 --arm
 */
struct TcblTask *TCBL_AddTask(struct TcblSystem *tcbl, TcblFunc func, u32 workSize,
                              u32 priority)
{
    struct TcblTask *task;
    struct TcblTask *cur;
    struct TcblTask *sentinel;

    sentinel = &tcbl->sentinel;
    task = TCBL_PopFreeTask(tcbl);
    if (task == 0) {
        return 0;
    }
    task->priority = priority;
    task->func = func;
    if (workSize > tcbl->workSize) {
        task->work = GFL_HEAP_Alloc(tcbl->workHeapId, workSize, 0, tcbl_File, 325);
    } else {
        task->work = 0;
    }
    for (cur = sentinel->next; cur != sentinel; cur = cur->next) {
        if (cur->priority > task->priority) {
            task->prev = cur->prev;
            task->next = cur;
            cur->prev->next = task;
            cur->prev = task;
            return task;
        }
    }
    task->prev = tcbl->sentinel.prev;
    task->next = &tcbl->sentinel;
    tcbl->sentinel.prev->next = task;
    tcbl->sentinel.prev = task;
    return task;
}

void TCBL_SetTaskFunc(struct TcblTask *task, TcblFunc func){ task->func = func; }

/*
 * A four-instruction tail call to TCBL_GetTaskWork (src/matched/TCBL_GetTaskWork.c,
 * this same packet), one section back. The mwccarm one-section-per-function
 * rule means even a same-file neighbour is reached through a pool word and
 * `bx`; see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_GetWork.c \
 *       --func TCBL_GetWork --addr 0x02031290 --cc 1.1p1
 */
void *TCBL_GetWork(struct TcblTask *task)
{
    return TCBL_GetTaskWork(task);
}
