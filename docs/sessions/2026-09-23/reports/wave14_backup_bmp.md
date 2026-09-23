# Wave 14, backup_system.c and bmp.c lane

EXACT 2 (1036 bytes) / MATCH 0 / DIFF 1.

- EXACT 0x0203335C sub_0203335C (156 B, ARM, 1.1p1), src/matched/sub_0203335C.c, shard pkt_0203335C.
  Levers: mask `(long long)(3 << sh) ^ -1` (fixes the 3/-1/mask colours) plus `slots[(int)w]`
  on the first read only (fixes the w/slots/v rotation); found by sweep (2640 + 4320 points) after
  a permuter anneal pointed at the cast. Four earlier lanes sat at 21 bytes.
- EXACT 0x0204427C func_0204427C (880 B + 8 pool, ARM, 1.1p1), src/matched/func_0204427C.c,
  shard pkt_0204427C. Levers: q-then-p with `v += pal; *p = v;` braced (276 -> 114, size right),
  `xx * 4` in a named temporary (permuter anneal, ablated to this one: 4), keyed source pointer as
  plain `src->pixels + ...` (48-point form sweep: 0).
- DIFF 0x02031FE0 (1704 B, size-exact), still 9 bytes: B / A+B register swap (image B r8, AB r4).
  Near miss single divergence: `+0x380 mov r8, r0` compiled `mov r4, r0` (and its 7 dependents).
  Hill 800, anneal 2000 (focused), 1.1p1 / ../2.0/sp2 / sp2p2 / sp1p7 / 1.2 / ../1.2/sp4, and
  about 300 swept variants (casts, parameter-variable reuse, register, dead inits, pointer spellings)
  all 9 or worse. Appended to docs/notes/pkt_02031FE0.c.txt with the best-source marker.

Notes appended: docs/notes/sub_0203335C.c.txt, docs/notes/pkt_02043B98.c.txt, docs/notes/pkt_02031FE0.c.txt.
Headers updated: docs/families/backup_system.h (0x0203335C entry), docs/families/bmp.h (0x0204427C EXACT).

Integrator: seed
- none (both files are labelled functions, verdict EXACT, not EXACT*).

Shards verified: pkt_0203335C (1 entry EXACT), pkt_0204427C (1 entry EXACT). No entries witness
each other, so one pass each.
