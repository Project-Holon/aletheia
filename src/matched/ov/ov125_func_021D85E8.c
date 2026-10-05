/*
 * function: func_021D85E8
 * address:  0x021D85E8
 * packet:   pkt_ov125_021D85E8
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM tail call: ldr ip, =target; bx ip.
 *
 * symbols:
 *   func_021D7BDC  0x021D7BDC  arm ov125
 */

extern void func_021D7BDC(char *p);

void func_021D85E8(char *p)
{
    func_021D7BDC(p);
}
