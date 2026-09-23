# Wave 14 lane: g3d_util.c (0x02047CFC family)

EXACT 6 of 7, MATCH 0, DIFF 1.
- EXACT: 0x02047CFC (create, 336 B), 0x02047E88 / 0x02047F4C / 0x02048010 (add-unit
  twins, 192/192/208), 0x02048330 (create objects with on-demand load, 648),
  0x02048918 (delete objects, 220, EXACT* only because the listing extent runs into
  unit_020489F4). Files in src/matched/func_<addr>.c.
- DIFF: 0x02048744 (456): correct size, 18 bytes out, one swapped register pair
  (object counter i in r8 rather than sb; objTbl/j in sb rather than r8). Near miss:
  `+0x0028 mov sb, #0` compiled as `mov r8, #0`. Best source and everything tried
  appended to docs/notes/pkt_02048330.c.txt (it was 480/468, 358 out before).

Library shape identified: Game Freak's g3d utility object, written up in
docs/families/g3d_util.h (new). Util is 0x218 B {res**, resStat*, u16 resCount,
obj**, objStat*, u16 objCount, Unit[0x40] of {resIdx,resCount,objIdx,objCount} at
+0x16, u16 heapID at +0x216}; Setup {ResSetup* (0xc: arc, dat, type 0..3), count,
ObjSetup* (0x10: mdl idx/dat, tex idx, AnmSetup*, anmCount), count}. Levers, each
of which closed a function that sweeps had not: u16 parameters on the callees and
the constructor (the per-call lsl/lsr pairs are implicit argument conversions);
func_0204767C takes three arguments; the resource loader is an inline switch
writing through an out pointer (no local result), which keeps the model handle in
its stack home; `rnd` declared before `obj` in 0x02048918.

Seeds for layout/function_starts.txt:
- arm9 0x020489F4 arm, witness src/matched/unit_020489F4.c (clears the EXACT* on
  0x02048918; the unit's other members 0x02048A00, 0x02048A0C, 0x02048A18 arm are
  already named on its function: line).

Shards verified (twice, stable, 0 rewritten): pkt_02047CFC (1 entry), pkt_02047E88
(7), pkt_02048330 (4; the one non-EXACT flag is 0x02048918's EXACT*).
