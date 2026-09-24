/*
 * function: func_021EBFEC
 * address:  0x021EBFEC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm  arm9
 *
 * Forward the i-th word of the pooled table.
 */

extern void func_0204B98C(int);

void func_021EBFEC(char *p, int i)
{
    func_0204B98C(*(int *)(p + i * 4 + 0x9E74));
}

