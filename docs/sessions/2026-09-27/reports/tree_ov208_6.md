# tree_ov208_6 (ov208)

## Seeds (layout/function_starts.txt; ov208 listing regenerated with `python tools/disasm.py overlay 208`)

- 0x021C0130: bl from ov208 at 0x021BFD54 (func_021BF9B0).
- 0x021C2228: bl from ov208 at 0x021C18B0 (func_021C1810).
- 0x021C2234: bl from ov208 at 0x021C18BC (func_021C1810).
- 0x021C255C: witness found. It is a bl from ov208 at 0x021BCD0C, in case 3 of the untraced jump table at 0x021BCCA0. The call sites in 1810 and BF9B0 are in untraced jump-table cases too.

All four are now code labels (345 to 349 functions). I re-verified the shards whose extent changed with `--force`, twice: 0090 (now EXACT), 0130 (EXACT*), 2228, 2234 (EXACT*), 252C (now EXACT), 1810. I updated the headers to match.

## ovstats ov208

- Before: `39128 / 25416 B, 345 funcs, 212 matched, 64.96%`.
- After the seeds: `39144 / 25432 B, 349, 216, 64.97%`.
- Final: `39144 / 20364 B, 349, 225, 52.02%`. Commit 1b4bb91a changed ovstats mid-lane, so this figure counts instruction bytes only. The drop comes from that change, not from this lane. Under the new measure this lane adds 3040 B.

## Verdicts (each shard verified twice, second pass 0 rewritten)

- 021C255C EXACT.
- Roots: 10B8, 0134 and 1AD4 are EXACT.
  - 10B8: state 5 has its own locals; `p[0x78]--`.
  - 1AD4: locals declared in the order `out1, out2, form`.
- Callees of those roots: 1E10, 1F50, 0CCC, 1920 and 0B6C are EXACT; 1D30 is EXACT*.
  - 1920: the flag is a ternary.
  - 0B6C: new idiom. Its u16 heap parameter is reloaded before each call because the callees take u16.
- 021C2238 DIFF, 16 bytes out: only the argument order in the loop. It stays in pending with a note. Permuter seed 11401 found nothing better.

## Files

- src/matched/ov/ov208_func_{021C255C, 021C10B8, 021C0134, 021C1AD4, 021C1E10, 021C1F50, 021C0CCC, 021C1D30, 021C1920, 021C0B6C}.c, plus header edits to _021C0090, _021C0130, _021C2234, _021C252C.
- src/pending/ov/ov208_func_021C2238.c.
- Shards: layout/matched/ov208/pkt_ov208_<same ten addresses>.json. Modified: pkt_ov208_021C0090, _021C0130, _021C2234, _021C252C.
- docs/notes/pkt_ov208_021C2238.c.txt.
- docs/idioms/a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters.md.
- layout/function_starts.txt.

`manifest --check` is clean.

## Next lane

021C1450 (960, the last open callee of 10B8), 021C0D5C (688, a callee of 1920), 021C2238 (loop scheduling), and the near misses 021C0544/021C4F78, 021BD634, 021C53F4 and 021C5CF0.

## Integrator

- func_021BDBAC is declared here as `(void *s, u32 on)`. Its matched body forwards r1 to BD330 and the image sets r1 = 0.
- New files use `func_XXXXXXXX` names inside.
