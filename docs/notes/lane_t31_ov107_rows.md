# Lane T31: ov107 open SDK rows 0-5 (six smallest, libmb)

Slice: `python scratch/a2/open_rows.py ov107 0 6`. All six re-measured at the project pin
(`dsi/1.1p1`, `-O4,p`, `--lang c99`, per-row region/ISA). **1 of 6 reaches EXACT and is filed:**

| row | address | bytes | verdict |
|---|---|---|---|
| 0 | 0x021F2E58 MBi_calc_sendblock | 124 | **EXACT, filed** `src/matched/ov_sdk/ov107_func_021F2E58.c`, shard `ov107/pkt_ov107_021F2E58.json` |
| 1 | 0x021F3830 MBi_SetSegmentInfo | 348/348 | DIFF 115 |
| 2 | 0x021F4140 MBi_SendFixedBeacon | 356/356 | DIFF 63 |
| 3 | 0x021F6658 MBi_SetTask | 348/356 | DIFF (parked source, T10's 352 B variant not filed) |
| 4 | 0x021F5904 MB_Init | 472/472 | DIFF 9 (two basins, now 26 fresh shapes) |
| 5 | 0x021F42D4 MBi_SendVolatBeacon | 600/612 | DIFF 401 + 3 unresolved relocations (not reachable) |

Per-row diffs: `scratch/t31/<ADDR>.txt`; variant sources/diffs `scratch/t31/{m,e,s,t,f}_*.c|txt`;
generators `scratch/t31/gen*.py`.

## Closed: 0x021F2E58 MBi_calc_sendblock - 124/124 EXACT

The parked source's `Ent *e` local was the whole residue (S8 and T10 both parked it as "not
reachable from C"). Two independent things were wrong:

1. **The a/b update is one if/else, not nested ifs.** The image's else-arm store is reached by
   fall-through from the inner test as well as by the first `bhi`, i.e.
   `if (y <= x && x <= y + 2) e->a = x + 1; else e->a = y;`. The parked nested form returns on
   the inner-test-false path, so it emits an unpredicated `bx lr` where the image has
   `strhle` + `bxle lr` falling into the else arm (120 vs 124 bytes).
2. **The element pointer must not be held in a local.** Spell the element expression inline at
   every use - `((Ent *)(g_021F6FA0 + file_id * 0x5d4))->a` - and mwcc emits an un-CSE'd value:
   `mla ip, r0, r1, r2`, derives `ip + 0x1d00` into r0 for the guard/if body, and **re-derives**
   `ip + 0x1d00` in the else arm. With a named `e` local the allocator gives the base r3, puts the
   field `y` in ip, and re-uses the derived r0 for the else store: size-exact but 8 bytes wrong
   (`mla r3`/`ldrh ip`/`add r0, r3`/`strh ip`).

So the winning shape is `e` -less: the base is not a source-level object at all, and the address
re-derivation in the else arm follows from that. Declaration scope of `x`/`y`, operand order,
`u8 *` base with casts, and a `u32` base (that one does not compile) are all inert (8 diffs).

## 0x021F5904 MB_Init - 9 bytes, two basins, now measured from 26 fresh shapes

Identical to the S8/T10 finding; nothing new lands outside the two basins.

* **in-loop read** (`c = mbi_life_mp.gname;` inside the body): 9 diffs, 472/472, colours right
  (base r0, cursor r1, char r2, dest r3) - but the load is re-executed so the back edge targets
  `+0x00F8` instead of `+0x00FC`, and `str r1, [r0, #0xc]` precedes `add r6, r6, #1`.
  First divergence: image `+010C add r6, r6, #1` | ours `str r1, [r0, #0xc]`.
  Reached by: post-increment field, field `++` as its own statement, assignment inside the
  deref, `do { } while (++i < 16)`, `while` with `i++` before the writeback, for-increment
  holding the writeback (23-39 diffs, worse).
* **hoisted cursor** (`c = mbi_life_mp.gname;` before the loop, or in the `for` init): the load
  is hoisted once (back edge `+0x00FC` matches) but the base load is scheduled first at `+0x00E8`,
  the whole set rotates (base r1, cursor r3, char r0, dest r2) and the diff is 32-39 bytes.

The compiler never emits `add r6` before the field store in any source shape tried here (26 this
lane, plus the ~200 hand spellings and ~7,500 permuter compiles already on the row): the store is
always emitted immediately after the `add` that produces its value. Parked: the two requirements
(hoisted load **and** `i++` before the writeback **and** the in-loop colours) have not co-occurred
in any spelling, and the compiler axis is dead per rule 4.

## 0x021F3830 MBi_SetSegmentInfo / 0x021F4140 MBi_SendFixedBeacon / 0x021F6658 MBi_SetTask

Unchanged walls, re-measured this lane:

* **0x021F3830**: 348/348, 115 diffs. Residue is case B only: image keeps `error_flag` in r2 /
  `load_last_addr` in r3 (`mov r2, #0; mov r4, r2`) where ours swaps them, and the image keeps the
  `size <= 0x40000` test as a predicated move + branch pair where ours tail-merges both arms.
  Measured first divergence (branch-displacement fallout only, size-exact):
  image `+0028 beq #0x21f3960` | ours `beq #0x21f395c`; the semantic site is
  image `+0080 mov r2, #0` | ours `mov r3, #0`.
* **0x021F4140**: 356/356, 63 diffs, all colouring - the two long-lived globals land swapped
  (image sUnlockFunc r7 / bsendBuff r8; ours the reverse), with the same pool slots and the same
  instruction order. New this lane: swapping the two `extern` declarations and trying array
  (pointer-decay) forms for either global does not move it (array forms do not compile).
  First divergence: image `+0010 ldr r4, [r3, #0x1c]` | ours `ldr r0, [r3, #0x1c]`.
* **0x021F6658**: the parked source is still the 348-byte one; T10's 352-byte store-order variant
  (`pt->task`/`pt->active`/`pt->callback` between the interrupt state and the priority store) was
  never filed and the row is 4 bytes short of the 356-byte image either way. Residue after that
  fix: the image does **not** CSE the two `p_work->head` reads - it re-loads `ldr r1, [r4, #0xc0]`
  at `+0x00E0` after the `OS_WakeupThreadDirect` call - while 1.1p1 keeps the `+0x00AC` value live
  across the call. Measured first divergence (pool offset, we are 8 bytes short):
  image `+0004 ldr r4, [pc, #0x154]` | ours `ldr r4, [pc, #0x14c]`; the semantic site is
  image `+00A0 mov r5, r0` | ours `stmib r8, {r1, r7}`.

## 0x021F42D4 MBi_SendVolatBeacon - not reachable by construction

600/612, 401 diffs, and 3 of 9 relocations cannot resolve: the two `bsendBuff` (0x021F6F20) ABS32
sites at `+0x024C/+0x0250` and the third report "no witness outside 021F42D4..021F452C", so the
entry can never reach EXACT regardless of code. Ours also hoists `SM->p1c`/`SM->unk29`/`SM->unk10`
ahead of the `bsendBuff` field stores. Measured first divergence (pool offset, we are 12 bytes
short): image `+0008 ldr r7, [pc, #0x240]` | ours `ldr r7, [pc, #0x238]`; the semantic site is
image `+0034 ldrb r0, [r2, #4]` | ours `ldr r0, [r7, #0x1c]`. Parked on both counts; not
body-shape work.
