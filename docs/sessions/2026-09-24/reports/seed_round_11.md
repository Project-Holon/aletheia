# Seed round 11: data-object map regenerated, HANDOFF brought to wave 18

## Data-object map

`python tools/datamap.py` on the current tree, installed as reconciled in `datamap_reconcile.md`:
1474 derived rows (1091 pool, 348 string, 35 table-guess) against 1506 committed. The hand-declared
section is carried over byte for byte. Exactly the 32 stale rows listed in the reconcile report are
dropped (29 pool words that are now function pointers into traced code, 3 strings whose bytes are now
instructions); none added; the other 1004 changed lines are referrer-unit renames. tools/datamap.py is
unchanged.

## Worklist and figures

`worklist.py --refresh` and `--summary` on HEAD plus this round's files only (a clean worktree, because
the shared tree held other lanes' uncommitted shards and sources): 4391 functions, 386994 of 400306
bytes, 96.6745 percent exact, 96.7755 percent reproduced, the same as `9a167b7`. The sole-ref share
moves from 215 functions / 47106 bytes to 209 / 46608 through the evidence changes below.

## Re-verified shards

The 53 matched shards holding any source that cites one of the 32 addresses (packets found from the
file headers, then the shard that lists each source), 195 entries, `manifest --verify --shard` twice
each. The second pass agrees with the first everywhere.

- One verdict change: pkt_02094488, 0x020944CC EXACT* to EXACT. The reconcile lane saw the same change
  under the old map (it comes from the match.py now committed, not from the map).
- Evidence-only changes, status unchanged: code sole-ref entries dropped on 0x02029F6C, 0x0202B500,
  0x0202B7BC, 0x0202BAF4, 0x0204BE38 and 0x0209AB80 (their targets are matched and attest directly);
  0x02095AA4 gains `code:0x02094B8C` (__strtold is open).
- pkt_02098B44 re-verified with no change to its committed entries; it is not staged here because a
  wave 19 lane has added an entry to it in the working tree.

## Fold-in

`python tools/session/wave.py foldin` passes: rebuilt ROM sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5.
Its printed figures (97.52 / 97.62) include wave 19's uncommitted files in the shared tree and are not
this commit's. For the same reason this round is committed with explicit paths and the wave.py message
format instead of `wave.py commit`, whose `git add -u layout/matched src/matched docs/sessions` would
have swept other lanes' in-flight files in.

## HANDOFF

Current-figures block, a 2026-09-24 table (wave 18 commits `319410d` to `8f90ffa`), owner decision 7
(orders of 2026-09-24, DSi key policy, the 0x0209128C pin ruling, backup_system declared a tie), and
section 6 rebuilt from the worklist at `9a167b7`: 2 MSL bodies in progress, 3 ties in progress, 25
documented ties, and 0x0206DC00.
