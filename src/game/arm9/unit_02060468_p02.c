/*
 * file:     unit_02060468_p02.c
 * unit:     yes
 * function: func_02060814, func_02060888, func_02060A08, func_02060ABC, func_02060B6C, func_02060C5C, func_02060C94, func_02060CA0, func_02060CD0, func_02060E30, func_02060E6C, func_02060E94, func_02060F18, func_02060F40, func_02060F50, func_02060F90, func_02060F98
 * address:  0x02060814
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020606D0  0x020606D0  arm
 *   func_020607E8  0x020607E8  arm
 *   func_02060764   0x02060764  arm
 *   func_02060790   0x02060790  arm
 *   func_020607B8   0x020607B8  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   sub_02060764   0x02060764  arm
 *   sub_02060790   0x02060790  arm
 *   sub_020607B8   0x020607B8  arm
 *   sub_020607E8   0x020607E8  arm
 *   sub_02060B6C   0x02060B6C  arm
 *   func_02091588  0x02091588  arm
 */
struct MBlock;
struct ExpHeap_02060888;
struct ExpHeapLists;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct MBlockList_02060814 {
    struct MBlock *head;
    struct MBlock *tail;
};

struct ExpHeap_02060814 {
    u8                pad_00[0x18];
    void             *lo;
    void             *hi;
    u32               attr;
    struct MBlockList_02060814 freeList;
    struct MBlockList_02060814 usedList;
    u16               groupId;
    u16               feature;
    u8                pad_38[0];
};

struct MBlock {
    u16            signature;
    u16            attr;
    u32            size;
    struct MBlock *prev;
    struct MBlock *next;
};

struct ExpHeapLists {
    struct MBlockList_02060814 freeList;
    struct MBlockList_02060814 usedList;
    u16               groupId;
    u16               feature;
};

struct MemRegion {
    int start;
    int end;
};

typedef signed int     s32;

struct ExpHeap_02060888 {
    u8                pad_00[0x24];
    struct MBlockList_02060814 freeList;
    struct MBlockList_02060814 usedList;
    u16               groupId;
    u16               feature;
};

typedef int            BOOL;

typedef struct MBlockHead_02060814 MBlockHead_02060814;

struct MBlockHead_02060814 {
    u16         signature;
    u16         attribute;
    u32         blockSize;
    MBlockHead_02060814 *pMBHeadPrev;
    MBlockHead_02060814 *pMBHeadNext;
};

typedef struct { MBlockHead_02060814 *head; MBlockHead_02060814 *tail; } MBlockList_02060814;

typedef struct { void *start; void *end; } MemRegion;

typedef struct { MBlockList_02060814 mbFreeList; } ExpHeapHead;

struct MBlockHead_02060CD0 {
    u16 signature;
    u16 attribute;
    u32 blockSize;
    struct MBlockHead_02060CD0 *prev;
    struct MBlockHead_02060CD0 *next;
};

struct MBlockList_02060CD0 {
    struct MBlockHead_02060CD0 *head;
    struct MBlockHead_02060CD0 *tail;
};

struct ExpHeapHead {
    struct MBlockList_02060CD0 freeList;
    struct MBlockList_02060CD0 usedList;
    u16 groupId;
    u16 feature;
};

struct HeapHead {
    u32 pad[8];
    u32 attribute;
    struct ExpHeapHead exp;
};

struct Region {
    u32 start;
    u32 end;
};

struct MBlockList {
    struct MBlock *head;
    struct MBlock *tail;
};

struct ExpHeap {
    u8                pad_00[0x24];
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
};

struct HeapBlock {
    u32 unk_00;
    u32 size;
    u32 unk_08;
    struct HeapBlock *next;
};

struct Heap {
    u8 pad_00[0x24];
    struct HeapBlock *head;
};

extern void           func_020606D0(struct ExpHeap_02060814 *h, void *sig, void *self,
                                    void *lo, u32 attr);
extern void *func_020607E8(int *p, int v);
extern void func_02060764(int *out, int *blk);
extern void *func_02060790(int *p, int *node);
extern void *func_020607B8(int *p, void *node, int *a);
extern void           MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void func_0206074C(void *heap);
extern void sub_02060764(int *out, int *blk);
extern void *sub_02060790(int *p, int *node);
extern void *sub_020607E8(int *p, int v);
extern void *sub_020607B8(int *p, void *node, int *a);
extern s32 sub_02060B6C(struct ExpHeapHead *heap, struct Region *rgn);
extern s32 func_02091588(s32 x);
void *func_02060814(struct ExpHeap_02060814 *heap, void *lo, u32 attr);
void *func_02060888(struct ExpHeapLists *heap, struct MBlock *block, void *ptr, u32 size, u16 fromTail);
void *func_02060A08(struct ExpHeap_02060888 *heap, u32 size, s32 align);
void *func_02060ABC(struct ExpHeap_02060888 *heap, u32 size, s32 align);
BOOL func_02060B6C(ExpHeapHead *pEHHead, const MemRegion *pRegion);
void *func_02060C5C(void *start, u32 size, u32 attr);
void func_02060C94(void *heap);
void *func_02060CA0(struct ExpHeap_02060888 *heap, u32 size, s32 align);
u32 func_02060CD0(struct HeapHead *heap, void *memBlock, u32 size);
void func_02060E30(struct ExpHeap *heap, void *block);
int func_02060E6C(int *p);
s32 func_02060E94(struct Heap *heap, s32 x);
u32 func_02060F18(char *p, u32 v);
u16 func_02060F40(char *p, u16 v);
void func_02060F50(int *p, void (*fn)(void *, void *, int), int ctx);
int func_02060F90(char *p);
u8 func_02060F98(char *p);




/*
 * COMPILER PIN: this function is byte-exact only under `--cc ../2.0/sp2` and
 * is DIFF under the project default dsi/1.1p1.  Every instruction and both
 * relocations are right under 1.1p1 too -- the residue is the signature
 * documented in docs/FRONTEND-PINS.md and in the compiler-pin section of
 * docs/families/cluster_020737C0.h: the function materialises the literal 0
 * at two separate points, 1.1p1 pools it into a callee-saved register and
 * reuses it, which widens the prologue to `push {r4, r5, lr}` where the image
 * has `push {r3, r4, lr}` and shifts every later register by one.  sp2
 * rematerialises `mov r0, #0` and `mov r1, #0` exactly as the image does.
 * The C body is identical under both front ends; only the pin differs.
 *
 * The expanded heap's layout pass, reached from func_02060C5C once the arena
 * has been word-aligned and size-checked.  The 0x38-byte handle is written at
 * the arena's own start: func_020606D0 fills the common header (signature,
 * bounds, attribute, child list) and the rest of this function lays out the
 * expanded heap's own record -- group id and feature halfwords at +0x34/+0x36,
 * a single free block spanning the whole remaining arena on the free list at
 * +0x24/+0x28, and an empty used list at +0x2c/+0x30.
 *
 * Argument order to func_020606D0 is read off the register moves, not guessed:
 * `mov r3, r1` puts this function's own second parameter in the FOURTH
 * argument slot and `ldr r1, [pc, #0x50]` puts the 'EXPH' signature word
 * (0x45585048, at the pool word 0x02060880) in the second, so the call is
 * (heap, signature, heap + 0x38, lo, attr).
 *
 * The `bic r0, r0, #1` at +0x28 is load-bearing and does not survive a
 * constant-folded spelling: `feature = 0; ... feature & ~1` folds to a plain
 * zero and four bytes are lost.  Storing 0 to the field and then reading the
 * FIELD back for the clear is what keeps it, the
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060814.c \
 *       --func func_02060814 --addr 0x02060814 --cc ../2.0/sp2 --arm
 */
void *func_02060814(struct ExpHeap_02060814 *heap, void *lo, u32 attr)
{
    int  pair[2];
    u16  feature;

    func_020606D0((struct ExpHeap_02060814 *)heap, (void *)0x45585048, (void *)((u8 *)heap + 0x38), lo, attr);

    heap->groupId = 0;
    heap->feature = 0;
    heap->feature = heap->feature & ~1;

    pair[0] = (int)heap->lo;
    pair[1] = (int)heap->hi;
    heap->freeList.head = func_020607E8(pair, 0x4652);
    heap->freeList.tail = heap->freeList.head;
    heap->usedList.head = 0;
    heap->usedList.tail = 0;
    return heap;
}





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
void *func_02060A08(struct ExpHeap_02060888 *heap, u32 size, s32 align)
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
void *func_02060ABC(struct ExpHeap_02060888 *heap, u32 size, s32 align)
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




static inline void *GetMemPtrForMBlock(MBlockHead_02060814 *p) { return AddU32ToPtr(p, sizeof(MBlockHead_02060814)); }




static inline void *GetMBlockEndAddr(MBlockHead_02060814 *p) { return AddU32ToPtr(GetMemPtrForMBlock(p), p->blockSize); }




static inline u32 GetOffsetFromPtr(void *start, void *end) { return (u32)end - (u32)start; }




static inline MBlockHead_02060814 *InitFreeMBlock(MemRegion *r) { return func_020607E8((int *)r, 0x4652); }




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
    MBlockHead_02060814 *pBlkPrFree = 0;
    MemRegion freeRgn = *pRegion;

    {
        MBlockHead_02060814 *pBlk;
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

    if (GetOffsetFromPtr(freeRgn.start, freeRgn.end) < sizeof(MBlockHead_02060814))
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
    return func_02060814((struct ExpHeap_02060814 *)lo, end, attr);
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
void *func_02060CA0(struct ExpHeap_02060888 *heap, u32 size, s32 align)
{
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;

    if (align >= 0) {
        return func_02060A08((struct ExpHeap_02060888 *)heap, size, align);
    }
    return func_02060ABC((struct ExpHeap_02060888 *)heap, size, -align);
}



/*
 * NNS_FndResizeForMBlockExpHeap shape: resize a used block of the expanded
 * heap in place.  Grow: find the free block that starts at this block's end,
 * take its region, unlink it, give the caller what it asked for (absorbing a
 * remainder under 0x10), re-insert the rest as a new 'FR' (0x4652) block, and
 * clear the grown part when heap attribute bit 0 asks for it.  Shrink: hand
 * the tail back through RecycleRegion and restore the old size on failure.
 * Returns the block's resulting size.
 *
 * Closed wave 12 from the 26-bytes-out source in
 * docs/notes/sub_02060CD0.c.txt.  The residue was the COMPILER, not the loop:
 * under ../2.0/sp2 the plain NitroSystem search
 *     for (p = head; p; p = p->next) { if (p == end) break; }
 * compiles to the image's `cmp / ldrne / cmpne / bne` loop, and the shrink
 * arm's volatile re-read is no longer needed (plain field read, EXACT).
 * dsi/1.1p1 with that loop is 356 bytes; this cluster's first sp2 pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02060CD0.c \
 *       --func func_02060CD0 --addr 0x02060CD0 --arm --cc ../2.0/sp2
 *   EXACT, 352 bytes, 6 of 6 relocation sites resolved (sp2p2 EXACT too).
 */
u32 func_02060CD0(struct HeapHead *heap, void *memBlock, u32 size)
{
    struct ExpHeapHead *pEHHead;
    struct MBlockHead_02060CD0 *pMBlkFr;
    u32 crBlockSize;
    struct MBlockHead_02060CD0 *pMBHead;
    struct Region rgnFree;
    struct Region rgn;

    pEHHead = &heap->exp;
    pMBHead = (struct MBlockHead_02060CD0 *)memBlock - 1;
    size = (size + 3) & ~3;
    crBlockSize = pMBHead->blockSize;

    if (size == crBlockSize) {
        return size;
    }

    if (size > crBlockSize) {
        struct MBlockHead_02060CD0 *crUsedEnd = (struct MBlockHead_02060CD0 *)(crBlockSize + (u32)(pMBHead + 1));
        u32 oldStart;
        struct MBlockHead_02060CD0 *pMBlkFrPrev;
        u32 fillSize;
        u8 attr;

        for (pMBlkFr = pEHHead->freeList.head; pMBlkFr; pMBlkFr = pMBlkFr->next) {
            if (pMBlkFr == crUsedEnd)
                break;
        }
        if (pMBlkFr == 0 || size > crBlockSize + 0x10 + pMBlkFr->blockSize) {
            return 0;
        }

        sub_02060764((int *)(&rgnFree), (int *)pMBlkFr);
        pMBlkFrPrev = sub_02060790((int *)(&pEHHead->freeList), (int *)pMBlkFr);

        oldStart = rgnFree.start;
        rgnFree.start = size + (u32)memBlock;
        if (rgnFree.end - rgnFree.start < 0x10) {
            rgnFree.start = rgnFree.end;
        }
        pMBHead->blockSize = rgnFree.start - (u32)memBlock;
        if (rgnFree.end - rgnFree.start >= 0x10) {
            sub_020607B8((int *)(&pEHHead->freeList), sub_020607E8((int *)(&rgnFree), 0x4652), (int *)pMBlkFrPrev);
        }
        attr = (u8)heap->attribute;
        fillSize = rgnFree.start - oldStart;
        if ((attr & 1) != 0) {
            MIi_CpuClear32(0, (void *)oldStart, fillSize);
        }
    } else {
        rgn.start = size + (u32)memBlock;
        rgn.end = pMBHead->blockSize + (u32)(pMBHead + 1);
        pMBHead->blockSize = size;
        if (sub_02060B6C(pEHHead, &rgn) == 0) {
            pMBHead->blockSize = crBlockSize;
        }
    }

    return pMBHead->blockSize;
}



/*
 * The expanded heap's free primitive: read the block's own extent with
 * func_02060764, unlink its header from the heap's used list (+0x2c) and hand
 * the extent to func_02060B6C, which splices it back into the free list at
 * +0x24 and merges it with any adjacent free block.
 *
 * The 2-word extent is two separate scalars, not an int[2] and not a struct,
 * and that is load-bearing: mwcc caches the address of one object in a
 * callee-saved register (r4) across the second call when the two call sites
 * name the same object, collapsing `add r0, sp, #0` / `add r1, sp, #0` into
 * one `add r4, sp, #0` plus a `mov`, four bytes longer.  Two distinct
 * variables are different objects to its alias analysis, so each site
 * rematerialises `sp + 0` and the original's 60 bytes come out.
 *
 * The second site spells the base as `&end - 1`, since `end` is the *later*
 * declaration and mwcc lays locals out with the later declaration at the
 * lower address: `end` sits at sp+0 and `start` at sp+4, so `&end - 1` and the
 * block's own base (`&start`, as func_02060764 must be handed) are the same
 * word.  The pair is not a struct or an array: with one object named at both
 * sites the compiler folds the two addresses into one value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060E30.c \
 *       --func func_02060E30 --addr 0x02060E30 --cc 1.1p1 --arm
 */
void func_02060E30(struct ExpHeap *heap, void *block)
{
    struct MBlock *hdr = (struct MBlock *)((u8 *)block - 0x10);
    int            end;
    int            start;

    func_02060764(&start, (int *)hdr);
    func_02060790((int *)(&heap->usedList), (int *)hdr);
    func_02060B6C((ExpHeapHead *)(&heap->freeList), (const MemRegion *)(&end - 1));
}


int func_02060E6C(int *p)
{
    int *q = (int *)p[9];
    int total = 0;
    if (q == 0)
        return 0;
    do {
        total += q[1];
        q = (int *)q[3];
    } while (q != 0);
    return total;
}



/*
 * Largest-free-space search over the allocator's block list hanging off the
 * heap object at +0x24.  Each node is {u32, u32 size, u32, Node *next} with
 * its payload at +0x10; the size passed in is first folded through
 * func_02091588 (abs), so it doubles as the alignment: the aligned start of
 * the candidate payload is (size - 1 + payload) & ~(size - 1), and what is
 * left between that start and the node's end (payload + size) is the space
 * on offer.  The winning node is the one with the most space, ties going to
 * the smaller offset; the amount is what comes back, or 0 if nothing fit.
 *
 * Notes on the codegen, all three of which are required to reach the
 * original's register assignment:
 *
 *  - `m` and `mask` are NOT locals in this file.  They are the two
 *    sub-expressions of the loop-invariant `start` computation, so the
 *    compiler hoists them into the loop preheader, which is emitted after
 *    the loop's entry test (the `beq` to the shared epilogue at +0x20).  As
 *    named locals they are emitted in source order before the test and the
 *    whole function's allocation shifts by one register.
 *  - The declaration order is size, best, ofs, blk.  That order is what puts
 *    the loop cursor in lr, `best` in r3 and `ofs` in ip; moving the cursor
 *    declaration earlier rotates those three the other way.
 *  - `ofs = -1` is spelled `sub ip, r3, #1`, i.e. rematerialised off the
 *    zero in `best` (docs/idioms/a-small-constant-is-rematerialised-off-a-
 *    zero-register-unless-an-argument-shares-it.md), and it is that, not
 *    `mvn ip, #0`, that shows in the original.  `best` being in r3 rather
 *    than r0 is also why the epilogue needs its `mov r0, r3`: 32 of the 33
 *    instructions of a version that hoists `best` into r0, which is
 *    otherwise byte-identical, and is what the "same size, register names
 *    only" trap looks like here.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x02060F50 (188 bytes)
 * because the code after this function's `pop` at 0x02060F18 has no
 * func_ label.  It is not padding and not a byte difference: 0x02060F18 is
 * a pair of unlabelled ARM leaf accessors (ldrh/and/bic/strh on the
 * halfword at +0x36, then ldrh/strh on +0x34, each ending in `bx lr`),
 * which disasm.py only auto-labels when a leaf saves lr.  Both want
 * seeding into layout/function_starts.txt, which is the integrator's file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060E94.c \
 *       --func func_02060E94 --addr 0x02060E94 --cc 1.1p1 --arm
 */
s32 func_02060E94(struct Heap *heap, s32 x)
{
    s32 size = func_02091588(x);
    u32 best = 0;
    u32 ofs = -1;
    struct HeapBlock *blk = heap->head;

    for (; blk != 0; blk = blk->next) {
        u32 data = (u32)blk + 0x10;
        u32 start = ((size - 1) + data) & ~(size - 1);
        u32 end = blk->size + data;

        if (start < end) {
            u32 amt = end - start;
            u32 off = start - data;

            if (best < amt || (best == amt && ofs > off)) {
                best = amt;
                ofs = off;
            }
        }
    }
    return best;
}



/*
 * Setter: replaces bit 0 of the halfword at +0x36 and returns the old bit 0.
 * 2026-10-05 (wave D7 lane 18): closed by reading the old bit first
 * (`old = *h & 1`, which places the and before the orr) and doing the two
 * stores through a named u16 pointer local (plain `*h = *h & ~1; *h = *h | (v & 1)`).
 */
u32 func_02060F18(char *p, u32 v)
{
    u32 old = *(u16 *)(p + 0x36) & 1;
    u16 *h = (u16 *)(p + 0x36);
    *h = *h & ~1;
    *h = *h | (v & 1);
    return old;
}



/*
 * Setter: stores a halfword at +0x34 and returns the old value.
 */
u16 func_02060F40(char *p, u16 v)
{
    u16 old = *(u16 *)(p + 0x34);
    *(u16 *)(p + 0x34) = v;
    return old;
}


void func_02060F50(int *p, void (*fn)(void *, void *, int), int ctx)
{
    int *q = (int *)p[0xb];
    if (q == 0)
        return;
    do {
        int *next = (int *)q[3];
        fn((char *)q + 0x10, p, ctx);
        q = next;
    } while (q != 0);
}


int func_02060F90(char *p){ return *(int *)(p - 0xc); }



/*
 * 12-byte ARM leaf right after func_02060F90 (its sibling getter on the
 * same header, p - 0xc): "ldrh r0, [r0, #-0xe]; and r0, r0, #0xff; bx lr".
 * It saves nothing, so the prologue sweep prints it as .word data.  The
 * only call site in the image is the blx at ov009 0x02156FE4
 * (func_02156FDC), which needs this entry as its matched witness.
 */
u8 func_02060F98(char *p)
{
    return *(u16 *)(p - 0xe);
}
