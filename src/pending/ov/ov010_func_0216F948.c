/*
 * function: func_0216F948
 * address:  0x0216F948
 * packet:   pkt_ov010_0216F948
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Builds the list of level-up moves a mon could still learn: reads
 * species/form/level and its 4 current moves, loads the learnset (26
 * {move, level} pairs, 0xFFFF/0xFFFF terminated) with func_0201ADD0, and
 * collects moves at or below its level that it neither knows nor already
 * collected. Returns the 0x34-byte list (caller frees); frees the learnset.
 * Callees: func_02030734 (heap, size, flag, file, line) allocs, func_020307B0
 * frees; no callee takes fewer parameters than passed.
 *
 * 2026-10-05 (wave P6 lane U9): DIFF, 296 B vs 344 B. Original keeps one
 * distinct 4-byte Ent stack temp per use (8 of them, frame 0x40: isEnd and
 * level param copies, two-level copies for the cur and out searches, one for
 * the store) and holds the cur base (sp+0x38) hoisted in r7, tbl spilled to
 * [sp,#0x14], j in ip. mwcc here merges the temps (frame 0x28) and keeps tbl
 * in a register. Tried: by-value inline helpers (this file); flat inline
 * helpers; opt_propagation off (320 B, adds boolean materialisation);
 * opt_lifetimes off (no change); explicit copy locals Ent t1..t7 (320 B,
 * frame 0x34, a stand-in form so not filed). Also the original zero is one
 * u8 (r4 = i) copied into n (r6); chained n = i = 0 gives a separate n zero.
 *
 * 2026-10-05 (wave P6 lane U9b): DIFF. Closest forms are in wD9r/u9b_8.c
 * (328 B, frame 0x3c, 254 B differ; explicit per-use Ent copy locals t1..t7
 * declared in the original slot order, `#pragma opt_dead_assignments off`,
 * `i = 0; n = i;` (gives the original prologue: zero in r4, n copied to r6),
 * `for (; i < 4; i++)`). dead_assignments off is the lever that keeps the
 * dead t2.move half-copy and gives 8 distinct Ent slots, same relative layout
 * as the original. Tried without result: block-local `Ent x = e;` copies
 * (320 B, copies merge), the four untried pragmas on the helper form
 * (common_subs 296, scheduling 296, peephole 296, dead_assignments 308 B),
 * dead_assignments off on the explicit forms (328 B), function-level or
 * block-local cur pointer (propagated, or spills everything at 0x44),
 * declaration order tbl/out, opt_propagation off on top (348 B).
 * Remaining residue: the original hoists &cur into r7 for the fill loop
 * (mon in r5, i in r4) and spills tbl to [sp,#0x14] with j in ip; ours keeps
 * mon in r7, recomputes the cur address after the call and keeps tbl in r7.
 * One extra live value in the original loops (cur base) was not reproduced.
 *
 * 2026-10-05 final push G9L7: DIFF, 340 B vs 344 B, 156 B differ (was 225 B
 * differ at 296 B). Best form: the explicit per-use Ent copy locals of U9b
 * (declared in the original slot order) under `#pragma opt_propagation off`,
 * with do-while loops for the fill and k loops (no entry guard, as in the
 * original; for loops gain a `cmp rN,#4; bhs` guard under the pragma). The
 * pragma explains three things the earlier forms missed: the original's
 * second-level copy t4 = t3 is reloaded from t3 (not forwarded), the k and m
 * loops reread t4.move / t6.move each iteration, and the fill loop hoists
 * `add r7,sp,#0x38`. The fill loop and the whole k section now match the
 * original instruction for instruction (register names aside). Without the
 * pragma the t3->t4 and t5->t6 copies collapse (v13, 320 B).
 * Remaining residue: (1) the original is propagation-on for constants: its m
 * loop guard is `movs r5,#0; cmp r6,#0; bls` (m = 0 folded, copies t5/t6 sit
 * after the guard) where ours compares m with n (`cmp r2,r5; bhs`); `if (n > 0)`
 * gives `beq` instead of `bls`; copies inside the loop body stay in the loop.
 * (2) the original spills tbl to [sp,#0x14] and keeps j in ip (frame 0x40,
 * push {r3..}); ours keeps both in registers (frame 0x3c). (3) `n = i` is
 * `adds r6,r4,#0` in the original (zero args then read r6) but `movs r5,#0`
 * here. Diagnostic only, not filed: `t4 = *(Ent *)&t3;` with propagation ON
 * also gives the non-forwarded reload and the right m guard (336 B, 256 off),
 * so the original's temps are probably reached through a type-punned or
 * pointer access; no human form for that was found (pointer-taking or
 * by-value inline helpers, named pointer local, member-wise copies, memcpy,
 * Ent[8], u16[2] temps all either collapse the temps or add spills).
 * Also tried: nested inline Find wrappers, static (non-inline) helpers (emits
 * calls), opt_common_subs/opt_loop_invariants/opt_lifetimes off, j = 0, named
 * cur pointer, passing n as the zero argument (344 B but 273 off).
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02173B74     0x02173B74  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u16 move;
    u16 level;
} Ent;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_02030734(u32 heap, u32 size, u32 flag, const char *file, u32 line);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
extern void func_020307B0(void *p);
extern const char d_02173B74[];

#pragma opt_propagation off
u16 *func_0216F948(void *mon, u32 heap)
{
    u16 cur[4];
    u16 species;
    u8 form;
    u8 level;
    u8 i;
    u8 n;
    u8 j;
    u8 k;
    u8 m;
    Ent *tbl;
    u16 *out;
    Ent t1, t2, t4, t6, t7, t5, t3, e;

    i = 0;
    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    level = func_02017E1C(mon, 0x9E, 0);
    n = i;
    do {
        cur[i] = func_02017E1C(mon, 0x36 + i, 0);
        i++;
    } while (i < 4);
    tbl = (Ent *)func_02030734(heap, 0x68, 0, d_02173B74, 0x55);
    out = (u16 *)func_02030734(heap, 0x34, 0, d_02173B74, 0x56);
    func_0201ADD0(species, form, tbl);
    for (j = n; j < 26; j++) {
        e = tbl[j];
        t1 = e;
        if (t1.move == 0xFFFF && t1.level == 0xFFFF) {
            out[n] = 0xFFFF;
            break;
        }
        t2 = e;
        if (t2.level > level)
            continue;
        t3 = e;
        t4 = t3;
        k = 0;
        do {
            if (cur[k] == t4.move)
                break;
            k++;
        } while (k < 4);
        if (k != 4)
            continue;
        t5 = e;
        t6 = t5;
        for (m = 0; m < n; m++)
            if (out[m] == t6.move)
                break;
        if (m != n)
            continue;
        t7 = e;
        out[n] = t7.move;
        n++;
    }
    func_020307B0(tbl);
    return out;
}

#pragma opt_propagation reset
