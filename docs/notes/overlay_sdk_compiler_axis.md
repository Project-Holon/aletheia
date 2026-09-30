# The compiler axis on the eleven allocator-wall rows (lane S5)

Scope: the eleven `size-exact: allocation or scheduling` rows of `scratch/a2/sdk_residues.json`
with `concrete > 100` — ov009 0x021573C4 / 0x02159A80 / 0x0216C230 / 0x0216C8DC / 0x0216CA04 /
0x0217E504 / 0x0219A52C / 0x0219D5C4, ov107 0x021F3830, ov114 0x021BC740, ov172 0x021C3DF4.

Method: `tools/match.py sweep` per row, `--arm --lang c99 --extra`, once over the nine `dsi/` trees
(99 configs, already done by the previous pass — `scratch/s5/sweep_*.json`) and once over the fifteen
non-default trees `1.2/{base,sp2,sp2p3,sp3,sp4}` and `2.0/{base,sp1,sp1p2,sp1p5,sp1p6,sp1p7,sp2,sp2p2,sp2p3,sp2p4}`
(165 configs — `scratch/s5/sweep2_*.json`). 264 configurations per row, 2904 compiles. Every tree is a
distinct `mwccarm.exe` (md5-checked). Extra flags outside the harness's eleven (`-gccext,on`,
`-inline deferred`, `-ipa file`, `-nofail`) are byte-identical to `-O4,p`; `-opt on` only degrades
(`scratch/s5/extraflags.sh`). `-ipa function` is rejected outright by the whole 1.2 family (5 CCERR per row).

## The matrix, restricted to configurations that hit the target size

Concrete diffs are only comparable at the target size; `2.0` numbers at other sizes are sizes, not scores.

| row | target | default (dsi 1.x) | best size-exact alternative | best of any size |
|---|---|---|---|---|
| ov009 0x021573C4 | 536 | **1.1p1 D188** | none (1.2 +56..+58, 2.0 +44..+64) | 2.0/sp2p2 D449 @580 |
| ov009 0x02159A80 | 1384 | **1.1p1 D820** | none (1.2 +92, 2.0 +52) | 2.0/sp2p2 D988 @1436 |
| ov009 0x0216C230 | 1368 | **1.1p1 D326** (1.6sp1/2 D356) | none (1.2 +140, 2.0 +92) | 2.0/sp2p2 D1143 @1460 |
| ov009 0x0216C8DC | 296 | 1.1p1 D134 | none (2.0 300 = +4, D50) | **2.0/sp2p2 D50 @300** |
| ov009 0x0216CA04 | 300 | 1.1p1 D133 | none (2.0 304 = +4, D42) | **2.0/sp2p2 D42 @304** |
| ov009 0x0217E504 | 704 | **1.1p1 D184** (1.6sp1/2 D192) | none (1.2 +48, 2.0 +12) | 2.0/sp2p2 D492 @716 |
| ov009 0x0219A52C | 244 | 1.1p1 D107 | **2.0 any of ten, D89 @244**; 1.2/sp3,sp4 D119 @244 | **2.0 D89 @244** |
| ov009 0x0219D5C4 | 672 | **1.1p1 D140** (1.6sp1/2 D146) | none (1.2 +32, 2.0 +40) | 2.0/sp2p2 D609 @712 |
| ov107 0x021F3830 | 348 | **1.1p1 D115** (1.6sp1/2 D134 @344) | none (1.2 +64, 2.0 +36) | 2.0/base D164 @364 |
| ov114 0x021BC740 | 484 | **1.1p1 D142** (1.6sp1/2 D157) | none (1.2 +72, 2.0 −4) | 2.0/sp2p2 D290 @480 |
| ov172 0x021C3DF4 | 3496 | **1.1p1 D282** | none (1.2 +232, 2.0 +156) | 2.0/sp2p2 D3269 @3652 |

First divergence offset (how far into the function the pin agrees), `scratch/s5/firstdiff_table.txt`:

| row | 1.1p1 | 1.2/sp3 | 2.0/sp2p2 |
|---|---|---|---|
| 0x021573C4 | +0008 | +0000 | +0000 |
| 0x02159A80 | +00A8 | +0000 | +00A8 |
| 0x0216C230 | +0080 | +0000 | +0014 |
| 0x0216C8DC | +0004 | +0008 | **+0020** |
| 0x0216CA04 | +0004 | +0008 | **+0030** |
| 0x0217E504 | +0010 | +0000 | +0010 |
| 0x0219A52C | +0000 | +0000 | +0000 |
| 0x0219D5C4 | +000C | +0000 | +0000 |
| 0x021F3830 | +0028 | +0000 | +0020 |
| 0x021BC740 | +0020 | +0000 | +0020 |
| 0x021C3DF4 | +0204 | +0008 | +0000 |

## Verdict

**No configuration matches, and no row earns a pin.** Across 264 configurations per row there is not one
`EXACT`/`MATCH`, and only one row (`0x0219A52C`) has a size-exact alternative at all — the 2.0 line at D89
against the default's D107. On the other ten rows every non-default tree changes the size (+4 to +232
bytes, and one −4) and the eighteen 1.2/2.0 trees all diverge in the prologue, so they are not candidates
for a *size-exact* row at any flag setting. The eleven rows are capped on the compiler axis, measurably.

## The two residues worth handing to a body lane

Both rows are 4 bytes over the target under `2.0/sp2p2` with an otherwise identical prologue, which is
itself the strongest confirmation yet that this SDK object is a 2.0 build: `1.1p1` cannot emit the image's
+0004 `movs r6, r1` (it puts the same parameter in r7 and only agrees from +0008 on), while `2.0/sp2p2`
matches the image byte for byte up to +0020 (0x0216C8DC) and +0030 (0x0216CA04).

- **0x0216C8DC**, `2.0/sp2p2`, 300 vs 296. First divergence at +0020: image `blo #0x216C940` where we emit
  `blt`. The image's `cmp r7, #0x64` is an UNSIGNED compare, so the parked source's compared value is
  signed where the object says unsigned; the `sub r2/r1` and `mul r3/r2` naming follows from it.
- **0x0216CA04**, `2.0/sp2p2`, 304 vs 300. Everything matches instruction for instruction to +00F8; the
  whole 4-byte excess is one instruction at +00FC (`mov r0, r8`), which the image does not have — it keeps
  the base in r8 and loads through it (`ldr r1, [r8, r4]`) where our build copies r8 into r0 first. Every
  other "difference" in the 42 is the +4 pool displacement that the extra instruction causes.

A pin (`compiler: ../2.0/sp2p2` in the house header, evidence in `docs/FRONTEND-PINS.md`) becomes
justifiable on these two only after a body change brings the 2.0 build down to the target size; a pin alone
closes neither. Neither row is filed and no source was edited in this lane.

Evidence: `scratch/s5/sweep2_*.json` (15-tree sweep), `scratch/s5/matrix3.txt` (size-exact matrix),
`scratch/s5/matrix_sizes.json`, `scratch/s5/firstdiff_table.txt`, `scratch/s5/firstdiff.json`,
`scratch/s5/diff_ov009_0x0216C8DC_2.0_sp2p2.txt`, `scratch/s5/diff_ov009_0x0216CA04_2.0_sp2p2.txt`,
`scratch/s5/diff_ov009_0x0219A52C_2.0sp2.txt`, `scratch/s5/extraflags.sh`.
