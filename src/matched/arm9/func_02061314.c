/*
 * function: NNSi_FndFreeToVramAllocator
 * address: 0x02061314
 * packet: pkt_arm9_02061314
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
 *   OS_FreeToHeap 0x020869E8 arm
 */

typedef unsigned int u32;

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

extern void OS_FreeToHeap(int id, int heap, void *ptr);
void NNSi_FndFreeToVramAllocator(struct Allocator02061 *allocator, void *ptr);

void NNSi_FndFreeToVramAllocator(struct Allocator02061 *allocator, void *ptr)
{
    OS_FreeToHeap((int)allocator->param1, (int)allocator->heap, ptr);
}
