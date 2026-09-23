# Wave 12, mcss.c, fourth lane: report

**No function reached EXACT, EXACT\* or MATCH, so nothing was filed and no shard was touched.** Three rows moved a long way:

- **The 2164-byte frame walker** had never been transcribed before this lane. It now comes out at the right size with every relocation resolved and 43 bytes out.
- **0x020172D8** went from 82 to 47 bytes out.
- **0x02016C60** went from 103 to 61 bytes out.

The two twins (0x020163C4 and 0x02016630) did not move. Nothing was committed.

Before any source was written, `grep -l "address:  0x<ADDR>" src/matched/*.c` came back empty for all seven addresses.

## Rows (all DIFF; each has a new section appended to its note)

| address | before | now | note |
| --- | --- | --- | --- |
| 0x02014D2C (with 0x02014D90 and 0x02015590) | not transcribed | **2164/2164, 43 out**, all 62 relocations resolved | docs/notes/pkt_02014D2C_boundary.c.txt |
| 0x020172D8 | 82 / 220 | **47** / 220 | docs/notes/pkt_020172D8.c.txt (the integrator already committed this section in d51f3f6) |
| 0x02016C60 | 103 / 870 vs 872 | **61** / 870 | docs/notes/pkt_02016C60.c.txt |
| 0x020163C4 | 16 / 620 | 16 | docs/notes/func_020163C4.c.txt |
| 0x02016630 | 21 / 592 | 21 | docs/notes/func_02016630.c.txt |

Compilers: dsi/1.1p1 is right for every row. `../2.0/sp2` was worse on each residue I tried it on:

- 0x020172D8: 179 bytes out.
- 0x02014D2C: 2304 bytes laid out.
- The twins: already measured by the wave-11 lane.

### 0x02014D2C: the frame walker

- **Shape:** it is one function, `void func_02014D2C(struct McssSys *sys)`, and must be checked with `match.py tu --addr 0x02014D2C --thumb`.
  - The two `bl` long branches come out of the compiler on their own once the size is exact.
  - The relocations resolve as label or literal, except five: 0x0209E090, 0x0209E09C, func_02016FC8, sub_020169D4 and func_020155A0 resolve only as sole-ref.
- **What closed it, in order (draft 2224 bytes, then 1331, then 540, then 44, then 43):**
  1. The rodata vectors are block-local initialisers in the billboard arm; mwcc hoists the copy into the loop preheader itself.
  2. `ctrl` and `nodes` are real pointer locals.
  3. In case 2 of each switch, the animation element is read through one local pointer.
  4. **FX_Mul is an inline function, not the FX_MUL macro.** This was the largest single step (1331 to 1221 bytes out, 60 bytes of size), and it also fixed the push list. I wrote it up as a new idiom.
  5. The drawer calls are written out in both arms of the `b8` test.
  6. Declaration order sets the scalar stack slots.
  7. The first rotation goes through a `u16 rot` local, and `c` is assigned before `s`.
  8. The G3_TexImageParam value is split through an int temporary (found by the permuter).
- **What is left, 43 bytes, all in 0x0201534A..0x0201538A:**
  - The 0x1e of G3_StoreMtx(30) is shared with the TEXIMAGE constant 0x1e<<15 and kept in r5 across `sub_020169D4`; the image loads it again after the call instead.
  - Six things measured flat: SDK inline helpers, casts, const, every split point, defining sub_020169D4 in the same file, and type and declaration-order sweeps.
- **The stock permuter cannot score this function.** It compares against the 100-byte listing extent that ends at the false label 0x02014D90.
  - I wrote a scratch-only wrapper, `scratchpad/w12_mcss/perm_full.py`. It imports tools/permuter.py and overrides `match.target_extent` (2164 here, 870 for 0x02016C60). Nothing in tools/ was edited.
  - Through the wrapper, 900 anneal compiles reached 43 and went no lower.

### 0x020172D8

- **What moved it:** `idx[0]` is assigned before `idx[1]`. The earlier note had fixed the opposite order because this one first came out 216 bytes long. The idx block is instruction-for-instruction right; the 216 came only from `hi` being held in a register.
- From there, permuter hill and anneal plus a declaration-order change gave 47, with the image's frame and all four spill slots.
- **What is left:** one register rotation (a0, k and b0 each land one register over).
- **Excluded, all flat:** anneal 2500 with `--types`, a 300-compile declaration-order search, 64 spelling combinations, and other arithmetic, table-type and helper spellings (listed in the note).

### 0x02016C60

- **The "pad trap" was a scoring artefact.** The permuter scored against the 872-byte listing extent, so any candidate that grew by two bytes looked better.
- Scored against 870 through the wrapper, anneal `--types` went 103 → 81 → 66 → 61, then stayed flat over 6 more seeds.
- What is left is stack-slot numbering of compiler temporaries, plus one scheduled block in the second pass.
- The note's source is the permuter's own spelling (tmp locals), not yet tidied.

### The twins, 0x020163C4 and 0x02016630

New hypotheses, all flat:
- The heap id through a u16 inline helper: 21, unchanged.
- a2 made a memory variable (address taken): no. The prologue becomes `push {r0-r3}` and the reload still lands after the store.
- An inline `Arc(src)` for the first argument, and four inline constructor wrappers that read the src fields inside: 16, unchanged.

## New files and edits

- **docs/idioms/a-nested-fx-mul-keeps-the-inner-product-in-r0-only-as-an-inline-function.md** (new).
- **docs/families/mcss.h, new section 9:**
  - the func_02014D2C prototype;
  - new McssSys fields: +0x2c bit 0, +0x18 texture record, +0x44 scale;
  - new McssWork fields: +0x2c table layout, +0x34 animation controller, +0x74 node array, +0x78 cell chain, +0x9c texture info, the transform block 0xe0..0x184, and flag bits 8, 11, 13 and 29;
  - the byte-visible spellings, and the two moved rows.

## Integrator: seed

- No new unlabelled leaves.
- The known layout action still stands: 0x02014D90 and 0x02015590 are false function starts inside 0x02014D2C (long branches written as `bl`). They come from disasm.py's branch-target rule, not from layout/function_starts.txt.

## Gate

I filed nothing into src/matched or src/pending, so there is no packet to run `manifest --verify` on.

## Housekeeping

- All scratch work is in `scratchpad/w12_mcss/`. Another lane uses `scratchpad/w12/`; I only copied files out of it.
- Three permuter runs outlived the 5-minute foreground limit and were moved to the background. I stopped two of them with `pkill -f perm_full.py` and let the third run to its finished budget. No processes of mine are left running, and no stray files are in the repo.
