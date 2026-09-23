# wave 18, lane dec2num_fresh

0x0209739C (MSL __dec2num, 1492 code bytes, extent 1524): DIFF 718 -> EXACT
(1.1p1 -O4,p; EXACT under dsi/1.2 as well, filed 1.1p1). 13 measurements, no
permuter.

What moved it: a fresh MSL-layout rewrite. The first draft already put the
refinement loop's invariants (&x64, &dec, the `& 1` mask's zero) in the loop
preheader. The piece that closed it: the loop head is `if (is_low) { ++*ll;
if (isinf(guess)) goto done; } else --*ll;` with no is_high variable. The image's
`mov r7, #1 / movne r7, #0` before the loop is 1.1p1's negated if-condition
(!is_low) hoisted as a loop invariant. Writing is_high = !is_low with
`if (!is_high)` gives the same loop instructions, but moves the invariants to
+0x2A0 (the 721/1520 wall of waves 9 to 17). Other facts: `unsigned char sign`,
`int is_low = 0` set by `if (__less_dec(...)) is_low = 1`, `ll = (u64 *)&guess`
initialised at its declaration, the double swap written after the struct swap,
the struct swap through the later difflow decimal (six decimals, frame 0xfc).

Files written:
- src/matched/func_0209739C.c (status EXACT, packet pkt_0209739C)
- layout/matched/arm9/pkt_0209739C.json (written by manifest --verify)
- docs/notes/pkt_0209739C.c.txt (wave 18 fresh rewrite section)
- docs/idioms/negated-if-condition-is-hoisted-as-a-loop-invariant.md

Shards verified: pkt_0209739C, twice (1 rewritten, then 0). Evidence: sole-ref
self:0x020A8A7C (pow_10), string:0x020A8B90.

Seeds: none new.

Integrator: kind is recorded as `game` (same as the pkt_02096D10 neighbours,
although this is MSL code); reclassify if the runtime rows should own it. Older
notes (docs/notes/pkt_02094B8C.c.txt) say 0x02094B8C was capped by this function;
worth re-checking now.
Nothing committed.
