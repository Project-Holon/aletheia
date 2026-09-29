/*
 * function: func_021A7EB4
 * address:  0x021A7EB4
 * packet:   pkt_ov021_021A7EB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A8268  0x021A8268  thumb  ov021
 */

typedef unsigned char u8;

extern int func_021A8268(void *p);

void func_021A7EB4(u8 *p)
{
    if (func_021A8268(p) != 0) {
        p[0x2C] = 0;
        p[0x2D] = 3;
        p[0x2E] = 1;
        p[0x2F] = 2;
        p[0x30] = 5;
        p[0x31] = 6;
        p[0x32] = 7;
        p[0x33] = 8;
    } else {
        p[0x2C] = 0;
        p[0x2D] = 1;
        p[0x2E] = 2;
        p[0x2F] = 5;
        p[0x30] = 6;
        p[0x31] = 7;
        p[0x32] = 8;
    }
}
