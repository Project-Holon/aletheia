/*
 * function: func_021A2170
 * address:  0x021A2170
 * packet:   pkt_ov021_021A2170
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   func_021A2170 0x021A2170 thumb ov021
 *   func_021A16E4 0x021A16E4 thumb ov021
 */

extern void func_021A16E4(unsigned char *p, unsigned int v);

void func_021A2170(unsigned char *o, unsigned int v, int i)
{
    func_021A16E4((*(unsigned char ***)(o + 0x18))[i], v);
}
