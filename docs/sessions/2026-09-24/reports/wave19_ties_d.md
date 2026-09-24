# Wave 19 lane ties_d (19D)

Per address, bytes out before -> after, verdict, what moved it:

- 0x02048744: 14 -> 14, DIFF. 12 measurements: eight placements of `resIdx = resIdx;` / `i = i;` / `objCount = objCount;`, `register long`, `(long)objCount`, i initialised at declaration (58). None moved the sb/r7 pair.
- 0x0202E1F0: 21 -> 21, DIFF. 12 measurements: `o = o;` / `w = w;` at five boundaries, three of them also under dsi/1.2, an actor local (75), a Flags pointer, cnt declared first (31).
- 0x0200CA98: 147 -> 147, DIFF. 7 hand measurements (sel as a switch 396/251, self-assignments, inline offset, u16 id, scope of q); permuter anneal 1000 --types seed 2401 stayed flat.
- 0x0202CC70: 236/176 -> 240/174, DIFF, new best source in the note. Named `w`/`h` locals (`w = win->w; x1 = win->x + w;`, `h = win->h; sy = win->y; y1 = sy + h;`) reproduce the image's three live copies of y for the first time. What is left: the image spills sx to sp+0x20 and loads xmin after x1. Permuter anneal 1000 seed 2402 gave 244/244 at 121 out, but with the wrong frame (push {r3-r7}, sub #0x28), so I discarded it.
- 0x0202173C / 0x02021848: 33 / 33 -> 33 / 33, DIFF. 5 + 3 measurements (self-assignments of `a`, a block copy, a renamed parameter copy).
- 0x0204EEC8: 58 -> 58, DIFF. 10 measurements (table-load locals, sb temp, inline helpers, element pointers, store order).
- 0x0209D7D4: 43 -> 43, DIFF. 5 measurements (`buffer = buffer;`, a u8 or int zero local passed twice with a self-assignment, `(void *)0` parameter).
- 0x02011D9C: 8 -> 8, DIFF. 3 measurements (ternary and if/else single call 268/169, a mixed 0x10000 spelling 8).

Reading: under 1.1p1 the no-code self-assignment changed no bytes in any of 20 placements across five functions (and in 5 under dsi/1.2). It may only work in the 1.2 back end, and even there it did not move these pairs.

Files: notes appended under a 2026-09-24 wave 19 marker in docs/notes/pkt_02048330.c.txt, pkt_0202E1F0.c.txt, pkt_0200CA98.c.txt, func_0202CC70.c.txt, func_0202173C.c.txt, pkt_0204EEC8.c.txt, func_0209D7D4.c.txt, pkt_02011D9C.c.txt. No src files, no idioms.

Shards verified: none (nothing filed).

Seeds: none new; seeds 2401 and 2402 used.

For the integrator: nothing to integrate beyond the notes.
