/*
 * function: POKETRADE_3D_FillTexturePage
 * address:  0x021E37D8
 * packet:   pkt_ov119_021E37D8
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

void POKETRADE_3D_FillTexturePage(u16 *p, u8 *src, int k, int a3)
{
    u8 *row;
    int i;
    int j;

    i = 0;
    row = src + k * 30;
    for (; i < 5; i++) {
        for (j = 0; j < 6; j++)
            POKETRADE_3D_FillTextureCell(p, j, i, row[i * 6 + j]);
    }
}
