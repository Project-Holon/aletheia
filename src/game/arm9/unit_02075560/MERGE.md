# unit_02075560 (arm9)

Merge status: 3 files remain (every file verified).

- `unit_02075560_p01.c`: func_02075560, func_020755A8, func_02075618 (compiler 1.1p1, flags -O4,p, lang c99, isa arm)
- `unit_02075560_p02.c`: func_02075698, func_02075794, func_02075858, func_02075968 (compiler ../2.0/sp2, flags -O4,p, lang c99, isa arm)
- `unit_02075560_p03.c`: func_02075994, func_02075A2C, func_02075A94, func_02075AB8, func_02075B28, func_02075B54, func_02075B94 (compiler 1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `unit_02075560_p01.c` | `unit_02075560_p02.c`: settings differ (1.1p1/c99 vs ../2.0/sp2/c99); never merged across a compiler or flags change.
- `unit_02075560_p02.c` | `unit_02075560_p03.c`: settings differ (../2.0/sp2/c99 vs 1.1p1/c99); never merged across a compiler or flags change.
