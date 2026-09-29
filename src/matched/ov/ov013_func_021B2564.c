/*
 * function: func_021B2564
 * address:  0x021B2564
 * packet:   pkt_ov013_021B2564
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B2010  0x021B2010  arm  ov013
 *   func_021B275C  0x021B275C  arm  ov013
 */

typedef unsigned char u8;

extern int func_021B2010(int a, int b, u8 *buf, int n);
extern int func_021B275C(int a, u8 *buf);

int func_021B2564(int a, int b)
{
    u8 buf[16];
    int r;

    r = func_021B2010(a, b, buf, 16);
    if (r != 0)
        return r;
    if (func_021B275C(a, buf) != 0)
        return 0;
    return -4;
}
