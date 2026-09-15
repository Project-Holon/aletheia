/*
 * unit:     no
 * function: func_0203D378
 * address:  0x0203D378
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *
 * TU: net.c.
 *
 * Inverted forward: 1 when func_02039338 reports zero.  The result local is
 * initialised before the call, so the zero lands in r4 ahead of the `bl`
 * and the true case is a single `moveq`; writing `return f() == 0;`
 * instead puts the materialisation after the call and loses the shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D378.c \
 *       --func func_0203D378 --addr 0x0203D378 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 func_02039338(void);

u32 func_0203D378(void)
{
    u32 res = 0;

    if (func_02039338() == 0) {
        res = 1;
    }
    return res;
}
