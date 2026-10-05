/*
 * function: func_0217EC54
 * address:  0x0217EC54
 * packet:   pkt_ov019_0217EC54
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180648  0x02180648  data a2
 */

typedef unsigned short u16;

extern const u16 d_02180648[][2];

u16 func_0217EC54(int i, int j)
{
    return d_02180648[i - 2][j];
}
