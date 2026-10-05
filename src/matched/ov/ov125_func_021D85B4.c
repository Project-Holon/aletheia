/*
 * function: func_021D85B4
 * address:  0x021D85B4
 * packet:   pkt_ov125_021D85B4
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
 *   func_021D770C  0x021D770C  arm ov125
 */

extern void func_021D770C(void);

void func_021D85B4(void)
{
    func_021D770C();
}
