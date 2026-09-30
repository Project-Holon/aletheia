# Lane U20 — ov107 / ov015 / ov175 SDK rows (frozen slice scratch/a2/slices/u20.txt)

16 rows, all measured this pass with `match.py one --cc 1.1p1 --lang c99 --arm --diff`
against the vendor object (`tools/sdkobj.py`). **Zero filings for this lane: not one row
reached EXACT or MATCH.** No source was modified; every row below is the parked spelling
plus a measured residue.

Method note that pays on this class: a raw `concrete byte(s) differ` count is useless when
the sizes differ. A single missing/extra instruction shifts every pc-relative operand, so a
4-byte gap reads as ~1,180 differing bytes (see MBi_ParentCallback). Align the *mnemonic
streams* (`scratch/u20/align2.py`, difflib over the two diff columns with `#imm` normalised)
and the residue collapses to one instruction.

## Per-row state

| address | region | image / compiled | first divergence | residue |
|---|---|---|---|---|
| 0x02179F74 IRC_Init | ov015 | 80 / 80 | +0024 image `mov r3,#0xff` \| ours `mov r2,#0xff` | constant-materialisation order: the object hoists `mov r2,#0` above `strb r3,[r1,#1]` and keeps r3/r2 distinct; 1.1p1 frees r1 after the strb and materialises the zero late. 9 B otherwise. 7 hand spellings + 2,500 permuter compiles: floor 11 B. |
| 0x0217A034 IRCi_Send | ov015 | 152 / 152 | +0058 image `strb r0,[r6,#2]` (sumLo) \| ours `strb r1,[r6,#3]` (sumHi) | mwcc emits the `sum>>8` store first *regardless* of source order (swapping the two assignment lines is byte-identical), so the object's sumLo-first order cannot be spelled. Second cluster +0060..+0078: loop-2 counter is `ip` in the object, r1 here. 10 B. 4 hand spellings + 2,500 permuter: floor 10 B. |
| 0x0217A7AC IRCi_Read | ov015 | 320 / **328 (+8)** | +0004 | object runs both loops unguarded with size in r4 / i in r5; this spelling emits the redundant `cmp r5,#0 / ble` pre-test around the first loop and colours size/i the other way. One extra instruction + rotation. |
| 0x021DF65C DWCi_HandleWSLoginError | ov175 | 216 / **200 (-16)** | +0080 image `cmp r4,#0x69; bgt; beq` \| ours `sub r2,r4,#0x69; cmp r2,#3; addls pc,pc,r2,lsl#2` | switch lowering differs: object peels 105 and linear-tests 106/107/108, 1.1p1 emits a 4-entry table. **Object stamp is `Metrowerks C/C++ for ARM 4.0.0.1025` — no build under tools/mwccarm writes that stamp**, so this row is not reproducible with the available trees at all. |
| 0x021E11F0 DWC_GdbCancelRequest | ov175 | 336 / 336 | +0004 image `ldr r6,[pc]` \| ours `ldr r7,[pc]` | register rotation only (object: g_021E5334→r6, 0x38→r5, 3→r7; ours r7, r6, r5) plus an `mla` operand swap at +00C0. Permuter best 15 B (from 22) — **but the same unavailable stamp, 4.0.0.1025**. |
| 0x021F3830 MBi_SetSegmentInfo | ov107 | 348 / 348 | +0028 image `beq #0x21f3960` \| ours `#0x21f395c` | 4-byte shift → one structural instruction; 115 B raw. |
| 0x021F4140 MBi_SendFixedBeacon | ov107 | 356 / 356 | +0010 image `ldr r4,[r3,#0x1c]` \| ours `ldr r0,[r3,#0x1c]` | scratch colouring, 63 B. |
| 0x021F6658 MBi_SetTask | ov107 | 356 / **348 (-8)** | +0004 (pc offset) | store order of pt->task / pt->active / pt->callback plus a separate walk local in the field-0xC4 arm (known lever, not yet landed); 163 B raw. |
| 0x021F5904 MB_Init | ov107 | 472 / 472 | +010C image `add r6,r6,#1` \| ours `str r1,[r0,#0xc]` | documented two-basin wall (second copy loop: hoisted cursor 32-40 B, in-loop 9 B, back edge +011C). This spelling is the 9 B basin. 2,500 permuter compiles: floor 9 B. |
| 0x021F42D4 MBi_SendVolatBeacon | ov107 | 612 / **600 (-12)** | +0034 | 401 B raw; **three relocations have no witness (incl. bsendBuff 0x021F6F20 → unresolved)**, so the row cannot reach EXACT regardless of code. Measured, parked. |
| 0x021F2A44 MBi_CommParentSendBlock | ov107 | 632 / 632 | +0128 image `ldr r6,[r5]` \| ours `ldr r7,[r5]` | scratch rotation in the card_addr / pl block (+0140..+0148 operand order). 12 B. 2,500 permuter: floor 12 B. |
| 0x021F3544 MB_RegisterFile | ov107 | 632 / 632 | +01A8 image `add r7,r6,#0x1e8` \| ours `add r3,r6,#0x1e8` | three scratch temps rotated (0x1e8→r7, 0x258→r3, update+1→r6 vs r3, r6, r1). 8 B. Permuter could not run: `ISA conflict for MBi_MakeDownloadFileInfo at 021F37BC` — the symbols block declares arm, the image says thumb (ov057); fix the token and it will run. |
| 0x021F2200 MBi_CommParentRecvDataPerChild | ov107 | 1216 / 1216 | +0008 image `ldr sb,[pc] / movs r6,r1 / ldr r7,[pc]` \| ours `movs r4,r1 / mov r6,#1` | structural from instruction 2 (globals hoisted into sb/r7 by the object); 1018 B raw. Rewrite. |
| 0x021F2FA0 MB_ReadSegment | ov107 | 1324 / 1324 | +04D4 image `ldr r1,[sb,#0x28]` \| ours `ldr r0,[sb,#0x28]` | the whole function matches; only the final 5-instruction store sequence is rotated (object r1,r2,r3,r0 vs r0..r3). 10 B. 2,500 permuter: floor 10 B. |
| 0x021F46C8 MBi_ParentCallback | ov107 | **2004 / 2000** | real divergence only at +02E0 | object has two adjacent `ldr [r4,#0xc]` (0x2E0→r0, 0x2E4→r3); mwccarm CSEs them into one, and the missing 4 bytes shift every pc-relative operand — which is why the raw count is 1,178 for a one-instruction gap. Everything else is byte identical modulo the shift. Alias-symbol workaround measured 2012 before (worse). One-instruction CSE wall. |
| 0x021F4EFC MBi_ChildCallback | ov107 | **2464 / 1720 (-744)** | +0000 prologue: object `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` \| ours `push {r3,r4,r5,r6,r7,r8,lr}` | the parked source is not the object's skeleton (fp/sl live, different entry sequence). Rewrite, not a tweak — the ParentCallback skeleton does not template onto it as parked. |

## Permuter sweeps (scratch/u20/perm/, 2,500 compiles each)

Zero improvement on 02179F74 (11 B), 0217A034 (10 B), 021F2A44 (12 B), 021F2FA0 (10 B),
021F5904 (9 B); one partial win on 021E11F0 (22 B → 15 B, `best_021E11F0.c`);
021F3544 aborted on the ISA conflict above. ~15,000 compiles total — the register-tie-break
rows are at a wall for this compiler, not for want of spellings.

## Compiler stamps (measured, all 16)

`1.1p1 / 4.0.0.1024` (the toolchain's own build) for all ov015 and ov107 rows.
`4.0.0.1025`, "no tools/mwccarm build writes this stamp", for **both** ov175 rows —
so 0x021DF65C and 0x021E11F0 are not closable with the available trees no matter the source.
