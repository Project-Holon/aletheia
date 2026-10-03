/*
 * function: func_021DF224
 * address:  0x021DF224
 * packet:   pkt_021DF224
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021E4D08     0x021E4D08  data
 *   func_021DFAA0  0x021DFAA0  arm  ov175
 *
 * One-line tail thunk: the object's +4 word is forwarded to the +0x84 accessor
 * that sits at the tail of func_021DFA6C's extent.
 */

typedef unsigned int u32;

extern u32  g_021E4D08[];
extern u32 func_021DFAA0(u32 p);

void func_021DF224(void)
{
    func_021DFAA0(g_021E4D08[1]);
}
