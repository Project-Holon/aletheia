# Lane S8: ov016 + ov107 structure rows (13 rows, unnamed-residue table)

All 13 rows re-measured under their own region/ISA/pin/lang (`--lang c99`), instruction diff per row in
`scratch/s8/<region>_<ADDR>.txt`, sweep matrices in `scratch/s8/sw_<region>_<ADDR>.json`.
Verdict: **0 of 13 reach EXACT** at `-O4,p` on any of 8 pins (and 24 pins for the four smallest rows).
Two levers did land and are handed over below. Nothing in the repo was filed: no row reached EXACT.

## Closed measurement 1: func_021BC63C 0x021BC63C (thumb, 232 B) — 195 → 70 concrete diffs, now SIZE-EXACT

The parked source carried **two spurious duplicate stores** that the image does not have:

```c
    BSS.gAtermNotify = notify;   /* +001E in the image, once */
    BSS.gAtermAlloc = alloc;
    DAT.gMaxBssIdList = maxap;
    BSS.gAtermApState = 7;
    BSS.gAtermNotify = notify;   /* <- not in the image */
    BSS.gAtermAlloc = alloc;     /* <- not in the image */
    BSS.gAtermFree = free;
    DAT.gThreadStackSize = stackSize;
```

Dropping the two duplicates (order otherwise unchanged) takes the compile from 236 B/195 diffs to
**232 B/70 diffs** — the row becomes size-exact and every instruction from `+0082` on is identical.
Improved source: `scratch/s8/ov016_func_021BC63C_v2_size-exact.c` (verified with
`--cc 2.0/sp1p2 --thumb`). Sweep over 24 pins × 7 flag sets: every `2.0/*` pin gives the same
`-O4,p` 232 B / 70 diffs; nothing reaches EXACT.

Remaining residue, one root cause — the vendor build keeps the constant **7 live in r6 across the
`func_021B97A8` call** and derives the error codes from it; ours materialises 7 into r2 and writes the
codes directly:

```
  * +0000 push {r4, r5, r6, lr}   | push {r3, r4, r5, lr}      <- r6=7 is a third live reg, we pad with r3
  * +001E movs r6, #7             | str r2, [r5, #0x7c]        <- r2=7, dies at the store
  * +0022 str r6, [r0, #0x38]     | movs r2, #7; str r2, [r5, #0x38]
  * +0056 adds r0, r6, #0         | movs r0, #0                 <- image: -1 = 7-8
  * +0058 subs r0, #8             | mvns r0, r0
  * +0068 adds r0, r6, #0         | movs r0, #8                 <- image: -9 = 7-16
  * +006A subs r0, #0x10          | mvns r0, r0
  * +0038 ldr r1, [pc, #0x94]     | adds r1, r5, #0             <- image holds &DAT in r5 and reloads &BSS
```

Not tried: a source shape that makes the literal 7 live past the call (the only lever left). Everything
else in the body is byte-identical.

## Closed measurement 2: func_021D0DE0 0x021D0DE0 — byte-EXACT at `-O1`, excluded by project policy

`match.py one --flags -O1` is **EXACT** for 19 configurations (every dsi build and every 2.0 build,
`-O1 -lang c99`), i.e. the parked source is right and the residue is entirely the if-conversion of one
arm. `docs/MATCHING.md` ("the optimisation level is pinned: `-O4,p` and only `-O4,p` ... What is
excluded is any *other* level") makes that non-fileable. Residue at `-O4,p` (144/148):

```
  * +0030 popne {r3, pc}      | moveq r0, #2
  * +0034 mov r0, #2          | strbeq r0, [r1, #0xb94]
  * +0038 strb r0, [r1, #0xb94] | pop {r3, pc}
```
The image leaves `if (g->st != 0) { if (prm[0] == 2) g->st = 2; }` unpredicated; 1.1p1 if-converts the
inner arm. Four early-return spellings, an inline setter, a block local and an explicit `return` were
already tried by an earlier pass; the flag sweep is the only new result.

## The other eleven rows, one line each

| region | address | bytes | first divergence (`image` | `ours`) | named residue |
|---|---|---|---|---|---|
| ov016 | 0x021B97A8 | 188/164 | `+0002 adds r6, r0, #0` | `sub sp, #8` | ours spills a param + two temps to an 8-byte frame and re-materialises the `0x70`/`0xc0`/`0xd0` address arithmetic the image keeps in r6/r7; whole tail is rescheduled. 8 pins, no EXACT |
| ov016 | 0x021B9FE0 | 186/196 | `+0002 sub sp, #8` | `adds r6, r3, #0` | prologue order: image spills `r1` to `[sp,#4]` before shuffling 3 args into r6/r7; ours shuffles first and needs no frame in the same place. 10 bytes of the byte-swap tail. 8 pins, no EXACT |
| ov016 | 0x021BD8D8 DWCi_KBlInit | 876/844 | `+0000 push {r3,...}` | `push {r4,...}` | the +32 overshoot is **one spilled zero, not a missing block**: see below |
| ov016 | 0x021BE844 disp | 652/656 | `+0004 sub sp, sp, #0x18` | `sub sp, sp, #0x20` | frame `0x18`+1 spill vs `0x20`: the image interleaves the fifteen `ldrb` copies with the `line*12` setup, 1.1p1 copies in order. Documented already in `docs/notes/pkt_ov016_021BD8D8.c.txt`; 8 pins, no EXACT |
| ov016 | 0x021C78A0 | 164/192 | `+0000 push {r4,...,lr}` | `push {r4,...,sl,fp,lr}` | image (192 B) keeps a 12-iteration loop body with its argument setup *inside* the loop; ours hoists the setup and spins a 3-instruction loop around it. -28 B. Not a spelling: a loop-body placement |
| ov016 | 0x021C9A94 isPush | 620/636 | `+0008 ldr r0, [pc, #0x258]` | `ldr r0, [pc, #0x248]` | pool offsets + one register: image keeps the `0x1d` in r7, ours in r6, and ours re-orders the 3-iteration tail so the `mov r0, #0xe` lands earlier. -16 B |
| ov016 | 0x021D0E74 | 332/344 | `+0004 str r0, [sp]` | `mov fp, r0` | image spills the frame pointer (`prm`) to `[sp]` and re-loads it per field; ours keeps it in fp, which pushes the base into `add r0, fp, r8, lsl #2` form and loses 12 B |
| ov016 | 0x021D15F0 taskMove | 184/192 | `+0000 push {r4, r5, r6, lr}` | `push {r3, r4, r5, lr}` | image keeps the constant `0` in a third callee-saved register (r4) and reuses it for `func_021D5250`'s idx and two `func_021D7680` args; ours needs only 2 callee-saved regs and pads with r3, then if-converts the `type == 5` ternary to `ldrne` where the image branches (`bne`/`ldr`/`b`). ±8 B |
| ov016 | 0x021D657C | 280/272 | `+0004 ldr r0, [pc, #0xf4]` | `ldr r0, [pc, #0xfc]` | +8 B: image assigns the first u16 to r2 and the second to r3 and carries the mask in r4; ours swaps those (r3/r2) and needs `mov r2, #0x20` inline twice. Same shape, 2 extra instructions |
| ov107 | 0x021F2E58 MBi_calc_sendblock | 120/124 | `+0020 mla ip, r0, r1, r2` | `mla r1, r0, r1, r2` | image keeps the element pointer in **ip** and re-derives `add r0, ip, #0x1d00` in the `else` (`strh r3, [r0,#0x48]`); ours reuses r0 and drops that one instruction. Tried a byte-offset spelling (`p[0x1d52]`, `*(u16*)(p+0x1d48)`) to force the re-derivation: identical 120 B, so not reachable from C. 8 pins, no EXACT |
| ov107 | 0x021F6658 MBi_SetTask | 348/356 | `+00A0 mov r5, r0` | `stmib r8, {r1, r7}` | documented in the parked header: 1.1p1 coalesces `pt->task`/`pt->field4` into `stmib` and sinks the `bak_cpsr` move; all store orders and bitfield spellings already tried |

## DWCi_KBlInit 0x021BD8D8, the +32 overshoot, measured

The extra 32 bytes are entirely **from the button loop (0x21BDA14) on**, and they are one spilled
constant, not an extra block:

* image: `push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}` + `sub sp, #0x20` = 72 B frame, 0x20 of locals.
  ours: `push {r4..fp, lr}` + `sub sp, #0x24` = the same 72 B frame, but 0x24 of locals — the extra slot
  is `sp+0x10`, holding the constant `0`.
* image holds `0` in `sl` (`mov sl, #0` at 0x21BDA1C), reuses `sb` (already 0 from the skey loop) as the
  button-loop counter, keeps `2` (the FNTlDrawRect colour) in `fp` and re-materialises
  `mov r0, #0x480; str r0, [sp, #8]` **per call** inside the inner loop.
* ours uses r8 as the button-loop counter (it was the skey loop's 0), spills the next zero to `sp+0x10`
  and reloads it in the loop (`ldr r0, [sp, #0x10]` at +0160/+0170/+01C8/+0208), and hoists
  `mov fp, #0x480`.
* the spilled slot doubles as the canvas-loop outer counter `i` (`add r0, r0, #1; str r0, [sp, #0x10]`
  at +01FC..+0208), so the extra instruction count is the store + 3 loads + the 0x480 materialisation
  difference.

Sweeps: 24 pins × 7 flag sets for the parked source — every dsi build 876 B at `-O4,p`, every 2.0 build
854/876, no EXACT. This is the same row a 400-budget permuter run (seed 9804) already left flat, and
swapping the loop variables among `i, j, k` was already shown inert. **Parked: the levers left are a
register-allocation shape 1.1p1 does not reproduce, not a spelling.**
