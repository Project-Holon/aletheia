/*
 * function: ArrayDeleteAt
 * address:  0x0218437C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the two helpers on both arguments.
 *
 * symbols:
 *   func_021840CC  0x021840CC  arm  ov009
 *   func_02184324  0x02184324  arm  ov009
 */

extern void func_021840CC(int a, int b);
extern void func_02184324(int a, int b);

void ArrayDeleteAt(int a, int b)
{
    func_021840CC(a, b);
    func_02184324(a, b);
}

