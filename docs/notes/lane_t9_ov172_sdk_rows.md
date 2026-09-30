# Lane T9 — ov172 open libssp SDK rows 0-7 (measured 2026-09-30)

Slice: `python scratch/a2/open_rows.py ov172 0 8` — the 8 smallest open ov172 rows, all
TwlSDK/libssp (JPEG). Every row was **compiled live** with the harness at pin 1.1p1, `--arm`,
`--lang c99`, `-O4,p`; residues below are read from the live diff, not from the parked headers.
**0 of 8 closed.** Two rows improved (BF0B0 14 -> 10 concrete bytes, BE468 34 -> 33); the other six
are unchanged. Nothing was filed and no parked source was edited — the improved drafts live in
`scratch/laneT9/`.

Harness line:

```
python tools/match.py one --src <src> --func <name> --addr <addr> --region ov172 --arm \
    --cc 1.1p1 --lang c99 --diff
```

Note for the next lane: `--func` must be the **static symbol name**, not `func_<ADDR>`, for two rows
(0x021C131C = `Yos_JpegEncoderComponentSequential`, 0x021C104C =
`Yos_JpegEncoderHuffmanEncoderBuildTable`); otherwise the harness reports "not found in tu.o".
Also: the diff row labels on a literal-pool ABS32 mismatch name **our** symbol at that offset, not
the image's — decode the pool words instead (`python tools/match.py show --addr <pool> --size N
--region ov172 --arm`).

## Results

| # | address | function (sdk) | image B | compiled B | concrete | verdict |
|---|---|---|---|---|---|---|
| 0 | 0x021C0370 | GetWord (exifdec.o) | 80 | 80 | 7 | DIFF, parked |
| 1 | 0x021C2050 | SSP_YUV422ToYUV888 (jpegenc.o) | 96 | 96 | 35 | DIFF, parked |
| 2 | 0x021BF0B0 | get_matrix_sub (jpegdec.o) | 172 | 172 | **10** (was 14) | DIFF, parked (improved) |
| 3 | 0x021C1F04 | SSP_RGB555ToYUV888 (jpegenc.o) | 332 | 328 | 222 | SIZE -4, parked |
| 4 | 0x021BE468 | Mel_JPEGDecodeExif (jpegdec.o) | 348 | 348 | **33** (was 34) | DIFF, parked (improved) |
| 5 | 0x021C1D8C | SSP_JpegEncoderResample (jpegenc.o) | 376 | 388 | 237 | SIZE +12, parked |
| 6 | 0x021C131C | Yos_JpegEncoderComponentSequential | 484 | 476 | 282 | SIZE -8, parked |
| 7 | 0x021C104C | Yos_JpegEncoderHuffmanEncoderBuildTable | 508 | 520 | 241 | SIZE +12, parked |

Correction to the residue index: `scratch/a2/sdk_residues.json` gives 0x021C131C as 484/476 with no
row for 0x021C104C; the live numbers above are the authoritative ones (0x021C104C is 508/520,
+12, not previously recorded).

## Rows 0-2 (size-exact, allocation only) — pin sweeps first

`match.py sweep` (9 pins x 7 flag sets) was run on rows 0 and 2 and every size-exact row is
**invariant under the pin**: all of dsi 1.1 / 1.1p1 / 1.2 / 1.2p1 / 1.2p2 / 1.3 / 1.3p1 / 1.6sp1 /
1.6sp2 at `-O4,p` give byte-identical output (`scratch/laneT9/sweep_BF0B0.txt`,
`sweep_BE468.txt`; 021BE468 does move to 46 diffs on 1.6sp*). `-O4,s -O4 -O3 -O2 -O1 -O0` are all
far worse. So on these rows the pin is not the lever and the residue is the body shape.

### 0x021C0370 GetWord — 80/80, 7 concrete bytes — PARKED
Little-endian arm only; the big-endian arm at +0x30 is byte-identical. Residue:

```
image +0010  ldrb r3, [r0, r1]     | ours  ldrb r1, [r0, r1]
image +001C  lsl r1, r0, #0x10     | ours  lsl r0, r0, #0x10
image +0020  lsl r0, r3, #0x10     | ours  orr r0, r1, r0, lsr #16
image +0024  lsr r1, r1, #0x10     | ours  lsl r0, r0, #0x10
image +0028  orr r0, r1, r0, lsr #16 | ours lsr r0, r0, #0x10
```

The image materialises `zext16(word)` in a *separate* register (r1) and keeps the `src[cur]` byte
in r3, then folds its `lsr` into the `orr`; ours keeps the byte in r1 and folds `word`'s `lsr`.
The image's own big-endian arm uses **our** pattern, so this is operand/register allocation inside
one expression, not a missing statement. Tried and rejected this lane (15 spellings, all producing
byte-identical output to the parked draft, i.e. MWCC canonicalises them): `(u16)src[cur] | word`,
`word | (u16)src[cur]`, `word |= src[cur]`, `|= (u16)src[cur]`, joined single expression,
`return word | (u16)src[cur]`, separate `u16 lo`/`u16 hi` locals, `unsigned int word`,
`int lo = src[cur]`, `unsigned char c` local (load into c first and last), double casts on both
operands. Files: `scratch/laneT9/fw_*.c`, `gw_*.c`, `gx_*.c`. Two spellings (`word |= src[cur]`
in the LE arm) make both arms structurally identical and the compiler **tail-merges** them to 48
bytes — the image's two arms are deliberately non-identical (9 vs 8 instructions).

### 0x021C2050 SSP_YUV422ToYUV888 — 96/96, 35 concrete bytes — PARKED
Residue is the whole loop body's register set:

```
image +000C  add r4, r3, ip, lsl #1   | ours add r1, r3, ip, lsl #1    (Cb base: r4 vs r1)
image +001C  ldr r1, [r0], #4         | ours ldr r8, [r0], #4          (yuyv reuses r1 vs r8)
image +0024  and r6, r1, #0xff        | ours and r5, r8, #0xff
image +004C  orr r1, r5, r1, lsr #24  | ours orr r4, r4, r5, lsr #16   (Cr fold reversed)
```

The image reuses the dead `width` register (r1) for `yuyv` and keeps the Cb plane base in r4; ours
keeps the base in r1 and puts `yuyv` in r8, and folds the `(yuyv>>24)` term on the other side of
the orr. Same instruction count. Previous lane already tried explicit `cbbuf` pointers, DWARF
declaration order, size split, `while` form, three result locals, post-increment split.

### 0x021BF0B0 get_matrix_sub — 172/172, 14 -> 10 concrete bytes — PARKED (improved)
Declaring the two locals **`int dx;` before `int i;`** (instead of `i` then `dx`) is worth 4 bytes:
it moves `dx` from r6 to r5, matching the image. Left is one pure swap of `cx` and `i`:

```
image +0004  movs r6, r3   | ours movs r4, r3     (cx: r6 vs r4)
image +0044  lsleq r0, r0, r6 | ours lsleq r0, r0, r4
image +0050  sub r6, r6, #1   | ours sub r4, r4, #1
image +005C  mov r4, #0       | ours mov r6, #0    (i: r4 vs r6)
image +008C  add r4, r4, #1   | ours add r6, r6, #1
```

The image's allocation order is `i`(r4), `dx`(r5), `cx`(r6), `ax`(r7) — locals *before* the
parameter; ours is `cx`(r4), `dx`(r5), `i`(r6), `ax`(r7) — parameter first. Tried this lane (all
14 or worse, none flip the swap): `for`/`while`/`do-while`, `i != cx`, `cx > i`, prefix/postfix,
`unsigned cx` (168 B, breaks size), `unsigned i`, `unsigned dx`, both unsigned, `int cx = cxArg`
copies with 1/2/3 locals and every declaration permutation, an extra `n` local aliasing `cx`
(coalesced straight back to r4). Best draft:
`scratch/laneT9/gm_v1_declswap.c` (= `gn_for.c`), 10 concrete bytes.

## Rows 3-7 (large, frame/prologue mismatch + pervasive regalloc) — PARKED

All five have the same first residue — the prologue frame split — and then every stack slot is
addressed at a different offset, so the whole body diverges.

- **0x021C1F04** SSP_RGB555ToYUV888, image 332 / ours 328 (-4), 222 diffs.
  image `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` + `sub sp, sp, #0x10` (= 56);
  ours `push {r4, ..., fp, lr}` + `sub sp, sp, #0x14` (= 56). Ours needs one **fewer 4-byte
  stack local** for MWCC to pad the push with r3 and split 40+16 instead of 36+20. The parked
  note says mwccarm spills `i*2` and keeps `w` in a slot where the image keeps `i*2` in r7 / `w`
  in r5. Tried this lane: hoisting `(h+7)&~7` out of `area`, splitting `d1/d2` assignment from
  declaration, indexing `dst` as `dst[area*i + i]` — the last one **does reach 332 bytes**
  (`scratch/laneT9/rgb_areaidx.c`) but with 246 diffs and the same 36+20 frame, so the size
  agreement there is coincidental, not a shape match.
- **0x021C1D8C** SSP_JpegEncoderResample, image 376 / ours 388 (+12), 237 diffs.
  image `push {r3,...,lr}` + `sub sp,#0x18` (40+24); ours `push {r4,...,lr}` + `sub sp,#0x1c`
  (36+28). Same 64-byte total, same story: one local too many. first divergence
  (+0x10) image `mov r6, r0` | ours `mov fp, r0` — image keeps `src` in r6, ours spills to fp.
- **0x021C131C** Yos_JpegEncoderComponentSequential, image 484 / ours 476 (-8), 282 diffs.
  first (+0x10) image `mla r8, r6, r5, r7` | ours `mla r7, r6, r5, r7` — `du` (or the offset) is
  in r8 in the image and r7 in ours, and the draft spills `du` to `[sp]` (`str r1, [sp]` at +0x28)
  where the image does not.
- **0x021C104C** Yos_JpegEncoderHuffmanEncoderBuildTable, image 508 / ours 520 (+12), 241 diffs.
  first (+0x08) image `mov r7, r2` | ours `mov r8, r2`; the zero constant goes to `sb` in the
  image and `r7` in ours. Same prologue/frame family as 0x021C1F04.
- **0x021BE468** Mel_JPEGDecodeExif, 348/348, 34 -> **33** concrete bytes — PARKED (improved).
  Everything from +0x4C to the pool is byte-identical. All the drift is the six-statement
  prologue block plus the literal pool:

```
image +0014  mov r8, r0            | ours mov r6, r2      (param copies in reverse order:
image +0018  mov r6, r2            | ours mov r7, r1       image a->r8, option->r6, length->r7;
image +001C  mov r7, r1            | ours mov r8, r0       ours option, length, a)
image +0020  ldr r3, [pc, #0x124]  | ours ldr r2, [pc, #0x124]
image +0028  ldr r0, [pc, #0x120]  | ours ldr ip, [pc, #0x120]   (image keeps g_021C8C1C in r0
image +0030  strh r5, [r0, #0x80]  | ours strh r5, [r2]           and reuses r0 for arg0; ours
image +0034  ldr r2, [pc, #0x118]  | ours ldr r1, [pc, #0x11c]    goes via ip)
```

The image's literal pool at 0x021BE5B0 is `g_021C88F0, g_021C8D1C, g_021C8C1C, g_021C8B1C,
g_021C959C` — i.e. the **source statement order of the parked draft** — and its three `strh`
stores also come out in that order. Ours permutes both: with the draft's statement order
(`8D1C, 8C1C, 8B1C`) our pool comes out `8B1C, 8D1C, 8C1C` and the stores `8B1C, 8C1C, 8D1C`
(reversed). Measured relationship over three statement orders — our pool = `[last, first, second]`
of the source order, our stores = the reverse of the source order — so a source order that fixes
the pool cannot also fix the stores: the row needs the register-pressure difference at the top
(the param-copy order) fixed first, because that is what the statement scheduler is reacting to.
Best draft: `scratch/laneT9/ex_E3.c` (source order 8B1C, 8C1C, 8D1C), 33 concrete bytes.

## What is left for a follow-up lane

1. 0x021BF0B0 is 5 instructions from exact and now has a named, single-cause residue (`cx`/`i`
   register swap). Any lever that makes MWCC allocate a *parameter* after its locals closes it.
   Start from `scratch/laneT9/gm_v1_declswap.c`.
2. 0x021BE468 has a one-block residue; the whole rest of the function including 7/7 relocations
   already agrees. The lever is the order of the four callee-saved parameter copies at the top.
3. The five large rows all want the same experiment: delete exactly one 4-byte stack local so the
   push gains the r3 filler and the frame splits 40+16 / 40+24 like the image. That is a size fix
   (+-8..12 bytes), not a match fix; each still needs its regalloc worked afterwards.
4. 0x021C0370 and 0x021C2050 are canonicalisation walls at 7 and 35 bytes; both have now had
   15+ spellings and a 9-pin x 7-flag sweep with byte-identical results. Do not re-spell without a
   new structural idea.

## Files

- `scratch/laneT9/run.py` — batch variant runner (compiles N files, prints extent/compiled/concrete).
- `scratch/laneT9/sweep_BF0B0.txt`, `sweep_BE468.txt` — pin x flag sweeps.
- `scratch/laneT9/gm_v1_declswap.c` (best 021BF0B0), `ex_E3.c` (best 021BE468),
  `rgb_areaidx.c` (021C1F04 size-exact shape), `fw_*/gw_*/gx_*` (021C0370 spellings),
  `gn_*`, `gp_*` (021BF0B0 spellings), `ex_*` (021BE468 statement orders).
