/*
 * function: func_021BF100
 * address:  0x021BF100
 * packet:   pkt_021BF100
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call through a pool word: bx r3 spends r3 on the target, so only the
 * two argument registers are live (see docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * symbols:
 *   func_021C0F5C  0x021C0F5C  thumb  ov217
 *   d_021C3628     0x021C3628  data   ov217  a4
 *
 * Addresses are Black-image addresses.
 */

extern unsigned char d_021C3628[];
extern void func_021C0F5C(int, int);

void func_021BF100(char *p)
{
    func_021C0F5C(*(int *)(p + 0x348), d_021C3628[*(unsigned char *)(p + 0x38)]);
}
