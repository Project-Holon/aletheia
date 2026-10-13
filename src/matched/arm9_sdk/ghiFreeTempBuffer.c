/*
 * function: ghiFreeTempBuffer
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
 *   func_020913A4 0x020913A4 arm
 */

typedef unsigned int u32;

extern void func_020913A4(u32 heap);

void ghiFreeTempBuffer(u32 heap)
{
    if (heap) {
        func_020913A4(heap);
    }
}
