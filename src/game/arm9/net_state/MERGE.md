# net_state (arm9)

Translation unit 020353B0..0203E5F8, confidence weak. 46 parts (net_state_p01.c .. p46.c), all EXACT, compiler 1.1p1 everywhere
(no compiler boundary in this TU). Round 6 (lane w11b) went from 56 to 46 parts.

Done in round 6
- g_021469D4: one struct Votes (tag[8], mask[8], ready[8]) in every part that uses it.
- g_021469D8: one struct NetCmd (0x22c bytes: grp[4] of NetCmdGrp, slot[5] of NetCmdSlot at 0x40, ent[9] of NetCmdEnt at 0xb8,
  f220[8], f228) in the parts that use it. The alias d_021469D8 is gone. g_020A7AE8 is a struct NetCmdGrp (g_020A7AE8_arr stays a
  second name for the same address: folding the two pool words into one makes func_0203A67C four bytes short).
- struct Entry (0x50 bytes, element of the table at +0x70 of the func_0203D788 object): one canonical definition by offset in
  p03 (obj, slot[8], key3e, key40, key44, key46, f49, f4a). The p03/p04 and later Entry_0/Entry_1 views are gone.
- func_02082BCC is `void *(void *, int, u32)` everywhere.
- Merged pairs: old p05+p06, p07..p10, p11+p12, p02+p03, p03+p04 etc. (greedy and pair merges, all EXACT).

Still split, and why
- p01|p02: func_0203675C calls func_02036738 with three arguments while the definition takes two (p01). Give it the third
  parameter if it stays EXACT, or leave: the original had no prototype in view.
- Veneers (linker, not in any function): 0203D0AC, 0203D0B8, 0203D0C4, 0203D14C, 0203D158, 0203D164, 0203D170, 0203D594,
  0203D5A0, 0203D644, and 12 bytes at 020377AC. Each is a real boundary unless a hidden function is added for it.
- p03|p04 (0203A118..): g_021469DC is `u8 *` in one part, `u32 *` in the next, and a different local struct (NetState, Sys,
  Card0203C5EC, Card0203C600, Card0203CB00, Hdr021469DC, B794, B868) in p07..p24. NEXT STEP: one struct NetState (0x64 bytes):
  f00, f04, f08 (state fn, called with the object), rng[6] at 0x0c (MATHRandContext64, u64 x/mul/add), f24, f28 (teardown fn),
  f2C, err[4] at 0x30, mac[6] at 0x40, f46 u16, flag s8 at 0x48, f4A, f4B, f4C, f4D, f4F, f50, f51, f53, f56, addr[6] at 0x57.
  Also unify func_0203AD80 to (struct NetState *, void *, u16, int), replace the raw (0x21469DC) reads and the unk_021469DC
  alias (p16, p21, p23, p24), and write the raw-address stand-ins (func_0203B22C, func_0203B2A8, func_0203B688, func_0203B6B4,
  func_0203C464) as typed C.
- g_021469E0 (Mod, Singleton, u8[], u32[] views) and g_021469F0 (Wrap, Ctx, Ctx_0203DC4C, S0203DC04, G_021469F0, u8 *, int *):
  not started. 0x021469E0 is also written through a raw u16 cast in func_0203CB34.
- The func_0203D788 object (Owner/Obj/Sess/Singleton/Ctx views, vtable at +0x340) and func_0203D798 object (+0x56, +0x61,
  +0x64, +0x65): still `u8 *` plus casts in most parts; one canonical struct with a named vtable would remove the raw offsets.
