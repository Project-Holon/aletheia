/*
 * function: func_021C2304
 * address:  0x021C2304
 * packet:   pkt_021C2304
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C 0x0207D63C  arm
 *
 * Writes 4 on the stack and calls the SDK function at 0x0207D63C with
 * (0x04000050, 0, 0x3F, 0xC, 4).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207D63C is the ARM
 * SDK symbol G2x_SetBlendAlpha_, and the `sdk` class attests the call once
 * the symbols block declares `arm`.  The old `thumb` declaration fought the
 * image's ISA and suppressed the witness.  Verified EXACT, 24 bytes.
 */

extern void func_0207D63C(void *, int, int, int, int);

void func_021C2304(void)
{
    func_0207D63C((void *)0x04000050, 0, 0x3f, 0xc, 4);
}
