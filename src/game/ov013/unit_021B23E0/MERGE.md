# unit_021B23E0 (ov013)

5 parts (was 9). Round 5 (r5g02): one canonical St view of d_021B60D8 (u8 b0 @0, cb @4, arg @8, fC @0xC, state @0x10) and one struct Stat (G_Stat.h) for d_021B4BD0 applied to the old p01..p06; they merged into p01 (old p01+p02) and p02 (old p03..p06).

Left, per boundary:
- p01|p02: DIFF after merge. func_021B2724 is called in p01 as (Node *, unsigned) but defined in p02 as (u8 *, u8). Try deleting the prototype before the call (implicit call) and keep the u8 definition only.
- p02|p03: Sess (G_Sess.h) and St views of d_021B60D8; p03 also has struct N_021B2A20 incomplete and a different Pool layout (nodes/tick/freeList/active) than G_Pool.h.
- p03|p04 and p04|p05: struct Pool tag redefined (G_Pool.h against local Pool), struct N redefined (G_N.h against local N), g_021B4BE0 and d_021B4BE0 are the same address under two names.
Next: one canonical Pool block (G_Pool.h layout: nodes, head, tick, mul, add, freeList_*, active_*) and one N block in p03..p05, g_ names renamed to d_ names.
