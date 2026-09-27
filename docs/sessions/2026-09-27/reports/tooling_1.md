# Tooling lane 1 (2026-09-27)

Selftest: 224 cases (206 before, +18), 4 failures, all pre-existing (see Flags).

Changes (tools/match.py unless noted):
1. `overlay_data_structure()`: an extent ends at its last instruction's real length (the byte count the listing prints). ov010 0x0216FED8 is data again. func_02155328 promoted EXACT.
2. `OVERLAY_ID_CONSUMERS` gains 0x020124AC (r1, read from src/matched/func_020124AC.c). `OVERLAY_ID_WALK` goes from 8 to 24: ov100/ov195/ov119 need 19/15/10 steps, all instructions the walker already models. Selftests: an 18-step walk resolves, a clobbered id is still refused, and a walk past the bound is refused. docs/MATCHING.md updated.
3. Overlay pool words as `literal` witnesses: refused. All six addresses lie in 2 to 17 overlapping windows. The ov010 words naming them sit in untraced code, so they are not pool words. The two labelled pools (ov021, ov174) are in overlays whose own windows cover the address, so they name other objects. The reason is written in match.py.
4. Promoted: ov010 func_02155328 (EXACT), ov195 func_0220609C (EXACT*, alignment padding). ov010 func_02155478 is now 91/97 and stays MATCH (the six data sites).
5. FRONTEND-PINS: `.comment` stamp tell row; aoss.o `../2.0/sp1p2` pin row.
6. Ten arm9 seeds with witnesses, listings regenerated, worklist refreshed.
7. Manifest kind `runtime`, plus worklist `classify()`/`cover_from_entries()` and a summary line. The 12 runtime2 files are in src/matched, each shard verified twice. Summary: game unchanged (4485 fns, 400424 B), runtime reproduced 34 of 34 (8964 B). coveragemap gold #e0b020: 68 gold function rects. csrc splices only each runtime entry's first function.

Foldin: sha1 26ad0b99... holds.

Flags (not changed, figure-moving, owner decision): commit 0b639465 added
- `attest_sole_ref_data` accepts any address in 0x02000000..0x02008000 or 0x04xxxxxx with no start/alignment check (the 4 selftest failures);
- coveragemap `render_arm9` redraws every `open` function as `matched`, so the map says 100.00% where worklist says 99.95%.
