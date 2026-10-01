/*
 * function: func_021B949C
 * address:  0x021B949C
 * packet:   pkt_ov021_021B949C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

void func_021B949C(u16 *p, u16 v)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (v == p[i]) {
            p[i] = 0xFFFF;
            return;
        }
    }
}
