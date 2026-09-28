# tree_ov170_6 report

## Seeds (layout/function_starts.txt, ov170 only; listing regenerated with `python tools/disasm.py overlay 170`)

- 0x021EBB1C Thumb, witness bl at 0x021E7B6E (func_021E7A10). 0x021EBB28 and 0x021EBB34 were already labelled and already matched in src/matched/ov/func_021EBB28.c and func_021EBB34.c (pkt_021DC9A0), so the pending copies src/pending/ov/ov170_func_021EBB28.c and ov170_func_021EBB34.c were duplicates and are deleted.
- 0x021DEB08 was already seeded and labelled; only its C was missing.
- NEW 0x021E2648 Thumb tail thunk to func_021E9284, witness: pointer word 0x021E2649 at 0x021EFABC (state handler table). It sat inside func_021E24EC's extent.
- 021DD718 left pending (ARM9 seed owned elsewhere).

ovstats ov170: before `57018 / 54300, 572 funcs, 371 matched, 95.23%`; after the 021EBB1C seed `57026 / 54288, 573, 371, 95.20%`; final `57030 / 60836, 574, 391, 106.67%`. Integrator: matched exceeds code. The ov170 shards have no duplicate addresses (checked), so ovstats is over-counting ov170, and the 95% baseline was already inflated (lane.py still lists 34 open functions of 200 to 360 bytes). Please check this before quoting the ov170 figure.

## Filed: 23 EXACT, all shards verified twice (second pass 0 rewritten), `manifest --check` clean

Promoted from pending: ov170_func_021EBB1C, 021E7A10, 021E152C. New: 021DEB08, 021E2648.
Roots: 021E2334 (case order: case 1 is written before case 0 in both switches; u16 read for the second 0xA16C test), 021E87A0, 021E644C (case 0 falls through into case 1), 021ED370 (loop rows as a byte offset `i * 0x18 + 0x138` from the table base, unsigned i), 021E594C, 021E5AD4 (empty cases -8, -7, -3, -1 give the compare tree and table; locals declared `b, a`), 021E8A74, 021ECDF4 (unsigned loop), 021DEDD8 (single exit with the NULL case in the else; the gender getter returns u8; the showgender test is inverted), 021E5C5C, 021E73D8 (template 021E6A60), 021E81D0, 021DC9E0, then band rows 021E24EC and 021E087C (template 021DFA30).

Files: src/matched/ov/ov170_func_{021EBB1C,021E7A10,021E152C,021DEB08,021E2648,021E2334,021E87A0,021E644C,021ED370,021E594C,021E5AD4,021E8A74,021ECDF4,021DEDD8,021E5C5C,021E73D8,021E81D0,021DC9E0,021E24EC,021E087C}.c with shards layout/matched/ov170/pkt_ov170_<same>.json; deleted src/pending/ov/ov170_func_{021EBB1C,021EBB28,021EBB34,021E7A10,021E152C}.c; layout/function_starts.txt (two ov170 lines). Permuter not used. No new idiom file.

## Next lane (lane.py --band 200 360 --regions ov170)

021E0778, 021E1E80, 021E21A0, 021E2B88, 021E3258, 021E35D8, 021E432C, 021E543C, 021E695C, 021E7298, 021E7D64, 021E7E54, 021E8024, 021E83C0, 021E8508, 021E85F0, 021E8950, 021E8E24, 021E91A0, 021E92A8, 021E95F8, 021E96E8, 021E9848, 021E9B74, 021EAFBC, 021EC0DC, 021ECCCC, 021EDC0C, 021EE120, 021DE7C8, 021DE8B4, 021DEB90; then 021DCB8C (near miss, not attempted).
