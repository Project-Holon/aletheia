/*
 * function: func_021620B0
 * address:  0x021620B0
 * packet:   pkt_ov010_021620B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker: 7 concrete bytes differ in 92/92 bytes: outer index and offset
 * spill slots at sp+0 and sp+4 are exchanged; instructions otherwise match.
 * checks: 1 own 02161ECC/02161E78 confirm1/1, SDK copy arity3; 2 current 02161D98/F90 no compacting twin; 3 unsigned offset/long index7/92, inner u8 index71/100 with extra narrowing; 4 aggregate and inline spill-home hypotheses both7/92; 5 refreshed idioms/neighbours, no new twin.
 * newpass: declaration reversal and block-local offset each remained DIFF7;
 * once300 --types permuter baseline and best DIFF7/92, exit1, no improvement.
 * evidence: scratchpad/overlay-newpass-20261003-w75/R5/0b0-*.log;
 * baseline emitted spelling agreed with fixed one. This search is spent.
 *
 * wave76: Four compiles: anonymous aggregate locals7/92; inline compact wrapper7/92; unsigned offset/long outer index7/92; u8 inner index71/100. Original best7/92 retained; final authorized retry exhausted; old permuter300 not repeated.
 * evidence76: scratchpad/overlay-newpass-20261003-w76/R2/; each log awaited to terminal exit.
 *
 * recoup 2026-10-05 (P19L2, 14 compiles): residue unchanged, 7/92 B: the original keeps
 * the outer index i at sp+4 and the offset o=i*0x18 at sp+0; ours puts o at sp+4 (o
 * is a compiler temp above the named locals). Callees checked: func_02161ECC returns int
 * (ov010_func_02161ECC.c), func_02161E78 is void. Tried, all DIFF 7: for-loop with o
 * in the body; o declared first; j in the inner block; a second assignment `o = i*0x18`
 * after the call or at the end of the body (a-redundant-second-assignment idiom, which is
 * a stand-in here); named k = j*0x18; struct-array copy a[i] = a[j] (inlined, 100 B, 54 off);
 * each per-function pragma (opt_common_subs off 72 off, others 7). Idioms read: separate-index-local-
 * per-loop, scaled-record-base-pointer, redundant-second-assignment, spilled-value-below-cse-temps,
 * narrow-flag-local. Twin search: grep of func_02161ECC/02161E78/02082D44 in src/matched/ov found only
 * ov010 siblings 02161D98, 021621E8, 0216220C (no compacting twin).
 *
 * final push 2026-10-05 G3L3 (40 compiles, 3 rounds): still DIFF 7/92 B, spill slots of i and o exchanged.
 * Model: slot order low to high is inline locals, named locals (last declared lowest), compiler temps;
 * o = i*0x18 folds to a temp, so it sits above named i; the image has o below i. Tried, all DIFF 7:
 * no o local; o=0 before i=0; callee decls const void pointer with u32, unsigned char*, T* (bitfield struct);
 * o declared first; i*0x18 at one use only (two forms); inline int offset helper (assigned and at each
 * site); whole-body inline helper; inline pointer helper; block-scoped o/j; C99 for-init locals;
 * continue-style loop; E[0x18] struct array with &p[i]; register int i; const int o; one-struct cursor
 * {off,idx} (both field orders); o reassigned before the memcpy; declaration initialisers; while (++i < 10);
 * named src/dst offsets (both orders); param copy local; unsigned i (8 B); unsigned char o (96 B, extension code);
 * pragmas opt_strength_reduction, opt_loop_invariants, opt_vectorize_loops, opt_dead_code, opt_unroll_loops,
 * opt_cse_calls off. Matched-asm search for `ldr [sp,#4]; muls; str [sp]` found no twin (only this function);
 * 22 generic `muls; str [sp]` sites spill the offset with the counter in a register. Caller func_02161E60
 * passes p+8 / p+0xF8. Idioms read: of-two-equal-temps, function-scope-vs-block-scope, a-spilled-local-assigned-twice,
 * an-inline-return-temp, a-redundant-second-assignment, a-two-word-region-as-a-struct, scaled-record-base-pointer,
 * spilled-value-below-cse-temps, a-loop-counter-zero-before-an-offset, constant-temp-reuses-first-assigned-slot.
 * pass 2 2026-10-06 P2L14 (40 compiles, 3 rounds): still DIFF 7/92. Tried, all 7 unless noted: inline
 * helper with o as parameter (both orders); inline int *pi helper; inline offset helper with a local;
 * inline move helper; o assigned twice with both declaration orders; all six declaration orders; 0x18*i,
 * 1+i, o+p, i += 1, i = i + 1, ++i; one-field struct carrier for i and for o; o = i; o *= 0x18;
 * for (j = i; ++j < 10;); j = i; while (++j < 10); o assigned inside the call argument; named pointer
 * under opt_propagation off; opt_lifetimes off; opt_propagation off with o first; inner while loop.
 * Worse: inner search then if (j < 10) (77), optimization_level 3/2 (71/69), three pragmas off (72).
 * Diagnostics: volatile i gives the image slots (i memory-homed above, o spill temp at sp+0, 10 B
 * from one extra reload); o as a second parameter stays 7. Matched sub sp,#8 functions with a counter
 * at sp+4 (ov119 021DD174/021E5164, ov183 021DF5B8, ov048 021F4590, ov194 021F4F7C, ov094 02209458)
 * all have a spilled parameter at sp+0; no matched body temp below a counter. Notes: scratchpad wD9r/p2_P2L14.
 * symbols:
 *   func_02161ECC  0x02161ECC  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02082D44  0x02082D44  arm
 */

extern int func_02161ECC(char *);
extern void func_02161E78(char *);
extern void func_02082D44(char *, char *, int);

void func_021620B0(char *p)
{
    int i;
    int j;
    int o;

    i = 0;
    do {
        o = i * 0x18;
        if (func_02161ECC(p + o) == 0) {
            for (j = i + 1; j < 10; j++) {
                if (func_02161ECC(p + j * 0x18) != 0) {
                    func_02082D44(p + j * 0x18, p + o, 0x18);
                    func_02161E78(p + j * 0x18);
                    break;
                }
            }
        }
        i++;
    } while (i < 10);
}
