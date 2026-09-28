# tree_ov135_3 (ov135, relaunch)

## Salvage

There was nothing to salvage. The cut run's four leaves (021FD08C, 021FD760, 021FD790 and 021FFD1C) were already committed in 74c486e7, and there were no untracked ov135 files.

## Trees (all ten briefed roots, 59 functions)

- **57 EXACT/EXACT\*.** Each is in src/matched/ov/func_ADDR.c with layout/matched/ov135/pkt_ADDR.json, and each shard was verified twice (second pass 0 rewritten). The 57 are:
  - Roots: 021FCC40, 021FD924, 0220189C, 022005EC, 021F6E58, 021FAFF0, 021F9FF0, 021FA85C, 021FA394.
  - The callees listed in scratchpad/tree_ov135_3/filed.txt, including the two VBlank callbacks the roots install: 021FD8BC and 021FF50C.
- **Pending: 022010BC, MATCH.** Its only blockers are five unlabelled Thumb call targets.
- **Pending: 021FF384, DIFF.** The allocator keeps the zero in r7 where the image keeps 0x440. The permuter (seed 10601) did not help. Notes are in docs/notes/pkt_021FF384.c.txt.

## What closed them (existing idioms only, no new idiom file)

- Declaration order sets the stack order: 021FC8CC and 021F84EC.
- Arms written out in full, and inner switch arms in source order: 021F8010, 021FD104, 022010BC and 0220189C.
- A local for the shared store: 022022B8.
- Struct padding: 021FD924. A 6-byte Rec shifted every offset by 4 and pushed 0xD50 into the literal pool.
- Overlay-hinted proc templates d_021E75xx (ov119) with ov119_id: 021F6E58.
- DWC_GetDateTime used as the ov009 SDK witness: 0220246C.

## Seeds (unlabelled starts with a witness site)

- 0x0200FB4C (arm9, Thumb), called from 022010BC.
- 0x021B97F4, 0x021B99F0, 0x021B99F4 and 0x021B9A14 (ov114, Thumb), all called from 022010BC.
- 0x021FAC84 (ov135, Thumb, `return -1`). It sits inside func_021FAC50's extent, which is why that function is EXACT\*.

## Integrator

- Several callers declare returns or arguments that the callees' own bodies do not. Nothing breaks, because the bytes match:
  - The callers pass an argument to 021FCF28 and 021FDD00, which are void(void).
  - The callers use the returns of 0220052C, 022026BC and 021FC8A8 (declared u16 in the caller).
- `manifest --check`: my shards are clean. The only duplicates are ov010 0216742C and 02167444, which belong to another lane.
- Stage explicitly: the 57 source/shard pairs, src/pending/ov/func_022010BC.c, src/pending/ov/func_021FF384.c and docs/notes/pkt_021FF384.c.txt.

## Next lane (open ov135 roots, biggest first)

021FB800, 021F601C, 021F61D4, 021FA15C, 021F57EC, 021F5CFC, 021F8358, 021FB3D8, 021F8BE8, 021F4580, 021FEC00, 02200ED8.
