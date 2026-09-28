# tree_ov010_4 report (2026-09-28, relaunch)

## Salvage and the brief's named items

- 02169AB8, 02156CE0 and 02155A98 were already committed EXACT (the `thumb ov021` fix is in). I re-ran all three and they are still EXACT. Nothing needed doing.
- 021569A4 is still DIFF, 2 bytes out. 0215611C is still DIFF, 20 bytes out (permuter seed 9601 was used by the cut run). Both notes files have new measurements.
- **02165ECC is now EXACT\*.** The `cmp #38; bgt` / `cmp #47` switch tree only appears when the 16..38 run has 10 or 11 case labels (idiom file).

## New this run: 25 EXACT/EXACT\*, 6 MATCH, 2 DIFF

| function | verdict | lever |
| --- | --- | --- |
| 02168924 (root) | EXACT | frame declaration order, u8 IV, u16 `rank` |
| 0216883C, 021684E8 | EXACT | 021684E8: EV share as an int, `n` reused as the counter |
| 02167FB4 | EXACT\* | `heap` read into a local |
| 0215BE24 | EXACT | nested alloc check, version compared via a local |
| 0215C63C, 0215840C | EXACT, EXACT\* | first draft |
| 02161070 | EXACT | arms in image order, party fetch split into its own statement |
| 02161724 | EXACT\* | pointer local set to NULL and then tested (idiom file) |
| 0216DE54, 0216DE94 | EXACT, EXACT\* | declaration order |
| 021619B8 | EXACT | `t > 15u`, floor local |
| 02162970 | EXACT\* | u32 count, `type == 2 \|\| type == 3` (idiom file) |
| 02162E48, 02162E9C, 02164708 | EXACT | sub-struct pointer |
| 021673A8, 021673C4, 021673E0, 0216745C, 0216747C, 0216749C | EXACT/EXACT\* | first draft; 0216749C needs a signed page |
| 0216EE7C (root), 0216EE20 | EXACT | `u32 *` result |
| 0215C95C | MATCH | ov011 0x02175FB4 unlabelled; ov071_id and 0x021BA758 unattested |
| 02164A2C | MATCH | 0x021BDB40 (ov216 process template) unattested |
| 02164C64 | MATCH | ov011 0x02177BF4 unlabelled |
| 02166D30 | MATCH | arm9 0x02024108 unlabelled |
| 0216C538 | MATCH | arm9 0x0201A354 unlabelled |
| 0216EE40 | MATCH | arm9 0x0201313C unlabelled |
| 021664CC | DIFF, 10 bytes | argument-store scheduling; permuter seed 9602 flat |
| 0216F948 | DIFF, 144 bytes | struct copy chains fold; notes |

Every shard was verified twice, and the second pass rewrote nothing. `manifest --check` is clean.

## For the integrator

- **Stage these (all untracked, nothing staged):** every `?? src/*/ov/ov010_func_*.c` and `?? layout/matched/ov010/pkt_ov010_*.json` in `git status`. Also stage the deletions of `src/pending/ov/ov010_func_02165ECC.c` and `021684E8.c`, the three new idiom files, and the notes for 021664CC, 0216F948 and 021569A4.
- **Duplicates removed:** I had created duplicate files for 0216742C and 02167444, which already existed as `pkt_0216742C` and `pkt_02167444`. I deleted my copies.
- **Seeds (no labels yet):**
  - arm9 Thumb: 0x02024108, 0x0201A354, 0x0201313C
  - ov011: 0x02175FB4, 0x02177BF4, 0x02176880

## Next lane

- ov010 has no real roots of 256 bytes or more left: 02170A3C and 02170EA4 are pointer tables, not functions.
- Next is the 200–256 byte band: 0215A214, 0215A370, 0215BBD0, 0215BD2C, 0215C200, 0215CB08 and so on.
- Open callees: 02164D6C, 02164FD0, 02166E50, 0216C484.
- Near misses: 021569A4, 0215611C, 021664CC, 0216F948, 02157174, 021681C8, 02157E9C, 0216EB98.
