# tree_ov170_5 report

## Salvaged (committed in 353641bf, re-verified EXACT, shards verified twice, 0 rewritten)

ov170_func_{021E0200, 021DDAE8, 021DE428, 021E8BF8, 021DD530}.c. 021DCB8C stays DIFF (14 bytes, zero-register residue; permuter seed 10501 flat; docs/notes/pkt_ov170_021DCB8C.c.txt).

## New: 25 EXACT, 2 MATCH, 3 EXACT held in pending

| root (trees) | verdicts | what closed it |
|---|---|---|
| 021E3340 | EXACT; leaf 021EBD1C | first drafts |
| 021E3C88 | EXACT; leaf 021ED508 | work pointer read through a local, so 0xA194 is not CSEd into the increment |
| 021E0470 | EXACT; 021DE530 | template 021E0ABC |
| 021E6A60 | EXACT; 021EC45C, 021EC48C, 021ED1C8, 021E122C, 021DE980 | 021ED1C8: `int j < 8u` (new idiom); 021E122C: inverted conditions; 021EC48C: u16 box |
| 021E99B0 | EXACT; 021E072C, 021EC61C, 021EBC58, 021EBA84, 021EBA30, 021EAC28 | 021EC61C: int window id; 021EAC28: hoisted 0x8C load |
| 021E7A10 | MATCH; 021DCF58, 021E8FE8, 021E95CC, 021EBAF8, 021EBCB4 EXACT | blocked by seed below |
| 021E6D00 | EXACT | twin of 021E6A60 |
| 021DD718 | MATCH | blocked by seed below |

New idiom: docs/idioms/a-signed-index-under-an-unsigned-bound-keeps-the-window-sum-uncached.md. `manifest --check` clean. Permuter used once (10501).

## Seeds (integrator)

- 0x021EBB1C, 0x021EBB28, 0x021EBB34: the listing shows one 64-byte ARM function; they are three Thumb functions, EXACT in src/pending/ov. Witness: bl at 0x021E7B6E. Seeding them promotes those three and 021E7A10.
- 0x02019CF8 (arm9): 8-byte Thumb thunk, decoded as ARM; witness bl at 0x021DD750. Promotes 021DD718.

## Next lane (ov170, lane.py band 200+)

021E2334 (440), 021E87A0 (432), 021E644C (408), 021ED370 (408), 021E594C, 021E5AD4 (392), 021E8A74 (388), 021ECDF4 (388), 021DEDD8 (384), 021E5C5C (380), 021E73D8 (372), 021E81D0 (368), then 021DC9E0 and the 200 to 360 byte rows.
