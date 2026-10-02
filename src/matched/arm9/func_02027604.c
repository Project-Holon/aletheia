/*
 * function: func_02027604
 * address:  0x02027604
 * packet:   pkt_02027604
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: byte lookup in a u8 table; called from ov070, ov131 and ov198.
 * symbols:
 *   d_0209FCEC  0x0209FCEC  data
 */

typedef unsigned char u8;

extern const u8 d_0209FCEC[];

u8 func_02027604(u8 i)
{
    return d_0209FCEC[i];
}
