# Lane T29 — ov172 open SDK rows 0-7 (libssp), decompiled to EXACT

Measured 2026-09-30. Slice: `python scratch/a2/open_rows.py ov172 0 8`, smallest first. Every row
below was **compiled** with the harness and the residue read from the live diff. Nothing was filed:
**0 of 8 rows closed.** Six rows parked with a named residue, two (rows 1 and 4) moved closer than
their parked header claims.

Harness line used for every row:

```
python tools/match.py one --src <path> --func <name> --addr <addr> --region ov172 \
    --arm --cc 1.1p1 --lang c99 --diff
```

Pins were not swept (brief rule 4). Every variant was run at `1.1p1 / -O4,p / arm / c99`.
Raw diffs and every variant source: `scratch/t29/raw_*.txt`, `scratch/t29/var/*.c`.

## Row table

| # | address | function | image B | ours B | verdict | concrete B | first divergence |
|---|---|---|---|---|---|---|---|
| 0 | 0x021C0370 | GetWord | 80 | 80 | DIFF | 7 | +0010 `ldrb r3,[r0,r1]` \| `ldrb r1,[r0,r1]` |
| 1 | 0x021C2050 | SSP_YUV422ToYUV888 | 96 | 96 | DIFF | 35 | +000C `add r4,r3,ip,lsl #1` \| `add r1,r3,ip,lsl #1` |
| 2 | 0x021BF0B0 | get_matrix_sub | 172 | 172 | DIFF | **10** (was 14) | +0004 `movs r6,r3` \| `movs r4,r3` |
| 3 | 0x021C1F04 | SSP_RGB555ToYUV888 | 332 | 328 | SIZE (-4) | 222 | +0000 `push {r3,r4..fp,lr}` \| `push {r4..fp,lr}` |
| 4 | 0x021BE468 | Mel_JPEGDecodeExif | 348 | 348 | DIFF | **31** (was 34) | +0014 `mov r8,r0` \| `mov r6,r2` |
| 5 | 0x021C1D8C | SSP_JpegEncoderResample | 376 | 388 | SIZE (+12) | 237 | +0000 `push {r3,r4..fp,lr}` \| `push {r4..fp,lr}` |
| 6 | 0x021C131C | Yos_JpegEncoderComponentSequential | 484 | 476 | SIZE (-8) | 282 | +0010 `mla r8,r6,r5,r7` \| `mla r7,r6,r5,r7` |
| 7 | 0x021C104C | Yos_JpegEncoderHuffmanEncoderBuildTable | 508 | 520 | SIZE (+12) | 241 | +0008 `mov r7,r2` \| `mov r8,r2` |

Rows 6 and 7 are filed under their SDK names, not `func_`: the object defines
`Yos_JpegEncoderComponentSequential` / `Yos_JpegEncoderHuffmanEncoderBuildTable`, so
`--func func_021C131C` refuses with "not found in tu.o". The parked headers still carry `func_`
names; that is a header defect worth fixing even though the bodies do not close.

## Row 0 — GetWord 0x021C0370 (7 concrete B, spelling-invariant)

Image arm 1 and ours differ only in which `|` operand MWCC folds into the `orr` shifted slot and
where the 16-bit re-truncation lands:

```
image +0010  ldrb r3, [r0, r1]     ; byte
      +001C  lsl  r1, r0, #0x10    ; word << 16
      +0020  lsl  r0, r3, #0x10
      +0024  lsr  r1, r1, #0x10    ; zext16(word) materialised
      +0028  orr  r0, r1, r0, lsr #16   ; zext16(word) | zext16(byte)
ours  +0010  ldrb r1, [r0, r1]
      +001C  lsl  r0, r0, #0x10
      +0020  orr  r0, r1, r0, lsr #16   ; byte | zext16(word)
      +0024  lsl  r0, r0, #0x10
      +0028  lsr  r0, r0, #0x10         ; zext16(result)
```

Rule 4 applies: **12 spellings, all byte-identical** (base, `word | (unsigned short)src[cur]`,
`(unsigned short)word | (unsigned short)src[cur]`, `(unsigned short)(word | src[cur])`,
`(unsigned short)((src[cur+1]<<8)&0xff00) | ...`, `word | src[cur]` with `|=`, two locals, both
declaration orders, a mid-block `unsigned short a = src[cur]`). MWCC normalises the operand order
and the extra cast nodes, so the surviving difference is the allocator's folded-operand pick, not a
source shape. Arm 2 and the whole tail are byte-identical. This confirms the earlier measurement
(7 concrete differences, identical under every pin) and adds that it is also identical under every
spelling: a node-identity residue, not an unspelled body.

## Row 1 — SSP_YUV422ToYUV888 0x021C2050 (35 concrete B)

Size-exact, ~1 instruction selection difference and the rest register naming. The image keeps three
**distinct** plane base pointers in r3 / r4 / lr and indexes every store `[base, r7]`:

```
image +000C  add r4, r3, ip, lsl #1     ; u plane = dst + 2y bytes
      +0010  add lr, r4, ip, lsl #1     ; v plane = u + 2y
      +001C  ldr r1, [r0], #4
      +0024  and r6, r1, #0xff ; and r5, r1, #0xff0000 ; orr r8, r6, r5, lsr #8
      +0030  and r6, r1, #0xff00 ; and r5, r1, #0xff000000 ; lsr r5, r5, #0x10
      +0034  add r2, r2, #1
      +0040  strh r8, [r3, r7] ; +0044 orr r6,r6,r6,lsr #8 ; +0048 strh r6, [r4, r7]
      +004C  orr r1, r5, r1, lsr #24 ; +0050 strh r1, [lr, r7]
ours  +000C  add r1, r3, ip, lsl #1
      +001C  ldr r8, [r0], #4
      +0034  ... add r2, r2, #1 ; strh r5, [r3, r7] ; +0048 strh r6, [r7, r1]
      +004C  lsr r4, r8, #0x18 ; orr r4, r4, r5, lsr #16
```

Two real differences, not just names: (1) the u-plane base is r4 in the image, r1 in ours, and ours
then addresses the second plane as `[r7, r1]` (index form) where the image uses `[r4, r7]`; (2) the
image folds `yuyv >> 24` into the `orr` (`orr r1, r5, r1, lsr #24`) while ours materialises
`lsr r4, r8, #0x18` and folds the mask instead, so the third value's operands are swapped. The
scheduler also interleaves the three values with the stores in the image and batches them in ours.
The parked header's note ("keeps yuyv in r1, the Cb base in r4") is confirmed from the live diff.
No new lever was found; the previous lane's variants (explicit cbbuf pointer, size split, while
form, three result locals) were not re-run.

## Row 2 — get_matrix_sub 0x021BF0B0 (10 concrete B, was 14)

Nothing in the body differs: same instruction count, same selection, only a 3-register rotation.
**Declaration order is a real lever here**: moving `dx` before `i` (`int dx; int i;` instead of
`int i; int dx;`) fixed 4 bytes (the `sub r7, r7, r5`/`dx` colouring and one store), taking 14 -> 10.

What is left is a straight swap of the two remaining registers:

```
image  cx -> r6 (movs r6, r3, sub r6, r6, #1, cmp r6, #0), i -> r4 (mov r4, #0, cmp r4, r6)
ours   cx -> r4,                                             i -> r6
```

dx -> r5 is correct in both. Inert variants tried this lane (all 172 B, 10 diffs unless noted):
base `int i; int dx;` (14), `int dx; int i;` (10), `int dx, i;`, a local copy `n = cx;` used
throughout (with `n` declared first, second or third), `register int i`, `int i = 0` at declaration
in both orders, `cx = cx - 1` instead of `cx--`, `i = 0; while (i < cx)`, `for (i = 0; i < cx - 1; i++)`,
locals block-scoped inside the `if`, `dx = 0` hoisted above the guard (32), `unsigned int i` (168 B),
`if (cx > 0)` (176 B). MWCC gives the earliest-starting live range (cx, live from +0004) the lowest
callee-saved register in our spelling and the highest in the image; no source shape moved it.

## Row 4 — Mel_JPEGDecodeExif 0x021BE468 (31 concrete B, was 34; size-exact)

The best row in the slice and the one worth a follow-up lane. Size-exact at 348 B and the whole body
from +004C to the end (modulo the pool words) is byte-identical.

**New this lane: the pool order is a source lever.** The five ABS32 words sit in a fixed order in the
image, and the order of the three zero-stores selects it:

| statement order | pool order |
|---|---|
| `C1C[0x40]; B1C[0]; D1C[0];` | `88F0, 8D1C, 8C1C, 8B1C, 959C` = **image** |
| `D1C; C1C; B1C;` (parked header order) | `88F0, 8B1C, 8D1C, 8C1C, 959C` |
| `D1C; B1C; C1C;` | `88F0, 8C1C, 8D1C, 8B1C, 959C` |
| `C1C; D1C; B1C;` | `88F0, 8B1C, 8C1C, 8D1C, 959C` |
| `B1C; D1C; C1C;` | `88F0, 8C1C, 8B1C, 8D1C, 959C` |
| `B1C; C1C; D1C;` | `88F0, 8D1C, 8B1C, 8C1C, 959C` |

`C1C[0x40]; B1C[0]; D1C[0];` (i.e. `g_021C8C1C[0x40]=0; g_021C8B1C[0]=0; g_021C8D1C[0]=0;`) drops
the concrete diff from 34 B to 31 B and reproduces the pool exactly. That is the file
`scratch/t29/var/k4.c` and it is the best body found for this row so far.

What is left is 12 instructions, all in the prologue and the pool-pointer block:

```
image +0014  mov r8, r0            ; a        (copies in the order a, option, length)
      +0018  mov r6, r2            ; option
      +001C  mov r7, r1            ; length
      +0020  ldr r3, [pc]  ; D1C   +0028 ldr r0, [pc] ; C1C
      +002C  strh r5, [r3]         +0030 strh r5, [r0, #0x80]
      +0034  ldr r2, [pc]  ; B1C   +0038 ldr r1, [pc] ; 959C
      +003C  strh r5, [r2]         +0040 mov r0, r5      +0044 mov r2, #0x1000
ours  +0014  mov r6, r2      +0018 mov r7, r1      +001C mov r8, r0
      +0020  ldr r2, [pc] ; D1C     +0028 ldr ip, [pc] ; C1C   +002C ldr r3, [pc] ; B1C
      +0030  strh r5, [r2]          +0034 ldr r1, [pc] ; 959C
      +0038  mov r0, r5             +003C mov r2, #0x1000
      +0040  strh r5, [ip, #0x80]   +0044 strh r5, [r3]
```

So: same instruction multiset, same store order (D1C, C1C, B1C), same call setup. The image assigns
the four address temps to r3/r0/r2/r1 - exactly r0-r3 - and overwrites r0 and r2 with the call
arguments at the very end; ours needs r0 live earlier, so one temp goes to `ip` and the
`mov r0, r5` / `mov r2, #0x1000` pair is hoisted above the last two stores. Inert this lane: all
five permutations of the three stores other than k4 (31-34), five orderings of the local
declarations `int p; int s; unsigned char b; long result;` (31 each). The parameter-copy order
(image `a, option, length`; ours `option, length, a` = reverse parameter order) is the other half of
the residue and was not movable by anything tried.

## Rows 3, 5, 6, 7 — parked, all size-mismatched

- **0x021C1F04 SSP_RGB555ToYUV888** (332/328, -4, 222 diffs). The frame split: the image pushes a
  fourth scratch (`push {r3, r4..fp, lr}` + `sub sp, sp, #0x10`) and ours pushes three
  (`push {r4..fp, lr}` + `sub sp, sp, #0x14`); total frame identical, so the image spends one word
  in r3's push that ours spends in the frame. Body diverges immediately after (`mov r5, r1` vs
  `add r4, r1, #7`, i.e. an aligned-stride computation is a plain copy in ours). The extra 4 bytes
  are one instruction in the image's rotation elsewhere. Matches lane S9's "same prologue split".
- **0x021C1D8C SSP_JpegEncoderResample** (376/388, +12, 237 diffs). Same split (`push {r3..}` +
  `sub sp,#0x18` vs `push {..}` + `sub sp,#0x1c`), then `mov r6, r0` vs `mov fp, r0`: the y/u/v
  plane pointers land in different registers from the first instruction. Ours is 12 bytes long.
- **0x021C131C Yos_JpegEncoderComponentSequential** (484/476, -8, 282 diffs). First divergence at
  +0010 `mla r8, r6, r5, r7` vs `mla r7, r6, r5, r7`; the whole indexed-field walk colours one
  register lower in ours and ours is one instruction short. Also filed under `func_` in the header
  while the object defines `Yos_JpegEncoderComponentSequential`.
- **0x021C104C Yos_JpegEncoderHuffmanEncoderBuildTable** (508/520, +12, 241 diffs). First divergence
  at +0008 `mov r7, r2` vs `mov r8, r2`; ours is 12 bytes long and the pool offsets differ from
  +0018 (`[pc, #0x1b8]` vs `[pc, #0x1c4]`), so the tail layout is off by the same 12 bytes. Same
  `func_`-vs-SDK-name header defect.

## What is left

- Row 4 (0x021BE468) is the cheapest row in this slice: 31 concrete bytes, size-exact, the body and
  pool order settled, and the residue is one scheduling/register decision in the prologue block.
  Start from `scratch/t29/var/k4.c`, not from the parked file.
- Row 2 (0x021BF0B0) is 10 bytes, pure register rotation between `cx` and `i`; the declaration-order
  lever (`int dx; int i;`) is already applied.
- Rows 3 and 5 are the same frame-split shape and would be worth working as a pair, but both carry
  200+ concrete bytes and need their frame layout pinned before any further spelling.
- Rows 6 and 7 need their headers repaired (`func_` name vs SDK name) before anything else, and both
  are size-mismatched by one instruction or more.
