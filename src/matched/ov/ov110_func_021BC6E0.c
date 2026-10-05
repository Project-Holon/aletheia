/*
 * function: func_021BC6E0
 * address:  0x021BC6E0
 * packet:   pkt_ov110_021BC6E0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Halfword accessor: p + i*2 + 0x40.
 */

typedef unsigned char u8;
typedef unsigned short u16;

u16 func_021BC6E0(u8 *p, int i)
{
    return *(u16 *)(p + i * 2 + 0x40);
}
