/*
 * unit:     no
 * address:  0x0202D0D4
 * packet:   pkt_0202D064
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202D0D4
 *
 * symbols:
 *   func_0202D4A8  0x0202D4A8  thumb
 *
 * One of a family of thin wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8: it forwards its own three stack
 * arguments, hands the callee out-pointers for two width accumulators and
 * a status word, and folds the results into a single returned extent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202D0D4.c \
 *       --func func_0202D0D4 --addr 0x0202D0D4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int s32;

extern void func_0202D4A8(u32 a0, u32 a1, u32 a2, u32 a3,
                          u32 s5, u32 s6, u32 s7,
                          s32 *p8, u32 s9, u32 s10,
                          s32 *p11, s32 *p12, u32 s13);

s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 r;

    r = 0;
    func_0202D4A8(a0, a1, a2, a3, s5, s6, s7, &b, 0, 0, &a, &r, 0);
    if (r == 0) {
        r = b + 0x12 + a;
    }
    return r;
}
