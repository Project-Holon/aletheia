/*
 * file:     unit_02060468_p07.c
 * unit:     yes
 * function: func_02060888, func_02060A08, func_02060ABC, func_02060B6C, func_02060C5C, func_02060C94, func_02060CA0
 * address:  0x02060888
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
 *   func_02060764   0x02060764  arm
 *   func_02060790   0x02060790  arm
 *   func_020607B8   0x020607B8  arm
 *   func_020607E8   0x020607E8  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02060888  0x02060888  arm
 *   func_02060814  0x02060814  arm
 *   func_02060A08  0x02060A08  arm
 *   func_02060ABC  0x02060ABC  arm
 */
struct ExpHeap;
struct ExpHeapLists;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct MBlock {
    u16            signature;
    u16            attr;
    u32            size;
    struct MBlock *prev;
    struct MBlock *next;
};

struct MBlockList {
    struct MBlock *head;
    struct MBlock *tail;
};

struct ExpHeapLists {
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
};

struct MemRegion {
    int start;
    int end;
};

typedef signed int     s32;

struct ExpHeap {
    u8                pad_00[0x24];
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
};

typedef int            BOOL;

typedef struct MBlockHead MBlockHead;

struct MBlockHead {
    u16         signature;
    u16         attribute;
    u32         blockSize;
    MBlockHead *pMBHeadPrev;
    MBlockHead *pMBHeadNext;
};

typedef struct { MBlockHead *head; MBlockHead *tail; } MBlockList;

typedef struct { void *start; void *end; } MemRegion;

typedef struct { MBlockList mbFreeList; } ExpHeapHead;

extern void func_02060764(int *out, int *blk);
extern void *func_02060790(int *p, int *node);
extern void *func_020607B8(int *p, void *node, int *a);
extern void *func_020607E8(int *p, int v);
extern void           MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void *func_02060888(struct ExpHeapLists *heap, struct MBlock *block, void *ptr, u32 size, u16 fromTail);
BOOL func_02060B6C(ExpHeapHead *pEHHead, const MemRegion *pRegion);
extern void *func_02060814(struct ExpHeap *heap, void *lo, u32 attr);
extern void func_0206074C(void *heap);
void *func_02060C5C(void *start, u32 size, u32 attr);
void func_02060C94(void *heap);
extern void *func_02060A08(struct ExpHeap *heap, u32 size, s32 align);
extern void *func_02060ABC(struct ExpHeap *heap, u32 size, s32 align);


/*
 * The expanded heap's carve: the allocator's back end, entered from
 * func_02060A08 (head of the free list) and func_02060ABC (tail of it) with
 * the block they picked and the data address it will hand out.  The block is
 * unlinked from the free list, its extent read with func_02060764, and the
 * new allocation is cut out of it: whatever is left in front of the new
 * block and whatever is left behind it become two free blocks (signature
 * 0x4652) around the new one (signature 0x5544), which goes back on the used
 * list at the end.  A remainder smaller than 0x14 cannot hold a header plus
 * one word, so the cut is snapped to the block's own edge instead and the
 * pair handed to func_020607E8 degenerates to a zero-length region.
 *
 * Argument 5 is the direction flag from the caller and lands in bit 15 of the
 * new block's attribute; its low byte is the heap's group id and bits 8..14
 * the distance to the preceding block, which is what func_02060764 reads
 * back.  It arrives as a halfword, so the parameter is declared u16 even
 * though both callers pass an int.
 *
 * Three shapes are load-bearing:
 *  - The first 2-word region is two scalars, the other two are
 *    `struct MemRegion`.  Three structs cost a sixth callee-saved register
 *    (r9) and 24 bytes, because then both `func_02060764(&rgn, ...)` and
 *    `func_020607E8(&rgn, ...)` name one object and mwcc hoists `sp+0x10`
 *    into r4; the scalars keep the two `add r0, sp, #0x10` apart, the second
 *    site spelling the same word as `&end - 1`.
 *  - The region is passed to MIi_CpuClear32 through the `sz` local, which is
 *    what puts the argument setup in the condition's block: the branch is
 *    the `tst` of the heap attribute and the difference is scheduled into
 *    its shadow (a `sub` without the S bit, so the flags still belong to the
 *    `tst`).  Written inline, mwcc tests the difference itself with a second
 *    `subs`/branch and the setup sinks into the guarded block.
 *  - The attribute is built as three clear-then-set statement pairs, not
 *    three masked assignments: the pairs are what emit the two stores per
 *    field the original has, and the value of each field passes through the
 *    same `sz` local.  Field 2 keeps the u16 truncation in `sz` and shifts at
 *    the OR (`(sz & 0x7f) << 8`); a pre-shifted value moves the truncation to
 *    a different register and four instructions differ.  The attribute read
 *    is a `(u8)` cast, since a bare `& 0xff` folds away and loses the
 *    `and r0, r0, #0xff`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060888.c \
 *       --func func_02060888 --addr 0x02060888 --cc 1.1p1 --arm
 */
void *func_02060888(struct ExpHeapLists *heap, struct MBlock *block, void *ptr,
                    u32 size, u16 fromTail)
{
    int              end;
    int              start;
    struct MemRegion rest;
    struct MemRegion alloc;
    struct MBlock   *prev;
    struct MBlock   *node;
    u32              sz;

    func_02060764(&start, (int *)block);
    rest.end = end;
    end = (int)ptr - 0x10;
    rest.start = (int)(size + (u32)ptr);

    prev = func_02060790((int *)(&heap->freeList), (int *)block);
    if ((u32)(end - start) < 0x14) {
        end = start;
    } else {
        prev = func_020607B8((int *)(&heap->freeList), func_020607E8(&end - 1, 0x4652),
                             (int *)prev);
    }
    if ((u32)(rest.end - rest.start) < 0x14) {
        rest.start = rest.end;
    } else {
        func_020607B8((int *)(&heap->freeList), func_020607E8((int *)&rest, 0x4652), (int *)prev);
    }

    sz = (u32)(rest.start - end);
    if ((u8)((u32 *)heap)[-1] & 1) {
        MIi_CpuClear32(0, (void *)end, sz);
    }

    alloc.start = (int)ptr - 0x10;
    alloc.end = rest.start;
    node = func_020607E8((int *)&alloc, 0x5544);
    node->attr = node->attr & ~0x8000;
    node->attr = node->attr | (u16)(fromTail << 15);
    sz = (u16)((u32)node - (u32)end);
    node->attr = node->attr & ~0x7f00;
    node->attr = node->attr | ((sz & 0x7f) << 8);
    sz = heap->groupId & 0xff;
    node->attr = node->attr & ~0xff;
    node->attr = node->attr | sz;
    func_020607B8((int *)(&heap->usedList), node, (int *)heap->usedList.tail);
    return ptr;
}





/*
 * The head-end half of the expanded-heap allocator that sits under the game's
 * own heap layer: src/matched/sub_02030098.c calls func_02060CA0, which
 * dispatches here for a non-negative alignment and to func_02060ABC for a
 * negative one.
 *
 * Walk the free list from the head keeping the smallest block that can still
 * hold the request once its data start is rounded up to the alignment, then
 * hand the winner to func_02060888, which carves the region out of the block
 * and moves it to the used list.  The search stops early on the first hit
 * when the heap's allocation mode is "first", and on an exact size fit in
 * either mode.
 *
 * The heap handle is 0x24 bytes of common header followed by the expanded
 * heap's own record: free-list head and tail at +0x24 and +0x28, used-list
 * head and tail at +0x2c and +0x30, group id at +0x34 and the feature
 * halfword at +0x36 whose bit 0 is the allocation mode.  A free block carries
 * a 0x10-byte header, which is why the data start is `block + 0x10`.
 *
 * The rounding mask is loop-invariant and the compiler hoists both halves of
 * it (`sub r2, r2, #1` / `mvn r5, r2`) above the loop on its own; writing it
 * as a local before the loop is the same code.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060A08.c \
 *       --func func_02060A08 --addr 0x02060A08 --cc 1.1p1 --arm
 */
void *func_02060A08(struct ExpHeap *heap, u32 size, s32 align)
{
    int            allocFirst;
    struct MBlock *found;
    struct MBlock *block;
    u32            foundSize;
    void          *foundPtr;

    allocFirst = (u16)(heap->feature & 1) == 0;
    found = 0;
    foundPtr = 0;
    foundSize = 0xFFFFFFFF;

    for (block = heap->freeList.head; block != 0; block = block->next) {
        u8   *base = (u8 *)block + 0x10;
        u8   *ptr = (u8 *)(((align - 1) + (u32)base) & ~(align - 1));
        u32   offset = (u32)(ptr - base);

        if (block->size >= size + offset && foundSize > block->size) {
            found = block;
            foundSize = block->size;
            foundPtr = ptr;
            if (allocFirst || foundSize == size) {
                break;
            }
        }
    }

    if (found == 0) {
        return 0;
    }
    return func_02060888((struct ExpHeapLists *)(&heap->freeList), found, foundPtr, size, 0);
}



/*
 * The tail-end half of the expanded-heap allocator, the mirror of
 * func_02060A08: func_02060CA0 dispatches here when the caller asked for a
 * negative alignment, which is how src/matched/sub_02030098.c spells "take
 * this block from the high end of the heap".
 *
 * The walk runs from the free list's tail through the `prev` link at +0x08
 * (the head walk uses `next` at +0x0c), and the candidate address is the end
 * of the block minus the request rounded *down* to the alignment, so the
 * rejection test is a signed `subs`/`bmi` against the block's own data start
 * rather than the head walk's unsigned size comparison.  The same
 * smallest-block-wins rule and the same two early exits apply.
 *
 * The rounding mask is one register here, not two: rounding down needs only
 * `~(align - 1)` and the compiler rewrites `sub`/`mvn` in place on the
 * alignment argument.
 *
 * The last argument of func_02060888 is the direction flag, 0 from the head
 * walk and 1 here, which is what tells the carve which side of the block the
 * remainder stays on.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060ABC.c \
 *       --func func_02060ABC --addr 0x02060ABC --cc 1.1p1 --arm
 */
void *func_02060ABC(struct ExpHeap *heap, u32 size, s32 align)
{
    int            allocFirst;
    struct MBlock *found;
    struct MBlock *block;
    u32            foundSize;
    void          *foundPtr;

    allocFirst = (u16)(heap->feature & 1) == 0;
    found = 0;
    foundPtr = 0;
    foundSize = 0xFFFFFFFF;

    for (block = heap->freeList.tail; block != 0; block = block->prev) {
        u8   *base = (u8 *)block + 0x10;
        u8   *end = (u8 *)(block->size + (u32)base);
        u8   *ptr = (u8 *)(((u32)end - size) & ~(align - 1));

        if ((s32)(ptr - base) >= 0 && foundSize > block->size) {
            found = block;
            foundSize = block->size;
            foundPtr = ptr;
            if (allocFirst || foundSize == size) {
                break;
            }
        }
    }

    if (found == 0) {
        return 0;
    }
    return func_02060888((struct ExpHeapLists *)(&heap->freeList), found, foundPtr, size, 1);
}

static inline void *AddU32ToPtr(void *ptr, u32 val) { return (void *)(val + (u32)ptr); }

static inline void *GetMemPtrForMBlock(MBlockHead *p) { return AddU32ToPtr(p, sizeof(MBlockHead)); }

static inline void *GetMBlockEndAddr(MBlockHead *p) { return AddU32ToPtr(GetMemPtrForMBlock(p), p->blockSize); }

static inline u32 GetOffsetFromPtr(void *start, void *end) { return (u32)end - (u32)start; }

static inline MBlockHead *InitFreeMBlock(MemRegion *r) { return func_020607E8((int *)r, 0x4652); }

/*
 * NitroSystem fnd expanded heap, RecycleRegion: return a region to the free
 * list, coalescing with the free block that starts at its end and the one
 * that ends at its start, and drop it if it is smaller than a block header
 * (0x10).  func_02060790 is RemoveMBlock, func_020607B8 InsertMBlock and
 * func_020607E8 InitMBlock (called with the 'FR' free-block signature 0x4652
 * through an inline InitFreeMBlock).
 *
 * docs/notes/pkt_02060B6C.c.txt stood at 52 bytes with a volatile region
 * pointer and a hand-built loop.  The library's own shape closes it: the
 * region is copied BY VALUE (`MemRegion freeRgn = *pRegion;`, which is the
 * image's two loads before `mov r6, r0`), the walk is a plain `for` with
 * `continue` (the predicated `movlo` is the one-statement arm), the pointer
 * is NOT volatile, and the block end address goes through small inline
 * helpers whose add is written `val + (u32)ptr` -- `(u32)ptr + val` swaps
 * the two registers of both end-address sums (4 bytes).  1.1p1; ../2.0/sp2
 * is also byte-exact on this source.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02060B6C.c \
 *       --func func_02060B6C --addr 0x02060B6C --arm --cc 1.1p1
 */
BOOL func_02060B6C(ExpHeapHead *pEHHead, const MemRegion *pRegion)
{
    MBlockHead *pBlkPrFree = 0;
    MemRegion freeRgn = *pRegion;

    {
        MBlockHead *pBlk;
        for (pBlk = pEHHead->mbFreeList.head; pBlk; pBlk = pBlk->pMBHeadNext)
        {
            if ((void *)pBlk < pRegion->start)
            {
                pBlkPrFree = pBlk;
                continue;
            }
            if ((void *)pBlk == pRegion->end)
            {
                freeRgn.end = GetMBlockEndAddr(pBlk);
                (void)func_02060790((int *)(&pEHHead->mbFreeList), (int *)pBlk);
            }
            break;
        }
    }

    if (pBlkPrFree && GetMBlockEndAddr(pBlkPrFree) == pRegion->start)
    {
        freeRgn.start = pBlkPrFree;
        pBlkPrFree = func_02060790((int *)(&pEHHead->mbFreeList), (int *)pBlkPrFree);
    }

    if (GetOffsetFromPtr(freeRgn.start, freeRgn.end) < sizeof(MBlockHead))
    {
        return 0;
    }

    (void)func_020607B8((int *)(&pEHHead->mbFreeList), InitFreeMBlock(&freeRgn), (int *)pBlkPrFree);
    return 1;
}



/*
 * The expanded heap's create front door: word-align the arena the caller
 * handed over (start rounded up, end rounded down), reject it if the rounding
 * inverted the range or left less than 0x4c bytes -- the 0x38-byte heap
 * handle plus one 0x10-byte block header plus a word -- and otherwise hand
 * the aligned pair to func_02060814, which lays the handle out in place.
 *
 * Two shapes are load-bearing.  The end address is `size + (u32)start`, not
 * `start + size`: the image's `add r1, r1, r0` accumulates into the size
 * register, which is the commutative-operand-order tell.  And the two
 * rejections are ONE `||`, not two `if`s: the image's `bhi` jumps to the same
 * `mov r0, #0` / `pop` the length test falls into, which a chain of separate
 * `if`s cannot reach -- mwcc if-converts each one into its own
 * `movhi`/`pophi` pair instead and four instructions differ.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060C5C.c \
 *       --func func_02060C5C --addr 0x02060C5C --cc 1.1p1 --arm
 */
void *func_02060C5C(void *start, u32 size, u32 attr)
{
    void *end = (void *)((size + (u32)start) & ~3);
    void *lo  = (void *)(((u32)start + 3) & ~3);

    if (lo > end || (u32)((u8 *)end - (u8 *)lo) < 0x4c) {
        return 0;
    }
    return func_02060814(lo, end, attr);
}


void func_02060C94(void *heap){ func_0206074C(heap); }


/*
 * The expanded-heap allocator's front door, and the function
 * src/matched/sub_02030098.c calls once it has picked the arena: round the
 * request up to a word (a zero-byte request still costs one word, which is
 * what makes an empty allocation a distinct pointer), then walk the free list
 * from the head for a non-negative alignment or from the tail for a negative
 * one, the sign being how the caller spells "high end of the heap".
 *
 * The sign test is scheduled into the rounding: `cmp r2, #0` sits between the
 * `add` and the `bic` because both halves of the rounding are on the critical
 * path of neither branch.  The two calls are not tail calls even though
 * nothing follows them, since each is reached through its own `pop`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060CA0.c \
 *       --func func_02060CA0 --addr 0x02060CA0 --cc 1.1p1 --arm
 */
void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align)
{
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;

    if (align >= 0) {
        return func_02060A08(heap, size, align);
    }
    return func_02060ABC(heap, size, -align);
}
