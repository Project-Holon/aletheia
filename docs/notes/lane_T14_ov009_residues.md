# Lane T14 — ov009 open SDK rows 64-71 (DWC/libssl block)

Slice: `python scratch/a2/open_rows.py ov009 64 8` — the eight open ov009 SDK rows from
0x0217D904 upward.  gpiProcessSearch (0x0219091C) is **not** in this slice (it is a smaller
open row), so nothing here waits on that lane.

All eight were re-measured from their parked sources with

    python tools/match.py one --src src/pending/ov_sdk/ov009_func_<ADDR>.c --func <name> \
        --addr 0x<ADDR> --region ov009 --arm --cc 1.1p1 --lang c99 --diff

Two rows were **improved and re-written in place** (both were clean in `git status`):
021602B8 (size 1192 -> 1196 = image, 714 -> 628 concrete bytes, 245 -> 228 rows) and
02198A0C (88 -> 86 concrete bytes, 41 -> 39 rows).  The other six are parked with a named
residue; nothing else was touched.

| # | address | bytes | name | class | compiled | concrete B | rows | verdict |
|---|---|---|---|---|---|---|---|---|
| 64 | 0x0217D904 | 928 | gsiLargeIntDiv | structure +8 | 936 | 489 | 166 | parked |
| 65 | 0x02174FE8 | 1008 | DWCi_NNCompletedCallback | structure -8 | 1000 | 713 | 211 | parked |
| 66 | 0x02198A0C | 1128 | Think | size-exact | 1128 | 86 | 39 | improved, parked |
| 67 | 0x0217E078 | 1164 | gsLargeIntPowerMod | structure -72 | 1092 | 114 | parked |
| 68 | 0x021602B8 | 1196 | cert_item | structure (=) | **1196** | **628** | **228** | improved, parked |
| 69 | 0x0216C230 | 1368 | DWCi_GT2ClosedProcess | size-exact (allocator wall) | 1368 | 326 | 100 | capped |
| 70 | 0x02159A80 | 1384 | dt_ack | size-exact (allocator wall) | 1384 | 820 | 256 | capped |
| 71 | 0x0219C7C0 | 1532 | qr2_parse_queryA | structure -60 | 1472 | 366 | parked |

## Residues, one line each (image | ours at the first differing instruction)

* **0x0217D904 gsiLargeIntDiv** — +0008 `mov r5, r1` | `mov r8, r1` (params land r8/sb/r5/r6
  instead of r5/r4/r8/sb, so every following register and both branch displacements differ).
  Real blocker under it: stack-slot order.  The image has scopy at sp+0x10 (zeroed right after
  gsiLargeIntTimerEnter) and quotient at sp+0x210 (zeroed after the memcpy of src); this build
  cannot have both.  New evidence this pass: **later declaration = lower address**, and it holds
  when the aggregates are made siblings — flat `unsigned int scopy[128]; gsLargeInt_t quotient;`
  still put scopy at sp+0x114 and quotient at sp+0x10 (D1, 531 B), and hoisting quotient to the
  top of the same block only moved it to sp+0x20C (X1, 730 B, compiled 932).  The image needs the
  aggregate that is initialised *first* on the low slot, which the two initialiser positions
  forbid.  Untried lever: spell the *second* zeroing as a hand-written store loop instead of an
  initialiser, so the first-initialised aggregate can be declared last.
* **0x02174FE8 DWCi_NNCompletedCallback** — +0008 `mov r6, r0` | `mov r7, r0` (image keeps
  `result` in r6 and the shared zero in r7; ours swaps them, which cascades through all four
  zero stores at +0090..+00A4).  Compiles 1000 vs 1008; the missing two instructions are the
  status pick: image emits a 4-instruction branch form (`cmp r0,#0xe / bne / mov r0,#0xf / b /
  mov r0,#6`) where 1.1p1 emits two conditional moves.  63-config sweep on this source
  (`scratch/laneT14/sweep_02174FE8.json`, 9 dsi trees x 7 `-O` spellings, `--extra`): no
  configuration reaches 1008; every tree gives the same numbers, best 750 diffs at 884 B
  (`-O4,s`).  Body shapes tried (braces, `status = 6; if (...)`, ternary, ternary as the call
  argument, inverted condition, switch): none produce the branch form; the closest add 4 B
  (1004) and get worse elsewhere.  **Pin/flags axis: shut for this row.**
* **0x02198A0C Think** — +011C `mov r3, #0xa` | `mov sb, #0xa`, then the 3-cycle r1/r3/r2
  rotation (flags base / g_021AE4A7 / ptype) over +0134..+018C and the store/load order that
  follows at +01A8/+01F8/+0238.  Same size, 26/26 relocs.  Fixed this pass: `cookie` is
  **unsigned** (NN_NTOHL's `>>24` and the fused `(x>>8)&0xff<<8` are `lsr` in the image, `asr`
  here) — that is worth 2 bytes and is the correct field type.  Re-spellings measured this pass
  and rejected: source-buffer local (259 rows), local `NatifyFlags *` for the switch (739 rows),
  local for the compared porttype (bit-identical), `saddrlen` first (91 rows).
* **0x0217E078 gsLargeIntPowerMod** — +027C `sub r6, r1, #1` | `sub r1, r1, #1` (the first
  +027C bytes match).  What differs there: the image runs the divisorHighBit scan
  (`tst r0, #0x80000000` .. the 0x20-bit shift test) **before** the R zero-init loop and zeroes
  R twice (again just before `R.mLength = mod.mLength + 1`), while this build hoists the single
  R init above the scan.  Compiled 1092 vs 1164; the ~18-instruction second init plus the
  reordering is the 72 bytes.  Same class as 0x0217D904: an aggregate initialiser's position is
  not expressible without moving the aggregate's slot.
* **0x021602B8 cert_item** — +000C `ldr r4, [fp]` | `ldr r1, [fp]` (parameter mirror: image
  level=r7, seq=r6, mode=r8, *ps=r4, &s=r5; ours r8/r7/r6/r1/r4).  **Two fixes this pass**, both
  in the source of the object, not spellings: case 2's arms are laid out `mode == 2` before
  `mode == 0` (-49 B) and case 6's loop needs `char *obj = (char *)object[i];` because the image
  loads `object[i]` once for strlen+memcmp (-37 B, and it is what makes the size 1196).  714 ->
  628 concrete bytes.  Residue left: the parameter mirror and the branch *direction* it forces
  in the two case-2 arms (image `cmp mode,#0 / beq` into the copy block, ours `cmp mode,#2 /
  streq / streq / beq` to the exit) plus the case-6 jump-table body order at +0244.
* **0x0216C230 DWCi_GT2ClosedProcess** — +0080 `bne #0x216c3b0` | `bne #0x216c410`;
  same size 1368, 45/45 relocs, 326 concrete bytes.  Register rotation only: image keeps the
  shared zero in r6 and the match-control base in r5, this build has them in r2/r6, and the
  `cmp r0,#1` select at +01D0 is two predicated stores in the image and one branchless select
  here.  **Capped**: this row is in the eleven-row allocator-wall set already swept by lane S5
  (264 configurations across 24 compiler trees, `docs/notes/overlay_sdk_compiler_axis.md`);
  1.1p1 D326 is the best any configuration achieves.  Do not re-spell.
* **0x02159A80 dt_ack** — +00A8 `str r0, [sp]` | `mov fp, r0` (a spill the image does and this
  build does not; it then diverges at every branch displacement and the epilogue's
  `ldr r0, [sp]` at +053C).  Same size 1384, 34/34 relocs, 820 concrete bytes.  **Capped** by
  the same S5 sweep (best 1.1p1 D820; every alternative tree is larger *and* worse).
* **0x0219C7C0 qr2_parse_queryA** — +0000 `push {r4, r5, r6, r7, r8, sb, sl, fp, lr}` |
  `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}`; frame 0x18c vs 0x188 (image `add sp, sp,
  #0x400` after `#0x18c`).  The image has **one more 4-byte local**, stored before the first
  call (`str r1, [sp, #0x588]` at +002C, ours `str r4, [sp, #0x584]`), and it does not
  if-convert the `id == -1 / ptr == 0` preamble where this build does (`movs sb, r0` /
  `ldreq r0, [pc]` vs the image's plain `cmp`/`branch`).  1472 vs 1532, 44 relocs.  The parked
  body was not re-derived this pass; the residue to attack first is that missing slot.
