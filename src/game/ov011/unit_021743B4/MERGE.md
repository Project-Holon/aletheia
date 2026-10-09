# unit_021743B4.c

Round 4 (r4_ov04): 9 parts -> 2. Hidden functions added: func_02174690, func_02174798, func_021747E0 (in p01) and func_02174898 (in p02). The old p05..p09 (0x02174854..0x02175BE4) are now one part (struct Ent_02174F54 is the one Ent layout, func_02082D44 takes (const void *src, void *dst, int n)).

Left: p01|p02 boundary is the uncovered block 0x0217482C..0x02174854 (40 bytes): `void f(int a, int b, u8 *c, u8 *p)` copying 4 bytes c[0..3] to p[a*4 + 0x8d4 ..]. The target loads two bytes, stores two, loads two, stores two. Tried: plain byte stores, u8 temporaries, struct copies of {u8 a,b,c,d}, u8[4], two {u8,u8} pairs, a loop. All give DIFF. Needs another source shape.
