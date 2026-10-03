/*
 * function: func_021E0764
 * address:  0x021E0764
 * packet:   pkt_021E0764
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *
 * ARM tail call: zeroes r0 and jumps to 0x0217CCCC (ov009) -- the
 *  *  "release and clear" entry of the ov009 object pair.
 */

extern void func_0217CCCC(unsigned int theMS);

void func_021E0764(void)
{
    func_0217CCCC(0);
}

