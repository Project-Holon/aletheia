/*
 * function: func_021642A4
 * address:  0x021642A4
 * packet:   pkt_ov010_021642A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 func_0219A7DC and func_0219A8C0: returns
 * the low halfword of word i of a table.
 *
 * symbols:
 *   d_021714B0     0x021714B0  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;
extern u32 d_021714B0[];

u16 func_021642A4(int i)
{
    return d_021714B0[i];
}
