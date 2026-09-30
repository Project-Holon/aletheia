# Lane T16: ov016 open SDK rows 17-25 (libdwcutil), measured

Slice `python scratch/a2/open_rows.py ov016 17 9` = 9 rows, 4,676 bytes. Every row had a parked
source in `src/pending/ov_sdk/` and every one is a DIFF (0 filed; no shard written). All measurements
are `tools/match.py one ... --lang c99 --diff` with each row's own region/ISA/pin; per-row two-column
diffs are in `scratch/t16/ov016_<ADDR>.txt`, candidates in `scratch/t16/*.c`.

| # | address | name | bytes image/ours | concrete diffs | first divergence (`image` \| `ours`) |
|---|---|---|---|---|---|
|17| 0x021D0B44 | DWCi_USBAPlBegin | 372/372 | 4 | `+002C ldr r3, [r5]` \| `ldr r4, [r5]` |
|18| 0x021D1868 | disp | 396/396 | 10 | `+0128 ldr r4, [pc, #0x44]` \| `lsl r5, r0, #2` |
|19| 0x021C687C | input | 400/404 | 98 | `+0010 cmp r4, #0x83` \| `cmp r4, #0` |
|20| 0x021B87F0 | AOSSi_WLANConnect | 464/464 | **4** (was 6) | `+00EA movs r4, r5` \| `lsls r6, r6, #2` |
|21| 0x021C84BC | initGraphics | 508/508 | 17 | `+0144 ldr r2, [r5, #8]` \| `ldr r1, [r5, #8]` |
|22| 0x021C2610 | drawInfo | 528/504 | 48 | `+0028 add sl, sp, #0x1a` \| `add sb, sp, #0x1a` |
|23| 0x021C1210 | taskFramework | 632/596 | 120 | `+0068 cmp r0, #0x1a` \| `cmp r0, #0x14` |
|24| 0x021C9A94 | isPush | 636/620 | 127 | `+0008 ldr r0, [pc, #0x258]` \| `ldr r0, [pc, #0x248]` |
|25| 0x021C00A8 | disp | 640/624 | 148 | `+0008 ldr r3, [pc, #0x24c]` \| `ldr r4, [pc, #0x240]` |

Rows 21-25 are the byte-pair/stack-buffer prologue and switch-dispatch classes already documented by
O62 (`docs/notes/ov016_o62_big_lane.c.txt`) and S8; their residues are reproduced here, not reworked.

## Closed measurement: 0x021B87F0 AOSSi_WLANConnect, 6 → 4 concrete diffs (still DIFF)

Parked source is 464/464 bytes with 22/22 relocations resolved, and the residue is two spots:

* **(a) one jump-table halfword (compiler label choice, source-invariant).** The msg switch table at
  `0x21B88B4` (20 halfwords, entry i at `0x21B88B4+2i`, targets relative to `0x21B88B6` — confirmed
  against `asm/overlays/ov016.s`). Entry 19: image `0x002C` → `0x21B88E2`, the `b` that ends case 18's
  block; ours `0x00B6` → `0x21B896C` (the loop test), i.e. ours folded `case 19: break;` with the
  `case 4:/case 8: break;` exit instead of reusing case 18's break branch. Both are semantically the
  same no-op; nothing in C moves it — **six case-18/19 spellings** (fallthrough, explicit `break;`,
  source-order swap, a nested `switch (wep_id)`, a `;` body) all compile **byte-identical** to the
  parked body, and all 10 pins under 2.0 give the same 464 B/4 diffs (`dsi/*` pins give 448 B/200
  diffs). Parked: compiler-internal label placement.
* **(b) the empty `ssidLength` loop, two instructions (register assignment + schedule).**
  image `+0116 ldr r1,[pc,#0xb4]` / `+0118 movs r0,#0` / `+011A ldrh r1,[r1,#0xa]`;
  parked source ours `ldr r0,[pc]` / `movs r1,#0` / `ldrh r0,[r0,#0xa]` (right order, index in r1).
  **Lever that works (6 → 4):** hoist the bound into a signed local before the loop —
  `int n = g_021DCE60_b.ssidLength; i = 0; for (; (i < n) ? 1 : 0; i++) ;`
  (`scratch/t16/cc_x1.c`) — the index then lands in r0 and the bound in r1 and the compare is `blt`
  again. `u32`/`u16 n` is wrong: the compare becomes unsigned (`blo`, 6 diffs). What is left is that
  ours schedules `ldrh` before `movs r0,#0` while the image emits the init first; only the post-
  increment spelling survives -O4,p dead-loop elimination, so this is a reconstructed loop.
  **Sweeps:** 10 pins × 2.0 (byte-identical), 3 extra flag sets (`-O4,p -inline off|all`,
  `-O4,p -ipa function`) inert; `-O4,s` changes everything (excluded level bias).

## Closed measurement: 0x021D0B44 DWCi_USBAPlBegin, 4 concrete diffs (still DIFF)

372/372 with 16/16 relocations; the whole residue is one statement pair:

```
tick = OS_GetTick();
g_021DE654->start = tick;
rs = WM_Initialize(g_021DE654, func_021D0DE0, 3);
```

image: `ldr r3,[r5]` / `add r3,r3,#0x1000` / two stores / **`ldr r0,[r5]`** / `ldr r1,[pc]`
ours:  `ldr r4,[r5]` / `add r3,r4,#0x1000` / two stores / `mov r0,r4` / `ldr r1,[pc]`

The image derives the store base in place in r3 and **re-reads the global** for the next statement;
1.1p1 keeps the loaded pointer live in r4 and CSEs the second read across the intervening stores.
This is the same alias question O62 note 3 names (`func_021C5FA8`), reached where the *reload* is what
the image does and ours is the CSE. Spellings tried, all 4 diffs or worse (no change in the reload):
volatile global pointer (392 B/90), `*(u64 *)((u8 *)g + 0x1b88) = tick;` (identical 4), `u64 *` local
(identical 4), block-scoped pointer copy (identical 4), `g->start = OS_GetTick();` direct (8),
an extra call between the statements (384 B/86), and **8 pins** (every `dsi/*` 372 B/4; `2.0/sp1p2`
392 B/86). Parked: allocator choice — the lever left is a store that the compiler cannot prove
disjoint from `g_021DE654`, which the object does not expose.

## The other seven rows, one line each

* **0x021D1868 disp** 396/396, 15/15 relocs, 10 diffs from `+0128`: in the tail
  `func_021D5FF4(g_021DA9FE[type].x, y0, ... + g_021DAA16[type][0], y1, &r)` the image hoists the
  `&g_021DA9FE` pool load into r4 before the `type*4` shift and keeps both table pointers live
  (r4/r2); ours materialises `&r` into r4 first (`add r4, sp, #4`) and reuses r2 for both tables, so
  the two `ldrh`s and the `cmp/movgt` interleave differently. Allocation/scheduling; 5 dsi pins and 4
  tail spellings (hoisted `x0`/`w` locals, a `RectT *pr = &r;` local, a re-wrapped argument list) all
  byte-identical at 10 diffs, no EXACT.
* **0x021C687C input** 400/404 (+4 B), 98 diffs from `+0010`: switch dispatch order — the image tests
  the 0x80..0x83 cluster first, 1.1p1 tests case 0 first. Parked in the source header; every case body
  is byte-identical.
* **0x021C84BC initGraphics** 508/508, 26/26 relocs, 17 diffs from `+0144`: only the last six display
  writes. Image keeps the `0x04001008` literal in r1 and `MemSsl->back` in r2 and sinks
  `sub r2, r1, #0x1000` (deriving 0x04000008) to just before its use; ours swaps r1/r2 and hoists the
  `sub`. Parked (inline setters, macros, non-volatile registers, pointer walk, permuter 9204 flat).
* **0x021C2610 drawInfo** 528/504 (-24 B), 48 diffs from `+0028`: callee-saved allocation of the four
  frame buffers — image `&buf` in r8, `&tmpbuf` in sl, the literal 20 in sb; ours `&tmpbuf` in sb,
  20 in r8, `&buf` rematerialised into r4 (shared with id). Parked in the source header.
* **0x021C1210 taskFramework** 632/596 (-36 B), 7 relocs, 120 diffs from `+0068` (`cmp r0, #0x1a` |
  `cmp r0, #0x14`): switch lowering. The image (vendor stamp 4.0.0.1025) is a 0..20 jump table plus a
  decision tree for 23/26/29/34; 1.1p1 cuts the table at 29. Parked; dispatch only.
* **0x021C9A94 isPush** 636/620 (-16 B), 15/15 relocs, 127 diffs from `+0008`: the constant 0x1d in r7
  vs r6 shifts every pool offset by 0x10, and the 3-iteration AREA-copy tail is re-ordered (ours
  loads all four fields first and drops the dead store of `t`). Parked; permuter seed 9202 flat.
* **0x021C00A8 disp** 640/624 (-16 B), 9 relocs, 148 diffs from `+0008`: the keyboard.o prologue — the
  image keeps the string-table pointer in r3 and the first destination byte in sl, ours r4/r3, so the
  three 5-byte initialiser copies diverge; two pool words (@0x20862/64/66) also have no witness
  outside this function. Parked (docs/notes/pkt_ov016_021BF74C.c.txt).

## Reusable findings

1. **An empty-loop bound read from a struct member wants a hoisted signed local.** `int n = m->field;`
   before `for (i = 0; (i < n) ? 1 : 0; i++) ;` puts the index in r0 and the bound in r1 exactly as the
   image does; reading the member inline in the condition allocates them the other way round, and
   `u32`/`u16` for the local silently turns `blt` into `blo`.
2. **`case N: break;` reached by fallthrough is a jump-table halfword, and the table entry is not
   reachable from C.** When the image's entry for an empty case points at the *branch* that ends the
   previous case's block rather than at the shared exit, changing the case spelling (6 tried, including
   a nested switch) does not move it: the compiler's label-reuse choice is a function of the
   surrounding chain, not of the statement.
3. **A table entry can be verified from memory without trusting the disassembly of the table.** In a
   Thumb `adds r0,r0,r0; add r0,pc; ldrh r0,[r0,#k]; ... add pc,r0` dispatch, the table base is
   `(add r0,pc addr)+4+k`, the entry for key i sits at `base+2i`, and the target is
   `base+2+entry` — check two known cases against `loc_` labels in `asm/overlays/<region>.s` before
   concluding anything from the harness's own decode of a data run.
