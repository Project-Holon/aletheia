/*
 * function: MSL_C_LIB_AllocFromHeap
 * address:  0x020913D0
 * packet:   pkt_020913D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MSL_C_LIB_AllocAllFromHeap  0x0209138C  arm
 */

typedef unsigned int u32;

extern void *MSL_C_LIB_AllocAllFromHeap(u32 heap);

void *MSL_C_LIB_AllocFromHeap(u32 heap)
{
    if (heap == 0)
        return 0;
    return MSL_C_LIB_AllocAllFromHeap(heap);
}
