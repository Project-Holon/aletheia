# Lane U8 — ov172 open SDK rows 0-12 (measured 2026-09-30)

Slice: `python scratch/a2/open_rows.py ov172 0 13` — the 13 smallest open ov172 rows, all
TwlSDK/libssp (JPEG/Exif). Every row below was **compiled live** with
`python tools/match.py one --src <src> --func <name> --addr <addr> --region ov172 --arm --cc 1.1p1
--lang c99 --diff`; the numbers are from those diffs, not from the parked headers.

**0 of 13 EXACT.** One row materially improved (0x021BE468, 34 -> 31 concrete bytes, its literal
pool *and* its store order now agree with the image; landed in
`src/pending/ov_sdk/ov172_func_021BE468.c`). Nothing was filed, so no shard was written. Two rows
had 26 further spellings tried and rejected, with the negative results recorded below.

Rows 0-7 were previously worked by lane T9 (`docs/notes/lane_t9_ov172_sdk_rows.md`) and rows 8-15 by
T30 (`docs/notes/lane_T30_ov172_rows_8_15.md`); this lane re-measured all of them live and started
each attempt from the vendor object (`python tools/sdkobj.py <addr> --region ov172`).

## Slice state (live)

| # | address | function (sdk) | image B | compiled B | concrete | relocs | first divergence |
|---|---|---|---|---|---|---|---|
| 0 | 0x021C0370 | GetWord (exifdec.o) | 80 | 80 | 7 | 0 | +0010 image `ldrb r3, [r0, r1]` \| ours `ldrb r1, [r0, r1]` |
| 1 | 0x021C2050 | SSP_YUV422ToYUV888 | 96 | 96 | 35 | 0 | +000C image `add r4, r3, ip, lsl #1` \| ours `add r1, r3, ip, lsl #1` |
| 2 | 0x021BF0B0 | get_matrix_sub (jpegdec.o) | 172 | 172 | 14 / **10** best | 3/3 | +0004 image `movs r6, r3` \| ours `movs r4, r3` |
| 3 | 0x021C1F04 | SSP_RGB555ToYUV888 | 332 | 328 | 222 | 1/1 | +0000 image `push {r3,...}` \| ours `push {r4,...}` |
| 4 | 0x021BE468 | Mel_JPEGDecodeExif (jpegdec.o) | 348 | 348 | **31** (was 34) | 7/7 | +0014 image `mov r8, r0` \| ours `mov r6, r2` |
| 5 | 0x021C1D8C | SSP_JpegEncoderResample | 376 | 388 | 237 | 2/2 | +0000 image `push {r3,...}` \| ours `push {r4,...}` |
| 6 | 0x021C131C | Yos_JpegEncoderComponentSequential | 484 | 476 | 282 | 7/7 | +0010 image `mla r8, r6, r5, r7` \| ours `mla r7, r6, r5, r7` |
| 7 | 0x021C104C | Yos_JpegEncoderHuffmanEncoderBuildTable | 508 | 520 | 241 | **6/14** | +0008 image `mov r7, r2` \| ours `mov r8, r2` |
| 8 | 0x021C1AE4 | SSPi_JpegEncoderDoSign | 680 | 680 | 103 | 6/6 | +0000 image `push {r4,r5,r6,r7,lr}` \| ours `push {r3,r4,r5,r6,r7,r8,lr}` |
| 9 | 0x021C0D04 | Yos_JpegEncoderForwardDct | 840 | 848 | 717 | 0 | +000C image `add r3, r0, ip` \| ours `add lr, sp, #0x14` |
| 10 | 0x021BF690 | hloadbit | 984 | 896 | 658 | 3/3 | +0004 `ldr r4, [pc, #0x3bc]` \| `ldr r4, [pc, #0x364]` |
| 11 | 0x021BFA68 | writeblock | 1372 | 1424 | 1129 | 4/9 | +0004 image `sub sp, sp, #0x2c` \| ours `sub sp, sp, #0x34` |
| 12 | 0x021C0440 | GetAPP1 | 1908 | 1924 | 1294 | 35/37 | +0000 image `push {r4,...,fp,lr}` \| ours `push {r3,...,fp,lr}` |

`--func` notes: 0x021C131C/0x021C104C need their static names (`Yos_…`), 0x021C0D04 needs
`Yos_JpegEncoderForwardDct`, 0x021C0440's parked source defines `GetAPP1`, 0x021C1AE4's defines
`SSPi_JpegEncoderDoSign`, 0x021BF690/0x021BFA68 need `func_<ADDR>`.

## 0x021BE468 — IMPROVED, 34 -> 31 (the one real result)

The parked draft wrote the three table clears in the order the image's `strh` **stores** run in
(0x021C8D1C, 0x021C8C1C, 0x021C8B1C). The image's literal pool at 0x021BE5B0 is
`g_021C88F0, g_021C8D1C, g_021C8C1C, g_021C8B1C, g_021C959C`, i.e. **0x021C8C1C, 0x021C8B1C,
0x021C8D1C** for the three clears. Writing the source in *that* order makes our pool and our stores
come out exactly as the image's — the previous order is what produced the "our pool is a rotation,
our stores are reversed" note in the T9 file. 34 -> 31 concrete bytes, 7/7 relocations, and
everything from +0x4C to the pool was and stays byte-identical.

Measured over all six permutations of the three clears plus four statement-position variants
(`scratch/laneU8/ex_*.c`, `ex_p0*.c`): our pool for source order (X,Y,Z) is (Z,X,Y) **and** our
store order is (Z,Y,X) — so the two are locked together and the *only* order that puts the pool in
the image's order also puts the stores there. The permutation search is therefore closed: 31 is the
floor for this body. (Two orders reach 30/31; `CBD` is the one that matches the pool.)

Residue, all in the prologue, two clusters:

```
+0014 image mov r8, r0        | ours mov r6, r2      three parameter home-copies come out
+0018 image mov r6, r2        | ours mov r7, r1      option, length, a in ours, a, option,
+001C image mov r7, r1        | ours mov r8, r0      length in the image (same destinations)
+0020 image ldr r3, [pc,#0x124] | ours ldr r2, [pc,#0x124]   which register each prologue
+0028 image ldr r0, [pc,#0x120] | ours ldr ip, [pc,#0x120]   pointer lands in, and where the
+0034 image ldr r2, [pc,#0x118] | ours ldr r1, [pc,#0x11c]   call setup sits
```

The second cluster is one cause: the image keeps `mov r0, r5` / `mov r2, #0x1000` (the
`MIi_CpuClearFast` arguments) at +0x40/+0x44 so that **r0 is free** for the third pointer; ours
hoists them to +0x38/+0x3C, so r0 is busy and the pointer goes to `ip`. A source form that makes
mwcc schedule those two moves below the clears closes both clusters at once.
Rejected this lane (all compile, none under 31): six clear permutations, the call before/inside the
clears, `bits = 0` after the clears (39), three spellings of the call arguments, a comma-joined
clear statement, two local declaration orders. DWARF confirms the local declaration order
(`result, b, s, p` listed = reverse source order).

## Rows with new negative results

### 0x021C0370 GetWord — 80/80, 7 concrete bytes — CANONICALISATION WALL (re-confirmed)
16 further arm-1 spellings this lane (`scratch/laneU8/gw_a*.c`), all of them 80 bytes and exactly the
same 7 concrete bytes: `(u16)((x<<8)&0xff00) | (u16)y`, the same with the mask dropped, `*256`, a
named u16 `hi`, reversed operand order, four return/assignment forms. Two results worth keeping:
- `word |= src[cur]` in **both** arms (the symmetric form) makes mwcc **if-convert the two arms into
  48 bytes** — which is why the vendor's two arms must stay structurally different, and why the
  symmetric spelling can never be the answer here.
- The whole residue is one operand flip: the image materialises `zext16(word)` in r1 and folds the
  byte (`lsl r1,r0,#16 / lsl r0,r3,#16 / lsr r1,r1,#16 / orr r0,r1,r0,lsr #16`); ours materialises
  the byte in r1 and folds `word`. Same instruction count. Do not re-spell without a new idea.

### 0x021BF0B0 get_matrix_sub — 172/172, 14 -> 10 concrete bytes — ONE REGISTER SWAP
DWARF gives the target exactly: `s r9, p r8, ax r7, cx r6, dx r5, i r4`. Ours (with `int dx;`
declared first) is `cx r4, dx r5, i r6, ax r7, p r8, s r9` — i.e. `dx` already matches and **only
`cx` and `i` are exchanged**; the instruction sequence is otherwise byte-identical (5 sites:
0x04 movs, 0x44 lsleq, 0x50 sub, 0x5C mov, 0x8C add).
Ten further declaration/scoping forms this lane (`scratch/laneU8/gm_v*.c`) — `int i; int dx;`,
`int dx, i;`, `int i, dx;`, block-scoped `dx`/`for (int i …)`, `i = 0;` hoisted inside the `if`,
`int i = 0;` at declaration, an `ax` copy — all give 10 or 14 concrete bytes, i.e. the allocator
always puts the **parameter** at r4 (lowest) and the image puts it at r6 (highest of the three).
The image's assignment is a clean descending run over the DWARF order `s,p,ax,cx,dx,i` -> `r9..r4`;
ours is the same run with `cx` moved to the end. A lever that makes mwcc list a parameter *after*
the locals in this function closes the row; nothing in the statement set does.

## Rows 1, 3, 5, 6, 7, 9-12 — parked, residue named

- **0x021C2050 SSP_YUV422ToYUV888** 96/96, 35 concrete bytes. DWARF: `crbuf r14, ybuf r0,
  pYuyv r0, y r12, x r2, yuyv r0` (so the loop bound the image keeps in `ip` is `y` and the counter
  in r2 is `x`). Residue is the whole loop's register set: the image loads `yuyv` into the **dead
  `width` register r1** and keeps the Cb plane base in r4; ours keeps the base in r1 and `yuyv` in
  r8, and folds the `yuyv>>24` term on the other side of the orr (image `orr r1, r5, r1, lsr #24` |
  ours `orr r4, r4, r5, lsr #16`). Same instruction count. Same wall as row 0.
- **0x021C1F04 SSP_RGB555ToYUV888** 332 vs 328, 222 concrete bytes, 1/1 reloc. **The parked draft's
  local set is wrong**: DWARF says the vendor's variables are `pRgb, ybuf, crbuf, image_width, x, y,
  j, rr, gg, bb` — `x`,`y`,`j` counters and three plane pointers, i.e. **nested x/y loops**, not the
  flat `for (i = 0; i < area; i++)` with `i % stride` that the parked source has (which needs the
  `_u32_div_f` call). Also frame: image `push {r3,…,lr}` (40) + `sub sp,#0x10` (16); ours 36+20 — the
  image holds one more value in a register, so the push gains the r3 filler. A rewrite to the DWARF
  structure is the lever; re-spelling the flat loop is not.
- **0x021C1D8C SSP_JpegEncoderResample** 376 vs 388 (+12), 237 diffs, 2/2 relocs. DWARF lists
  `fmt r5, yuyvBak r4, v r12, u r3, y r0, ofs r0, loopDstH [fb+16], loopDstW r2, loopSrcH r0,
  loopSrcW r1, stepSrcW [fb+20]` — reversed, that is **exactly the parked draft's declaration order**,
  so the body structure and the local set are right and the 12 bytes are allocation only.
  First divergence +0x0010 image `mov r6, r0` | ours `mov fp, r0`: DWARF wants `src r6` and
  `dst r11`; ours has src in fp, so one extra value is spilled (our frame 36+28 vs the image 40+24 —
  same 64-byte total, different split). Fix = make the compiler hold one more value in a register.
- **0x021C131C Yos_JpegEncoderComponentSequential** 484 vs 476 (-8), 282 diffs, 7/7 relocs.
  DWARF: `dc r0, ac r10, component r0, dst r9, ptr r8, col [fb+44], row [fb+48]`; variables
  `rrrrssss r0, value r0, diff r1, du r6, bits r5, zerorun r5, ssss r4, index r4` — note `du r6` and
  that `idx`-like values reuse registers (`bits`/`zerorun` both r5, `ssss`/`index` both r4).
  First +0x0010 image `mla r8, r6, r5, r7` | ours `mla r7, r6, r5, r7`, and the draft spills `du`
  (`str r1, [sp]` at +0x28) where the image does not — the extra stack slot is the -8 bytes.
- **0x021C104C Yos_JpegEncoderHuffmanEncoderBuildTable** 508 vs 520 (+12), 241 diffs, **only 6 of 14
  relocations resolve**. Two separate problems: (a) the body/frame (first +0x0008 image `mov r7, r2`
  | ours `mov r8, r2`, the zero constant in `sb` vs `r7`); (b) the sources' `symbols:` block names
  the four table symbols in a form the harness cannot resolve, so 8 of 14 sites stay wildcarded —
  DWARF's own names are `dc0_tbl`, `dc1_tbl`, `ac0_tbl`, `ac1_tbl` plus their `+0x10` sub-objects
  (0x021C8500/0x021C8520/0x021C86C0/0x021C8600/0x021C8510/0x021C8530/0x021C86D0/0x021C8610).
  Fix the symbols block first or the row can never be filed.
- **0x021C1AE4 SSPi_JpegEncoderDoSign** 680/680, 103 diffs, 6/6 relocs. Re-measured from the pending
  source (which lane T30 improved and landed); its file is modified in the working tree, so this lane
  touched nothing. Residue unchanged: image loads `*(u32 *)(gBitLen + 8)` into `ip` and keeps the u16
  tag/count in r2, ours reuses the dead pool register r2 and puts `n` in `ip`, which costs an extra
  `push {…, r8}`. DWARF: `dst r5, ptr r4, tag r3, i r7, registrationNumber r2` — `tag r3` is the
  register the image keeps the count in, so the fixed point is *r2 and r3 both live*.
- **0x021C0D04 Yos_JpegEncoderForwardDct** 848 vs 840, 717 diffs, no relocations. +0x000C image
  `add r3, r0, ip` | ours `add lr, sp, #0x14`: ours pre-computes the pass-2 `tmp` base into `lr`
  before the loop; the image forms it one instruction later and keeps **r3** as the `tmp` pointer.
  Followed by a whole-body rotation from +0x0C.
- **0x021BF690 hloadbit** 896 vs 984 (-88), 658 diffs, 3/3. +0x0004 pool displacement
  `[pc,#0x3bc]` vs `[pc,#0x364]` — ours is 88 bytes short, so the entry block re-allocates freely and
  the frame/base addressing diverges from the prologue on.
- **0x021BFA68 writeblock** 1424 vs 1372 (+52), 1129 diffs, **4/9 relocs**. +0x0004 image
  `sub sp, sp, #0x2c` | ours `sub sp, sp, #0x34` (8 bytes more frame). Ceiling is MATCH anyway:
  `limits 0x021C802C`, `Crrtab 0x021C752C`, `Crgtab 0x021C7B2C`, `Cbbtab 0x021C732C` are four whole
  arrays with no witness outside 021BFA68..021BFFF8.
- **0x021C0440 GetAPP1** 1924 vs 1908 (+16), 1294 diffs, 35/37. +0x0000 image
  `push {r4,…,fp,lr}` | ours `push {r3,…}` and +0x0004 image `sub sp,#0x24` | ours `#0x28`: ours saves
  one extra callee register and reserves 4 bytes more, so `cur` sits at a different slot. Cap MATCH
  (`g_021CADB0` / `g_021CADC4` have no witness outside 021C0440..021C0BC4).

## Files

- `scratch/laneU8/run.py` — variant runner (extent/compiled/concrete per file).
- `scratch/laneU8/sweep2.sh` — live re-measurement of the 13 rows; `sweep.py` (needs explicit
  `--func` names for the static bodies).
- `scratch/laneU8/gw_a01..a16.c` (row 0 spellings), `gm_v01..v10.c` (row 2 declaration forms),
  `gm_*.c` generator `gen_gm.py`; `ex_BCD..DCB.c`, `ex_p01..p09.c` (row 4 clear orders and
  statement positions), generators `gen_gw.py`, `gen_ex.py`, `gen_ex2.py`, scanner `ex_scan.py`.
- `src/pending/ov_sdk/ov172_func_021BE468.c` — updated in place: clears reordered to the image's pool
  order, header records the residue and the rejected variants (34 -> 31).
