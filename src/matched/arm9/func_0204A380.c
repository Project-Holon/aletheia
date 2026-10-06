/*
 * function: func_0204A380
 * address:  0x0204A380
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A39C  0x0204A39C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3)
{
    u32 unk;
    return func_0204A39C(a0, a1, a2, a3, &unk);
}
