/*
 * function: func_021A2160
 * address:  0x021A2160
 * packet:   pkt_ov021_021A2160
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
 *   func_021A2160 0x021A2160 thumb ov021
 *   func_021A16D4 0x021A16D4 thumb ov021
 */

extern void func_021A16D4(unsigned char *p, unsigned int v);

void func_021A2160(unsigned char *o, unsigned int v, int i)
{
    func_021A16D4((*(unsigned char ***)(o + 0x18))[i], v);
}
