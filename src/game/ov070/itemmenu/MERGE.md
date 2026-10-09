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
