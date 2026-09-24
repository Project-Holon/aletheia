# Wave 20, lane nns_fresh (20O)

0x0206F4C8: 2 -> 0, EXACT under ../2.0/sp2p2 (../2.0/sp2 and 1.1p1 DIFF).
Rewritten from the start in the NitroSystem G3D joint-animation scale-fetch
shape: NNS_G3D_JNTANM_SINFO_* flags, FX_Whole frame, one pArray base, goto
SCALE_NONINTERP / SCALE_INTERP_2 tails, (s, invs) pair structs. What moved it:
SCALE_INTERP_2 through one element pointer; the fx32 1:3 arm through element
pointers with the 64-bit product named (`w = (fx64)v * 3`), which fixes the
adds operand order and keeps v/v_sub sharing r6; the fx16 arm by subscript
with the base advanced to the idx_sub element. 10 measurements, no permuter.

0x02067080: 2 -> 2, DIFF (../2.0/sp2). The library-shape rewrite (NNS G2D
DoAffineTransforme_ with the SDK G2_* inlines) converges on the wave-13
source and the same tie: the y read at +0x21C takes ip, the image takes r6.
13 measurements (all 2 or worse, listed in the note). Forms that break the
halfW << 12 CSE do keep halfW live past +0x21C, but only through an emitted
use. Wrapping the body as a static inline stops inlining at that depth, so
DoAffineTransforme_ is its own function as filed. Permuter on the adjust
inline (scratch MUTFUNC copy, tools/ untouched), anneal --types, 1000 at seed
5201 and 1000 at seed 5202 (the second run was an accidental repeat): best 2.

Files written:
- src/matched/func_0206F4C8.c (new, EXACT)
- docs/idioms/a-named-64-bit-product-over-element-pointers-keeps-the-sum-in-place.md
- docs/notes/pkt_0206F4C8.c.txt (closing section)
- docs/notes/pkt_02066E30.c.txt (wave-20 section with the equal-score source)

Shards verified: pkt_0206EB00, manifest --verify --shard twice, second pass
0 rewritten (layout/matched/arm9/pkt_0206EB00.json changed by the first pass).

Seeds: none noticed.

For the integrator: docs/families/cluster_0206EB00.h still lists
func_0206F4C8 as "DIFF (2 bytes, sp2p2)" with the (int *out, int t, Rec *r,
u8 *base) prototype. The filed source uses the same ABI with NNS-style types
(fx32 *, fx32, const pair-info *, const u8 *). Update the header row and
normalise the shape against the siblings if you want them to look the same.
