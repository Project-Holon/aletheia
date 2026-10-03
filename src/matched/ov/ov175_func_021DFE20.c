/*
 * function: func_021DFE20
 * address:  0x021DFE20
 * packet:   pkt_021DFE20
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DF968  0x_021DF968  arm  ov175
 *
 * ARM tail jump to func_021DF968, the ov175 +0x5c/+0x84 string writer.
 */

extern char *func_021DF968(void);

void func_021DFE20(void)
{
    func_021DF968();
}

