/*
 * function: func_02189ACC
 * address:  0x02189ACC
 * packet:   pkt_ov021_02189ACC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf: returns one of two pooled constants (0x1EE / 0x136) depending on
 * func_02013BA8() == 1.  Callee of func_021881D8 (assigns p->x104).
 *
 * symbols:
 *   func_02013BA8  0x02013BA8  thumb
 */

extern int func_02013BA8(void);

int func_02189ACC(void)
{
    if (func_02013BA8() == 1)
        return 0x1EE;
    return 0x136;
}
