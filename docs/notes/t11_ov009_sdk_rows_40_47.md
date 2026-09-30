# Lane T11 — ov009 open SDK rows 40..47 (8 rows, 3,240 bytes, all parked)

Slice: `python scratch/a2/open_rows.py ov009 40 8`. Every row was already parked; none reached
EXACT. Nothing was filed. Verified per row with
`python tools/match.py one --src <path> --func <name> --addr <addr> --region ov009 --arm|--thumb
--cc <pin> --lang c99 [--diff]` against the pinned cc from the source header (the harness reports
the compiler as `dsi/<pin>`, so `--cc 1.1p1` is the dsi/1.1p1 front end).

## Verdicts

| # | address | bytes | sdk name | verdict | residue (first differing instruction) |
|---|---|---|---|---|---|
| 40 | 0x0217273C | 384/380 | DWCi_PostProcessSVConnectionFullmesh | DIFF, structure +4 | `+0000` image `push {r3, r4, r5, r6, r7, lr}` \| ours `push {r4, r5, r6, lr}` |
| 41 | 0x02180A64 | 408/408 | gsUdpReceivedRoutingCB | DIFF, size-exact, 8 B | `+0064` image `add r4, sp, #0x30` \| ours `add r3, sp, #0x30` |
| 42 | 0x0219C3A4 | 432/432 | qr_process_client_message | **MATCH**, 0 concrete B | all 399 concrete bytes equal; `+0198` ABS32 `@13818` wildcarded |
| 43 | 0x02180C94 | 436/436 | gsUdpConnAttemptCB | DIFF, size-exact, 8 B | `+0050` image `ldr r3, [sp, #0x94]` \| ours `ldr r4, [sp, #0x94]` |
| 44 | 0x021612C8 | 436/440 | create_key_block | DIFF, structure −4 | `+0014` image `beq #0x21612fc` \| ours `beq #0x21612f8` |
| 45 | 0x0217DE94 | 484/484 | gsLargeIntSquareMod | DIFF, size-exact, 19 B | `+0014` image `mov r0, #7` \| ours `str r6, [sp, #0x14]` |
| 46 | 0x02189780 | 520/524 | gpiRecvToBuffer | DIFF, structure −4 | `+0078` image `ldr r1, [pc, #0x174]` \| ours `ldr r1, [pc, #0x170]` |
| 47 | 0x021573C4 | 536/536 | CPS_Startup | DIFF, size-exact, 188 B | `+0008` image `mov r4, r0` \| ours `mov r5, r0` |

## What was run

* **Pin sweep** (rule 4) on all eight rows: `1.1 1.1p1 1.2 1.2p1 1.2p2 1.3 1.3p1 1.6sp1 1.6sp2`
  crossed with each row's own pin (full table in `scratch/a2/t11/pinsweep.txt`). No pin reaches
  EXACT, and 1.6sp1/1.6sp2 are strictly *worse* on four rows: 0x02180A64 8→16 B, 0x0219C3A4
  MATCH/0→12 B, 0x021612C8 318→320 B, 0x0217DE94 19→23 B. The other four are byte-identical at every
  pin. The pin lever is exhausted for this slice; the residue is body-shaped, not versioned.
* **Idiom search**: `docs/idioms/` (426 files) grepped for the allocator/colouring class —
  `a-no-code-self-assignment-reorders-the-register-colouring`,
  `declaration-position-orders-block-scope-colouring`,
  `a-store-moved-below-the-table-loads-recolours-its-operands`,
  `an-element-pointer-reuses-the-dying-base-register-an-indexed-base-does-not`,
  `a-vec-copy-as-three-field-moves-with-swapped-registers-is-an-inline-setter`,
  `block-locals-declared-without-initialisers-colour-differently` — and each lever applied.
* **Permuter** (`tools/permuter.py`, anneal): 0x0217273C 500 compiles → best 185 B out (worse than
  the 177 B baseline); 0x02180A64 1,500 compiles → plateau at the 8 B baseline (asm=40);
  0x02180C94 1,500 compiles → plateau at the 8 B baseline (asm=40); 0x0217DE94 (second run) plateau
  at 19 B. Outputs kept in `scratch/a2/t11/perm/`.

## Row-by-row residue

**40 — 0x0217273C, 380 B, structure +4.** One root cause, `result`'s zero. The image materialises
`mov r4, #0` at `+0008` and keeps it live to the end (used by `strb r4, [r0, #0x620]` at `+00CC`,
`strb r4, [r0, #0x6d9]` at `+016C` and both `movne r0, r4` error returns); this form constant-folds
`result` to immediates and hands r4 to the `tmpNewNodeInfo = f()->newNodeInfo` block copy, so the
copy colours dest r4/src r6 here against dest r6/src r7 in the image, the destination address is
hoisted above the `bl` at `+000C`, and the whole 177 concrete bytes rotate. Not a spelling problem:
the source order of `result = 0`, `pNew = &tmpNewNodeInfo` and `pNew`'s declaration (tested bare and
with an initialiser, before/after the copy, self-assignment of `result`) is inert, as is the
`linkProgress = result` / `flag = result` spelling with a literal. The 500-compile anneal's best was
185 B out, i.e. it moved away from the image. Capped on the allocator's constant-hoisting decision.

**41 — 0x02180A64, 408 B, size-exact, 8 B.** The 16-byte `aHandler.mHeader = *(GSUdpHdr *)theMessage;`
copy loop. Image: `add r4, sp, #0x30` (dest) / `mov r3, sb` (src). Ours: `add r3, sp, #0x30` /
`mov r4, sb`. Same instruction sequence, mirror register pair. Tried: the three manual levers (single
temp reuse, declaration order by first use — worse at 11 B, `aHandlerFound` first — 8 B, and moving
the copy / the `aUdp = func_02180404()` assign / the `func_0217D254` log across the calls they
precede — 312–339 B out), plus `theMessage = theMessage;` / `theMessageLen = theMessageLen;` /
`theConnection = theConnection;` self-assignments, `*(GSUdpHdr *)&aHandler.mHeader`, and moving the
copy above the log. A 1,500-compile anneal plateaued at the 8 B baseline with stall=44. The matched
sibling 0x021810CC does the identical source line with dest r3/src r8, so the colouring is
context-dependent and this row is capped.

**42 — 0x0219C3A4, 432 B, MATCH.** Zero concrete bytes differ; 8 of 9 relocation sites resolve. The
single wildcard is `+0198` ABS32 against the vendor object's six-byte initialiser template
`FD FC 1E 66 6A B2` at 0x021A1B64. **Parked: template ambiguity** — those six bytes also sit at
0x021A5A7C, the head of the named global `NNMagicData`, and the `template` class refuses on both
prongs (uniqueness fails with hits `021A1B64`/`021A5A7C`; elimination finds no claim). No named data
symbol exists at 0x021A1B64: `asm/overlays/ov009.s` carries `.word 0x661EFCFD /* 021A1B64 */` with
no `d_`/`g_`/`tbl_`/`pool_` label (switching on the local to the `memcpy` form against an extern
0x021A1B64 would trade the strong refused class for `sole-ref/self` and diffs 75 concrete bytes).
Full analysis in `docs/notes/qr2_0219C3A4_vendor_template_twin.c.txt`.

**43 — 0x02180C94, 436 B, size-exact, 8 B.** Same copy residue as row 41 at
`*(GSUdpHdr *)aHandler.mInitialMsg = *(GSUdpHdr *)message;`: image
`+0050 ldr r3,[sp,#0x94]` / `+0054 add r4, sp, #0x3c` vs ours `ldr r4` / `add r3`. Manual levers all
negative: first-use declaration order 18 B, `aCallbacks` before `anAddr` 15 B, `aHandler` first 8 B,
moving the copy across the `func_02184234`/`func_021843E8` calls 58 B / 148 B, moving
`aUdp = func_02180404()` past the log call 56 B. Self-assignments and the cast forms inert. Anneal
plateaued at the 8 B baseline (stall=44).

**44 — 0x021612C8, 436 B against 440, structure −4.** Two independent residues.
(i) Branch layout: the `con->f32` size table. Image puts `beq` to the `==4` block first and
*predicates* the `==5` arm (`moveq/streq` ×5, then `b` over the `==4` block); this form emits the
`==5` arm unpredicated behind a `bne` and a shared tail, which is where the 4 bytes go.
(ii) Colouring: image `len`=sb / `p`=fp, ours `p`=sb / `len`=fp, which then rotates the whole loop
(318 concrete bytes). Tried: `if==4 / else if==5` inversion (321 B, worse), `p`/`len` declaration
permutations in every slot (`len` before `p`, after the sizes, first, `p` after the sizes), and
`p`/`len` assignment order. None moved either residue. Capped on the predication decision plus the
sb/fp pair.

**45 — 0x0217DE94, 484 B, size-exact, 19 B.** Six instructions of prologue schedule: the image emits
`mov r0,#7` / `str r1,[sp,#0xc]` / `str r2,[sp,#0x10]` / `mov r5,r6` / `mov r7,r6` / `str r6,[sp,#0x14]`;
this form puts the `squareLen = 0` store three slots early, at `+0014`. Everything from the
`func_0217D3AC` call on is identical. Pin sweep inert, and the note records 24 statement orders of
carry/oldShiftBit/squareLen/len, decl-init vs statement, `squareLen = (u32)carry`, `result = 0`,
volatile, `len` declared after `squareLen`, and 1.2/1.2p1/1.2p2 already measured. New this pass:
(a) `squareLen` declared **inside** the arrays' block — the residue drops to 15 B, but the store then
lands one slot *late* (after the `bl`) and the `mov r6,#0`/`mov r8,r0` pair swaps; (b)
`len * 0`, `(u32)carry`, `0u` initialisers, `squareLen = 0` as a statement before/after the `len`
load, and a redundant re-init — all 19 B or worse. **Parked at 19 B (size exact)**; the anneal's best
was also 19 B.

**46 — 0x02189780, 520 B against 524, structure −4, pin dsi/1.1p1.** One call site: the GSIDebug
raw-dump `func_0217D254(1, 0, 0x20, g_021A458C, g_021ADFC8.recvCount++, id, buf)` at `+0078`. The
image loads the format into r3 first and spills count+id with one `stm`; this front end schedules the
`recvCount++` load/increment/store first and rematerialises the format pointer in r3, which is the
short-by-4 body and shifts everything after it (147 bytes of the count are that shift, not 147
independent errors). Called out in
`docs/idioms/a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md`: scalar,
array and struct-member counters, a named `count = counter++` local, `register int`, an `int *`
pointer to the counter, an unprototyped callee and a `void`/`int` return were all measured, every one
reproducing the compact order. Additionally **capped at MATCH by evidence**: `g_021A4568` (`+01F8`)
and `g_021A458C` (`+0200`) are unresolved — "has no witness outside 02189780..02189988" — so the row
cannot reach EXACT even with the call site fixed. The main loop, grow path, error/closed branches and
the RECVTOTL dump line up.

**47 — 0x021573C4, 536 B, size-exact, 188 B.** One register cascade. The image hoists the u64 add-high
zero into r6 *before* the `OS_GetTick` branch (`+0028 mov r6, #0`, then used by
`str r6, [r5, #0x8c]` at `+0054` for `rand.add`'s high word); this form CSEs the zero late into r4, so
`config` colours r5 here against r4 in the image and the whole body shifts by one register
(188 concrete bytes, every instruction otherwise identical). Tried: a `u64 seed` local with
`if (seed == 0) seed = OS_GetTick();`, explicit `rand.x/mul/add` field stores instead of
`MATH_InitRand32`, `x`/`mul`/`add` store order inside the helper, a `MATHRandContext32 *` local, and
hoisting the `mul`/`add` stores above the caller's `if`. All 188 B or worse (`add_before_mul` 199,
`x_last` 190, `rand_local_ptr` 248). Capped on the constant-hoisting decision.

## Files

* `scratch/a2/t11/` — copies of the eight parked sources, variant JSONs, `vary.py` (edit-and-measure
  driver), `gen/` (compiled variants + full harness output), `perm/` (permuter best sources).
* No parked source, no shard and no other lane's file was modified: the slice produced no EXACT, so
  there was nothing to file.
