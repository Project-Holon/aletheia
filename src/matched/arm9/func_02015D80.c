/*
 * function: func_02015D80
 * address:  0x02015D80
 * packet:   pkt_02015D80
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: halfword setter at +0x178; called from ov131 func_021D785C (bl at
 *   +0x78 and +0xB6) with the pooled full-width value 0xD555.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_02015D80(u8 *p, u16 v)
{
    *(u16 *)(p + 0x178) = v;
}
