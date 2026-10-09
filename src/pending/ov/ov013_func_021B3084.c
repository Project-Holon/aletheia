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
 * pass 5 2026-10-06 P5L03 (3 rounds, 40 compiles, best stays 6 B, c99 and c): same residue (the
 * 3C50 pool load wins the pick after the lsr, so it is live across thr and thr gets ip). Tried (6
 * unless noted): SDK nested CP_GetSqrtResult32 { CP_WaitSqrt(); return CP_GetSqrtResultImm32(); }
 * at one or all sites (42 without thr); pointer/direct mixes for the three stores (f0 direct 6,
 * f4 direct 15, q for 3C50 6); non-volatile SQRT_PARAM as in 021B33F8; ret = 1 between or after
 * the 4C2C stores; all f0 volatile removed (still 6: the pointer copy alone holds the schedule, kept
 * volatile for the shared struct with 021B3018); a volatile view for p (17); inline setter
 * VadSetThreshold(st, thr) (17); inline VadThreshold(rms); &d_021B3C50 taken at the top; 3C50 as a
 * u32 array; 3C50 store between or before the 4C2C stores (12, 24); ring update per arm (321);
 * static const pointer to 3C50 (231, not folded); pragmas opt_pointer_analysis off,
 * opt_pulloutconstants off, opt_moveinvariantsinaddressexpr off, opt_optimizecontrolflow off,
 * peephole off; thr = REG then p then (thr*3)>>1 (8); ret u8; d_021B3C50.f0 = ret = 1; sq reused
 * for thr; thr at function scope. Matched-assembly search: `str rA,[rB]; ldr rA,pool; str
 * ..,[rB,#k]; str ..,[rA]` occurs only here. Notes: scratchpad wD9r/p5_P5L03/research.md.
 * pass 6 2026-10-06 P6L03 (3 rounds, about 40 compiler runs, best stays 6 B): scheduler capture
 * of mwccarm (pre-RA pass 1 and post-RA pass 2, DAG, heights, aliases, picks) plus a replay
 * model. Proof: holding back only the 3C50 pool load in the pre-RA pass of the success block
 * (debugger edit) makes the whole function byte-exact. Pre-RA, the zero copy must take the load
 * stall (so the f4 store must not wait on the f0 store) and then `str thr` (height 3) must beat
 * the 3C50 pool load (height 5); no volatile subset, statement order, alias spelling or variable
 * reuse gives that graph (webs split before the pass, alias analysis sees through casts). The
 * original needs an extra pre-RA node or edge after `str thr`. Tried: ret or p reused (11, 6),
 * goto split (6), f4 store spellings (6), volatile f4 (15), ring update per arm (317), 3C50
 * store after the join (225); all dsi builds give 6. Notes: scratchpad wD9r/p6_P6L03/research.md.
 * pass 6 2026-10-06 P6L09 (3 rounds, 10 compiler runs, best stays 6 B): alias trace of the
 * success block. The narrow-spill rule (ov093 021D09E0, 021D32E0) does not apply: no stack
 * slots, and the residue is in the pre-RA pass. The unknown set G already holds every object;
 * the three stores are k1 (4C2C+0, 4C2C+4, 3C50+0) and the backend traces p to the symbol across
 * copies and blocks (opt_pointer_analysis off: same). Replay: only str thr -> str f4 plus
 * str f4 -> str 3C50 (both lat 1) works, so str f4 must alias both f0 fields; no k1 object can.
 * Tried: p at outer-block top (309), p at function scope (313), local aggregate for f0/f4 (430).
 * Notes: scratchpad wD9r/p6_P6L09/research.md.
 * pass 6 2026-10-06 P6L11 (3 rounds, 13 compiler runs, best stays 6 B): mwccdbg sched/sched-replay on
 * pre block 16 confirms the pick order 0 4 1 6 2 3 9 8 5 7 10 11. Edits that fix it: str thr -> 3C50
 * load or -> mov #1 (lat 0), str thr -> 3C50 store with lat 2, the f4 store aliasing both f0 stores,
 * or a new node fed only by str thr. New rule found: a pool address load keeps the AO of the IR
 * address it was made for, and each access adds its own offset again (0x574CB0), so a direct
 * field access falls back to the unknown set when 2*off + size > object size (why every f8 access
 * here is kind 2). The f4 store would need a base AO offset >= 5 or an 8-byte object; neither fits
 * the 12-byte d_021B4C2C. Also ruled out: register-pressure pick mode (limit 14, peak 6), block
 * skip flags (set only after the pre pass), VadState.f4 as s32 (6), f4 direct (15).
 * Notes: scratchpad wD9r/p6_P6L11/research.md.
 * pass 6 2026-10-06 P6L13 (3 rounds, about 30 compiler runs, best stays 6 B): declared object size
 * lever. Direct field accesses get AO lookup(obj, 2*off, size) (lda pass 0x51B215 plus pointer
 * analysis), pointer accesses lookup(obj, off, size); incomplete arrays never go to G. With a
 * 12-byte d_021B4C2C nothing in the success block can be G. An 8-byte declaration (VadHead {f0,
 * f4}) with the success f4 store direct makes block 16 exactly the original, but the ring updates
 * then need their f4 accesses both outside G (else the ring store aliases them: 41-53 B) and on a
 * late lda vreg (pointer form st: schedule exact, colours off, 25 B; regalloc-replay shows st must
 * be numbered after the block's temps). f8 kept direct only with a flexible array member (f1, 37 B).
 * No plausible form gives both. Notes: scratchpad wD9r/p6_P6L13/research.md.
 * pass 6 2026-10-06 P6L14 (3 rounds, 13 compiler runs, best stays 6 B): refine log shows each access
 * AO is the merge of a refine from the off-0 base and one from the lda's own IR offset, so the
 * success f4 store reaches G only from an lda made for f8 (none in block 16, and lda sharing stops
 * at the loop exit) or an object under 12 bytes. File statics get separate pool words (no 8-byte
 * head plus counter variable) and stay in G (static ring with the 8-byte form: 37). VadCfg as its
 * true 16-byte layout (6), ring declared [4] (6). Notes: scratchpad wD9r/p6_P6L14/research.md.
 * pass 6 2026-10-06 P6L15 (3 rounds, 6 compiles plus 9 mwccdbg captures, best stays 6 B): TU context
 * and control flow. All three objects defined in the TU (VadCfg 16 B with the .data values), all
 * three file statics, and siblings 021B3018/021B3064 (address passed to memcpy) before the function:
 * 6 B each, block-16 AOs unchanged. Flag form ret = (sq && sq >= root << 1); if (ret): 344; do/while(0)
 * with break: 93; goto shared exit: 93 (block-16 DAG and picks unchanged). Volatile f4 replay: the
 * new str thr -> str f4 edge takes the release count from the zero copy at cycle 3, so the 3C50
 * pool load moves earlier (why volatile f4 was worse). desc is an instruction class (copy 0, store
 * 1, alu 2, ldr 3, lda/mov-imm 4). storeload/localcse run before sched pre, so no vanishing node
 * can feed str thr; no WAR is possible (thr and base defined in block 16). A second smaller extern
 * name would need a second 4C2C pool word (the listing has one). Notes: wD9r/p6_P6L15/research.md.
 * pass 6 2026-10-06 P6L16 (3 rounds, 9 compiler runs, best stays 6 B): block-boundary route. The pre
 * pass sees 28 blocks, the post pass 19: loop preheaders and while-entry jumps (each a `b` to the next
 * block) and if-convertible ifs are merged after pre, so a straight-line pre boundary is possible, but
 * every source of one is a loop or a predicated if, and the binary has none after `str thr`. Tried:
 * do { p->f0 = thr; ret = 1; } while (0) (labels gone before the backend, 6); one-trip for loop around
 * the f4 store (folded, 6); ret flag with `if (ret) { f4 = 0; cfg = 1; }` after the join (no jump
 * threading, 375); --skip-block pre:16 edit (23, so not a skipped block). Opcode table: no code-free
 * barrier pseudo-op. Neighbour pragmas: + opt_common_subs off (as 021B33F8/021B3924) 6, opt_lifetimes off
 * (as 021B0614) 198. Statement order cannot move the cycle-6 pick (decided by height, deadlines cannot
 * separate the nodes). Notes: scratchpad wD9r/p6_P6L16/research.md.
 * pass 7 2026-10-09 r5g02 (about 8 compiles, best stays 6 B): checked the pick table of pre block 16
 * again. Putting d_021B4C2C.f8 = 0 into the success block (a real G-set store after the f0 store)
 * gives the wanted order 5 7 10 (str thr, str f4, then the 3C50 load), because h(str thr) rises to
 * 5 and ties the pool load, which loses on desc. So the original has one more node after str thr
 * with a latency path of 2 to the end; no emitted instruction can be that node. Same family as the
 * 8-byte head result of P6L13: with f1 (flexible f8) only the two ring updates differ (37 B), and a
 * ring declared [4] changes nothing (the ring store AO stays inside G, so str ring -> str f4 stays
 * an edge). Not filed. * symbols:
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
