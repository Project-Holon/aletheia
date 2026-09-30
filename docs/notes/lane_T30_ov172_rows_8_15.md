# Lane T30 — ov172 open SDK rows 8-15 (libssp / JPEG, the same slice as lane T19)

Measured 2026-09-30. Slice: `python scratch/a2/open_rows.py ov172 8 8`. Every row compiled live with
`python tools/match.py one --src … --func … --addr … --region ov172 --arm --cc 1.1p1 --lang c99 --diff`.
Raw diffs: `scratch/laneT30/d<NN>.txt`, variants `scratch/laneT30/r8_v*.c`.

**0 of 8 closed. One row materially improved: 0x021C1AE4 went from 732 B / 568 concrete bytes to
680 B (SIZE-EXACT) / 103 concrete bytes; the improved draft is landed in
`src/pending/ov_sdk/ov172_func_021C1AE4.c` and re-verified by recompile.** No pin or flag was swept
(rule 4); everything below is body shape.

| # | address | function | image B | compiled B | relocs | diffs | verdict |
|---|---|---|---|---|---|---|---|
| 8 | 0x021C1AE4 | SSPi_JpegEncoderDoSign | 680 | **680** | 6/6 | **103** | SIZE-EXACT, allocator |
| 9 | 0x021C0D04 | Yos_JpegEncoderForwardDct | 840 | 848 | 0 | 717 | SIZE +8 |
| 10 | 0x021BF690 | hloadbit | 984 | 896 | 3/3 | 658 | SIZE −88 |
| 11 | 0x021BFA68 | writeblock | 1372 | 1424 | 4/9 | 1129 | SIZE +52 |
| 12 | 0x021C0440 | GetAPP1 | 1908 | 1924 | 35/37 | 1294 | SIZE +16 |
| 13 | 0x021BE5C4 | Mel_JPEGDecode | 2548 | 2444 | 21/21 | 2098 | SIZE −104 |
| 14 | 0x021C20B0 | Yos_JPEGEncode | 2592 | 2512 | 49/52 | 2209 | SIZE −80 |
| 15 | 0x021C3DF4 | jpeg_encode_main | 3496 | 3496 | 31/31 | 279 | SIZE-EXACT, allocator |

`--func` must be `func_<ADDR>` for 0x021BF690, 0x021BFA68, 0x021BE5C4 and 0x021C3DF4 (static bodies:
`hloadbit`, `writeblock`, `Mel_JPEGDecode` and `jpeg_encode_main` are not in `tu.o` under those names).

## 8. 0x021C1AE4 SSPi_JpegEncoderDoSign — 680/680, 6/6 relocs, 103 concrete bytes (was 732/568)

The parked draft was **52 bytes long** because every 4-byte big-endian field read was spelled
`dst[offset + 8] … dst[offset + 0xb]`: mwcc then has to materialise each index, four
`add rN, r1, #k` per read, and it could not keep the pointer. The image materialises
`add r0, r5, r1` once and reads `[r0,#8] … [r0,#0xb]` (same for `[2]`/`[3]` and `[0xa] … [0xd]`).
Three body-shape changes together took 732 → 680 (SIZE-EXACT) and 568 → 103 concrete bytes:

1. `const unsigned char *p = dst + offset;` inside each scan loop, reads spelled `p[8] … p[11]`
   (and `p[0xa] … p[0xd]` in the sign block). This alone is the 52 bytes.
2. `unsigned int i;` (was `int`) — the loop guards become the image's `bls` / `blo`
   (`cmp r2,#0; bls`, `cmp ip,#0; bls`) instead of `ble` / `blt`.
3. `tag = (u16)((dst[offset + 1] + (dst[offset] << 8)));` — the same value, but `dst[offset]` is the
   term that gets shifted, which is the image's `ldrb r6,[r5,r1]` + `ldrb r3,[r0,#1]` load pair
   (worth 9 concrete bytes).
4. In the second block, `offset = base + 2;` moved **after** the `n = …` read, which removes the
   `mov rN, r1` copy the image does not have (112 → 103 combined with 3).

Residue (all one register rotation, first differing instruction at +0x0010):

```
+0010 image ldr ip, [r2, #8]   | ours ldr r2, [r2, #8]     <- the whole residue is this
+0018 image cmp ip, #0x17      | ours cmp r2, #0x17
+0000 image push {r4,r5,r6,r7,lr} | ours push {r3,r4,r5,r6,r7,r8,lr}
```

The image loads `*(u32 *)(gBitLen + 8)` into **ip** and keeps the u16 count/tag in **r2**; ours
reuses the dead pool register r2 for the load and puts `n` in ip. That extra live value is carried
into the second scan, where the loop counter `i` lands in r8 (image: r7) and costs a
`push {…, r8}` / `pop …` the image does not have. Everything from +0x10 to the tail is the same
instruction sequence with those three registers renamed. Rejected this lane (each compiled, all
103-137): `((u32 *)gBitLen)[2]`, a named `u32 *lp` block, `p` at function scope, `p` assigned vs
declared per loop, every declaration order of `n`/`tag`/`p`/`i`, and the original open-brace/per-loop
scoping of `i`. The lever is a source form that makes mwcc pick ip for the gBitLen load; nothing in
the statement set tried moves it.

## 9-15 — parked, residue named

- **0x021C0D04 Yos_JpegEncoderForwardDct** 848 vs 840 (+8), 717 diffs, no relocations.
  first: +0x000C image `add r3, r0, ip` | ours `add lr, sp, #0x14` — ours pre-computes the pass-2
  `tmp` base into `lr` before the loop and then keeps it there; the image forms the same address one
  instruction later and keeps **r3** as the `tmp` pointer for the whole loop. Same 8 bytes of extra
  register pressure the parked header names: pass 2 spills a second value. Body is structurally
  right; the whole body is a register rotation from +0x0C.
- **0x021BF690 hloadbit** 896 vs 984 (−88), 658 diffs, 3/3 relocs. first: +0x000C image
  `ldr r5, [r4, r2, lsl #2]` | ours `ldr r8, [r4, r2, lsl #2]` (and +0x08 `ldr r3,…` vs `ldr sl,…`).
  The pool-relative displacements differ too (`[pc,#0x3bc]` vs `[pc,#0x364]`) because ours is 88
  bytes short, so the entry block's pointer set is freely re-allocated: the frame/base addressing
  diverges from the prologue onwards.
- **0x021BFA68 writeblock** 1424 vs 1372 (+52), 1129 diffs, **4/9 relocs**. first: +0x0004 image
  `sub sp, sp, #0x2c` | ours `sub sp, sp, #0x34` — ours reserves 8 bytes more frame and addresses
  every slot 8 higher. Cap is MATCH anyway: `limits 0x021C802C`, `Crrtab 0x021C752C`, `Crgtab
  0x021C7B2C`, `Cbbtab 0x021C732C` are four whole arrays with no witness outside
  021BFA68..021BFFF8, so the ceiling is MATCH even with a byte-exact body.
- **0x021C0440 GetAPP1** 1924 vs 1908 (+16), 1294 diffs, 35/37 relocs. first: +0x0000 image
  `push {r4, r5, r6, r7, r8, sb, sl, fp, lr}` | ours `push {r3, …}`; +0x0004 image `sub sp, sp, #0x24`
  | ours `sub sp, sp, #0x28`. Ours saves one extra callee register and reserves 4 bytes more, so
  `cur` is at a different slot and every later load differs. Cap MATCH (`g_021CADB0` /
  `g_021CADC4` have no witness outside 021C0440..021C0BC4).
- **0x021BE5C4 Mel_JPEGDecode** 2444 vs 2548 (−104), 2098 diffs, **21/21 relocs**. first: +0x0004
  image `sub sp, sp, #0x350` | ours `sub sp, sp, #0x348`; +0x000C image `str r5, [sp, #0x24]` |
  ours `ldr r4, [pc, #0x948]`. Frame 8 bytes smaller and 104 bytes short: every local is at a
  different offset and the shared epilogue differs throughout. The callee set is right (all 21
  relocations resolve), so this row can still reach EXACT — but only after the frame is pinned.
- **0x021C20B0 Yos_JPEGEncode** 2512 vs 2592 (−80), 2209 diffs, 49/52 relocs. first: +0x0000 image
  `push {r4, r5, r6, r7, r8, sb, sl, fp, lr}` | ours `push {r3, …}`; +0x0004 image `sub sp, sp, #0x74`
  | ours `sub sp, sp, #0x70`; +0x001C image `str r0, [sp, #0x1c]` | ours `str r0, [sp, #0x34]`.
  Ours saves one extra callee register and reserves 4 bytes less frame, so `huffsize`/`huffcode`
  and the SoF/DQT/DHT buffers are all at different offsets.
- **0x021C3DF4 jpeg_encode_main** 3496/3496, 31/31 relocs, 279 concrete bytes over 122 instructions
  in 10 clusters. first: +0x0204 image `ldrsh r1, [sb, #4]` | ours `ldr r1, [pc, #0xb60]`; at
  +0x0210 image loads the `g_021CADF0` word only after `strh r1, [sb, #4]`, ours hoists the pool
  load above the `count0++` and therefore has to keep the counter in r2 instead of r1. Everything
  from +0x0000 to +0x0204 is byte-identical; every later cluster is the same r0/r1/sl/fp/r3 rotation
  (full cluster list in `docs/notes/lane_t19_ov172_libssp.md`). This row is owned by lane T19 and its
  file is modified in the working tree; T30 only re-measured it from a scratch copy
  (`scratch/laneT30/t15_021C3DF4.c`), which reproduced 279/31-of-31 exactly.

### Tried on 0x021C3DF4 this lane (DWARF-guided, negative result worth recording)

`sdkobj.py 0x021C3DF4 --region ov172` lists **28 separate `entry` variables** plus `jexif` (r9) and
`cfg_encode_exif` (r8) — one block-scoped `exif_tag_entry *entry` per tag block, allocated in
r0/r10/r7/r5/r4. The parked draft reuses one `struct Slot *s` for all 27 blocks. A mechanical
transform that gives every block its own `{ struct Slot *entry = &jexif->…; … }` scope
(`scratch/laneT30/t15b.c`, 34 blocks converted) compiles to **byte-identical output** to the
single-`s` draft: 3496 bytes, 279 concrete bytes, same clusters. So the DWARF variable identity is
not the lever on this row — the allocator coalesces them anyway — and the 279 bytes are not a
scoping artefact.

## Files

- `scratch/laneT30/r8_v1.c` (pointer-local, 680 B / 141), `r8_vB.c` (unsigned i + offset placement,
  680 / 112), `r8_vF.c` (**best: 680 / 103**, also landed in the pending source).
- `scratch/laneT30/t15_021C3DF4.c` (scratch copy), `t15b.c` (block-scoped `entry` transform).
- `scratch/laneT30/d<08..15>.txt` — live diffs; `dumpall.sh` — the batch runner.
