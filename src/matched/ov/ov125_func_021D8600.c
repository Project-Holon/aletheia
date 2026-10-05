/*
 * function: func_021D8600
 * address:  0x021D8600
 * packet:   pkt_ov125_021D8600
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
 *   func_021D89EC  0x021D89EC  arm ov125
 */

extern int func_021D89EC(int n);

int func_021D8600(int n)
{
    return func_021D89EC(n);
}
