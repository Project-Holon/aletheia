/*
 * function: func_021F3BE8
 * address:  0x021F3BE8
 * packet:   pkt_ov046_021F3BE8
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr push) between func_021F3BC8 and func_021F3BFC.
 *
 * symbols:
 *   d_021F41C4  0x021F41C4  data  a4
 */

extern int d_021F41C4[][4];

int func_021F3BE8(int *p, int i)
{
    return d_021F41C4[*p][i] - 5;
}
