# unit_02061B2C (arm9)

Round 4 state: 6 files remain, all byte-exact (tools/match.py).

- `unit_02061B2C_p01.c`: func_02061B2C, func_02061B5C, func_02061B74, func_02061BB0, func_02061BC0, func_02061BD0, sub_02061C0C, func_02061C30 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_02061B2C_p02.c`: func_02061C44, sub_02061CA4, func_02061D0C, func_02061DF0, func_02061DFC, func_02061E48, DWCi_TSKlForm (compiler 1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_02061B2C_p03.c`: func_02061EB8, func_02061FF8, func_0206207C, func_0206210C, func_02062114 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_02061B2C_p04.c`: func_0206216C, func_020621FC, func_02062270, func_0206246C, func_02062474, func_020624C8 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_02061B2C_p05.c`: func_02062594 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_02061B2C_p06.c`: func_020625D8 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)

Boundaries between adjacent files:
- `unit_02061B2C_p01.c` | `unit_02061B2C_p02.c`: settings differ (../2.0/sp2 vs 1.1p1). Proven real: the pieces on one side build DIFF under the other compiler (tested in round 4).
- `unit_02061B2C_p02.c` | `unit_02061B2C_p03.c`: settings differ (1.1p1 vs ../2.0/sp2). Proven real: the pieces on one side build DIFF under the other compiler (tested in round 4).
- `unit_02061B2C_p03.c` | `unit_02061B2C_p04.c`: same compiler (2.0), blocked by g_02146B94: p03 views it as struct Save (pad to 0xc, f0c..f18) and p04 as u32 head words (g_02146B94, g_02146B98, g_02146B9C) plus struct Cfg g_02146B94_blk at the same address; func_02061FF8 also has two prototypes (void *pp, int arg) versus (u32 *head, u32 *pool). One canonical struct Cfg { head_a, head_b, pool, f0c, f10, f14, f18 } for g_02146B94 and one prototype for func_02061FF8 are needed.
- `unit_02061B2C_p04.c` | `unit_02061B2C_p05.c`: same compiler (2.0), merge fails with "not a struct/union/class": the two pieces view one global through different struct layouts. Needs a struct pass.
- `unit_02061B2C_p05.c` | `unit_02061B2C_p06.c`: same compiler (2.0), merge fails with an unsigned int to void * conversion: func_020625D8 passes a u32 where the merged prototype takes a pointer. Needs one prototype by definition.

