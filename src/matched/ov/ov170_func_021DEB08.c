/*
 * function: func_021DEB08
 * address:  0x021DEB08
 * packet:   pkt_ov170_021DEB08
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEA6C 0x021DEA6C thumb
 *
 * Steps the object with mode 0 (sibling of func_021DEAFC, which passes 1).
 */

extern int func_021DEA6C(unsigned char *p, int mode);

int func_021DEB08(unsigned char *p)
{
    return func_021DEA6C(p, 0);
}
