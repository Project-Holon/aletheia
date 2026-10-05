/*
 * function: func_021550DC
 * address:  0x021550DC
 * packet:   pkt_ov008_021550DC
 * region:   ov008
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * checks: 1 ARM9 unit020120F0 own pointer returns/const args and 020120B4 four-arg forwarder reread; 2 ov001/ov004 sibling interfaces and ov008 neighbours unchanged, no new twin; 3 full-word enum state and Bool return retain11, top-level const pointers retain11; 4 register-tie/front-end and typed-pointer idioms read; 5 fresh idiom directory/neighbours, no stack-object residue. Prior permuter300 consumed, not repeated.
 * wave75: 4 runs; swapped-signature inline wrapper, st=st, unsigned state, proper pointer-return prototypes and const table all retain DIFF11/96B. Both scheduling levers consumed.
 * wave76: 4 runs; parameter reuse worsens74, enum state11, Bool result11; stopped after three nonshrinking iterations; const-pointer check11. Retained previous best C.
 *
 * near miss: DIFF 11 bytes: only the r5/r6 swap (original r6=state ptr, r5=object; ours r5=state, r6=object); switch/if forms, statement order, struct forms tried.
 * lane R1 (2026-09-28), 20 more runs, all still the same 11-byte swap: local copies of either or both
 *   params in every declaration order (coalesced away), `u32 m = *mode` read before args[0], u32/void*
 *   types as in the matched ov001/ov004 siblings, Args/Req struct form, `register` on either param,
 *   K&R parameter declarations in swapped order, `*q = ...` for args[4], `default:` first, inverted
 *   case-1 test; permuter --budget 300 found nothing below 11. A `ret` variable or hoisting q above the
 *   switch makes it worse (80 / 25 bytes). The allocator seems to order the two params by parameter
 *   position regardless of source; untried: a wrapper/inline caller shape.
 *
 * recoup 2026-10-05 (wave P19, lane P19L1): real extent 0x021550DC..0x02155138 (92 B + pool); still DIFF 11 B,
 *   only the r5/r6 swap (original st=r6, o=r5; build st=r5, o=r6). Callee types re-checked against matched
 *   definitions (F4 returns void *, F0 returns u32, B4 void; all already as declared). Tried, no change:
 *   all six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments,
 *   scheduling, peephole): 11 B each; *st += 1 and *st = *st + 1: 11; first param as void *: 11; st as
 *   one-field struct pointer: 11; o as 16-word struct with o = ob->w: 11; local s = *st: 11; q declared
 *   before h: 11; dead first parameter reused as h: 11. Worse: returns in each arm 37; if/if chain 62;
 *   case 1 before case 0 78; Ctx struct fields with &o->out 74; h read in each arm 14.
 *   Twin search: grep func_020120F4/func_020120B4/func_020120F0 in src/matched/ov (ov010 0215A370, ov000
 *   021542C0 use the same callees; 0215A370 reads s = *st then p0 = c->f0, no shape that changes this).
 *   Idioms read in full: two-long-lived-values-in-each-others-registers (no missing arg, no join local),
 *   a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off (pragma: no effect here),
 *   a-base-pointer-and-its-mask-scratch-swap-as-an-allocator-tie, a-dead-parameter-reused-as-the-index-
 *   rotates-the-loop-registers (u reused: 11), a-compound-assignment-on-a-field-flips-the-guards-register-pair (+=: 11).
 *   Human-source note: st is longer lived than o (reloaded after the call) yet the original gives o the lower
 *   register; no source form tried reverses the colouring order. Unresolved.
 *
 * final push 2026-10-05 G3L10 (34 compiles, 3 rounds; still DIFF 11/96, only the r5/r6 swap):
 *   Mechanism found: mwcc pushes nodes by ascending vreg once degree < K; in ours st has one more
 *   st-only temp neighbour than o (loaded o[3] value, -1 constant, the reload) so o is pushed first and
 *   gets the higher register. Extending o's live range past the 020120B4 call (probe: `o[1] = 0;` after
 *   `(*st)++`, not a valid form) flips the colouring to the original (o=r5, st=r6), so the original has o
 *   live later or one fewer st-only temp. Per-arm loads of o[0] (no hoisted h; inline Setup(o) or o[0]
 *   read in each arm) also give the original colours but move the ldr r7 below the dispatch (14 B).
 *   Tried, all 11 B: const-free forms with st[0]/*st, u32 st, void **o, struct o (typed fields), copies of
 *   o and st declared inside case 0 in all orders, local obj for o[2], q declared in-block, callee types
 *   from the matched twin ov010 0216C978 (const struct Ctx *, struct IcaAnime *, u32 id, ~0), static inline
 *   Setup(o, h) and Step(st), o[0] re-read in F4/F0 calls. Worse: q[5]=o[3] moved earlier 28-36 B,
 *   o[0] re-read at the B4 call 73 B, one-struct &o->out form 74 B, per-arm h without hoist 14 B.
 *   Matched-asm search for the exact prologue/arg sequence (adds r4,rN,#0; adds r0,r7,#0; adds r4,#imm):
 *   only ov010 0216C978 (matched, st=r5 o=r6 natural, smaller body). Same prologue (r6=r1, r5=r2) in
 *   matched ov010 021619B8, ov071 021B730C: o there is used in case 1 or has far more uses. Unresolved.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_0215513C     0x0215513C  data  ov008  a4
 */

void *func_020120F4(const void *h);
void func_020120B4(void *h, unsigned int a, void *t, void *q);
unsigned int func_020120F0(const void *h);
extern char d_0215513C[];

int func_021550DC(int u, int *st, int *o)
{
    void *h = (void *)o[0];
    int *q;

    switch (*st) {
    case 0:
        q = o + 4;
        o[4] = (int)func_020120F4(h);
        q[2] = o[2];
        q[1] = o[1];
        q[3] = *(int *)(o[2] + 0x48);
        q[4] = *(int *)(o[2] + 0x4c);
        q[5] = o[3];
        func_020120B4(h, -1, d_0215513C, q);
        (*st)++;
        break;
    case 1:
        if (func_020120F0(h) == 0)
            return 1;
        break;
    }
    return 0;
}
