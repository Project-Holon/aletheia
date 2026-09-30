# Lane U17 - ov016 SDK slice (14 rows), all parked with named residues

Scope: the frozen slice `scratch/a2/slices/u17.txt`. Harness: dsi/1.1p1 unless the row's own pin says
otherwise. **No row moved to EXACT; every pending source is untouched.** Diffs kept in `scratch/u17/d_<ADDR>.txt`.

| addr | bytes (ours/image) | concrete | first diff | residue |
|---|---|---|---|---|
| 0x021D0B44 | 372/372 | 9 | +0x2C | `MemUsb` loaded once by us, twice by the object |
| 0x021B87F0 | 464/464 | 6 | +0xEA | one jump-table halfword + empty-loop register roles |
| 0x021C84BC | 508/508 | 38 | +0x144 | `sub` hoisted, MemSsl r1 vs r2 |
| 0x021BE844 | 652/656 | 465 | +0x04 | 0x18 frame vs 0x20, 15 initialiser bytes |
| 0x021C687C | 404/400 | 318 | +0x10 | dispatch order (see pkt_ov016_021C6588.c.txt) |
| 0x021C2610 | 504/528 | 141 | - | &buf/&tmpbuf/20 callee-saved allocation |
| 0x021C1210 | 596/632 | 416 | - | 4.0.0.1025 jump-table dispatch |
| 0x021C9A94 | 620/636 | 409 | +0x08 | AREA copy pairs vs hoisted field loads |
| 0x021C00A8 | 624/640 | 457 | - | prologue 5-byte initialiser scheduling |
| 0x021C73D0 | 748/704 | 601 | - | predicated `popeq` + dead `pop` at 0x021C7418 |
| 0x021D1208 | 784/796 | 567 | - | `dark` in fp vs spill, DWCiMsgCmn/EFF hoist |
| 0x021C7D80 | 828/824 | 479 | - | ErrorCode r0 vs r1, C_CODE argument order |
| 0x021BD8D8 | 876/844 | 519 | +0x00 | 0x24 frame vs 0x20, zero-register reuse |
| 0x021BA804 | 952/996 | 801 | - | AutoProfile zero-fill idiom, unattested globals |

## Measurements made this lane (all re-measurable, sources in `scratch/u17/`)

**0x021D0B44** (size-exact, 4 instruction slots; object stamped 4.0.0.1025). Object:
`ldr r3,[r5] / add r3,r3,#0x1000 / str r0.. / str r1.. / ldr r0,[r5] / ldr r1,[pc]` - two independent
loads of `MemUsb`, the second one reloaded because stores through the loaded pointer killed the memory
value. Ours keeps one load in r4 across the two stores and copies it (`mov r0, r4`). The `tick` local
must stay (removing it - variant A/B2 - hoists the base load above `OS_GetTick`, 29 bytes out).
Nine-byte residue either way. Tried and flat: `WM_Initialize(g,..)` / `(void*)g` / `g->wmBuf` /
`&g->wmBuf[0]` / a named `void *wm` local as the argument; `tick` as `u64` at declaration. Not worth
another spelling: this is the 1025 front end's memory-CSE, not a source shape.

**0x021B87F0** (size-exact, 6 bytes), two independent residues:
1. table halfword at +0xEA: object `0x002C` (case 19's own break copy, laid down directly after case
   18's body) vs ours `0x00B6` (the shared break tail used by cases 4/8). The table itself is at
   +0xC4..+0xEB with values relative to base 0xC6, 20 entries; everything else in it matches, so this
   is only "does the empty arm get its own copy of the exit branch".
   Tried and byte-identical: explicit `break;` closing case 18 (variant E1), `case 19: goto lstest;`
   (G2), both together (G3).
2. empty `ssidLength` loop at +0x116: object holds `i` in r0 and the `g_021DCE60_b` base in r1
   (`cmp r0,r1`); ours the reverse (`cmp r1,r0`). Same instruction count. Tried and flat: `i = 0;`
   hoisted out of the `for` header (G1). DWARF lists `i` -> r0, which is the object's colour.

**0x021C84BC** (size-exact, 17 lines / 38 bytes). Object keeps `MemSsl` in r2 and computes
`sub r2,r1,#0x1000` for 0x04000008 immediately before use; ours keeps MemSsl in r1 and hoists the
`sub`. Tried and flat: inlining the `DWCi_Char(PLLT_PUSH.s)` argument (F1, 38), a named `MEMSSL *`
base in front of the last store (F2, 45 - worse), an explicit `volatile unsigned short *pr` for
0x04001008 (F3, 38). The tie is decided by the r1/r2 free-list state after the two `mov r1,r7 /
mov r2,r6` argument setups; it converged again by +0x188 in both.

**0x021BE844** (4 bytes short). DWARF of the object: `i` r14, `ix` r12, `N_BTN` fb+8, `N_SKEY` fb+13,
`N_KEY` fb+18 - i.e. a 0x18 frame whose only extra slot is [fb+4] (`line * 12`). Ours is 0x20: the same
three 5-byte arrays shifted up by 8 with two extra spilled words at [sp+8]/[sp+0xc]. The object loads
`N_KEY[4]` first and interleaves the fifteen initialiser bytes with the `line * 12` setup; ours copies
in order. Existing note (pkt_ov016_021BD8D8.c.txt) already records struct locals and cast-copied
`u8[5]` measuring the same, so this is the 1025 scheduling, not the copy spelling.

Late additions: lane U6 closed 0x021D0B44 mid-lane with the volatile pointer cast
(`*(MemUsbT *volatile *)&g_021DE654` for the second read; see
docs/notes/idiom_volatile-pointer-cast-forces-a-global-re-read.md) - that row is off this slice and is
not mine to claim. Applying the same family of levers here: `const` on the read-only extern
`g_021DCE60_b` in 0x021B87F0 (the "const settles a register tie" idiom) is worse - 476 B vs 464, the
whole prologue recolours - and const on `g_021DCE40` as well does not compile to a match either. The
read-only externs in 0x021C84BC (`scenesetlist_rodata`) are already const and `scenesetlist_bss.MemSsl`
is written by the function, so that tie has no const to add.

Conclusion: this slice is the hard residue of keyboard.o / scenesetlist*.o / usbap.o; every remaining
divergence is either a register-allocation tie inside a single basic block or a duplicated
branch/exit copy - both of which need the Metrowerks 4.0.0.1025 front end that no tools/mwccarm build
writes. No further pin or flag sweep will move these rows.
