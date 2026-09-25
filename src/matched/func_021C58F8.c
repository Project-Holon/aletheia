/*
 * function: func_021C58F8
 * address:  0x021C58F8
 * packet:   pkt_021C58F8
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4268  0x021C4268  thumb
 *   d_021C60B6     0x021C60B6  data  a1
 *
 * Addresses are Black-image addresses.
 */

extern int func_021C4268(char *);
extern unsigned char d_021C60B6[];

int func_021C58F8(char *p, int b)
{
    if (func_021C4268(p) == 2)
        return 0;
    return d_021C60B6[b];
}
