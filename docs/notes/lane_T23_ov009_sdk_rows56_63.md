# Lane T23 — ov009 open SDK rows 56-63

Slice: `python scratch/a2/open_rows.py ov009 56 8` (eight parked SDK rows, ov009, ARM,
pin dsi/1.1p1, `-O4,p --lang c99`). Wall clock: ~65 min, 41 compiles.

## Closed

**0x0218DD88 `gpiFailedOpCallback` — EXACT, 908 bytes** (`src/matched/ov_sdk/ov009_func_0218DD88.c`,
shard `ov009/pkt_ov009_0218DD88`).

The 60-byte residue was cases 1/4/5/6: the image issues the `ldr r0, [r7, #0x1c]` of
`operation->result` *inside* the trailing run of inline zeroing `strb`s, ours kept it after the
run in r1 and then ordered `mov r0, r8` before the stores. Fix: declare the parameter
`const GPIOperation *operation` (and thread the `const` through the `func_02189DFC` extern, or the
front end refuses the call site with an illegal-implicit-conversion CCERR). That is the idiom in
`docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md`, now with
a fifth instance: the load trades places with a *run of zero stores to another object's field*,
not with a single store, and the pointer that must go `const` is the one the load reads through
(the *source*), not the one being written.

One spelling, one compile: 60 → 0 concrete bytes.

## Parked, with residue

`first` is the first differing instruction pair, image | ours.

| address | name | size (img/ours) | concrete bytes | first divergence |
|---|---|---|---|---|
| 0x0215BF88 | func_0215BF88 (dhcp_analyze_response) | 880/880 | 65 | `addeq r3, r5, #0xf0` \| `cmpeq r0, #0x63` |
| 0x0217D904 | func_0217D904 (gsiLargeIntDiv) | 928/936 | 489 | `mov r5, r1` \| `mov r8, r1` |
| 0x02174FE8 | DWCi_NNCompletedCallback | 1008/1000 | 713 | `mov r6, r0` \| `mov r7, r0` |
| 0x02198A0C | func_02198A0C (Think) | 1128/1128 | 86 | `mov r3, #0xa` \| `mov sb, #0xa` |
| 0x0217E078 | gsLargeIntPowerMod | 1164/1092 | 401 | `sub r6, r1, #1` \| `sub r1, r1, #1` |
| 0x021602B8 | cert_item | 1196/1196 | 628 | `ldr r4, [fp]` \| `ldr r1, [fp]` |
| 0x0216C230 | DWCi_GT2ClosedProcess | 1368/1368 | 326 | `bne #0x216c3b0` \| `bne #0x216c410` |

### 0x0215BF88 (65 bytes, size exact)

Sole structural difference in the whole function: the image *predicates* the option-pointer bump
into the `&&` chain of the `0xec..0xef == 63/82/53/63` test —

```
+0104  ldrbeq r0, [r5, #0xef]
+0108  addeq r3, r5, #0xf0     <- s += 0xf0, predicated
+010C  cmpeq r0, #0x63
```

— while this build emits it unconditionally after the `bne` (`add ip, r5, #0xf0`), which also
flips the two registers (image option pointer r3 / mode ip; ours ip / r3). Everything downstream is
the same instruction stream with those two names swapped. Measured inert on 1.1p1 (each 880/65):
`mode` first, `mode` as a declaration initialiser, `s = s + 0xf0`, a block-nested `mode` block, a
`for (s += 0xf0; ...)` loop init, and named `u8 *opt = s + 0xf0` (888 bytes and an extra
callee-saved push, reproducing the earlier lane's number). Parked: the predication is the
compiler's, not reachable from statement order here.

### 0x02198A0C (86 bytes, size exact)

Three-value cyclic rotation in the NN_ERTREPLY branch: image flags-base `g_021AE44C` = r1,
`g_021AE4A7` = r3, ptype = r2; ours r3 / r2 / r1. Consequence, same three instructions reordered
at `+01A8`: image `str r4, [r1, #0xc]` *before* the `ldrh r1, [sp, #0xe]` / `ldr r0, [sp, #0x10]`
argument setup, ours after (repeated at +01F8, +0238). Same class as before: allocator colouring,
body already reproduces the vendor logic byte for byte around it.

### 0x0216C230 (326 bytes, size exact)

`+0080 bne #0x216c3b0 | bne #0x216c410`: the image and this build place the `r7 != 0` continuation
0x60 apart in the linear layout even though the surrounding instructions agree, i.e. a different
merge/ordering of the arms, not a single wrong statement. 100 mismatch rows.

### 0x021602B8 (628 bytes, size exact)

Pure parameter mirror: image level=r7, seq=r6, mode=r8, `*ps`=r4, `&s`=r5; ours r8/r7/r6/r1/r4.
Every arm's scratch registers and all displacements follow; nothing in the body is known wrong.

### 0x0217D904 (489 bytes, +8), 0x02174FE8 (713 bytes, -8), 0x0217E078 (401 bytes, -72)

Size gaps with cascading stack/register colouring; 0x02174FE8 also picks its status value with a
branch in the image where this build if-converts to `moveq/movne`, and 0x0217E078 zeroes `R`
twice in the object. Not closable by a body re-spelling in this lane's budget.

## Notes for the curator

- `src/pending/ov_sdk/ov009_func_0218DD88.c` is now superseded by the filed copy in
  `src/matched/ov_sdk/`; this lane may not delete files.
- The existing idiom file for the `const` load-hoist is worth extending with instance five (see
  above); `docs/idioms/` is outside this lane's write set, so it is recorded here instead.
