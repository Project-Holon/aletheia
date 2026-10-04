/*
 * function: func_02189A50
 * address:  0x02189A50
 * packet:   pkt_ov021_02189A50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves no lr): stores r1 at +0x144.  Callee of ov020
 * func_02187CEC and func_02187CFC.
 *
 * symbols:
 */

void func_02189A50(char *p, int v)
{
    *(int *)(p + 0x144) = v;
}
