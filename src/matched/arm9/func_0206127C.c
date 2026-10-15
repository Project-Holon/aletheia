/*
 * function: NNSi_FndPushFreeBlock
 * address:  0x0206127C
 * packet:   pkt_0206127C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unit-heap free: pushes the block onto the free list at +0x24 of the
 * heap head (the same list NNSi_FndAllocBlockFromHeap pops through NNSi_FndPopFreeBlock).
 * Its only reference is the ARM pool word at 0x020612F4, the tail call
 * of the allocator-table entry 0x020612E8 (word at 0x020A16FC).
 */

typedef unsigned int u32;

struct UnitBlock0206127C {
    struct UnitBlock0206127C *next;
};

struct UnitHeap0206127C {
    u32 head[9];
    struct UnitBlock0206127C *freeList;
};

void NNSi_FndPushFreeBlock(struct UnitHeap0206127C *heap, void *block)
{
    struct UnitBlock0206127C *b = (struct UnitBlock0206127C *)block;

    b->next = heap->freeList;
    heap->freeList = b;
}
