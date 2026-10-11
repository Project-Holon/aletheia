# unit_02060468 (arm9)

Round 5 (lane s13): 2 files, all verified by tools/match.py.

- `unit_02060468_p01.c`: func_02060468 .. func_020607E8 (compiler ../2.0/sp2, flags -O4,p, isa arm)
- `unit_02060468_p02.c`: func_02060814 .. func_02060F98 (compiler ../2.0/sp2, flags -O4,p, isa arm)

Boundaries:
- `p01` | `p02`: real: func_02060814 (p02, ExpHeap layout) is DIFF when merged after the heap-common functions (func_02060C5C and later change by 12 bytes). Probable original file boundary: heap common code versus the expanded heap. All nine members build under ../2.0/sp2; the 1.1p1 tags were not real (round 5).

Round 17 (L12): not retried. SDK NitroSystem fnd code (list, heap common, expheap are separate objects in the
library), so the p01|p02 boundary is probably a real object boundary.

Round 17 (L04): greedy merge p01+p02 retried: DIFF at func_02060814. No __FILE__ anchor and no SDK member name in
layout for this range. Kept as two NitroSystem fnd objects (heapcommon / expheap).
