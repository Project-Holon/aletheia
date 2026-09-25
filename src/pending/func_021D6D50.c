/*
 * function: func_021D6D50
 * address:  0x021D6D50
 * packet:   pkt_021D6D50
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  func_0205121C is an unlabelled arm9 leaf wrapper (no func_ label,
 *           not in symbols_sdk.json / runtime_arm9.txt), so the call at +000A
 *           has no witness outside this range. Byte-correct; caps at MATCH.
 *
 * symbols:
 *   func_0205121C  0x0205121C  arm
 *   func_02051230  0x02051230  arm
 *
 * Addresses are Black-image addresses.
 */

extern int func_0205121C(int, int, int);
extern void func_02051230(int, int, int, int);

void func_021D6D50(int *p, int a, int b, int c)
{
    int x = func_0205121C(a, b, c);
    func_02051230(*p, x, 1, 0);
}
