/*
 * function: NNSi_FndAllocFromExpHeap
 * address:  0x02060888
 * packet:   pkt_02060814
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndGetMBlockRegion   0x02060764  arm
 *   NNSi_FndRemoveMBlock   0x02060790  arm
 *   NNSi_FndInsertMBlock   0x020607B8  arm
 *   NNSi_FndInitMBlock   0x020607E8  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *
 * The expanded heap's carve: the allocator's back end, entered from
 * NNSi_FndAllocFromExpHeapHead (head of the free list) and NNSi_FndAllocFromExpHeapTail (tail of it) with
 * the block they picked and the data address it will hand out.  The block is
 * unlinked from the free list, its extent read with NNSi_FndGetMBlockRegion, and the
 * new allocation is cut out of it: whatever is left in front of the new
 * block and whatever is left behind it become two free blocks (signature
 * 0x4652) around the new one (signature 0x5544), which goes back on the used
 * list at the end.  A remainder smaller than 0x14 cannot hold a header plus
 * one word, so the cut is snapped to the block's own edge instead and the
 * pair handed to NNSi_FndInitMBlock degenerates to a zero-length region.
 *
 * Argument 5 is the direction flag from the caller and lands in bit 15 of the
 * new block's attribute; its low byte is the heap's group id and bits 8..14
 * the distance to the preceding block, which is what NNSi_FndGetMBlockRegion reads
 * back.  It arrives as a halfword, so the parameter is declared u16 even
 * though both callers pass an int.
 *
 * Three shapes are load-bearing:
 *  - The first 2-word region is two scalars, the other two are
 *    `struct MemRegion`.  Three structs cost a sixth callee-saved register
 *    (r9) and 24 bytes, because then both `NNSi_FndGetMBlockRegion(&rgn, ...)` and
 *    `NNSi_FndInitMBlock(&rgn, ...)` name one object and mwcc hoists `sp+0x10`
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
 *   python tools/match.py one --src src/matched/NNSi_FndAllocFromExpHeap.c \
 *       --func NNSi_FndAllocFromExpHeap --addr 0x02060888 --cc 1.1p1 --arm
 */

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

struct ExpHeap {
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
};

struct MemRegion {
    int start;
    int end;
};

extern void NNSi_FndGetMBlockRegion(int *out, int *blk);
extern void *NNSi_FndRemoveMBlock(int *p, int *node);
extern void *NNSi_FndInsertMBlock(int *p, void *node, int *a);
extern void *NNSi_FndInitMBlock(int *p, int v);
extern void           MIi_CpuClear32(u32 data, void *dest, u32 size);

void *NNSi_FndAllocFromExpHeap(struct ExpHeap *heap, struct MBlock *block, void *ptr,
                    u32 size, u16 fromTail)
{
    int              end;
    int              start;
    struct MemRegion rest;
    struct MemRegion alloc;
    struct MBlock   *prev;
    struct MBlock   *node;
    u32              sz;

    NNSi_FndGetMBlockRegion(&start, (int *)block);
    rest.end = end;
    end = (int)ptr - 0x10;
    rest.start = (int)(size + (u32)ptr);

    prev = NNSi_FndRemoveMBlock((int *)(&heap->freeList), (int *)block);
    if ((u32)(end - start) < 0x14) {
        end = start;
    } else {
        prev = NNSi_FndInsertMBlock((int *)(&heap->freeList), NNSi_FndInitMBlock(&end - 1, 0x4652),
                             (int *)prev);
    }
    if ((u32)(rest.end - rest.start) < 0x14) {
        rest.start = rest.end;
    } else {
        NNSi_FndInsertMBlock((int *)(&heap->freeList), NNSi_FndInitMBlock((int *)&rest, 0x4652), (int *)prev);
    }

    sz = (u32)(rest.start - end);
    if ((u8)((u32 *)heap)[-1] & 1) {
        MIi_CpuClear32(0, (void *)end, sz);
    }

    alloc.start = (int)ptr - 0x10;
    alloc.end = rest.start;
    node = NNSi_FndInitMBlock((int *)&alloc, 0x5544);
    node->attr = node->attr & ~0x8000;
    node->attr = node->attr | (u16)(fromTail << 15);
    sz = (u16)((u32)node - (u32)end);
    node->attr = node->attr & ~0x7f00;
    node->attr = node->attr | ((sz & 0x7f) << 8);
    sz = heap->groupId & 0xff;
    node->attr = node->attr & ~0xff;
    node->attr = node->attr | sz;
    NNSi_FndInsertMBlock((int *)(&heap->usedList), node, (int *)heap->usedList.tail);
    return ptr;
}
