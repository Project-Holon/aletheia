# Wave 16: __dec2num and the NNS/MSL residues

__dec2num 0x0209739C: DIFF, 718 -> 718 concrete bytes out (1520 of 1524, 1.1p1); nothing moved it. Measured alone on the wave-15 base: outer-scope C89 declarations of the chunk locals (identical), an int sign read early (1528 B, 1059) or late (1520 B, 355 out but constants still at +0x2A0, not the image), a separate digit pointer (737), a chunk count n (identical), for(;;)/break with the found block after the loop (identical), decimals moved outward (718), a DBL_MAX double constant (identical), is_low `!= 0` (713, not closer). First_guess held in registers is 1504 B, so it really is address-taken. A temp-struct swap cannot fit: the 0xfc frame is exactly six decimals plus three doubles. Anneal 1500: size compensation only. All in docs/notes/pkt_0209739C.c.txt.

EXACT 4 functions, in 3 files:
- 0x02099224 fdlibm __kernel_cos: unit anchored at the home-area push, func_02099228 body, upstream k_cos.c verbatim, 1.1p1, EXACT on the first compile (src/matched/unit_02099224.c).
- 0x0206EA00 and 0x0206EA2C: NitroSystem NNSi_G3dGetTexPatAnmTexNameByIdx / PlttNameByIdx in the library's shape. The old "if-conversion wall" was the kept-branches tell; EXACT under ../2.0/sp2 (src/matched/unit_0206EA00.c, 88 B tu-EXACT). Replaces src/pending/unit_0206EA00.c. That deletion was in the index and went into integrator commit b7e5af9.
- 0x0206DBF4: the gecom.c DMA-completion leaf, 1.1p1. It witnesses func_0206DC00's ABS32 site. func_0206DC00 stays MATCH (12 of 14 resolved), capped only by the two TWL-ltd PC24 targets.
MATCH 0 new.
DIFF, notes appended with a best-source marker:
- 0x02098B44 __ieee754_rem_pio2: fdlibm verbatim. Under 1.1p1 one stm against the image's str pair (1756/1760). Under dsi 1.2..1.6sp2 it is 18 out, prologue only. MATCH-capped anyway by npio2_hw 0x020A6320.
- 0x020681E4 GetCharIndex1D: verbatim library 18 out under every 2.0 patch. The wave-11 source (10 out) stays the best.
- 0x0209D7D4: the image shape is two tail-merged calls. The residue is the zero built in r2 and copied into r1 (72 B, 43 out).
Not code: 0x020A8FE6 (Thumb-2 data blob) and 0x0209C2B8 (runtime divide body; belongs in runtime_arm9.txt). Not attempted: 0x02094798 (documented strcpy tie).

New FRONTEND-PINS row: src/matched/unit_0206EA00.c, ../2.0/sp2, kept-branches tell.
Integrator: seed 0x0206DBF4 (ARM, src/matched/func_0206DBF4.c, pkt_0206DC00), currently folded into func_0206DBDC's extent.
Shards verified twice: pkt_02099224, pkt_0206EA00, pkt_0206DC00 (all entries EXACT).
