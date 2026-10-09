# net_state (arm9)

Translation unit 020353B0..0203E5F8, 413 functions, confidence weak (tools/tuboundary.py).

State after round 5 (lane r5_s02): 75 parts became 58 parts (net_state_p01.c..net_state_p58.c), all EXACT.
Part numbers below are the NEW numbers. Round-4 numbers are in parentheses as "old".

Done in round 5
- p03 (old p03..p04 of round 4, 0x02036B4C..0x020377AB) and p04 (old p05..p21, 0x020377B8..0x02039965):
  g_021469D0 is now ONE struct Net (0x1f0 bytes) in every part. Named fields f00..f18 (u8 * buffers), f1C/f2C/f3C
  (struct NetRing, 16 bytes, state u32 at +8), f4C[8] (struct NetRing), fCC and fF4 (0x28-byte byte arrays),
  f11C[8][16], f19C[16], f1AC, f1B0 and f1B4[8] (int), f1D4..f1D6, f1D7[8], f1E0 (slot size), f1E4 (u16), f1E7..f1ED.
  The same text block is in p03 and p04 and must stay identical (scratchpad/r5s02/canon.py + sync.py).
  The aliases lbl_021469D0 and unk_021469D0 are gone: one name g_021469D0 with one `extern struct Net *`.
  All raw offset code (u8 + 0x1EB, *(u32 *)(g + 0x54 + i * 16), ...) became field accesses.
- One prototype each (the definition's): func_0203D788 and func_0203D798 are `void *f(void)` everywhere in p03/p04
  (struct return types became casts at the few member uses). func_02038924 is the definition's
  `int (u32, u8 *, s32)`; func_02039160 `int (u32)`; func_020392B8 `u32 (void)` (callers that compare it signed
  cast it to int); func_02039338 `u16 (void)`; func_020366A8 `int (struct Conn *)`; func_02036428 `(u8 *, u8 *, s32)`;
  func_0203666C `void (u32)`; func_02038DF0 `(struct Src *, s32, u8 *, struct St *, u32)`. NOTE: the second
  parameter of func_02038DF0 had to become s32 (u32 changed register allocation in func_020390BC).
- Stand-ins rewritten as typed C: func_02038D30, func_02038D4C (p04).
- p04 holds 17 old parts merged in one go (greedy, all EXACT). The earlier DIFFs around func_02038380 (p04 now)
  and func_02038524 were caused by the local struct views; they are gone with the Net block.

Still split, and why
- p03|p04: a 12-byte linker veneer (veneer_020377AC, `ldr ip,[pc]; bx ip; .word`) sits between them. It is not in
  any function: a real file boundary unless a hidden function is added for it (the callee func_020377AC is only
  an address of a function pointer in p04, so it is a candidate for a hidden function).
- Other veneers inside the TU (asm/arm9/main.s veneer_...): 0203D0AC, 0203D0B8, 0203D0C4, 0203D14C, 0203D158,
  0203D164, 0203D170, 0203D594, 0203D5A0, 0203D644. Each is a boundary between the parts that touch it
  (p46..p58 region). Confirm before spending compiles there.
- p01|p02: func_0203675C calls func_02036738(char *q, int v) with three arguments in its first call. The
  definition has two parameters, so a merge cannot compile. The original had no prototype in view there.
  func_0203666C is defined in p01 as `void func_0203666C(void){ }` but called with one u32 argument in
  p02, p04, ...: give it a `(u32 h)` parameter in p01 before merging p01|p02 and p01|p03 (not tried).
  func_02036428 is defined in p01 with (NetRingBuff *, const u8 *, int); p04 declares (u8 *, u8 *, s32).
- g_021469D4 (new p05..p06) and g_021469D8 (p07..p12): not started; viewed as u8 *, void *, struct Votes,
  struct Entry, struct HugeRecv, Obj0203A85C.
- g_021469DC parts (p12..p34, e.g. p12 func_0203A85C, p14 func_0203B018/B038, p16..p20), g_021469E0 (p33..p47) and
  g_021469F0 (p47..p58): not started. Each is viewed as u8 *, u32 *, int, void *, or a different local struct
  (Sys, NetState, Card0203C5EC, Card0203C600, Card0203CB00, Singleton, Mod, Wrap, Ctx, Ctx_0203DC4C,
  S0203DC04, G_021469F0).
- Machine one-liners with raw addresses still present (current part): func_02035750 (p01, *(int *)0x21469C4),
  func_0203B22C (p18), func_0203B2A8 (p19), func_0203B688 and func_0203B6B4 (p22), func_0203C464 (p28),
  func_0203C044 and func_0203D0DC / func_0203D10C (look near p23..p40), plus the calls
  func_0203AD80((struct NetState *)*(int *)0x21469DC, (void *)0x203B16C, ...) in p12, p14, p16, p19, p20, p25, p27
  (raw address of a callback and raw global address). Rewrite as g_021469DC and function names once the
  g_021469DC struct exists.
- Functions with two prototypes still open after this round: func_02036BD4 (struct Handler vs others),
  func_02039658 and func_0203B52C and func_0203DC68 (differently named local structs for the same
  parameter). func_0203D798/func_0203D788 are only unified in p03/p04; the later parts (p05 onward) still
  declare `u8 *`, `int`, `struct NetSys`, `struct Sys`, ... (see `rg "func_0203D78[8]|func_0203D798" -g
  "net_state_p*.c"`). Change them to `void *` with casts at member uses, as done in p04.
- The vtable at (func_0203D788())+0x340 is called through raw casts all over (offsets 0x04, 0x08, 0x0c, 0x10, 0x14,
  0x28, 0x2c, 0x3c, 0x40, 0x44, 0x48, 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74, 0x78, 0x7c, 0x80,
  0x84, 0x88, 0x8c, 0x90, 0x9c, 0xa0, 0xa4, 0xa8, 0xac, 0xb4, 0xbc, 0xc0). A struct NetCtx { ...; u32 f64? }
  with a struct NetVtbl would turn those into named calls. Context 0x64/0x65/0x56 bytes belong to the func_0203D798
  object (f56 u16, f64 u8, f65 u8).
- c99=DIFF cases of the earlier round still unexamined: around func_0203B1D8, func_0203D210, func_0203D634,
  func_0203D5AC (all in the G-DC/E0/F0 groups; veneers 0203D594/0203D5A0/0203D644 explain the last three).
  Greedy merges of the old neighbours showed DIFF in several parts beyond p04; run
  scratchpad/r5s02/go.py LO HI (greedy over a part range) and mm.py/dd.py on them.

Tools (scratchpad/r5s02): lib.py (rd/wr/verdict/sub), canon.py (the Net block), sync.py (copies the Net block into
every part that has it), e03..e21.py (the conversions done this round), go.py LO HI [apply] (greedy merge of parts
LO..HI, keeps the first file name), renum.py (renumber to p01.. by address), pair.py N M ... (merge numbered
parts, prints compile errors), mm.py, dd.py (differing rows), protos.py LO HI (prototype variants per function),
vall.py (re-verify all parts).
