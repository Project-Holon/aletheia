# btl_server.c (ov093)

Translation unit 021B8CB0..021D3568. 4 parts, all EXACT (round 18, lane L01d). Shared types: ../btl_server_types.h
(Server with one field per used offset, Entry, Action, union Slot, CallFlags and the types several parts share).

All 479 server functions take `Server *p` and use fields; the p13..p15 functions of the closure were converted in
this round (p->fC, p->w1ab8, ...). No `p + n` is left on a `Server *` except the raw forms marked in the code
(`(u8 *)p + q` in func_021BDA00).

## Boundaries left (current part numbers, round 19, lane C19)

Old p01+p02 are now p01 (closed: func_021BDD7C local n is u8, func_021BD1D0 takes u8 n in the whole TU).
Old p03 is p02, old p04 is p03, old p05 is p04.

- p01|p02 (old p03 with the merged p01): the pair compiles. The 4-byte pool move is gone after
  func_021C3810 got `u8 position` (func_021B8E28 takes u8 in every part), func_021C2048/func_021C6CAC take u16 b,
  func_021D80BC returns u8, func_021C2910 takes `const void *`, func_021BD170 takes u16 x (its caller passes a
  halfword unnarrowed), and the func_021C62D8 out type is O_p11 in both. The only diff left is the stack frame of
  func_021C4614 (the stand-in func_021C4104 (int sa, u8 sb) in place of the {int,u8} struct parameter): the merged
  unit uses push {r4-r7} / sub sp,#0x14 where the image has push {r3-r7} / sub sp,#0x20.
- p02|p03 (old p03|p04): func_021CAA58/func_021CACF4 pass the key to func_021B98A4(u8 b) unnarrowed. Closed in
  every function but one with: func_021D80BC returns u8; func_021CAA24 is `u8 f(Server *, u8 *, int, u8 n, u8 value)`;
  func_021CAA58 and func_021CACF4 take u8 move; their locals n and key are u8 (func_021CAA58 is then exact).
  func_021CACF4 stays off: the code is identical but two spill slots swap (n at sp+0x14 and j at sp+0x18, the image has
  n at +0x18 and j at +0x14). Tried without effect: declaration order of i/count/j/n/b/key/selected, j hoisted to
  function scope or typed u8/u32/int, count/i as u8 or int, operand order of the n compares, `(u8)n` casts with a wide n.
  A wide n (int or u32) with a u8 key makes the unit 428 bytes shorter and not equal. These edits are NOT in the
  tree (reverted): p03/p04 keep int key and the int prototypes, since the pair does not close yet.
- p03|p04 (old p04|p05): func_021D8394 is (void *, u8, u32) in one part and (void *, u8, u8) in the other; p15
  passes a wide `j` that needs the u8 proto's narrowing, a cast `(u8)j` changes its register allocation. Not
  attempted in round 19.

## Levers used this round

u8 return view for func_021B8D8C; func_021CAA58/func_021C0A4C parameters as u32/u16 views chosen so callers do not
narrow; one union Slot for every one-word struct passed by value; one CallFlags; QueueA/QueueB/Word_021CC768, Buf_021CC768,
Rec_021CAA58 in the header; the five p14 one-letter macros expanded (they collided with type names);
tail-call stubs written as code (func_021C82B8 returns func_021B911C(p->f4, z)).
