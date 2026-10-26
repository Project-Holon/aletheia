/*
 * file:     nns_fnd_unitheap.c
 * unit:     yes
 * function: NNSi_FndPopFreeBlock, NNSi_FndAllocBlockFromHeap, NNSi_FndPushFreeBlock, NNSi_FndAllocFromExpHeapAllocator, NNSi_FndFreeToExpHeapAllocator, NNSi_FndAllocFromFrmHeapAllocator, NNSi_FndFreeToFrmHeapAllocator, NNSi_FndAllocFoundMBlock, NNSi_FndFreeToUnitHeapAllocator, NNSi_FndAllocFromVramAllocator, NNSi_FndFreeToVramAllocator
 * address:  0x02061224
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from nns_fnd_unitheap.c by tools/splitfile.py.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   NNS_FndAllocFromExpHeapEx  0x02060CA0  arm
 *   NNS_FndFreeToExpHeap  0x02060E30  arm
 *   NNS_FndAllocFromFrmHeapEx  0x02061124  arm
 *   OS_AllocFromHeap  0x020868E0  arm
 *   OS_FreeToHeap  0x020869E8  arm
 */
#include "nns_fnd_types.h"

struct ExpHeap;

#include "../types.h"

typedef struct NNSiFndUnitBlock {
    struct NNSiFndUnitBlock *next;
} NNSiFndUnitBlock;

typedef struct NNSiFndUnitHeap {
    NNSiFndHeapHead head;
    NNSiFndUnitBlock *freeList;
    u32 unitSize;
} NNSiFndUnitHeap;

typedef struct NNSiFndHeapRef {
    u32 id;
    NNSiFndUnitHeap *heap;
} NNSiFndHeapRef;

typedef struct NNSiFndAllocator {
    void *funcs;
    void *heap;
    u32 heapParam1;
    u32 heapParam2;
} NNSiFndAllocator;

#include "mi_memory.h"

#include "nns_fnd_expheap.h"


#include "nns_fnd_frameheap.h"

#include "../sdk_os.h"
#include "os_alloc.h"


NNSiFndUnitBlock *NNSi_FndPopFreeBlock(NNSiFndUnitBlock **pFreeList);

void *NNSi_FndAllocBlockFromHeap(NNSiFndUnitHeap *pHeap);

void NNSi_FndPushFreeBlock(NNSiFndUnitHeap *pHeap, void *block);

void *NNSi_FndAllocFromExpHeapAllocator(NNSiFndAllocator *pAllocator, u32 size);

void NNSi_FndFreeToExpHeapAllocator(NNSiFndAllocator *pAllocator, void *block);

void *NNSi_FndAllocFromFrmHeapAllocator(NNSiFndAllocator *pAllocator, u32 size);

void NNSi_FndFreeToFrmHeapAllocator(NNSiFndAllocator *pAllocator, void *block);

int NNSi_FndAllocFoundMBlock(NNSiFndHeapRef *pHeapRef, u32 unitIndex);

void NNSi_FndFreeToUnitHeapAllocator(NNSiFndAllocator *pAllocator, void *block);

void *NNSi_FndAllocFromVramAllocator(NNSiFndAllocator *pAllocator, u32 size);

void NNSi_FndFreeToVramAllocator(NNSiFndAllocator *pAllocator, void *ptr);

NNSiFndUnitBlock *NNSi_FndPopFreeBlock(NNSiFndUnitBlock **pFreeList)
{
    NNSiFndUnitBlock *pBlock = *pFreeList;
    if (pBlock != 0)
        *pFreeList = pBlock->next;
    return pBlock;
}

/*
 * A 64-byte allocate-or-fetch helper: it hands the address of the object's
 * field at +0x24 to NNSi_FndPopFreeBlock, and if that returns non-null clears the
 * block it belongs to with MIi_CpuClear32(0, p, o->unitSize).
 *
 * Two source shapes are load-bearing and both were measured against the bytes:
 *
 * 1. The guard must be written positively -- `if (p != 0) { ... }` -- not as
 *    an early `if (p == 0) return 0;`.  With the early return mwccarm 1.1p1
 *    hoists the `ldr r2, [r5, #0x28]` (the size) below the `beq` and the file
 *    is five sites wrong; with the body inside the arm the load is issued
 *    between the flag load and the mask, exactly as the original does.  See
 *    docs/idioms/a-guard-whose-arm-can-carry-the-body-is-not-predicated.md.
 * 2. The size has to reach the call through a named local (`u32 size;
 *    size = o->unitSize;`) rather than as the call's third argument written out
 *    at the call site: the local pins the load above the mask test, and
 *    nothing else in the function moves once both loads are in that order.
 *
 * The `and r0, r0, #0xff` before the `tst r0, #1` is the u8 narrowing of the
 * flag field; the field itself is a word (a plain `ldr`, not an `ldrb`), so
 * the cast is in the source, and `((u8)o->head.attribute) & 1` is the spelling that
 * keeps both instructions -- `(o->head.attribute & 0xff) & 1` folds the mask away and
 * costs four bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_FndAllocBlockFromHeap.c \
 *       --func NNSi_FndAllocBlockFromHeap --addr 0x0206123C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 2 relocation sites, all 2 resolved.
 */
void *NNSi_FndAllocBlockFromHeap(NNSiFndUnitHeap *pHeap)
{
    u32 size;
    void *pBlock = NNSi_FndPopFreeBlock(&pHeap->freeList);

    if (pBlock != 0) {
        size = pHeap->unitSize;
        if (((u8)pHeap->head.attribute) & 1) {
            MIi_CpuClear32(0, pBlock, size);
        }
    }
    return pBlock;
}

/*
 * Unit-heap free: pushes the block onto the free list at +0x24 of the
 * heap head (the same list NNSi_FndAllocBlockFromHeap pops through NNSi_FndPopFreeBlock).
 * Its only reference is the ARM pool word at 0x020612F4, the tail call
 * of the allocator-table entry 0x020612E8 (word at 0x020A16FC).
 */
void NNSi_FndPushFreeBlock(NNSiFndUnitHeap *heap, void *block)
{
    NNSiFndUnitBlock *b = (NNSiFndUnitBlock *)block;

    b->next = heap->freeList;
    heap->freeList = b;
}

/*
 * Allocator-table alloc for the expanded heap: tail call to
 * NNS_FndAllocFromExpHeapEx(allocator->heap, size, allocator->heapParam1).  Table word
 * 0x0206128C at 0x020A1708.
 */
void *NNSi_FndAllocFromExpHeapAllocator(NNSiFndAllocator *allocator, u32 size)
{
    return NNS_FndAllocFromExpHeapEx(allocator->heap, size, (s32)allocator->heapParam1);
}

/*
 * Allocator-table free for the expanded heap: tail call to
 * NNS_FndFreeToExpHeap(allocator->heap, block).  Table word 0x020612A0 at
 * 0x020A170C.
 *
 * NitroSystem fnd code, compiled like the fnd heap neighbours
 * (NNS_FndFreeByStateToFrmHeap) with ../2.0/sp2: dsi/1.1p1 issues the pool load after
 * the argument load, the transposition in
 * docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md.
 * The other four allocator stubs match under either compiler and use the
 * same one for consistency.
 */
void NNSi_FndFreeToExpHeapAllocator(NNSiFndAllocator *allocator, void *block)
{
    NNS_FndFreeToExpHeap(allocator->heap, block);
}

/*
 * Allocator-table alloc for the frame heap: tail call to
 * NNS_FndAllocFromFrmHeapEx(allocator->heap, size, allocator->heapParam1).  Table word
 * 0x020612B0 at 0x020A1700.
 */
void *NNSi_FndAllocFromFrmHeapAllocator(NNSiFndAllocator *allocator, u32 size)
{
    return NNS_FndAllocFromFrmHeapEx(allocator->heap, size, (s32)allocator->heapParam1);
}

/*
 * Allocator-table free for the frame heap: a frame heap frees only in
 * bulk, so the per-block free is empty.  Table word 0x020612C4 at
 * 0x020A1704.
 */
void NNSi_FndFreeToFrmHeapAllocator(NNSiFndAllocator *allocator, void *block)
{
    (void)allocator;
    (void)block;
}

/*
 * The tail `bl NNSi_FndAllocBlockFromHeap` at 0x020612E0 was the file's only MATCH site:
 * 0x0206123C had no `label` witness, because this call is the only branch to
 * it in the image.  Now that src/matched/NNSi_FndAllocBlockFromHeap.c is an EXACT entry,
 * the site resolves as `matched` and the file is EXACT (with a trailing `*`
 * for the unlabelled follower at 0x0206127C).
 *
 * The guard is an unsigned compare (`cmp r1, r2` / `movhi r0, #0` / `pophi`),
 * so the second parameter is `u32`, and the loaded field is passed on as r0:
 * `return NNSi_FndAllocBlockFromHeap(p);` -- the value handed back is the callee's own
 * result, which is why the call is not a tail call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNSi_FndAllocFoundMBlock.c \
 *       --func NNSi_FndAllocFoundMBlock --addr 0x020612C8 --arm --cc 1.1p1
 *   MATCH, 32 bytes, 1 relocation site, 0 resolved.
 */
int NNSi_FndAllocFoundMBlock(NNSiFndHeapRef *o, u32 i)
{
    NNSiFndUnitHeap *p = o->heap;

    if (i > p->unitSize) {
        return 0;
    }
    return (sptr)NNSi_FndAllocBlockFromHeap((NNSiFndUnitHeap *)p);
}

void NNSi_FndFreeToUnitHeapAllocator(NNSiFndAllocator *allocator, void *block)
{
    NNSi_FndPushFreeBlock((NNSiFndUnitHeap *)allocator->heap, block);
}

void *NNSi_FndAllocFromVramAllocator(NNSiFndAllocator *allocator, u32 size)
{
    return OS_AllocFromHeap((int)allocator->heapParam1, (sptr)allocator->heap, size);
}

void NNSi_FndFreeToVramAllocator(NNSiFndAllocator *allocator, void *ptr)
{
    OS_FreeToHeap((int)allocator->heapParam1, (sptr)allocator->heap, ptr);
}
