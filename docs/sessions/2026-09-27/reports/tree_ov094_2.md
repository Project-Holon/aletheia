# tree_ov094_2

## Seeds (layout/function_starts.txt, listings regenerated)
- ov094 0x021FF3FC: bl from 0x021FD24A, 0x021FD25E, 0x021FD330, 0x021FD352, 0x021FD366 (func_021FD1CC).
- ov094 0x021FD04C: bl from 0x021FCCFA. ov094 0x021F7000: bl from 0x021FA08E. The prologue sweep already labelled both; seeded anyway.
- ov099 0x021B9FD0: pointer word 0x021B9FD1 at 0x021B98F4. It was already EXACT in a committed file.
- `disasm.py overlay 94` and `overlay 99`. pkt_021FD1CC and pkt_ov094_021F9AB8 verified twice (0 rewritten).

ovstats ov094: before `65346 8880 534 71 13.59%`, after seeds and 021F7000 `65380 9120 535 73 13.95%`. Commit 1b4bb91a then changed the metric: `65380 3482 535 76 5.33%`.

## ov094
- 021F7000 EXACT (pkt_ov094_021F9AB8).
- Root 021F9AB8: DIFF, size 1092/1092, 12 bytes out: the scheduler moves the last load of the d_0220ACA0 arms. Levers and best source are in docs/notes/pkt_ov094_021F9AB8.c.txt. Permuter seed 11301 found nothing.
- Callbacks, new shard pkt_ov094_02200A84: 02200A84 EXACT, 02200B10 EXACT (`^ 0xFFFFFFFF`), callee 021F9260 EXACT*.

## ov099, root 021BF2C4 (shard pkt_ov099_021BF2C4, 12 entries, verified twice)
- EXACT: 021B9C4C, 021BB4EC, 021BB918, 021BDD0C (no overlay hint on contested d_021C3B9C), 021C24A4, 021C1C10 (ov067 hints), 021C1CD4.
- EXACT* (padding or follower): 021B9F90, 021BA874, 021C2370, 021C1968, 021C282C (unlabelled follower 0x021C2850, no witness found).
- MATCH: src/pending/ov/ov099_func_021B9A34.c. Blocker: ov127 0x021C4948 is unlabelled (memset stub), bl from ov099 0x021B9A40.

## Files
src/matched/ov/: ov094_func_021F7000.c, ov094_func_021F9260.c, ov094_func_02200A84.c, ov094_func_02200B10.c, ov099_func_{021B9C4C,021B9F90,021BA874,021BB4EC,021BB918,021BDD0C,021C1968,021C1C10,021C1CD4,021C2370,021C24A4,021C282C}.c; src/pending/ov/ov099_func_021B9A34.c; layout/matched/ov094/pkt_ov094_021F9AB8.json (modified), pkt_ov094_02200A84.json, layout/matched/ov099/pkt_ov099_021BF2C4.json; docs/notes/pkt_ov094_021F9AB8.c.txt; layout/function_starts.txt (4 lines). manifest --check clean.

## Next lane
- ov094: 021F9AB8 (12 B), 021FE9F0, 021FD8CC, 021FD1CC.
- ov099 tree 021BF2C4, still open: 021B96D0, 021B9800, 021B984C, 021B989C, 021B9BC4, 021B9C9C, 021B9F48, 021B9FDC, 021BA0F8, 021BA978, 021BAADC, 021BAEDC, 021BB2F0, 021BB374, 021BB460, 021BB528 (1008 B), 021BDE30, 021BE3CC, 021BE448, 021BE4BC, 021C18C8, 021C1908, 021C1B04, 021C2090, 021C2224, 021C2274, 021C22E8, then the root.
- Integrator: seed ov127 0x021C4948 (ov127 lane).
