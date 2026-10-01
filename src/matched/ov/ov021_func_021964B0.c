/*
 * function: func_021964B0
 * address:  0x021964B0
 * packet:   pkt_ov021_021964B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_021964B0(u16 (*dst)[16], u16 *add, int n)
{
    int i;
    int j;
    u16 c;
    u16 r;
    u16 g;
    u16 b;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 16; j++) {
            c = dst[i][j];
            r = c & 0x1F;
            g = (c & 0x3E0) >> 5;
            b = (c & 0x7C00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) {
                r = 31;
            }
            if (g > 31) {
                g = 31;
            }
            if (b > 31) {
                b = 31;
            }
            dst[i][j] = (b << 10) + (r + (g << 5));
        }
    }
}
