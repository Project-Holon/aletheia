/*
 * unit:     yes
 * function: func_0202D1AC
 * address:  0x0202D1AC
 * packet:   pkt_0202D1AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202D4A8  0x0202D4A8  thumb
 *
 * The two consecutive wrappers around the 13-argument text/window
 * measurement routine at 0x0202D4A8, folded into one translation unit.
 * Each forwards its three stack arguments, hands the callee two
 * out-pointers and returns their sum plus a per-function constant
 * (7, 8).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D1AC.c \
 *       --addr 0x0202D1AC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int s32;

extern void func_0202D4A8(u32 a0, u32 a1, u32 a2, u32 a3,
                          u32 s5, u32 s6, u32 s7,
                          s32 *p8, s32 *p9, u32 s10,
                          u32 s11, u32 s12, u32 s13);

s32 func_0202D1AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    func_0202D4A8(a0, a1, a2, a3, s5, s6, s7, &b, &a, 0, 0, 0, 0);
    return b + a + 7;
}

s32 func_0202D1E0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;

    func_0202D4A8(a0, a1, a2, a3, s5, s6, s7, &b, &a, 0, 0, 0, 0);
    return b + a + 8;
}

