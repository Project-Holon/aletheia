# btl_server.c (ov093)

Translation unit 021B8CB0..021D3568, confidence weak (tools/tuboundary.py).
Round 5 (lane r5s01): 132 parts became 131, all EXACT, header status EXACT, gamecheck clean.
No member files are left.

## True boundaries (not work items)

Of the 130 boundaries, 114 are real linker veneers (bx pc; nop; ldr ip,[pc]; bx ip; .word, 16 bytes each,
in runs of 1 to 16, sometimes preceded by a 2-byte nop pad). Example: 021BCEEC between p08 and p09 (called by
name from func_021BCCE0). No hidden setters are left. Hidden functions added in earlier rounds: func_021CE040,
func_021D0D38, func_021D0D44. Round 5 added none.

## Closed in round 5

- 021BC550 + 021BCB14 (old p08 + p09): one canonical Action union, Entry (16 bytes: a, b, c, d, done, f) and
  Server struct (named fields by offset: f0, f4, f8, fC, f10, f14, w4b8, n at 0x782, f784, f786, f78a bits,
  flags at 0x7c1, e[6] at 0x7e0, t at 0x840, w1ab8, lock at 0x1d74, f1f78, f1fe8). The same block is now in
  parts p08..p13 (identical text). Server-typed definitions: p08 func_021BC550..021BCCE0 (merged), p09
  func_021BCEFC..021BD0C0, p10 func_021BD148..021BD200, p11 func_021BD338/3E8/43C, p12 func_021BD4E4..021BD850,
  p13 func_021BD8AC/8F0. Those parts stay separate: the boundaries between them are veneers (for example
  021BCEEC between p08 and p09; merging them gives DIFF at the bl to func_021BCEFC).
- Guesses: func_021BCAAC takes u32 i and callers narrow it with (u8) (func_021BD170 and func_021BCB14);
  EntryAlt in p08 is a second type with the same layout as Entry: reading e[l].b through it is the only
  spelling found that reloads the field in func_021BC610 (a local Action copy added 4 bytes of frame);
  func_021BD170 now takes u8 x (the old u8 *q stand-in was a narrowing id); its caller in p101 still passes a
  pointer-shaped cast.
- func_021C0F24 (p36) now calls func_021C11A4 with the definition's pointer types (stale u32 words removed).

## Closed in round 4 (addresses only; numbers change)

- 021C001C + 021C024C + 021C07D4, 021C1184 + 021C11F0, 021C2204 + 021C2488, 021C25A4 + 021C27A0 + 021C282C,
  021C2E4C + 021C312C, 021B8CB0 + 021B9A00 (see git history for the details).

## Boundaries with no veneer that still fail (16 pairs; current part numbers, first address of each side)

Gap 0 or a 2-byte pad. All were tried with the greedy merge and the harmonizer in round 4.

- p28|p29 021BF9A4|021BFD24: func_021BFD24 has u16 c; caller func_021BFC08 passes int n from func_021B8D8C
  without narrowing. u16 n moves the narrowing to the assignment. Still DIFF.
- p32|p33 021C0898|021C08CC: func_021C0898 clamps c then calls func_021C08CC(u8 c). u8 c in the caller or u32 c
  in the callee both give DIFF.
- p36|p37 021C0F24|021C11A4: still blocked: struct Flags { u32 word } in p36 versus struct Fl { u32 f : 1 } in p37
  (func_021C11F0 reads a7.f). Renaming p36 to the bitfield struct gives DIFF; p37 as a word struct changes the
  bit read. The pointer types of the extern are fixed already.
- p37 extern func_021C4104(u8 *, u8 *, u8 *, u16, int, u8, u16 *) is stale against the definition in p55
  (u8 *p, u32 q, u8 *c, u16 d, S s, u16 *e); fix when p37 and p55 are near each other.
- p82|p83 021C8810|021C8C6C: func_021C8C6C is defined with int and called with a struct pointer view.
- p104|p105 021CAA24|021CAA58: func_021CAA24 pointer-versus-int parameter views.
- p115|p116 021CC768|021CCB34: struct views of the writer object (w) differ.
- p116|p117 021CCB34|021CD5E0: c99 DIFF after prototype unification of func_021CCAA8.
- p117|p118 021CD5E0|021CE170: struct Q is incomplete in one part and defined in the other; void-versus-int at one call.
- p120|p121 021CEEB8|021CFD50: struct G views (G versus G_021CFD50, G_021CFE08) and func_021D6314 prototype.
- p121|p122 021CFD50|021CFFAC: union Slot versus an anonymous union at the call of func_021D6314.
- p122|p123 021CFFAC|021D04E4: struct G_021D0100 versus u8 * at func_021D04E4; func_021E8B80 prototype.
- p123|p124 021D04E4|021D09E0: c99 DIFF (func_021D799C prototype differs).
- p125|p126 021D0B6C|021D10B8: func_021EEC20 and func_021D8394 prototypes differ (int * versus u8 **).
- p127|p128 021D123C|021D1410: func_021D1410 third argument view; func_021EEC20 prototype.
- p128|p129 021D1410|021D1C40: struct L / struct views of s->msg and func_021D1C40.
- p129|p130 021D1C40|021D2030: Seq_021D2030 typedef differs; func_0201BD28 prototype differs.
- p130|p131 021D2030|021D2C7C: struct StateData defined twice with different fields, func_02005D90 and func_021EA3D4 prototypes differ.

## Open work

- Server struct outside p08..p13: the other parts still view the server object as u8 *p (with Obj headers)
  or as local S/E structs (p02..p05, p15..p20, p60.., p100..p102). Their externs for the functions retyped in
  round 5 (func_021BC610, func_021BC874, func_021BC8EC, func_021BC948, func_021BCCE0, func_021BD0C0..., ) are
  stale; when those parts are merged, use the Server/Entry block from p08 (copy it verbatim).
- Callers in other parts keep their own externs until their boundary is merged.
