/*
 * function: func_021A25BC
 * address:  0x021A25BC
 * packet:   pkt_ov021_021A25BC
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
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A2C30 0x021A2C30 thumb ov021
 */

extern void func_021A2C30(unsigned char *o, int a, int b);

void func_021A25BC(unsigned char *o, int arg)
{
    func_021A2C30(o + 0x40, *(int *)(o + 0xC), arg);
}
