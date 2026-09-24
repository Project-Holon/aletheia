/*
 * function: func_021C2304
 * address:  0x021C2304
 * packet:   pkt_021C2304
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0207D63C 0x0207D63C  thumb
 *
 * Writes 4 on the stack and calls the function at 0x0207D63C with
 * (0x04000050, 0, 0x3F, 0xC, 4).
 *
 * BLOCKED.  Missing witness: 0x0207D63C is only named by
 * layout/symbols_sdk.json, which is not an attestation, so match.py leaves
 * the call field wildcarded.  The bytes and the argument set are right.
 */

extern void func_0207D63C(void *, int, int, int, int);

void func_021C2304(void)
{
    func_0207D63C((void *)0x04000050, 0, 0x3f, 0xc, 4);
}
