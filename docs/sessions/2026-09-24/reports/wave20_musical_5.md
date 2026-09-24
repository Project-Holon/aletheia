# Wave 20 lane musical_5 (20I)

## 0x0200CA98 (musical_dist_save.c, Thumb, 392 bytes): DIFF 89 -> 89

The musical_4 best source was extracted again and measured again: 392/392, 89 out, +0x00..+0xBC byte-exact. No
improvement after 21 hand sweeps (about 600 compiles in all). The permuter was not run.

The register map has not changed. Image: off r0, base r1, chain family r2 (0xFF/eor/lsl, loop row, sel, arm
temps). Compiled: chain r0, off r1, base r2. Under lowest-free assignment the image colours off, then base,
then the chain. Every source measured colours the chain family first: it held r0 in all 21 sweeps, even in
variants where off or base moved (off unnamed: base r1 correct, off r2; inline Tail(): the same). The
lever therefore has to reorder the chain temps against off and base, not off and base against each other.
The tail loop runs at full Thumb pressure (8 low registers live), so the order comes from the optimistic
spill heuristic.

These were measured flat, or worse: all 6 orders of base, off and bit, each crossed with the position of
`i = 0`; integer base (four types); a chain local n (5 types, 7 positions; it is constant-propagated); a
separate tail counter (7 types); no-code self-assignments at every boundary (inert on 1.1p1); variable
identity (y, off and bit, and the counter, in dead variables); types of bit, y, off and base; parameter
types of id, sel and alt (64 combinations, all 89); the tail as a static inline; per-arm row locals, an
OrBit helper and alt copies in the arms; a factored arm tail; 2D row and struct-row bases; p copied into
a local; six loop forms; and mask spellings.

The full list, with the bytes-out figure for each, is in the note under the dated marker
"2026-09-24, wave 20 (lane musical_5, 20I)".

Files written: docs/notes/pkt_0200CA98.c.txt (section added), this report. Nothing was filed in src/, so
no shards needed verifying. No seeds were found.

For the integrator: nothing to do. Untried leads: find which node in the r0 family sets its priority;
find a source that brings the tail's peak pressure below 8 before scheduling; invert the alt arms per arm.
