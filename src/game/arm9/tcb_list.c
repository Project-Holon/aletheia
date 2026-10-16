/*
 * file:     tcb_list.c
 * unit:     yes
 * function: TCB_BuildFreeStack, TCB_AllocTask, TCB_FreeTask, TCB_GetTaskOffset, TCB_Init, TCB_Reset, TCB_Main, TCB_Noop, TCB_AddTask, TCB_InsertTask, TCB_DeleteTask
 * address:  0x02030BD4
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
 */
#include "gfl_heap_wrap_shared_types.h"

struct TcbSystem;

struct TcbTask;

/* Task list (priority-sorted, fixed pool of tasks, one callback per task). */
typedef void (*TcbFunc)(struct TcbTask *task, void *work);

struct TcbTask {
    struct TcbSystem *owner;     /* +0x00 */
    struct TcbTask   *prev;      /* +0x04 */
    struct TcbTask   *next;      /* +0x08 */
    u32               priority;  /* +0x0c, ascending order of the list */
    void             *work;      /* +0x10 */
    TcbFunc           func;      /* +0x14 */
    u32               skipOnce;  /* +0x18, set on a task added during a pass that would run in it */
};

struct TcbSystem {
    u32                capacity;       /* +0x00 */
    u32                usedCount;      /* +0x04, tasks taken from the free stack */
    struct TcbTask     sentinel;       /* +0x08 */
    struct TcbTask   **freeStack;      /* +0x24 */
    struct TcbTask    *taskPool;       /* +0x28 */
    u32                isAdding;       /* +0x2c */
    struct TcbTask    *current;        /* +0x30 */
    struct TcbTask    *nextTask;       /* +0x34, successor read before the callback runs */
    struct TcbTask    *freeStackStorage[1]; /* +0x38 */
};

void TCB_BuildFreeStack(struct TcbSystem *sys);

struct TcbTask *TCB_AllocTask(struct TcbSystem *sys);

u32 TCB_FreeTask(struct TcbSystem *sys, struct TcbTask *task);

u32 TCB_GetTaskOffset(u32 idx);

struct TcbSystem *TCB_Init(u32 capacity, struct TcbSystem *sys);

void TCB_Reset(struct TcbSystem *sys);

void TCB_Main(struct TcbSystem *sys);

void TCB_Noop(void);

struct TcbTask *TCB_AddTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);

struct TcbTask *TCB_InsertTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);

void TCB_DeleteTask(struct TcbTask *task);

/*
 * Refill the free stack: every node in the pool is blanked, pointed back at
 * its owner and at the sentinel, and pushed onto the stack in index order, so
 * afterwards the stack holds all `capacity` nodes and the top index is zero.
 * The allocator in src/matched/unit_02030C44.c reads that stack from the top.
 *
 * The node stride is 0x1c, so the pool index is a real `mul` against a hoisted
 * 0x1c, not a shift.  `&sys->taskPool[i]` is recomputed from the field for the
 * free-stack store, and the loop bound re-reads sys->capacity, because the
 * writes through the cursor may alias either pointer.
 *
 * This function is kept in its own file rather than folded into
 * unit_02030C44.c beside it: a unit spanning both records its manifest entry
 * at the unit's own start address, and 0x02030C44 then stops being an
 * attestable address, which costs unit_02030DA8.c its only witness.  See
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_BuildFreeStack.c  *       --func TCB_BuildFreeStack --addr 0x02030BD4 --cc 1.1p1 --arm
 */
void TCB_BuildFreeStack(struct TcbSystem *sys)
{
    struct TcbTask *task;
    u32 i;

    for (i = 0; i < sys->capacity; i++) {
        task = &sys->taskPool[i];
        task->owner = sys;
        task->next = &sys->sentinel;
        task->prev = &sys->sentinel;
        task->priority = 0;
        task->work = 0;
        task->func = 0;
        sys->freeStack[i] = &sys->taskPool[i];
    }
    sys->usedCount = 0;
}

/*
 * Allocate a task from the TCB pool.  Free tasks live in a stack of pointers at
 * sys->freeStack with sys->usedCount the live index: this function hands back the entry
 * at the top and steps up, and 0x02030C68 (src/matched/unit_02030C68.c) steps
 * back down and stores the node there.  It calls nothing, so the unit holds
 * no relocations at all and needs no outside evidence; that is what unblocks
 * src/matched/unit_02030DA8.c, whose only unresolved site was the call to
 * 0x02030C44.
 *
 * 0x02030C68 used to be written out again at the bottom of this file, from
 * when it was still an unlabelled follower and this unit's inferred extent
 * ran to 0x02030CB0.  It is seeded in layout/function_starts.txt now and
 * src/matched/unit_02030C68.c is the manifest entry for it, so the extent
 * here stops at 0x02030C68 and the second body was redundant: two files laid
 * out the same 72 bytes and only one of them could own the address
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * In 0x02030C44 the popped entry is bound to a local before sys->usedCount is stepped:
 * that is the `movne r0, r2` at the end, four bytes that disappear if the
 * subscript is returned directly.  `cmp r3, r1` puts the live top on the
 * left, so the guard is written with sys->usedCount first
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030C44.c \
 *       --addr 0x02030C44 --cc 1.1p1 --arm
 */
struct TcbTask *TCB_AllocTask(struct TcbSystem *sys)
{
    struct TcbTask *task;
    u32 used;

    used = sys->usedCount;
    if (used == sys->capacity) {
        return 0;
    }
    task = sys->freeStack[used];
    sys->usedCount = used + 1;
    return task;
}

/*
 * Push one frame onto the context's stack: fail if the stack is full,
 * otherwise point the frame at the context and at its inline buffer, clear
 * the three counters, and store the frame in the slot the decremented
 * depth names.
 *
 * Filed as a unit, not a single function, because 0x02030C68 saves nothing
 * on entry: disasm.py only auto-labels a prologue that pushes lr, so it
 * put a label on the `mov r0, #1` tail at 0x02030CA8 and the inferred
 * extent stops eight bytes early.  `tu` compares the compiled layout
 * instead and covers 0x02030C68..0x02030CB0.  0x02030CA8 is not a function
 * start and wants removing from layout/function_starts.txt; that file is
 * the integrator's, so this note is the report.
 *
 * The +8 store lands before the pair at +0 and +4 because that is the
 * source order: written ctx, cur, end the compiler emits the `stm` first
 * and the lone `str` last, six bytes apart.
 *
 * Decompiled to unstick src/pending/TCB_DeleteTask.c (fan-in 196), which is
 * this function's only caller image-wide and so had no `label` witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030C68.c \
 *       --addr 0x02030C68 --cc 1.1p1 --arm
 */
u32 TCB_FreeTask(struct TcbSystem *sys, struct TcbTask *task)
{
    if (sys->usedCount == 0) {
        return 0;
    }
    task->next = &sys->sentinel;
    task->owner = sys;
    task->prev = &sys->sentinel;
    task->priority = 0;
    task->work = 0;
    task->func = 0;
    sys->usedCount--;
    sys->freeStack[sys->usedCount] = task;
    return 1;
}

/*
 * Index-to-offset arithmetic: a fixed 0x38-byte header plus 0x20 bytes per
 * element. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_GetTaskOffset.c \
 *       --func TCB_GetTaskOffset --addr 0x02030CB0 --cc 1.1p1
 */
u32 TCB_GetTaskOffset(u32 idx)
{
    return (idx << 5) + 0x38;
}

/*
 * Lay a TCB system out over caller-supplied storage and return it.  The
 * two arrays live in the tail of the block: the free stack of `capacity`
 * node pointers starts at +0x38 and the node pool starts immediately after
 * it, which is what `add r3, r4, #0x38` and `add r2, r3, r0, lsl #2` are.
 * Nothing is allocated here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_Init.c \
 *       --func TCB_Init --addr 0x02030CBC --cc 1.1p1 --arm
 */
struct TcbSystem *TCB_Init(u32 capacity, struct TcbSystem *sys)
{
    sys->capacity = capacity;
    sys->freeStack = sys->freeStackStorage;
    sys->taskPool = (struct TcbTask *)(sys->freeStack + capacity);
    sys->usedCount = 0;
    sys->isAdding = 0;
    TCB_Reset(sys);
    return sys;
}

/*
 * Reset the context: rebuild the free stack over the whole pool (0x02030BD4)
 * and then re-arm the embedded sentinel so the circular list is empty, both
 * links pointing back at the sentinel itself.  The walk cursor at +0x30 is
 * parked on the sentinel, which is the "nothing pending" state the stepper at
 * 0x02030D28 tests for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_Reset.c \
 *       --func TCB_Reset --addr 0x02030CF4 --cc 1.1p1 --arm
 */
void TCB_Reset(struct TcbSystem *sys)
{
    TCB_BuildFreeStack(sys);
    sys->sentinel.owner = sys;
    sys->sentinel.next = &sys->sentinel;
    sys->sentinel.prev = &sys->sentinel;
    sys->sentinel.priority = 0;
    sys->sentinel.work = 0;
    sys->sentinel.func = 0;
    sys->current = &sys->sentinel;
}

/*
 * time_icon.c tail (the task-list runtime).  One pass over the circular
 * callback list at +0x08: unless the +0x2c busy flag is set, walk from
 * head.next to the embedded sentinel through the +0x30 cursor, pre-reading
 * each successor into +0x34 so a callback may unlink its own node, and call
 * each node's callback unless its +0x18 "fired" flag is set (which is
 * cleared instead).  The loop ends with the cursor on the sentinel, whose
 * callback slot is cleared.
 *
 * The documented 13-byte "loop-carried register" residue
 * (docs/notes/TCB_Main.c.txt) was a misread callback arity: the image
 * loads the node into r0 and node->arg into r1 before `blx r2`, so the
 * callback is fn(node, arg), not fn(arg).  With two arguments the body is
 * byte-exact under 1.1p1 -O4,p.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_Main.c \
 *       --func TCB_Main --addr 0x02030D28 --cc 1.1p1 --arm
 */
void TCB_Main(struct TcbSystem *sys)
{
    if (sys->isAdding != 0) {
        return;
    }
    sys->current = sys->sentinel.next;
    while (sys->current != &sys->sentinel) {
        sys->nextTask = sys->current->next;
        if (sys->current->skipOnce == 0) {
            if (sys->current->func != 0) {
                sys->current->func(sys->current, sys->current->work);
            }
        } else {
            sys->current->skipOnce = 0;
        }
        sys->current = sys->nextTask;
    }
    sys->current->func = 0;
}

void TCB_Noop(void){ }

/*
 * Previously capped at MATCH: 0x02030C44 has exactly one caller image-wide,
 * the call inside TCB_InsertTask below, so no `label` witness exists and no cut
 * could free the site.  src/matched/unit_02030C44.c now reproduces the node
 * allocator's own byte range, so the PC24 at +0x34 resolves in the `matched`
 * class and the unit is EXACT.
 *
 * Insert one node into the context's circular list, kept sorted ascending on
 * the key at +0x0C, plus the re-entry wrapper that guards it.
 *
 * The two functions are one unit rather than two files because nothing in
 * the image branches to 0x02030DC8 except the wrapper: as separate files the
 * wrapper's call has no witness of any class and caps at MATCH, while in one
 * translation unit it is `local` and needs no image evidence at all
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md read the
 * other way round).
 *
 * The wrapper takes four parameters, not one.  Its own bytes never set r1,
 * r2 or r3 before the call, which is what forwarding untouched parameters
 * looks like, and the tell is the register the constant 1 lands in: `mov ip,
 * #1` before the call and `mov r1, #0` after it.  With fewer parameters
 * declared, r1 is free on both sides and the compiler uses it twice.
 *
 * The list is doubly linked through +0x04 (prev) and +0x08 (next) with the
 * sentinel embedded in the context at +0x08, which is why `sys->sentinel.prev`
 * is the same word as the context's +0x0C and the loop bound is the address
 * of the sentinel itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030DA8.c \
 *       --addr 0x02030DA8 --arm
 */
struct TcbTask *TCB_AddTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority)
{
    struct TcbTask *task;

    sys->isAdding = 1;
    task = TCB_InsertTask(sys, func, work, priority);
    sys->isAdding = 0;
    return task;
}

struct TcbTask *TCB_InsertTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority)
{
    struct TcbTask *task;
    struct TcbTask *other;

    task = TCB_AllocTask(sys);
    if (task == 0) {
        return 0;
    }
    task->priority = priority;
    task->work = work;
    task->func = func;
    if (sys->current->func != 0) {
        if (sys->current->priority <= priority) {
            task->skipOnce = 1;
        } else {
            task->skipOnce = 0;
        }
    } else {
        task->skipOnce = 0;
    }
    for (other = sys->sentinel.next; other != &sys->sentinel; other = other->next) {
        if (other->priority > task->priority) {
            task->prev = other->prev;
            task->next = other;
            other->prev->next = task;
            other->prev = task;
            if (other == sys->nextTask) {
                sys->nextTask = task;
            }
            return task;
        }
    }
    if (sys->nextTask == &sys->sentinel) {
        sys->nextTask = task;
    }
    task->prev = sys->sentinel.prev;
    task->next = &sys->sentinel;
    sys->sentinel.prev->next = task;
    sys->sentinel.prev = task;
    return task;
}

/*
 * Unlink one node from its owner's doubly-linked list and then tail-call
 * TCB_FreeTask on the owner.  The node carries its owner at +0, its
 * predecessor at +4 and its successor at +8; the owner's list head is at
 * +0x34 and is advanced to the successor when the node being removed is
 * the head.
 *
 * `ldmib r1, {r0, r2}` is the paired load of the two link fields, not an
 * aggregate copy: the head fix-up above it is predicated, so there is no
 * branch anywhere in the function and the scheduler is free to fold the
 * two loads.  The links are then re-loaded for the second unlink store
 * because the first store may alias them.
 *
 * The `mov r1, r0` that opens the function is the arity tell: nothing in
 * the body reads r1, and r1 is not callee-saved, so the only reason to
 * spend an instruction parking the node there is that the tail call
 * needs it as a second argument.  Written as a one-argument call the
 * whole function comes out four bytes shorter with the node left in r0,
 * every concrete byte shifted by one instruction.  See
 * docs/idioms/a-parameter-moved-out-of-r0-at-entry-names-the-tail-calls-arity.md.
 *
 * 0x02030C68 has no branch witness of its own: this function is its only
 * reference image-wide.  The site resolves on class `matched` against
 * src/matched/unit_02030C68.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_DeleteTask.c \
 *       --func TCB_DeleteTask --addr 0x02030EAC --cc 1.1p1 --arm
 */
void TCB_DeleteTask(struct TcbTask *task)
{
    struct TcbSystem *sys = task->owner;

    if (sys->nextTask == task) {
        sys->nextTask = task->next;
    }
    task->prev->next = task->next;
    task->next->prev = task->prev;
    TCB_FreeTask(task->owner, task);
}
