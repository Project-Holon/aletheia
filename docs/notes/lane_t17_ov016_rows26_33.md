# Lane T17: ov016 open SDK rows 26..33

Slice: `python scratch/a2/open_rows.py ov016 26 8`. Eight parked libdwcutil.TWL.HYB.a rows,
656..996 bytes each. All eight were read whole, compiled under their own header pin, ISA and lang,
and their first divergence located before anything else was judged. No row reached EXACT; one row's
body was materially improved and filed.

`0x021C84BC initGraphics` is row **21**, not in this slice: it was read from
`docs/notes/overlay_sdk_residues.md` line 70 (508/508, size-exact, first divergence `+0144
ldr r2,[r5,#8]` | `ldr r1,[r5,#8]`) and left untouched.

## Residues, all eight rows

| # | address | function | compiled/extent | concrete bytes | first divergence | class | pin |
|---|---|---|---|---|---|---|---|
| 26 | 0x021BE844 | disp | 652/656 | 465 | `+0004 sub sp,sp,#0x18` | `sub sp,sp,#0x20` | structure -4 | 1.1p1 |
| 27 | 0x021B9BF8 | ScanAP | **652/660** | 355 | `+000A ldr r0,[pc,#0x26c]` | `ldr r0,[pc,#0x264]` | structure -8 | ../2.0/sp1p2 |
| 28 | 0x021C73D0 | input | 748/704 | 601 | `+000C ldr r7,[pc,#0x2a0]` | `ldr r7,[pc,#0x2cc]` | structure +44 | 1.1p1 |
| 29 | 0x021D1208 | DWCi_WINlInitEx | 784/796 | 567 | `+0000 push {r4..fp,lr}` | `push {r3,r4..fp,lr}` | structure -12 | 1.1p1 |
| 30 | 0x021D2450 | ParentStateCallback | 792/796 | 245 | `+0000 push {r4..r8,lr}` | `push {r3..r7,lr}` | structure -4 | 1.1p1 |
| 31 | 0x021C7D80 | drawMessage | 828/824 | 479 | `+001C ldr r0,[pc,#0x2e8]` | `ldr r0,[pc,#0x2ec]` | structure +4 | 1.1p1 |
| 32 | 0x021BD8D8 | DWCi_KBlInit | 876/844 | 519 | `+0000 push {r3..fp,lr}` | `push {r4..fp,lr}` | structure +32 | 1.1p1 |
| 33 | 0x021BA804 | AutoConfigThreadEx | 952/996 | 801 | `+0000 push {r4..r7,lr}` | `push {r3..r7,lr}` | structure -44 | ../2.0/sp1p2 |

All eight were DIFF before and after this lane; none is size-exact, so brief rule 4's "pin or flags
before re-spelling" does not apply to any of them, and the pin/flag lever is already measured shut
project-wide (`docs/notes/overlay_sdk_residues_named.md` section "The pin and flag lever, measured
shut": nine dsi front ends crossed with the flag matrix, 4284 configurations, no EXACT and no new
MATCH). Re-checked directly here: `disp` compiles to an identical 652 bytes under dsi/1.1, 1.1p1,
1.2, 1.2p1, 1.2p2, 1.3, 1.3p1 and 1.6sp1, and `drawMessage`'s four front-end outputs (1.1p1, 1.2,
1.3, 1.6sp1) are byte-identical below the harness's own compiler line.

## Provenance cap on four rows

`keyboard.o` (26, 32), `sceneseteditaddr.o` (28) and `dwc_mov_mbp.o` (30) all carry `.comment`
Metrowerks C/C++ for ARM **4.0.0.1025**, which no bundled build writes (1.1p1 is 1024, 1.2 is 1026);
the project already established that 1.1/1.2/1.2p1/1.3 are mutually byte-identical on such bodies
(`docs/notes/lane_s6_ov009_dwc_structures.md` line 83). Those four are capped by the front end, not
by source shape, and every residue they show is exactly the class that front end decides: a callee
saved-register rotation taken one register lower, and a prologue frame size.

Rows 27 and 33 are pinned to `../2.0/sp1p2` (atermset.o is stamped 3.0.0.126) and row 31 to 1.1p1;
those are the three rows where source shape is still a live lever.

## Row 27 ScanAP: body improved and filed, 616/660 -> 652/660

`src/pending/ov_sdk/ov016_func_021B9BF8.c` now carries the lattice from
`docs/notes/pkt_ov016_021BA804.c.txt` (20-entry event switch with cases 0..19, BssListSize as one
expression, `retv = -1` first, `i = 0` after `wmbssdesc = ap_list`, the 6-byte MAC struct copy).
Measured: **652 of 660 bytes, 192 diff lines, 355 concrete bytes, frame `sub sp,#0x70` exact, every
switch slot exact and all 29 relocation sites resolved**; the previous parked body was 616/660, 268
lines, 494 concrete, frame `sub sp,#0x68` and 27 of 29 sites resolved (`atermset_bss`,
`atermset_data` were not on the symbols line; they are now, at 0x021DCFD0 and 0x021DAB58, which is
what raises the honest concrete count to 355).

Residue, two parts, probably one cause:
1. loop tail, the missing 8 bytes: the image increments `retry` through its stack slot and re-reads it
   for the bound test (`ldr r0,[sp,#0x1c]; adds; str; ldr r0,[sp,#0x1c]; cmp r0,#0x1e`), this front end
   keeps `retry` in a register. The same 8 bytes move the two `break` branches that in the image chain
   onto the canceled-check.
2. the found block's copy into `gAPMac`: the image computes `pBssid+0x28` twice, byte 0 through one
   register and bytes 1..5 through a copy held in another with `[r0,#k]`; every spelling tried
   (struct copy, six statements, inline helper, `__builtin_memcpy`) misses, and `#pragma
   opt_unroll_loops` over the `n` loop unrolls it and kills `n` again, which takes (1) with it.

## Row 26 disp: one lever moved the byte, grid negative

Two scripted grids, `scratch/t17/r26_grid.py` and `r26_grid2.py` (5 + 5 cells, results in
`scratch/t17/r26_grid.txt` and `r26_grid2.txt`).

- Only lever that moved anything: **reversing the order of the three 5-byte initialiser copies**
  (N_BTN, N_SKEY, N_KEY instead of N_KEY, N_SKEY, N_BTN). Concrete 465 -> **382**, size 652 -> 644,
  first divergence moves from the frame to `+0000`'s pushed register set.
- Compensations around that lever, all flat at 644/382: declaration order of the three arrays
  (three permutations), `ix = line * 12;` before the copies, after the copies.
- Inert: the three copies written as fifteen explicit byte assignments (652/465), `ix` before the
  copies (652/465).
- Worse: copies N_KEY..N_BTN with `ix` after the loop guard (632/526).

Not filed: the lever improves the concrete count but moves the size away from the image (-12 instead
of -4), so it is not a promotion and it would change the row's recorded class.

## Row 31 drawMessage: pair grid negative, one inert lever

Two scripted grids, `scratch/t17/r31_grid.py` and `r31_grid2.py` (22 + 30 cells, results in
`scratch/t17/r31_grid.txt` and `r31_grid2.txt`).

Residue: the compared `ErrorCode` value lands in `r0` where the image keeps it in `r1`, and `prm` is
reloaded from `sp+0x18` at `+019C` where the image reuses the `r0` it loaded at `+0100`; the extra
reload is the whole +4 byte size gap. Tail argument evaluation is mirrored too (the image computes
`C_CODE[lang].x` from its first `DWCi_Language()` call and `.y` from its second, ours the reverse).

Cells: err type `int`/`long` x prm type `int`/`long`/`unsigned int`/`short`/`unsigned short` x
comparison direction (`K <= err` / `err >= K`) x `?:` vs if/else, plus a second `prm` local, plus the
`prm - 2000` test moved next to the other two `prm` tests. **52 cells.**
- Inert: every type and every comparison direction (all 828/479).
- Only lever that moved the byte: the two `id = (prm == 2) ? a : b;` statements rewritten as if/else,
  479 -> **465** at unchanged size 828; it reproduces the image's `cmp; moveq; movne` slot order at
  `+0104`/`+0130` and nothing else. Compensations around it (err/prm type x direction, `prm` local,
  test moved): all 465, no cell better.
- Worse: a second `prm` local (820/667); moving the `prm - 2000` test (812/434).
- The first divergence at `+001C` did not move in any of the 52 cells.

Not filed: 465 of 479 is a different tie, not the missing source line, and the register decision is
immovable from the C.

## Untouched, residue restated for the next lane

- **28 input (748/704, +44)**: the image lays the jump table and the `default` block out so the
  `p <= 0` arm is the fallthrough (`bgt Lswitch; popeq {..pc}; b Ldefault`) and carries a dead
  `pop {r3,r4,r5,r6,r7,pc}` at 0x021C7418 that 1.1p1 never emits; ours inverts the two arms
  (`ble Ldefn` with the switch as fallthrough). Provenance-capped at 4.0.0.1025.
- **29 DWCi_WINlInitEx (784/796, -12)**: 567 concrete; the allocator keeps `dark` in `fp` where the
  image spills it to `[sp+0x10]`, and ours defers the `DWCiMsgCmn` pool word to `r5` where the image
  hoists it to `r4`. 1.6sp1/1.6sp2 shave 2 concrete (565) at unchanged size and are not the build
  compiler. Provenance-capped at 4.0.0.1025.
- **30 ParentStateCallback (792/796, -4)**: 245 concrete, the lowest in the slice. Every instruction
  body matches; the image allocates `child_aid` to `r8` and the case-2 temp to `r6`
  (`push {r4,r5,r6,r7,r8,lr}`), ours one register lower (`push {r3,r4,r5,r6,r7,lr}`), and MSG case 0xD
  lowers to a range tree in the image (`cmp #8/bgt, ==2, ==1, ==9`) but a linear chain under 1.1p1.
  Also the `+0x1b144` / `+0x1b140` pair is associated `(g+0x1b000)+0x144` in the image and
  `(g+0x144)+0x1b000` here. Provenance-capped at 4.0.0.1025.
- **32 DWCi_KBlInit (876/844, +32)**: 519 concrete. From the button loop on, the image holds 0 in
  `sb` for the skey loop's lcd argument and reuses `sb` as the button counter, holds 2 (color) in `fp`
  and materialises `0x480` per call; 1.1p1 spills a zero to `sp+0x10` and hoists `0x480`, costing a
  `0x24` frame for the image's `0x20`. Permuter seed 9804 budget 400 flat. Provenance-capped at
  4.0.0.1025.
- **33 AutoConfigThreadEx (952/996, -44)**: 801 concrete. The residual is the `g_021DD224`
  zero-fill: the image emits the MWCC large-aggregate idiom (2x-unrolled `stm` of zeroed registers
  with the counter in `ip`), a plain `for` zero loop and `memset()` both come out ~40 bytes short, and
  a compound-literal `(WS11G_PROFILE_DATA){0}` spills a 596-byte stack temporary (frame 0x280 vs the
  image's 0x2c). Seven data globals still need an outside witness.

## Verdicts

Nothing promoted. Row 27's body was replaced with a strictly closer one (652/660 and 187 lines
against 616/660 and 268). Rows 26, 28, 29, 30, 31, 32, 33 keep their parked bodies unchanged, with
the two scripted grids above recording that their residues are not reachable from C by any cell of
the covered dimensions.
