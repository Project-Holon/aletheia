/*
 * function: func_021B3084
 * address:  0x021B3084
 * packet:   pkt_ov013_021B3084
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * note 2026-10-05 (wave P5 lane T4): written from the listing, no twin found.
 * Voice-activity style gate: d_021B4C38 is a 4-entry ring of energies, the
 * hardware sqrt of the ring mean is compared to a threshold (d_021B4C2C.f0);
 * returns 0/1 (idle: start), 2 (active), 3 (active timed out). 17 bytes differ,
 * 1 block: in the start path the compiler keeps the sqrt result in ip and loads
 * the d_021B3C50 pool word before the *3 >> 1, the original keeps r1 for the
 * result, puts mov lr,#1 in the load stall and loads the pool word after.
 * Closed by: separate loop counters (int i, block-local u32 j), i = sum = 0
 * chains, ring read before the compare (root local), return-3 tail with
 * if (res <= thr) { ... } else f8 = 0; ret = 2 after the join. Tried without
 * effect: all six per-function pragmas, ret = 1 earlier, chained
 * d_021B3C50.f0 = ret = 1, inline ring-rms helper (worse).
 *
 * note 2026-10-05 (wave P5 lane T4b, 16 compiles, still 17 B): same single
 * residue. Tried without effect (all 17 B unless noted): sqrt result via a
 * u32 local or an inline CP_GetSqrt32; `* 3 / 2`; ret = 1 before the stores
 * (with d_021B3C50.f0 = ret); cfg pointer local at function top (260 B, all
 * pool loads hoisted and registers shift), only at the store, all uses via
 * cfg (378 B); VadState pointer local in the block; swapping the f0 and f4
 * stores (27 B); cfg store first (235 B, shifts 4 B); cfg store between f0
 * and f4 (23 B); second sqrt reusing i/sum (23 B); signed f0 fields.
 * Reading: the original pool load of d_021B3C50 sits after the f0 store with
 * the sqrt result in r1 (anti-dependence), so r1 was coloured for the result
 * and the pool load scheduled after it. The compiler gives r1 to the pool
 * address instead. Looks like a list-scheduler/colour tie
 * (docs/idioms/a-pool-word-order-residue-is-a-list-scheduler-tie.md), no
 * source shape found. Parked.
 *
 * recoup 2026-10-05 (R16, 13 compiles, best stays 17 B): same single residue
 * (pool d_021B3C50 load scheduled before the *3 chain, result in ip). Tried:
 * second result via root local (17), via sum2 reuse (17), via a block local
 * (17), sum2 = result * 3 then >> 1 (17), ret = 1 before the f0 store with
 * f0 = ret (17), f4 store before f0 (27), ret = 0 before the if with no else
 * (452 B), failure-first polarity (96), ret = 1 at block top (464 B),
 * declaration orders root,i,sum,ret (456 B) and sum,i,root,ret (21).
 * Idioms checked: a-pool-word-order-residue-is-a-list-scheduler-tie (matches
 * the symptom, no source lever), a-dying-pointer-loads-scratch-colour-can-be-
 * an-allocator-tie, a-pool-address-takes-ip-only-when-the-low-scratch-is-
 * reserved, a-width-stored-in-the-handle-temp-it-replaces (reuse, 17),
 * a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer
 * (const not applicable, no pointer reads). Pragmas not retried (header).
 *
 * final push 2026-10-05 G5L3 (39 compiles, 3 rounds, best stays 17 B): same single residue. Tried (all 17 B
 * unless noted): named locals for result/threshold (c99 initialised too), ret = 1 first / after WaitSqrt /
 * before the call, d_021B3C50.f0 = ret, flag local, chained ret forms, inline helpers (VadStart,
 * VadThreshold, VadRead), (r*3)/2 and r + (r<<1) >> 1 (464 B, 236 off), ret as int/s32/u8, signed f0,
 * 3C50 and 4C2C as arrays (alone and both), f0 store of 3C50 before the result read (235 off),
 * ret and 3C50 store before the sqrt call (74 off), opt_propagation off with named locals
 * (function-wide, breaks the loops: 401 off). Reading (mwcc docs/SCHEDULER.md pick rule: urgency,
 * release count, height, textual order): the pool load beats mov lr on height here; the original picks
 * mov lr, so its pool load had lower height or a predecessor edge. Same family as the pending ov013
 * 021B3018 pool-slot residue. Matched-assembly search for ldr/mov lr,#1/add lsl #1/lsr: only this
 * function. Parked.
 *
 *
 * final push 2026-10-05 G10L10 (about 38 compiles shared with 021B3018, 3 rounds, best stays 17 B): same
 * single residue. One-object model checked first and ruled out: d_021B3C50, d_021B4C2C and d_021B4C38 lie at
 * 3C50, 4C2C, 4C38 (ring directly after the state, 12 B apart); modelled as one struct, ARM folds the field
 * offsets into one pool word (the original has separate words 323C, 3240, 324C), so they are separate objects
 * (33F8 only kept sym+0x484 as a pool word because of the large offset). Tried (all 17 B unless noted):
 * all pairs of per-function pragmas (common_subs, lifetimes, dead_assignments, peephole, scheduling; any pair
 * with lifetimes 200 B); ret = 1 first with d_021B3C50.f0 = ret (235 B, f0/f4 become an stm); 3C50 store
 * first (235 B); ret=1 before the f0 store with the 3C50 store last; a block-local u32 one = 1 used for both
 * stores; ret read back from d_021B3C50.f0; chained d_021B3C50.f0 = ret = 1 (17 or 23 B); block-scoped
 * VadState and VadCfg pointer locals in either declaration order. Cross-check: the original has no stm
 * between the f0 and f4 stores only because the 3C50 pool load sits between them. Parked.
 *
 * pass 2 2026-10-06 P2L32 (3 rounds, about 90 single compiles plus sweeps, best 15 B): adopted the
 * sibling 021B3018 model (volatile f0 in VadCfg and VadState, which closed 3018): 17 -> 15 B. Sweeps:
 * all 512 volatile subsets (c0+s0 only best), volatile x store order (96), every opt_* pragma name
 * in mwccarm 1.1p1 on/off: none below 15. Same single residue: the 3C50 pool load takes the load
 * stall instead of mov lr,#1. A side-effecting right-hand side moves the value before the address
 * load and fixes schedule and colours: `ret = 0; d_021B4C2C.f4 = 0; d_021B3C50.f0 = ++ret;` (or
 * `ret = d_021B4C2C.f4 = 0; ... = ++ret`) gives 2 B, but emits add lr,r3,#1 (from the zero
 * register) for mov lr,#1; not a human form, not filed. Constant right-hand sides (ret = 1 first,
 * chains, one-locals, inline helpers returning 1, propagation off) all keep the mov below the pool
 * load. Lead: the original needs the #1 materialised textually before the 3C50 address load.
 *
 * pass 3 2026-10-06 P3L15 (3 rounds, 40 compiles, best stays 15 B, c99 and c): same single residue.
 * Tried (15 B unless noted): ret as enum VadResult (also enum f0 field and enum return type); ret
 * u8/u16/s32/register assigned before the stores; inline setter with enum or u32 parameter (also
 * under opt_propagation off); ret = 1 in the earlier block under opt_propagation off (59); a cfg
 * pointer for the top store, the test and the success store (377); `u32 ret = 0` initialiser with
 * `f0 = ++ret` (377); ret = 0 before the inner if (295); ring update and ret in each arm (175);
 * ++ret under opt_propagation off or opt_common_subs off (2 B, still add lr,r3,#1: the zero reuse is
 * a backend constant tracker); inline helpers returning ++st or writing through &ret.
 * Matched-assembly search: a constant materialised before its own pool base in one statement occurs
 * once in all listings (a phi value), the reverse order 122 times; a constant right-hand side is
 * always placed after the base. Notes: scratchpad wD9r/p3_P3L15/research.md.
 * pass 4 2026-10-06 P4L09 (3 rounds, 40 compiles, 15 -> 6 B, c99 and c): opt_propagation off with
 * do-while loops (P2L32 h1), a block-local VadState pointer p for the two d_021B4C2C stores and a
 * block-local thr for the scaled root. The pointer copy moves mov lr,#1 into the load stall and fixes
 * the 4C2C base (r2). Left: the lsr result gets ip (original r1), so the post-RA pass lifts the 3C50
 * pool load (r1) above the f0 store; the pre-RA schedule still puts that pool load between the lsr and
 * the store. Without thr: 8 (lsr r2, base ip). Tried (6 unless noted): p reused for 3C50 (one struct
 * type), a separate q pointer for 3C50 (q only: 21), p before thr (8), thr in place (thr = REG;
 * thr *= 3; thr >>= 1), root or sum reused for thr, initialised declarations, declaration orders,
 * ret = 1 earlier with f0 = ret, extra pragmas common_subs/loop_invariants (6), lifetimes (189), volatile
 * f4 (229), 3C50 store between the 4C2C stores (12), inline CP_GetSqrtResult32 (6, 8 without thr).
 * Matched-assembly search: `op rA; str rA,[rB]; ldr rA,pool` occurs only here among ARM functions.
 * Notes: scratchpad wD9r/p4_P4L09/research.md.
 * symbols:
 *   d_021B3C50  0x021B3C50  data  a4
 *   d_021B4C38  0x021B4C38  data  a4
 *   d_021B4C2C  0x021B4C2C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define reg_CP_SQRTCNT       (*(volatile u16 *)0x040002B0)
#define reg_CP_SQRT_RESULT   (*(volatile u32 *)0x040002B4)
#define reg_CP_SQRT_PARAM    (*(volatile u32 *)0x040002B8)

typedef struct VadCfg { volatile u32 f0; u32 f4; s32 f8; } VadCfg;
typedef struct VadState { volatile u32 f0; u32 f4; s32 f8; } VadState;

extern VadCfg d_021B3C50;
extern u32 d_021B4C38[];
extern VadState d_021B4C2C;

static inline void CP_SetSqrt32(u32 v)
{
    reg_CP_SQRTCNT = 0;
    reg_CP_SQRT_PARAM = v;
}

static inline void CP_WaitSqrt(void)
{
    while (reg_CP_SQRTCNT & 0x8000) {
    }
}

#pragma opt_propagation off
u32 func_021B3084(u32 x, u32 sq, u8 *out)
{
    u32 ret;
    u32 sum;
    int i;
    u32 root;

    d_021B3C50.f4 = sq >> 8;
    if (out != 0)
        *out = sq >> 8;
    if (d_021B3C50.f0 == 0) {
        i = sum = 0;
        do {
            sum += d_021B4C38[i];
            i++;
        } while (i < 4);
        CP_SetSqrt32(sum >> 2);
        CP_WaitSqrt();
        root = reg_CP_SQRT_RESULT;
        if (sq != 0 && sq >= (root << 1)) {
            u32 sum2;
            u32 j;
            VadState *p;
            u32 thr;

            j = sum2 = 0;
            do {
                sum2 += d_021B4C38[j];
                j++;
            } while (j < 4);
            CP_SetSqrt32(sum2 >> 2);
            CP_WaitSqrt();
            thr = (reg_CP_SQRT_RESULT * 3) >> 1;
            p = &d_021B4C2C;
            p->f0 = thr;
            p->f4 = 0;
            d_021B3C50.f0 = 1;
            ret = 1;
        } else {
            ret = 0;
        }
        d_021B4C38[d_021B4C2C.f4] = x;
        d_021B4C2C.f4 = (d_021B4C2C.f4 + 1) & 3;
    } else {
        d_021B4C38[d_021B4C2C.f4] = x;
        d_021B4C2C.f4 = (d_021B4C2C.f4 + 1) & 3;
        i = sum = 0;
        do {
            sum += d_021B4C38[i];
            i++;
        } while (i < 4);
        CP_SetSqrt32(sum >> 2);
        CP_WaitSqrt();
        if (reg_CP_SQRT_RESULT <= d_021B4C2C.f0) {
            d_021B4C2C.f8++;
            if (d_021B4C2C.f8 > d_021B3C50.f8) {
                d_021B3C50.f0 = 0;
                d_021B4C2C.f8 = 0;
                d_021B4C2C.f4 = 0;
                return 3;
            }
        } else {
            d_021B4C2C.f8 = 0;
        }
        ret = 2;
    }
    return ret;
}
#pragma opt_propagation reset
