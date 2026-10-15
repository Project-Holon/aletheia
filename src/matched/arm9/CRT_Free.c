/*
 * function: CRT_Free
 * address:  0x020913E8
 * packet:   pkt_020913E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MSL_C_LIB_FreeToHeap 0x020913A4 arm
 */

typedef unsigned int u32;

extern void MSL_C_LIB_FreeToHeap(u32 heap);

void CRT_Free(u32 heap)
{
    if (heap) {
        MSL_C_LIB_FreeToHeap(heap);
    }
}
