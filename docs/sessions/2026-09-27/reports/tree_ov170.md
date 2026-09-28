# tree_ov170 report

Tree: ov170 root func_021DFA30 (1532 B, a 17-state switch with a pool in the middle of its body). It has 49 open functions, 4 of them unlabelled leaves. I closed the tree bottom up: all 49 are filed EXACT or EXACT* (the EXACT* cases are 2 bytes of trailing padding). No MATCH or DIFF left, and I did not use the permuter.

Files: src/matched/ov170_func_<addr>.c (49) and layout/matched/ov170/pkt_ov170_<addr>.json (49). I verified each shard twice and the second pass rewrote nothing. `manifest --check` is clean.

Functions: 021DFA30 021DE158 021DDC00 021DD930 021EDD38 021DE66C 021DDEFC 021DE07C 021EC804 021EC35C 021DEC98 021DD16C 021DD090 021DCFC0 021EE038 021EC5A0 021ED6E4 021ED75C 021ED7C4 021EB874 021EB7E8 021EC8E4 021ECBD8 021EE364 021EE26C 021EDF5C 021EF400 021EF534 021EF57C 021E00C4 021E0128 021E19D4 021E1A28 021DF43C 021DF1DC 021DD694 021DD25C 021DD2D0 021DE5C8 021EC548 021EC0B0 021EC768 021EC7B8 021ED55C 021EE244 021EE3E4 021EF1B4 021EF1C4 021EF264.

What closed them, in the order of the idioms index:
- Unsigned loop bounds.
- `int j` compared with `8u`, which stops the `j + K` CSE (021ED75C, 021EDD38).
- Declaration order of spilled locals (021EC804, 021DEC98).
- Source order of the switch and if arms (the root, 021DDEFC).
- A local set by both arms for a flag return (021EF400).
- The accumulator operand order in a multiply (021DD930).
- An element pointer local ahead of a u16 temporary (021DE158).
- A field struct at 0x1A6, spelled as an offset of a large struct and not as a separate pointer (021DD090).
- `int k` for a byte index (021EC5A0).

No new idiom file.

Seeds (unlabelled starts, all now EXACT, every witness a `bl` in the root):
- 0x021DE5C8 (site 0x021DFBA4)
- 0x021EF1B4 (site 0x021DFC96)
- 0x021EF1C4 (site 0x021DFD5E)
- 0x021EF264 (site 0x021DFCCE)

Next lane's list:
- ov170 roots still open (band >= 1024): 021DF484 (1452), 021E2650 (1204), 021E2CBC (1436), 021E3E84 (1192), 021E4504 (1088), 021E4F60 (1044), 021E5E68 (1108). About 250 smaller ov170 functions are still open.
- ov119: not started. Roots are 021DBE70 (1088) and 021E049C (1100). I stopped after one full tree to stay inside the context budget.

Integrator: seed the four addresses above into layout/function_starts.txt. Nothing else is needed.
