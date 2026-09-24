/*
 * function: func_021DFD18
 * address:  0x021DFD18
 * packet:   pkt_021DFD18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E0098  0x_021E0098  arm  ov175
 *
 * ARM tail jump to func_021E0098, the ov175 byte-read path.
 */

extern void func_021E0098(void);

void func_021DFD18(void)
{
    func_021E0098();
}

