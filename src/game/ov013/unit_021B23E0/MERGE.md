# unit_021B23E0 (ov013)

9 parts (from 5 plus 9 folder members). Left: d_021B60D8 has views Ctx{f0,cb,arg,fC,state}, Ctx_021B2488{b0,fC}, Ctx{b0}, u8, St{state@0x10}, struct Sess (G_Sess.h). A shared local struct Sess {u8 b0; u8 f1; pad; cb@4; arg@8; fC@0xC; state@0x10; f14} in every part, dropping the G_Sess.h include, would let them merge. d_021B4BD0 and d_021B4BE0 have the same problem (Stat vs struct Stats).

Round 4 (r4_ov05): greedy pass fails every boundary (Ctx, Ctx_021B2488, St, Sess, Stat, Stats, Pool, N, G views of d_021B60D8, d_021B4BD0, d_021B4BE0, d_021B4C0C). Canonical Sess: u8 b0 @0, cb @4, arg @8, fC @0xC, state @0x10, f14 @0x14. Not applied.
