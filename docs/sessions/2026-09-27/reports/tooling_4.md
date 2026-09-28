# tooling_4: overlay ISA evidence, seeds, veneers

Salvaged: the previous run's seeds in layout/function_starts.txt, src/matched/func_0202E930.c and func_0202E938.c, and the match.py edit (from scratch). New: 10 seeds and this report. match.py selftest: 241 cases, 0 failures (10 new).

## 1-2. isa_evidence()

Order: the symbols-line hint alone, when its window holds the address (label, then its own SDK row, else unevidenced); then the site's region (label, then its own row, via the new sdk_region_isa); then the first labelling overlay. 0x021DF490 from ov175 now resolves `arm`, and `thumb` is refused. Over 19801 declarations, 28 lose a foreign-label answer. None gains a conflict.

ov010_func_02169AB8.c with 0x021A153C declared `thumb ov021` is EXACT (81 of 81 relocations; tested on a scratch copy, file untouched). This needed two more seeds: arm9 0x020056BC and 0x02008DF0, already EXACT but unlabelled. The owning lane should flip the symbol line and promote the file.

## 3. Seeds

All requested starts are seeded. I also added ov208 0x021BD360 and 0x021BDBAC and the two arm9 leaves above. Every shard touched verifies EXACT twice. ARM9: 5621 functions, 400832 bytes (+22), open 0. `manifest --check` is clean.

## 4. Findings

- ov172 0x021BE0D4: admitted honestly. The bytes at ov172 0x021B8904 are Thumb that disasm.py has not traced: `movs r0,#0xF7; lsls r0,#2; ldr r0,[r4,r0]; movs r1,#1; bl 0x021BE0D4`, between `pop {r3-r7,pc}` epilogues. It is now seeded. The ov204 bl at 0x021BDCFE is not a witness (another overlay).
- `bx pc` veneers to 0x0689xxxx: 386, all in ov093. lane.py lists 320 of them as open (5120 veneer bytes, 5412 extent bytes; 295 have extent exactly 16). ov095 has 478 open veneers back into 0x021Dxxxx (7648 bytes). These are mwldarm range-extension veneers: the targets are out of bl range. Proposed: a `veneer` class outside the game denominator. This moves the figures, so it needs an owner decision.
- ov208 0x021BD360: function_starts did not carry it, and the listing left it unlabelled. It is now seeded as Thumb from the pool word 0x021BD361 at 0x021BDBA8.
