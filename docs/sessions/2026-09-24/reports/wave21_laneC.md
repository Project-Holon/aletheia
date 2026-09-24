# Wave 21, lane C: 0x02067080 (g2d DoAffineTransforme_)

**Verdict: DIFF 2, unchanged.** The best source is still the wave-13 source in
`docs/notes/pkt_02066E30.c.txt` (704/704, 2 bytes out under `../2.0/sp2`). The y
read at +0x21C lands in ip, where the image has r6. I re-verified it with
`match.py one` at the start of the lane.

## Provenance

Before the owner's rule change I read the ntrtwl/NitroSystem reconstruction:
g2di_OamUtil.h, g2d_RendererCore.c/.h and its meson.build, with the build flags
`-ipa file -inline on,noauto -gccext,on`. The measurements taken from it are
tagged `[ext]` in the notes: the library flags, the verbatim inline under those
flags, the enum-typed overwrite field and a static DoAffineTransforme_. None of
them moved the residue, and nothing filed depends on them. I deleted the
downloaded copies from scratch and consulted nothing external after the rule.

## What was tried (about 160 hand compiles, plus 12,600 permuter compiles)

- **Front ends:** every 2.0 build (base through sp2p4) gives the same residue.
  dsi 1.2p1/1.2p2/1.3/1.3p1/1.6sp1/1.6sp2 give 676 bytes, and 1.2/sp4 gives 740.
  No front end separates the tie.
- **Library flags [ext]:** `-ipa file`, `-inline on,noauto` and `-gccext,on`, in
  every combination, all 2. The verbatim inline is 696 bytes with or without them.
- **New spelling classes, all 2 or worse:**
  - the overwrite arm: switch, mode local, enum field, one call per arm;
  - the flag: scope, const-ness, ternary, a local for the effect, computed inside the inline;
  - the y side: volatile, pointer, `(&x)[1]`, const temporaries, const dy chains;
  - dying-local reuse: x_new and y in one local (the 2026-09-24 idiom);
  - per-axis nested inline helpers (74..87 bytes out);
  - the double block with CSE broken;
  - types: SDK unions for MtxFx22 and GXOamAttr, `*const` inline parameters, sizes by value;
  - caller pointer locals, and a static function with a caller.
  The notes give the full list with bytes out.
- **Permuter** (scratch copy with MUTFUNC, anneal --types): 3000 on the adjust
  inline, 3000 from item 1, 2000 on MulMtx22, 1000 on RemovePosition, 600 on
  G2_GetOBJEffect and 3000 on the function body. Every best result is
  `DIFF asm=10 bytes-out=2 size=704/704`.

## Reading

The colour choices in the block fit greedy colouring in the order r0-r3, ip, lr,
r4..., with `dy +=` coalesced. Under that order the image's r6 for the y read
needs ip held across +0x21C by a value that no image instruction names. No
spelling here creates such a value without also emitting a use of it.

## Files touched

- `docs/notes/pkt_02066E30.c.txt`: one appended dated section, "2026-09-24, wave 21 (lane C)".
- `docs/sessions/2026-09-24/reports/wave21_laneC.md`: this report.

There is no source in `src/matched/` or `src/pending/`, and no shard was written
(nothing reached MATCH or EXACT). `tools/` and `layout/` are untouched.
