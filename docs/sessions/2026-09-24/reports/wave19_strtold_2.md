# Wave 19 lane 19F (strtold_2) report

0x02094B8C, MSL __strtold (C99), ARM, 1.1p1 -O4,p:
before: 3860 of 3864 bytes, DIFF (19A best).
after: 3864 of 3864 bytes, 90 concrete bytes out, DIFF. dsi/1.2 gives the same bytes.

What moved it:
- The digit-limit 14 is now a variable, `unsigned maxdigits;` at function
  scope, assigned `maxdigits = 14;` in the hex_start arm and tested by
  both digit arms. This gives the image's `mov r0,#0xe; cmp r2,r0` and
  `mov r0,r2` exactly. It also closed the entry zero-chain residue
  without any edit at the entry.
- The 11-bit exponent mask is written as `(unsigned)(expsign << 21) >> 25`
  and `>> 17`. That gives the image's shared `lsl #21`. With `& 0x7FF`,
  mwcc built the mask from the ~0x7FF register.
- Remaining: a register rotation in the hex tail, +0x0D0C..+0x0EE4 (p is r4
  in the image and r2 here; ui, uch and chindex shift with it). No lever
  moved it: long types, declaration order, block scope, self-assignments,
  a pointer copy, `register`, and dsi/1.2.

Measurements: 24 by hand plus the permuter (tools/permute.py hill, 1439
compiles, seed 2601). The permuter found nothing better than 90; its top
candidates all tie. Every measurement is in the note.

Verdict: DIFF. The best source is in docs/notes/pkt_02094B8C.c.txt under the
"2026-09-24, wave 19, lane 19F" best-source marker. Nothing is filed in
src/, and no shard was verified.

Files written:
- docs/notes/pkt_02094B8C.c.txt (appended)
- docs/idioms/a-constant-compared-from-a-register-is-a-variable-assigned-in-another-arm.md (new)
- this report

Seeds: none noticed.

Integrator: the ceiling stays MATCH even at exact bytes, because
__double_huge has no outside witness and there are two anonymous string pool
words. Levers not yet tried for the rotation: a declaration-order sweep of
the tail variables with maxdigits in place, a while or guarded-for shape
for the tail loops, and hexresult at function scope. The idiom index needs
a rebuild.
