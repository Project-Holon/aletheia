/*
 * function: func_020275EC
 * address:  0x020275EC
 * packet:   pkt_020275EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: byte lookup in a u8 table; called from ov094 func_02204CC0 (bl at
 *   +0x1EE, 0x02204EAE) with a u8 index.
 * symbols:
 *   d_0209FCF8  0x0209FCF8  data
 */

typedef unsigned char u8;

extern const u8 d_0209FCF8[];

u8 func_020275EC(u8 i)
{
    return d_0209FCF8[i];
}
