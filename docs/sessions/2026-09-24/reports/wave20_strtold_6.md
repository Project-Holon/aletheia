# Wave 20 lane 20M (strtold_6)

## 0x02094B8C (MSL __strtold, ARM, 3864 bytes)

36 -> 0 concrete bytes out, MATCH (size exact). Filed in src/pending/func_02094B8C.c with
status MATCH. Blocking class: two unresolved anonymous string pool words (+0x0EF0, +0x0EF4,
the "INFINITY" and "NAN(" initialiser literals). __double_huge and func_0209739C now resolve
by sole-ref, so they no longer cap it.

What moved it: declaration position of p inside the hex block. From the lane 20J 39-byte
variant (U C H hr p), the block `double hexresult; unsigned long ui2; unsigned long ch2;
unsigned char *p = (unsigned char *)&hexresult; unsigned char hch;` (p one slot earlier,
between ch2 and hch) gives p r4 and the chindex/hch pair r5, as in the image. 20J had swept
the U/C/H orders with p fixed last.

Levers measured (16, all in the note): p function-scope at 3 slots 77; p recomputed before
the swap loop 3868/133; `p = p;` in the second loop (two spots) 39 identical; p in a nested
block opened below the chindex part 162/102/46/46; p uninitialised then assigned 162; ch1
block var at 3 positions 39 identical; hr U p C H 47; hr U C p H MATCH. A bare mixed
declaration is CCERR under 1.1p1. Permuter (seed 5001) did not run: tools/permuter.py cannot
parse this file (`<src>:64:47: before: |`).

Verification: `match.py one` on the repo file: MATCH, 15 of 17 relocations resolved.
`tools/session/promote_fast.py --dry` gives it a fresh MATCH; `pending_pct.py` counts it
(2892 code bytes; reproduced 98.8289 percent at the time of the run, exact 98.1064).

Files written: src/pending/func_02094B8C.c, docs/idioms/declaration-position-orders-block-scope-colouring.md,
docs/notes/pkt_02094B8C.c.txt (appended, dated marker), this report. No shard (MATCH, not
EXACT). Seeds: none noticed.

Integrator: graduation needs the two anonymous string literals to gain a witness (sole-ref/string
on the ROM words, or naming them); regenerate the idiom index; tools/permuter.py parse failure on
the MSL enum/macro region is worth a look.
