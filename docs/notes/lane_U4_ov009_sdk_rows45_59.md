# Lane U4 — ov009 open SDK rows 45-59

Slice: `python scratch/a2/open_rows.py ov009 45 15` (fifteen parked SDK rows, ov009, ARM,
`-O4,p --lang c99`, pin `dsi/1.1p1`). Wall clock ~75 min, 45 compiles. No pin sweep, no flag
sweep (brief rule 4); one source lever found and applied (row 52).

Compiler stamps (from `tools/sdkobj.py`): rows 49, 50, 52, 59 are `4.0.0.1024` = our `dsi/1.1p1`;
rows 45, 46, 47, 48, 51, 53, 54, 55, 56, 57, 58 are `4.0.0.1025` (the TwlDWC stamp, no build of
ours). Every row's image bytes equal its vendor object's bytes exactly (`0 concrete mismatches`),
so the reference is the archive member in every case. The `4.0.0.1025` rows show a *systematic*
allocator difference (below), which is the single most useful result of this lane.

## Closed / improved

**0x0215BF88 `dhcp_analyze_response` — 65 → 41 concrete bytes, size exact (880).**
`src/pending/ov_sdk/ov009_func_0215BF88.c`, note rewritten in the file.

The vendor front end predicates the option-pointer bump into the `&&` chain
(`ldrbeq r0, [r5, #0xef]` / `addeq r3, r5, #0xf0` / `cmpeq r0, #0x63` / `bne`). This **is**
reachable from C: put the bump inside the condition as a comma expression, reading the same byte
off the new pointer —

```c
if (s[0xec] == 0x63 && s[0xed] == 0x82 && s[0xee] == 0x53 && (s += 0xf0, s[-1] == 0x63)) {
```

That swapped the unconditional `add ip, r5, #0xf0` for a predicated `addeq ip, r5, #0xf0` and took
the residue 65 → 41 bytes (34 sites). The earlier lane's "measured inert" list was measured on the
*old* shape, where the bump was the first statement of the block; with the bump in the condition
every mode spelling (`u32`/`int`, function scope / inner block / declaration initialiser) is
identically 41.

Residue, and it is one tie: the option pointer and the `mode` mask are mirrored one register apart.
Image `addeq r3, r5, #0xf0` (pointer r3) + `and ip, r0, #2` (mask ip) + the byte load off the OLD
base (`ldrb r0, [r5, #0xef]`, scheduled before the add); ours `addeq ip, r5, #0xf0` +
`ldrb r0, [ip, #-1]` (folded onto the new base) + `and r3, r0, #2`. All 34 sites follow from that
one swap. Measured worse: `(s += 0xf0)` alone (884 B), `(s += 0xf0) != 0 && ...` (888), trailing
`(s += 0xf0, 1)` (65 — reverts), `(s[-1] == 0x63, s += 0xf0)` (876, drops the predication), a named
`u8 *opt = s` mirror (65). Park.

## Parked, with residue

`first` is the first differing instruction pair, image | ours.

| # | address | name | lib | img/ours B | concrete | first divergence |
|---|---|---|---|---|---|---|
| 45 | 0x0219D5C4 | QEStartQuery | dwcgsserverbrowsing | 672/672 | 140 | `mov r5, r1` \| `mov r4, r1` |
| 46 | 0x02168AD4 | DWCi_FriendProcess | dwcmatch | 680/684 | 428 | `ldr r4, [pc, #0x28c]` \| `ldr sb, [pc, #0x290]` |
| 47 | 0x0217E504 | gsiLargeIntMultM | dwcgscommon | 704/704 | 184 | `mov r4, r2` \| `mov r7, r0` |
| 48 | 0x0218263C | gsiXmlUtilDecodeString | dwcgscommon | 720/720 | 70 | `mov r5, r1` \| `mov r4, r1` |
| 49 | 0x021679C0 | WcmWmcbReset | libwcm | 756/756 | 594 | `mov r5, #3` \| `bl #0x21657c8` |
| 50 | 0x02161C80 | parse_record_in_buf | libssl | 792/792 | 260 | `ldrb r3, [r5, #1]` \| `ldrb r0, [r5, #2]` |
| 51 | 0x0216F770 | DWCi_SBUpdateAsync | dwcmatch | 868/868 | 372 | `push {r3..lr}` \| `push {r0, r1, r2, r3}` |
| 53 | 0x0217D904 | gsiLargeIntDiv | dwcgscommon | 928/936 | 489 | `mov r5, r1` \| `mov r8, r1` |
| 54 | 0x02174FE8 | DWCi_NNCompletedCallback | dwcmatch | 1008/1000 | 713 | `mov r6, r0` \| `mov r7, r0` |
| 55 | 0x02198A0C | Think | dwcgsnatneg | 1128/1128 | 86 | `mov r3, #0xa` \| `mov sb, #0xa` |
| 56 | 0x0217E078 | gsLargeIntPowerMod | dwcgscommon | 1164/1092 | 401 | `sub r6, r1, #1` \| `sub r1, r1, #1` |
| 57 | 0x021602B8 | cert_item | libssl | 1196/1196 | 628 | `ldr r4, [fp]` \| `ldr r1, [fp]` |
| 58 | 0x0216C230 | DWCi_GT2ClosedProcess | dwcmatch | 1368/1368 | 326 | `bne #0x216c3b0` \| `bne #0x216c410` |
| 59 | 0x02159A80 | dt_ack | libcps | 1384/1384 | 820 | `str r0, [sp]` \| `mov fp, r0` |

Rows 52, 53, 54, 55, 56, 57, 58, 59 carry the residues recorded by lanes T23/T24 in
`docs/notes/lane_T23_ov009_sdk_rows56_63.md` and `docs/notes/ov009_T24.md`; this lane confirmed the
same numbers and did not re-grind them.

### The 4.0.0.1025 rows are one allocator signature, not fourteen unrelated bugs

Rows 45 and 48 are the clean statement of it. Both are **size-exact, instruction-for-instruction
identical to the image, and every one of their mismatch sites is a register rename** — the whole
callee-saved assignment is *shifted by one slot*, cyclically:

* 0x0219D5C4 (45): image = `{querySuccess→r4, server→r5, engine→r6, 0→r7, 0→r8, &queryBuffer→sb}`;
  ours = `{server→r4, engine→r5, 0→r6, 0→r7, &queryBuffer→r8, querySuccess→sb}` — ours rotated
  right by one. 78 sites, 140 bytes, all renames.
* 0x0218263C (48): image = `{readPos→r4, len→r5, buffer→r6}`; ours = `{len→r4, buffer→r5,
  readPos→r6}`. 45 sites, 70 bytes, all renames. The stack frame, the offsets and every immediate
  agree.

The same "the parameters take one register higher than ours and one local takes r4" shape is
visible in 47 (`mov r4, r2` before `mov r7, r0`), 53 (`mov r5, r1` vs `mov r8, r1`) and 54. Where
the two builds must agree on a *value* they do: the vendor emits `add r0, r4, #7` for `pos = 7`
because its copy of the constant 0 sits in r4, while ours rematerialises `mov r0, #7`.

Nothing in C moves this. On 45 I measured: the current order, full reverse, DWARF-print order,
DWARF-reverse order, `ip` first, and a two-block reorder — 140 bytes for the DWARF-consistent
orders, 148 for the others, never lower, and never a different shape. Removing the named `ip`
local (which the DWARF of the vendor object does not have) *changes the size* to 668 with 499
mismatches, i.e. worse. On 48 the previous lane had already tried declaration order, block-scope
order, loop spelling and compilers 1.2–1.3p1. Both rows are the `4.0.0.1025` front end, which we
do not have a build of: park, and treat the other `4.0.0.1025` rows in this slice as the same
class until a body-level (not register-level) difference is shown in one of them.

### Row 46 — the one size gap that looks fixable

`680 vendor / 684 ours` (row 46, `4.0.0.1025`). The extra four bytes are in the pool-base
selection: image `ldr r4, [pc, #0x28c]` + `ldr r0, [r4, #0xc]`, ours `ldr sb, [pc, #0x290]` +
`ldr r0, [sb, #0xc]` — the global base goes to a callee-saved register in ours, which costs one
push and four bytes of frame. Same class as row 47's `g_021A826C` note ("writing the field inline
drops the whole allocation"): worth one lane, not chased here for budget.

### Rows 47 / 50 / 49 — real scheduling differences, not colouring

* 0x0217E504 (47): image hoists `logB_r = m->mLength` (`ldr r1, [r4]`) *above* the `temp[128] = {0}`
  zeroing loop and stores it to `[sp, #0x10]` at +0028; ours computes it at +0054, after the loop.
  Our declaration order already matches DWARF exactly (DWARF prints `logB_r … tempLen`, the reverse
  of the source), so this is the front end's sink. Inner-loop colouring follows.
* 0x02161C80 (50): first divergence at +0124 in the handshake loop — the vendor's `sub`/`+4` temp
  pair is r8/r7 and the `((s[1]<<16) + (s[2]<<8)) + s[3]` accumulation is right-associated with the
  `<<16` term as the accumulator; ours is the mirror. Same two-register tie as row 52's residue.
* 0x021679C0 (49): ours emits the `bl WCMi_GetSystemWork` before the image's `mov r5, #3`
  (a hoisted constant), and the whole function then runs one instruction behind for 594 bytes.

### Row 51 — a home-area push we should not have

`0x0216F770`: ours opens `push {r0, r1, r2, r3}` *in front of* the real
`push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` / `sub sp, #0x2e0`; the image has no home area. See
`docs/idioms/a-home-area-push-hides-the-real-function-start-one-word-early.md`. Ours takes the
address of a register parameter (or is compiled as variadic); the vendor takes neither. Not chased:
the body is 372 bytes of mismatch behind it.
