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
