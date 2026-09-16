/*
 * function: func_020913A4
 * address:  0x020913A4
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_FreeToHeap  0x020869E8  arm
 */

typedef unsigned int u32;

extern void OS_FreeToHeap(u32 a, u32 b, u32 heap);

void func_020913A4(u32 heap)
{
    OS_FreeToHeap(0, (u32)-1, heap);
}
