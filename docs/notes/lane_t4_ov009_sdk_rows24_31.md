# Lane T4 — ov009 open SDK rows 24..31

Slice: `python scratch/a2/open_rows.py ov009 24 8` (smallest-first order over the 79 open
ov009 SDK rows). All eight had a parked source already; one closed.

| # | address | bytes | name | library | verdict |
|---|---------|-------|------|---------|---------|
| 24 | 0x02197458 | 244 | gti2BeginReliableMessage | libdwcgsgt2 (gt2message.o) | **EXACT — filed** |
| 25 | 0x0219A52C | 244 | SendConnectAck | libdwcgsnatneg (natneg.o) | parked, 107 B / 45 hunks |
| 26 | 0x02194B74 | 248 | gti2GetChallenge | libdwcgsgt2 (gt2auth.o) | parked, 4 B / 2 instr |
| 27 | 0x02157290 | 256 | reset_network_vars | libcps (network.o) | parked, 16 B / 8 hunks |
| 28 | 0x0215D92C | 264 | SOCLi_CopyCPSBuffer | libsoc | parked, 101 B / 31 hunks |
| 29 | 0x021782B4 | 264 | DWCi_Auth_Start | libdwcauth | parked, 182 B / 56 hunks |
| 30 | 0x021685CC | 276 | DWCi_GetMathRand32 | libdwcmatch | parked, 108 B / 42 hunks |
| 31 | 0x0216C8DC | 296 | DWC_AddMatchKeyInt | libdwcmatch (dwc_match.o) | parked, 134 B / 48 hunks |

Tooling left in `scratch/t4/`: `harness.py` (compile one candidate, report the concrete-byte
delta), `sweep.py` (pin/flag sweep), `triage.py`, `residues.py`, `gen_b*.py` (variant banks),
`d_<ADDR>.txt` (full `match.py one --diff` dumps), `c*_*.c` / `w_*` / `x_*` / `y_*` / `r*` / `b*`
candidate files.

## Filed: 0x02197458 gti2BeginReliableMessage (244 B, EXACT)

`src/matched/ov_sdk/ov009_func_02197458.c`, shard `layout/matched/ov009/pkt_ov009_02197458.json`.

Both failure exits in the function are the same expression,
`return (gti2ConnectionMemoryError(connection) != 0) ? (*overflow = 1) : 0;`.
1.1p1 lowers that as the **taken** arm first — `movne r0,#1; strne r0,[r5]; moveq r0,#0` — which
is 14 bytes out at +0040 and +0074. Inverting the test and swapping the arms

```c
return (gti2ConnectionMemoryError(connection) == 0) ? 0 : (*overflow = 1);
```

makes the compiler emit the else-constant first and the predicated taken arm second, i.e. the
image's `cmp r0,#0; moveq r0,#0; movne r0,#1; strne r0,[r5]`. Same three instructions, same
predicate — only the emission order of the two arms changes. `!gti2ConnectionMemoryError(connection)
? 0 : (*overflow = 1)` is the same codegen. The order of the two arms *with the predicate
unchanged* (`? (*overflow=1) : 0`) does not move it; the test has to be inverted with them.

## Residues of the seven rows left parked

- **0x0219A52C SendConnectAck** (244/244, 107 B, 45 hunks) — first diff **+0000**: image
  `push {r3, r4, r5, r6, r7, r8, sb, lr}` | ours `push {r4, r5, r6, lr}`; then +000C image
  `mov r3, #4` | ours `mov r5, r0`, +0010 image `ldrb sb, [r2]` | ours `ldrb r3, [r2]`. The image
  stages the whole 6-byte `*(NNMagic *)&p = g_021A5A7C` in six registers (sb/r8/r7/lr/ip/r5) with
  the version/packettype constants live in r3/r2 from +000C, and keeps `p`'s base in r4 from
  +0018; ours interleaves load/store through three registers and never needs the wider pool. Whole
  callee-saved set and every constant are upstream different. Tried: field setters before the copy,
  copy after, a named `NNMagic` local, byte-wise element copies, two-word (u32+u16) copy — 107–197 B,
  none better than the parked 107. Same *web-count at the allocation stage* trigger as
  `ov009_libssl_block_flush_index_zero.md`, but no statement position found that adds the three
  live magic bytes.
- **0x02194B74 gti2GetChallenge** (248/248, 4 B, 2 instructions) — **first diff +0084**: image
  `eor r0, r0, r2` | ours `eor r0, r2, r0`, and +0088 image `eor r8, r0, r1` | ours
  `eor r8, r1, r0`. Both are the *same* value, only the commutative operand slots differ; every
  other instruction including the hoisted loads, the four `bl rand`s and the flag-setting compares
  is identical. 26 body spellings tried (all `^` nestings, two-statement splits, `^=` chains,
  named temps, named `b0`/`bp` locals, `? 1 : 0`, `<` vs `>`, unsigned compare, explicit bool
  casts) and 8 compiler pins × 4 flag sets: all give exactly these 4 bytes. The image's operand
  order is neither "left first" nor "older register first" consistently across the four eors, so
  it is the coalescer's choice, not a spellable one.
- **0x02157290 reset_network_vars** (256/256, 16 B, 8 hunks) — **first diff +0010**: image
  `str r0, [r2, #0x4c]` (fills the load-delay slot of `ldr r1,[r1,#0x50]`) | ours `mov r5, #0`.
  Everything after is the image's schedule shifted one slot, plus image `mov r5,#0`/`str r1,[r2,#0x74]`
  swapped with ours' `mov r3,#1`. Both `mov r5,#0` (the ternary's false value) and `mov r3,#1`
  are constants for the `had_ip` test; ours materialises r5 at +0010 and the image at +0030, next
  to `mov r3,#1`. Tried: every position of the reason store (first, after `myip=0`, last, mid),
  the packed pointer form, chained `a=b=...=0`, a local zero, `volatile` forms, `== 0` test
  inversion, `unsigned long`/`unsigned char` `had_ip` — best 12 B, none reaches the delay slot.
  The residue is a single scheduler slot, not a statement order.
- **0x0215D92C SOCLi_CopyCPSBuffer** (260/264, 101 B, 31 hunks) — **first diff +0040**: image
  `beq #0x215d9d0` | ours `beq #0x215d9cc` (branch displacement already 4 short, so an
  instruction is missing before +0040), then +0090 image `bne #0x215d9ec` | ours
  `ldreq r0, [r1, #0xf8]`. Ours if-converts the `+0x90` guard where the image branches; the two
  arms of the early control flow differ in shape before the body is even reached. Not attempted
  beyond triage this lane — the arm-order lever (`lane_s6_ov009_dwc_structures.md` §3) is the
  first thing to try here.
- **0x021782B4 DWCi_Auth_Start** (256/264, 182 B, 56 hunks) — -8 B; **first diff +0004**: image
  `ldr r5, [pc, #0xe4]` | ours `ldr r5, [pc, #0xe0]`, then +0028 image
  `ldr r2, [pc, #0xc0]` | ours `ldr r1, [pc, #0xbc]`, +0030 image `ldr r1, [pc, #0xc4]` | ours
  `add r0, r0, #0x1000`. Pool offsets and a pool-load/`add` order; the whole body follows. Same
  row lane S6 already named (`256/264, -8`), unchanged.
- **0x021685CC DWCi_GetMathRand32** (268/276, 108 B, 42 hunks) — -8 B; **first diff +0008**: image
  `ldr r6, [pc, #0xf0]` | ours `ldr r4, [pc, #0xec]`, then +000C image `mov r5, r0` | ours
  `mov r6, r0`. The ctx/`&seed`/max triple sits one register higher in the image (ctx r6, `&seed`
  r4, max r5) with the ctx literal reloaded for the `stm` that writes `x`; ours takes ctx r4,
  `&seed` r5, max r6 and folds one pool word. The `Rand32` half is exact. Unchanged from lane S6's
  note; a body-shape / web-count lever, not a spelling one.
- **0x0216C8DC DWC_AddMatchKeyInt** (296/296 — size exact, 134 B, 48 hunks) — **first diff +0004**:
  image `movs r6, r1` | ours `movs r7, r1`, then +0014 image `moveq r0, #0` | ours `mov r4, #0`,
  +005C/+0060 image `mov r0, #0` | ours `mov r0, r4`. The parked estimator is right: the *only*
  difference is one callee-saved slot. Ours materialises a zero into r4 at +0014 and keeps it live
  for both `return 0` sites and the `f1 = 0` store (`mov r0, r4`, `strb r4, [r0, r5]`); the image
  rematerialises `mov r0,#0` / `mov r2,#0` at each use and therefore needs one register less, which
  shifts a0/a1/a2 from r8/r7/r6 to r7/r6/r5 and the index from r5 to r4. Tried: split the `a1||a2`
  guard into two ifs, reorder `i = a0-0x64`, `(u8)0`/`(u16)0` zero stores, a `struct Key *k` local,
  `int i = 0` initialiser, u32/u16 typed stores — all 134 B or worse (192–249). The lever is
  preventing that one cross-block constant CSE, which no statement spelling here moved.

## Rule this lane adds to the corpus

*Inverting a ternary test while swapping its arms changes which arm 1.1p1 emits first, even when
the two arms are otherwise unaffected by the swap.* `c ? A : B` lowers to two predicated
instructions (or one, plus the else-constant) whose order follows the arm that carries the side
effect; if one arm writes memory and the other is a constant, the image's order is decided by
writing the constant arm as the *taken* arm (`cond == 0 ? 0 : side_effect`) rather than by moving
the parts around inside the arms. Worth a `docs/idioms/` file if the integrator wants it.

## Not touched

Rows 0..23 and 32+ of the ov009 open list, every other region, `src/pending/**` (write set is
`src/matched/ov_sdk/` plus own shards), `tools/`, `asm/`, other lanes' `layout/` shards.
