/*
 * function: func_02165B04
 * address:  0x02165B04
 * packet:   pkt_ov010_02165B04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Count byte of the 30-record queue func_02165AC4 reads (head at +0xB04,
 * count at +0xB05). Unlabelled leaf reached from ov032 func_021F27D4.
 */

typedef unsigned char u8;

u8 func_02165B04(u8 *q)
{
    return q[0xb05];
}
