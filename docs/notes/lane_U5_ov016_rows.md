# Lane U5 — ov016 open SDK rows 0-12

Slice: `python scratch/a2/open_rows.py ov016 0 13`, skipping 0x021B97A8 (index 4) and
0x021D0DE0 (index 2). All 13 rows are `libdwcutil.TWL.HYB.a` members. The two atermset.o
rows are stamp 3.0.0.126 (pin `--cc ../2.0/sp1p2`); the other nine are 4.0.0.1025 (TwlDWC,
no build of ours writes that stamp, so they stay on `dsi/1.1p1` — the sibling 0x021D36B0 in
dwc_mov_wh.o is EXACT on 1.1p1, confirming the default is right for these objects).

## Filed EXACT (2)

- **0x021CC0E8 `button`, 288 bytes, arm, dsi/1.1p1** —
  `src/matched/ov_sdk/ov016_func_021CC0E8.c`, shard `layout/matched/ov016/pkt_ov016_021CC0E8.json`.
  The park's 2-instruction residue at +00B8..+00C0 (image
  `add ip,r5,#1 / ldrsb r3,[r1,r3] / mov r2,r4`, parked `mov r2,r4 / ldrsb r3,[r1,r3] /
  add ip,r5,#1`) closes by qualifying the *table*: `extern const s8 g_021DA724[7]` (was
  plain `s8[]`). The const table lets the front end order the fifth argument's `idx + 1`
  above the table load. Body unchanged.
- **0x021BC820 `DWCi_ANIMElInitEx`, 204 bytes, arm, dsi/1.1p1** —
  `src/matched/ov_sdk/ov016_func_021BC820.c`, shard `layout/matched/ov016/pkt_ov016_021BC820.json`.
  73-byte residue, size-exact: image `push {r4,r5,r6,lr}` with `pal = g_021D9FF8[color]` read
  into lr at +0040, parked `push {r3,r4,r5,r6,r7,lr}` with the pal load sunk past the w0
  store. Closes with `extern const u8 g_021D9FF8[]` — the const table hoists the indexed load
  above the obj stores, freeing the seventh register and re-colouring the whole body.
  Body unchanged.

## The lever (worth propagating to other lanes)

Both closures are the same move: **a global that the image reads through an index is declared
`const` at its extern**, which lets the front end hoist the indexed load (or its scaled index)
above intervening stores. Verify the *body* is already byte-exact/size-exact and the residue is
one to four instructions in the wrong order or one register out — that is the tell. Two
negative results bound it: `const` on a pointer member (`MEMSTEP *const`, `Wh *const`) and on a
whole struct global (`const STEP_BSS step_bss`) do *not* hoist field/pointer loads, and a const
*pointer to* the leaf (`M * const g_021DE654`) lets the compiler cache the value and blows the
function up (188 B vs 220). Only the indexed-table read responds.

Cross-check with the same wave: lane U6 closed 0x021CBDF8 in this same region with the identical
lever (`extern const struct tagCOORD g_021DA72C[6]`), and that address is inside *my* slice
(open_rows index 10) — indices shift as rows close, so U6's 13-25 and my 0-13 overlapped.
0x021CBDF8 is filed at `src/matched/ov_sdk/ov016_func_021CBDF8.c`; I did not duplicate it.

## Residues parked (9), one line each (image | ours)

- **0x021D3638 DWCi_MOV_WH_Initialize, 120 B, arm — 2 instr (5 B).**
  `moveq r0, r5 / movne r0, r4` | `movne r5, r4 / mov r0, r5` at +0068/+006C. Whole body and
  the r5=0/r4=1 constant colouring byte-exact; only the destination of the final boolean
  select differs. 30+ spellings over four waves and this lane (`int r = 0; if (c) r = 1;`,
  `? 1 : 0`, `!= 0`, `!!`, both if/else senses, if/return without else, 2-arm if/else,
  `local = c ? 1 : 0`, `return r`, inline ternary, unsigned/char return, a `z = 0` named
  local, c99 mid-block declaration). Every shape with the right constant colouring funnels
  into the coalesced tail; every shape that avoids it flips the constants. `wh *const` and a
  `../2.0/sp1p2` probe change nothing (the latter is 17 diffs worse). `moveq r0, rN` +
  `movne r0, rM` occurs exactly once in the whole `asm/` tree — this function — so there is no
  sibling shape to copy.
- **0x021D06A4 taskEnd0, 144 B, arm — 4-instr window (12 B).**
  `ldr r0,[r4,#4] / str r2,[sp,#4] / ldr r0,[r0,#0x10] / sub r1,r2,#0x99` |
  `str r2,[sp,#4] / ldr r0,[r4,#4] / sub r1,r2,#0x99 / ldr r0,[r0,#0x10]` at +0060..+006C
  (else arm only; the `x > 152` arm and everything else is byte-exact — same four
  instructions, permuted). Tried this lane: `void *cell = MemStep->cell[4];` before/after the
  `x = 152` store and used as the first argument, `x = 152` inside the argument list, the
  literal 152 in the call with the store after it, `MEMSTEP *const MemStep`, `void *const
  cell[5]`, `const STEP_BSS step_bss` (the last is 136 B, much worse). Nothing moves it.
- **0x021D04BC taskBegin4, 156 B, arm — same window (12 B).**
  `ldr r0,[r4,#4] / str r2,[sp,#4] / ldr r0,[r0,#0x10] / sub r1,r2,#0xb1` |
  `str r2,[sp,#4] / ldr r0,[r4,#4] / sub r1,r2,#0xb1 / ldr r0,[r0,#0x10]` at +0068..+0074.
  Identical shape with 0xb1 (x = 176).
- **0x021D15F0 taskMove, 192 B, arm — 8 B size + if-conversion (130 B).**
  image `cmp r0,#5 / bne / ldr r1,[pc,A] / b / ldr r1,[pc,B]` (a real branch, 8 bytes more) |
  ours if-converts the function-pointer select (184 B). T6's eight spellings re-fold; not
  re-attempted.
- **0x021B9FE0 SetFrameData, 194 B, thumb, ../2.0/sp1p2 — 176 B differ, 186 vs 196.**
  image `sub sp,#8` frame spilling `id` to [sp,#4] and reloading lpkey from [sp,#0x20], the
  eight ELEMENTHEADER byte stores interleaved with the FullLength SWAP16 chains | ours needs
  no frame (`1e 1c` | `82 b0` at +0002) and computes both SWAP16 chains after the lpkey/copy
  branch. Structural gap; the parked source is a near-rewrite.
- **0x021D0CEC DWCi_USBAPlEnd, 220 B, arm — 2 B.**
  `ldr r1,[r0,#0xb90] / cmp r1,#0` | `ldr r0,[r0,#0xb90] / cmp r0,#0` at +0094/+0098. The
  load coalesces into its dying base register. T6's 28 spellings plus later batches all land
  on the same pair; `M * const g_021DE654` is 188 B (much worse). Documented as unreachable
  from C at this base lifetime in
  docs/idioms/a-guard-load-that-folds-into-its-dying-base-register-is-not-a-source-shape.md.
- **0x021BC63C ATERMi_ApConfigStart, 232 B, thumb, ../2.0/sp1p2 — 195 B differ, 236 vs 232.**
  image `bl func_021B97A8` is a 4-byte THM_CALL at +0032 | ours is two bytes there
  (`fd f7 / 9b f8`) and the whole body shifts; 11 relocations, one extra store. Near-rewrite.
- **0x021D657C readKey, 272 B, arm — 169 B differ, 280 vs 272.**
  Eight bytes too long from the first loop on (`b0 20 d0 e1` | `b0 30 d0 e1` at +000C, then a
  rotating register wall); the tail differs by a whole 8-byte block. Needs re-decompilation,
  not a lever.
- **0x021CBDF8 initObj, 264 B, arm — closed by lane U6** (see above), not duplicated.

## Class residue for docs/notes/overlay_sdk_residues.md

Five of the parked rows (0x021D06A4, 0x021D04BC, 0x021D3638, plus the two now-closed
0x021CBDF8 and 0x021CC0E8) were all the same shape: size-exact code whose only difference is a
2-4 instruction window holding exactly the image's instructions in a different order, or one
register out. Three of the five yielded to a `const` qualifier on the indexed global; the two
that did not (0x021D06A4/0x021D04BC — the hoist is of a *pointer member*, not an indexed
table) survived every const spelling tried. Treat "size-exact, all windows byte-equal except a
permutation of 2-4 adjacent instructions" as a residue class whose first move is the const
qualifier on whichever global the window reads.

## Budget

~100 min (85 budgeted; the overrun bought both EXACTs). Compiles: ~140, all through
`tools/match.py one --diff` on copies in `scratch/U5/`. Write set touched:
`src/matched/ov_sdk/ov016_func_021CC0E8.c`, `src/matched/ov_sdk/ov016_func_021BC820.c`,
`layout/matched/ov016/pkt_ov016_021CC0E8.json`, `layout/matched/ov016/pkt_ov016_021BC820.json`,
this note, `scratch/U5/`. No parked file was edited.
