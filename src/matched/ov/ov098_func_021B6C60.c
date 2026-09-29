/*
 * function: func_021B6C60
 * address:  0x021B6C60
 * packet:   pkt_ov098_021B6C60
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf inside the handed extent of func_021B6C34.
 */

typedef unsigned char u8;

void func_021B6C60(char *p)
{
    u8 s = *(u8 *)(p + 0x14);

    if (s == 0 || s == 3) {
        *(int *)(p + 4) = 0x1f000;
        *(int *)(p + 8) = 0x7000;
        *(int *)(p + 0xc) = -0x52aa;
        *(int *)(p + 0x10) = 0x1800;
        *(u8 *)(p + 0x15) = 6;
        *(u8 *)(p + 0x14) = 1;
    }
}
