# Lane T20: ov107 rows 6-11, ov015 all, ov175 all (11 rows)

All rows re-measured under their own region/ISA/pin/lang (`--lang c99`, `-O4,p`). Instruction diffs per
row in `scratch/t20/d_<region>_<ADDR>.txt` (baseline, `--cc 1.1p1`), sweeps in `scratch/t20/sw*_*.txt`.
Verdict: **0 of 11 reach EXACT**. Nothing was filed; no parked source was modified (all variants live in
`scratch/t20/v*`). Compiles run: ~190. Wall clock ~70 min.

Everything below that is not marked "new" was already recorded in the parked headers or in
`docs/notes/s8_ov016_ov107_structure_rows.md`; this lane re-measured it and adds the pin/flags axis.

## Sweeps run (new this lane)

* ov015 0x02179F74 / 0x0217A034 / 0x0217A7AC: 12 pins (1.1, 1.1p1, 1.2, 1.2p1, 1.2p2, 1.3, 1.3p1,
  1.6sp1, 1.6sp2, 2.0/base, 2.0/sp1p2, 2.0/sp2p4) x `-O4,p`. The two small rows are pin-invariant
  (80 B / 6 sites and 152 B / 7 sites on **every** pin); 0x0217A7AC is 328/60 on every dsi pin and
  332/70 on every 2.0 pin.
* ov175 0x021DF65C: 12 pins, **200 B / 35 sites on all twelve** (no source change needed to know the
  pin is right).
* ov107 rows 6-11: 1.1p1 vs 2.0/base, 2.0/sp1p2, 2.0/sp2p4. Every 2.0 pin is strictly worse
  (+24..+300 B); 1.1p1 is the row's pin for all six.

## The eleven rows

| region | address | function | bytes (img/ours) | first differing instruction (`image` | `ours`) | residue |
|---|---|---|---|---|---|
| ov015 | 0x02179F74 | IRC_Init | 80/80 | `+002C mov r2, #0` | `strb r2, [r1, #1]` | object materialises **both** immediates before the first store and colours 0xFF->r3, 0->r2 (r1 stays live); 1.1p1 sinks the zero past the `strb` and reuses the dead r1 for it. 6 sites, 11 bytes. New: all **24** store permutations at 1.1p1 give an identical 80 B/6 sites — order is not the lever |
| ov015 | 0x0217A034 | IRCi_Send | 152/152 | `+0058 strb r0, [r6, #2]` | `strb r1, [r6, #3]` | object writes **sumLo before sumHi**; 1.1p1 writes sumHi first, and loop 2's counter lands in r1 where the object uses ip. 10 bytes. Pin-invariant |
| ov015 | 0x0217A7AC | IRCi_Read | 320/328 | `+006C ldrb r4, [r6]` | `ldrb r5, [r6]` | size/i are swapped (object size=r4, i=r5), so the object reuses the zeroed i for `buf[0]=0` while ours re-materialises `mov r0,#0` (+4 B); ours then emits the redundant `size != 0` guard as `ble` (+4 B). 60 sites. New: 12 pins — dsi all 328/60, 2.0 all 332/70 |
| ov175 | 0x021DF65C | DWCi_HandleWSLoginError | 216/200 | `+0080 cmp r4, #0x69` | `sub r2, r4, #0x69` | see below (switch lowering). 12 pins, all 200 B/35 |
| ov175 | 0x021E11F0 | DWC_GdbCancelRequest | 336/336 | `+0004 ldr r6, [pc, #0x128]` | `ldr r7, [pc, #0x128]` | pure colour rotation of the whole function: object base->r6, 0x38->r5, 3->r7; ours r7/r6/r5. Bodies and cross-jumps are byte-identical |
| ov107 | 0x021F2A44 | MBi_CommParentSendBlock | 632/632 | — (no mnemonic differs) | | register-rotation only, `card_addr` base computation +0128..+0148 (mbc->r6, idx->r2, base->r6 vs r7/r6/r2). permute.py(150)/permuter.py(400) already plateaued here |
| ov107 | 0x021F3544 | MB_RegisterFile | 632/632 | — (no mnemonic differs) | | 8 bytes, the three buffer-offset temps at +01A8..+01E4 (buf+0x1e8->r7, buf+0x258->r3, update+1->r6 vs r3/r6/r1). Decl-order already exhausted |
| ov107 | 0x021F2200 | MBi_CommParentRecvDataPerChild | 1216/1216 | `+0008 ldr sb, [pc, #0x4a4]` | `movs r4, r1` | object keeps `&g_021F6FA0` in sb for the whole run; ours uses r5, shifting every other value, and the switch on fileid is narrowed to a 4-entry table. 289 sites — codegen wall, not a spelling |
| ov107 | 0x021F2FA0 | MB_ReadSegment | 1324/1324 | — (no mnemonic differs) | | only the final six instructions rotate by one: image `ldr r1,[sb,#0x28]; ldr r2,[pc]; ldr r3,[r6,#0x48]; ldr r0,[pc]; sub r1,r2,r1; str r0,[r3,r1]`, ours r0..r3. New: **10 spellings** of the final store (offset/pointer/const/ram/cb locals, add-order swap, u8 cast) all give 1324 B/6 sites |
| ov107 | 0x021F46C8 | MBi_ParentCallback | 2004/2000 | `+02E4 ldr r3, [r4, #0xc]` | `add r0, r3, #0x500` | one missing reload: object re-loads `g_021F6F90.p_parm` (r0) for the case-0x07 0x52C test and again (r3) for the WM_StartMPEx arg list; mwcc CSEs to one load. New: **10 spellings** tried (u32*/u16*/void*/struct base casts, volatile, if-statement, offset reshapes, parm-before-test) — all 2000; struct-base cast is worse (2016) |
| ov107 | 0x021F4EFC | MBi_ChildCallback | 2464/1720 | `+0008 ldrh r2, [r0]` | `mov r1, r0` | 744 bytes missing, not a spelling: prologue saves {r3,r4..r8,lr} vs object {r3,r4..r8,sb,sl,fp,lr}, frame 0x1c vs 0x28, and the case arms 0x00/0x01/0x02/0x0B/0x0C/0x0E/0x0F/0x15/0x1D/0x26/0x80 are not reconstructed. 413 sites |

## Closed measurement (new): ov175 0x021DF65C switch lowering

The image's decision tree for `switch (result)` over {2..7, 100..108} balances exactly like ours
(`cmp 0x66 / bgt`, `cmp 0x64`, a 0..7 jump table, `cmp 0x65`, `cmp 0x68`, `cmp 0x67`) and diverges at
one node only:

```
  * +0080  cmp r4, #0x69            | sub r2, r4, #0x69
  * +0084  bgt #0x21df6ec           | cmp r2, #3
  * +0088  beq #0x21df70c           | addls pc, pc, r2, lsl #2      <- ours: 4-entry table 105..108
  * +0090  cmp r4, #0x6c ...        | ...                           <- object: 105 peeled off, then a
                                                                       linear test of 106/107/108
```
i.e. the object spends 9 instructions on the node {105,106,107,108} (one compare for 105, then a
106/107/108 chain) where mwcc 1.1p1 emits a 4-entry relative jump table. 16 bytes. Levers tried this
pass, all **200 B** except where noted:

* 10 case-group re-orderings (105 its own group / fused with 103 / fused with 106 / separate 107 /
  separate 108 / each case on its own line / group moved first): all 200/35.
* body-shape variants: `case 105: errorCode = errorCode - 8;` as a separate statement (204/36);
  same for 106 (208/37); `{ errorCode -= 8; }` braced (200/35); if/else range test (compile error).
  The extra arm is emitted but the tree still tables 105..108 — the run is detected over the value
  set, not the statement, so a distinct body does not break it.

Pin sweep: 12 pins, every one 200 B/35 sites, so the object was built with the same `-O4,p` dsi line.
Verdict: **parked** — the object's switch heuristics split a 4-value run that 1.1p1 tables, and no C
shape reachable from the source changes the value set at that node.

## Parked residues, named

* `ov107 0x021F4EFC MBi_ChildCallback`: first divergence `+0008 ldrh r2, [r0]` (image) |
  `mov r1, r0` (ours) — ours is 744 B short from the prologue on; the object saves sb/sl/fp and a
  0x28 frame. Needs the missing case arms written, not a respelling.
* `ov107 0x021F46C8 MBi_ParentCallback`: first divergence `+02E4 ldr r3, [r4, #0xc]` (image) |
  `add r0, r3, #0x500` (ours) — the CSE of `g_021F6F90.p_parm` across the case-0x07 0x52C test and the
  WM_StartMPEx argument list. Everything else is byte-identical modulo the 4-byte shift.
* `ov107 0x021F2FA0 MB_ReadSegment`: first (and only) divergence `+04D4 ldr r1, [sb, #0x28]` (image) |
  `ldr r0, [sb, #0x28]` (ours) — one-position rotation of the four final loads + `sub`/`str`.
* `ov107 0x021F2200`: `+0008 ldr sb, [pc, #0x4a4]` (image) | `movs r4, r1` (ours).
* `ov175 0x021E11F0`: `+0004 ldr r6, [pc, #0x128]` (image) | `ldr r7, [pc, #0x128]` (ours).
* `ov015 0x0217A7AC`: `+006C ldrb r4, [r6]` (image) | `ldrb r5, [r6]` (ours).
* `ov015 0x0217A034`: `+0058 strb r0, [r6, #2]` (image) | `strb r1, [r6, #3]` (ours).
* `ov015 0x02179F74`: `+002C mov r2, #0` (image) | `strb r2, [r1, #1]` (ours).
* `ov175 0x021DF65C`: `+0080 cmp r4, #0x69` (image) | `sub r2, r4, #0x69` (ours) — see above.
* `ov107 0x021F2A44` / `0x021F3544`: no mnemonic differs; register colouring only.
