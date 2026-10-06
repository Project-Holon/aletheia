# iss_road_sys (arm9)

Merge status: 2 files remain.

- `iss_road_sys_p01.c`: func_0202B1AC, func_0202B1EC, func_0202B1F4 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa thumb)
- `iss_road_sys_p02.c`: func_0202B20C (compiler 1.1p1, flags -O4,p, lang c99, isa thumb)

Blockers between adjacent files:
- `iss_road_sys_p01.c` | `iss_road_sys_p02.c`: settings differ (dsi/1.1p1/-O4,p/c99/thumb vs 1.1p1/-O4,p/c99/thumb); never merged across a settings change.

- `func_0202B1FC.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_0202B224.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
