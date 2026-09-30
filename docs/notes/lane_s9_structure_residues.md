# Lane S9 — ov114 / ov172 / ov015 / ov175 structure rows + ov172 libssp JPEG

Measured 2026-09-30. Every row below was **compiled** with the harness and the residue read
from the live diff, not copied from the parked header. Nothing was filed: **0 of 9 structure
rows closed, 0 of 4 ov172 libssp rows closed.** Every row is parked with a named residue.

Harness lines used (all `--lang c99`, `--arm`):

```
python tools/match.py one --src src/pending/ov_sdk/<file>.c --func <name> \
    --addr <addr> --region <region> --arm --cc <pin> --lang c99 --diff
```

`tools/match.py sweep` was also run on ov114 0x021BC2FC and ov114 0x021BA150: all nine
compiler dirs x {-O4,p -O4,s -O4 -O3 -O2 -O1 -O0} give byte-identical output, so the pin
is not the lever on these rows. Raw diffs: `scratch/laneS9/raw_<addr>.txt`,
baselines: `scratch/laneS9/baseline.json`.

## Structure rows (the nine assigned rows)

| region | address | function | image B | compiled B | verdict | residue |
|---|---|---|---|---|---|---|
| ov114 | 0x021BA150 | func_021BA150 | 164 | 176 | DIFF (+12) | regalloc only |
| ov114 | 0x021BBBC8 | func_021BBBC8 | 296 | 292 | DIFF (-4) | prologue scheduling |
| ov114 | 0x021BC2FC | func_021BC2FC | 136 | 132 | DIFF (-4) | one redundant `b` |
| ov114 | 0x021C7A74 | func_021C7A74 | 212 | 208 | DIFF (-4) | regalloc only |
| ov172 | 0x021C0440 | GetAPP1 | 1908 | 1924 | DIFF (+16) | prologue reg set + frame |
| ov172 | 0x021C1D8C | func_021C1D8C | 376 | 388 | DIFF (+12) | prologue reg set + regalloc |
| ov172 | 0x021C1F04 | func_021C1F04 | 332 | 328 | DIFF (-4) | regalloc / spill |
| ov015 | 0x0217A7AC | func_0217A7AC | 320 | 328 | DIFF (+8) | loop guard + reg swap |
| ov175 | 0x021DF65C | func_021DF65C | 216 | 200 | DIFF (-16) | second jump table vs compare tree |

### ov175 0x021DF65C — DWCi_HandleWSLoginError (75 concrete diffs, 1/1 reloc)

Everything up to +0x7C matches except pool-branch displacements. The whole divergence is the
switch lowering of cases 0x69..0x6C (105..108, all `errorCode -= 8`):

```
image +0080: cmp r4, #0x69 ; bgt +0x6EC ; beq <case -8> ; b <default>
             cmp r4, #0x6C ; bgt <default> ; cmp r4, #0x6A ; blt <default>
             cmpne r4, #0x6B ; beq <case -8> ; cmp r4, #0x6C ; bne <default>
ours  +0080: sub r2, r4, #0x69 ; cmp r2, #3 ; addls pc, pc, r2, lsl #2   (second jump table)
```

first differing instruction: image `cmp r4, #0x69` | ours `sub r2, r4, #0x69` (+0x80).
Tried and rejected: splitting the 105..108 arms into two case groups (208 B, still a table),
moving `case 104` after 105..108 (204 B), lifting 105..108 into a leading `if` range test
(196 B, 104 diffs). The image keeps one jump table (0..7) and a compare **tree** for the
0x69..0x6C run; ours builds a table for that run. Under the same counts MWCC picks the table,
so the original switch's case set for that region is not the four-in-one-arm spelling.

### ov114 0x021BC2FC — NHTTPi_BufFull (14 concrete diffs, 4/4 relocs)

The smallest row in this lane and the only one where a new, tighter residue was found. The
image's tail is

```
+0030 cmp r0, #0              ; the earlier `if (full == 0) goto set`
+0034 beq +0x7C              ; -> set
...
+0074 cmp r0, #0              ; the second func_021BB2FC result
+0078 b   +0x7C              ; UNCONDITIONAL branch to the very next-but-one instruction
+007C moveq r4, #1           ; set:  (predicated)
+0080 mov r0, r4             ; end:
+0084 pop {r4, r5, r6, pc}
```

So `set:` is only the predicated store and the second path reaches it with an **unconditional**
branch after its own `cmp`. Our draft folds the store's test into the set block, which is 4
bytes short (132 B) and, when the store is re-expressed, 5 bytes off:

best variant found (`scratch/laneS9/var/d1.c`, 136 B, 5 concrete bytes):
image `b #0x21BC378` | ours `bne #0x21BC37C` (+0x78) and image `moveq r4, #1` |
ours `mov r4, #1` (+0x7C).

Variants tried this lane (all 132-144 B, none exact): exact predecessor draft; merged compound
condition; brace/`else` variants of the shared tail; `if (full == 0) goto set;` + `set: if
(full == 0) ret = 1;`; bare `goto set;` before the label; `if(full==0) {...} else {...}`; the
docs/idioms "if/else storing to the same target keeps a `b` to the next instruction" shape
(`if (full == 0) ret = 1; else ret = 1;` — MWCC if-converts it to a plain `mov` and emits
`bne end`, not `cmp; b set; moveq`); `?:`; `else ret = ret;`; `goto end` placed in each arm.
MWCC's branch eliminator always removes the redundant `goto` and hoists the `cmp` into the
previous block, so the surviving `b` in the image was emitted in a block order the source
spelling has not yet reproduced.

### ov015 0x0217A7AC — IRCi_Read (177 concrete diffs, 12/13 relocs)

first differing instruction: image `ldrb r4, [r6]` | ours `ldrb r5, [r6]` (+0x6C).
Two independent differences: (1) image keeps `size` in r4 and `i` in r5, ours swaps them;
(2) ours emits a redundant loop pre-test guard `ble` right after the `if (size != 0)` `beq`:

```
image +0088 cmp r4, #0 ; beq <else> ; sub sl, r4, #1 ; ... ; b <loop test>
ours  +008C cmp r5, #0 ; beq <else> ; ble <...>      ; sub sl, r5, #1 ; ...  (extra branch)
```

Tried this lane: `if (size == 0) { else } else { loop }` polarity swap and the `while`-without-
guard spelling (173 and 177 diffs). Unresolved reloc: `g_0217ACA0` (ABS32) has no witness
outside the compared range.

### ov114 regalloc rows (parked on register allocation alone)

- **0x021BA150** NHTTPi_strnicmp, 164/176 (+12), 95 diffs. Image: zero in r4, one in r5,
  c1 = sb, c2 = r8. Ours: zero in r6, one in r7, c1 = r3, c2 = sb.
  first: image `mov r4, #0` | ours `mov r6, #0` (+0x08).
- **0x021C7A74** DWCi_Ndi_intToStrFigure, 212/208 (-4), 119 diffs. Image hoists the sticky
  flag `b` into r0 (`mov r0, r5` before the loop) and loads the u64 table twice (hi word then
  lo word from two pool loads); ours keeps `b` in r1 and does one table load.
  first: image `ldr r4, [pc, #0xb8]` | ours `ldr r4, [pc, #0xb4]` (+0x08).

### ov172 regalloc / scheduling rows

- **GetAPP1 0x021C0440**, 1908/1924 (+16), 1294 diffs, 35/37 relocs.
  first: image `push {r4, r5, r6, r7, r8, sb, sl, fp, lr}` | ours adds `r3`;
  (+0x04) image `sub sp, sp, #0x24` | ours `sub sp, sp, #0x28`.
- **0x021C1D8C** SSP_JpegEncoderResample, 376/388 (+12), 237 diffs.
  same prologue split: image `push {r3,r4..fp,lr}` + `sub sp,#0x18`;
  ours `push {r4..fp,lr}` + `sub sp,#0x1C`. y/u/v in r0/r3/ip vs r7/sl/r8.
- **0x021C1F04** RGB555->planar YCbCr, 332/328 (-4), 222 diffs. Same prologue split; ours
  spills `i*2` and keeps `w` in a stack slot where the image keeps `i*2` in r7 and `w` in r5.
- **0x021BBBC8** NHTTPi_getHeaderValue, 296/292 (-4), 186 diffs, 5/5 relocs.
  first: image `mov sl, r0` | ours `mov r3, #0` (+0x08) — image moves the r0 parameter into sl
  first and stores the stack argument later; the length compare loads differ too.

## ov172 libssp (JPEG) — measured, none previously had a residue

| address | function | image B | compiled B | verdict | residue |
|---|---|---|---|---|---|
| 0x021C3DF4 | jpeg_encode_main | 3496 | 3496 | **SIZE-EXACT** DIFF | 280 concrete bytes |
| 0x021C20B0 | Yos_JPEGEncode | 2592 | 2512 | SIZE (-80) | 2209 concrete bytes |
| 0x021BE5C4 | Mel_JPEGDecode | 2548 | 2444 | SIZE (-104) | 2098 concrete bytes |

**0x021C3DF4 jpeg_encode_main** — the parked header says "the whole function does not
reproduce"; that is wrong and worth correcting. It is **size-exact at 3496 bytes** with only
**280 of 3496 concrete bytes** differing and 27/31 relocations resolved; the first concrete
divergence is at +0x204 (image `ldrsh r1, [sb, #4]` | ours `ldr r1, [pc, #0xB60]`). Four
relocation sites stay unresolved: `write_exif_ifd_tables` twice (no `symbols:` line) and the
ABS32 globals `g_021CB728` / `g_021CAE90` (wildcarded). This is the closest libssp row in the
region and the best candidate for a follow-up lane. NOTE: `src/pending/ov_sdk/ov172_func_021C3DF4.c`
is modified in the working tree by another writer — work from a copy.

**0x021C20B0 Yos_JPEGEncode** — first divergence at +0x0000:
image `push {r4, r5, r6, r7, r8, sb, sl, fp, lr}` | ours `push {r3, r4, ... fp, lr}`;
(+0x04) image `sub sp, sp, #0x74` | ours `sub sp, sp, #0x70`. The whole function is off, not a
tail mismatch: ours saves one extra callee register and reserves 4 bytes less frame, so every
stack slot (locals, `huffsize`/`huffcode`, the SoF/DQT/DHT buffers) is addressed at a different
offset. 49/52 relocations resolve.

**0x021BE5C4 Mel_JPEGDecode** — first concrete divergence at +0x000C (image `str r5, [sp,
#0x24]` | ours `ldr r4, [pc, #0x948]`); (+0x04) image `sub sp, sp, #0x350` | ours
`sub sp, sp, #0x348`. All 21/21 relocations resolve, so the callee set is right; the frame and
the shared epilogue differ throughout.

### Do the JPEG functions share a helper?

No. Their relocation sets are disjoint in the sense that matters: jpeg_encode_main calls
`STD_CopyLString` (0x0208CB10) / `func_02082EA4` / `write_exif_ifd_tables`; Yos_JPEGEncode
calls `_u32_div_f` / `_s32_div_f` / the three `Yos_JpegEncodeSample*to*Component` resamplers;
Mel_JPEGDecode calls `MIi_CpuClearFast` / `SSP_ExifDecode` / the `func_021BEFB8` /
`func_021BF15C` / `func_021BFA68` marker walkers. There is **no shared unmapped helper to write
first** — each row's residue is its own prologue/regalloc shape, not a missing callee. (The one
already-matched resampler the encoder consumes, `func_021C1D8C`/`func_021C1F04`'s siblings, are
matched files.) No helper was written.

## What is left

- 0x021BC2FC is 5 bytes / 1 instruction from exact (ove114); a lane that can reproduce MWCC's
  surviving unconditional branch should take it first — it is the cheapest row in this lane.
- 0x021C3DF4 jpeg_encode_main is size-exact with 280 bytes of concrete drift and 4 unresolved
  relocations; adding a `symbols:` line for `write_exif_ifd_tables` (0x021C3A28 in the image at
  +0x0CE8) plus witnesses for `g_021CB728`/`g_021CAE90` would shrink the residue materially.
- Yos_JPEGEncode and Mel_JPEGDecode need their frame layouts pinned before any further spelling
  is worth budget.
