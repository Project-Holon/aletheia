/*
 * function: POKETRADE_3D_FillTextureHeader
 * address:  0x021E380C
 * packet:   pkt_ov119_021E380C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_3D_FillTextureCell  0x021E3758  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void POKETRADE_3D_FillTextureCell(u16 *p, int x, int y, int colour);

void POKETRADE_3D_FillTextureHeader(u16 *p, u8 *src, int a2)
{
    int i;

    for (i = 0; i < 6; i++)
        POKETRADE_3D_FillTextureCell(p, i % 2 + 2, i / 2 + 1, src[i]);
}
