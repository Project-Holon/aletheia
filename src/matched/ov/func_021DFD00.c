/*
 * function: func_021DFD00
 * address:  0x021DFD00
 * packet:   pkt_021DFD00
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E0080  0x_021E0080  arm
 *
 * ARM tail jump to 0x021E0080, which carries labels in ov093 and ov183 as
 *  *  well, so the site needs the region hint below.
 */

extern void func_021E0080(void);

void func_021DFD00(void)
{
    func_021E0080();
}

