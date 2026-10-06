/*
 * function: func_021BB810
 * address:  0x021BB810
 * packet:   pkt_ov088_021BB810
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Redraws menu row `row` (height from the row table d_021BD5EE) at tile
 * row y on bg layer 2 with palette pal, then commits the layer.
 *
 * symbols:
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BD5EE     0x021BD5EE  data  ov088  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 d_021BD5EE[];

extern void func_020413B0(u32, u32, u8, u8, u8, u32);
extern void func_02041B6C(u32);

void func_021BB810(void *p, u8 row, int y, int pal)
{
    func_020413B0(2, 3, y, 0x1a, *(u16 *)((char *)d_021BD5EE + row * 4), pal);
    func_02041B6C(2);
}
