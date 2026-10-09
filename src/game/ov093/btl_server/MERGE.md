# btl_server.c (ov093)

Translation unit 021B8CB0..021D3568, confidence weak (tools/tuboundary.py).
Round 4 (lane r4_ov07): 140 parts became 132, all EXACT, header status EXACT, gamecheck clean.
No member files are left.

## True boundaries (not work items)

Of the 131 boundaries, 114 are real linker veneers (`bx pc; nop; ldr ip,[pc]; bx ip; .word`, 16 bytes each,
in runs of 1 to 16, sometimes preceded by a 2-byte nop pad). No hidden setters are left (all other gaps are
veneers or pads). Hidden functions added in earlier rounds: func_021CE040, func_021D0D38, func_021D0D44.
Round 4 added no hidden functions.

## Closed in round 4 (current numbers differ; identified by address)

- 021C001C + 021C024C + 021C07D4 (func_021C07AC takes u16 c, u16 d: caller-side narrow type; p18 extern follows).
- 021C1184 + 021C11F0 (func_021C11A4 typed: u16 *a, u8 *b, u8 *c, u8 *d, u8 *e, struct Fl g; func_021C1880 and
  func_021C232C now take pointers instead of u32 words; callers in other parts updated).
- 021C2204 + 021C2488 (func_021C25A4 takes u8 *a, u8 *b, Word s1; p46 loop variable is u8 *t).
- 021C25A4 + 021C27A0 + 021C282C: one-word struct Word passed by value (S and Word were the same object).
- 021C2E4C + 021C312C: duplicate enum Kind unified.
- 021B8CB0 + 021B9A00: one struct S2 { u8 *items[6]; u8 count; } for the item list getters, one
  Unk021EFD70 { u16 n0; volatile u16 n1; u8 b[6]; } for data_021EFD70. func_021B8B9C keeps the u32 k
  prototype; the two calls in func_021BA73C and func_021BA7F8 cast the loop index to (u8) (guess).

## Boundaries with no veneer that still fail (17 pairs; part numbers are current, first address of each side)

Gap 0 or a 2-byte pad. All have been tried with the greedy merge and the harmonizer.

- p08|p09 021BC550|021BCB14: the server object has an array of 16-byte entries at 0x7E0 (a, action
  bitfield word, c, d, flag) seen through about ten local views (E_021BC550, E_021BC610, E_021BCB14, E_021BCB68,
  E_021BCCE0, S_xxxx with n at 0x782). Needs one canonical Entry and State struct across p08..p14; then the
  merge compiles. Best next work item.
- p29|p30 021BF9A4|021BFD24: func_021BFD24 has u16 c; caller func_021BFC08 passes int n from func_021B8D8C
  (returns int) without narrowing. u16 n moves the narrowing to the assignment. Widening the callee changes its
  body. Deleting the declaration (implicit call) is rejected by mwcc (redeclared). Still DIFF.
- p33|p34 021C0898|021C08CC: func_021C0898 clamps c then calls func_021C08CC(u8 c). u8 c in the caller or
  u32 c in the callee both give DIFF (narrowing moves, registers swap).
- p83|p84 021C8810|021C8C6C: func_021C8C6C is defined with int and called with a struct pointer view.
- p105|p106 021CAA24|021CAA58: func_021CAA24 pointer-versus-int parameter views.
- p116|p117 021CC768|021CCB34: struct views of the writer object (w) differ (pointer conversions).
- p117|p118 021CCB34|021CD5E0: c99 DIFF after prototype unification of func_021CCAA8.
- p118|p119 021CD5E0|021CE170: `struct Q` is used as incomplete type in one part and defined in the other;
  also a void-versus-int mismatch at one call.
- p121|p122 021CEEB8|021CFD50: struct G views (G versus G_021CFD50, G_021CFE08) and func_021D6314 prototype.
- p122|p123 021CFD50|021CFFAC: union Slot versus an anonymous union at the call of func_021D6314.
- p123|p124 021CFFAC|021D04E4: struct G_021D0100 versus u8 * at func_021D04E4; func_021E8B80 prototype.
- p124|p125 021D04E4|021D09E0: c99 DIFF (func_021D799C prototype differs).
- p126|p127 021D0B6C|021D10B8: func_021EEC20 and func_021D8394 prototypes differ (int * versus u8 **).
- p128|p129 021D123C|021D1410: func_021D1410 third argument view; func_021EEC20 prototype.
- p129|p130 021D1410|021D1C40: struct L / struct views of s->msg and func_021D1C40.
- p130|p131 021D1C40|021D2030: Seq_021D2030 typedef differs; func_0201BD28 prototype differs.
- p131|p132 021D2030|021D2C7C: struct StateData defined twice with different fields (result[14] only in one),
  func_02005D90 and func_021EA3D4 prototypes differ.

Lessons from this round: a u32 stand-in parameter that is really a pointer or a one-word struct is the usual
reason a boundary fails; retyping the definition and its callers (not casting) closed six boundaries.
Callers in other parts keep their own externs until their boundary is merged: expect stale u32 externs in
parts that are still separate (for example func_021C11A4 in p37/p38, func_021C4104 in p58).
