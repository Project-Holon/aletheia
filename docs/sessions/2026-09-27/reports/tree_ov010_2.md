# tree_ov010_2 report (2026-09-28, relaunch)

## Salvaged from the cut run (re-verified, both shard passes clean)

EXACT/EXACT* in src/matched (20, with shards pkt_ov010_*): 02156074*, 021568E0, 02157384, 0216025C*, 0216040C, 02160564, 021606DC, 0216070C*, 0216075C, 021607E0, 02160A28*, 02160A4C*, 02160A64*, 02160A7C*, 02164480, 021644C4, 021644F4, 0216D9E4*, 0216DD1C, 0216F3D4 (headers corrected to EXACT* where the tool says so). Pending: 021568A8, 0216F40C, 0216F830 (MATCH), 0215611C, 02157E9C (DIFF).

**Do not stage** src/matched/ov010_func_021605C0.c or layout/matched/ov010/pkt_ov010_021605C0.json: they duplicate the committed pkt_021605C0 (`manifest --check` reports it). The deletion was refused here.

## New this run

| tree | function | verdict | lever |
| --- | --- | --- | --- |
| 02157E9C | 02157E9C | DIFF, 10 insns | 288-shape grid and pid splits flat; notes |
| 02169AB8 (852) | 02169AB8 | DIFF, 1 insn | tool ISA refusal, see below |
| | 02169EA4*, 02169EBC, 02169FFC, 0216A07C*, 0216A148 | EXACT | first draft |
| | 0216A0BC | MATCH | 0x021904A8 unlabelled (ov021) |
| 021681C8 (800) | 0216869C | EXACT | u8 local; `const u16 *` nick pointer |
| | 021681C8 | DIFF | allocation (rec in r7); notes |
| 02155C0C subtree | 02156710, 02156770*, 021567D8, 02156F68, 02156F98, 02156FD0, 0215700C, 021572A8, 02157278* | EXACT | first draft or one reshape |
| | 02156824 | EXACT | call result through a local |
| | 02157028 | EXACT | `u8 buf[6] = {0,...}` in a nested block |
| | 021572E4* | EXACT | u8 slot parameter |
| | 02156420* | EXACT | u16 local for the deref, nested-block array |
| | 02156934*, 021572C0* | EXACT | decl order |
| | 02155FB4, 02155FC8, 02156B74, 02156530 | MATCH | ov186-window callees unlabelled |
| | 02157174 | DIFF, 19 | j/row register swap |

Total: 21 EXACT, 5 MATCH, 3 DIFF. Notes: docs/notes/pkt_ov010_02157E9C.c.txt, pkt_ov010_021681C8.c.txt. Permuter seeds 7201-7203 used.

## For the integrator

- Tool: `isa_evidence()` answers 0x021A153C with ov009's ARM label (DWC ProcessIncomingData) for an ov010 `bl` into an ov021 Thumb thunk, and ignores the `ov021` hint on the symbols line. That is the only diff in 02169AB8 (filed declaring `arm`).
- Seeds: ov021 Thumb thunks 0x021A1500..0x021A1554 (12-byte stride) and 0x021904A8; ov186 window 0x021FD4F8, 0x021FD8F8, 0x021FD948, 0x021FD954, 0x021FD95C; ov010 leaves 0x0215725C, 0x02157260, 0x02157298, 0x02157364, 0x02156954, 0x02156978, 0x0215699C, 0x021569A4.

## Next lane

02155C0C (792, root of the subtree above), 0215D504, 02160A94, 02165FCC, 0215DB38, 0216EB98, 0215D884, 0216B004, 02160018, 02157450; near misses 021681C8, 02157174, 02157E9C.
