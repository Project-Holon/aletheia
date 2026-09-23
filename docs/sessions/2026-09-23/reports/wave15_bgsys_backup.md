# Wave 15, bg_sys.c / gf_standard.c / g3d_util.c / backup_system.c lane

EXACT 0 / MATCH 0 / DIFF 5 (plus one row that is not C). No source filed.

- 0x02040EC0 (32 B, bg_sys): not C. The bytes are already EXACT from the real entry 0x02040EBC
  (func_02040EBC.c and unit_02040E78.c, shard pkt_02040DA8); the row is disasm.py's late label on
  the `push {r3, lr}` after the home-area push. Integrator item: start the function at 0x02040EBC
  and drop the 0x02040EC0 label. Stale park src/pending/func_02040EC0.c got a header line saying so.
- 0x020433E0 (188 B, bg_sys): 6 -> 6. Widened mask, `~(..)` masks, single cast read, int locals,
  out-pointer getter, inline RMW setter, sp2 and sp2p2: all the same r3/ip pair.
- 0x0203FCA0 (1876 B, bg_sys): 1860/1171 -> 1860/1171. SDK `(u16)` casts on all 24 stores,
  u16/u8 type and bgId: byte-identical. sp2p2 1988. Moved on.
- 0x0203F0A8 (340 B, gf_standard): 16 -> 16 (14 at best, wrong colours, as before). Named u32
  index, (u32)/(int) cast reads, u32 kk with signed tests, pointer spellings: 16. Found that the
  scaled load comes out when mt[kk] is the second address named; no spelling that does this also
  keeps the image's orr order and colours. sp2/sp2p2 352 bytes.
- 0x02048744 (468 B, g3d_util): 18 -> 18. Counter after j, named objTbl in all positions, casts:
  18; u16 i or j changes the size (476/484); u32 i 21.
- 0x02031FE0 (1704 B, backup_system): 9 -> 9. Out-pointer record helpers (4 shapes) 9; u16 B
  1712, u16 B and AB 1720, u16 callee return 9. Stopped as instructed.

Notes appended: docs/notes/pkt_02040EC0.c.txt, func_020433E0.c.txt, func_0203FCA0.c.txt,
func_0203F0A8.c.txt, pkt_02048330.c.txt, pkt_02031FE0.c.txt.

Integrator: seed
- arm9 0x02040EBC arm, witness src/matched/func_02040EBC.c (the function is already EXACT; the
  0x02040EC0 label also needs to go, which is a disasm.py/layout decision).

Shards verified: none touched (nothing filed).
