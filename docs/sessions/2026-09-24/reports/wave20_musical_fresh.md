# wave 20, lane musical_fresh (20Q)

0x0200CA98 (musical_dist_save.c, Thumb, 392 bytes): DIFF 89 -> EXACT
(1.1p1 -O4,p). 14 measurements, no permuter run (not needed).

What moved it: a from-scratch rewrite. struct Blk37 pointer, u16 id, the walk
as func_0200C7C0's do/while with the form path inside the match arm ending in
`break`, and four inline bit helpers on a u16 index (plain FormSetBit /
FormResetBit for the flat form index; SetBit / ResetBit that do `no--` first
for the 1-based species id). The helpers produce the shared off / bit / mask
values the image reuses across the clear loop and all six arms. The closing
fact: a `(u8 *)` cast on every row argument (`ResetBit((u8 *)p->unk1AC[i],
id)`). Without it 1.1p1 reassociates each address as (p + off) + K, holds K in
a register, keeps p in r7 and spills alt; that was the whole tail "rotation"
of waves 19 and 20. With it p + K is the hoisted invariant and p lives at
[sp], as in the image.

Files written:
- src/matched/func_0200CA98.c (status EXACT, packet pkt_0200CA98)
- layout/matched/arm9/pkt_0200CA98.json (written by manifest --verify)
- docs/notes/pkt_0200CA98.c.txt (wave 20 musical_fresh section)
- docs/idioms/a-cast-row-argument-keeps-struct-plus-offset-as-the-loop-invariant.md
- docs/sessions/2026-09-24/reports/wave20_musical_fresh.md

Shards verified: pkt_0200CA98, twice (1 rewritten, then 0).

Seeds: none new.

Integrator: sub_0200C818 is the same SetBit inline (its `(u16)idx - 1` is the
helper's `no--`); its matched spelling could be normalized to the helper form
for code shape if it stays EXACT. docs/families/musical_dist_save.h still calls
func_0200CA98 "NOT matched"; update it. Nothing committed.
