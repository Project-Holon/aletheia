# Four halfword zero stores into a stack struct are its `= {0}` initialiser, and the block it opens places them

summary: `add rN, sp, #K; strh rZ, [rN]; strh rZ, [rN, #2]; strh rZ, [rN, #4];
strh rZ, [rN, #6]` clearing an 8-byte `{u16 a, b, c; u8 d, e;}` stack local is
`Local s = {0};`: mwcc clears a zero-initialised halfword-aligned struct by
halfwords, while zeroing the fields one by one ends in two `strb`. The
initialiser runs where its block opens, so when the stores sit after an
earlier call (or at the top of a loop body), declare the struct in a block
that starts there; the block's position also moves the struct's stack slot
against the function-scope locals.

Found in: src/matched/ov/ov033_func_021F07F4.c (0x021F07F4),
src/matched/ov/ov033_func_021F0924.c (0x021F0924)

Both functions build an OBJ template (`Local`, the ObjPos shape of
func_021FD08C's `{x, y, z, pri, f7}`) for func_0204B294.

- 0x021F07F4: the four `strh #0` open each loop pass, and a later `strb` stores
  the counter at +6. Field stores `s.a = s.b = s.c = 0; s.d = s.e = 0;` compile
  to three `strh` and two `strb`. A function-scope `Local z = {0}; ... s = z;`
  or a nested `{ Local t = {0}; s = t; }` builds a second copy and copies it
  halfword by halfword. `Local s = {0};` as the loop body's first declaration
  is byte-correct except for the stack slots; moving the later `Pos pt` (its
  `{x, y}` stores follow the loop) into its own block after the loop puts `pt`
  at sp+0x10 below `s` at sp+0x14, which is EXACT.
- 0x021F0924: the stores sit after the first call
  (`func_02024A20(4, 3, ...)`). `Local s = {0};` at function scope clears it
  before that call and shifts every spill slot. Opening a block right after the
  call with `Local s = {0}; u32 h; u32 arc; ...` in it, and leaving `ptr` (the
  out-parameter at sp+0x28) at function scope, is EXACT.
