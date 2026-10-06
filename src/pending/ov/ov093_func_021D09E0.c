/*
 * function: func_021D09E0
 * address: 0x021D09E0
 * packet: pkt_ov093_021D09E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * residual: 302/304 bytes, nine concrete bytes differ; count home-store at
 * entry and count reload at first loop latch reorder; two trailing zeros.
 * checks: 1 own ov093 bodies and ARM9 units rederived; pointer-payload externs corrected, all10 sites resolve, still DIFF9; 2 D0644/D0D50/CFBF0 byte-count callers reread, no sorting twin; 3 enum bound, long index, enum count, u16 count unchanged9; 4 home-store/spill, byte-count and masked-local idioms read; 5 fresh directory/neighbours reread, scores stack offsets agree.
 * wave75: six runs; stopped after three nonshrinking changes.
 * wave76: 5 runs, three nonshrinking iterations then checks1/3; best9/302 retained.
 * permuter: prior 300 --types consumed; best volatile(kind) mutant rejected;
 * search not repeated. Enum-bound hypothesis now tested unchanged.
 * 2026-10-05 wave P8 W9: u8 loop counter i with i++ (instead of i = (u8)(i + 1)) and
 * plain i < count closes the latch residue: 9 -> 5 bytes. Left: entry home store
 * 'str r2,[sp,#4]' is first in the original (before the r3/r1 copies), we emit it
 * third. Tried without effect: count u32 (9 B), u16 (11 B, signed branches), local copy
 * of count before the call, p as void *, func_021D57FC returning u32, pragmas scheduling
 * off and peephole off (5 B), opt_propagation off (275 B). The two trailing bytes of the
 * 304 B extent are padding (movs r0,r0), so size is exact (302 B).
 * recoup 2026-10-05 R3: still 5 B (entry 'str r2,[sp,#4]' third). Tried, no gain: i = 0
 * before the call (13 B); i/j declared first (12 B); j before i (12 B); count u32 (9 B),
 * int (15 B), u16 (11 B); p as u32, target as u8 *, func_021D57FC returning u32, type
 * cast (u16): 5 B; type u32/u16 (16 B); const count (5 B); count copied to a local
 * (5 B); explicit if (count == 0) return (289 B); pragmas opt_lifetimes off (96 B),
 * opt_common_subs off (267 B), opt_dead_assignments off (13 B). Spill slots already agree.
 * final push 2026-10-05 G2L4: still 5 B (only the entry order: original str r0,[sp]; str r2,[sp,#4]; adds r0,r3; adds r7,r1).
 * Matched entries with the same prologue (ov094 021F6B04, 021F94F8, ov021 021C9450, ov018 0217B4D8) all have u32/pointer
 * params and no r3->r0 first-call argument copy; no matched twin has this shape. Tried, all 5 B unless noted: target as
 * u32, int, u8 *, const void *, local copy; order as u32, u8 *const, local ord; p as const u8 *, u8 *const, u32, void *
 * plus local; count char (11 B), u16 (11 B, signed branches), u32 (9 B); type u32 (16 B); func_021D57FC returning int and u8;
 * count > i guard; while loop form; scores declared last; j as int (93 B). Store position does not depend on any
 * parameter width, so it is not the narrow-parameter idiom. Left DIFF.
 * round 4 (G2L4): also no change (5 B): pragmas opt_strength_reduction, opt_unroll_loops, opt_vectorize_loops off; opt_loop_invariants off
 * (17 B); cnt = count local before the call; n = count local before the sort loop; type as u16 (16 B); i declared before scores (12 B);
 * clamp of count (280 B); inline wrapper for func_021D57FC (16 B). func_021D57FC takes one argument (r1 is not read), so r1 live at
 * the call is only order's copy. Matched twins with r2 stored first use u32 params and no narrowing; none explains the order.
 * pass 2 2026-10-06 P2L08: still 5 B. 38 compiles. The count home store goes to the front in every build where the
 * first count read after the call comes before the spilled i = 0 store ('if (count > 0) { i = 0; do .. while }' gives
 * the right entry but beq and i = 0 after the guard, 9 B; i = 0 before the call gives the right entry but moves the i
 * store, 13 B). Also no change: num = count after the call, block-scoped or separate loop counters, scores[i] = j = 0,
 * for-init comma with type, register count/i, u8 *const p, unprototyped func_021D57FC, struct view of p, K&R (288 B),
 * target reused as mon (282 B), type u8/u16 (16 B), type declared later (12 B), opt_dead_code off, --lang c99.
 * pass 3 2026-10-06 P3L03: still 5 B, about 40 compiles. Probe: the right-entry form 'if (count > 0) { i = 0; do }'
 * plus one more spilled zero def before the guard flips the entry back to ours, so any zero def between the call and
 * the count compare puts the count home store late; the original has that zero and still the early store. No change
 * (5 B unless noted): counter-guard do-while, goto guard, u8 i = 0 at declaration, u32/u16/int num copies (5/11/11 B),
 * sibling 021D0980 u32 counter (9 B), u16 counter (69 B), loop names swapped (21 B), char *p, void *const target,
 * u8 kind, static function, block-scoped body locals, (u32)/(u16) casts in the guard, extra call arguments, inline helper
 * for loop 1 (16 B), const int type (16 B), call in both arms (101 B), opt_propagation off with copies or do-while (275 B),
 * scheduling off (inert), ipa off and K&R after a prototype (CCERR).
 * symbols:
 *   func_0201C314 0x0201C314 thumb
 *   func_0201C1C8 0x0201C1C8 thumb
 *   func_0201C1D8 0x0201C1D8 thumb
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D799C 0x021D799C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021D57FC(void *);
extern void *func_021B9C00(void *, u32);
extern int func_021D5B68(void *);
extern u8 func_021D5448(void *);
extern u8 func_021D5584(void *, u32);
extern u16 func_021D54C0(void *, int);
extern u32 func_0201C314(void *);
extern u8 func_0201C1C8(void *);
extern u16 func_0201C1D8(void *);
extern int func_021D799C(int, int);
void func_021D09E0(u8 *p, u8 *order, u8 count, void *target)
{
    u16 scores[6];
    int type;
    u8 i;
    u8 j;
    void *mon;
    u16 move;
    u16 power;
    u16 temp;
    u8 tempid;
    type = func_021D57FC(target);
    for (i = 0; i < count; i++) {
        scores[i] = 0;
        mon = func_021B9C00(*(void **)(p + 0x118), order[i]);
        if (!func_021D5B68(mon)) {
            u8 n;
            n = func_021D5448(mon);
            for (j = 0; j < n; j++) {
                if (func_021D5584(mon, j)) {
                    move = func_021D54C0(mon, j);
                    if (func_0201C314((void *)(u32)move)) {
                        int kind;
                        kind = func_0201C1C8((void *)(u32)move);
                        power = func_0201C1D8((void *)(u32)move);
                        if (power < 10) power = 60;
                        switch (func_021D799C(kind, type)) {
                        case 5: power *= 4; break;
                        case 4: power *= 2; break;
                        case 2: power /= 2; break;
                        case 1: power /= 4; break;
                        case 0: power = 0; break;
                        case 3: break;
                        }
                        if (scores[i] < power) scores[i] = power;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
                tempid = order[i];
                order[i] = order[j];
                order[j] = tempid;
            }
        }
    }
}
