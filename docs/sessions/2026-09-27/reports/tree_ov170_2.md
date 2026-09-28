# tree_ov170_2 report (relaunch)

## Salvaged from the cut run (uncommitted, re-verified)

I re-verified 34 ov170 sources in src/matched, each with its shard in layout/matched/ov170. Every shard was verified twice and the second pass rewrote nothing. Results: 31 EXACT, and 3 EXACT* (021EB324, 021EB988, 021EF248).

Addresses: 021DF040 021E2650 021E2CBC 021E3E84 021E4504 021E4F60 021E954C 021E9C94 021E9CE0 021E9D2C 021E9E7C 021EA064 021EA14C 021EA798 021EA808 021EA9F4 021EAA3C 021EB324 021EB988 021EBEE0 021ECB84 021ECC1C 021ED094 021ED310 021ED594 021EE57C 021EE65C 021EE754 021EE850 021EE96C 021EECE4 021EF1D4 021EF248 021EF508.

Two salvaged pending files are real MATCH, so they stay in src/pending:
- src/pending/ov170_func_021DF484.c (root)
- src/pending/ov170_func_021EA0BC.c

Both are blocked by one thing: ARM9 0x02026124 is an unlabelled Thumb function.

## New this run

| function | verdict | what closed it |
|---|---|---|
| ov170 021E9D98 (salvaged DRAFT) | EXACT | store p->b1A before p->next (store order recolours the zero) |
| ov170 021E5E68 (root, 1108 B) | EXACT | sibling template (021E4F60); clamp spelled as if/else stores, not a ternary |
| ov170 021EEA48 | EXACT | twin of 021EE57C; range test as `r - 0x24 <= 2` |
| ov170 021EA1F4 | EXACT | first draft |
| ov170 021EA2DC | EXACT | first draft |
| ov119 021DBE70 (root, 1088 B) | DIFF, 6 B | see docs/notes/pkt_ov119_021DBE70.c.txt |

Status of the ov170 roots: all seven are EXACT except 021DF484, which is MATCH.

For 021DBE70, the residue is a swap of r1 and r3 in one bound block. The following levers closed the rest of it:
- func_021DB7AC takes three arguments.
- The out-parameter is copied to a register local.
- The rest of the function sits in the default arm of the func_021D9F24 switch.

I ran the permuter once (seed 9001), and it made no gain.

## Files

Written:
- src/matched/ov170_func_{021E9D98,021E5E68,021EEA48,021EA1F4,021EA2DC}.c
- the five matching shards pkt_ov170_*
- src/pending/ov119_func_021DBE70.c
- docs/notes/pkt_ov119_021DBE70.c.txt

Deleted: the untracked pending copies of 021E9D98 and 021E5E68 (both promoted). `manifest --check` is clean.

## Seeds

These are unlabelled ARM9 Thumb starts. They show as `.word` in asm/arm9/main.s.
- 0x02026124: witness is the bl at ov170 0x021DF6AE (021DF484+0x22A) and at 021EA0FE. Seeding it closes both MATCH files as EXACT.
- 0x0202614C and 0x0202616C: these are adjacent leaves in the same `.word` run, and each starts with a push or with code.

## Next lane

- ov119 021E049C (1100 B): not started.
- ov119 021DBE70: 6-byte residue.
- ov170: about 250 smaller functions are still open.
