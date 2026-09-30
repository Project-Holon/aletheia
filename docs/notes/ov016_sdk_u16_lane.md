# ov016 SDK lane U16 — eight rows, two closed, six parked

Slice `scratch/a2/slices/u16.txt` (8 rows after the 8 that were dropped as recently
touched).  Every row was worked at its own pin (`1.1p1`, or `../2.0/sp1p2` where the
member's `.comment` is `Metrowerks C/C++ for ARM 3.0.0.126`).

## Closed

| addr | name | bytes | shard |
|---|---|---|---|
| 0x021CBDF8 | initObj (scenesetselectap) | 264 | `layout/matched/ov016/pkt_ov016_021CBDF8.json` |
| 0x021CC0E8 | button (scenesetselectap) | 288 | `layout/matched/ov016/pkt_ov016_021CC0E8.json` |

Both were size-exact parks whose whole residue was *one scheduling slot* — a
scaled index or a last-argument `add` placed one instruction away from where the
image has it.  Both closed on the same lever, with the body untouched:

**Qualify the read-only global as `const` in its declaration.**  A `const` table
is read as a table, not as an object that could be written, and the front end
then schedules the index/argument computation one slot earlier:

* initObj: `extern const struct tagCOORD g_021DA72C[6];` (was plain
  `struct tagCOORD`).  Image `+0050 lsl r2, r3, #2` before the cell store, the
  park's after it.  `j = i + 3` and the statement order are unchanged.
* button: `extern const s8 g_021DA724[7];` (was `extern s8`).  Image
  `+00B8 add ip, r5, #1` before `+00C0 mov r2, r4`; the park had them swapped.

Neither park's own note mentioned the qualifier; both had tried statement order,
block scope, named locals and types.  A `const` on the *address* of a pointer
global is a different and much blunter lever — it changed the whole body
(0x021D0CEC fell 220 -> 188 bytes, 0x021CFCC8 336 -> 324).  Qualify the table,
not the pointer, and only when the object is never written (the reader line in
the source says so: `g_021DE690` and `g_021DAB58` are written and refuse to
compile as `const`).

This lever also paid on a row that stayed open: 0x021D5A58 went 33 -> 10
differing bytes with it (below).

## Parked, with the first differing instruction

| addr | name | compiled/extent | residue |
|---|---|---|---|
| 0x021D0CEC | DWCi_USBAPlEnd | 220/220 | already closed as a wall by an earlier lane (`docs/idioms/a-guard-load-that-folds-into-its-dying-base-register-is-not-a-source-shape.md`); 2 bytes, image `+0094 ldr r1, [r0, #0xb90]` / `cmp r1, #0` | ours `ldr r0, [r0, #0xb90]` / `cmp r0, #0`.  Untouched this pass. |
| 0x021D5A58 | DWCi_FNTlFormBgEx | 360/360 | 10 bytes, image `+00AC str r5, [r5, #0x18]` (cv->self) | ours `add r0, r0, r4, lsl #3` (cv->font value first).  Const tables fixed the rest. |
| 0x021CFCC8 | write | 336/336 | 9 bytes, image `+012C str r2, [sp]` (the alloc result's home store) | ours `+012C ldr r0, [r6]`; ours sinks that store past the two argument loads. |
| 0x021D657C | readKey | 280/272 | +8 bytes from the first block: image `+000C ldrh r2, [r0]` / `+0014 ldr r4, [pc, #0xec]` / `+0018 mov r3, #0` | ours `ldrh r3, [r0]` / `ldr lr, [pc, #0xf4]` / `mov r2, #0` — a different register rotation for `bit`, `input` and the counter from +000C on. |
| 0x021D0E74 | scanFirst | 332/344 | -12 bytes: the vendor parameter `prm` lives at `[fb+0]` and the image spills it (`+0004 str r0, [sp]`, reloaded `+0018 ldr r0, [sp]` each iteration) with `i` in fp; ours keeps `prm` in fp and puts `i` in r8, saving the spill and the reloads. |
| 0x021BC63C | ATERMi_ApConfigStart | 232/232 | 18-19 bytes: the six-store prefix is now the image's order, but the image loads both bases first (`+001A ldr r5, [pc, #0xb8]` DAT, `+001C ldr r0, [pc, #0xb0]` BSS) and stores `maxap` second (`+0020 str r1, [r5, #0x10]`); mwcc 2.0/sp1p2 sinks that store to the end of the run (`+002C`). |

Two improvements were written back into the parked sources
(`src/pending/ov_sdk/ov016_func_021D5A58.c`, `ov016_func_021BC63C.c`):
0x021D5A58 33 -> 10 differing bytes at the same size, 0x021BC63C 236 -> 232 bytes
(size now exact) and 195 -> 18 differing bytes.  Both files' mtimes were from the
previous day; `src/pending/ov_sdk/ov016_func_021D0CEC.c` (mtime same day, 10:51)
was left alone and only read.

## Notes on the two compiles that are near

* 0x021D5A58 is at *three instructions*: `cv->font = ...` sits before
  `cv->self = cv;` in the source and the stores follow that order; the image has
  the self store first.  Swapping the two statements reproduces the image's
  store order but recolours the block (the MemFont value moves from r0 to r1 and
  the constant 1 from r1 to r0) for 21 differing bytes, so the swap alone is not
  the answer — the vendor line must have been written so that the base load and
  the constant still land where they do.  `cv->font = &g_021DE680[font * 8]`, a
  `(void *)` cast, a named `s`, a byte-offset store, a braced block and reversing
  `f20`/`f24` were all measured, all 21.
* 0x021BC63C's prefix was eight stores (two pairs duplicated) before this pass;
  the six the image wants are `DAT.gMaxBssIdList = maxap`,
  `BSS.gAtermApState = 7`, `BSS.gAtermNotify`, `BSS.gAtermAlloc`,
  `BSS.gAtermFree`, `DAT.gThreadStackSize`, and that order is the one that
  reaches 232 bytes.  Ten further permutations of the six, a `volatile` member
  and the `../2.0/base` and `../2.0/sp1` trees all leave the `maxap` store where
  it is.
