/*
 * function: func_021A273C
 * address:  0x021A273C
 * packet:   pkt_ov021_021A273C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021D88E8  0x021D88E8  data  a1
 */

typedef unsigned char u8;

extern const u8 data_021D88E8[];

u8 func_021A273C(u8 *p)
{
    return data_021D88E8[p[0x26]];
}
