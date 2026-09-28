# seeds_2 report (2026-09-28)

## Resolver fix (tools/match.py, selftest 241 to 245)

Cause: `source_key()` returned None for a source outside the repo (a lane's scratchpad copy), and `attest_matched()` refuses a None source outright. Every `matched` callee was lost that way, not by a region mismatch. tree_ov010_3 saw the same thing. Fix: an outside path now gets the key `external:<abs path>`. No manifest source can equal that key. For such a source, an entry inside the compared range is refused. `suggest_split` now passes the symbols-line hint and the site region.

ov175 0x021DA6B8, scratchpad copy: before, 80 of 83 relocations resolved (1102 concrete bytes out). After, 83 of 83 resolved (1110 out, because the three sites are now compared).

Selftests added: the ov175 entry attests an external ov175 caller that has the hint; it does not attest an ov119 caller; external key; in-range refusal.

## Seeds (layout/function_starts.txt, witness in each comment)

- arm9: 02009EC8, 0200DFD8, 0200DFE4, 02012F68, 02012F74
- ov009: 02156F50
- ov177: 021E8AB4, 021E8AB8
- ov010: 02157650
- ov021: 021C536C, 021C5380, 021C5394, 02189A08
- ov098: 021B6158
- ov227: 021B95C8
- ov132: 021FCE28, 021FCE44, 021FD83C, 021FD8EC, 021FD908, 021FDA6C

## Matched (shards verified twice)

- func_02009EC8 (EXACT*), unit_0200DFD8 (EXACT), unit_02012F68 (EXACT)
- func_02156F50 (EXACT), func_021E8AB4 (EXACT), func_021E8AB8 (EXACT*)

Worklist: open 0, 100 percent.

## Promoted

- ov175: func_021D7E18 (EXACT*), func_021D965C (EXACT), func_021D9D50 (EXACT*)
- ov010: 02156A3C (EXACT*), 02156AD4 (EXACT*), 0215DDC8, 0215DE0C, 02160018 (EXACT)

## Still MATCH

- ov010 02155C0C: 0215611C (DIFF pending)
- 0215DB38: ov100_id, d_021BB6A4
- 0216B004: d_021B6D74, d_021B98A4

Permuter: unused.
