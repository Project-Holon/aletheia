/*
 * function: func_021B275C
 * address:  0x021B275C
 * packet:   pkt_ov013_021B275C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B2620  0x021B2620  arm  ov013
 *   func_02176E90  0x02176E90  arm  ov009
 */

typedef unsigned char u8;

extern int func_021B2620(int *o, u8 *p);
extern int func_02176E90(int i, u8 *p, int n);

int func_021B275C(u8 *o, u8 *p)
{
    if (p[4] == 0xff && p[6] == 4) {
        func_021B2620((int *)o, p);
    } else if (func_02176E90(o[4], p, 0x10) == 0) {
        return 0;
    }
    return 1;
}
