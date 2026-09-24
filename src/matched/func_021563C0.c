/*
 * function: func_021563C0
 * address:  0x021563C0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Halfword at +0x56 of the block func_0203D798 returns, passed on.
 *
 * symbols:
 *   func_02156344  0x02156344  thumb  ov009
 */

extern char *func_0203D798(int a);
extern void func_02156344(int v);

void func_021563C0(int a)
{
    func_02156344(*(unsigned short *)(func_0203D798(a) + 0x56));
}

