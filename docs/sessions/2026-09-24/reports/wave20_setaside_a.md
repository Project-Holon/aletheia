# Wave 20, lane setaside_a (20F)

Per address (1.1p1):
- 0x02011688 (ica_anime): 14 -> 0, EXACT* (54 code bytes exact; the 56-byte
  extent includes a 2-byte pad). What moved it: the two-return form with
  `idx %= n` (the parameter homing from wave 10) plus the table base held as
  an integer, `u32 base = (u32)p->f1c`, with `base + idx * 12` and `base +=
  off`. The integer type is load-bearing (`u8 *base` is 50/25). 3 measurements.
- 0x0202173C / 0x02021848 (palanm): 33 / 33, unchanged. The palanm.h structs
  have no s8 fields. Tried: s8, s16 and u16 `done`, two inverted-guard tails
  (244/135), `done = 1` at the head of the body, integer slot addresses. 7
  measurements.
- 0x02048744 (g3d_util): 14, unchanged. Tried: guarded do-while (32), an
  inverted early return (484), `short i` (476), a heap-id local (472), an
  integer res base (472). 5 measurements.
- 0x0209D7D4 (MSL console hook): 43, unchanged. Tried: s8 `c`, an s8 callee
  parameter, an integer end pointer. 4 measurements.

Permuter not run: every note already records a permuter negative, and the
hand levers from the brief did not move any of the three.

Files written:
- src/matched/func_02011688.c (new, EXACT*)
- docs/idioms/an-integer-table-base-multiplies-into-a-copy-of-the-index.md
  (new)
- note appends under 2026-09-24 wave 20 markers: docs/notes/pkt_02011688.c.txt,
  docs/notes/func_0202173C.c.txt, docs/notes/pkt_02048330.c.txt,
  docs/notes/func_0209D7D4.c.txt

Shards verified: pkt_02011688 (manifest --verify twice; the first pass
rewrote layout/matched/arm9/pkt_02011688.json and the second rewrote
nothing).

Seeds: none noticed.

For the integrator: commit the shard JSON together with the source. Regenerate
the idiom index. The integer-base lever is worth trying on other Thumb near
misses that multiply an index in place where the image multiplies into a copy.
