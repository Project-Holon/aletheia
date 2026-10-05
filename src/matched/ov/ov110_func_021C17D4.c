/*
 * function: func_021C17D4
 * address:  0x021C17D4
 * packet:   pkt_ov110_021C17D4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3 to an ARM9 function.
 *
 * symbols:
 *   func_020419E4  0x020419E4  arm
 */

extern void func_020419E4(void);

void func_021C17D4(void)
{
    func_020419E4();
}
