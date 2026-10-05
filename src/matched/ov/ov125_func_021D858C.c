/*
 * function: func_021D858C
 * address:  0x021D858C
 * packet:   pkt_ov125_021D858C
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
 *   func_021D8B44  0x021D8B44  arm ov125
 */

extern void func_021D8B44(void);

void func_021D858C(void)
{
    func_021D8B44();
}
