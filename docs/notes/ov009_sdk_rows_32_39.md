# ov009 SDK rows 32-39 (lane T5) — pin sweep first, one header repair, three named residues

2026-09-30. Slice: `python scratch/a2/open_rows.py ov009 32 8`, eight parked rows, 300..388
bytes. 61 compiles for the flag sweep (all 9 dsi compilers x 7 flag sets, via
`match.py sweep`), 92 compiles for the all-tree pin sweep (all 1.2/2.0/dsi subtrees x
`-O4,p`/`-O4,s`/`-inline off`/`-ipa function`, via `scratch/a2/laneT5/pin_sweep.py`),
then 39 compile-and-diff runs over 39 text variants
(`scratch/a2/laneT5/gen_*.py`, driven by `scratch/a2/laneT5/vrun.py`). No row closed; every
row's floor is unchanged from the parked source *except* 0216CA04, whose pin was wrong.

## Headline: the pin, not the body (0x0216CA04, DWC_AddMatchKeyString)

`dsi/1.1p1 -O4,p` is the right pin for seven of the eight rows. It is **wrong** for
`func_0216CA04`: under any **2.0-tree** compiler (`2.0/base`, `2.0/sp1`, `2.0/sp1p2` - all
three give the same bytes) the register allocation matches the image instruction for
instruction from +0004 to +0x2C and the residue falls **133 -> 42** concrete bytes, with the
same 300-byte size. No dsi compiler or flag set does this; 1.1p1 and 1.2..1.6sp2 all sit at
133. The remaining 42 bytes are one redundant instruction:

    +00FC  image `mov r0, r7`            | ours `mov r0, r8`
    +0100  image `str r5, [r1, r4]`      | ours `str r5, [r1, r4]`
    +0104  image `ldr r1, [r8, r4]`      | ours `ldr r1, [r0, r4]`
    +0108  image `bl #0x219d158`         | ours `mov r0, r7`
    +010C  image `mov r0, r7`            | ours `bl #0x219d158`

i.e. mwcc forwards the keyString base through r0 instead of reading `[r8, r4]` directly,
which costs 4 bytes and shifts the 12-word pool from +0114 on. Eight tail spellings under
2.0/base (explicit struct members, element pointer in three positions, call-before-store, a
`char *` keyString local, an all-element-pointer body) gave 42/50/55/103/131/140/147 - 42 is
the floor with this source shape. This is the one row where a future lane should start from
`--cc 2.0/base`, and the only row of the eight whose header pin is now known to be wrong.

## Rule 1/2 conformance repair (0x02164D74, WCM_InitEx)

The parked `symbols:` block wrote bare hex addresses (`OS_DisableInterrupts 02087988 arm`).
`SYMBOL_RE` requires `0x`, so the regex failed on the first line and `read_header` dropped
the *whole* block (`symbols_lines` empty, `declared_symbols` empty) - the one ABS32 stayed
wildcarded and the row could never be EXACT. With `0x` addresses: 18 of 18 relocation sites
resolved, `g_021AA7D4` resolving as `sole-ref`, instruction residue unchanged at 18 bytes.
Fixed in the parked source; this is the only file in the slice with the defect (the other
seven parse 3..17 symbols).

## Pin sweep, per row (unchanged floors)

| address | function | bytes | verdict @1.1p1 -O4,p | best of 92 other configs |
|---|---|---|---|---|
| 0x0216CA04 | DWC_AddMatchKeyString | 300/300 | DIFF 133 | **2.0/base DIFF 42** |
| 0x02182414 | gsiXmlUtilParseName | 320/320 | DIFF 7 | DIFF 7 (identical) |
| 0x021986C4 | gt2StringToAddress | 328/324 | DIFF 189 (SIZE) | -O4,s 308/173 |
| 0x02164D74 | WCM_InitEx | 364/364 | DIFF 18 | DIFF 18 (identical) |
| 0x021894D8 | gpiSendData | 364/364 | DIFF 21 | DIFF 21 (identical) |
| 0x0219C5B8 | qr2_process_ip_verify | 364/364 | DIFF 46 | DIFF 46 (identical) |
| 0x0215C910 | CPS_Resolve | 380/380 | DIFF 24 | DIFF 24 (1.6sp1/2: 30) |
| 0x0215CB24 | SOCLi_StartupCPS | 388/380 | DIFF 162 (SIZE) | no config beats 162 |

No pin below 1.1p1 in the dsi tree moves any of the seven; the 1.2/2.0 trees only move
0216CA04. Flag variants (`-O4,s`, `-O4`, `-O3`, `-O2`, `-O1`, `-O0`, `-inline off`,
`-ipa function`) are all worse everywhere.

## Named residues (nothing promoted; all eight stay parked)

* **0x02182414** - 7 bytes, +0038..+0088, one register pair swapped: image `ldrsb r3, [sl, r0]`
  (the character) and `add r2, sl, r0` (`buffer + *pos`), ours `ldrsb r2, ...` / `add r3, ...`.
  10 spellings flat: `&buffer[*pos]`, named `char *` pointer local in three declaration
  positions, `int idx = *pos`, mLen-before-mData, guard split in two, `load via a pointer
  local`; a `char *` cast on the base re-colours the entry block (67).
* **0x021986C4** - 4 bytes (328 vs 324). One extra `mov r2, #0`: the image reuses the live
  `srcIP = 0` zero (r4) for the `GT2_ISDIGIT` clamp at +0084 (`movhs r0, r4`), ours
  materialises a fresh zero in the loop preheader (+0074) and `movhs r0, r2`; that also pushes
  `check` from r2 to r3 and takes `host = 0` / `stackHost[len] = 0` off r5 onto r4. Residue is
  "the clamp's zero is not textually the `srcIP = 0` value".
* **0x02164D74** - 18 bytes, +0018..+0028, a six-instruction schedule rotation at the same
  364 bytes: image `ldr sb, [pc, #0x148]` / `mov r1, #0` / `ldr r2, [sb, #4]` / `mov r5, r0` /
  `str r1, [sp]`, ours `mov r1, #0` / `ldr sb` / `str r1, [sp]` / `ldr r2, [sb, #4]` /
  `mov r5, r0`. The image loads the pool word first and sinks expectLen's spill below the wcmw
  load; ours spills immediately. `long expectLen = 0;` as a declaration initialiser is much
  worse (396/345), as is putting `expectLen` before `OS_DisableInterrupts` (396) or both as
  initialisers (400).
* **0x021894D8** - 21 bytes at +0118..+0138, cap already named:
  `a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer`. Pin sweep adds
  nothing.
* **0x0219C5B8** - 46 bytes: the two loop-carried counters swap. Image r5 = `i`, r0 =
  `numDuplicates`, and the image's `numDuplicates = 0` is a *copy* of i's zero
  (`mov r0, r5` at +0024, ahead of `firstFreeIndex = -1` at +002C); ours has i in r0 and
  `mov r0, r5` displaced to +004C (+0058 `addeq r2, sl, r5, lsl #4` vs `r0`; +0070 `add r5` vs
  `add r0`; +0088 `addeq r0, r0, #1` vs `r5`). 13 spellings (empty for-header init,
  `numDuplicates = i` as statement and as declaration initialiser, `numDuplicates` after the
  `func_0217F264()` call, `firstFreeIndex = -1` as a declaration initialiser) leave 46 as the
  floor; the empty for-init alone moves the zero to +0008 and costs 53.
* **0x0215C910** - 24 bytes, the two schedule swaps in the id set-up already named in its
  blocker. Pin sweep flat; no new spelling spent.
* **0x0215CB24** - 162 bytes / 388 vs 380: this is the allocator wall of the slice, already
  named in three parts (+0x60 lan_buf select, +0xA8 register trio, +0xDC predication
  threshold). No configuration in 92 moves it.

## Late round (12:50-13:20) — no further movement

* 0x0216CA04 under 2.0/base: an `unsigned int` index and dropping the index local entirely both
  keep 304/42; `int index = keyID - 0x64;` as a declaration initialiser re-colours the entry
  block (300/173), the call-before-store order gives 50, and taking the *address* of the
  keyString field at the call is much worse (304/137). 42 stands.
* 0x02182414: `isdigit(c) || !isalnum(c)` (test order swapped) costs 11; storing mData/mLen
  before the char load, or loading the char twice, re-colours the block (324/217, 332/221,
  324/212). 7 stands.

## Files

* `src/pending/ov_sdk/ov009_func_{0216CA04,02182414,021986C4,02164D74,021894D8,0219C5B8,0215C910,0215CB24}.c`
  - header notes only, plus the 02164D74 symbols-block repair. No body edits: nothing
    measured reached EXACT, so no source moved to `src/matched/`.
* `scratch/a2/laneT5/` - `pin_sweep.py`/`pin_sweep.txt`/`pin_sweep.json`, `sweep_*.txt|json`,
  `gen_*.py`, `v0216CA04/`, `v02182414/`, `v0219C5B8{,b}/`, `v02164D74/`, `vrun.py`,
  `annotate.py`, `d_*.txt`.
