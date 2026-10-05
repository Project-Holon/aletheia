/*
 * function: func_02155F58
 * address:  0x02155F58
 * packet:   pkt_ov009_02155F58
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (user decision): the goto into the case 4 if-body is accepted as real source.
 * 2026-10-05 (wD9r lane158): EXACT. Shape: `ret` has no initialiser; `v = 0` at the top is the value of
 *   the early callback return (`return v;`) and of the r == 0 path. `if (r == 0) goto L;` enters case 4,
 *   where `L: ret = v;` follows the DWC_GdbShutdown call. The copy at L is needed on the r == 0 path (ret
 *   has no other definition there), so it is not a redundant statement; on the DWC path it repeats the
 *   `ret = v;` before the switch. This copy survives branch threading, so the r == 0 beq lands on case 4's
 *   join `b` as in the original. Tried and not taken: the post-switch tail as a static inline
 *   `finish(a, b, r, ret)` (432 B, same bne/b).
 * 2026-10-05 (wD9r lane143): HIDDEN SECOND RESIDUE FOUND AND FIXED. The draft also had an extra lone `b` in the
 *   case 3/6 inner switch (the 0x7A9 if-join jumped to the shared func_0205CC20 call; bne landed on that b).
 *   The original falls through: the 0x7A9 arm has no func_0205CC20 call and no break, it falls into
 *   `case 0: case 1: case 2: func_0205CC20(); break;`. Applied here (real source form). Now only the r == 0
 *   bne/b remains (code 0x19C vs 0x19A; the size shows 436 because the original's 2-byte pad absorbs it).
 *   Probes with the fall-through (scratchpad wD9r/l143): (1) w2.c = lane125's goto mechanism with
 *   `ret = v;` BEFORE the switch, `if (r == 0) goto L;`, case 4 `if (range) { DWC_GdbShutdown(); L: ret = v;
 *   goto out; }`: EXACT. Not filed: the case 4 `ret = v` repeats a value ret already holds on that path (a
 *   redundant statement, stand-in rule) and the goto enters a case body. (2) w3.c = lane125's p3 (ret = v
 *   after the switch, so the case 4 copy is not redundant) plus fall-through: 436 B, only residue is the
 *   case 1/2 cross-jump flip (case 1 jumps into case 2's `movs r0,#6; bl` instead of the reverse); case
 *   order swap moves the layout (worse), declaration order and `if (!range) break;` form of case 4 do not
 *   change it. The flip comes from the post-switch `ret = v` join block. Open: a real form with a
 *   non-redundant copy on the r == 0 edge and after the DWC call, with no copy at the main switch exit.
 * 2026-10-05 (wD9r lane125): still 4 bytes (440 vs 436). Mechanism found by probe (scratchpad wD9r/l125/p3.c):
 *   a register copy in case 4's join block survives branch threading and is removed only after colouring,
 *   so a beq into that block stays a beq onto a lone `b end`. Probe: switch value in `v` (ret = 0, v = 0 at
 *   the top), `ret = v;` after the switch, `if (r == 0) goto L;`, case 4 `if (range) { DWC_GdbShutdown();
 *   L: ret = v; goto out; } break;`: 436 B, beq onto 02156022 exactly. Residue of the probe: two cross-jump
 *   directions flip (case 1 jumps into case 2's `movs r0,#6; bl` tail instead of the reverse; the case 3/6
 *   inner switch gets an extra `b` to the shared func_0205CC20 call). Not filed: goto into a case body is not
 *   a natural form. Without the goto, an r == 0 copy block of its own is constant-folded (ret = v = 0 ->
 *   movs r6,#0, 440 B). Inline tries: range test plus DWC call as a static inline in cases 2 and 4 (void,
 *   int-returning, and early-return forms): 440 B, r5/r6 swap; switch and r test in a static inline
 *   `handle(a, b, r)` with case 4 `return v;`: the r test is not threaded (two `cmp r5,#0`), 440 B.
 *   Next: find a natural construct that puts the same non-constant copy on the r == 0 edge and after the
 *   case 4 call (identical blocks would merge), and check which cross-jump order it keeps.
 * 2026-10-05 (wD9r lane105): still 4 bytes (440 vs 436). Rescan with a fixed parser (scratchpad wD9r/l105/an.py,
 *   reads match.py listings): 674 far Thumb cond branches land on a `b`: 468 on an expansion b, 110 on a b after
 *   a b or pop, 88 on a b after an unrelated cond branch, 2 after a store or move, only 6 right after a call. The 5 matched ones are loop latches (backward, for
 *   example ov093 021EC8C4 `bls` onto the `b loop` after a call); ov121 021DC734 shows the other real cause,
 *   a suffix cross-jump that turns a join block into a lone `b` while the branch into it is kept. Ours is the
 *   only forward after-call case in the game. Tried: `do { if (r == 0) continue; ... } while (0)` (same 440,
 *   bne/b); r == 0 as the empty first arm of an if / else-if chain with the callback test (same 440);
 *   probe: a goto into case 4 followed by a duplicated `if (g[0x79E])` test with gotos to the same arms
 *   (beq does land on 02156022, but mwcc does not cross-jump blocks that end in a conditional, 448 B);
 *   probe: the same dead store in the r == 0 path and after the DWC call (removed early, threaded, 440).
 *   Open idea: an identical statement in the r == 0 path and after the DWC call that survives cross-jumping
 *   and then vanishes (coalesced copy); no natural source found. Draft code unchanged.
 * 2026-10-05 (wD9r lane83): still 4 bytes (440 vs 436). Callee prototypes from matched definitions:
 *   func_021C5B80 (ov114) returns int, DWC_GdbShutdown (ov175 021E1340) returns int, func_020111E8 returns
 *   u32; all three applied: same 440 B (kept the draft's void externs). Tried: `if (r == 0) goto tail;`
 *   with case 4 ending `goto tail;` (both edges to one label): same bne/b. Scan of asm/overlays: 483 far
 *   Thumb conditional branches land on a `b`; in matched code the reused `b` is always itself the kept
 *   `bcc body; b far` form of another far branch (ov186 021FFC9C: beq and bhi reuse the else-if's b at
 *   021FFD1A, not the earlier case-end b's; ov011 02172D70 0x2172DBE expands although a b is in range).
 *   Probe with cases 1 and 2 deleted: the beq still expands, no join `b` after a call is reused. So the
 *   original 02156022 b was not a plain join b at branch-fix time; source form still unknown.
 * 2026-10-05 (wD9r lane65): still 4 bytes (440 vs 436). Twin search: no matched function with this
 *   callee set (021552E8 and 02156690 call func_02059E38 but are different shapes). Tried: case 4 as
 *   `if (out of range) break; DWC_GdbShutdown(); break;` and as two nested ifs (both 440 B, same bne/b);
 *   a dead local store and `ret = ret` after the switch with case 4 last, as a probe for a non-empty
 *   join block (both 440 B, same bne/b, so an early-emptied block is not the cause); `if (r == 0) goto L;`
 *   with `L:` inside case 4's if-body followed by a written-out copy of the post-switch tail (probe):
 *   the beq then lands at the right place (after the DWC call) and the range fails go to the main tail as
 *   in the original, but mwcc does not cross-jump the multi-block tail copy (504 B with `return`, 464 B
 *   with `goto out`). Not a real source form; reverted to the draft code.
 * 2026-10-05 (wD9r lane52): still 4 bytes (440 vs 436). Tried: the callbacks and the switch in two
 *   separate `if (r != 0)` blocks, so the first block's r == 0 edge reaches a second test that the
 *   compiler could thread into a different block: 444 B, worse (case 4's DWC_GdbShutdown tail is
 *   duplicated and r4/r5 swap). Reverted to the draft code.
 * 2026-10-05 (wD9r lane25): still 4 bytes (440 vs 436). Tried: case 4 moved to the end of the switch with no break,
 *   so that its call falls into the switch exit, which is also the exit of `if (r != 0)` (one shared join block):
 *   same 440 B, the r == 0 edge still threads to end (bne/b).
 * 2026-10-05 (wD9r lane09): still 4 bytes (bne/b, 440 vs 436). Tried: the switch result in a second variable
 *   (`v = a; if (a == 0 || b == 1) v = r; switch ...; ret = v;` inside the r != 0 block) so that a copy sits
 *   at the join: coalesced, same bne/b. Confirmed mwcc does no island reuse in our build (three `b end` are in
 *   range of the r == 0 branch and none is used), so the original IR edge targets case 4's join block.
 * 2026-10-05 (wD9 lane08): still 4 bytes. Reading: in range of the beq there are three `b end`
 *   (02155FF0, 02156022, 02156028); only 02156022 (case 4 join) is a block that holds nothing but
 *   the goto, so the r == 0 edge reached that block in the IR (or a tail merge of identical
 *   [copy; goto end] blocks put it there). Our build has the same block at the same place and
 *   still emits bne/b. No new source form tested closes it.
 * 2026-10-05 (wave D7 lane 18): still 4 bytes. Reading: the original beq lands on the `b end`
 *   that is the fall-through of case 4's DWC_GdbShutdown call (the bgt/blt range fails go straight
 *   to end), so the r == 0 edge targeted the block after that call. Tried: `if (r == 0) goto skip;`
 *   with `skip:` inside case 4's if-body right after the call (threaded to end, same bne/b, 440 B).
 * 2026-10-05 (wave D6 lane 19): still 4 bytes (bne/b instead of beq onto case 4's `b end`).
 *   Tried: `if (r == 0) { } else { ... }` (empty then-arm, same bne/b). The r == 0 target is
 *   threaded to the tail before range fixing in every form so far.
 *
 * note (2026-10-04, wave D3 lane 13): complete draft, only residue is the first
 *   branch after func_02059E38: original is `beq 0x2156022` (a short branch to the
 *   `b end` that closes case 4), ours is `bne body; b end` (+4 bytes, 440 vs 436).
 *   Everything after matches instruction for instruction modulo that shift.
 *   Tried: `if (r == 0) goto tail;` plus a tail label (same output).
 *   Idea left: find what makes mwcc retarget a far beq to an existing b-trampoline.
 * note (2026-10-05, D4-11): still 4 bytes (beq onto case 4's `b end`). Tried: `goto skip`
 *   with the label inside case 4 before its break (threaded to end, same output); the
 *   post-switch tail written out in the r == 0 arm (504 bytes, no cross-jump); an
 *   `else { ret = 0; }` / `else { ret = r; }` arm (still bne/b, worse).
 * note (2026-10-05, D5-15): still 4 bytes. mwcc threads the branch to `end` without
 *   checking range, so the original beq target must have held code at threading time
 *   that a later pass removed (or a cross-jump merged a separate `b end` block into
 *   case 4's tail). Tried: `do { if (r == 0) break; ... } while (0)` and again
 *   `goto skip` with `skip: break;` after case 4's if (both bne/b, 440 bytes).
 *
 * 2026-10-05 (wD8 lane09): still 4 bytes. New reading of the jump table: [0]->end, 1->02155FD8, 2->02155FF2,
 *   3,6->0215602A, 4->02156012, 5->02156024, 7->02156092. The beq target 02156022 is the join block of case 4's
 *   range if (its range-fail edges go straight to end). Case 5's `b end` at 02156028 is also in range but is not
 *   used, so the r == 0 edge targets that join block in the IR and is not an island reuse. No new form found.
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155374  0x02155374  thumb  ov009
 *   func_02059E38  0x02059E38  arm
 *   func_02059F18  0x02059F18  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0205CC20  0x0205CC20  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_0216AD50  0x0216AD50  arm  ov009
 *   func_021C5B80  0x021C5B80  arm  ov114
 *   DWC_GdbShutdown  0x021E1340  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef int (*Cb)(u32, u32, u32, int);

extern u8 *g_021A8264;
extern void func_02155374(int v);
extern int func_02059E38(int *a, int *b);
extern void func_02059F18(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void func_0205CC20(void);
extern void func_020111E8(void);
extern void func_0216AD50(void);
extern void func_021C5B80(void);
extern void DWC_GdbShutdown(void);

u32 func_02155F58(void)
{
    int a, b;
    int r;
    u32 ret;
    u32 v = 0;
    Cb cb;

    r = func_02059E38(&a, &b);
    if (r == 0) goto L;
    cb = *(Cb *)(g_021A8264 + 0x294);
    if (cb != 0) {
        if (cb(*(u32 *)(g_021A8264 + 0x298), a, b, r) == 1)
            return v;
    }
    cb = *(Cb *)(g_021A8264 + 0x28C);
    if (cb != 0)
        cb(*(u32 *)(g_021A8264 + 0x290), a, b, r);
    v = a;
    if (a == 0 || b == 1)
        v = r;
    ret = v;
    switch (b) {
    case 1:
        func_02059F18();
        if (g_021A8264 != 0 && *(u32 *)(g_021A8264 + 0x754) == 0xE)
            func_02155374(6);
        break;
    case 2:
        if (a <= -40000 && a >= -41999)
            DWC_GdbShutdown();
        if (g_021A8264 != 0 && *(u32 *)(g_021A8264 + 0x754) == 0xE)
            func_02155374(6);
        break;
    case 4:
        if (a <= -40000 && a >= -41999) {
            DWC_GdbShutdown();
        L:
            ret = v;
        }
        break;
    case 5:
        func_021C5B80();
        break;
    case 3:
    case 6:
        if (g_021A8264 != 0) {
            switch (*(u32 *)(g_021A8264 + 0x754)) {
            case 3: case 6: case 7: case 8: case 9: case 10: case 11:
            case 14: case 18: case 19: case 20:
                if (g_021A8264[0x7A9] == 1) {
                    func_0216AD50();
                    g_021A8264[0x7A9] = 0;
                }
                /* fall through */
            case 0: case 1: case 2:
                func_0205CC20();
                break;
            default:
                break;
            }
        }
        if (g_021A8264 != 0)
            func_02155374(0x10);
        break;
    case 7:
        if (g_021A8264 != 0) {
            Cb f;
            func_02155374(0x11);
            f = *(Cb *)(g_021A8264 + 0x2A8);
            if (f != 0)
                ((void (*)(int))f)(-a);
        }
        break;
    default:
        break;
    }
    if (g_021A8264[0x79E] != 0) {
        ret = 0x3EE;
        func_0203C9AC(a, b, r, ret);
    } else if (*(u32 *)(g_021A8264 + 0x754) == 0x14) {
        ret = 0x3F0;
        func_0203C9AC(a, b, r, ret);
    } else if (r != 0) {
        func_0203C9AC(a, b, r, 0);
        func_020111E8();
    }
    return ret;
}
