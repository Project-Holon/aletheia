/*
 * file:     tcbl.c
 * unit:     yes
 * function: func_020306F0, func_02030734, func_020307B0, func_020307C8, func_020307E0, func_02030830, func_0203084C, func_02030880, func_020308B8, func_02030958, func_02030984, func_020309B8, func_02030A00, func_02030A2C, func_02030A5C, func_02030A7C, func_02030B50, func_02030BA4, func_02030BBC, func_02030BC8, sub_02030BD4, func_02030C44, func_02030C68, func_02030CB0, func_02030CBC, sub_02030CF4, func_02030D28, func_02030DA4, func_02030DA8, func_02030DC8, func_02030EAC, TCBL_GetTaskUserData, TCBL_GetTaskSlot, TCBL_PopFreeTask, TCBL_PushFreeTask, TCBL_InitTaskLinks, TCBL_FreeTask, TCBL_GetTaskWork, TCBL_BuildFreeList, TCBL_Create, TCBL_Main, TCBL_Destroy, TCBL_DeleteAllTasks, TCBL_DeleteTask, TCBL_AddTask, TCBL_SetTaskFunc, TCBL_GetWork
 * address:  0x020306F0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Delete           0x0202FF98 arm
 *   GFL_HEAP_GetLastError          0x02030524 arm
 *   OS_Terminate           0x02088234 arm
 *   sub_02030098           0x02030098 arm
 *   MIi_CpuClear32         0x02082A7C arm
 *   GFL_HEAP_FreeMemory          0x02030164 arm
 *   GFL_HEAP_InitAllocator          0x02030238 arm
 *   sub_020302A4           0x020302A4 arm
 *   sub_02030344           0x02030344 arm
 *   sub_020304CC           0x020304CC arm
 *   sub_020304C0           0x020304C0 arm
 *   sub_02030428           0x02030428 arm
 *   NNSi_FndGetListTotalSize          0x02060E6C arm
 *   NNSi_FndGetListAllocatableSize          0x02060E94 arm
 *   sub_020304B8           0x020304B8 arm
 *   sub_0203046C           0x0203046C arm
 *   NNSi_FndGetMBlockSize          0x02060F90 arm
 *   func_0203F004          0x0203F004 arm
 *   MI_CpuCopy8            0x02082D44 arm
 *   sub_020303D8           0x020303D8 arm
 *   sub_0203038C           0x0203038C arm
 *   func_0209128C          0x0209128C arm
 *   NNSi_FndWalkHeapBlocks          0x02060F50 arm
 *   func_02030534          0x02030534 arm
 *   GFL_HEAP_AllocSystem          0x020305C4 arm
 *   GFL_HEAP_FreeSystem           0x020305E4 arm
 *   gWatchedHeapId         0x020A7820 data
 *   gHeapBlockReport       0x02146970 data
 *   gHeapBlockReportName   0x0214697C data
 *   kSystemAllocName       0x020A7824 data
 *   tcbl_File              0x020A7834 data
 */
struct Heap;
struct TcbSystem;
struct TcbTask;
struct TcblSystem;
struct TcblTask;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned char u8;

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

/* Header of a heap block: the allocation site stored at header+4. */
struct HeapBlockSite {
    char name[0x12];
    u16  tag;
};

/* Report on the last block visited by the heap walk. */
struct HeapBlockReport {
    u16 tag;
    u16 pad_02;
    void *payload;
    u32 blockSize;
    char name[0x13];
};

/* Callback of the heap block walker. */
typedef void (*HeapVisitFunc)(void *block, int *heap, u32 userParam);

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

extern u32  GFL_HEAP_Delete(u32 heapId);
extern u16  GFL_HEAP_GetLastError(void);
extern void OS_Terminate(void);
extern void *sub_02030098(u32 heapId, u32 size);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern u32 GFL_HEAP_FreeMemory(void *p);
extern u32 GFL_HEAP_InitAllocator(void *p, u32 heapId, s32 size);
extern u32 sub_020302A4(void *p, u32 size);
extern void *sub_02030344(u32 heapId);
extern u32 sub_020304CC(u32 heapId);
extern void *sub_020304C0(void *p);
extern void *sub_02030428(u32 heapId);
extern int NNSi_FndGetListTotalSize(int *p);
extern s32 NNSi_FndGetListAllocatableSize(struct Heap *heap, s32 x);
extern u16 sub_020304B8(void *p);
extern u16 sub_0203046C(u32 heapId);
extern int NNSi_FndGetMBlockSize(char *p);
extern u32 func_0203F004(const u8 *s);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32 sub_020303D8(u32 heapId);
extern void *sub_0203038C(u32 heapId);
extern void func_0209128C(int x);
extern void NNSi_FndWalkHeapBlocks(int *heap, HeapVisitFunc visitor, u32 userParam);
extern signed int func_02030534(u32 size);
extern void *GFL_HEAP_AllocSystem(u32 size);
extern int GFL_HEAP_FreeSystem(u32 idx);
void func_020306F0(u32 heapId);
void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 sub_020307B0(void *block);
void func_020307C8(void *block, u32 heapId, s32 newSize);
void sub_020307E0(void *block, u32 size);
void *sub_02030830(u32 heapId);
void *sub_0203084C(u32 heapId);
void sub_02030880(void *payload, const char *site, u16 tag);
int sub_020308B8(u8 *nameBuf, const char *blockName);
void sub_02030958(u32 heapId, u32 size, const char *site, int tag);
void sub_02030984(void *payload, u32 size);
void sub_020309B8(void *payload);
void sub_02030A00(u32 heapId, void *payload, u32 size);
void sub_02030A2C(void *payload);
void sub_02030A5C(u32 heapId);
void func_02030A7C(void *block, int *heap, u32 userParam);
void func_02030B50(u32 heapId);
void func_02030BA4(u32 size);
void *sub_02030BBC(u32 size);
int sub_02030BC8(u32 idx);
void sub_02030BD4(struct TcbSystem *sys);
struct TcbTask *sub_02030C44(struct TcbSystem *sys);
u32 func_02030C68(struct TcbSystem *sys, struct TcbTask *task);
u32 sub_02030CB0(u32 idx);
struct TcbSystem *sub_02030CBC(u32 capacity, struct TcbSystem *sys);
void sub_02030CF4(struct TcbSystem *sys);
void func_02030D28(struct TcbSystem *sys);
void func_02030DA4(void);
struct TcbTask *sub_02030DA8(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);
struct TcbTask *sub_02030DC8(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);
void sub_02030EAC(struct TcbTask *task);
u32 TCBL_GetTaskUserData(struct TcblSystem *tcbl);
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
extern s32 gWatchedHeapId;
extern struct HeapBlockReport gHeapBlockReport;
extern char gHeapBlockReportName[0x13];
extern const char kSystemAllocName[];
extern const char tcbl_File[];


/*
 * Heap teardown: run the pre-destroy hook, then destroy.  On failure ask
 * sub_02030524 for the current error policy and terminate under policies 1
 * and 2, the same policy read the rest of the heap layer does (see
 * src/matched/sub_0203084C.c, which spells the complementary
 * `!= 1 && != 2 && == 3` shape).
 *
 * The two arms each carry their own `bl OS_Terminate` and their own
 * epilogue rather than sharing one: that is what an `else if` chain of two
 * equality tests gives here, and it is also the evidence that the compiler
 * was not told OS_Terminate is noreturn, since a `pop` follows each call.
 *
 * The two arms must be a `switch`, not an `else if` chain.  Written as two
 * equality `if`s the compiler inlines the first arm on the fall-through
 * path (`bne` over a `bl`/`pop` pair) and the function comes out 64 bytes
 * instead of 68; the switch is what pushes both arms past the shared
 * `pop {r4, pc}` and leaves two forward `beq`s.
 *
 * The PC24 at +0x10 (GFL_HEAP_Delete) has no `label` witness: func_020306F0
 * is 0x0202FF98's only caller image-wide, and the two are not contiguous,
 * so no unit can make the site `local` either.  It resolves on class
 * `matched` against src/matched/GFL_HEAP_Delete.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020306F0.c \
 *       --func func_020306F0 --addr 0x020306F0 --cc 1.1p1 --arm
 */
void func_020306F0(u32 heapId)
{
    sub_02030A5C(heapId);

    if (GFL_HEAP_Delete(heapId) == 0) {
        u32 errorPolicy = GFL_HEAP_GetLastError();

        switch (errorPolicy) {
        case 1:
            OS_Terminate();
            break;
        case 2:
            OS_Terminate();
            break;
        }
    }
}









/*
 * The allocation entry point of the game's heap layer, and the highest-
 * radiation function in the image: 1163 branch references from arm9 and
 * the overlays. Every object constructor in the game that wants memory
 * goes through this wrapper rather than calling the raw allocator at
 * 0x02030098 directly.
 *
 *   void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                      u16 tag)
 *
 * Previously capped at MATCH: all 124 concrete bytes were correct but four
 * of the seven relocation sites had no witness, each target's only branch
 * reference in the image being the call inside this function. All four are
 * now EXACT and attest this file by the `matched` class:
 *
 *   0x02030098  the raw allocator            src/matched/sub_02030098.c
 *   0x02030880  provenance stamp             src/matched/sub_02030880.c
 *   0x02030958  out-of-memory reporter       src/matched/sub_02030958.c
 *   0x02030A00  watched-allocation hook      src/matched/sub_02030A00.c
 *
 * The fifth argument is a u16 delivered on the stack; with six registers
 * pushed it lands at [sp, #0x18], and the callee reads it back with a
 * halfword load rather than a word load, which is what pins its type.
 * It is carried, together with the fourth argument, into the success-side
 * bookkeeping call sub_02030880, which stamps the pair into the 0x1c-byte
 * block header the raw allocator reserved: the string goes into the
 * 0x12-byte name field at header+4 and the tag into the halfword at
 * header+0x16. It is *not* the classic __FILE__/__LINE__ pair: the sites
 * that call this pass addresses above the arm9 static image end
 * (0x020A6800 per layout/layout.json), i.e. BSS globals, not string
 * constants. See src/matched/STRBUF_Create.c for a worked caller.
 *
 * Shape notes:
 *
 *  - The raw allocator sub_02030098 reads only r0 and r1, so this call
 *    forwards only heapId and size; r2 and r3 arriving unchanged from
 *    this function's own prologue are leftovers, the shape of
 *    docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md.
 *    The same is true of the failure reporter: sub_02030958 reads only
 *    r0, so the site and tag registers set up for it are leftovers too,
 *    and the four-parameter declaration below is kept only because it is
 *    what the original call site's register setup looks like.
 *  - The failure arm is the fall-through, so it is written first
 *    (docs/idioms/the-fall-through-arm-is-the-source-order.md). It calls
 *    sub_02030524 with no arguments, reports, then OS_Terminate; the
 *    branch to the shared `return p` tail after OS_Terminate shows the
 *    compiler was not told OS_Terminate is noreturn.
 *  - The clear flag guards MIi_CpuClear32(0, p, size), which is why a
 *    caller that wants zeroed memory passes a non-zero third argument
 *    rather than clearing at the call site.
 *
 * layout/symbols_sdk.json offers the names GX_GetBankForBGExtPltt for
 * 0x02030524 and ENV_SetResourceSet for 0x020307B0. Both are
 * signature-matcher guesses with large sibling sets (37 and 8
 * respectively) and neither fits the role played here, so the canonical
 * sub_ names are used. MIi_CpuClear32 and OS_Terminate have no such
 * ambiguity and keep their SDK names.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030734.c \
 *       --func sub_02030734 --addr 0x02030734 --cc 1.1p1 --arm
 */
void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag)
{
    void *block;

    block = sub_02030098(heapId, size);
    if (block == 0) {
        GFL_HEAP_GetLastError();
        sub_02030958(heapId, size, site, tag);
        OS_Terminate();
    } else {
        sub_02030880(block, site, tag);
        sub_02030A00(heapId, block, size);
        if (clear != 0) {
            MIi_CpuClear32(0, block, size);
        }
    }
    return block;
}









/*
 * The release counterpart of sub_02030734, and the second-highest-radiation
 * function of the heap layer: 904 branch references image-wide.  It runs the
 * watched-allocation bookkeeping first (sub_02030A2C, which reads the block
 * header the raw allocator stamped) and then hands the pointer to the raw
 * free at 0x02030164, which walks back over the 0x1c-byte header.
 *
 * The pointer has to survive the first call, which is the whole reason for
 * the `push {r4, lr}` and the `mov r0, r4` before the second: with the calls
 * the other way round the parameter would still be in r0 and the function
 * would be a pair of tail calls.
 *
 * layout/symbols_sdk.json offers the name ENV_SetResourceSet for this
 * address.  It is a signature-matcher guess with eight siblings, and the role
 * here is plainly the heap free, so the canonical sub_ name is used; see the
 * same note in src/matched/sub_02030734.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020307B0.c \
 *       --func sub_020307B0 --addr 0x020307B0 --cc 1.1p1 --arm
 */
u32 sub_020307B0(void *block)
{
    sub_02030A2C(block);
    return GFL_HEAP_FreeMemory(block);
}









void func_020307C8(void *block, u32 heapId, s32 newSize)
{
    if (GFL_HEAP_InitAllocator(block, heapId, newSize) == 0) {
        OS_Terminate();
    }
}









/*
 * BLOCKED on one relocation site: all 80 concrete bytes are correct, but
 * the call to sub_020302A4 at +0004 has no witness, that call being
 * 0x020302A4's only branch reference in the image. 0x020302A4 is written
 * and byte-correct in src/pending/sub_020302A4.c but is itself capped at
 * MATCH on sub_02060CD0, so the chain is
 * 0x02060CD0 -> 0x020302A4 -> this function: one EXACT entry for
 * 0x02060CD0 promotes all three.
 *
 * A heap-state assertion, guarded on the result of sub_020302A4 and then
 * dispatched on the heap-layer state word returned by sub_02030524.
 *
 *   void sub_020307E0(void *p, u32 size)
 *
 * Neither call takes an argument. The dispatch is the ARM form of the
 * dense switch: `cmp r0, #5` then `addls pc, pc, r0, lsl #2`, so the table
 * runs from case 0 to case 5 inclusive and the fall-through past the
 * `addls` is the default. Every case body here is one instruction, so the
 * bodies live directly in the table slots rather than being branched to:
 * cases 0, 4 and 5 are the bare `pop`, cases 1, 2 and 3 are branches to
 * three separate `bl OS_Terminate; pop` blocks further down.
 *
 * Those three blocks are byte-identical and are *not* cross-jumped, which
 * is the interesting part: writing the three arms as one shared arm
 * (`case 1: case 2: case 3:`) collapses them into a single block and loses
 * sixteen bytes. Each arm must be spelled out separately. The likely
 * original is three distinct assertion messages that the release build
 * stripped down to the same call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020307E0.c \
 *       --func sub_020307E0 --addr 0x020307E0 --cc 1.1p1 --arm
 */
void sub_020307E0(void *block, u32 size)
{
    if (sub_020302A4(block, size) != 0) {
        return;
    }
    switch (GFL_HEAP_GetLastError()) {
    case 0:
        break;
    case 1:
        OS_Terminate();
        break;
    case 2:
        OS_Terminate();
        break;
    case 3:
        OS_Terminate();
        break;
    case 4:
        break;
    case 5:
        break;
    }
}









/*
 * Asserting wrapper around sub_02030344: forwards its single argument,
 * terminates if the result is NULL, and hands the result back either way.
 *
 *   void *sub_02030830(u32 heapId)
 *
 * The `movs r4, r0` that both saves and tests the result is the tell that
 * the value is bound to a local before being compared, not compared as a
 * call expression; the value has to survive the OS_Terminate call, which
 * is what spends r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030830.c \
 *       --func sub_02030830 --addr 0x02030830 --cc 1.1p1 --arm
 */
void *sub_02030830(u32 heapId)
{
    void *heapHead;

    heapHead = sub_02030344(heapId);
    if (heapHead == 0) {
        OS_Terminate();
    }
    return heapHead;
}









/*
 * Promoted from MATCH with no change to the C. The call to sub_020304CC at
 * +0004 was the one unresolved site: 0x020304CC's only branch reference in
 * the image is this call, so no `label` witness exists. It closed when
 * src/matched/sub_020304CC.c landed EXACT, which makes the site `matched`.
 *
 * Asserting wrapper around sub_020304CC, the same shape as sub_02030830
 * but with the assertion itself gated on the heap-layer state word.
 *
 *   void *sub_0203084C(u32 heapId)
 *
 * The guard is one three-term conjunction, and the way it splits across
 * the instructions is what pins that reading: `cmp r0, #1` / `cmpne r0,
 * #2` is the conditional-compare fold of the first two terms into a single
 * `beq`, and the third term gets its own `cmp r0, #3` / `bne`. The third
 * term subsumes the first two, so as written the test is just `state ==
 * 3`; the compiler does not simplify it, and writing only `state == 3`
 * loses the first two comparisons and eight bytes. The redundancy is
 * evidence that the original spelled three named state constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203084C.c \
 *       --func sub_0203084C --addr 0x0203084C --cc 1.1p1 --arm
 */
void *sub_0203084C(u32 heapId)
{
    void *heapHead;
    u32 errorPolicy;

    heapHead = (void *)sub_020304CC(heapId);
    if (heapHead == 0) {
        errorPolicy = GFL_HEAP_GetLastError();
        if (errorPolicy != 1 && errorPolicy != 2 && errorPolicy == 3) {
            OS_Terminate();
        }
    }
    return heapHead;
}









/*
 * Success-side bookkeeping for the allocation entry point sub_02030734:
 * stamps the allocation-site provenance pair (name string, u16 tag) into
 * the block header of a freshly allocated payload.
 *
 *   void sub_02030880(void *p, const char *site, u16 tag)
 *
 * sub_020304C0 (already EXACT) converts the payload pointer into
 * `&((char *)p - 0x1c)[4]`, so the provenance record lives at header+4 and
 * is 0x14 bytes wide: an 0x12-byte name field followed by the u16 tag at
 * +0x12. The copy is a bounded strncpy-shaped loop that stops on the NUL
 * but, like strncpy with a full-length source, does not NUL-terminate: the
 * terminator is only written because it is copied.
 *
 * The single `ldrsb` per iteration (not two loads) is the tell that the
 * source byte is bound to a local before being both stored and tested;
 * writing `dst[i] = site[i]; if (site[i] == 0)` would reload, since a
 * `const char *` source may alias the `char *` destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030880.c \
 *       --func sub_02030880 --addr 0x02030880 --cc 1.1p1 --arm
 */
void sub_02030880(void *payload, const char *site, u16 tag)
{
    struct HeapBlockSite *record;
    int i;

    record = (struct HeapBlockSite *)sub_020304C0(payload);
    for (i = 0; i < 0x12; i++) {
        char c = site[i];
        record->name[i] = c;
        if (c == 0) {
            break;
        }
    }
    record->tag = tag;
}









/*
 * Copies a block's allocation-site name out of its header into a caller
 * buffer and answers whether the name is plausible. A leaf: no prologue,
 * no relocations.
 *
 *   int sub_020308B8(u8 *dst, const char *src)
 *
 * Three passes, in this order:
 *
 *  1. Copy up to 0x12 bytes, stopping on the NUL, then NUL-terminate at
 *     the copied length. This is the read-back of what sub_02030880
 *     stamped, and it is the mirror image of that function's loop: there
 *     the terminator is stored and the length test comes after the store,
 *     here the test comes first and the terminator is written separately,
 *     which is why the buffer must be 0x13 bytes and not 0x12.
 *  2. Every byte must be printable ASCII, 0x20..0x7e. The `ldrb` here
 *     against the `ldrsb` of the copy loop is the whole signedness story:
 *     the source is `char` (signed by -char signed) and the destination is
 *     read back as `u8`, which is what makes `< 0x20` an unsigned `blo`.
 *  3. A name shorter than the full 0x12 bytes must contain a '.', i.e. it
 *     must look like a file name. A name that fills the field is accepted
 *     without the dot, since the dot may simply have been truncated away.
 *
 * An empty name is rejected before pass 2, and the zero it returns is the
 * same register the NUL-terminator store just materialised, which also
 * seeds the pass-2 index: one `mov r2, #0` doing three jobs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020308B8.c \
 *       --func sub_020308B8 --addr 0x020308B8 --cc 1.1p1 --arm
 */
int sub_020308B8(u8 *nameBuf, const char *blockName)
{
    int len;
    int i;

    for (len = 0; len < 0x12; len++) {
        char c = blockName[len];
        if (c == 0) {
            break;
        }
        nameBuf[len] = c;
    }
    nameBuf[len] = 0;
    if (len == 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        u8 c = nameBuf[i];
        if (c < 0x20 || c > 0x7e) {
            return 0;
        }
    }
    if (len < 0x12) {
        for (i = 0; i < len; i++) {
            if (nameBuf[i] == '.') {
                break;
            }
        }
        if (i == len) {
            return 0;
        }
    }
    return 1;
}









/*
 * The out-of-memory failure reporter reached from the allocation entry
 * point sub_02030734 just before OS_Terminate.
 *
 *   void sub_02030958(u32 heapId)
 *
 * Only r0 is read. sub_02030734 sets up four argument registers at this
 * call (heapId, size, site, tag) but the last three arrive unchanged from
 * its own prologue and are leftovers, the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md;
 * the declaration in src/pending/sub_02030734.c spelling four parameters
 * is therefore wider than the real callee and should be narrowed to one
 * when that file is revisited.
 *
 * Body: sub_02030428 maps the public heap id to the heap's arena handle
 * (it masks the id, range-checks it against the count at +8 of the heap
 * table, records an error code at +0xe on failure and otherwise tail-calls
 * GFL_HEAP_GetHeap), that handle is then walked by sub_02060E6C and dumped by
 * sub_02060E94 with a mode of 4, and sub_02030B50 is passed the original
 * public id. The handle value is live across two calls, so it costs r4,
 * and the id costs r5.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030958.c \
 *       --func sub_02030958 --addr 0x02030958 --cc 1.1p1 --arm
 */
void sub_02030958(u32 heapId, u32 size, const char *site, int tag)
{
    void *arena;

    arena = sub_02030428(heapId);
    NNSi_FndGetListTotalSize(arena);
    NNSi_FndGetListAllocatableSize(arena, 4);
    func_02030B50(heapId);
}









/*
 * The watched-allocation audit, reached only from sub_02030A00 when the
 * global watch id g_020A7820 names this allocation's heap.
 *
 *   void sub_02030984(void *p)
 *
 * Only r0 is read; sub_02030A00 also sets r1 to the size, a leftover
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Three things happen, and two of them discard their results, which is
 * what a stripped diagnostic looks like: the calls survive for their side
 * effects (sub_0203046C records an error code in the heap table at +0xe)
 * and for the bounds checking they perform, while the value each computes
 * is dropped.
 *
 *  - sub_020304C0(p) is the provenance record stamped by sub_02030880,
 *    i.e. header+4. It is live across two calls and so costs r4.
 *  - sub_020304B8(p) is a plain `ldrh [p, #-0x1c]`: the heap id stored in
 *    the first halfword of the block header. It feeds sub_0203046C, the
 *    id-to-arena mapper, whose result is dropped.
 *  - sub_020308B8 copies the provenance name into a 0x13-byte stack
 *    buffer and validates it (all bytes printable 0x20..0x7e, and a '.'
 *    present unless the name fills all 0x12 bytes); its verdict is also
 *    dropped. The buffer is declared before the pointer locals, which is
 *    what puts it at sp+0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030984.c \
 *       --func sub_02030984 --addr 0x02030984 --cc 1.1p1 --arm
 */
void sub_02030984(void *payload, u32 size)
{
    u8 nameBuf[0x13];
    void *siteRecord;

    siteRecord = sub_020304C0(payload);
    sub_0203046C(sub_020304B8(payload));
    sub_020308B8(nameBuf, (const char *)siteRecord);
}









/*
 * The free-side audit, the counterpart of sub_02030984: same three opening
 * calls, then the actual release of the block and a dump of the heap it
 * came from.
 *
 *   void sub_020309B8(void *p)
 *
 * The difference from sub_02030984 is that the block's heap id is needed
 * twice here, so it is bound to a local and costs r4, while in
 * sub_02030984 it flows straight from sub_020304B8 into sub_0203046C and
 * costs nothing. sub_02060F90 is handed the header address (p - 0x1c), the
 * same address sub_02030098 got back from the expanded-heap allocator, and
 * sub_02030344 then dumps the heap the id names.
 *
 * The 0x13-byte scratch buffer is declared first, which is what puts it at
 * sp + 0; the stack frame is rounded to 0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020309B8.c \
 *       --func sub_020309B8 --addr 0x020309B8 --cc 1.1p1 --arm
 */
void sub_020309B8(void *payload)
{
    u8 nameBuf[0x13];
    void *siteRecord;
    u32 heapId;

    siteRecord = sub_020304C0(payload);
    heapId = sub_020304B8(payload);
    sub_0203046C(heapId);
    sub_020308B8(nameBuf, (const char *)siteRecord);
    NNSi_FndGetMBlockSize((char *)payload - 0x1c);
    sub_02030344(heapId);
}









/*
 * Success-side bookkeeping for the allocation entry point sub_02030734,
 * and a debug filter: the whole body is gated on a global watch id.
 *
 *   void sub_02030A00(u32 heapId, void *p, u32 size)
 *
 * g_020A7820 is a signed watch id, -1 (or any negative value) meaning
 * "watch nothing". Only when it is non-negative and equal to the heap id
 * of this allocation does the block get handed to sub_02030984, which
 * validates the provenance name stamped by sub_02030880.
 *
 * The `cmp r3, #0` / `cmpge r0, r3` pair is the conditional-compare fold
 * of a single `&&`: the first comparison is the first-written conjunct,
 * and the guard must be one expression, not two sequential `if`s, for the
 * `popne` to serve both.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030A00.c \
 *       --func sub_02030A00 --addr 0x02030A00 --cc 1.1p1 --arm
 */
void sub_02030A00(u32 heapId, void *payload, u32 size)
{
    if (gWatchedHeapId >= 0 && heapId == (u32)gWatchedHeapId) {
        sub_02030984(payload, size);
    }
}









/*
 * The free-side watch filter, exactly the shape of sub_02030A00 on the
 * allocation side: the audit runs only when the global watch id names this
 * block's heap.
 *
 *   void sub_02030A2C(void *p)
 *
 * The heap id is not a parameter here, it is read back out of the block's
 * own header by sub_020304B8, which is why the call is scheduled before
 * the global is even loaded: its result has to be in r0, and only then can
 * the conditional-compare pair `cmp r1, #0` / `cmpge r0, r1` fold the two
 * conjuncts. The source order of the conjuncts is still watch-id-first,
 * the order the comparisons appear in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030A2C.c \
 *       --func sub_02030A2C --addr 0x02030A2C --cc 1.1p1 --arm
 */
void sub_02030A2C(void *payload)
{
    u32 heapId;

    heapId = sub_020304B8(payload);
    if (gWatchedHeapId >= 0 && heapId == (u32)gWatchedHeapId) {
        sub_020309B8(payload);
    }
}









/*
 * Dumps a heap, but only if the heap actually has live allocations.
 *
 *   void sub_02030A5C(u32 heapId)
 *
 * sub_0203046C returns the heap's +0xc record halfword, which
 * sub_02030098 increments on every successful allocation, so a zero answer
 * means an empty heap and there is nothing to report. Note that the
 * out-of-range answer from sub_0203046C is 0xffff, not zero, so a bad id
 * still reaches sub_02030B50; the range check is left to that call.
 *
 * The id has to survive the first call, which is what spends r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030A5C.c \
 *       --func sub_02030A5C --addr 0x02030A5C --cc 1.1p1 --arm
 */
void sub_02030A5C(u32 heapId)
{
    if (sub_0203046C(heapId) != 0) {
        func_02030B50(heapId);
    }
}









/*
 *           8 of 10 relocation sites resolved.  Down from 3 unresolved sites to 2.
 *           sole-ref x1 -- the class was widened 2026-09-21 to accept an address that
 *           lands on something the layout recognises, and 0x020A7824 is the start of a
 *           NUL-terminated printable run (sole-ref/string).  The note below about
 *           attest_string() refusing it is still accurate for the OLD `string` class
 *           and is kept for the record, but it no longer blocks this file.
 * Fills in the allocator's bookkeeping object at 0x02146970 (u16 tag, two
 * pointers, then an 18-character name buffer at 0x0214697C) and names the
 * block it was handed.  The block's own id is read out of the block header
 * (+0x12, a u16 halfword) when func_020308B8 finds a name for the scratch
 * buffer, and the buffer is otherwise loaded with the 13-byte default
 * "SYSTEM ALLOC" at 0x020A7824 and tagged 0.  That name is then copied into
 * the object's name buffer (length + 1) and space-padded out to 18 columns
 * with the terminator at the padding boundary, which is why the loop is
 * written as a guarded `do` with the index left over for the final store.
 *
 * Every byte of the 212-byte extent matches, relocation fields aside: this
 * file compiles to 212 bytes of which 200 are code, exactly the original's
 * shape, and match.py's only complaint is the three wildcarded pool words
 * below.  All three are data:
 *
 *  - 0x02146970 and 0x0214697C are bss addresses (bss runs from 0x020A9E80
 *    to 0x021542C0 and is not part of this image), so nothing disassembles
 *    there and the only evidence class that can ever name them is `literal`.
 *  - 0x020A7824 is the "SYSTEM ALLOC" string.  The `string` class refuses
 *    it: the four bytes immediately before it are FF FF FF FF (a word
 *    alignment filler between it and the preceding "time_icon.c"), and
 *    attest_string() requires NUL padding directly before the run, not
 *    another string's terminator four bytes away.  `data_table` refuses it
 *    as well -- 0x54535953 is not a pointer into a loaded region.
 *
 * So the function's own literal pool is the only thing in the image that
 * holds these three values: each has exactly one pool word image-wide
 * (0x02030B44, 0x02030B48, 0x02030B4C) and all three sit inside the
 * function's own extent, where the honesty rule refuses them as witnesses.
 * `--suggest-split` returns 0 pieces and leaves the single function out:
 * there is no cut that frees a site, because this function is the whole
 * range.  The three addresses are unwitnessable at any spelling of the C --
 * the pass is only reachable when some *other* matched function happens to
 * pool one of them, and nothing else in the image references them.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02030A7C.c \
 *       --func func_02030A7C --addr 0x02030A7C --cc 1.1p1 --arm
 */
void func_02030A7C(void *block, int *heap, u32 userParam)
{
    u8 nameBuf[0x14];
    u8 *payload = (u8 *)block + 0x1c;
    void *siteRecord = sub_020304C0(payload);
    u16 siteTag;
    s32 nameLen;
    s32 padCount;
    s32 i;

    gHeapBlockReport.blockSize = NNSi_FndGetMBlockSize(block);
    gHeapBlockReport.payload = payload;
    if (sub_020308B8(nameBuf, siteRecord) != 0) {
        siteTag = ((struct HeapBlockSite *)siteRecord)->tag;
    } else {
        MI_CpuCopy8(kSystemAllocName, nameBuf, 0xd);
        siteTag = 0;
    }
    nameLen = func_0203F004(nameBuf);
    MI_CpuCopy8(nameBuf, gHeapBlockReportName, nameLen + 1);
    gHeapBlockReport.tag = siteTag;
    padCount = 0x12 - func_0203F004(nameBuf);
    i = 0;
    if (padCount > 0) {
        do {
            nameBuf[i] = ' ';
            i++;
        } while (i < padCount);
    }
    nameBuf[i] = 0;
}









/*
 * Tears the object down and then runs func_02030A7C over every block in the
 * allocator list: the five per-object teardown calls, the global
 * "shutting down" flag set through func_0209128C(1), then NNSi_FndWalkHeapBlocks with
 * the callback and the context the teardown returned, and the flag cleared
 * again with func_0209128C(0).  The callback is passed a zero context, which
 * is why the constant is materialised once in r4 and copied to r2 rather
 * than emitted twice.
 *
 * All 84 bytes of the extent match, relocation fields aside: 80 bytes of
 * code plus the function's own pool word, exactly the original's shape.  The
 * blocker is not the C -- it is that this function is the only evidence for
 * two of the addresses it names:
 *
 *  - 0x0209128C (the "shutting down" flag setter at the head of packet
 *    pkt_020911D8) is branched to from exactly two sites in the whole image,
 *    and both of them are this function's own two `bl`s.  The `label` class
 *    needs a branch from *outside* the compared range, so the range being
 *    this function makes the only witnesses in the image inadmissible.
 *  - 0x02030A7C (the callback, and this packet's other function) is named by
 *    a single pool word image-wide, at 0x02030BA0, and that word is inside
 *    this function's own extent; nothing anywhere `b`/`bl`s to it, so the
 *    `label` class has no site to offer either.  It is also why the two
 *    functions cannot attest each other: func_02030A7C is this file's
 *    sibling in pkt_02030A7C, but it is itself MATCH-capped on three data
 *    sites (see src/pending/func_02030A7C.c), so no `matched` entry exists
 *    to witness this call.
 *
 * `--suggest-split` returns 0 pieces and leaves the single function out:
 * both blockers are inside the range and no cut can free them.  Every
 * unresolved site here clears the moment the function it names is matched
 * by somebody else -- 0x0209128C is an entry point of pkt_020911D8, and
 * 0x02030A7C is blocked on bss evidence rather than on anything this file
 * could do differently.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02030B50.c \
 *       --func func_02030B50 --addr 0x02030B50 --cc 1.1p1 --arm
 */
void func_02030B50(u32 heapId)
{
    sub_020303D8(heapId);
    sub_02030344(heapId);
    sub_0203038C(heapId);
    sub_0203046C(heapId);
    func_0209128C(1);
    NNSi_FndWalkHeapBlocks(sub_02030428(heapId), func_02030A7C, 0);
    func_0209128C(0);
}








void func_02030BA4(u32 size)
{
    if (func_02030534(size) == 0) {
        OS_Terminate();
    }
}








/*
 * A four-instruction tail call: `ldr ip, [pc]; bx ip; .word target`. The
 * target, 0x020305C4, is not itself a labelled function: it is the second
 * half of the 176-byte function at 0x02030534 (pkt_02030534, outside this
 * packet), reached only through this pool word and never by a branch, so
 * `disasm.py`'s prologue sweep never fires on it. See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md for the shape;
 * this is the same phenomenon one level up, a whole secondary entry point
 * rather than one accessor.
 *
 * Promoted from MATCH with no change to the C. The one relocation had no
 * witness under the honesty rule: the only reference to 0x020305C4
 * anywhere is this call, inside the range under test, and the address
 * carried no func_ label. It closed when 0x020305C4 was seeded into
 * layout/function_starts.txt and written as src/matched/GFL_HEAP_AllocSystem.c,
 * which makes the site `matched`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030BBC.c \
 *       --func sub_02030BBC --addr 0x02030BBC --cc 1.1p1 --arm
 */
void *sub_02030BBC(u32 size)
{
    return GFL_HEAP_AllocSystem(size);
}








/*
 * A four-instruction tail call to GFL_HEAP_FreeSystem (src/matched/GFL_HEAP_FreeSystem.c,
 * pkt_02030534), attested by the `matched` class: GFL_HEAP_FreeSystem's own EXACT
 * entry pins its address, and this call is the only branch to it found in
 * the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030BC8.c \
 *       --func sub_02030BC8 --addr 0x02030BC8 --cc 1.1p1
 */
int sub_02030BC8(u32 idx)
{
    return GFL_HEAP_FreeSystem(idx);
}






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
 *   python tools/match.py one --src src/matched/sub_02030BD4.c  *       --func sub_02030BD4 --addr 0x02030BD4 --cc 1.1p1 --arm
 */
void sub_02030BD4(struct TcbSystem *sys)
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
struct TcbTask *sub_02030C44(struct TcbSystem *sys)
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
 * Decompiled to unstick src/pending/sub_02030EAC.c (fan-in 196), which is
 * this function's only caller image-wide and so had no `label` witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030C68.c \
 *       --addr 0x02030C68 --cc 1.1p1 --arm
 */
u32 func_02030C68(struct TcbSystem *sys, struct TcbTask *task)
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
 *   python tools/match.py one --src src/matched/sub_02030CB0.c \
 *       --func sub_02030CB0 --addr 0x02030CB0 --cc 1.1p1
 */
u32 sub_02030CB0(u32 idx)
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
 *   python tools/match.py one --src src/matched/sub_02030CBC.c \
 *       --func sub_02030CBC --addr 0x02030CBC --cc 1.1p1 --arm
 */
struct TcbSystem *sub_02030CBC(u32 capacity, struct TcbSystem *sys)
{
    sys->capacity = capacity;
    sys->freeStack = sys->freeStackStorage;
    sys->taskPool = (struct TcbTask *)(sys->freeStack + capacity);
    sys->usedCount = 0;
    sys->isAdding = 0;
    sub_02030CF4(sys);
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
 *   python tools/match.py one --src src/matched/sub_02030CF4.c \
 *       --func sub_02030CF4 --addr 0x02030CF4 --cc 1.1p1 --arm
 */
void sub_02030CF4(struct TcbSystem *sys)
{
    sub_02030BD4(sys);
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
 * (docs/notes/sub_02030D28.c.txt) was a misread callback arity: the image
 * loads the node into r0 and node->arg into r1 before `blx r2`, so the
 * callback is fn(node, arg), not fn(arg).  With two arguments the body is
 * byte-exact under 1.1p1 -O4,p.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02030D28.c \
 *       --func func_02030D28 --addr 0x02030D28 --cc 1.1p1 --arm
 */
void func_02030D28(struct TcbSystem *sys)
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





void func_02030DA4(void){ }







/*
 * Previously capped at MATCH: 0x02030C44 has exactly one caller image-wide,
 * the call inside sub_02030DC8 below, so no `label` witness exists and no cut
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
struct TcbTask *sub_02030DA8(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority)
{
    struct TcbTask *task;

    sys->isAdding = 1;
    task = sub_02030DC8(sys, func, work, priority);
    sys->isAdding = 0;
    return task;
}





struct TcbTask *sub_02030DC8(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority)
{
    struct TcbTask *task;
    struct TcbTask *other;

    task = sub_02030C44(sys);
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
 * sub_02030C68 on the owner.  The node carries its owner at +0, its
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
 *   python tools/match.py one --src src/matched/sub_02030EAC.c \
 *       --func sub_02030EAC --addr 0x02030EAC --cc 1.1p1 --arm
 */
void sub_02030EAC(struct TcbTask *task)
{
    struct TcbSystem *sys = task->owner;

    if (sys->nextTask == task) {
        sys->nextTask = task->next;
    }
    task->prev->next = task->next;
    task->next->prev = task->prev;
    func_02030C68(task->owner, task);
}






/*
 * A plain word accessor at offset 0x10. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_GetTaskUserData.c \
 *       --func TCBL_GetTaskUserData --addr 0x02030EE8 --cc 1.1p1
 */
u32 TCBL_GetTaskUserData(struct TcblSystem *tcbl)
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
    return (struct TcblTask *)(index * (tcbl->workSize + 0x18) + (u32)tcbl->taskTable);
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
 * the three payload words cleared.  It is the shape sub_02030C68 has for the
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
        sub_020307B0(task->work);
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

    tcbl = sub_02030734(heapId, sizeof(struct TcblSystem), 0, tcbl_File, 199);
    tcbl->taskCount = taskCount;
    tcbl->workSize = workSize;
    tcbl->workHeapId = workHeapId;
    tcbl->reserved0C = 0;
    tcbl->deletePending = 0;
    tcbl->taskTable = sub_02030734(heapId, (((workSize + 3) & ~3) + 0x18) * taskCount, 0,
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
 * sub_020307B0.  (layout/symbols_sdk.json offers the name
 * ENV_SetResourceSet for 0x020307B0; it is a signature-matcher guess and the
 * role here is the heap free, so the call goes to the local definition.)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_Destroy.c \
 *       --func TCBL_Destroy --addr 0x02031140 --cc 1.1p1
 */
void TCBL_Destroy(struct TcblSystem *tcbl)
{
    sub_020307B0(tcbl->taskTable);
    sub_020307B0(tcbl);
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
        task->work = sub_02030734(tcbl->workHeapId, workSize, 0, tcbl_File, 325);
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
