# tree_ov094 (relaunch)

Salvage: none. No uncommitted ov094 files were left by the cut run; its earlier
work (pkt_021FD1CC: 021F8694, 021F8710, 021FD070) was already committed.

## Tree 1: root func_021FD1CC (1792 B), 11 open, shard pkt_021FD1CC
EXACT: 021F7F1C, 021FD088 (the mode result doubles as the return value),
021FF3FC (unlabelled; field copies, not a struct assign), 021FCF2C (EXACT*),
021FD04C (unlabelled), 021FF3F4 (EXACT*, tail-call stub).
DIFF, notes appended to docs/notes/ov094-lane-func_021FD1CC.c.txt:
- 021FD1CC: 8 bytes, the kind==4 swap (dx/dy registers). All 720
  declaration orders tried. Even at 0 bytes it caps at MATCH, because 13 ARM9
  accessors (0x02051790..0x02051830) are unlabelled.
- 021FD8CC: 46 bytes, the zero register gets allocated differently.
  Permuter seed 10401 found nothing usable.

## Tree 2: root func_021F9AB8 (1092 B), 17 open, shard pkt_ov094_021F9AB8
EXACT: 021F899C, 021F89BC, 021F8B40 (counter set before the global load),
021F896C, 021F8684, 021F7208, 021F918C, 02201934, 021FF16C, 021FF1B0,
021FDB20, 0220074C (non-const vector params force the reloads),
021FF630, 021F6F48 (EXACT*).
MATCH (pending): 022006B4, blocked on the unlabelled ARM9 Thumb leaf 0x02015D30.
DIFF (docs/notes/pkt_ov094_021F9AB8.c.txt): 021FE9F0, 73 bytes. The loop keeps
a guard that our build folds away.

Shards verified twice (second pass: 0 rewritten). 9 + 14 entries. manifest --check is clean.

## Remainder for the next lane
021F9AB8 (root, not started: a multi-switch with cross-jumped arms),
021FE9F0, 021FD8CC, 021FD1CC, callbacks 02200A84 and 02200B10 (passed by
021FF630). ov099 not reached.

## Seeds / integrator
- Add to function_starts: 0x021FF3FC, 0x021FD04C (both EXACT now), and
  0x021F7000 (follower of 021F6F48).
- ARM9 session: unlabelled leaves 0x02015D30 and 0x02051790, 0x020517A4, 0x020517B4,
  0x020517D0, 0x020517D8, 0x020517E0, 0x020517E8, 0x020517F0, 0x02051800,
  0x02051808, 0x02051818, 0x02051820, 0x02051830. Filing them unblocks
  022006B4 and the 021FD1CC root.
- Stage: src/matched/ov/ov094_func_*.c (20 files), src/pending/ov/ov094_func_022006B4.c,
  layout/matched/ov094/pkt_021FD1CC.json, pkt_ov094_021F9AB8.json, and the two notes.
