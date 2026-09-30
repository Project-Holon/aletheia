# Lane U18 — ov172 (libssp jpeg/exif) frozen slice: measurements and residues

15 rows worked from `scratch/a2/slices/u18.txt` (ov172: exifdec.o / jpegdec.o / jpegenc.o / jpeg.o).
No row reached EXACT in this lane. Everything below is *measured* with
`tools/match.py one --cc 1.1p1 --lang c99 --arm --diff` and the vendor object
(`tools/sdkobj.py <addr> --region ov172`), not inferred.

## The one transferable rule this lane nailed: pool order is [last, first, second]

For a run of independent statements that each mention a *distinct fixed-address global*,
mwccarm (dsi/1.1p1, -O4,p) lays their literal-pool words down as
**[last, first, second]** of the source mention order, while the offsets attached to the
bases stay with their statement. Measured on `Mel_JPEGDecodeExif` 0x021BE468, whose image
pool is `bcode2, mtx+0x200, mtx+0x100, mtx+0` (0x14C/0x150/0x154) while its instruction
stream loads them in the order mtx+0x200, mtx+0x100, mtx+0:

```
source zero-store order            compiled pool (0x14C/0x150/0x154)   concrete bytes out
8D1C, 8C1C(+0x40), 8B1C   (parked) 8B1C, 8D1C, 8C1C                      34
8B1C, 8C1C, 8D1C                   8D1C, 8B1C, 8C1C                      32
8C1C, 8D1C, 8B1C                   8B1C, 8C1C, 8D1C                      33
8C1C, 8B1C, 8D1C                   image's pool  (8D1C, 8C1C, 8B1C)      30  <- pick this
```

So when a row's diff shows the pool words in the wrong order, permute the *statements* that
mention them; the pool order is a function of mention order alone. The catch the brief warned
about is real: the same rotation is applied to the emitted base sequence, so an order that
fixes the pool can leave a store's *offset* on the wrong base (that is the 31-byte variant
below). Fix the pool first, then re-measure the offsets.

## Rows

| address    | bytes | state | first divergence / residue |
|------------|-------|-------|----------------------------|
| 0x021C0370 | 80    | park  | GetWord: size-exact, 7 B. ldrb r3 image | ldrb r1 ours (arm 1 byte load). 12 spellings measured (see file note). |
| 0x021C2050 | 96    | park  | SSP_YUV422ToYUV888: 35 B. `add r4, r3, ip, lsl #1` image | `add r1, ...` ours (Cb base r4 vs r1, yuyv r1 vs r8). |
| 0x021BF0B0 | 172   | improved | get_matrix_sub: 14 B -> **10 B** with `int dx;` before `int i;`. Left: cx/i 2-cycle (see below). |
| 0x021C1F04 | 332   | park  | SSP_RGB555ToYUV888: structure -4 B. `push {r3,...}` image | `push {r4,...}` ours (frame word). |
| 0x021BE468 | 348   | improved | Mel_JPEGDecodeExif: 34 B -> **31 B** with pool order + index pairing fixed. Left: prologue (below). Lane U8 reached the same 31 B and is editing the parked file, so U18 left it alone; the two independent measurements agree on the pool rule. |
| 0x021C1D8C | 376   | park  | SSP_JpegEncoderResample: structure +12 B. `push {r3,...}` image | `push {r4,...}` ours. |
| 0x021C131C | 484   | park  | Yos_JpegEncoderComponentSequential: 476 vs 484, 282 B. `mla r8, r6, r5, r7` image | `mla r7, ...` ours. |
| 0x021C104C | 508   | park  | Yos_JpegEncoderHuffmanEncoderBuildTable: 520 vs 508, 241 B. `mov r7, r2` image | `mov r8, r2` ours. |
| 0x021C0D04 | 840   | park  | Yos_JpegEncoderForwardDct: 848 vs 840, 717 B. `add r3, r0, ip` image | `add lr, sp, #0x14` ours. |
| 0x021BF690 | 984   | park  | hloadbit: 896 vs 984, 658 B. `ldr r4, [pc, #0x3bc]` image | `[pc, #0x364]` ours (pool base). |
| 0x021BFA68 | 1372  | park  | writeblock: 1424 vs 1372, 1129 B. `sub sp, sp, #0x2c` image | `#0x34` ours. |
| 0x021C0440 | 1908  | park  | GetAPP1: 1924 vs 1908, 1294 B. `push {r4,...}` image | `push {r3,...}` ours. |
| 0x021BE5C4 | 2548  | park  | Mel_JPEGDecode: 2444 vs 2548, 2098 B. `sub sp, sp, #0x350` image | `#0x348` ours. |
| 0x021C20B0 | 2592  | park  | Yos_JPEGEncode: 2512 vs 2592, 2209 B. `push {r4,...}` image | `push {r3,...}` ours. |
| 0x021C3DF4 | 3496  | park  | jpeg_encode_main: size-exact 3496, 279 B in ~40 sites. `ldrsh r1, [sb, #4]` image | `ldr r1, [pc, #0xb60]` ours — the image keeps the struct field in a register across the neighbouring code where we rematerialise a pool constant. |

## The four size-exact rows that did not close

* **0x021BF0B0 (10 B).** `int dx;` before `int i;` is worth 4 bytes (14 -> 10):
  `dx` lands in r5 and `i` in r6 as the image wants. The remaining swap is `cx`/`i`:
  image `movs r6, r3` | ours `movs r4, r3`, and at 0x44/0x50/0x58 the image reads the
  loop bound from r6 where we read r4. The allocator colours the *parameter* `cx` first
  (r4, then the locals r5/r6); the image colours the locals first and the parameter last
  (i r4, dx r5, cx r6). Reached by: declaration order (both), block scope for `i`,
  `for (int i...)`, early-return guard, `unsigned` cx/i/dx, one-line declarations,
  `i = 0; i = i;`, `dx = dx;`, `cx = cx;`, `ax = ax;`, and 6 renames (names are inert).
  Nothing moves it; the parameter's colour is not reachable from statement or declaration
  order. Next lever to try: `tools/permuter.py`.
* **0x021BE468 (31 B).** Everything outside the 13-instruction prologue (0x14..0x44) now
  matches, including relocations and the pool. Two independent rotations remain there:
  (a) the three callee-saved parameter moves come out `option, length, a` where the image
  has `a, option, length` — the same [last, first, second] rotation applied to the
  live-across-call list, whose order is our source's first-use order (length, a, option);
  (b) the pool loads are batched (bases live at once in r2/ip/r3, and `mov r0,r5` /
  `mov r2,#0x1000` hoisted above the last two stores) where the image loads each base
  immediately before its own store (r3/r0/r2) and keeps the two `mov`s last.
  Both are invariant over all 12 statement orders measured; the statement order only moves
  the pool words and the store pairings. Next lever: a `volatile`/lifetime change that
  shortens each base's live range, or permuter.
* **0x021C0370 (7 B).** Only `ldrb r3, [r0, r1]` vs `ldrb r1, [r0, r1]` in the little-endian
  arm (plus the 4 instructions that follow from it). The image computes
  `zext16(word) | zext16(byte)` and truncates nothing at the end; we compute `byte | word`
  in 32 bits and truncate the result, which is what makes the byte land in r1 (killing
  `cur`) instead of r3. 12 spellings measured: split statements, one expression, casts on
  both operands, explicit u16 locals (`w2`, `int`), compound `|=`, `+=`, `+`, a separate
  `(unsigned short)(word|byte)`, reversed arms, direct returns — all of them fold back to
  the same 7 bytes. The expression that *forces* the per-operand truncation is not any of
  these spellings.
* **0x021C3DF4 (279 B).** Size-exact and 31 relocations resolve; the residue is ~40 sites of
  "keep the field live" vs "rematerialise the pool constant" scheduling spread over the
  whole 3.5 KB body (first at 0x204). Not an allocator tie: the image holds
  `ldrsh r1, [sb, #4]` across the region where we reload a symbol from the pool. Real work,
  not a spelling.

## Relocation notes (verified)

* `GetAPP1` 0x021C0440 needs `--func GetAPP1`; `Yos_JpegEncoderComponentSequential`
  0x021C131C, `Yos_JpegEncoderHuffmanEncoderBuildTable` 0x021C104C and
  `Yos_JpegEncoderForwardDct` 0x021C0D04 need their object symbol names, not `func_<ADDR>`.
* `Mel_JPEGDecodeExif`'s five data targets want the **region token present** in
  `symbols:` (`g_021C8D1C 0x021C8D1C data ov172`) — with the bare `data` token
  (`data`) the harness reports `unresolved` and the literal is wildcarded.
  `bcode2 0x021c88f0 data` (no region) is correct: it is the `sole-ref/self` case.
