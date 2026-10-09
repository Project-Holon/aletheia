# unit_021B23E0 (ov013)

5 parts (was 9). Round 5 (r5g02): one canonical St view of d_021B60D8 (u8 b0 @0, cb @4, arg @8, fC @0xC, state @0x10) and one struct Stat (G_Stat.h) for d_021B4BD0 applied to the old p01..p06; they merged into p01 (old p01+p02) and p02 (old p03..p06).

Left, per boundary:
- p01|p02: DIFF after merge. func_021B2724 is called in p01 as (Node *, unsigned) but defined in p02 as (u8 *, u8). Try deleting the prototype before the call (implicit call) and keep the u8 definition only.
- p02|p03: Sess (G_Sess.h) and St views of d_021B60D8; p03 also has struct N_021B2A20 incomplete and a different Pool layout (nodes/tick/freeList/active) than G_Pool.h.
- p03|p04 and p04|p05: struct Pool tag redefined (G_Pool.h against local Pool), struct N redefined (G_N.h against local N), g_021B4BE0 and d_021B4BE0 are the same address under two names.
Next: one canonical Pool block (G_Pool.h layout: nodes, head, tick, mul, add, freeList_*, active_*) and one N block in p03..p05, g_ names renamed to d_ names.

Lane w8d (2026-10-09), notes for the next pass. The same objects were unified in the sibling TU unit_021B1498 (all 7 parts now one EXACT file); use its canonical block as the template (copy of the idea, with these differences for this TU):
- d_021B4C0C is the address of d_021B4BE0.active (0x4BE0 + 0x2C). `struct N`, `N_021B2A20`, the p02 `N {a,b,c,kind,e,next}` and Node are all the same 0x18-byte pool node: `{u32 state; u8 f4; u8 f5; u16 f6; u32 f8; u32 fC; u32 f10; Node *next;}` (a = state, kind = fC, id = f4). Replace every N/Node view by this one.
- Pool (d_021B4BE0 / g_021B4BE0, G in p02/p03 and p05's E-view are other views): `{Node *nodes; Node *head; void *tick; u32 mul; u32 add; Node freeList; Node active;}` (G.flag = active.state at 0x2C, G.id = active.f4 at 0x30).
- Sess (d_021B60D8): `{u8 b0; u8 b1; u8 pad2[2]; int (*cb)(int,int,int,int); int arg; int fC; int state; u32 f14;}`; p05 reads byte 1 as `f1` and `f10` is `state`.
- Stat (d_021B4BD0): `{int f0; u32 mask; u64 t;}` here (p04 calls f4 mask, f8 t). Note: in unit_021B1498 the 8-byte view without `t` was needed for EXACT; here keep the 16-byte one.
- func_021B2724 is really `void (Node *p, u8 v)` (memset 24, state, fC = 0, f4 = v); p01 calls it with (Node *, unsigned): test the u8 prototype, else leave it unprototyped.
- Pkt: p03/p04 `Pkt {pad0[4]; f4..fb; fc}`; p01/p02/p05 use `u8 *p` offsets for the same packet (p[8] = f8, p[9], p[10], p[11]).
- Keep d_021B4C0C a separate extern if the pool/active scheduling changes when the two names are folded (seen in unit_021B1498 func_021B22B4: two names for one address change instruction order; one name was fine there).
