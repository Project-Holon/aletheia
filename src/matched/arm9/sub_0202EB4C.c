/*
 * unit:     no
 * function: sub_0202EB4C
 * address:  0x0202EB4C
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202EB0C   0x0202EB0C  thumb
 *   func_02087DE0  0x02087DE0  arm
 *
 * Neither call sets an argument register, so both callees are declared
 * with no parameters: the `blx` to the ARM helper follows a `cmp r0, #1`
 * and leaves r0 holding the 1 it was compared against, which is a
 * leftover and not an argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * Declaring either callee with a parameter costs an `adds r0, ...` the
 * original does not have.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB4C.c \
 *       --func sub_0202EB4C --addr 0x0202EB4C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202EB0C(void);
extern int func_02087DE0(void);

u32 sub_0202EB4C(void)
{
    if (sub_0202EB0C() == 1) {
        return func_02087DE0();
    }
    return 1;
}
