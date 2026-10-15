/*
 * function: NNSi_FndAllocFromExpHeapAllocator
 * address:  0x0206128C
 * packet:   pkt_0206128C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_FndAllocFromExpHeapEx  0x02060CA0  arm
 *
 * Allocator-table alloc for the expanded heap: tail call to
 * NNS_FndAllocFromExpHeapEx(allocator->heap, size, allocator->param1).  Table word
 * 0x0206128C at 0x020A1708.
 */

typedef unsigned int u32;
typedef signed int   s32;

struct Allocator02061 {
    void *funcs;
    void *heap;
    u32 param1;
    u32 param2;
};

struct ExpHeap;
extern void *NNS_FndAllocFromExpHeapEx(struct ExpHeap *heap, u32 size, s32 align);

void *NNSi_FndAllocFromExpHeapAllocator(struct Allocator02061 *allocator, u32 size)
{
    return NNS_FndAllocFromExpHeapEx(allocator->heap, size, (s32)allocator->param1);
}
