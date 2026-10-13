/*
 * file:     unit_0202FBAC.c
 * unit:     yes
 * function: GFL_HEAP_GetHeap, GFL_HEAP_GetParentHeap, GFL_HEAP_GetBlock, GFL_HEAP_GetAllocCount, GFL_HEAP_InitManager, GFL_HEAP_CreateChildHeapImpl, GFL_HEAP_RegisterBlockHeapImpl, GFL_HEAP_AddRecord, GFL_HEAP_Delete, GFL_HEAP_AllocMemory, GFL_HEAP_FreeMemory, GFL_HEAP_InitAllocator, GFL_HEAP_ResizeMemory, GFL_HEAP_GetTotalFreeSize, func_0203038C, GFL_HEAP_GetHeapSize, GFL_HEAP_GetHeapHandle, GFL_HEAP_GetAllocCountById, GFL_HEAP_GetBlockHeapId, GFL_HEAP_GetBlockName, GFL_HEAP_IsHeapValid, GFL_HEAP_GetLastError, GFL_HEAP_InitSystemHeap, GFL_HEAP_AllocSystem, GFL_HEAP_FreeSystem, GFL_HEAP_Init, func_0203064C, func_02030678, GFL_HEAP_FatalError
 * address:  0x0202FBAC
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
 *   gHeapManager  0x02146954  data
 *   sub_02060C5C  0x02060C5C  arm
 *   sub_02086788  0x02086788  arm
 *   sub_02060CA0  0x02060CA0  arm
 *   func_02060C5C  0x02060C5C  arm
 *   func_02060C94  0x02060C94  arm
 *   func_02060E30  0x02060E30  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02061358         0x02061358  arm
 *   sub_02060CD0    0x02060CD0  arm
 *   sub_02060F90    0x02060F90  arm
 *   sub_02060E6C    0x02060E6C  arm
 *   sub_02060E94    0x02060E94  arm
 *   gSystemHeap              0x02146964  data
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  arm
 *   OS_GetArenaLo                0x02086580  arm
 *   OS_SetArenaHi                0x02086760  arm
 *   OS_SetArenaLo                0x02086774  arm
 *   OS_InitAlloc                 0x02086A50  arm
 *   OS_CreateHeap                0x02086AF8  arm
 *   OS_AllocFromHeap   0x020868E0  arm
 *   OS_FreeToHeap    0x020869E8  arm
 *   sub_0202FC48  0x0202FC48  arm
 *   sub_02030524  0x02030524  arm
 *   sub_02086580  0x02086580  arm
 *   sub_0208656C  0x0208656C  arm
 *   sub_02088234  0x02088234  arm
 *   sub_0202FDC4  0x0202FDC4  arm
 *   sub_020306A0  0x020306A0  arm
 *   GFL_HEAP_RegisterBlockHeapImpl  0x0202FE68  arm
 *   func_02088234  0x02088234  arm
 */
struct ExpHeap;
struct HeapAllocator;
struct HeapSpec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* One heap of the manager (16 bytes). */
struct HeapRecord {
    void *heap;          /* expanded heap handle, NULL = free record */
    u32   parentHeap;    /* heap the memory was carved from, 0 if none */
    u32   block;         /* the carved memory block (freed to parentHeap) */
    u16   allocCount;    /* live allocations */
    u8    isExternal;    /* 1 = built over a caller-supplied block */
    u8    pad0F;
};

/* The heap manager (0x02146954).  A heap id (low 15 bits of a handle) maps
 * through slotOfHeapId (0xFF = unused id) to a record.  The first
 * staticHeapCount records are created at start-up; the rest are spares
 * for heaps created later. */
struct HeapManager {
    struct HeapRecord *records;
    u8              *slotOfHeapId;
    u16              heapIdCount;
    u16              staticHeapCount;
    u16              recordCount;
    u16              lastError;       /* code of the last failure, 0 = ok */
};

/* One start-up heap request. */
struct HeapSpec {
    u32 size;
    u32 reserved04;
};

typedef signed int     s32;

/* Header before every allocation (0x1C bytes).  magic is 0x194E while the
 * block is live and 0x194D after it is freed. */
struct BlockHeader {
    u16 heapId;
    u16 magic;
    char name[0x12];   /* allocation owner name, stamped by the caller */
    u16 tag;
    u32 reserved18;
};

/* Expanded heap header: only the end pointer is read. */
struct ExpHeapHead {
    u32 head[7];
    u32 *end;
};

/* The header seen from its name field. */
struct BlockHeaderNameView {
    char pad[4];
    int  name;
};

typedef signed int BOOL;

/* State of the fixed-size system heap (0x02146964). */
struct SystemHeapState {
    void *reserved0;
    s32 heapHandle;     /* OS heap handle, -1 = not created */
};

extern void *sub_02086788(u32 heap, u32 size, u32 align);
extern void *sub_02060C5C(void *mem, u32 size, u32 mode);
extern void *sub_02060CA0(struct ExpHeap *heap, u32 size, s32 align);
int sub_0202FDC4(u32 parentHeapId, u32 newHeapId, u32 size);
int GFL_HEAP_RegisterBlockHeapImpl(void *block, u32 size, u32 newHeapId);
extern void *func_02060C5C(void *start, u32 size, u16 attr);
int GFL_HEAP_AddRecord(u32 parentHeap, u32 heapId, u32 block, u32 size);
extern void  func_02060C94(void *block);
extern void func_02060E30(struct ExpHeap *heap, void *block);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);
extern void func_02061358(struct HeapAllocator *s, u32 a, u32 b);
extern u32 sub_02060CD0(struct ExpHeap *heap, void *memBlock, u32 size);
extern int sub_02060F90(char *p);
extern int sub_02060E6C(int *p);
extern s32 sub_02060E94(struct ExpHeap *heap, s32 x);
extern void SDK_AUTOLOAD_MAIN_TWL_START(void);
extern void *OS_GetArenaLo(u32 id);
extern void OS_SetArenaHi(u32 id, void *hi);
extern void OS_SetArenaLo(u32 id, void *lo);
extern void *OS_InitAlloc(u32 id, void *lo, void *hi, s32 heapCount);
extern s32 OS_CreateHeap(u32 id, void *start, void *end);
extern void *OS_AllocFromHeap(u32 id, s32 heap, u32 size);
u32 GFL_HEAP_Delete(u32 heapHandle);
void *sub_02030098(u32 heapId, u32 size);
u32 GFL_HEAP_FreeMemory(void *mem);
u32 GFL_HEAP_InitAllocator(void *allocator, u32 heapIdAndDirection, s32 alignment);
u32 sub_020302A4(void *mem, u32 newSize);
void *sub_02030344(u32 heapId);
void *sub_0203038C(u32 heapId);
u32 sub_020303D8(u32 heapId);
void *sub_02030428(u32 heapId);
u16 sub_0203046C(u32 heapId);
u16 sub_020304B8(void *mem);
void *sub_020304C0(void *mem);
u32 sub_020304CC(u32 heapId);
u16 GFL_HEAP_GetLastError(void);
BOOL GFL_HEAP_InitSystemHeap(u32 size);
void *GFL_HEAP_AllocSystem(u32 size);
extern int OS_FreeToHeap(u32 heapId, s32 heap, void *ptr);
extern int sub_0202FC48(const struct HeapSpec *specs, u16 staticCount, u16 heapIdCount, u32 extraSize);
extern u16 sub_02030524(void);
extern void  sub_02086580(u32 a);
extern void  sub_0208656C(u32 a);
extern void  sub_02088234(void *obj);
extern void  sub_020306A0(void *obj, void *a, u32 b);
extern void func_02088234(void);
void *GFL_HEAP_GetHeap(u32 heapId);
u32 GFL_HEAP_GetParentHeap(u32 heapId);
u32 GFL_HEAP_GetBlock(u32 heapId);
u16 GFL_HEAP_GetAllocCount(u32 heapId);
int GFL_HEAP_FreeSystem(u32 mem);
void sub_02030608(u32 specs, u32 staticCount, u32 heapIdCount, u32 extraSize);
void sub_0203064C(u32 parentHeapId, u32 newHeapId, u32 size);
void sub_02030678(void *block, u32 size, u32 newHeapId);
void GFL_HEAP_FatalError(int errorCode);
extern struct HeapManager gHeapManager;
extern struct SystemHeapState gSystemHeap;




void *GFL_HEAP_GetHeap(u32 heapId)
{
    u8 slot = gHeapManager.slotOfHeapId[heapId];
    if (slot == 0xff) return 0;
    return gHeapManager.records[slot].heap;
}




u32 GFL_HEAP_GetParentHeap(u32 heapId)
{
    u8 slot = gHeapManager.slotOfHeapId[heapId];
    if (slot == 0xff) return 0;
    return gHeapManager.records[slot].parentHeap;
}




u32 GFL_HEAP_GetBlock(u32 heapId)
{
    u8 slot = gHeapManager.slotOfHeapId[heapId];
    if (slot == 0xff) return 0;
    return gHeapManager.records[slot].block;
}




u16 GFL_HEAP_GetAllocCount(u32 heapId)
{
    u8 slot = gHeapManager.slotOfHeapId[heapId];
    if (slot == 0xff) return 0;
    return gHeapManager.records[slot].allocCount;
}







/*
 * The module initialiser named by src/matched/unit_0202FBAC.c: it allocates
 * both arrays gHeapManager reads and fills the header at +8.  The entry array
 * is sized count+0x18, so the first `count` slots are the caller's resources
 * and the remaining 0x18 are spares the binders in this file hand out.  The
 * id table is at least as long as the entry array, the caller's own request
 * being clamped up to it, and every byte starts at 0xff (free).
 *
 * The clearing loop reloads gHeapManager.records before every field store,
 * which is what writing each store through the global rather than through a
 * cached cursor produces: the stores may alias the pointer itself.
 *
 * count and heapIdCount are u16, and that is not decoration: it is the whole
 * difference between this and the 376-byte near miss recorded in
 * docs/notes/sub_0202FC48.c.txt.  With u32 parameters the allocator keeps the
 * constant zero live from the clearing loop to the last call and needs seven
 * callee-saved registers, which loses the `mov sb, r4` in the final loop's
 * preheader.  With count u16 the zero's live range ends at the clearing loop,
 * total takes sb and the preheader re-materialises the zero off the r4 that
 * `lastError = 0` has just left at zero: 380 bytes, byte for byte.  The caller
 * sub_02030608 truncates both arguments with an lsl/lsr #16 pair before the
 * call, which is where the u16 comes from.  heapIdCount's own type is not what
 * decides it ((u16)total below makes the truncation explicit either way);
 * count's is: u32 count with u16 heapIdCount still lands at 376.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202FC48.c \
 *       --func sub_0202FC48 --addr 0x0202FC48 --cc 1.1p1 --arm
 */
int sub_0202FC48(const struct HeapSpec *specs, u16 staticCount, u16 heapIdCount, u32 extraSize)
{
    u32   recordTotal;
    u32   specIndex;
    void *memory;
    u32   recordIndex;

    recordTotal = staticCount + 0x18;
    if (heapIdCount < recordTotal) {
        heapIdCount = (u16)recordTotal;
    }

    if (extraSize != 0) {
        while ((extraSize & 3) != 0) {
            extraSize++;
        }
        sub_02086788(0, extraSize, 4);
    }

    gHeapManager.records = sub_02086788(0, recordTotal * 16, 4);
    for (recordIndex = 0; recordIndex < recordTotal; recordIndex++) {
        gHeapManager.records[recordIndex].heap = 0;
        gHeapManager.records[recordIndex].parentHeap = 0;
        gHeapManager.records[recordIndex].block = 0;
        gHeapManager.records[recordIndex].allocCount = 0;
        gHeapManager.records[recordIndex].isExternal = 0;
    }

    gHeapManager.slotOfHeapId = sub_02086788(0, heapIdCount, 4);
    for (specIndex = 0; specIndex < heapIdCount; specIndex++) {
        gHeapManager.slotOfHeapId[specIndex] = 0xff;
    }

    gHeapManager.heapIdCount = heapIdCount;
    gHeapManager.staticHeapCount = staticCount;
    gHeapManager.recordCount = recordTotal;
    gHeapManager.lastError = 0;

    for (specIndex = 0; specIndex < staticCount; specIndex++) {
        memory = sub_02086788(0, specs[specIndex].size, 4);
        if (memory != 0) {
            gHeapManager.records[specIndex].heap = sub_02060C5C(memory, specs[specIndex].size, 0);
            gHeapManager.slotOfHeapId[specIndex] = specIndex;
        } else {
            gHeapManager.lastError = specIndex;
            return 0;
        }
    }
    return 1;
}


/*
 * Bind one resource of the module at gHeapManager to a destination slot.  Both
 * identifiers carry a flag in bit 15 and an index in the low fifteen bits: on
 * the destination the flag selects the step, +4 or -4, handed to 0x02060CA0,
 * and the low bits index the id table at gHeapManager+4, which must still read
 * 0xff (free) or the attempt fails.
 *
 * Three of the four failures are distinguished in the module's lastError halfword
 * at gHeapManager+0xE: 1 for a destination slot already taken, 2 for a source
 * resource that does not resolve, 3 for the 0x02060CA0 step failing.  The
 * fourth, 0x0202FED8 returning zero, deliberately leaves the lastError word alone,
 * which is visible as the fall-through into the shared `mov r0, #0` tail with
 * no `strh` in front of it.
 *
 * All four zero returns share one `mov r0, #0` / `pop` tail, and calls sit
 * between the guards, so the only spelling that reproduces it is an explicit
 * `goto fail` (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md);
 * plain `return 0;` in each arm costs four extra instructions.
 *
 * The masked destination index reuses the parameter's own register
 * (`and r6, r6, r1`), so it is written back over `dst` rather than bound to a
 * fresh local, which would take a register of its own.
 *
 * The single pooled 0x7fff is shared by both masks (`and r6, r6, r1` and
 * `and r0, r0, r1` read the same register), so the mask must be spelled the
 * same way on both identifiers rather than folded into one of them.
 *
 * GFL_HEAP_GetHeap is declared here with a u16 parameter, not the u32 of
 * src/matched/unit_0202FBAC.c: the `lsl #16` / `lsr #16` pair after the mask
 * is the argument truncation and nothing else in the function produces it
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md,
 * read for the equal-amount case).  The two declarations live in different
 * translation units and never meet.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202FDC4.c \
 *       --func sub_0202FDC4 --addr 0x0202FDC4 --cc 1.1p1 --arm
 */
int sub_0202FDC4(u32 parentHeapId, u32 newHeapId, u32 size)
{
    void *parentHeap;
    void *childBlock;
    s32   align;

    if (newHeapId & 0x8000) {
        align = -4;
    } else {
        align = 4;
    }
    newHeapId = newHeapId & 0x7fff;

    if (gHeapManager.slotOfHeapId[newHeapId] != 0xff) {
        gHeapManager.lastError = 1;
        goto fail;
    }

    parentHeap = GFL_HEAP_GetHeap((u16)(parentHeapId & 0x7fff));
    if (parentHeap == 0) {
        gHeapManager.lastError = 2;
        goto fail;
    }

    childBlock = sub_02060CA0(parentHeap, size, align);
    if (childBlock == 0) {
        gHeapManager.lastError = 3;
        goto fail;
    }

    if (GFL_HEAP_AddRecord((u32)parentHeap, newHeapId, (u32)childBlock, size) == 0) {
        goto fail;
    }
    return 1;

fail:
    return 0;
}


/*
 * The sibling of sub_0202FDC4: bind an already-built object rather than one
 * resolved out of the module.  0x0202FED8 is called with a null resource and
 * the caller's object in the third slot, the same slot sub_0202FDC4 fills
 * with the result of 0x02060CA0.
 *
 * On success the entry's +0xE byte is set to 1, which is what pins
 * HeapRecord's size at sixteen bytes: the index scale in
 * `add r1, r2, r1, lsl #4` is the struct stride and 0xE is its last used
 * byte.  On a taken destination slot the module lastError halfword takes 1, as in
 * sub_0202FDC4; a refusal from 0x0202FED8 leaves it alone.
 *
 * Both zero returns share one tail with a call between them, so the exit is
 * an explicit `goto`
 * (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_RegisterBlockHeapImpl.c \
 *       --func GFL_HEAP_RegisterBlockHeapImpl --addr 0x0202FE68 --cc 1.1p1 --arm
 */
int GFL_HEAP_RegisterBlockHeapImpl(void *block, u32 size, u32 newHeapId)
{
    u32 heapId;

    heapId = newHeapId & 0x7fff;
    if (gHeapManager.slotOfHeapId[heapId] != 0xff) {
        gHeapManager.lastError = 1;
        goto fail;
    }

    if (GFL_HEAP_AddRecord(0, heapId, (u32)block, size) == 0) {
        goto fail;
    }

    gHeapManager.records[gHeapManager.slotOfHeapId[heapId]].isExternal = 1;
    return 1;

fail:
    return 0;
}


/*
 * Scans the 0x02146954 table for the first free 16-byte slot: a slot whose
 * first word is NULL is claimed with func_02060C5C(a2, a3, 0); a failed
 * claim sets the status halfword at +0xe to 5 and moves on, a success fills
 * the slot, records the slot index in the byte map at +4 and returns 1.
 * Falling off the end sets the status to 4 and returns 0.
 *
 * The table address is a declared symbol, not a cast constant: the image
 * reloads it from its own pool slot after the claim call (two pool words for
 * the same address at 0x0202FF94 and 0x0202FFBC), which a plain constant
 * would let mwcc keep in a callee-saved register.
 */
int GFL_HEAP_AddRecord(u32 parentHeap, u32 heapId, u32 block, u32 size)
{
    int recordIndex;

    for (recordIndex = gHeapManager.staticHeapCount; recordIndex < gHeapManager.recordCount; recordIndex++) {
        if (gHeapManager.records[recordIndex].heap != 0) {
            continue;
        }
        gHeapManager.records[recordIndex].heap = func_02060C5C((void *)block, size, 0);
        if (gHeapManager.records[recordIndex].heap == 0) {
            gHeapManager.lastError = 5;
            continue;
        }
        gHeapManager.records[recordIndex].parentHeap = parentHeap;
        gHeapManager.records[recordIndex].block = block;
        gHeapManager.slotOfHeapId[heapId] = (u8)recordIndex;
        gHeapManager.lastError = 0;
        return 1;
    }
    gHeapManager.lastError = 4;
    return 0;
}






/*
 * Heap destroy.  The handle's low fifteen bits are the heap id; the three
 * accessors turn it into the block pointer and the two allocator objects,
 * the byte array at g_02146954+4 maps the id to a slot in the sixteen-byte
 * record table at g_02146954+0, and the record is cleared and the id
 * released (0xFF) once the block is freed.
 *
 * Two failures set the module's lastError word at g_02146954+0xE and return 0:
 * an unknown id (1) and a slot that was never registered (2).
 *
 * The record is cleared field by field with the table base re-read before
 * every store: the stores can alias the global, so a cached base is a
 * byte difference, not a missed optimisation.
 *
 * Three shapes the bytes pinned down:
 *
 *  - the id mask is applied to the parameter in place (`mov r5, r0` then
 *    `and`), not folded into a fresh local, which would be one `and`.
 *  - the unknown-id arm sets the lastError word predicated and branches to the
 *    function's last `mov r0, #0`, so it is the `if` arm of an if/else
 *    whose `return 0` sits after the whole else block, not an early
 *    `return` of its own.
 *  - the two allocator objects are tested as `a == 0 || b == 0`, with the
 *    single-call arm as the `else`.  Written as `a != 0 && b != 0` the
 *    compiler fuses the pair into `cmp`/`cmpne` and loses four bytes.
 *
 * Decompiled to unstick src/pending/func_020306F0.c (fan-in 121), whose
 * only unresolved relocation was this address: func_020306F0 is this
 * function's only caller image-wide, so class `label` was unavailable and
 * the two are not contiguous, so no unit could make the site `local`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_Delete.c \
 *       --func GFL_HEAP_Delete --addr 0x0202FF98 --cc 1.1p1 --arm
 */
u32 GFL_HEAP_Delete(u32 heapHandle)
{
    u32 recordIndex;
    void *heap;
    void *parentHeap;
    void *memBlock;

    heapHandle &= 0x7fff;

    heap = GFL_HEAP_GetHeap(heapHandle);
    if (heap == 0) {
        gHeapManager.lastError = 1;
    } else {
        parentHeap = (void *)GFL_HEAP_GetParentHeap(heapHandle);
        memBlock = (void *)GFL_HEAP_GetBlock(heapHandle);
        recordIndex = gHeapManager.slotOfHeapId[heapHandle];
        func_02060C94(heap);

        if (parentHeap == 0 || memBlock == 0) {
            if (gHeapManager.records[recordIndex].isExternal == 0) {
                gHeapManager.lastError = 2;
                return 0;
            }
        } else {
            func_02060E30(parentHeap, memBlock);
        }

        gHeapManager.records[recordIndex].heap = 0;
        gHeapManager.records[recordIndex].parentHeap = 0;
        gHeapManager.records[recordIndex].block = 0;
        gHeapManager.records[recordIndex].allocCount = 0;
        gHeapManager.records[recordIndex].isExternal = 0;
        gHeapManager.slotOfHeapId[heapHandle] = 0xff;
        return 1;
    }

    return 0;
}







/*
 * The raw allocator: the only function in the image that actually takes
 * memory from a heap. sub_02030734, the 1163-caller allocation entry
 * point, is a wrapper around this.
 *
 *   void *sub_02030098(u32 heapId, u32 size)
 *
 * The heap id is not a plain index. Bit 15 is a direction flag: set means
 * allocate from the high end of the expanded heap (alignment argument -4),
 * clear means the low end (+4); the remaining bits, masked with 0x7fff,
 * are the index. That is why the mask constant costs a pool word and the
 * flag test is a `tst` scheduled before the mask.
 *
 * Every block carries a 0x1c-byte header immediately before the pointer
 * handed back, which is why the request is `size + 0x1c` and the return is
 * a post-indexed `strh r7, [r5], #0x1c`: the heap id is written to the
 * header's first halfword and the pointer is advanced past the header in
 * one instruction. The header's second halfword is a constant 0x194E
 * signature. The rest of the header is the provenance record stamped
 * later by sub_02030880 (name[0x12] at +4, u16 tag at +0x16), which is
 * what sub_020304C0's `p - 0x1c + 4` is addressing.
 *
 * The module global at 0x02146954, already named gHeapManager by
 * src/matched/unit_0202FBAC.c, is the heap manager, not an environment
 * module: +0 is the array of 16-byte per-heap records, +4 the byte table
 * mapping heap id to record index, +8 the u16 heap count used as the
 * bound here, and +0xe a u16 result code written on every path (1 = id out
 * of range, 2 = no such heap, 3 = heap exhausted, 0 = success). The
 * per-heap record's +0xc halfword, read back by GFL_HEAP_GetAllocCount, is the live
 * allocation count incremented here. The name is kept for consistency with
 * the existing EXACT file; renaming it to a heap-manager name is an
 * integrator-wide change, not a per-packet one.
 *
 * Shape notes:
 *
 *  - The two failure returns before the interrupt-disable share one
 *    `mov r0, #0` / `pop` epilogue reached by branch. Statements sit
 *    between the two guards, so plain `return 0;` in each arm does not
 *    reproduce it: the compiler emits `movhs r0, #0` / `pophs` inline
 *    instead and the whole tail shifts by two instructions. Only an
 *    explicit `goto fail;` gives the shared exit
 *    (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *  - Declaration order pins the register split: `intr` before `align`
 *    puts the interrupt state in r4 and the alignment (later reused for
 *    the block pointer) in r5. The reverse order swaps them and costs 118
 *    bytes of diff without changing a single instruction's shape
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *  - The store of the result code at +0xe is likewise emitted once, with
 *    r0 holding 3 or 0 depending on the arm, so it must be written in both
 *    arms of the allocation-failed test rather than factored out after it.
 *  - The manager base stays in r8 across all four calls, the effect of
 *    referring to the same global on both sides of them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030098.c \
 *       --func sub_02030098 --addr 0x02030098 --cc 1.1p1 --arm
 */
void *sub_02030098(u32 heapId, u32 size)
{
    void *heap;
    u32 irqState;
    u8 *header;
    s32 direction;

    if ((heapId & 0x8000) != 0) {
        direction = -4;
    } else {
        direction = 4;
    }
    heapId &= 0x7FFF;
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    heap = GFL_HEAP_GetHeap(heapId);
    if (heap == 0) {
        gHeapManager.lastError = 2;
        goto fail;
    }
    irqState = OS_DisableInterrupts();
    header = (u8 *)sub_02060CA0(heap, size + 0x1c, direction);
    if (header == 0) {
        gHeapManager.lastError = 3;
    } else {
        ((struct BlockHeader *)header)->magic = 0x194E;
        ((struct BlockHeader *)header)->heapId = heapId;
        header += 0x1c;
        gHeapManager.records[gHeapManager.slotOfHeapId[heapId]].allocCount++;
        gHeapManager.lastError = 0;
    }
    OS_RestoreInterrupts(irqState);
    return header;

fail:
    return 0;
}







/*
 * Block release: the free that pairs with sub_02030098. The header is the
 * same 0x1c-byte block header sub_02030098 reserves, so the block pointer
 * is p - 0x1c and the heap id is the header's first halfword, loaded before
 * the header is validated (see the notes below); the second halfword is the
 * 0x194E signature and is rewritten to 0x194D here, so a freed block keeps
 * a recognisable header but is no longer live.
 *
 * The result code written to gHeapManager.lastError (+0xe) numbers four failure
 * modes: 1 bad signature, 2 heap id out of range, 3 no such heap (the
 * GFL_HEAP_GetHeap lookup, the arena handed to the release), 4 the heap's live
 * allocation count is already zero (a double free; the count is the +0xc
 * halfword GFL_HEAP_GetAllocCount returns). All four branches to the single
 * `mov r0, #0` / pop epilogue need the explicit `goto fail`, otherwise the
 * compiler predicates each failure inline and the whole tail shifts.
 *
 * Three shapes the bytes pinned down:
 *
 *  - The heap id load comes *before* the signature guard in the source.
 *    With `heapId = hdr->heapId;` after the guard mwccarm emits it at
 *    +0028, inside the fall-through, and 25 concrete bytes differ; written
 *    before the guard the same statement emits a single `ldrh r4,
 *    [r0, #-0x1c]` at +0010, folded onto the still-live parameter register
 *    rather than onto the materialised r6 = p - 0x1c base. Both spellings
 *    (`hdr->heapId` and the raw `((u16 *)p)[-14]`) compile to that same
 *    folded load, so it is the statement's position, not its form, that the
 *    bytes record.
 *  - The signature comparison reads the header through the materialised
 *    base, `ldrh r1, [r6, #2]`, because -0x1c + 2 = -0x1a is not an
 *    encodable extra-load offset; only the heap id at header offset 0 can
 *    fold onto the parameter.
 *  - `hdr->magic = 0x194D;` is emitted as `sub r2, r7, #1` off the r7 the
 *    guard already loaded 0x194E into, not as a second pool word, and the
 *    value it leaves in r2 is the dead third argument of func_02060E30
 *    (which is really the two-argument (arena, block) release that
 *    src/matched/GFL_HEAP_Delete.c declares).
 *
 * The count decrement is `gHeapManager.records[gHeapManager.slotOfHeapId[heapId]].allocCount--;`
 * -- the same double-index expression sub_02030098 increments -- and its
 * decremented result is not reused; the second call takes two arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_FreeMemory.c \
 *       --func GFL_HEAP_FreeMemory --addr 0x02030164 --cc 1.1p1 --arm
 */
u32 GFL_HEAP_FreeMemory(void *mem)
{
    struct BlockHeader *header;
    void *heap;
    u32 irqState;
    u32 heapId;

    header = (struct BlockHeader *)((char *)mem - 0x1c);
    heapId = header->heapId;
    if (header->magic != 0x194E) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 2;
        goto fail;
    }
    heap = GFL_HEAP_GetHeap(heapId);
    if (heap == 0) {
        gHeapManager.lastError = 3;
        goto fail;
    }
    if (GFL_HEAP_GetAllocCount(heapId) == 0) {
        gHeapManager.lastError = 4;
        goto fail;
    }
    irqState = OS_DisableInterrupts();
    gHeapManager.records[gHeapManager.slotOfHeapId[heapId]].allocCount--;
    header->magic = 0x194D;
    func_02060E30(heap, header);
    OS_RestoreInterrupts(irqState);
    gHeapManager.lastError = 0;
    return 1;

fail:
    return 0;
}







/*
 * BLOCKED on one relocation site: all 100 concrete code bytes (108 with the
 * trailing pool) are correct, but the call to func_02061358 at +0048 has no
 * witness. 0x02061358 is the 20-byte record-initialiser in the NNS-shaped
 * library block around 0x02060000; it has exactly one branch reference in
 * the whole image and it is this call, so class `label` cannot carry it
 * (every witness would sit inside the compared range), no pool word
 * anywhere holds the address so `literal` is unavailable too, and the
 * bytes at 0x02061358 (ldr ip,[pc,#12]; mov r3,#0; str r12,[r0];
 * stmia r0,{r1,r2,r3}; bx lr) are not one of the recognised veneer
 * encodings. No cut exists inside a single function section, so a
 * --suggest-split over 0x02030164..0x020302A4 offers nothing either: that
 * two-function unit was run and caps at MATCH for this same one site
 * (8 of 9 relocations resolved, zero concrete byte differences). An EXACT
 * entry for 0x02061358 promotes this file unchanged.
 *
 * Initialise a block in the heap: the heap id is bit-15-flagged like
 * sub_02030098's, and the low fifteen bits select the arena to store.
 *
 *   u32 GFL_HEAP_InitAllocator(void *p, u32 heapId, s32 size)
 *
 * The length is normalised to positive and then re-signed by the heap's
 * direction flag, which is what the two conditional negations around the
 * `tst r1, #0x8000` are: `movs r5, r2` / `rsbmi r5, r5, #0` is abs() on a
 * named local (not the parameter -- the parameter stays in r2), and the
 * second `rsbne r5, r5, #0` is signed from the flag. The `and r0, r1, r0`
 * mask with 0x7fff is scheduled after the tst, so the mask constant costs
 * a pool word while the flag test is immediate.
 *
 * The arena is passed straight from GFL_HEAP_GetHeap's return into r1 with no
 * local bound in between, so the call is the nested form
 * func_02061358(p, GFL_HEAP_GetHeap(heapId & 0x7fff), len).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_HEAP_InitAllocator.c \
 *       --func GFL_HEAP_InitAllocator --addr 0x02030238 --cc 1.1p1 --arm
 */
u32 GFL_HEAP_InitAllocator(void *allocator, u32 heapIdAndDirection, s32 alignment)
{
    s32 signedAlignment;

    signedAlignment = alignment;
    if (signedAlignment < 0) {
        signedAlignment = -signedAlignment;
    }
    if (heapIdAndDirection & 0x8000) {
        signedAlignment = -signedAlignment;
    }
    if ((heapIdAndDirection & 0x7FFF) >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    func_02061358(allocator, (u32)GFL_HEAP_GetHeap(heapIdAndDirection & 0x7FFF), signedAlignment);
    gHeapManager.lastError = 0;
    return 1;

fail:
    return 0;
}







/*
 * BLOCKED on one relocation site: all 160 concrete bytes are correct, but
 * the call to sub_02060CD0 at +0054 has no witness. 0x02060CD0 (the
 * expanded-heap resize primitive in the NNS-shaped library block around
 * 0x02060000) has exactly one branch reference in the image and it is this
 * call; the neighbouring 0x02060CA0 used by sub_02030098 has four and
 * resolves fine. No cut exists inside a single function section, so
 * --suggest-split offers nothing. An EXACT entry for 0x02060CD0 promotes
 * this file unchanged, and promoting it in turn unblocks
 * src/pending/sub_020307E0.c, whose only unresolved site is this function.
 *
 * Resize in place: the realloc of this heap layer.
 *
 *   u32 sub_020302A4(void *p, u32 size)
 *
 * The block header is the same 0x1c bytes sub_02030098 reserves, so the
 * heap id is `((u16 *)p)[-14]` and the address handed to the expanded-heap
 * routines is p - 0x1c. The new request is size + 0x1c, and it is written
 * twice rather than bound to a local: the compiler recomputes `add r1, r8,
 * #0x1c` for the comparison instead of keeping the value the call already
 * needed, which is what a second occurrence of the expression looks like.
 *
 * sub_02060F90 returns the block's current size, sub_02060CD0 does the
 * resize and returns a size-shaped answer. The two failure tests differ by
 * direction, and that is the whole point of the branch:
 *
 *   growing  (old < new):  failure is a zero answer      -> code 4
 *   shrinking(old >= new): failure is the size unchanged -> code 5
 *
 * Both arms then do the same two things, set the result code and clear the
 * return value, and the compiler cross-jumps them into the shared
 * `moveq r1, r2` / `strheq r0, [r4, #0xe]`; they must be written out in
 * each arm (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 * The zero reused for the cleared result is the same register the
 * `lastError = 0` store just used.
 *
 * The two early failures share one `mov r0, #0` / `pop` epilogue reached
 * by branch, which needs an explicit `goto`: written as plain `return 0;`
 * the compiler predicates them inline as `movhs r0, #0` / `pophs` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020302A4.c \
 *       --func sub_020302A4 --addr 0x020302A4 --cc 1.1p1 --arm
 */
u32 sub_020302A4(void *mem, u32 newSize)
{
    struct BlockHeader *header;
    void *heap;
    u32 oldSize;
    u32 resultSize;
    u32 success;

    header = (struct BlockHeader *)((char *)mem - 0x1c);
    if (header->heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 2;
        goto fail;
    }
    heap = GFL_HEAP_GetHeap(header->heapId);
    if (heap == 0) {
        gHeapManager.lastError = 3;
        goto fail;
    }
    oldSize = sub_02060F90((char *)header);
    resultSize = sub_02060CD0(heap, header, newSize + 0x1c);
    gHeapManager.lastError = 0;
    success = 1;
    if (oldSize < newSize + 0x1c) {
        if (resultSize == 0) {
            gHeapManager.lastError = 4;
            success = 0;
        }
    } else {
        if (resultSize == oldSize) {
            gHeapManager.lastError = 5;
            success = 0;
        }
    }
    return success;

fail:
    return 0;
}







/*
 * Checked heap-id lookup that hands the arena straight on to sub_02060E6C
 * and returns what that returns; see src/matched/sub_02030428.c for the
 * shared preamble this family has in common.
 *
 *   void *sub_02030344(u32 heapId)
 *
 * The two calls are back to back with no register shuffle between them,
 * which is the nested-call form `sub_02060E6C(GFL_HEAP_GetHeap(heapId))`
 * rather than a local bound in between; the result is not touched after
 * the second call either, so the function is a plain tail return of it
 * (the `pop` after the `bl` is the one-section-per-function tail form, not
 * a missed tail call).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030344.c \
 *       --func sub_02030344 --addr 0x02030344 --cc 1.1p1 --arm
 */
void *sub_02030344(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    gHeapManager.lastError = 0;
    return (void *)sub_02060E6C(GFL_HEAP_GetHeap(heapId));

fail:
    return 0;
}







/*
 * Checked heap-id lookup handing the arena to sub_02060E94 with a mode of
 * 4; see src/matched/sub_02030428.c for the shared preamble this family
 * has in common. The same (arena, 4) pair appears in sub_02030958, the
 * out-of-memory reporter, so mode 4 is the heap-layer's own dump mode.
 *
 *   void *sub_0203038C(u32 heapId)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203038C.c \
 *       --func sub_0203038C --addr 0x0203038C --cc 1.1p1 --arm
 */
void *sub_0203038C(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    gHeapManager.lastError = 0;
    return (void *)sub_02060E94(GFL_HEAP_GetHeap(heapId), 4);

fail:
    return 0;
}







/*
 * Total size of a heap's arena, in bytes: the shared checked-heap-id
 * preamble (see src/matched/sub_02030428.c), then the arena's end pointer
 * at +0x1c minus the arena base.
 *
 *   u32 sub_020303D8(u32 heapId)
 *
 * The two failure paths reach the same `mov r0, #0` / `pop` differently,
 * and that asymmetry is the shape to reproduce: the out-of-range path
 * branches to it, while the null-arena path simply falls into it because
 * the whole success tail is predicated `ne`. Writing the success case as
 * an `if (arena != 0) { ... return ...; }` that falls through to the label
 * gives exactly that; an `if (arena == 0) goto fail;` guard instead emits
 * a second branch and loses the predication.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020303D8.c \
 *       --func sub_020303D8 --addr 0x020303D8 --cc 1.1p1 --arm
 */
u32 sub_020303D8(u32 heapId)
{
    struct ExpHeapHead *heap;

    heapId &= 0x7FFF;
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    heap = GFL_HEAP_GetHeap(heapId);
    if (heap != 0) {
        u32 end = (u32)heap->end;
        gHeapManager.lastError = 0;
        return end - (u32)heap;
    }

fail:
    return 0;
}






/*
 * Checked heap-id lookup: masks the direction flag out of a public heap
 * id, range-checks the index against the manager's heap count, records a
 * result code, and returns the heap's arena pointer.
 *
 *   void *sub_02030428(u32 heapId)
 *
 * This is one of a family of four functions in this unit that open with
 * exactly the same eight-instruction preamble (pool-load the manager, pool
 * load 0x7fff, `ldrh` the count at +8, mask, compare, and on the
 * out-of-range path `movhs r0, #1` / `strhhs r0, [r?, #0xe]` / `bhs`) and
 * differ only in what they do once the id is known good:
 *
 *   0x02030344  -> sub_02060E6C(arena)      returns the arena's first block
 *   0x02030428  -> arena                    (this function)
 *   0x0203046C  -> the heap's record index, 0xffff on failure
 *   0x020304CC  -> a plain 1/0 validity answer (packet pkt_020304CC)
 *
 * The conditional store of result code 1 costs nothing extra because the
 * `movhs r0, #1` that feeds it is also the value the compiler needs; the
 * success path's `lastError = 0` is a separate `mov r1, #0` because r0 is
 * already committed to the masked id being passed on.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030428.c \
 *       --func sub_02030428 --addr 0x02030428 --cc 1.1p1 --arm
 */
void *sub_02030428(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    gHeapManager.lastError = 0;
    return GFL_HEAP_GetHeap(heapId);

fail:
    return 0;
}






/*
 * Checked heap-id lookup returning the heap's u16 record field (the one
 * GFL_HEAP_GetAllocCount reads, the +0xc halfword of the per-heap record), or 0xffff
 * if the id is out of range; see src/matched/sub_02030428.c for the shared
 * preamble.
 *
 *   u16 sub_0203046C(u32 heapId)
 *
 * Two details pin the C here:
 *
 *  - The failure return is `rsb r0, r0, #0x10000`, not a fresh constant.
 *    r0 already holds the 1 that was stored as the result code, and the
 *    compiler rematerialises 0xffff as 0x10000 - 1 off it rather than
 *    spending a pool word, so the literal in the source really is 0xffff
 *    and the result-code store really does precede it.
 *  - The `lsl #16` / `lsr #16` pair on the success path is the u16 return
 *    type truncating a wider callee result, so GFL_HEAP_GetAllocCount must be
 *    declared here as returning `int`, not `u16`. src/matched/unit_0202FBAC.c
 *    declares it `u16` (correct for its own body, which returns a halfword
 *    load); the truncation only appears at this call site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203046C.c \
 *       --func sub_0203046C --addr 0x0203046C --cc 1.1p1 --arm
 */
u16 sub_0203046C(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    gHeapManager.lastError = 0;
    return (int)GFL_HEAP_GetAllocCount(heapId);

fail:
    return 0xFFFF;
}






/*
 * A halfword accessor at a negative offset from its argument: the pointer
 * is to a member partway into a larger object, and this reads a sibling
 * field 0x1c bytes before it. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020304B8.c \
 *       --func sub_020304B8 --addr 0x020304B8 --cc 1.1p1
 */
u16 sub_020304B8(void *mem)
{
    return *(u16 *)((char *)mem - 0x1c);
}






/*
 * Address of a field 4 bytes into the object that starts 0x1c bytes before
 * the argument: the compiler keeps the two constants as two instructions
 * (`sub #0x1c`, `add #4`) rather than folding them into one, which is what
 * two separate struct-member computations look like against a single
 * folded offset. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020304C0.c \
 *       --func sub_020304C0 --addr 0x020304C0 --cc 1.1p1
 */
void *sub_020304C0(void *mem)
{
    struct BlockHeaderNameView *header = (struct BlockHeaderNameView *)((char *)mem - 0x1c);
    return &header->name;
}






/*
 * Heap validity probe: the same two guards that open the raw allocator
 * sub_02030098, with the allocation itself removed.
 *
 *   BOOL sub_020304CC(u32 heapId)
 *
 * It masks the heap id with 0x7fff (bit 15 is the allocator's high/low
 * direction flag, meaningless here but still masked off), bounds-checks it
 * against gHeapManager.count, then resolves the arena through GFL_HEAP_GetHeap.
 * Each failure stamps its own code into gHeapManager.lastError, 1 for an id out
 * of range and 2 for an id that maps to no live heap, exactly the codes
 * sub_02030098 uses, and returns 0; success writes 0 and returns 1. The
 * callers treat the return as a pointer-ish truth value (see
 * src/pending/sub_0203084C.c), but the code here materialises a plain 1.
 *
 * Shape notes:
 *
 *  - The two failure returns share one `mov r0, #0` / `pop` epilogue at
 *    0x02030514 reached by branch, with statements (the lastError store, then
 *    the call) sitting between the guards. Plain `return 0;` in each arm
 *    inlines a `movhs r0, #0` / `pophs` pair instead and shifts the tail;
 *    only the explicit `goto fail;` reproduces the shared exit
 *    (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *  - The mask is a pool word, not an immediate: 0x7fff has no ARM
 *    rotated-immediate encoding, which is why `ldr r1, [pc, #0x44]` is
 *    scheduled up beside the gHeapManager load.
 *  - The out-of-range arm reuses r0 for both the lastError code and the
 *    `strh`, so the code constant 1 is written before the mask result is
 *    dead; that falls out of writing the store as the first statement of
 *    the arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020304CC.c \
 *       --func sub_020304CC --addr 0x020304CC --cc 1.1p1 --arm
 */
u32 sub_020304CC(u32 heapId)
{
    void *heap;

    heapId &= 0x7FFF;
    if (heapId >= gHeapManager.heapIdCount) {
        gHeapManager.lastError = 1;
        goto fail;
    }
    heap = GFL_HEAP_GetHeap(heapId);
    if (heap == 0) {
        gHeapManager.lastError = 2;
        goto fail;
    }
    gHeapManager.lastError = 0;
    return 1;

fail:
    return 0;
}






u16 GFL_HEAP_GetLastError(void)
{
    return gHeapManager.lastError;
}




/*
 * BLOCKED on one relocation site: all 144 concrete bytes are correct, but
 * the call to OS_CreateHeap at +0068 has no witness. 0x02086AF8 is called
 * exactly once in the whole image, here, so no `label` witness exists
 * outside the compared range, and a single function section cannot be cut,
 * so --suggest-split offers nothing. It closes only when some other TwlSDK
 * caller of OS_CreateHeap turns up, or when the SDK library block around
 * 0x02086AF8 is itself matched.
 *
 * Heap-4 bring-up: this is what carves the heap that GFL_HEAP_AllocSystem
 * (0x020305C4, this packet, EXACT) allocates from.
 *
 *   BOOL GFL_HEAP_InitSystemHeap(u32 size)
 *
 * Take the current arena low mark, pin the arena high mark at 0x02FE3000,
 * hand OS_InitAlloc a single heap of `size` bytes off the low mark, push
 * the low mark past whatever the allocator claimed, then create the heap
 * over the same span. The handle lands in gSystemHeap (0x02146964),
 * the second module-like global whose id table src/matched/GFL_HEAP_FreeSystem.c
 * frees; the +4 slot is an OSHeapHandle, which is why the failure test is
 * against -1.
 *
 * Shape notes:
 *
 *  - 0x02FE3000 is *not* one pool word. It is a pool word holding
 *    0x02FE0000, the base of the arm9_autoload1_main_twl region, plus an
 *    `add r1, r1, #0x3000`. Writing the constant, or an extern array at
 *    0x02FE0000 plus 0x3000, folds the offset into the relocation addend
 *    and loses four bytes; declaring the base as a *code* symbol and
 *    casting is what keeps the add, which is the tell that the original
 *    named a linker-defined region symbol rather than an address literal
 *    (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 *    47 other pool sites in the image hold 0x02FE3000 outright, so this
 *    site is the odd one out and the split is real evidence, not noise.
 *  - The store to gSystemHeap is written *before* the -1 test even
 *    though the `str` is scheduled after the `moveq`: writing the test
 *    first delays the pool load of the global past the compare and costs
 *    four bytes of diff without changing the instruction count.
 *  - `arenaLo + size` is spelled twice, once for OS_InitAlloc and once for
 *    OS_CreateHeap, and the compiler recomputes `add r2, r5, r8` each
 *    time; binding it to a local costs a callee-saved register.
 *  - The success flag and OS_InitAlloc's heap count share the constant 1
 *    in r7, and -1 is then derived from it as `sub r1, r7, #2`
 *    (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *  - The 0x2f80 bound is an inline `movhi r0, #0` / `pophi`: nothing
 *    precedes it, so no shared exit and no goto.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_HEAP_InitSystemHeap.c  *       --func GFL_HEAP_InitSystemHeap --addr 0x02030534 --cc 1.1p1 --arm
 */
BOOL GFL_HEAP_InitSystemHeap(u32 size)
{
    void *arenaLow;
    void *heapStart;
    s32 osHeap;
    BOOL success;

    if (size > 0x2F80) {
        return 0;
    }

    arenaLow = OS_GetArenaLo(4);
    OS_SetArenaHi(4, (u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3000);
    success = 1;
    heapStart = OS_InitAlloc(4, arenaLow, (u8 *)arenaLow + size, 1);
    OS_SetArenaLo(4, heapStart);
    osHeap = OS_CreateHeap(4, heapStart, (u8 *)arenaLow + size);
    gSystemHeap.heapHandle = osHeap;
    if (osHeap == -1) {
        success = 0;
    }
    return success;
}



/*
 * The allocation front door for heap 4, the heap GFL_HEAP_InitSystemHeap carves out
 * of the OS arena a few bytes earlier in this packet.
 *
 *   void *GFL_HEAP_AllocSystem(u32 size)
 *
 * This is the hidden second entry point of what the listing used to show
 * as one 176-byte function at 0x02030534. It saves nothing, because it is
 * a pure tail call, so disasm.py's lr-saving prologue sweep never labelled
 * it, and nothing in arm9 branches to it: its only reference anywhere in
 * the image is the pool word at 0x02030BC4, read by the veneer-shaped tail
 * call at 0x02030BBC (src/pending/sub_02030BBC.c, whose single unresolved
 * relocation this file closes). It is now seeded in
 * layout/function_starts.txt, which is what splits 0x02030534's extent.
 *
 * The heap handle is reloaded from gSystemHeap at the call rather than
 * cached, and the whole body is a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). The heap id 4 is
 * materialised last, into r0, because the tail call has already spent the
 * argument registers it could reuse.
 *
 * gSystemHeap's +4 slot is an OSHeapHandle; src/matched/GFL_HEAP_FreeSystem.c
 * calls the same slot `slotOfHeapId` and passes it as a pointer, which is the same
 * word under a different reading.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_AllocSystem.c \
 *       --func GFL_HEAP_AllocSystem --addr 0x020305C4 --cc 1.1p1 --arm
 */
void *GFL_HEAP_AllocSystem(u32 size)
{
    return OS_AllocFromHeap(4, gSystemHeap.heapHandle, size);
}



/*
 * Frees the id table of a second module-like global, 0x10 bytes after
 * gHeapManager (0x02146954, see src/matched/unit_0202FBAC.c), through
 * TwlSDK's OS_FreeToHeap on heap 4 (the same heap id GFL_HEAP_InitSystemHeap, a few
 * bytes earlier in this packet, allocates from with OS_AllocFromArenaLo).
 * The idx argument is loaded into r2 but never used by the call: OS_Free
 * ToHeap only reads its first two arguments, and the leftover third
 * register is exactly the shape
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * describes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_FreeSystem.c \
 *       --func GFL_HEAP_FreeSystem --addr 0x020305E4 --cc 1.1p1
 */
int GFL_HEAP_FreeSystem(u32 mem)
{
    OS_FreeToHeap(4, gSystemHeap.heapHandle, (void *)mem);
    return 1;
}




/*
 * Every one of the 68 concrete bytes is reproduced.  Blocked on: no evidence
 * class for 0x0202FC48.  It has no caller outside this range and no matched
 * entry, so the PC24 at +0x14 stays wildcarded, and it is not adjacent, so no
 * cut reaches it.  0x0202FC48 is a 380-byte initialiser that currently stops
 * four bytes short on register allocation alone; the analysis and everything
 * already ruled out are in docs/notes/sub_0202FC48.c.txt.  Closing that
 * function graduates this file unchanged.
 *
 * Bring the module up and, if that failed, hand the failure to the reporter.
 * The two notifications with a zero argument run either way; only the final
 * report is conditional.
 *
 * The `lsl #16` / `lsr #16` pairs on both arguments before the call are the
 * truncation into 0x0202FC48's two u16 parameters, so this function's own
 * parameters are the wider type: nothing else in the body produces them.
 *
 * The literal zero passed twice lives in the callee-saved r4 rather than
 * being rematerialised at each call site
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030608.c \
 *       --func sub_02030608 --addr 0x02030608 --cc 1.1p1 --arm
 */
void sub_02030608(u32 specs, u32 staticCount, u32 heapIdCount, u32 extraSize)
{
    int success;

    success = sub_0202FC48((const struct HeapSpec *)specs, staticCount, heapIdCount, extraSize);
    sub_02086580(0);
    sub_0208656C(0);
    if (success != 0) {
        return;
    }
    sub_02088234((void *)sub_02030524());
}




/*
 * Previously capped at MATCH: nothing outside this range branches to
 * 0x0202FDC4, so the PC24 at +0x0C had no witness of any class and no cut
 * reached it.  src/matched/sub_0202FDC4.c now reproduces that function's own
 * byte range, so the site resolves `matched` and this file is EXACT with the
 * C unchanged.
 *
 * Guard, then forward.  If the test at 0x0202FDC4 says the pair is already
 * accounted for the function returns without doing anything; otherwise the
 * work is handed to 0x020306A0 with a fresh object from 0x02030524 in front
 * of the two parameters.
 *
 * The result of 0x02030524 is spelled inline as the first argument rather
 * than bound to a local: the original sets r1 and r2 after the call, from
 * the two callee-saved copies of the parameters, and never touches r0, which
 * is what an unnamed call result in argument position looks like
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203064C.c \
 *       --func sub_0203064C --addr 0x0203064C --cc 1.1p1 --arm
 */
void sub_0203064C(u32 parentHeapId, u32 newHeapId, u32 size)
{
    if (sub_0202FDC4(parentHeapId, newHeapId, size) != 0) {
        return;
    }
    sub_020306A0((void *)sub_02030524(), (void *)parentHeapId, newHeapId);
}




/*
 * The same guard-then-forward shape as sub_0203064C beside it, over the other
 * binder: if 0x0202FE68 already accounted for the pair the function returns,
 * otherwise the work goes to 0x020306A0 with a fresh object in front of it.
 * Here the middle argument is a constant zero rather than a forwarded
 * parameter, and only the third parameter survives the call, which is why it
 * is the one copied into r4.
 *
 * The result of 0x02030524 is spelled inline as the first argument rather
 * than bound to a local: r1 and r2 are set after the call and r0 is never
 * touched
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030678.c \
 *       --func sub_02030678 --addr 0x02030678 --cc 1.1p1 --arm
 */
void sub_02030678(void *block, u32 size, u32 newHeapId)
{
    if (GFL_HEAP_RegisterBlockHeapImpl(block, size, newHeapId) != 0) {
        return;
    }
    sub_020306A0((void *)sub_02030524(), 0, newHeapId);
}




void GFL_HEAP_FatalError(int errorCode)
{
    switch (errorCode) {
    case 0:
        break;
    case 1:
        func_02088234();
        break;
    case 2:
        func_02088234();
        break;
    case 3:
        func_02088234();
        break;
    case 4:
        func_02088234();
        break;
    case 5:
        func_02088234();
        break;
    }
}
