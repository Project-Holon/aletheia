/*
 * function: func_020336A4
 * address:  0x020336A4
 * packet:   pkt_020336A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_020A789C  0x020A789C  data
 *
 * The dma completion callback passed by func_020336B8: it raises the flag
 * that the synchronous path lowers before the asynchronous request.
 */

typedef unsigned int u32;

extern u32 d_020A789C;

void func_020336A4(void)
{
    d_020A789C = 1;
}
