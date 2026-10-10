# net_state (arm9)

Translation unit 020353B0..0203E5F8, confidence weak. 25 parts (net_state_p01.c .. p25.c), all EXACT, compiler 1.1p1 everywhere
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

Done in round 12 (lane w12a): 46 -> 36 parts, all EXACT
- g_021469DC is one struct NetState (0x64 bytes) in every part that touches it (old p03..p24): f00, f04, f08 (state callback,
  called with the object), rng (MATHRandContext64 embedded at 0x0c; u64 members are 4-aligned in this compiler), f24,
  f28 (teardown fn), f2C (callback taking func_0203D650's result), err[4] at 0x30, mac[6] at 0x40, f46 u16, flag s8 at 0x48,
  f4A, f4B, f4C, f4D, f4E, f4F, f50, f51, f53, f56, addr[6] at 0x57. The views Sys, Card0203C5EC/C600/CB00, Hdr021469DC,
  B794, B868, Rec, the unk_021469DC alias and the raw (0x21469DC) reads are gone.
- func_0203AD80 / func_0203AD74 take (struct NetState *, void *, u32 v, int line). Evidence: with u16 v the two sites that pass
  func_0203B2FC / func_0203B344 results get lsl/lsr; with u32 v (callee wide) every part is EXACT.
- Stand-ins rewritten as typed C: func_0203B22C (int, returns 1), func_0203B2A8, func_0203B688 (void, takes the object),
  func_0203B6B4 (int, returns 1), func_0203C464 (void). func_0203B2A8 keeps (void *)0x203B228 for the callback: naming
  unk_0203B228 there makes the part MATCH.
- Callbacks stored in f08 now take struct NetState *; func_0203B2FC / func_0203B344 take the object and use rng.
- Pair merges (all EXACT): old p03+p04, p05..p08, p09+p10+p11 (0203B5D4..), later runs up to old p24. Current parts:
  p03 = 020377B8..0203AFCC+, p04 = 0203B018.., p05 = 0203B5D4.., p06 = 0203B6EC.. (renumbered).

Done in round 13 (lane w13a): 36 -> 25 parts, all EXACT
- One struct NetCtx (0x354 bytes) for the func_0203D788 object, in every part: callbacks f08..f14, f1C, f24, f28, f2C, f30, f40, f44,
  u16 f56/f58/f5A/f5C/f5E, f60/f61/f64/f65/f66/f67, f6C/f6E, struct Entry table[9] at 0x70, struct NetVtbl *vt at 0x340, f344, f348
  (callback), f34C, f352. func_0203D798 returns the same type (its +0x56/+0x64/+0x65 accesses fit). The views Obj, Owner, Sess, Ctx,
  Singleton, Vt/Vtbl, NetSys and the raw +0x340 arithmetic are gone from p01..p25 except where listed below.
- struct NetVtbl: slots 0x00..0xC8 with signatures taken from the call sites (f3C/f68 take a callback as void *).
- struct Entry now lives in the shared block. Unused trailing parameters on definitions: func_02039834 / func_020398B4 (struct NetCtx *),
  func_0203CEAC takes a callback (void (*)(u32), always called with 0).
- func_020399EC takes no argument (the call in func_0203B7F8 passed a dead value). Stand-in one-liners func_0203C044, func_0203D0DC,
  func_0203D10C rewritten as typed C.
- Merged with the canonical block: old p03+p04 (twice), p06+p07, p11+p12, p14+p15, others by greedy.
- Scratch tools: scratchpad r14/w13a (nc.py canonical block, fix.py/conv.py converters, perpart.py, protos.py+sigs.py, auto.sh).

Still split, and why
- p01|p02: func_0203675C (p02) is a stand-in with three-argument call of func_02036738 (p01 definition takes two: add an unused trailing
  parameter) and p02 declares func_02036670 / func_0203660C / func_02036428 / func_0203666C with guessed types that differ from p01
  (p01: u8 *(u32 *), int(int,int,int,int), NetRingBuff *, void(void) called with an argument). Needs typed rewrite of p02's Queue020368C0.
- Veneers (linker, not in any function): 0203D0AC, 0203D0B8, 0203D0C4, 0203D14C, 0203D158, 0203D164, 0203D170, 0203D594, 0203D5A0,
  0203D644, and 12 bytes at 020377AC. Each is a real boundary.
- p03|p04 (current numbering) now fails on g_021469E0: views struct Mod, struct Singleton, u32[], u8[] and a raw u16 cast in func_0203CB34.
  NEXT STEP: struct NetMod { u16 f00; u32 f04; struct NetCtx *f08; u32 f0C; } as the data symbol.
- g_021469F0 (views Wrap/Base, Ctx, Ctx_0203DC4C, S0203DC04, G_021469F0, u8 *, int *): one struct NetLink. It shares a 0x70 byte header with
  NetCtx (callbacks at 0x18/0x1C/0x2C, f60/f64/f65/f67, f6E), then f70, f74, fn_78, fn_7C, f80, f84, f88, f8C, f90, mac table at 0x94
  (stride 8), flags f100..f10B. Not started.
- Callback arguments still written as raw addresses, e.g. (void *)0x0203C0F4: try the function names per site.
