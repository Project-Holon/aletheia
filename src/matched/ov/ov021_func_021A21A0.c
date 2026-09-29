/*
 * function: func_021A21A0
 * address:  0x021A21A0
 * packet:   pkt_ov021_021A21A0
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
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   func_021A16E0 0x021A16E0 thumb ov021
 */

extern void func_021A16E0(unsigned char *p, unsigned int v);

void func_021A21A0(unsigned char *o, unsigned int v, int i)
{
    func_021A16E0((*(unsigned char ***)(o + 0x18))[i], v);
}
