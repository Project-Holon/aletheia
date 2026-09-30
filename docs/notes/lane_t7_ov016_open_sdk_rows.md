# Lane T7: ov016 open SDK rows 9-16 (libdwcutil, smallest first)

Slice: `python scratch/a2/open_rows.py ov016 9 8`. Rows 9-16 by size: 021D0CEC 220,
021BC63C 232, 021CBDF8 264, 021D657C 272, 021CC0E8 288, 021CFCC8 336, 021D0E74 344,
021D5A58 360 (the catalog sizes; the listing extent is one power-of-two block behind or
ahead on four of them). **0 of 8 reach EXACT.** Nothing filed to `src/matched/ov_sdk/`.

All eight were re-measured on their own region/ISA/pin with `--lang c99`. The parked
sources are unchanged apart from one deliberate negative experiment (021BC63C's
duplicate-store variant, below). Levers tried per row are listed; every one of the
eight is flat at its first divergence.

Note on the compiler axis: for 8 rows I ran 18 pins x 9 flag sets (**1,368 compiles**)
under the old "sweep first" rule. It produced no EXACT and no row ever improved past its
baseline pin; the project's recorded measurement (24 trees x 11 flag sets, plus a
5,184-configuration run, zero matches) is confirmed. Two incidental samples below
(021D0E74 at `../2.0/base`, 021D657C at `-O2`) are noted because they are *different
shapes*, not because they are better.

## Row 9 — func_021D0CEC 0x021D0CEC (ARM, 220 B, DIFF 2 bytes)

`ldr r1, [r0, #0xb90]` | `ldr r0, [r0, #0xb90]` at +0094, and the `cmp` at +0098 with it.
Size-exact 220/220, 9/9 relocations, no wildcard. This is the guard-load folding into its
dying base register; the parked header already records 28 spellings and a full compiler
cross-product, and the class is written up as unreachable from C in
`docs/idioms/a-guard-load-that-folds-into-its-dying-base-register-is-not-a-source-shape.md`
(the 220-byte body has exactly one use of `g_021DE654` before the `func_021D7744(0)` call
that forces the reload). **Parked: not a source shape.**

## Row 10 — func_021BC63C 0x021BC63C (Thumb, 232 B, DIFF 70 bytes with the S8 fix)

Pin `../2.0/sp1p2`. Cross-checked lane S8's finding: the two spurious duplicate stores
(`BSS.gAtermNotify = notify; BSS.gAtermAlloc = alloc;` repeated after
`BSS.gAtermApState = 7;`) are exactly the +4 bytes; dropping them gives **232 B / 70
concrete diffs / 11 of 11 relocations, size-exact**, reproducing S8's number.
(Measuring without the real `string.h` include gives 220 B — the header include is load
bearing, do not inline a `memset` prototype.)

New lever tried, per S8's "make the literal 7 live past the call": a local
`int st = 7;` with the state store and both error returns written as `st - 8` / `st - 16`
(three spellings: `st` declared then assigned, `int st = 7;`, and re-reading
`BSS.gAtermApState`). All three still give 70 diffs: mwcc constant-folds the single
assignment to `7` and re-materialises `-1`/`-9` as `movs #0; mvns` / `movs #8; mvns`.
Re-reading the global instead gives 77 diffs (adds a reload). The image's `adds r0, r6, #0;
subs r0, #8` needs `7` to survive the `func_021B97A8` call in r6, and no spelling tried
makes the front end keep it. **Parked: register-allocation shape; the 7-in-r6 live range
is the only remaining difference and it is not reachable by re-spelling the error codes.**

## Row 11 — func_021CBDF8 0x021CBDF8 (ARM, 264 B, DIFF 11 bytes)

Size-exact 264/264, 10/10 relocations. Three instructions, one root cause — the position
of `lsl r2, r3, #2` relative to the cell store:

```
* +0050  lsl r2, r3, #2        | add r1, r1, sl, lsl #2
* +0054  add r1, r1, sl, lsl #2 | str r0, [r1, #0x10]
* +0058  str r0, [r1, #0x10]   | lsl r2, r3, #2
```

Tried and flat (all 264 B / 11 diffs): `j` block-scoped; `unsigned int j`; no `j` at all
(that one drops to 256 B and is worse); the store as a chained assignment inside
`func_021D5118`'s first argument; the call result through a `void *c` temp. The `lsl` is
`j * 4` for `g_021DA72C[j].x`; the image fills the `ldr r1, [r4, #4]` shadow with it and
ours fills the same slot with the dependent `add`. **Parked: list-scheduler tie between
two independent nodes; no statement order or declaration order in the block moves it.**

## Row 12 — func_021D657C 0x021D657C (ARM, 272 B, DIFF 169 bytes, 1 wildcard)

280 compiled vs 272 extent, 1 of 2 relocations resolved. The whole residue is one
register-allocation shift (`r4`=fold pointer / `ip`=bit / `r3`=i in the image; `lr`=fold
pointer / `r2`=i / `r3`=bit here); lane S8 measured it, `-O2` only re-orders it (149 diffs,
still 280 B).

The unresolved site is worth recording because it is a *consequence*, not a cause: the
pool word `ABS32 g_021DE690` lands at +010C in the image (0x021D6688, the last word of the
272-byte body) and at +0114 in our 280-byte compile. `sole-ref/self` compares the ROM word
at the site with the word about to be written; at +0114 that word belongs to the next
function (`sub sp, sp, #8`), so the site stays wildcarded. Once the body is 272 bytes the
site resolves by itself. The bytes at 0x021DE688/0x021DE690 are *not* duplicated anywhere
else in ov016 (`_overlay_start_attested` finds a single referrer, this function's own pool
word), so this is not the vendor-template / two-identical-copies case and there is no
named second symbol to declare. **Parked: same register-naming class as S8 recorded; the
wildcard disappears with the size, not with a data-symbol lever.**

Also confirmed from the image here: the `mov r1, r3` before the loop label with
`strbeq r1, [r0, r3]` inside it is `g_021DE690[i] = 0` — the parked source already has it
(see `docs/idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md`).

## Row 13 — button 0x021CC0E8 (ARM, 288 B, DIFF 8 bytes)

Size-exact 288/288, 23/23 relocations. Two instructions, one root cause, inside the
`DWCi_WINlInitEx(0x46, 0, 1, lang, idx + 1)` argument setup:

```
* +00B8  add ip, r5, #1   | mov r2, r4        <- idx + 1 (the 5th argument)
* +00BC  ldrsb r3, [r1,r0]| ldrsb r3, [r1,r0] <- lang, in the same slot in both
* +00C0  mov r2, r4       | add ip, r5, #1    <- dark = 1 (the 3rd argument)
```

Six spellings, all 288 B / 8 diffs: count pre-computed into a local before and after the
`lang` statement; `idx++` then pass `idx`; the table read inline in the call; `1 + idx`;
`(int)1` for `dark`; block-scoped `lang`. mwcc evaluates the arguments right to left in
the image (`idx+1`, then the `ldrsb`, then `dark`) and left to right in ours; the two
independent nodes sit on either side of the same pool-load shadow and the scheduler breaks
the tie the other way. **Parked: scheduler tie on two independent argument materialisations;
`mov r2, r4` reusing the `r4 = 1` from the earlier `state = 1` store is what makes it
invisible to any local-binding change.**

## Row 14 — write 0x021CFCC8 (ARM, 336 B, DIFF 9 bytes)

Size-exact 336/336, 6/6 relocations. Three instructions: the spill of the allocator result
is one slot late.

```
* +012C  str r2, [sp]    | ldr r0, [r6]       <- work = DWCi_HEAPlAllocEx(...)
* +0130  ldr r0, [r6]    | add r1, sp, #4     <- &MemSet->map
* +0134  add r1, sp, #4  | str r2, [sp]       <- &w
```

An independent store and an independent load; the scheduler has the store first in the
image and the load first here. Tried: the assignment folded into the argument
(`DWci_BACKUPlWritePage(&MemSet->map, w, work = DWCi_HEAPlAllocEx(0x100, 32))`), and the
declaration moved to a mid-block initialiser next to the call. Both 336 B / 9 diffs. The
parked header already records a permuter run (seed 10701) and a `static MemSet` spelling,
both flat. **Parked: scheduler tie; the idiom
`an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register` does not
apply because the value here is spilled, not held.**

## Row 15 — func_021D0E74 0x021D0E74 (ARM, 344 B, DIFF 286 bytes)

332 vs 344 at `1.1p1`. The image spills the parameter (`str r0, [sp]` at +0004, reloaded
per field) and puts the outer counter in `fp`; ours keeps `prm` in `fp` and the counter in
`r7`/`r8`, so every register in the body takes a different colour and the whole tail is
rescheduled. Same class as row 12.

The one genuinely different build sample on this row: `../2.0/base -O4,p` produces **344 B
(size-exact)** but 222 diffs — still the same first divergence (`str r0, [sp]` | `mov fp,
r0`), i.e. it is the same source shape at a size-correct front end, not a different one. No
2.0 tree reaches EXACT. **Parked: parameter-spill/register-pressure shape; forcing the
spill needs one more live value across the loop, which no spelling of this body provides.**

## Row 16 — func_021D5A58 0x021D5A58 (ARM, 360 B, DIFF 33 bytes)

Size-exact 360/360, 12/12 relocations. Two clusters: the three stores at +00AC..+00B4
(`cv->self` / `cv->font` order and the `g_021DE680 + font*8` add) and the arg setup at
+00D0..+00E8 for the eight-argument `func_02069078` (the `g_021DAA70[lcd]` load vs the two
stack stores). Swapping the source's `cv->font = ...; cv->self = cv;` to the image's store
order moves the divergence 12 bytes earlier and is worse, so the current order is the
better one; the residue is the compiler's own interleave of two independent clusters.
**Parked: intra-block scheduling; both clusters are correct and only their interleave
differs.**

## Files

- Parked sources untouched: `src/pending/ov_sdk/ov016_func_021{D0CEC,BC63C,CBDF8,D657C,CC0E8,CFCC8,D0E74,5A58}.c`
  (021CFCC8's file is the one whose header names `write`; the C symbol is `write`, so
  `--func write` is required).
- No shard written: no row reached EXACT, so there is nothing to file.
- Evidence: `scratch/a2/laneT7/` — `out_<ADDR>.txt` (baseline diff per row),
  `v_*.txt` (variant diffs), `sw_<ADDR>.json` (the pin/flag samples),
  `one.py` / `run.py` / `sweep.py` (harness wrappers).
