/*
 * function: func_021EBB28
 * address:  0x021EBB28
 * packet:   pkt_ov170_021EBB28
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBA84 0x021EBA84 thumb
 *
 * Prints message 0x2B into window i.
 *
 * Filed in src/pending although it compiles EXACT: the ov170 listing labels
 * 0x021EBB1C as one 64-byte ARM function and has no start at 0x021EBB28 or
 * 0x021EBB34.  The three are Thumb functions (two tail-call thunks to
 * func_021EBA84 and a sibling of func_021EBAF8).  Integrator: seed 0x021EBB1C
 * (Thumb, witness bl at 0x021E7B6E), 0x021EBB28 and 0x021EBB34 in
 * layout/function_starts.txt, then move all three to src/matched/ov.
 */

extern void func_021EBA84(unsigned char *p, int msg, int i);

void func_021EBB28(unsigned char *p, int i)
{
    func_021EBA84(p, 0x2B, i);
}
