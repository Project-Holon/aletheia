# Lane T26: ov016 open SDK rows 17-25 (libdwcutil), 1 of 9 EXACT

Slice: `python scratch/a2/open_rows.py ov016 17 9` — the nine open ov016 libdwcutil rows
0x021D1868 .. 0x021BE844, smallest first. Every row was measured under its own pin/ISA/lang from
its parked header (`--lang c99`), never swept (rule 4). One row closed.

## Filed EXACT

| address | bytes | symbol | pin | shard |
|---|---|---|---|---|
| 0x021D1868 | 396 | func_021D1868 (window.o) | dsi/1.1p1, arm, c99 | pkt_ov016_021D1868 |

`src/matched/ov_sdk/ov016_func_021D1868.c`. The whole function was byte-identical except the
sixteen instructions from +0128 to +0150 — pure reordering plus one register pairing:

```
  +0128 image ldr r4, [pc, #0x44]     | ours lsl r5, r0, #2
  +0134 image ldr r2, [pc, #0x4c]     | ours ldr r2, [pc, #0x38]
  +0138 image ldrh r0, [r4, r5]       | ours cmp r3, #0xc0
  +0144 image add r4, sp, #4          | ours movgt r3, #0xc0
  +014c image add r2, r0, r2          | ours ldrh r2, [r2, r5]
```

The two screen-x lookups of the tail call

```c
func_021D5FF4(g_021DA9FE[g_021DE658->type].x, y0,
              g_021DA9FE[g_021DE658->type].x + g_021DAA16[g_021DE658->type][0], y1, &r);
```

are written inline in the parked draft, and 1.1p1 then issues the `&r` add and the `y1` clamp `cmp`
*ahead* of the pair of `ldrh`, and pairs each pool load with its own `ldrh` (base, use, base, use).
Hoisting both lookups into named locals **before** the clamp statement

```c
    u16 x1, x2;
    ...
    x1 = g_021DA9FE[g_021DE658->type].x;
    x2 = g_021DAA16[g_021DE658->type][0];
    if (y1 > 0xc0)
        y1 = 0xc0;
    func_021D5FF4(x1, y0, x1 + x2, y1, &r);
```

gives image order exactly: both bases pooled first, both `ldrh` together, the clamp `cmp` after them,
the `&r` add sunk to just before its store. See
`docs/idioms/a-data-pair-load-hoisted-into-locals-before-a-clamp.md`.
Measured: inline = 32 concrete bytes off; a block-scoped `{ u16 x1... }` = 32; a single `u16` local
used for arg1 only = 400 bytes (SIZE); the named-pair form above = EXACT.

## Parked, one line each (first differing instruction: image | ours)

| address | bytes (ours/image) | first divergence | named residue |
|---|---|---|---|
| 0x021C687C `input` | 404/400 | `+0004 ldr r5, [pc, #0x178]` \| `ldr r5, [pc, #0x17c]` | switch **dispatch order** only: image tests the 0x80..0x83 cluster first and 0 last (structurally `+0010 cmp r4, #0x83` \| `cmp r4, #0`), every case body byte-identical. Re-measured: case labels reordered, `case 19` moved first, `case 18`/`case 19` given separate breaks, `case 19: ;` — all 404/400 and the same 318 bytes. Not a source shape on 1.1p1. |
| 0x021B87F0 `AOSSi_WLANConnect` | 464/464 (6 B) | `+00EA movs r4, r5` \| `lsls r6, r6, #2` | thumb, pin ../2.0/sp1p2. Two residues: (1) the **case-19 halfword** of the 20-entry switch table at +00B4 (image 0x2C = the case-18 arm's tail `b` at +00F2; ours 0xB6 = the shared loop-end label at +017C, i.e. ours threads the jump); (2) the **empty `ssidLength` loop** +0116..+0120 is the same five instructions with r0/r1 swapped (`ldr r1,[pc]`/`movs r0,#0`/`ldrh r1,[r1,#0xa]`/`adds r0,r0,#1`/`cmp r0,r1` vs the mirror). Re-measured: `for`/`while`/`do`-guard/`?1:0`-with-`!=0`/reversed `>` compare, case 19 first, separate breaks, `i` as `u32`/`unsigned`/`long`/`u16`/`short` — every one 6 bytes (u32/unsigned/unsigned-long 7). Both residues are table/label and register tie-breaks below the source text. |
| 0x021C84BC `initGraphics` | 508/508 (38 B) | `+0144 ldr r2, [r5, #8]` \| `ldr r1, [r5, #8]` | the last six BGxCNT priority writes: image pools 0x04001008 in **r1**, keeps MemSsl in r2, forms 0x04000008 as `r1 - 0x1000` at +0170 (just before use) and 0x0400000A as `r4 - 2`; ours pools into r2, swaps r1/r2 and hoists the `sub` to +0154. Already measured by the earlier lane: six static-inline setters, plain volatile macros, non-volatile registers, a pointer walked over the registers, and permuter seed 9204 (400) — all 17 lines / 38 bytes. Re-measured here: direct volatile stores, a negative-index pointer off the 0x04001008 base (`db[-0x800]`), a `char*`-base pointer-arith spelling, a named `MEMSSL *m` before the pltt[1] store, and const `db` pointer scoping — 38, 45, 152, 230, 38. Residue is a register-allocation tie-break. |
| 0x021C2610 `drawInfo` | 504/528 | `+0028 add sl, sp, #0x1a` \| `add sb, sp, #0x1a` | callee-saved colouring: image holds `&buf` in r8, `&tmpbuf` in sl and the literal 20 in sb; ours rematerialises `&buf` into r4 (shared with `id`) and puts `&tmpbuf` in sb / 20 in r8. 24 bytes of extra frame traffic follow. Parked (header documents it; needs the original declaration/use order of the two char buffers, which the object does not expose). |
| 0x021C1210 `taskFramework` | 596/632 | `+0014 ldr r6, [pc, #0x254]` \| `ldr r6, [pc, #0x234]` | switch **lowering**, not body: image is a 0..20 jump table plus a decision tree for 23/26/29/34; dsi/1.1p1 cuts the table at 29 (`+0068 cmp r0, #0x1a` \| `cmp r0, #0x14`) or emits a pure compare chain. Parked. |
| 0x021C9A94 `isPush` | 620/636 | `+0008 ldr r0, [pc, #0x258]` \| `ldr r0, [pc, #0x248]` | the AREA struct copies: image schedules each 8-byte copy in 4-byte units (`ldrh l`/`ldrh t`/`strh`/`strh`, then `w`/`h`), ours loads all four fields and then stores all four, and r6/r7 (the 0x1d literal vs the loop counter) are swapped from the first block on. Re-measured here: AREA re-declared as a nested `{l,t}{w,h}` pair struct (the 4-byte-unit shape) — identical 409 bytes. Permuter seed 9202 was already flat. |
| 0x021C00A8 `disp` | 624/640 | `+0008 ldr r3, [pc, #0x24c]` \| `ldr r4, [pc, #0x240]` | prologue only: the three 5-byte initialiser copies and `line * 3` are interleaved in the image, copied in order by 1.1p1, offsetting the whole body. Same residue as keyboard.o's disp (0x021BE844); keyboard10.o's `N_KEY`/`N_SKEY`/`N_BTN` are already cast-copied `KB_N5` struct assignments. Parked. |
| 0x021BE844 `disp` | 652/656 | `+0004 sub sp, sp, #0x18` \| `sub sp, sp, #0x20` | the same prologue: image loads `N_KEY[4]` first and interleaves the fifteen byte copies with the `line * 12` setup in a 0x18 frame (one spill slot); ours copies in order and needs 0x20, so 465 bytes shift. Struct locals and cast-copied `u8[5]` arrays measure identically; permuter seed 9803 flat. Parked. |

## What was tried and what was paid for

* Every park above was re-measured on **its own pin** first, then given at most two or three body-shape
  spellings from `docs/idioms/` (struct-assignment framing, pointer arith, `long`/`u32` index colouring,
  loop-form, case order, named locals). No pin or flag was swept.
* The one that paid was the named-local hoist of a *data pair* whose two loads the image issues together
  before a clamp guard — the same family as
  `docs/idioms/a-constant-pair-pools-the-one-used-first-and-only-pointer-math-defeats-the-fold.md`,
  one level up (loads, not constants).
* The seven parked rows are the "two registers swapped / label threaded differently / table entry points
  at a tail `b`" class that `docs/idioms/a-materialised-shift-temporary-is-not-reachable-from-c-or-from-flags.md`
  describes: for each of them the instruction *multiset* is already right and only the allocator's
  tie-break (or the switch lowerer) differs. Permuter runs already recorded against four of them
  (9202, 9204, 9803, 11102) are flat.

Lane budget: ~85 min wall clock, ~50 compiles.
