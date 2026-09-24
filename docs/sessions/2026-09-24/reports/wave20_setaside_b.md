# Wave 20, lane setaside_b (20G)

Per address, before -> after bytes out:

- 0x0201C7D0: 37 (1.1p1) / 2 (sp2) -> 0, EXACT under 1.1p1, no pin. Lever: the
  scratch address as an integer, `u32 base = (u32)&g_0214655C;` after the first
  call and `(struct Scratch *)base` at all three sites. 1.1p1 then reloads the
  one pool word per site instead of caching it in r4, so z keeps r4 and its
  stack store lands last. Filed src/matched/func_0201C7D0.c; manifest --verify
  --shard pkt_0201C7D0 run twice (second pass rewrote nothing).
- 0x0201D768: 63 holds (3 hand + permuter seed 4501, 800).
- 0x0201DB20: 15 holds (2 hand; missing return gives 152/19).
- 0x0206F4C8: 2 holds (8 hand). Naming the product fixes the adds operand order
  but breaks the r6 sharing (25 to 27).
- 0x02071104: 6 holds (5 hand + permuter seed 4502, 800).
- 0x02069BA0: 6 holds (5 hand + permuter seed 4503, 800).
- 0x0209128C: 1 holds (4 hand, narrow flag against narrow constant: no movne).

Files written: src/matched/func_0201C7D0.c;
docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md; dated
wave 20 sections in docs/notes/pkt_0201C7D0.c.txt, func_0201D768.diff.c.txt,
sub_0201DB20.c.txt, pkt_0206F4C8.c.txt, pkt_02071104.c.txt, func_02069BA0.c.txt,
func_0209128C.c.txt.

Shards verified: pkt_0201C7D0 (EXACT, dsi/1.1p1).

For the integrator:
- The same spelling makes the sibling func_0201C7A4 EXACT under 1.1p1 (44
  bytes, measured once). src/matched/func_0201C7A4.c is filed under the
  ../2.0/sp2 pin; it can be refiled under 1.1p1 and its pin retired (not
  edited here, outside scope).
- Other 1.1p1 functions carrying the "address cached in a callee-saved
  register, image reloads the pool word per site" residue may close the same
  way.
- src/pending/func_0201D768.c and func_0209128C.c are unchanged.
- Seeds: none new.
