/*
 * function: func_0200B2A4
 * address:  0x0200B2A4
 * packet:   pkt_0200B2A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200B1F8   0x0200B1F8  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0200B254   0x0200B254  thumb
 *
 * Rebuild the four per-slot fields for every entry the accessor count reports;
 * the count is a call, so it is re-evaluated on the loop back-edge, and the
 * third argument of every accumulate call is truncated to u8.
 */

typedef unsigned char u8;

extern void func_0200B1F8(int a0);
extern int  func_0201AA18(int a1);
extern int  func_0201AB28(int a1, int idx);
extern int  func_02017E1C(int obj, int key, int off);
extern void func_0200B254(int a0, int field, u8 idx, int value);

void func_0200B2A4(int a0, int a1)
{
    int i;

    func_0200B1F8(a0);
    for (i = 0; i < func_0201AA18(a1); i++) {
        int obj = func_0201AB28(a1, i);

        if (func_02017E1C(obj, 0xa9, 0) != 0) {
            func_0200B254(a0, 0, i, func_02017E1C(obj, 5, 0));
            func_0200B254(a0, 1, i, func_02017E1C(obj, 0x6f, 0));
            func_0200B254(a0, 2, i, func_02017E1C(obj, 6, 0) != 0);
            func_0200B254(a0, 3, i, func_02017E1C(obj, 0x6e, 0));
        }
    }
}
