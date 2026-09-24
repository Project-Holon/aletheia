# Wave 21, research lane: levers for 0x02067080 and 0x0202E1F0

This lane did research only. Neither target was compiled or edited. I read every notes section
for both targets (`docs/notes/pkt_02066E30.c.txt`, wave 12 through lane C4;
`docs/notes/pkt_0202E1F0.c.txt`, from the start through lane E6). I also read the wave 21
C/C2/C3/C4 and E/E2..E6 reports, all 217 idiom titles and about 40 idiom bodies, the headers
of about 60 matched sources, and the reports of the other wave 21 lanes (A, B, D2-D4, F, G, H).

Two listing scans were scripted:
- mla/mul followed by a load, over the ARM listings of every matched `../2.0/sp2` and `1.1p1`
  source;
- a stack-buffer address held in r4-r7 and passed as `adds rN, rX, #0`, over every matched
  Thumb source.

I made 11 scratch compiles, all under `/tmp/aletheia_research/p`. They are reduced skeletons
that test the precedents' mechanisms, not the targets. No other decompilation or
reconstruction was consulted.

## New facts from the scratch probes (these save compiles)

Target 2 (1.1p1 Thumb, `p1.c`, `p3.c`, `p5.c`, `p7.c`, `p8.c`):

- **`ws` spelled directly cannot be the image's spelling.**
  - With `ws` written at every site, 1.1p1 hoists `&ws` into a callee-saved register
    (`add r7, sp, #k`). That register covers only B0's extended basic block and the next loop.
  - At the first call after the loop, the address is rematerialised as `add r0, sp, #k`. That
    is exactly the +0x8E residue shape.
  - If the second loop also uses `ws`, a second `add r7, sp, #k` is emitted before the
    post-loop call (`p6`). The image has one `add r7, sp, #0x38` and nothing else. So the
    image's r7 is one variable web, which confirms the reused-parameter lever.
  - `ws` only in loop 2, with `w` everywhere else (`r_l2ws`): the loop-2 use is rematerialised
    inside the loop, and the entry value leaves w's register.
- **Lane D4's null-pointer re-rank does not transfer to `w`.**
  - `w = (unsigned long)((char *)0 + (unsigned long)ws);` is codeless, but it folds `w` into
    the hoisted constant. The entry value splits off into r1, the same fold E3 item 4 describes.
  - `func_02024368((void *)((char *)0 + w), ...)` is folded before costing: the output is
    identical to the version without it.

Target 1 (`../2.0/sp2` ARM, `a1.c`, `a2.c`, a reduced adjust inline):

- The two-statement negation idiom (`d = h << 12; d = 0 - d;`) is byte-identical to
  `d = -(h << 12)`. It is canonicalised, so it will not move anything.
- `(fx32)((char *)0 + ...)` on dx, dy or the y sum is NOT codeless under 2.0/sp2. It emits
  `add rX, rX, #0` (+8 bytes). Skip that class for 0x02067080.

## Precedents that are close but do not apply

- **Load after an mla that frees ip and a callee-saved register.** No matched `../2.0/sp2`
  function has this pattern. The 1.1p1 cases (0x0203BA98 at 0x0203BB1C, 0x0204C3CC at
  0x0204C58C) do put the load in the freed callee-saved register. In both, though, ip is
  claimed by a web created later (`adds ip, lr, r7`; `lsr ip, r6, #12`). The image of
  0x02067080 has no later ip web, so these are not analogues.
- **Held stack-buffer addresses in Thumb.** 0x0201A59C, 0x0200EE64 and 0x0200AA68 keep a buffer
  address across branches only as the loop-hoisted constant described above.

## 0x02067080 (g2d DoAffineTransforme_, ../2.0/sp2), ranked

1. **Variable identity: reuse `effectTypeAfter` for the effect read.**
   - Precedents: `src/matched/func_0206AB18.c` (sp2, closed by variable identity after hill and
     anneal were flat), `docs/idioms/reusing-a-loop-variable-across-phases-changes-the-allocation.md`,
     and lane D3 lead 3 ("webs are per variable": a merge reallocates the whole callee-saved set
     with no code change).
   - Why it applies: the effect web (r4, live across +0x21C) is the long web that C4 says is
     coloured ahead of list order.
   - Not tried: merging it with the overwrite arm's variable. Lanes tried a separate const
     GXOamEffect local, int typing and declaration order.
   - Spelling: `effectTypeAfter = G2_GetOBJEffect(pOam); { const BOOL bShouldAdjust = effectTypeAfter == GX_OAM_EFFECT_AFFINE_DOUBLE; NNSi_G2dAdjust...(..., bShouldAdjust); }`.
     Also try the variant with the assignment inside the initialiser:
     `const BOOL b = (effectTypeAfter = G2_GetOBJEffect(pOam)) == ...;`.
2. **A one-line nested inline for the y read or the final add only.**
   - Precedent: `src/matched/func_0206EC50.c` (sp2): two nested inline helpers renumber values;
     the same statements written flat could not be moved.
   - Lane C's per-axis helpers wrapped the `halfW << 12` term, which broke the CSE (74-87). A
     helper that does not touch the shift was never measured.
   - Spelling: `static inline fx32 GetY_(const NNSG2dFVec2 *p) { return p->y; }` with
     `pV->y = GetY_(pV) + (dy + pM->_11 * halfH);`.
   - Also try `static inline void AddY_(NNSG2dFVec2 *p, fx32 d) { p->y += d; }` with
     `AddY_(pV, dy + pM->_11 * halfH);`, on both the base and item 1.
3. **Split compound statements whose intermediate stores the front end drops.**
   - Precedent: `src/matched/func_0206775C.c` (same cluster, sp2). Its flip write-back as four
     compound statements closed 61 -> EXACT with no extra stores.
   - Spelling: `pV->y += dy; pV->y += pM->_11 * halfH;`, and the same split for x
     (`pV->x += dx; pV->x += pM->_10 * halfH;`), one at a time.
   - Risk: the sum may re-associate to `add` then `mla`. Discard it if the size or instruction
     count moves.
4. **Read the coordinate into its own local inside the inline, then add.**
   - Precedent: also `func_0206775C.c`, lever 2 (65 -> 61, `add r0, x, w` rather than
     `add r0, w, x`).
   - Item 1 hoisted y into a function-level local. Not tried: the image's own operand order
     spelled with a fresh block-scope local declared after dy, read after the dy mla and before
     the _11 load. Operand orders were measured, but not in combination with this position.
   - Spelling: `{ fx32 y = pV->y; pV->y = y + (dy + pM->_11 * halfH); }` with the block opened
     immediately after `dy += pM->_01 * halfW;`.
   - Low confidence: C4 rule 4 predicts it re-creates at the use.
5. **Narrow signed halfW / halfH (lane D3 bands).**
   - Precedent: `docs/notes/pkt_02048330.c.txt`, lanes D3/D4. A sign-extended narrow web
     (short, signed char) is ranked above int, while u8, u16 and long webs fall to the bottom band.
   - Spelling: `const short halfW = NNS_G2dGetOamSizeX(&oamShape) >> 1;`, then the same for
     halfH, then both.
   - Keep only if it adds no `lsl #16` / `asr #16`. The u16 table value >> 1 may be range-known;
     if the extension appears, stop. Lanes tried long only.

Skip, measured here: the two-statement negation (identical output) and null-pointer arithmetic
(not codeless under sp2).

## 0x0202E1F0 (blink_palanm, dsi/1.1p1 Thumb), ranked

1. **Put `w`'s def inside the first B0 call's argument list.**
   - Precedent: `src/matched/func_0202F870.c` (1.1p1 Thumb, the pms family) and
     `docs/idioms/an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md`.
     1.1p1 evaluates arguments right to left, and an assignment inside an argument list is
     created at that point.
   - The lanes moved the def to four statement positions but never into an argument list.
   - Spelling: `func_0202465C((void *)(w = (unsigned long)ws), 1, c3);`.
   - Variant: `h = func_0202441C((void *)w, cnt = c3);`, measured on both base and s21.
2. **Callee arity: `n = (u8)func_0201D478(h);`.**
   - At +0x48, r0 still holds h (`str r0, [sp, #0x24]; bl func_0201D478`).
   - Precedents: `src/matched/func_02014C08.c`, `src/matched/func_0201104C.c`, and lane G's
     0x0209D7D4. In each, an arity fix was the whole lever for a "tie" that 3,800 permuter
     compiles could not move.
   - It adds a codeless live range (h across the call) that survives to costing.
   - Also check every other bare call for leftover arguments, for example `func_02041B6C` at
     +0x17E, where r0 holds `func_02045730`'s result.
   - Lane E7's scratch rewrite already declares `func_0201D478(void *)`, so coordinate with it.
3. **`const` on read-only pointers and prototypes.**
   - Precedents: `docs/idioms/const-on-a-read-only-source-parameter-settles-a-register-tie.md`
     (0x0204D18C, 0x0204D224, 0x0204BE84, all 1.1p1) and
     `const-on-a-descriptor-parameter-orders-the-argument-loads.md` (0x020163C4, 0x02016630).
   - Both describe permuter-flat same-size ties closed by `const` alone. The permuter never adds
     it to prototypes.
   - Spelling: `const struct Cs *cs`, and `const void *` as the first parameter of
     `func_020244F8`, `func_020244D4`, `func_02024368` and `func_0202441C`. Measure them singly,
     then all together, on s21 (the g call passing `w`).
4. **The stack parameters as one by-value struct, with `w` its first member.**
   - The notes' own early fact: the `ldr r0,[sp,#0x64]; str r0,[sp,#0x64]` renormalising pairs
     "appear only with the by-value spelling".
   - `docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md` (1.1p1): mwcc does not
     constant-fold through an aggregate member. A member reassigned to `ws` may keep the web
     without folding the copy at +0x8E.
   - Spelling: `struct Args { unsigned long w; struct Cs *cs; u16 c1; u32 c2; u16 c3; }`, passed
     by value at sp+0x60, with `args.w = (unsigned long)ws;` and `args.w` at every later site.
   - This is structural and higher cost, but no lane has tried it.
5. **Variable identity of the registered webs (lane D3 lead 3, `func_0206AB18`).**
   - E3 tried a separate loop-2 counter. Not tried: merging webs that already share registers
     with lifetime-disjoint roles. The loop-1 counter and g are both r4; the loop-1 constant 1
     and the loop-2 counter are both r5.
   - Spelling: run loop 1 on `g` cast as its counter (the null-based step
     `g = (void *)((char *)g + 1)`, compare `(s32)g < n`) before `g = func_02024368(...)`.
   - Low confidence: the o/w order has so far moved only with o's or w's own cost.

Skip, measured here: the null-pointer re-rank on `w`'s def or the g argument (it folds, or is
inert), `ws` in loop 2 only, and `ws` everywhere (it rematerialises at the post-loop call).

## Files

- This report is the only file written in the repo.
- Scratch: `/tmp/aletheia_research/` (`probe.py`; `p/*.c` and `*.out`; `mla_scan.py`,
  `mla2.py` and `buf_scan.py` with their outputs).
