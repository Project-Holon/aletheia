# Lane U14 — ov009 SDK slice (13 rows, frozen scratch/a2/slices/u14.txt)

Method: `tools/sdkobj.py <addr> --region ov009` for the vendor object (disassembly + DWARF
prototype/local registers), then `tools/match.py one --cc 1.1p1 --lang c99 --diff` for the
byte diff. Nothing filed: **0 of 13 reach EXACT**; every row is size-exact or short by a
single instruction, and every residue is either a front-end version difference or a
callee-saved colouring the source cannot move.

## Compiler stamps (tools/sdkobj.py, measured table in docs/FRONTEND-PINS.md)

| stamp | rows | tree |
|---|---|---|
| `Metrowerks C/C++ for ARM 4.0.0.1025` | 9 (all TwlDWC members) | **no tools/mwccarm build writes this stamp** (1.1p1 writes 1024, 1.2 writes 1026) |
| `Metrowerks C/C++ for ARM 4.0.0.1024` | 4 (TwlWiFi/libcps) | `dsi/1.1p1` |

The 9 stamp-1025 rows are the ones whose residues are all *unsinkable* fold / schedule /
colour choices (see below); the 4 stamp-1024 rows have the right front end and are still
whole-body colouring residue.

Pin axis re-checked and closed for this slice (1.1p1 is the only size-exact tree):

| row | 1.1p1 | ../2.0/base | ../2.0/sp1p2 | ../1.2/sp3 |
|---|---|---|---|---|
| 021679C0 | 756 (594 diff) | 700 | 700 | 776 |
| 02169934 | 636 (21 diff) | 672 | 672 | 716 |
| 0218263C | 720 (70 diff) | 748 | 748 | 896 |
| 021732F8 | 560 (106 diff) | 568 | 568 | 600 |

(original extents: 756 / 636 / 720 / 564). No non-default tree reproduces an extent.

## Per-row residue (first divergence: image `X` | ours `Y`)

### 021732F8 DWCi_ProcessMatchSynTimeout — 564 B, ours 560 (4 short)
`+01C0` image `add r0, r0, #0x154` | ours `ldrb r5, [r0, #0x56a]`, then a uniform +4 shift to
the end. The aid read reaches an inner object at 0x154 with the field at 0x416; the 1025
front end keeps the two displacements apart, 1.1p1 (and 1.2/sp3, 2.0 trees) folds them.
Parked name: unfolded inner-object base, vendor stamp 4.0.0.1025.

### 02169934 DWCi_GPProfileSearchCallback — 636 B, 21 concrete bytes / 8 sites
`+0030` image `mul r6, r8, r0` | ours `mul r7, r8, r0`; `+00D4` image `mov r7, #0` | ours
`mov r5, #0`. Two long-lived temps swapped across r5/r6/r7: image j→r7, friend-list offset
temp (param*0xc)→r6, loop-2 matchoff (j*0xb0)→r5; ours j→r5, matchoff→r6, friendtemp→r7.
Every other instruction and all 15 relocations match. Tried this lane: 4 declaration
orders (`j` first, `match_index` first, `idx` first, initialiser vs later assignment) — all
byte-identical to the baseline (636/21).

### 021671C0 WcmWmcbScanEx — 648 B, ours 636 (12 short), 372 bytes
Needs an inlined `clz r0, r0` feeding WCMi_GetNextScanChannel (see
docs/idioms/a-clz-means-a-hand-written-asm-body-not-an-intrinsic.md). 23 of 24 relocations
resolve. Not reachable from any C spelling; needs `asm` or stays.

### 02173064 DWCi_SendMatchSynPacket — 660 B, ours 624 (36 short), 463 bytes
`+0000` image `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` | ours
`push {r4, r5, r6, r7, r8, sb, sl, lr}`: the vendor keeps one extra callee-saved value
(sendSize in fp) plus the r3 alignment push; 1.1p1 never takes fp here.

### 0219D5C4 QEStartQuery — 672 B, 140 bytes / 78 sites
`+000C` image `mov r8, #0` | ours `mov r7, #0`; `+0010` image `mov r5, r1` | ours
`mov r4, r1`. Whole-body one-slot rotation (image querySuccess r4, server r5, engine r6,
zeros r7/r8, queryBuffer sb; ours server r4, engine r5, zeros r6/r7, queryBuffer r8,
success sb). Stack frame and all 5 relocations identical. DWARF order is
i, pos, challengeNBO, saddr, querySuccess, queryLen, queryBuffer; reordering to it this
lane (and a bare-decl/assignment form of querySuccess) changed 140 → 140/148, i.e. nothing.

### 02168AD4 DWCi_FriendProcess — 680 B, ours 684 (+4), 428 bytes
`+0008` image `ldr r4, [pc, #0x28c]` | ours `ldr sb, [pc, #0x290]`; `+000C` image `mov r5, #0`
| ours `mov r6, #0`. Singleton/zero land in the opposite pair (DWARF: i r6, j r7, pidcnt r8).

### 0217E504 gsiLargeIntMultM — 704 B, 184 bytes
`+0010` image `mov r4, r2` | ours `mov r7, r0`; `+0014` image `str r1, [sp, #0x240]` | ours
`mov r0, #0`. Montgomery inner loop coloured one slot off (DWARF: tiptr r7, nptr r6, tptr lr,
lastnptr r5, lasttnptr fp — the image's file); ours gives tiptr r8.

### 0218263C gsiXmlUtilDecodeString — 720 B, 70 bytes / 45 sites
`+0008` image `mov r5, r1` | ours `mov r4, r1`; `+0010` image `mov r6, r0` | ours
`mov r5, r0`. Pure three-way rotation: image readPos r4 / len r5 / buffer r6; ours len r4 /
buffer r5 / readPos r6 (DWARF agrees with the image: buffer r6, len r5, haveWritten r7,
mask r8, digitEnd sb). Frame and every other instruction identical. Tried this lane: bare
`int readPos;` + `readPos = 0;` statement, swapped decl order, DWARF-order block locals,
bare block locals — 70 (or 95/214) bytes, no move.

### 021679C0 WcmWmcbReset — 756 B, 594 bytes (one instruction + shift)
`+000C` image `mov r5, #3` | ours `bl #0x21657c8` (WCMi_GetSystemWork). The image
materialises the `wlStatus = 3` seed in the entry block (r5 live across the call); 1.1p1
sinks it to the case 5/6 use at +0x210 and rematerialises there, which costs the +4 shift
everything after shows. Tried this lane: `unsigned short wlStatus = 3;` in three declaration
positions and a pre-call assignment statement — byte-identical to the baseline.

### 02161C80 parse_record_in_buf — 792 B, 260 bytes
`+0024` image `ldrb r3, [r5, #1]` | ours `ldrb r0, [r5, #2]`. Sub-record length sub=r8 with
its +4 temp=r7 in the vendor, mirrored (sub=r7, temp=r8) in ours — the handshake-loop
mirrored callee-saved pair.

### 0216F770 DWCi_SBUpdateAsync — 868 B, 372 bytes
`+0000` image `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` | ours starts
`push {r0, r1, r2, r3}` (the build also pre-pushes r0-r3 here, which the vendor object does
not). Whole body emitted through a different callee-saved map; the parked note's `6 + 3`
numBasicFields pair (6 live in sl, `add r7, sl, #3`) is still absent.

### 0215BF88 dhcp_analyze_response — 880 B, 65 bytes
**claimed by another lane mid-session** (`git status` shows src/pending/ov_sdk/ov009_func_0215BF88.c
modified); not touched. Residue for the record: `+0108` image `addeq r3, r5, #0xf0` | ours
`cmpeq r0, #0x63` — the `(s += 0xf0, s[-1] == 0x63)` pointer add is predicated inside the
`&&` chain in the image (option pointer r3, `dhcp_mode & 2` mask ip) and sunk below the
branch in ours (pointer ip, mask r3), with the four following instructions scheduled in the
image's order.

### 0217D904 gsiLargeIntDiv — 928 B, ours 936 (+8), 489 bytes
`+0008` image `mov r5, r1` | ours `mov r8, r1`; `+0010` image `mov r4, r0` | ours
`mov sb, r0`; `+001C` image `add r8, r2, #4` | ours `add r5, r2, #4`. Stack order
(scopy at sp+0x10, quotient at sp+0x210 with the two different zero points) plus the
parameter rotation.

## Handy residue names for this slice

- `021679C0` / `021732F8` / `0216F770` / `0217E504` — 1.1p1 keeps/sinks a constant or folds
  a displacement differently from the 4.0.0.1025 front end; the source cannot move it.
- `02169934` / `0219D5C4` / `0218263C` / `0217D904` / `02168AD4` — whole-value callee-saved
  rotations (one slot or a mirrored pair) with identical instruction count, stack frame and
  relocations: the overlays' most common wall, and inert under declaration reordering,
  bare-decl spellings and the pin sweep above.
