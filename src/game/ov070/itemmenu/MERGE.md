# ov070 itemmenu: merge status

Files: itemmenu_p01.c (0x021B6EF8 .. func_021B8688) and itemmenu_p02.c (0x021B8904
to the end). Was 20 files. Every file verifies EXACT.

Open boundary p01 | p02: unmatched code.
- 0x021B86B8 to 0x021B8904 (588 bytes) has no function in any file: no label, code
  begins `push {r3-r7, lr}; sub sp` at 0x021B86B8 (asm/overlays/ov070.s, around line
  5806). It is one or more functions that nobody has matched yet. When they are
  matched and placed here, merge the two files.
- Merging the two parts as they are compiles DIFF (every later address moves by
  588 bytes).

Things fixed on the way (for the next person): one symbols: row had trailing comment
text (it silently ended the symbol block in the merge), the two different local
`struct Obj` layouts are now `Obj_021B7B80` and `Obj_021B8990`, `struct Ent` uses
`Item item`, func_0204B92C takes `struct Obj *` with casts at the calls.

## Round 5 note (r5 g01)

Not decoded this round (ran out of budget on ov039). Callees of 0x021B86B8: blx 0x203064C, 0x203159C, 0x2082BCC, 0x2036370, bl 0x200816C, 0x2008284, 0x2008270, 0x2007FA0, 0x2008288 (a loop, blo back to 0x21B8730), blx 0x2045B38, 0x20457B0 x3, bl 0x201EC64, 0x201C450, 0x2028590, 0x201D7EC. Two data loops with blt/blo exits. Still one uncovered function, still the boundary p01 | p02.

## Round 17 (2026-10-12): func 0x021B86B8, best 44 bytes off (parked)
Drafts in the session scratchpad r18/L18b/Q1.c (46) and r18/L18h/d2.c (44).
With the fixed tools/mwccdbg regalloc replay:
- Loop: the original needs the CSE temps for v[0]/v[1] created after loop
  hoisting (late vreg numbers); ours names them in CSE run 1. Declaration
  order, structs and separate locals do not move them.
- Struct copy: the original computes q = &a2[5] early, uses it only for the
  w0c store, and loads the last two words a2-relative; IRO forward-substitutes
  a single-use q into the store, which moves the mov/add late.
No human-plausible source found yet for either.
