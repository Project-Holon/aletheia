/*
 * function: GFL_USE_StepBgmLoad
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
 * the leftover result of GFL_USE_GetCurrentSndHandle, which takes none (see
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * EXACT*: the listing extent runs to 148 bytes because the follower saves
 * no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_StepBgmLoad.c \
 *       --func GFL_USE_StepBgmLoad --addr 0x020063B4 --cc 1.1p1 --thumb
 *
 * symbols:
 *   GFL_USE_GetCurrentSndHandle  0x0200590C  thumb
 *   GFL_USE_SaveSeqBankState  0x0200597C  thumb
 *   GFL_USE_FinishBgmLoad  0x020059A0  thumb
 *   GFL_USE_StopBgm  0x02005D14  thumb
 *   GFL_USE_StartLoaderThread  0x02006300  thumb
 *   GFL_USE_StopLoaderThread  0x02006368  thumb
 *   GFL_USE_IsLoaderDone  0x02006394  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern void GFL_USE_StopBgm(void);
extern void GFL_USE_StopLoaderThread(void);
extern void sub_020746B0(int p0);
extern void GFL_USE_StartLoaderThread(u32 a, int mode);
extern int GFL_USE_IsLoaderDone(void);
extern void GFL_USE_SaveSeqBankState(void);
extern void sub_02085A38(u32 v);
extern int GFL_USE_FinishBgmLoad(u32 a);
extern u32 *GFL_USE_GetCurrentSndHandle(void);
extern u32 sub_020755A8(u32 a, int b, int c, int d, u32 e);

u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2)
{
    if (a2 == 1) {
        GFL_USE_StopBgm();
        GFL_USE_StopLoaderThread();
        *a1 = 0;
    } else {
        switch (*a1) {
        case 0:
            sub_020746B0(0x1300);
            GFL_USE_StartLoaderThread((u32)a0, 0);
            (*a1)++;
            break;
        case 1:
            if (GFL_USE_IsLoaderDone() == 1) {
                GFL_USE_SaveSeqBankState();
                GFL_USE_StartLoaderThread((u32)a0, 1);
                (*a1)++;
            } else {
                sub_02085A38(2);
            }
            break;
        case 2:
            if (GFL_USE_IsLoaderDone() == 1) {
                s32 z = 0;

                sub_020746B0(0);
                GFL_USE_FinishBgmLoad((u32)a0);
                sub_020755A8((u32)GFL_USE_GetCurrentSndHandle(), 0, z - 1, z - 1, (u32)a0);
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
