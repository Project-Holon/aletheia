/*
 * unit:     yes
 * function: func_0202D064
 * address:  0x0202D064
 * packet:   pkt_0202D064
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
 * The two consecutive three-out-pointer wrappers around the 13-argument
 * text/window measurement routine at 0x0202D4A8, folded into one
 * translation unit. The first sets the trailing flag to one and returns the
 * plain sum of the three accumulators; the second leaves every flag zero
 * and adds two.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D064.c \
 *       --addr 0x0202D064 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int s32;

extern void func_0202D4A8(u32 a0, u32 a1, u32 a2, u32 a3,
                          u32 s5, u32 s6, u32 s7,
                          s32 *p8, s32 *p9, s32 *p10,
                          u32 s11, u32 s12, u32 s13);

s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 c;

    func_0202D4A8(a0, a1, a2, a3, s5, s6, s7, &b, &a, &c, 0, 0, 1);
    return c + (b + a);
}

s32 func_0202D09C(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7)
{
    s32 b;
    s32 a;
    s32 c;

    func_0202D4A8(a0, a1, a2, a3, s5, s6, s7, &b, &a, &c, 0, 0, 0);
    return c + (b + a + 2);
}
