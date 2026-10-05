/*
 * function: func_021D85F4
 * address:  0x021D85F4
 * packet:   pkt_ov125_021D85F4
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
 *   func_021D7C14  0x021D7C14  arm ov125
 */

extern int func_021D7C14(void);

int func_021D85F4(void)
{
    return func_021D7C14();
}
