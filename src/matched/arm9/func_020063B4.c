/*
 * function: func_020063B4
 * address:  0x020063B4
 * packet:   pkt_020063B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A three-state step function: `*a1` is the state, it advances at most one
 * step per call and every arm reports 0 except the step out of state 2,
 * which reports 1.
 *
 * The a2 == 1 arm is deliberately NOT an early `return 0;`.  Written that
 * way (`*a1 = 0; return 0;` then the switch) the compiler duplicates the
 * `str r0, [r4]` into the arm and emits its own epilogue, 150 bytes and
 * four bytes of extra code; with the arm falling through to one shared
 * `return 0;` at the end of the function the two `*a1 = <r0>` stores
 * cross-jump into the single `str r0, [r4]` at +0x3C and the arm is
 * `movs r0, #0 / b +0x3C`.  That single `str` is then the merge point for
 * three different paths (a2 == 1 storing 0, the state-0 arm and the
 * state-1 arm storing `*a1 + 1`).
 *
 * The `bne` at +0x0A jumps PAST the whole then-arm into the switch, so the
 * a2 == 1 arm is the fall-through and the switch is the `else` -- an `if`
 * whose then-arm is small enough to keep inline and whose else-arm is the
 * long one.
 *
 * `z - 1` in the state-2 arm is two `-1` arguments; the compiler keeps the
 * zero in r6 and derives both from `subs r2, r6, #1` instead of loading
 * each `movs r0, #1 / rsbs`, and the second argument to sub_020755A8 is
 * the leftover result of sub_0200590C, which takes none (see
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * EXACT*: the listing extent runs to 148 bytes because the follower saves
 * no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020063B4.c \
 *       --func func_020063B4 --addr 0x020063B4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern void sub_02005D14(void);
extern void sub_02006368(void);
extern void sub_020746B0(int p0);
extern void sub_02006300(u32 a, int mode);
extern int sub_02006394(void);
extern void sub_0200597C(void);
extern void sub_02085A38(u32 v);
extern int sub_020059A0(u32 a);
extern u32 *sub_0200590C(void);
extern u32 sub_020755A8(u32 a, int b, int c, int d, u32 e);

u32 func_020063B4(u8 *a0, u32 *a1, u32 a2)
{
    if (a2 == 1) {
        sub_02005D14();
        sub_02006368();
        *a1 = 0;
    } else {
        switch (*a1) {
        case 0:
            sub_020746B0(0x1300);
            sub_02006300((u32)a0, 0);
            (*a1)++;
            break;
        case 1:
            if (sub_02006394() == 1) {
                sub_0200597C();
                sub_02006300((u32)a0, 1);
                (*a1)++;
            } else {
                sub_02085A38(2);
            }
            break;
        case 2:
            if (sub_02006394() == 1) {
                s32 z = 0;

                sub_020746B0(0);
                sub_020059A0((u32)a0);
                sub_020755A8((u32)sub_0200590C(), 0, z - 1, z - 1, (u32)a0);
                (*a1)++;
                return 1;
            }
            sub_02085A38(2);
            break;
        default:
            break;
        }
    }
    return 0;
}
