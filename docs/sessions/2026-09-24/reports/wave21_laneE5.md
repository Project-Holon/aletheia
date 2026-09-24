# Wave 21, lane E5: blink_palanm 0x0202E1F0

Every verdict below comes from `tools/match.py one --diff` (dsi/1.1p1, -O4,p, Thumb). About 135 compiles,
all written by hand. The permuter was not used. Scratch files are in `/tmp/aletheia_laneE5`.

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, section "wave 21 (lane E5)" |

The residue is unchanged. At +008E the image passes w from its register (`adds r0, r7, #0`), and the
compile rematerialises it as `add r0, sp, #0x38`. This is the reverse of how the task described it, and it
matters: making &ws a rematerialisable constant at that site reproduces the residue rather than fixing it.

## The three directions

- **(a) Another expression for the argument** (`&ws[0]`, a struct ws, `ws[1]`, an entry-block temporary,
  `(u8 *)marks - 8`):
  - every constant spelling gives the same 2 bytes out, with o=r6;
  - the marks-relative forms emit `add`/`subs` (263 out);
  - every spelling that goes through w gives 21, with o=r7.
- **(b) ws inside a struct with marks**, in both member orders: 416 bytes. The initialiser changes the frame
  code, and the o/w order does not move.
- **(c) Inline helpers:**
  - a helper parameter that receives w is copy-propagated (21/37);
  - one that receives ws is folded to the constant (2, or 314 when loop 1 is inside the helper);
  - a helper that returns ws for B0 folds all of w (374).

  An inline parameter never reaches costing as a web of its own.

## What the measurements show

1. **Neither live-range length nor interference degree affects the priority.** Up to 20 extra calls and
   two extra temporaries in o's range left o in r6.
2. **The entry use of w counts.** A second use of w's entry value makes w win.
3. **The free B0 uses come from extended-basic-block value numbering.** A branch between the def and the
   uses makes them count. Constants after that branch are rematerialised. The knowledge from B0 also
   reaches a successor block that has only one predecessor.
4. **Base is an exact tie that o wins.** With one w use and one o use added, o still wins. One conditional
   o use outside the loops is enough to flip s21.

## The new near-lever: cross-jumping

This shape moves o and w into the image's registers:

- the loop-1 guard is written as `if (n > 0) { do-while; T } else { T }`;
- T is the g call plus the first `func_02043B5C(func_02045770(o->f00), c2)` line.

With it, o is r6, w is r7, the g call is `adds r0, r7, #0`, and every register matches the image. How it
works:

- The else copy's `ldr r0, [r6]` adds one o unit to the costing.
- The else copy's w use is free, by the extended-basic-block rule above.
- The two copies are cross-jumped after allocation.

Cross-jumping runs after branch threading, so the replaced copy stays behind as a `b` to the next
instruction at +008A. The size stays 412 only because the `mov r8, r8` pad disappears, and every byte after
+008A is shifted (264 out).

This cannot reach 0 bytes out. The image's g block has exactly two predecessors: B0's `ble`, which goes
straight to +008A, and the loop fall-through. Neither path can carry a second copy of T without leaving a
hop.

Every variant (whole g block, g call alone, inverted arms, a copy after the return, the tail after loop 2)
is in the notes with its bytes out and o/w registers.

## Files touched

- `docs/notes/pkt_0202E1F0.c.txt` (section "wave 21 (lane E5)" appended)
- `docs/sessions/2026-09-24/reports/wave21_laneE5.md` (this file)

No source was filed to `src/matched/` or `src/pending/`, and no shard was written, because there is no EXACT
or MATCH result. `tools/`, `layout/` and 0x0206DC00 were not touched. No other decompilation or
reconstruction was consulted.
