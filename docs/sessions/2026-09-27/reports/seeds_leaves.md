# Seeds and leaves lane (2026-09-27)

Seeded in layout/function_starts.txt, listings regenerated (arm9 --split, overlay --all, ov011 again), worklist refreshed.

New functions, all EXACT, shards verified twice (second pass 0 rewritten):
- arm9 0x02015FBC (byte insert at +0x140), 0x02015FD4 (9-bit field at bit 14), 0x02051A34 (getter +0x94)
- ov119 0x021E3E40 (tail call 0x0204A48C with two ov119 tables and the u16 at +0x5F4)
- ov011 0x02175368 (sub_02082BCC(p+0x15C, 0, 4)), 0x0217537C (follower: p+0x15C if its byte is 1)

Two extra seeds beyond the four named, needed to clear stars: 0x02015FD4 (witness ov094/ov131 bl) and 0x02015FF0 (already matched, witness ov094/ov119/ov195 bl); ov011 0x0217537C has no branch witness, only the structural one (starts after 0x02175368's pool, ends bx lr before func_0217538C). Integrator: confirm that line.

ARM9 game code: open 0, 100.0000 percent (400810 / 400810).

Promoted to src/matched: ov117_func_021D49F4, ov117_func_021D4BF4 (EXACT); ov118_func_021D4A54, 021D58F0, 021D5950, 021D6E6C, 021D6ECC, ov018_func_0217FE38 (EXACT*, 2-byte alignment padding only).

manifest --check clean; the ov010 021605C0 duplicate was already resolved by that lane. Permuter not used.
