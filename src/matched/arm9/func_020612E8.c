/*
 * function: NNSi_FndFreeToUnitHeapAllocator
 * address: 0x020612E8
 * packet: pkt_arm9_020612E8
 * region: arm9
 * compiler: dsi/../2.0/sp2
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/unit_02061224.c and filed here.
 *
 * symbols:
 *   NNSi_FndPushFreeBlock 0x0206127C arm
 */

struct UnitHeap0206127C;
typedef unsigned int u32;

struct UnitBlock0206127C {
    struct UnitBlock0206127C *next;
};

struct UnitHeap0206127C {
    u32 head[9];
    struct UnitBlock0206127C *freeList;
};

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

void NNSi_FndPushFreeBlock(struct UnitHeap0206127C *heap, void *block);
void NNSi_FndFreeToUnitHeapAllocator(struct Allocator02061 *allocator, void *block);

void NNSi_FndFreeToUnitHeapAllocator(struct Allocator02061 *allocator, void *block)
{
    NNSi_FndPushFreeBlock((struct UnitHeap0206127C *)allocator->heap, block);
}
