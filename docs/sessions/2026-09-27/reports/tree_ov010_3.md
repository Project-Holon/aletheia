# tree_ov010_3 report (2026-09-28, relaunch)

## Salvaged from the cut run (every source re-run, every shard verified twice, second pass rewrote nothing)

- src/matched, 42 files with shards pkt_ov010_*: 02156908, 02156954, 02156978, 0215699C, 02157260 (header corrected to EXACT*), 02157298, 02157374, 0215897C, 02160A94*, 02160C88, 02165C34*, 02165D08, 02165E34..02165FC0 (16 files, 02165FB4*), 02165FCC*, 02166164..0216627C (14 files).
- 0215D504: parked as MATCH, now EXACT (the sole-ref class resolves 021569A4 and 021569EC). Moved to src/matched with shard.
- src/pending: 02155C0C, 0215DB38, 0215DDC8, 0215DE0C (MATCH), 021569EC (header corrected to MATCH*), 021569A4, 02165ECC, 0216EB98 (DIFF).

## New this run

| function | verdict | lever |
| --- | --- | --- |
| 0215D884 (root) | EXACT | cursor read as `x = *c->pc; c->pc++`, swap index as a `u8 n = j + 1` local |
| 02156A3C, 02156AD4 | MATCH* | first draft; ov132 0x021FCE28/0x021FCE44 unlabelled |
| 0216B004 (root) | MATCH | `ok` at function scope, heap declared before mon |
| 02160018 (root) | MATCH | nested if with the call in all three arms (new idiom) |
| 02157450 (root) | EXACT* | first draft |
| 0215739C | EXACT | pooled 8 is ov008_id |
| 02157650 | EXACT | unlabelled leaf after 02157450's pool |

Near misses still open, with notes: 0216EB98 (4 bytes, one register), 02157174 (19), 021681C8 (325), 02157E9C (10, not redrafted). The notes are docs/notes/pkt_ov010_{0216EB98,02157174,021681C8,02157E9C}.c.txt. New idiom: docs/idioms/a-branch-to-a-branch-after-a-two-part-test-is-a-nested-if.md. Permuter seed 8701 only (used on 021569A4 by the cut run and on 0216EB98 here). `manifest --check` is clean.

## For the integrator

- Seeds (no labels): ov010 0x02157650 (bl from 02157450); ov021 0x021C536C, 0x021C5380, 0x021C5394 (folded into func_021C5348), 0x02189A08; ov098 0x021B6158; ov227 0x021B95C8; ov132 0x021FCE28, 0x021FCE44.
- A source run from a scratch path outside the repo loses its `matched` witnesses. Tests must run from src/pending.

## Next lane

021569A4, 02165ECC, 0215611C (370 out), 02156CE0 (508), 02155A98 (372), and the near misses above.
