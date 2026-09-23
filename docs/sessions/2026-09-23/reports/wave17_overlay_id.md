# Wave 17E: the overlay_id evidence class

Rule (tools/match.py `attest_overlay_id`, tried after every other class, ABS32 data sites only, once the function's other sites are resolved). All three required:
1. the declared value is an overlay `id` in layout/layout.json (0..236);
2. a pc-relative `ldr` in the function's own code addresses exactly the site (decoded from the instruction bytes, so unlabelled continuation words and pools printed as code count);
3. walking forward from that load (register copies and unconditional `b` followed; conditional branch, unmodelled instruction, other call or more than 8 steps refuses), the first call is to a loader-table entry, that call site resolved on its own evidence, and the entry's id register still holds the loaded value.

Loader table `OVERLAY_ID_CONSUMERS`: FS_LoadOverlay 0x02079264 (r1), FS_UnloadOverlay 0x020792B8 (r1), sub_02034AC4 (r0), sub_02034A5C (r0), func_02031538 (r0), func_020314F4 (r1), func_02031348 (r1), func_020120B4 (r1): all from EXACT sources or symbols_sdk; func_020312CC (r0) from its listing (not matched).

Selftest: 166 cases, all pass (+7 overlay_id: hand-built positive, no loader, not a pool word, 0xEE past the last overlay (0xED is a `literal` elsewhere), wrong register, clobbered register, end-to-end func_0215FA34 EXACT; +1 stale fixture fixed: 0x021DFDB8 is labelled since seed round 9, so the "no overlay labels" case now uses 0x0215E334; it failed at HEAD).

Verdicts (before, after), moved to src/matched:
- func_0200F234, func_0200F17C, func_02014878, func_0202F9F8, sub_02009800, func_020120C0: MATCH, now EXACT
- func_0215FA34, func_0215FA44 (ov010): MATCH, now EXACT
- func_020274C8: MATCH*, now EXACT* (extent runs over sub_020274F8)

Still MATCH (ids resolve, notes updated): func_02010AC4 and func_02010C34, blocked on the ov data 0x021D6338 / 0x021D654C. The fix is to seed both pools as .word.

Shards verified twice (second rewrote 0): arm9 pkt_0200F17C, pkt_02014808, pkt_0202F9F8, pkt_020274C8, pkt_020120B4, pkt_02009800 (new), ov010 pkt_0215FA34 (new).

Integrator: stage tools/match.py, docs/MATCHING.md (new table row and section), the 9 moved files, 2 pending notes and the 7 shards. Update README figures. Not committed.
