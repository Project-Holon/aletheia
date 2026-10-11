# btl_server.c (ov093)

Translation unit 021B8CB0..021D3568. Round 17 (lane L01): 131 parts became 26, all EXACT.
Veneer gaps (16-byte form) are no longer boundaries: match.py takes them from the image, so parts are merged
across them. A script classified all 293 gap pieces inside the unit: 293 are the 16-byte veneer, 0 are code
(the 3 other pieces are 4-byte alignment words inside one part).

## Boundaries left (current part numbers; first error of the pair merge)

- p01|p02: E_021B8CB0 typedef differs; func_021B8B9C prototype; 'b' not a member of one Entry view.
- p02|p03, p03|p04: prototype differences (func_021CD4B0, func_021BB8B0, func_021D8454, func_021C6350,
  func_021C0780, func_021C60EC); p03 header holds two junk symbols rows (func_02018480/8 prose) to clean.
- p04|p05: DIFF at func_021B8D8C prototype view.
- p05|p06: union Slot_021C024C versus a struct view at a call (func_021C5620, func_021C5C1C).
- p06|p07: DIFF, func_021D5584 return view (u8 versus u32).
- p07|p08: u32 passed where const u32 * is declared.
- p08|p09, p09|p10: struct Flags versus Fl (bitfield versus word), func_021C0A4C, func_021C11A4.
- p10|p11, p11|p12: union Slot defined differently in each part.
- p12|p13 (func_021B911C), p13|p14, p18|p19, p21|p22, p22|p23, p23|p24 (struct Lock), p19|p20, p20|p21:
  int versus pointer parameter views.
- p14|p15, p15|p16, p16|p17, p17|p18: Ent_* typedef per function (b6/b7, count/targets/value) to unify into one Ent.
- p24|p25: DIFF, func_021D5778 prototype.
- p25|p26: struct G view at the call of func_021CFD50 (cast to the per-function struct, as in the merged parts).

Levers that closed pairs this round: u16/u8 return or parameter views chosen so the caller does not narrow
(func_021B8D8C u16 view, func_021D5584 u32 view, func_021D122C u8 view), unused trailing parameter
(func_021D1410), one Buf and one BattleSeq struct, Word typedef unified, d_021F3B64 as a union view.
