# Lane S6 — ov009 DWC structure rows (libdwcgsgp / libdwcmatch / libdwcauth / libdwcgscommon)

Lane S6, wave a2. Scope: the 15 `class == structure:*` rows of ov009 whose addresses
sit in libdwcmatch, libdwcauth, libdwcgscommon, libdwcgsgp, plus qr2_parse_queryA
(libdwcgsqr2) which this lane was handed by name. Lane S7 owns the libdwcutil /
libssl / libcps / libcrypto rows of the same region.

Tooling left in `scratch/s6/`: `dis.py` (reads `asm/overlays/ov009.s` by address —
including the `.inst` out-of-region calls, which the disassembler prints as a comment),
`cmp.py` (aligns the image listing against `match.py one --diff`'s compiled column with
`difflib`, so real hunks separate from relocation/pool-offset noise), `sweep.sh`,
`tails.py`, `triage.py`, `firstdiff.py`, per-row dumps `s_<ADDR>.txt`.

## Two source shapes that closed most of the two big gsgp rows

### 1. The four-`atoi` IP pack is a *masked-shift* chain, and the term order is load-bearing

`gpiProcessRecvBuddyStatusInfo` (0x02187D60) and `gpiProcessRecvBuddyMessage`
(0x021870B8) both build a 32-bit value from four `atoi` results. The image emits
11 instructions (4 `bl atoi` + 2 `lsl` + 2 `lsr` + 4 `and` + 3 `orr`); the parked
`(atoi << 24) | (atoi << 16) | (atoi >> 24) | ((atoi >> 8) << 8)` collapses to 6
instructions because 1.1p1 folds each shift into the `orr` operand and drops the
masks. The image's shape is exactly what the compiler emits for an explicitly
masked chain (`lsl`/`lsr` then a separate `and`), and the shifts are `<<24`, `<<8`,
`>>24`, `>>8` — not `<<24`, `<<16`, `>>24`, `>>8`:

```c
    v = (((unsigned int)atoi(buffer) >> 24) & 0xff) |      /* emitted first */
        (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
        (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
        (((unsigned int)atoi(buffer) << 24) & 0xff000000);
```

The `(unsigned int)` casts are required (the image uses `lsr`, not `asr`). The
*order of the four terms in the source* decides which register each `atoi` result
lands in: written `<<24,<<8,>>24,>>8` the compiler hoists the calls as
`(4th,3rd,1st,2nd)`, written `>>24,>>8,<<8,<<24` it hoists them `(1st,2nd,3rd,4th)`,
which is what the image shows (1st call feeds the `<<24` term, 2nd the `<<8`, 3rd the
`>>24`, 4th the `>>8`). Only the second order reproduces the image's register
assignment. A standalone probe file (`scratch/s6/pack.c`, functions `pack0..pack5`)
is how the mapping was pinned down without recompiling the 2 KB body each time.

Effect on `gpiProcessRecvBuddyStatusInfo`: 2204 -> 2264 bytes compiled, i.e. the whole
60-byte gap was this one expression shape (three occurrences).

### 2. A guard that shares the function's exit must be folded into the taken arm

`if (p->unk20 != 0 || p->unk2c != 0) return 0;` compiles to a predicated
`movne r0,#0; addne sp,#0x14; addne sp,#0x400; popne {...}`; the image instead has a
real `bne` into the single shared `return 0` block at the end of the function. Invert
the test and put the rest of the body in the taken arm so both failures reach one
`return 0`:

```c
    if (profile->unk20 == 0 && profile->unk2c == 0) {
        ... whole body ...
    }
    return 0;   /* one copy, reached by the guard and by callback.fn == 0 */
```

Same rule as `docs/idioms/a-bare-constant-return-guard-is-predicated-unless-its-exit-is-shared.md`.
Applying it took `gpiProcessRecvBuddyStatusInfo` from -15 instructions to size-exact.

### 3. Arm order decides if-conversion in an if/else whose other arm has a call

In `gpiProcessRecvBuddyStatusInfo`, `if (profile->unk8 == 0) {A} else {B}` (A = the
short assignment arm, B = the arm that calls `gpiRemoveBuddyStatus`) makes 1.1p1
branch over A (`bne`/`b`), one instruction longer than the image. Writing the *call*
arm first —

```c
        if (profile->unk8 != 0) { B } else { A }
```

— makes the compiler predicate A and jump over B with a single `beq`, which is the
image's shape. Same statements, same semantics, one instruction different.

## Row-by-row residue after this lane

| address | function | bytes (compiled/image) | residue |
| --- | --- | --- | --- |
| 0x02187D60 | gpiProcessRecvBuddyStatusInfo | 2260/2264 | -4 B: exit of the `callback.fn != 0` arm. Image `cmp r0,#0; addne sp,#0x14; addne sp,#0x400; popne` falling into the shared `mov r0,#0`; ours returns r0 straight (`add sp; add sp; pop`). The two blocks are adjacent and mwcc duplicated the epilogue here instead of routing the arm through the shared zero exit. Everything else — all three packs, the guard, the arms, both `memset`/`strzcpy` sites, all 18 pool words — is byte-identical |
| 0x021870B8 | gpiProcessRecvBuddyMessage | 3212/3240 | -7 instr: first real diff at +0x11C, image `mov fp,#1` | ours `bgt #0x218770C`. 4.0.0.1025 hoists the error constant 1 into fp after the date parse and rematerialises `&buffer`; 1.1p1 hoists `&buffer` into fp and emits `mov #1` per arm. Also 1025 inlines the 0x1c zero fill as a 7x4 `strb` loop where 1.1p1 calls `memset`. Not closeable here: the image's compiler (4.0.0.1025) is not in `tools/mwccarm`; 1.1/1.2/1.2p1/1.3 all give 3212 |
| 0x0219C7C0 | qr2_parse_queryA | 1472/1532 | -15 instr: prologue. Image `push {r4,r5,r6,r7,r8,sb,sl,fp,lr}` / `sub sp,#0x18c`; ours `push {r3,...,lr}` / `sub sp,#0x188`. Parameter registers are assigned differently at entry (`mov r7,r3; mov r6,r1; mov sb,r0; mov r8,r2` vs ours `movs sb,r0; mov r7,r2; mov r6,r3`), so the whole body diverges. Only the tail (`SEND` block) and the 18 pool words line up |
| 0x021685CC | DWCi_GetMathRand32 | 268/276 | -8 B: image keeps ctx in r6 / `&seed` in r4 / max in r5 and reloads the ctx literal for the `stm` that writes `x`; ours allocates ctx r4, `&seed` r5, max r6 with one pool word. The `Rand32` half is exact |
| 0x0216980C | func_0216980C | 184/180 | +4 B: instr 1, image `ldr r4,[pc]` then `mov r5,#0`; ours `mov r5,#0` then `ldr r4,[pc]` — two declaration/initialiser orders |
| 0x0217273C | func_0217273C | 384/380 | +4 B: instr 0, image `push {r3,r4,r5,r6,r7,lr}`; ours `push {r4,r5,r6,lr}` — one extra live value at entry (`mov r4,#0` + `mov r6,sp+8` frame shape) |
| 0x02176164 | func_02176164 | 236/240 | -4 B: +0x090, image `mov r7,r0` (base kept raw, both `+0x54`s added late, `d` in lr/ip); ours `mla r0,r4,r5,r0; add r4,r4,#1; add r7,r0,#0x54` — the copy destination address is formed early. Tail (`return 1` path) is exact |
| 0x02176CF8 | func_02176CF8 | 236/244 | -8 B: instr 1, image `ldr r3,[pc]` (then `ldr r2,[r3,#4]`); ours `ldr r6,[pc]` — pool base in a different register, everything downstream shifts |
| 0x021782B4 | func_021782B4 | 256/264 | -8 B: +0x028, image `ldr r2,[pc,#0xc0]; ldr r1,[pc,#0xc4]; add r0,r0,#0x1000`; ours loads the second pointer first and folds the `+0x1000` differently |
| 0x0217CF5C | func_0217CF5C | 564/556 | +8 B: instr 31, image `ldr r2,[sp,#0x140]`; ours `ldr r1,[sp,#0x140]` (one stack slot reloaded into a different register, one instruction later). Also two `@18`/`@20` compiler-template literals are undeclared in `symbols:` |
| 0x0217D8E0 | gsLargeIntDiv | 32/36 | -4 B: instr 1, image `mov lr,r1; mov ip,r2; str r3,[sp]`; ours `str r3,[sp]; mov ip,r1; mov r3,r2` — 1.1p1 does not produce the vendor's lr/ip parameter shuffle. Seven spellings + cc 1.1..2.0 tried by earlier lanes |
| 0x0217D904 | func_0217D904 (gsiLargeIntDiv) | 936/928 | +8 B: instr 2, image `mov r5,r1`; ours `mov r8,r1` — parameter register naming from entry onward |
| 0x02189780 | gpiRecvToBuffer | 520/524 | -4 B: the GSIDebug raw-dump call site. Image orders `ldr r1,[r0,#4]; mov r0,#1; str r1,[sp]; add r2,r1,#1; ldr r1,pool; str sl,[sp,#4]; str r2,[r1,#4]`; ours hoists the pool load and merges the two spills into `stm sp,{r3,sl}`. Additionally capped at MATCH by two pool literals (`g_021A4568`, `g_021A458C`) with no witness outside the function |
| 0x0219091C | func_0219091C | 232/9460 | the residue index's `extent` (9460) is not a function extent — the image block is 232 bytes of code with a following data blob. Not a `structure` row in any useful sense; left alone |
| 0x021986C4 | func_021986C4 | 328/324 | +4 B: instr 11, image `beq loc_021987E4`; ours `beq #0x21987E8` — one instruction of layout upstream (the `r5`/`r4` accumulator choice at instr 44 `moveq sl,r5` vs `moveq sl,r4`) |
