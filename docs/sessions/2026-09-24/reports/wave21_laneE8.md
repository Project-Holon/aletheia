# Wave 21, lane E8: blink_palanm 0x0202E1F0 (the research report's five spellings)

Every verdict comes from `tools/match.py one --diff` (dsi/1.1p1, -O4,p, Thumb). There were 73 compiles,
all written by hand, and the permuter was not used. Scratch files are in `/tmp/aletheia_laneE8`.

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt`, section "wave 21 (lane E8)" |

Nothing was filed. No file was written to `src/matched/` or `src/pending/`, and no shard was touched.

## Measurements

Each spelling was compiled on the wave-19 source ("base", 2 out) and on its s21 form (g passed w, 21 out).
Where it applied, it was also compiled on lane E7's fresh draft and on that draft's s21 form.

| research item | spelling | base / s21 | e7 / e7s |
|---|---|---|---|
| 1 | w's def inside the 0202465C argument | 2 / 21 | 2 / 21 |
| 1 | `cnt = c3` inside the 0202441C argument | 12 / 31 (spill slots only) | 9 / 28 |
| 1 | `w = (first call, ws)` as a comma expression | 400/374 (w folds) | - |
| 2 | `func_0201D478(h)`, `func_02041B6C(func_02045730(..))`, u8 getter | 2 / 21 each and together | 2 (reverted to void) |
| 3 | const on cs, and on each of the four prototypes, singly and together | 2 / 21 every time | 2 / 21 (const removed) |
| 4 | the stack parameters as one by-value struct | 408/272 | - |
| 4 | a struct holding only w | 400/374 (w folds) | - |
| 5 | loop 1 on `void *g`, with the null-based step | 21 / 40 (the guard is not folded) | 21 / 40 |
| 5 | loop 1 on g typed s32 | 18 / 37 (r4/r5 swap) | - |
| 5 | loop-2 counter reused for loop 1's constant 1 | 2 / 21 | - |
| all | the inert levers from items 1-3 combined | 2 / 21 | - |

## Findings

- An assignment written inside an argument list creates the def at that point. The w web and its constant
  fold are the same as for the statement form. In the comma-expression form, the whole of w folds.
- None of the spellings adds a reference that survives to costing. Arity fixes are codeless here, and
  const is ignored by the allocator.
- A struct member does not escape the fold. `args.w` is folded to &ws the same way a copy or a second def is.
- Merging webs by variable identity either un-folds loop 1's guard (the pointer counter) or swaps the r4/r5
  counters (the s32 g). Neither reaches the o/w balance.

## Conclusion

All five spellings from the research report are now measured, and none of them moves the one-unit o/w
balance. The best sources are unchanged: the wave-19 source and lane E7's fresh draft, both 2 bytes out.
