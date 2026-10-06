/*
 * function: func_021C1F28
 * address:  0x021C1F28
 * packet:   pkt_021C1F28
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)

 * Forwards to func_0204A39C with the first argument less one and an out slot.
 */


typedef unsigned int   u32;
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

void func_021C1F28(int a, int b, int c)
{
    int out;

    func_0204A39C((void *)c, a - 1, 0, b, (u32 *)(&out));
}

