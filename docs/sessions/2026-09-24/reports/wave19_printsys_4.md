# Wave 19 lane printsys_4 (19W): report

Lever under test: the 19L dead definition (redundant initialiser, `x = x;`,
a use after a call) to change web colouring order. Result: flat on all three.

| address | before | after | verdict | measurements |
|---|---|---|---|---|
| 0x0201D768 | 92/63 (1.1p1) | 92/63 | DIFF | 12 |
| 0x0201DB20 | 154/15 (1.1p1) | 154/15 | DIFF | 10 |
| 0x0201C7D0 | 56/37 (1.1p1; sp2 2) | 56/37 | DIFF | 12 (1.1p1 only) |

- 0x0201D768: head dead-initialised at function or block scope, `head =
  head;` at the loop top, after the call, at the loop end and after the loop,
  total initialised at the declaration or declared and zeroed last: 63 or 65
  (the surviving init only reorders the entry block). A real early def of
  head (`head = p[0]; start = head;`) 90/76. Total stays in r7, the loaded
  head is still spilled.
- 0x0201DB20: dead `= 0` on m, hi, lo; `hi = 0;` at the loop top, at the
  chain step and at the top of case 2; `m = m;` around hi's def, before the
  case-2 break and in the else arm: 15 in every case. m's web already starts
  at entry, so an earlier def has nothing to extend.
- 0x0201C7D0: `z = z;` after the last call, between the calls, before them;
  z through a copied, block-scope, or dead-initialised local; `z = (s16)z;`;
  the address through a dead-initialised pointer local assigned once or per
  call; all five arguments through locals (with and without dead inits):
  37 in every case. The early `str r4, [sp]` does not move.

Reading: on these three, mwcc removes the dead defs and self-assignments
before colouring and scheduling, so the lever that moved strtold's ui (a
web spanning a long loop with many defs) does not apply.

Files written: appended dated sections (no source change) to
docs/notes/func_0201D768.diff.c.txt, docs/notes/sub_0201DB20.c.txt,
docs/notes/pkt_0201C7D0.c.txt; this report. Nothing filed in src/matched;
no idiom file (nothing closed); no shards verified; no permuter runs
(seeds 4001 to 4049 not used). No unlabelled starts seen. Integrator: nothing to do
apart from staging these four files.
