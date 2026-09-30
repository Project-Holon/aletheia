# ov009 SDK open rows 56-63 (lane T13): codegen walls

Slice: `python scratch/a2/open_rows.py ov009 56 8`. All eight rows are parked `DIFF`. Every one
compiles to the image's size or within 4 bytes; none is a reconstruction gap except 0216F770.

Verdict for the whole slice: **no row closed**. Six rows are the same three-way callee-saved
rotation, two are the same "constant kept live in a register" wall. Evidence per row below.

## The two walls

**W1 — constant materialised once in a callee-saved register vs folded/rematerialised at the use.**
The image keeps a small constant live in a register across calls (`mov r5, #3` at entry in
WcmWmcbReset; `mov sl, #6` / `mov sb, #1` in func_0216F770) and reads it back at each use
(`mov r0, r5`, `add r7, sl, #3`, `cmp r0, sb`). Every dsi build instead folds the constant into the
use or rematerialises it there. Not reachable by source spelling: assignment position (before/after
the call), declaration initialiser, comma form, `int`/`u32`/`unsigned short` types, `register`, a
named local holding `1`, or a conditional use all compile byte-identically to the parked body. Pin
sweep (9 pins x 7 flag configs) finds no config closer than the current pin.

**W2 — identical instruction sequence, different callee-saved colouring.**
The emitted order and every mnemonic match; only which callee-saved register holds which variable
differs, plus one move that the colouring cascades into. Resistant to: declaration order, block
scope, single-move vs split assignment, `sizeof` vs literal, `(char *)` casts, `*(int *)p` store
spellings, loop spelling, and to all 9 pins x 7 flag configs.

## Rows

| # | address | image B | ours B | verdict | first divergence (image | ours) decoded |
|---|---------|---------|--------|---------|--------------------------------------------------|
| 56 | 0x02168AD4 DWCi_FriendProcess | 680 | 684 | DIFF 428 | +0008 `ldr r4,[pc,#0x28c]` (state->r4, zero->r5) | `ldr sb,[pc,#0x290]` (state->sb, zero->r6) |
| 57 | 0x0217E504 gsiLargeIntMultM | 704 | 704 | DIFF 184 | +0010 `mov r4, r2` | `mov r7, r0` (inner-loop colours tiptr/carry/mi rotated) |
| 58 | 0x0218263C gsiXmlUtilDecodeString | 720 | 720 | DIFF 70 | +0008 `mov r5, r1` (len->r5, readPos r4, buffer r6) | `mov r4, r1` (len->r4, buffer r5, readPos r6) |
| 59 | 0x021679C0 WcmWmcbReset | 756 | 756 | DIFF 594 | +000C `mov r5, #3` before `bl WCMi_GetSystemWork` | `bl WCMi_GetSystemWork` (constant sunk to first use, body+pool shifted 4) |
| 60 | 0x02161C80 parse_record_in_buf | 792 | 792 | DIFF 260 | +0124 `ldrb r3,[r5,#1]` then `lsl r3,#16`/`add r3,r3,r7,lsl #8` (sub=r8, type read at +013C before the advance) | `ldrb r0,[r5,#2]` then `lsl r0,#8`/`add r0,r0,r1,lsl #16` (sub=r7, type read after as `s[-4]`) |
| 61 | 0x0216F770 DWCi_SBUpdateAsync | 868 | 868 (scaffolded) | DIFF 372 | +0000 `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` | `push {r0,r1,r2,r3}` then the real push |
| 62 | 0x0215BF88 dhcp_analyze_response | 880 | 880 | DIFF 65 | +0108 `addeq r3, r5, #0xf0` (tail of a wildcarded/data region) | `cmpeq r0, #0x63` |
| 63 | 0x0218DD88 gpiFailedOpCallback | 908 | 908 | DIFF 60 | +0128 `ldr r0,[r7,#0x1c]` above the last clear strb | `strb r4,[r3,#7]` |

Row 62 is another lane's file (`src/pending/ov_sdk/ov009_func_0215BF88.c` is git-modified); it was
left alone. Its numbers above are read-only and already improved from `-4 bytes` to size-exact.

## Row 61 (DWCi_SBUpdateAsync): the one real finding

The parked source reaches 868 bytes only because of its scaffolding: `volatile int profileID` makes
dsi home the argument (`push {r0,r1,r2,r3}`, 16 B) and the image has no such push. Dropping
`volatile` (and the `if (1)`) gives the honest 852-byte body, which is **exactly 4 instructions
short** of the image and aligns from +0000 to +0028. The missing instructions, read off the image
prologue, are:

* `mov sl, #6` at +002C — the `n = 6` retry counter kept live (image uses `add r7, sl, #3` for
  `numBasicFields = n + 3`; ours folds to `mov r4, #9`);
* `mov sb, #1` at +0060 — the `== 1` compare constant kept in a register (image `cmp r0, sb`; ours
  `cmp r0, #1`);
* image keeps `profileID` raw (`mov r4, r0`) where ours masks it (`and r5, r0, #0xff`) — but
  `int`/`u32 searchHostType` overshoots (836 B), so `u8` is right and the mask is needed.

So row 61 is W1 plus one extra instruction still unidentified; the clean body is not a valid
reconstruction and the parked one is size-correct only by accident.

## Reproduce

```
python tools/match.py one --src src/pending/ov_sdk/ov009_func_<ADDR>.c --func <NAME> \
  --addr 0x<ADDR> --region ov009 --arm --cc 1.1p1 --lang c99 --diff
python tools/match.py sweep --src <same> --func <NAME> --addr 0x<ADDR> --region ov009 --arm
```

Variant harness and sweeps live in `scratch/t13/` (`var.py`, `cols.py`, `pinsweep.py`,
`sweep_*.json`, `v_*.c`, `w_*.c`, `p_*.c`, `f_*.c`, `g_*.c`, `x_*.c`).
