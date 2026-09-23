# Wave 11, mcss.c, third lane: report

The lane closed 1 function to EXACT. The other four rows it worked on moved a long way but are still DIFF. The 2164-byte row was surveyed and not transcribed. Nothing was committed.

## EXACT (filed)

| address | size | file | packet | cc |
| --- | --- | --- | --- | --- |
| 0x020155A0 | 1064 (1022 code + pools) | src/matched/func_020155A0.c | pkt_02014D90 | dsi/1.1p1 |

- **What it is:** mcss.c's quad drawer. It sets up G3 (optional frustum), writes the texture palette base and polygon attributes, does translate/rotate/scale, and draws one textured quad. When the slot is not hidden and alpha is non-zero it draws a second quad with polygon id 1. Finally it applies a depth step to `*z`.
  - It takes 4 register parameters and 11 stack parameters; the last is a u8 read with `ldrb`.
  - All 4 relocations resolve: `G3i_FrustumW_` and `G3_RotZ` as label, `FX_SinCosTable_` as literal.
- **No transcription existed.** This row had only a triage note.
- **First draft:** 790 bytes out.
- **What closed it:**
  1. `FX_SinCosTable_` is declared without `const` (the original re-reads the table after the call). This made the size exact: 1064 bytes, 149 out.
  2. `G3_Translate` and `G3_Scale` are written as the SDK inline functions, so all arguments are evaluated before the first register store: 58 out.
  3. The permuter found `expand(cell x2)`: 31 out.
  4. The second `G3_TexPlttBase` is written as the SDK's inline expression, so its 0/1 becomes a compiler temporary at the lowest frame slot. Alpha goes through a block-local, and `polyId` is declared last: 22 out.
  5. **`u32 *z` instead of `fx32 *z` closed the last 22 bytes.** Those bytes were a register tie in the two ±0x100 tails. A 547-mutation hill run, 2000 anneal compiles and a declaration-order search could not move them. This fits the wave-10 lesson that a residue the permuter can't move lives in the declarations.
- **Data flow:** the three call sites in 0x02014D2C (0x020154D0, 0x02015506, 0x02015562) pass a cell record's +0..+0x14 or +0x18..+0x2c words as x, y, width, height, s, t. `pose` and `frame` are sp+0x194 and sp+0x1a4, which are two instances of one 16-byte pose struct. `z` is &sp+0x74. This all matches the prototype.
- Its note (docs/notes/pkt_020155A0.c.txt) has a closing section appended.

## DIFF (appended sections in the existing notes)

| address | before (freshest re-verified) | now | note |
| --- | --- | --- | --- |
| 0x020163C4 | 26 / 620 | **16** / 620 | docs/notes/func_020163C4.c.txt |
| 0x02016630 | 36 / 592 | **21** / 592 | docs/notes/func_02016630.c.txt |
| 0x020172D8 | 183 / 220 | **82** / 220 (permuter line 81) | docs/notes/pkt_020172D8.c.txt |
| 0x02016C60 | 109 / 870 vs 872 | **103** / 870 vs 872 | docs/notes/pkt_02016C60.c.txt |

- **0x020163C4 and 0x02016630.**
  - Moving `flag = 1` out of the second constructor's arguments into a statement after that call fixes one of the four call sites in each twin (26 to 16, 36 to 21).
  - What remains is the known swap of the a2 reload and the a1 copy at the other sites.
  - **Excluded, all still flat:** hill 800 + anneal 2000, all 15 front ends (`../2.0/sp2` shows the same swap), a static inline helper, temporaries, `register`, struct-member spellings, and type sweeps.
- **0x020172D8.** The old transcription had three structural errors:
  1. The list guard is an `if`, not a `while`.
  2. The nibble tests are signed.
  3. The target byte is read once into a local.

  In addition, `b0 >> 1` is a logical shift, and both nibble offsets must recompute from a1 on their second assignment (the dead-store idiom). After fixing these, the permuter and a declaration-order search took it to 82. What is left is `cur` homed at sp+4 instead of ip, and a0 in r3 instead of r2.
- **0x02016C60.**
  - The clip multiplies are `step * i` / `step * j`: 109 to 103.
  - The permuter still walks to 872-byte candidates (the alignment-pad trap), so no permuter result counts here.
  - Split second-half locals in the image's slot order came out worse (132); a random declaration-order search reached 126 at best.
  - Next lever: frame slots seem to follow the order values are created more than declaration order (the 0x020155A0 finding).

## Not attempted

- **0x02014D2C / 0x02014D90 / 0x02015590** (one 2164-byte function, about 1000 instructions). I read it in full but did not transcribe it: it holds 21 `_ll_mul`, a soft-float block, LookAt, MTX and G3 calls, and two loops. I appended a complete map to docs/notes/pkt_02014D2C_boundary.c.txt: signature, frame, every call named (all resolve as SDK, runtime or matched), outer and inner loop shape, the pose struct, and the reverse-draw index. An attempt must be checked with `match.py tu --addr 0x02014D2C --thumb`.

## Family header

docs/families/mcss.h gained section 8:
- the `func_020155A0` prototype;
- new McssSys fields: +0x2c bit 1, +0x48;
- new McssWork fields: +0x78 animation → frame → cell chain, +0xc0 texture format, +0xc8 palette base;
- flag word: alpha is bits 14..22 with 0x20 as the "use b0 >> 1" value; bits 23, 30 and 31 are three separate 1-bit flags (so the 2-bit `b7` is really two fields);
- the four byte-visible declarations from 0x020155A0;
- the `flag = 1` placement for the 0x020163C4 / 0x02016630 twins, and the structural corrections for 0x020172D8.

## Integrator: seed

- No new unlabelled leaves; 0x020155A0 verified EXACT, not EXACT*.
- The only layout action is the known one: 0x02014D90 and 0x02015590 are false function starts inside 0x02014D2C (long `bl` branches), so they need removing from `layout/function_starts.txt`.

## Gate

`python3 tools/match.py manifest --verify --shard pkt_02014D90` passed: `shard pkt_02014D90: 1 shard(s), 2 entr(ies), 1 rewritten`. Both entries are EXACT: 0x020155A0 (new) and 0x020159C8. This is the only packet I filed into.

## Housekeeping

A failed unquoted heredoc created an empty `r0` in the repo root; I removed it. No other stray files are mine. The untracked `src/matched/func_0201C7A4.c`, `func_0201CD10.c`, `func_02022F60.c` and the others belong to other lanes.
