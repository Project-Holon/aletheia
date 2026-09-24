# Wave 19 lane anime_3 (19S)

0x02011688 (ica_anime.c): 14 -> 14 bytes out, DIFF, unchanged (best 50/56 at 14 out, the big_three
ret-variable source).

From the 52/31 two-return form (named `u32 i = idx % n`, t[i] copies), each lever measured once:
(1) compared field in a local used after the compare 52/32; (2) `u16 m` narrowed compare 56/37 (field
is a 32-bit ldr in the image); (3) modulus-before-compare variants (declare-then-assign, comma
expression, commuted `n == p->f18`, const i, s32 i, function- and block-scope copies of i) all 52/31;
(4) inverted guard 52/34; (5) n is not a parameter; `u16 idx` 52/31 and 52/34 (not value-preserving).
Extra: `idx %= n` with t[idx] 50/25; `u32 i = idx; i %= n;` 50/25 with t[i], 52/26 with &p->f1c[i].
15 measurements (cap). Nothing moved, so there was no combination to make. No permuter run.

Reading: in every spelling where the multiply works on a copy, i coalesces with the call's r1
return. The spellings that home the remainder in r2 (writing it back into the parameter) lose
the multiply copy. The five listed levers are exhausted.

Files written: docs/notes/pkt_02011688.c.txt (dated wave 19 anime_3 section, every measurement,
best-source marker pointing to the unchanged 50/14 source). No src/matched filing, no shard
verified. Seeds: none. Integrator: nothing to do beyond staging the note.
