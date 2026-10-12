# btl_server.c (ov093)

Translation unit 021B8CB0..021D3568. 5 parts, all EXACT (round 18, lane L01d). Shared types: ../btl_server_types.h
(Server with one field per used offset, Entry, Action, union Slot, CallFlags and the types several parts share).

All 479 server functions take `Server *p` and use fields; the p13..p15 functions of the closure were converted in
this round (p->fC, p->w1ab8, ...). No `p + n` is left on a `Server *` except the raw forms marked in the code
(`(u8 *)p + q` in func_021BDA00).

## Boundaries left (current part numbers)

- p01|p02 (old p02|p03): func_021B8E28 takes a u8 n, but func_021BDC98 passes an int that the original does not
  narrow. With any single prototype the caller gains a lsls/lsrs pair (tried u8, u32, unprototyped extern, block-scope
  extern, `u8 r`). Needs a second declaration, which one TU cannot have.
- p02|p03 (old p09|p10): merge compiles with the p10 prototypes unified (func_021C4104 takes sa/sb as separate ints,
  func_021C25A4 takes union Slot, W_021C312C shared) but one literal pool entry moves in func_021C3810 (+4 bytes),
  so every later bl differs by 4. Next step: find which constant is pooled twice in the merged unit.
- p03|p04 (old p13|p14): func_021CAA58 passes `key` (int from func_021CAA24) to func_021B98A4(u8 b) without narrowing.
  The thunk func_021B98A4 only matches with u8 b, and func_021CAA24 returning u8 changes its register allocation.
  This pair was closed before the crash of this lane; the closing edit was not recovered.
- p04|p05 (old p14|p15): func_021D8394 is (void *, u8, u32) in p14 and (void *, u8, u8) in p15; p15 passes a wide `j`
  that needs the u8 proto's narrowing, a cast `(u8)j` changes its register allocation.

## Levers used this round

u8 return view for func_021B8D8C; func_021CAA58/func_021C0A4C parameters as u32/u16 views chosen so callers do not
narrow; one union Slot for every one-word struct passed by value; one CallFlags; QueueA/QueueB/Word_021CC768, Buf_021CC768,
Rec_021CAA58 in the header; the five p14 one-letter macros expanded (they collided with type names);
tail-call stubs written as code (func_021C82B8 returns func_021B911C(p->f4, z)).
