/*
 * function: func_020179B8
 * address:  0x020179B8
 * packet:   pkt_020179B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A "select and apply" pair, structurally the sibling of func_02017900.
 * The value at selector 5 is compared against a1; when they already agree
 * nothing but the +0x18 restore happens.  Otherwise the old selection is read
 * back out of selector 0x6f into r4 (the local that was 0, which is why the
 * clearing write passes r4 and not a literal 0) and the new value is written
 * with selector 0x6f before the two geometry calls run with it.
 *
 * The `cmp` operand order is the tell: `(u16)func_02017E88(...)` only reaches
 * cmp's left slot because it was first bound to a named local (`t`), see
 * docs/idioms/cmp-operand-order-names-the-temporary.md.  Comparing the call
 * result directly emits `cmp a1, r0` and differs by one byte.
 *
 * EXACT*: the compared extent ran into the follower's four-byte pad, which is
 * identical in both objects.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020179B8.c \
 *       --func func_020179B8 --addr 0x020179B8 --cc 1.1p1 --thumb
 */

extern int func_02017DBC(int a0);
extern int func_02017E88(int a0, int a1, int a2);
extern int func_02017E64(int a0, int a1, int a2);
extern int func_02017C50(int a0, int a1, int a2);
extern int func_02017CC8(int a0, int a1, int a2);
extern int func_02017DE4(int a0, int a1);

int func_020179B8(int a0, int a1)
{
    int r4 = 0;
    int r7 = (unsigned char)func_02017DBC(a0);
    int t = (unsigned short)func_02017E88(a0, 0x6f, 0);

    if (t != a1) {
        func_02017E88(a0, 0x6f, r4);
        r4 = (unsigned short)func_02017E88(a0, 5, r4);
        func_02017E64(a0, 0x6f, a1);
        func_02017C50(a0, r4, r4);
        func_02017CC8(a0, r4, r4);
        r4 = 1;
    }
    func_02017DE4(a0, r7);
    return r4;
}
