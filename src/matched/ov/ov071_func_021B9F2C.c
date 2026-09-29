/*
 * function: func_021B9F2C
 * address:  0x021B9F2C
 * packet:   pkt_ov071_021B9F2C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

int func_021B9F2C(u8 *p, int i, int v)
{
    int old;

    if (i != 0xFFFF) {
        if (i >= p[0x27c] - 1 || i < 1) {
            return 0;
        }
    }
    old = *(int *)(p + 0x2f4);
    *(int *)(p + 0x2f8) = old;
    *(int *)(p + 0x2fc) = old;
    *(int *)(p + 0x2f4) = i;
    *(int *)(p + 0x304) = 1;
    *(int *)(p + 0x308) = v;
    return 1;
}
