/*
 * function: func_021E37D8
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
 *   func_021E3758  0x021E3758  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021E3758(u16 *p, int x, int y, int colour);

void func_021E37D8(u16 *p, u8 *src, int k)
{
    u8 *row;
    int i;
    int j;

    i = 0;
    row = src + k * 30;
    for (; i < 5; i++) {
        for (j = 0; j < 6; j++)
            func_021E3758(p, j, i, row[i * 6 + j]);
    }
}
