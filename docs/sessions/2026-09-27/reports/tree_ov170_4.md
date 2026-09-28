# tree_ov170_4 report

## Totals

- 21 new EXACT functions.
- 1 MATCH in src/pending, blocked by one seed.
- Every shard was verified twice, and the second pass rewrote nothing.
- `manifest --check` is clean.
- I did not use the permuter.

## Trees (all ov170)

| function | verdict | what closed it |
|---|---|---|
| 021E6EC0 (root, 920 B) | EXACT | template 021E5E68, first draft |
| 021EA598, 021EA66C | EXACT | templates 021EA1F4 and 021EA2DC |
| 021EEB40 | EXACT | twin of 021EE8A8; the range test is spelled `r - 9 <= 2` |
| 021E65E4 (root, 888 B) | EXACT | template 021E3E84 (not 021E376C) |
| 021EA39C, 021EA458 | EXACT | templates 021EA1F4 and 021EA39C; the parameter is unsigned (`bhs`) |
| 021EA514, 021EA4DC, 021E1458, 021DDE80 | EXACT | first drafts |
| 021E152C | MATCH | see the seed below |
| 021E0ABC (root, 916 B) | EXACT | template 021DFA30 (see below) |
| 021E1628 (root, 864 B) | EXACT | twin of 021E0ABC |
| 021E0FB0, 021EA878, 021ED108 | EXACT | 021EA878 needed the call written in each arm |
| 021EB378 (root, 864 B) | EXACT | window size locals declared u8 (new idiom) |
| 021E0FD8, 021E1324 | EXACT | state-machine siblings |
| 021E1B1C (792 B) | EXACT | template 021DFA30; `busy` is written as if/else; the `r = 0xFF` store comes before the byte store |
| 021E75E0 (788 B) | EXACT | template 021E5E68 |

What closed 021E0ABC:
- The two "fall back to p[0x16]" arms are an if/else-if, not an `||`.
- The spill slots follow declaration order.

## Files

- src/matched: ov170_func_{021E6EC0, 021EA598, 021EA66C, 021EEB40, 021E65E4, 021EA39C, 021EA458, 021EA514, 021EA4DC, 021E1458, 021DDE80, 021E0ABC, 021E1628, 021E0FB0, 021EA878, 021ED108, 021EB378, 021E0FD8, 021E1324, 021E1B1C, 021E75E0}.c, plus their pkt_ov170_* shards.
- src/pending: ov170_func_021E152C.c (MATCH).
- New idiom: docs/idioms/u8-size-locals-keep-the-loop-guard-on-a-spilled-cse.md

## Seed (integrator)

- 0x021DEB08 (ov170, Thumb) is an unlabelled thunk: `ldr r3, =func_021DEA6C; movs r1, #0; bx r3`. It is printed as `.word` data after func_021DEAFC's pool.
- Witness: bl at 0x021E15C4 (021E152C+0x98).
- Seeding it promotes 021E152C to EXACT.

## Next lane (ov170)

These roots are real and I have not started them. The biggest first:
- 021E0200 (624 B): a state machine in the 021DFA30 family. Its open callees are 021DDAE8 and 021DE428.
- 021E8BF8 (556 B)
- 021DCB8C (556 B)
- 021E3340 (552 B)
- 021E3C88 (508 B)
- 021E0470 (508 B)
- 021E6A60 (476 B)
- 021E99B0 (452 B)
- 021E7A10 (448 B)
- 021E6D00 (448 B)

The menu handlers close from the templates 021E5E68, 021E3E84 and 021E376C. The state machines close from 021DFA30 and 021E0ABC.
