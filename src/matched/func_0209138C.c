/*
 * function: func_0209138C
 * address:  0x0209138C
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_AllocFromHeap  0x020868E0  arm
 */

typedef unsigned int u32;

extern void *OS_AllocFromHeap(u32 a, u32 b, u32 heap);

void *func_0209138C(u32 heap)
{
    return OS_AllocFromHeap(0, (u32)-1, heap);
}
