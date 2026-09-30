# Lane T10: ov107 open SDK rows 0-5 (six smallest, libmb)

Slice: `python scratch/a2/open_rows.py ov107 0 6`. All six rows re-measured under their own
region/ISA/pin/lang. Verdict: **0 of 6 reach EXACT**; nothing filed into `src/matched/`.
One row moved materially (MBi_SetTask, 348 B/163 diffs -> 352 B/110 diffs, the recorded blocker
gone); the other five are the same walls the S8 note and the parked headers describe, each
re-measured with a 23-pin sweep and a batch of body-shape variants.

All per-row instruction diffs: `scratch/t10/<ADDR>.txt`; pin matrices: `scratch/t10/pin_sweep.json`
and `scratch/t10/pin_sweep.log`; variant sources/binaries: `scratch/t10/v_*.c`, `w_*.c`, `x_*.c`,
`y_*.c`, `z_*.c` with matching `.txt` diffs.

## Pin sweep, all six rows (23 pins, `-O4,p`, only the project-pinned flag set)

| row | best pin result | note |
|---|---|---|
| 0x021F2E58 | 120 B / 27 diffs on all 18 non-`1.2/sp*` pins | `1.2/sp2..sp4` push it to 128 B |
| 0x021F3830 | 348 B / 115 diffs on all 1.x pins | 1.6sp* 344/134, 2.0/* 384/242, 1.2/sp* 412-432 |
| 0x021F4140 | 356 B / 63 diffs on all 1.x pins | 1.2/sp* 372-376, 2.0/* 380/302 |
| 0x021F6658 | 348 B / 163 diffs (parked) | 2.0/* 352/139, 1.6sp* 344/160 |
| 0x021F5904 | 472 B / 9 diffs on **all nine** 1.x pins | 2.0/* 484/273, 1.2/sp* 508-516 |
| 0x021F42D4 | 600 B / 401 diffs (1.1p1, 1.2*) | 2.0/* 608/395, 1.2/sp* 652-664 |

No pin moves any row toward EXACT, so the compiler axis is shut for this slice.

## 0x021F6658 MBi_SetTask (arm, 356 B target) - blocker broken, 4 bytes left

The parked header recorded the +0x00A0 site as unbeatable: 1.1p1 coalesces `pt->task = task` (+4)
and `pt->callback = callback` (+8) into `stmib r8, {r1, r7}` and sinks the `bak_cpsr` move
(348 B/163 diffs). **The store order is the lever.** Writing

```c
    pt->task = task;
    pt->active = 1;
    pt->callback = callback;
```

between the `OS_DisableInterrupts()` result and the priority store reproduces the target's block
*exactly*:

```
+00A0 mov r5, r0
+00A4 str r7, [r8, #8]
+00A8 str r1, [r8, #4]
```

and every instruction from +00AC to +0128 is identical except for branch displacements. Best
variant (`scratch/t10/y_T5.c`): **352 B, 110 concrete diffs**, i.e. the old blocker is gone and the
row is 4 bytes short. Source: same store order, plus the `pt == &p_work->fieldC4` arm walking the
list with a separate local (`p2`) and assigning `pos = p2;` before the link - that is what puts the
head pointer in r1 for the whole tail, matching the target.

Remaining residue, one instruction: the target does **not** CSE the two `p_work->head` reads. It
keeps the load hoisted to +00AC for the priority arm and re-loads in the &fieldC4 arm:

```
  * +00E0    ldr r1, [r4, #0xc0]    | bne #0x21f676c      (ours reuses the +00AC value)
```

Ruled out for that load: pointer-cast spelling of the head read (`*(MBiTaskInfo_tag **)((char *)p_work + 0xC0)`,
Z/Y variants T1-T3, Z: T2 applied to the test itself), second local for the walk (T5 - kept, it is
what fixes the colours), re-reading head in the while condition (T4: 380 B), reversed branch
condition. Next lever: a spelling that stops mwcc's load-CSE across the head==0 arm without
disturbing the r1 colour.

## 0x021F5904 MB_Init (arm, 472 B) - 9 bytes, basin confirmed exhaustively again

Everything except the tail of the second copy loop is byte-exact. First divergence:

```
  * +010C    add r6, r6, #1        | str r1, [r0, #0xc]     (i++ vs the field writeback)
  * +011C    blt #0x021F5A00       | blt #0x021F59FC        (back edge: hoisted load vs in-loop)
```

`docs/notes/func_021F5904.c.txt` documents the two basins with ~7,500 permuter compiles. This lane
added 14 fresh spellings and they all land exactly on the documented two:

* hoisted cursor (function-scope, block-scope, field-pointer `u16 **fp`, `c++` vs `c = c + 1`,
  `while`, i-countdown, store-last, d-before-c and c-before-d, `for(;;)` with explicit break):
  **33-40 diffs**, always the same rotation - base=r1, cursor=r3, char=r0, dest=r2 (target:
  base=r0, cursor=r1, char=r2, dest=r3) - with the pool load for `&mbi_life_mp` scheduled at
  +00E8 (target +00F0). The hoisted form *does* fix the i++/writeback order and the back edge.
* in-loop field read: **9 diffs**, correct colours, wrong order, unhoisted load - independent of
  statement order (i++ in the body, store last, comma increment all give 9).

The field-pointer basins (`fp = &mbi_life_mp.gname`, `*fp` read/write) give 476 B (wrong size).
No pin changes any of it (all nine 1.x pins give the same 9). Conclusion stands: a spelling that
hoists the loop-invariant cursor load while keeping `&mbi_life_mp` in r0 has not been found and
does not appear reachable from C on this compiler.

## 0x021F4140 MBi_SendFixedBeacon (arm, 356/356 size-exact, 63 diffs)

The whole function is one systematic register-colour permutation, not a semantic residue:

```
  * +0010    ldr r4, [r3, #0x1c]   | ldr r0, [r3, #0x1c]      cur:  image r4 | ours r0
  * +0014    ldr r0, [r3, #0x20]   | ldr r3, [r3, #0x20]      data: image r0 | ours r3
  * +0060    ldr r8, [pc, #0xf0]   | ldr r7, [pc, #0xf0]      bsendBuff: image r8 | ours r7
  * +0064    ldr r7, [pc, #0xe8]   | ldr r8, [pc, #0xe8]      sUnlockFunc: image r7 | ours r8
```

The two globals are loaded at the same two slots in both and land in exactly swapped registers; the
rest of the diff is the fallout (`[r8, ...]` vs `[r7, ...]` everywhere). Tried this lane: `data`
read before `cur` (declared local, S1) - 63; swapped if/else with `MIi_CpuClear16` in the true arm
(S2) - 70; dead `lastAddr` re-init before the field stores (S3) - 63; 23-pin sweep. Parked: needs the
allocator's colour choice for two long-lived globals, not a spelling.

## 0x021F3830 MBi_SetSegmentInfo (arm, 348/348 size-exact, 115 diffs)

The switch dispatch, case A and case C are byte-identical; the whole residue is case B plus the
fallout in branch displacements (`+0028 beq #0x21f3960` | `#0x21f395c`).

```
  * +0080    mov r2, #0            | mov r3, #0       image: error_flag=r2, load_last_addr=r3
  * +0084    mov r4, r2            | mov r4, r3                            ours: swapped
  * +00B4    movls r4, #1          | b #0x21f3904     image keeps the `size <= 0x40000` test as a
  * +00B8    bls #0x21f3918        | b #0x21f3910     predicated move + branch pair; ours
                                                      tail-merges both arms into a jump table
```

Ruled out this lane: `u32` flags (K1), split `error_flag = 0; reload_flag = 0;` (K2), extra local
(K3), flags-after-`load_last_addr` (E1), `error_flag = reload_flag = 0` (E2), declaration order of
the two flags (E3), `unsigned int` + pad local for `load_last_addr` (E4). All 348 B/115. Parked:
allocator colour for the zero flag plus a tail-merge the if-conversion pass performs.

## 0x021F2E58 func_021F2E58 / MBi_calc_sendblock (arm, target 124, ours 120)

```
  * +0020    mla ip, r0, r1, r2    | mla r1, r0, r1, r2
  * +0064    add r0, ip, #0x1d00   | strh r1, [r0, #0x48]    else arm: image re-derives from ip
  * +0068    strh r3, [r0, #0x48]  | bx lr
  * +0060    bxle lr               | bx lr
```

The image keeps the element base in **ip** and re-computes `ip + 0x1d00` for the else-arm store;
ours keeps it in r1 (then r0) and reuses the derived pointer, so it is one instruction/4 bytes
short. S8 already measured a byte-offset spelling inert; this lane added an explicit `u8 *base`
local (L1) - 120 B/27 diffs, unchanged. The row stays capped: the re-derivation is not reachable
from C source shape.

## 0x021F42D4 MBi_SendVolatBeacon (arm, target 612, ours 600, 401 diffs)

```
  * +0034    ldrb r0, [r2, #4]     | ldr r0, [r7, #0x1c]
  * +0038    bic r0, r0, #3        | ldrb r1, [r2, #4]
  * +003C    orr r1, r0, #2        | ldrb r5, [r7, #0x29]
```

Ours hoists the `SM->p1c` (+0x1c), `SM->unk29` and `SM->unk10` loads ahead of the `bsendBuff`
field stores and re-orders the whole prologue; the parked note already records the logic as
reconstructed (600/612). Best pin 2.0/* is 608/395; 1.1p1 = 600/401. Separately, 3 of 9
relocations cannot resolve at all: the `bsendBuff` (0x021F6F20) sites at +024C/+0250/+0254 report
"no witness outside 021F42D4..021F452C", so this row cannot reach EXACT even with matching code
until that data address is attested elsewhere. Parked on both counts; not body-shape work.

## Not started (outside the smallest-six slice, as instructed)

* `MBi_ChildCallback` 0x021F4EFC (2,464 B, 744 short) and `MBi_ParentCallback` 0x021F46C8
  (2,004 B) are the known pair of one skeleton; read one and template the other when a lane owns
  them. Both are in `src/pending/ov_sdk/`.
