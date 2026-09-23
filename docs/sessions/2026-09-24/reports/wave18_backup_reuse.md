# Wave 18 lane report: backup_reuse

0x02031FE0 (backup_system.c, ARM, 1704 bytes): 9 -> 9, DIFF, no move.

Hypothesis: the loop registers AB r4, B r8, A r7 equal the prologue homes of
heap, mode and gen, so the original reused those dead parameters as loop
variables. Tested with 19 measurements (two of them declaration sweeps):

- All 6 full mappings (both loops): 44 to 58. The implied one
  (AB=heap, B=mode, A=gen) is 48.
- Partial reuse: AB=heap 9 (the object is identical to the baseline because
  heap's web is split). B=mode 45, A=gen 39, pairs 39 to 48. Implied mapping
  in the record walk only: 48. Reuse in the copy-back loop only: 9 (webs split).
- Declaration sweeps on the reuse sources: 120 orders on A=gen+B=mode give a
  best of 44. 720 orders on A=gen give a best of 39.
- Loop index as a parameter: i=mode 14, i=gen 17.
- Permuter (anneal, --types, 1500, seed 1851, from the 48 source): 14.

Finding: the mode and gen webs merge with a reusing local, but 1.1p1 colours
the merged web elsewhere. With mode/B the merged web lands in sb and gen/A in
r8, and i moves to r7. The image's r8/r7/sb needs the opposite. With i=mode,
mode moves to sb and the B/AB swap stays unchanged. The swap is independent of
the parameter webs, so the register coincidence is not caused by parameter
reuse. It remains an allocation tie.

Files written: docs/notes/pkt_02031FE0.c.txt (dated wave 18 backup_reuse
entry with every measurement; the best source is unchanged).
Shards verified: none (nothing filed).
Seeds: none noticed.
Integrator: nothing to do. No new idiom.
