/*
 * function: func_0220E340
 * address:  0x0220E340
 * packet:   pkt_ov198_0220E340
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD9r laneS1): still DIFF 9 bytes (arc r6 / arr r7), no code change; the half-edited state left by a
 *   stopped lane held only notes (code identical to HEAD, same 9 B verdict). Allocator model read from the mwcc
 *   source (src/backend/Coloring.c, SpillCode.c): interference nodes are pushed on a stack when degree < colours, in
 *   vreg index order; when none is left the node with the lowest spill_cost / degree goes next; colours are then
 *   picked in pop order (last pushed first), lowest free colour. spill_cost = sum over operands of block weight
 *   (x2 for one operand flag, x1 for the other), counted per vreg BEFORE coalescing, on the final PCode. Here p and i
 *   have the highest scores (coloured first, r5/r4); arc and arr compete for r6/r7 and the HIGHER score is coloured
 *   first and gets r6. Ours: arc (1 loop use at loop weight + 3 post-loop uses) outscores arr (1 loop use). The
 *   original needs score(arr) > score(arc): arc has degree >= arr (arr's neighbours are a subset), so the only source
 *   levers are one more arr operand at loop weight (a real instruction use, or a copy that survives to PCode) or
 *   about two fewer arc operands (probes of lanes 102/115 agree: two fewer arc uses flip it). Every spelling tried by
 *   lanes 29..209 either folds the extra arr use away at IR level (copies, helpers, temps) or changes code. No source
 *   without a stand-in (a surviving self-copy or a reassigned alias of arc) was found, so nothing is filed.
 * 2026-10-05 (wD9r lane209): still DIFF 9 bytes (arc r6 / arr r7), no code change. Instruction-by-instruction count of
 *   every value, original listing against our compiled output: arc 1 def + 4 uses (A6C8, ACEC, AF28, close) in both;
 *   arr 1 def + 1 use (loop store) in both; p (r5) 8 reads in both; i (r4) mul, lsl, add, cmp in both; BC78 result 1 def
 *   + 1 use in both (r6 in the original, r7 in ours, i.e. always arr's register); heap reload (ldr [r5]; ldrh #0x10) 4
 *   times in both; r4 pool offset 0x250C then +0x18 in both. No count differs, so the source has no extra or missing
 *   operation. Post-loop order is identical: BC3C, ACEC(arc, r, 1, 0, heap) -> [p+0x250C]; BC78, BCEC, AF28(arc, a, b,
 *   heap) -> [p+0x2524]; close(arc); argument sources match instruction for instruction. Also 9 B: `int *__restrict arr`.
 * 2026-10-05 (wD9r lane204): still DIFF 9 bytes (arc r6 / arr r7), no code change. Compiler and flags: neighbours
 *   0220E2B4, 0220E2F8, 0220E3F0, 0220E460, 0220E684 all declare dsi/1.1p1 -O4,p (the 20 plain `1.1p1` headers are in
 *   0220BB94..0220D218 and 0220F138+, the same compiler dir). The draft compiled with every dsi dir (1.1, 1.1p1, 1.2,
 *   1.2p1, 1.2p2, 1.3, 1.3p1, 1.6sp1, 1.6sp2): 9 B at -O4,p in all of them, 25 B at -O4,s in all of them (identical
 *   codegen across versions). Open call type: matched sub_020490F4 is `void *(u32 id, u16 heap)`, the draft already
 *   matches. Handle typed as `struct AF *` on the open return and all four callee first parameters, and as `int` on
 *   all five: both 9 B, swap unchanged (pointer type does not colour).
 * 2026-10-05 (wD9r lane202): still DIFF 9 bytes (arc r6 / arr r7), no code change. Re-mapped the listing: arr (r6) has
 *   exactly one use, the loop store `str r0,[r6,r1]`; it is dead after the loop (r6 is reused for the BC78 result at
 *   0x3C4), and both post-loop stores go through r5 plus a pool offset in r4 (0x250C, then +0x18), never through r6.
 *   So no post-loop store can be written as arr[N] without changing code: tested arr[26] and arr[32] (172 B, as lane29).
 *   Idioms read in full: a-hoisted-array-base-is-a-named-local-in-a-guarded-do-while (its guard-gate form fixes the
 *   add position, not a colour tie; no gate here, the image has no pre-test), a-counter-initialized-before-a-byte-bound,
 *   a-call-between-a-buffer-handle-and-its-first-read, a-dead-parameter-reused-as-the-index, a-named-per-element-pointer,
 *   array-bases-as-pointer-locals-reopen-a-flat-declaration-order, two-long-lived-values-in-each-others-registers,
 *   a-loop-invariant-buffer-read-through-the-field. None gives a new form beyond the ones lanes 29..191 already tried.
 * 2026-10-05 (wD9r lane191): still DIFF 9 bytes (arc r6 / arr r7), no code change. Studied ov173 021B7128: its r6 temp is
 *   the field address p+0x1B8 (non-immediate offset, shared constant register reused for the hoisted sum), read by a load in
 *   the loop test; the handle is a named local in r7 with one loop use. Wrote this loop as a pure temp (no named arr):
 *   `*(int *)((u32)(p + 0x24A4) + i * 4)`, `*(int *)((u32)p + 0x24A4 + i * 4)`, `*(u32 *)` variant: LICM hoists the sum
 *   as in ov173, 176 B, same 9 B swap (so temp-ness does not change the order). Pointer-typed inline forms
 *   (`((int *)(p + 0x24A4))[i]`, `*((int *)(p + 0x24A4) + i)`, `(u8 *)` base) and `i * 4 + (u32)p + 0x24A4`,
 *   `(u32)p + (0x24A4 + i*4)`: 180 B (reassociated, 0x4C hoisted). Array address in the loop test
 *   (`(u32)p + 0x24A4 + i*4 < ... + 24`, and `i*4 + 0x24A4 < 0x24A4 + 24`): 196 B. `i = 0;` before the open call
 *   (ov173 order): 27 B. arr declaration removed or reordered with the temp form: 9 B.
 * 2026-10-05 (wD9r lane186): still DIFF 9 bytes (arc r6 / arr r7), no code change. Twin search over all overlay listings
 *   (u16 counter loop with `str r0,[rM,rI]`, `lsls r1,rI,#2`, handle plus `adds r6,rP,rK` after an open call): no matched
 *   function has an indexed-store array base in r6 with the handle in r7 across such a loop. Nearest: ov173 021B7128
 *   (handle r7 from func_02045B38, `adds r6,r5,r6` = p+0x1B8 hoisted by LICM, i r4; the r6 value is a compiler temp,
 *   used once in the loop test, not a named local), ov197 0220C0B4 (arc spilled, per-iteration address), ov097 021F6F88
 *   (base spilled). Reading: temps colour before named locals (a-loop-invariant-buffer-read-through-the-field-colours-
 *   below-the-named-locals.md), so the image arr is probably a LICM temp. Tried to make p+0x24A4 an explicit hoistable
 *   node with a real Ctx (Rec rec[6] at 0, int a[26] at 0x24A4): `p->a[i]`, `*(p->a + i)`, `*(int *)((u8 *)p->a + i*4)`,
 *   `*(&p->a[0] + i)`: all 180 B (143 differ), the store address is folded to reg+reg+pool and 0x4C is hoisted into r7
 *   instead. Also 9 B: null-pointer counter step `i = (u16)((char *)0 + i + 1)` (a-counter-stepped-through-a-null-pointer),
 *   `u32 i` stepped with `i = (u16)(i + 1)`.
 * 2026-10-05 (wD9r lane180): still DIFF 9 bytes (arc r6 / arr r7), no code change. Idiom-driven tests, all 9 B, swap
 *   unchanged: the `long` colouring lever of docs/idioms/a-long-index-colours-apart-from-an-int.md on arr (`long *`),
 *   on arc (`long` and `unsigned long` handle with matching callee prototypes), on arr and arc together, plus x as
 *   `long`; `unsigned long i` (172 B, worse); arc as `u8 *`; arr as `u32 *` and `s32 *`. The signedness lever of
 *   a-byte-locals-signedness-flips-its-callee-saved-colour.md has no local to flip (i is u16, forced by the
 *   lsls/lsrs 16 truncation). The distinct-local lever of a-second-same-typed-local-changes-callee-saved-allocation.md
 *   matches the lane139 h/arc copies (coalesced). Named element pointer, struct-array and per-use-count idioms were
 *   already covered by lanes 29/36/102/167.
 * 2026-10-05 (wD9r lane178): still DIFF 9 bytes (arc r6 / arr r7), no code change. Tried the mixed-spelling lever of
 *   docs/idioms/a-second-spelling-of-an-item-address-in-the-if-body-makes-the-base-a-late-temp.md: the loop has one
 *   use of the array address, so there is no second spelling to mix; the raw `p + 0x24A4 + i * 4` store with arr
 *   dead is the 180 B form (143 differ). Also 9 B: `*(int *)((u8 *)arr + i * 4)` store; arc passed through a block
 *   local in the close call. No matched ov198 sibling mixes spellings here, so nothing is filed.
 * 2026-10-05 (wD9r lane175): still DIFF 9 bytes (arc r6 / arr r7), no code change. Transplanted every source
 *   difference of the matched siblings 0220E3F0/0220E460 (same open/close pair): their prototypes (func_0204A6C8
 *   as int(void *, unsigned x3, u16), func_02049238(void *)), char *p, the handle named owner and declared first
 *   (owner, i, arr, x), the heap read and both post-loop stores through struct fields (Hdr f10 at 0x10, Ctx
 *   f250C/f2524), and arr as &Ctx->f24A4. Each singly and all 24 combinations: all 9 B, swap unchanged. Callee
 *   prototypes agree with their matched definitions (sub_020490F4 u32,u16; sub_0201BA68 u32(void *);
 *   sub_0201BABC u32 x4; func_0201BC3C int(void); func_0204ACEC; sub_0204A6C8; sub_0204AF28; func_02049238), no
 *   narrow parameter or return type to adopt. The siblings have no loop and no second long-lived pointer, so they
 *   carry no information about the arc/arr colour order.
 * 2026-10-05 (wD9r lane169): still DIFF 9 bytes (arc r6 / arr r7), no code change. Fresh re-derivation from the
 *   listing: open(7, heap|0x8000) -> r7; r6 = p + 0x24A4; u16 i loop 0..5 (rotated, no top test, blo); record
 *   p + i*0x4C (+8 u16 test, +4 mon); x = BA68(185F4(mon)) or BABC(0,0,0,0); arr[i] = A6C8(arc, x, 0, 1, heap);
 *   then [p+0x250C] = ACEC(arc, BC3C(), 1, 0, heap); [p+0x2524] = AF28(arc, BC78(), BCEC(), heap) (0x2524 derived
 *   by mwcc from the held 0x250C); close(arc). No early return, no extra call result, no reload, no other bound:
 *   the draft logic is exact. Siblings 0220E3F0/0220E460 (same open/close pair, matched) keep the handle in r7 too;
 *   0220E460 uses the raw p + i*4 + 0x24A4 form (constant base in r6), which here gives 180 B, so this function
 *   really holds a pointer local. New loop kinds tried (both 9 B, swap unchanged): a goto loop
 *   (`i = 0; loop: ...; if (++i < 6) goto loop;`) and `for (;;) { ...; ++i; if (i >= 6) break; }`. So the colour
 *   is not set by the loop statement kind (mwcc finds the natural loop from the CFG either way).
 * 2026-10-05 (wD9r lane167): still DIFF 9 bytes (arc r6 / arr r7), no code change. New forms, all 9 B unless noted:
 *   a pointer local q = &arr[i] set after the x if/else (`*q = A6C8(...)`); `*Slot(arr, i) = ...` through a static
 *   inline returning &a[k]; arr as a one-int struct array (`arr[i].v`); arc and arr as fields of one local struct;
 *   a per-iteration static inline One(p, arc, arr, i) (u16 and int i, and arr-first parameter order); arr[(u16)i];
 *   arc in a one-element array local. Worse: the record pointer derived from arr (`(u8 *)arr - 0x24A4 + i*0x4C`,
 *   and `arr - 0x929`, 188 B: not folded back to p); the loop test against an end pointer `&arr[i] != arr + 6`
 *   (200 B). Inlined helper parameters and pointer copies coalesce before colouring, so none adds arr weight.
 * 2026-10-05 (wD9r lane150): still DIFF 9 bytes (arc r6 / arr r7), no code change. Rechecked: the caller
 *   0220E2B4 passes only p; no callee reads an extra register (BC3C/BC78/BCEC read no argument, 020185F4 is
 *   `bx lr`, AF28 has no stack argument); every prototype matches the matched callers. Tried (all 9 B): BA68 and
 *   BABC returning u16 with a u16 x; x as int; x reused for the A6C8 result; a u16 heap local for the open call;
 *   char *p; Ctx/Hdr/Rec structs (P->hdr->heap, P->rec[i].f4/.mon, 0220BEB8 shape); one u32 local for arr and
 *   the BC78 result (and x for BCEC; webs are split); the A6C8 call and store in each arm (rechecked). Worse:
 *   `&arr[i] < &arr[6]` loop test (not folded, 188 B). Probes: six extra calls after the loop, or six extra
 *   if-blocks after the loop, do not move arc, so the order follows weighted use counts only, not live span.
 * 2026-10-05 (wD9r lane139): still DIFF 9 bytes (arc r6 / arr r7), no code change. Listing check: all four arc
 *   uses (A6C8 in the loop, ACEC, AF28, the close) take r0 from r7, the open result; no load or getter call feeds
 *   them, and the matched callees (func_0204ACEC, sub_0204AF28, sub_020490F4, sub_0204A6C8) take the handle in r0.
 *   So a "second value equal to arc" can only be a coalesced copy. Tried (all 9 B, swap unchanged): `h = arc = open`
 *   with h in the post-loop calls; `arc = h = open` with h in the loop; h = arc before the loop for the loop use; h =
 *   arc after the loop for ACEC and AF28 only; arc in a one-field struct local and in a one-element array local (both
 *   promoted to a register). Copies merge into one node. Also: the store address computed at the loop top
 *   (`int *q = (int *)(p + 0x24A4) + i`, 173 B, arc goes to r7 but the hoisted base spills), arr assigned at the loop
 *   top with function-scope arr (9 B), `((int *)p)[i + 0x929]` both operand orders and a block temp r with q or the
 *   inline address after the call (143 B, 0x4C hoisted). Probe: two more uses of the BC78 result do not move arc, so
 *   arc is coloured before BC78; only arr can take r6 first in the image.
 * 2026-10-05 (wD9r lane115): still DIFF 9 bytes (arc r6 / arr r7), no code change. Static inline helpers taking arc
 *   are fully transparent here (all 9 B): the loop plus both post-loop stores in one Fill(p, arc) with open and close
 *   outside; void SetA(p, arc)/SetB(p, arc); value-returning GetA/GetB(arc, u16 heap), GetA/GetB(p, arc) and
 *   GetL(arc, x, u16 heap) for the loop call; Load(p, u32 a) plus Finish(p, u32 a) with u32 arc (both, and Finish
 *   only); Icon/Sub with int parameters (24 B). Also 9 B: arr declared inside the loop (LICM hoists it, 0x4C stays
 *   unhoisted, either order with e); explicit arr copies in the loop (q = arr; q[i]); the ov097 IconBase(int obj)
 *   accessor returning u32 (three spellings). Arr(p)[i] used directly hoists 0x4C instead (143 B). Probes: removing
 *   any two of the three post-loop arc uses gives the image colours, any one does not; then two extra arc uses
 *   before the loop undo it (pre and post uses weigh the same). One to three extra arr call uses, or one to four
 *   arr[k] stores, before the loop do not move arc. Self-assignments of arc or arr (probe only) and extra calls
 *   before arr or after the loop do not move it. So the image needs about two fewer arc uses or a real extra arr
 *   use in the loop; no source form found that gives either without code.
 * 2026-10-05 (wD9r lane102): still DIFF 9 bytes (arc r6 / arr r7), no code change. Logic rechecked block by block
 *   against the listing: no wrong helper, reload, field or operand order. New probes: passing 0 for arc in ACEC
 *   AND AF28 flips arc to r7 (either one alone, or the close call alone, does not), so arc outranks arr by two
 *   post-loop uses' worth. Tried (all 9 B unless noted): the ov209 021BD9B4 twin shape (struct with a[26]/b[6]/c[6],
 *   arr = p->a, pb = &p->b[0], pc = &p->c[0] before the loop: 192 B, pb/pc offsets spilled); one pointer
 *   q = p + 0x250C with q[0]/q[6] (56 B); `i = 0;` before the arr assignment; `void *const arc` and `int *const arr`
 *   C99 initialised; a u16 n = 6 loop bound; block-scoped int a/b temps for the AF28 arguments (ov097 twin shape);
 *   the ov097 double definition `arr = (int *)p; arr = p + 0x24A4` (dead store dropped, 9 B; a stand-in anyway).
 * 2026-10-05 (wD9r lane75): still DIFF 9 bytes (arc r6 / arr r7). No twin: ov097 021F6F88, ov209 021BD9B4 and
 *   ov021 021CC8DC run the same open/icon-loop/close sequence but at different pressure (spills, hoisted 0x6b/0x71).
 *   Tried (all 9 B, swap unchanged): p, arr and arc as u32 integers (ov097 shape); x as u16 with u16 callees; a
 *   second parameter holding arc or arr (numbering probe: no effect, so not a tie on vreg order); copies of arc
 *   (h = arc before or after the loop); the A6C8 call in each arm with one `arr[i] = r` after the join (the ov041
 *   idiom shape); x selection alone in a static inline (if/return and if-set forms); i or x reused as the 0x250C
 *   offset (`i = 0x250C; ... i += 0x18`); a u16 heap local and x/y locals for the post-loop calls. `off = 0x24A4`
 *   with `p + off + i*4` (three spellings) folds to the 180 B raw form. Probes: dropping only the final close call
 *   or the ACEC arc use does not move arc. The weight gap needs a real extra arr use in the loop; none found.
 * 2026-10-05 (wD9r lane36): still DIFF 9 bytes (arc r6 / arr r7 swap), no code change. Tried: `do { } while (++i < 6)`
 *   and `while (i < 6) { ...; i++; }` (9 B); a Ctx struct with `Rec recs[6]` at +4 and `int a[26]` at 0x24A4 used
 *   inline (180 B: mwcc never hoists p + 0x24A4 itself, only the 0x4C constant, so arr must be a named pointer);
 *   `arr = (int *)p; arr += 0x929;` (180 B); call and store in each if/else arm with x kept (9 B); a function-scope
 *   record pointer e in each of the 5 declaration slots, and a loop-scoped `for (u16 i = 0; ...)` (all 9 B).
 *   The ov041 021F3884 close (stores repeated in each arm raise a block value's rank) has no analogue here: no
 *   store follows the x if/else except arr[i], and that adds equal uses to arc and arr.
 * 2026-10-05 (wD9r lane29): still DIFF 9 bytes (arc r6 / arr r7). New probes: the colour follows a use-count
 *   priority. arc not used in the loop, or arr given one more use in the loop, or four more uses of arr before the
 *   loop, or all three post-loop arc uses removed: each gives arc r7 / arr r6 as in the image. One to three extra arr
 *   uses do not. (The wD7 probe that one removed post-loop line moves arc does not reproduce on this draft.) So the
 *   image source has arr weighted at least as high as arc. Tried with no change (9 B): the record pointer inline
 *   (`p + i * 0x4C + 8/+4`, a CSE temp), arr from a static inline accessor Arr(p), the store in a static inline
 *   Store(arr, i, v), x as a separate temp stored after the call, i declared first, `for (i = 0, arr = ...)` with
 *   arr[i]. Worse: post-loop stores as arr[26]/arr[32] (172 B, 39), arr assigned inside the loop (143), dead
 *   stores to arr[i] (stand-ins anyway). No real source found that adds an arr use without code.
 * 2026-10-05 (wD9r lane05): still DIFF 9 bytes (arc r6 / arr r7 swap). Tried: the open call in a static inline
 *   OpenArc(p, 7); the three post-loop lines in a static inline Finish(p, arc); arr as a u32 integer
 *   (`arr = (u32)p + 0x24A4`, and `arr = 0x24A4; arr = (u32)(p + arr)`, the reuse form that closed ov197 0220BA2C);
 *   the loop's x local reused for the BC78 result (all 9 B); i reused for it (51 B). Probe: an extra arr use after
 *   the loop does not move arc, so arc's colour is not set by arr's use count.
 * 2026-10-05 (wD9 lane06): still DIFF 9 bytes (same arc/arr r6/r7 swap). Tried: the loop body as a per-iteration
 *   static inline `arr[i] = LoadOne(p, arc, i)` (record pointer, x selection and the A6C8 call inside), and arr as a
 *   pointer to an `int[6]` array with C99 initialised declarations (arc first). Both 9 bytes, swap unchanged.
 * 2026-10-05 (wD8 lane05): still DIFF 9 bytes (arc r6 / arr r7, image arc r7 / arr r6). Tried: x declared in the loop
 *   block, the if/else arms swapped (`== 0` first, 32 B), raw `*(int *)(p + 0x24A4 + i * 4)` with a real Rec struct
 *   array for the records (180 B: LICM then hoists 0x4C into r7, not p + 0x24A4). Reading: arc gets r7 when its
 *   interference degree drops (see wD7 probe), so the image likely has one fewer value live across the post-loop calls.
 * note 2026-10-05 (wD5 lane18): tried arr only at the use site (`((int *)(p+0x24A4))[i]`, 180 B, 143 differ), arr assigned inside the loop, and `for (i = 0, arr = ...)` with `*arr++` (176 B, 75 differ). The r6/r7 swap of arc and arr stays only in the 9-byte form.
 * 2026-10-05 (wD4 lane16): also tried arr = (int *)p + 0x929, int loop counter (much worse), arc/arr/x declaration orders, and a temp for the call result before arr[i]: all 9 bytes, r6/r7 swap unchanged.
 * 2026-10-05 (wD6 lane07): still 9 bytes (arc/arr r6/r7 swap). Tried: the 0204A6C8 call and arr[i] store written in
 *   each if/else arm (rule 2 of the register-order idiom), a real Rec struct array for the p + i*0x4C records (closed
 *   0220D884), and a Ctx struct with int arr[6] at 0x24A4 (180 bytes, worse). No callee reads a missing argument.
 * 2026-10-05 (wD7 lane13): still 9 bytes (arc r6 / arr r7, the original has arc r7 / arr r6). Probes: with the
 *   final func_02049238(arc) removed, or either post-loop line removed, arc goes to r7 as in the original, so
 *   arc's later uses push it to the lower register; the BC78 hold (j3) does not matter. No real source moved it:
 *   the x selection and the A6C8 call in a static inline, a Heap(p) inline accessor, the loop in a static inline
 *   (p, arc) and (p, arc, arr) (arr param 180 B), the ACEC/AF28 lines in a static inline, arr in an inner block,
 *   x as a ternary or nested in the call, temps for the BC78/BCEC/BC3C results, an off = 0x250C local (+0x18 or
 *   off += 0x18), a Ctx struct with a[26]/b[6]/c[6] at 0x24A4/0x250C/0x2524 (the arrays that siblings 0220E2F8
 *   and 0220E684 use) with arr = p->a, arc as u32, arr as u32 *, int *const / register arr, one u32 local reused
 *   for arr and the BC78 result, arr assigned before the open call (35 B). Raw `p + i * 4 + 0x24A4` (sibling form)
 *   gives 180 B with 0x4C hoisted into r7 instead.
 * symbols:
 *   func_0220E340  0x0220E340  thumb  ov198
 *   func_020490F4  0x020490F4  arm
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 */
/*
 * 2026-10-04 (wave D2 lane03): DIFF, unchanged (9 bytes, pure r6/r7 swap of arc and arr). Also tried:
 * arr as a u8 * base with `*(int *)(arr + i*4)`, and `register void *arc`: still 9 bytes.
 * In the original the BC78 result is held in r6 (arr's register) across the BCEC call, same as mine in r7.
 */
/*
 * 2026-10-04 (wave D1 lane07): DIFF, same size (176), logic matches. Residue: r6/r7 swapped
 * everywhere: the original has arc in r7 and the p+0x24A4 array base in r6, mine the reverse.
 * Tried: declaration order arc/arr, arr computed before the arc call (hoists everything, worse),
 * no arr local with raw *(int *)(p + 0x24A4 + i * 4) (worse).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);

void func_0220E340(u8 *p)
{
    int *arr;
    void *arc;
    u16 i;
    u32 x;

    arc = func_020490F4(7, (*(u16 *)(*(u8 **)p + 0x10) & 0x7FFF) | 0x8000);
    arr = (int *)(p + 0x24A4);
    for (i = 0; i < 6; i++) {
        u8 *e = p + i * 0x4C;
        if (*(u16 *)(e + 8) != 0) {
            x = func_0201BA68(func_020185F4(*(void **)(e + 4)));
        } else {
            x = func_0201BABC(0, 0, 0, 0);
        }
        arr[i] = func_0204A6C8(arc, x, 0, 1, *(u16 *)(*(u8 **)p + 0x10));
    }
    *(int *)(p + 0x250C) = func_0204ACEC(arc, func_0201BC3C(), 1, 0, *(u16 *)(*(u8 **)p + 0x10));
    *(s32 *)(p + 0x2524) = func_0204AF28(arc, func_0201BC78(), func_0201BCEC(), *(u16 *)(*(u8 **)p + 0x10));
    func_02049238(arc);
}
