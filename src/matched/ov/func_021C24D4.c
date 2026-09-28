/*
 * function: func_021C24D4
 * address:  0x021C24D4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stamps the byte at +0x1342 with 0x2A when the selector is 4 and 0x7F otherwise,
 * then copies it down to +0x1341.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

void func_021C24D4(u8 *p, int v)
{
    if (v == 4) {
        p[0x1342] = 0x2A;
    } else {
        p[0x1342] = 0x7F;
    }

    p[0x1341] = p[0x1342];
}
