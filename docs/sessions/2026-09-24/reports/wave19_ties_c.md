# Wave 19 lane ties_c (19C)

Per address, bytes out before -> after, verdict, what was measured:

- 0x0201C7D0: 2 (sp2) / 37 (1.1p1), unchanged, DIFF. The three-extern lever: under 1.1p1 every one of the 48 code bytes matches the image, but the pool has three words (64 against 56, 10 out, pool only). The image's single pool word means one name, so the lever does not close it. It does show that the only 1.1p1 fault is value-numbering one address across three sites.
- 0x0201DB20: 15, unchanged. Self-assignments at six places, `long hi, lo`, dsi/1.2.
- 0x0201C8BC: 17, unchanged. Block-scope layouts show the rule: the stores use `sp+4 + 4` only when the addressable done slot sits below buf.
- 0x0201D768: 66, unchanged. Self-assignments, 1.2, long n/start/total.
- 0x02011688: 26, unchanged (14-out form confirmed). Long idx forms, else arm written out, 1.2. Permuter seed 2301: nothing valid.
- 0x0202350C: 12, unchanged. kb/k8 order, long, self-assignments, block scope.
- 0x0202627C: 10, unchanged. Tail written out in case 4 (304 B), a u32 bitfield container (296 B), self-assignments, inline helper, cb as u32 or void *.
- 0x020681E4: 10, unchanged. Both logs spelled with an in-place clz give the image's exact shape with only lw/lh exchanged (18). Self-assign and long do not flip it. The permuter cannot parse the asm.
- 0x02071104: 6, unchanged. SDK long typedefs, named locals plus self-assignments.
- 0x02069BA0: 6, unchanged. Long typedefs, long shortfall and n, self-assignments.
- 0x0206F4C8: 7, unchanged. Self-assignments at five places, j-first index spellings.

The self-assignment lever moved nothing here. It still works in the pow unit (25 without it under 1.2).

Files written: notes only (eleven files under docs/notes, each with a "2026-09-24, wave 19 (lane ties_c)" section). No src/matched or src/pending files, no idioms.

Shards verified: none (nothing filed).

Seeds: none new. Permuter seed used: 2301.

For the integrator: nothing to integrate. Worth a ruling: 0x0201C7D0 is code-exact under 1.1p1 only with three names, and the pool word count forbids that.
