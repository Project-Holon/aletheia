# pokeparty (arm9)

Round 5 lane s12: 12 parts -> 5 parts (p01 is the old p01..p08 plus four hidden functions).

What was done:
- func_02019D30 takes u16 a, u16 n (caller narrowing; func_02019C90 takes u16).
- func_020185F0 is declared unprototyped (`void *func_020185F0();`): p01 calls it without arguments.
- One canonical `struct Waza` (0x24 bytes, offsets from the old p04 view plus u32 at +0x20); one `struct WazaTool`
  (`struct Waza **recs`); `u16 move` locals in sub_0201B920 and sub_0201B970; sub_0201B850 takes u16 a3
  (its callers func_0201B7A0, func_0201B7EC, func_0201B818 take u16 too); sub_0201C1C8, sub_0201C1D8 and
  sub_0201C314 take u16 (the callee sub_0201BD28 takes u16 id).
- Hidden functions added (all EXACT, plain C, tail calls into func_02045EC0 through a `struct Ctx`):
  func_0201A468, func_0201A48C, func_0201A4A0, func_0201A4B4 (0x0201A468..0x0201A4D4).
  Guesses: the names of the Ctx struct and its fields (bank at +0, f34 at +0x34); the first two parameters
  are unused.

Left (not merged):
- p01|p02 (func_0201C4E4 | sub_0201C6B4): `struct PrintSys` (p02 view) against PrintSys_0201C450 and
  PrintSys_0201C4E4 (p01). Needs one canonical PrintSys by offset (unk07 is a u8 or two nibbles, unk08 is a
  union Ticks or u64, unk10 is void *, struct Rec * or struct PrintCtx *). func_0201D7C4 has two prototypes.
- p02|p03: sub_0201C808 takes void * in p02 but callers pass u32.
- p03|p04: PrintCtx_0201C6FC (p03) against PrintCtx_0201C7A4 and Scratch views (p04).
- p04|p05: c99=DIFF (816 bytes differ at +0xF4 on; not diagnosed).
- p01 still carries per-part clone structs (Mon_02019A50, Mon_02019C38, Party_0201A4D4, Party_0201AB28,
  Personal_0201AE1C, Personal_0201AFD4, EvoRow_0201B2B0, EvoRow_0201B70C, Rec_0201A4D4, Rec_0201B7B4,
  PrintSys_0201C450, PrintSys_0201C4E4): readability debt, a struct pass by offset is still open.
