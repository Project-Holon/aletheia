/*
 * function: func_02030524
 * address:  0x02030524
 * packet:   pkt_02030524
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_02146954   0x02146954  data  a2
 */

typedef unsigned short u16;

extern u16 d_02146954[];

u16 func_02030524(void)
{
    return *(u16 *)((char *)d_02146954 + 0xe);
}
