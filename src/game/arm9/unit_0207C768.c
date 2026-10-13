/*
 * file:     unit_0207C768.c
 * unit:     yes
 * function: func_0207C768, func_0207C778
 * address:  0x0207C768
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0207C930   0x0207C930  arm
 *   sub_0207C86C   0x0207C86C  arm
 *   func_0207C8A0  0x0207C8A0  arm
 *   func_0207C86C  0x0207C86C  arm
 */
typedef unsigned int u32;

typedef long fx32;

extern void sub_0207C930(u32 a, u32 b);
extern u32  sub_0207C86C(void);
extern void func_0207C8A0(fx32 denom);
extern u32 func_0207C86C(void);
u32 sub_0207C768(u32 numer, u32 denom);
fx32 func_0207C778(fx32 denom);


/*
 * Start the hardware unit through sub_0207C930 with the caller's two
 * operands, then block on it and return its result through sub_0207C86C.
 * Both arguments reach sub_0207C930 as leftovers in r0/r1; nothing is
 * spent setting them up
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0207C768.c \
 *       --func sub_0207C768 --addr 0x0207C768 --cc 1.1p1 --arm
 */
u32 sub_0207C768(u32 numer, u32 denom)
{
    sub_0207C930(numer, denom);
    return sub_0207C86C();
}


fx32 func_0207C778(fx32 denom)
{
    func_0207C8A0(denom);
    return func_0207C86C();
}
