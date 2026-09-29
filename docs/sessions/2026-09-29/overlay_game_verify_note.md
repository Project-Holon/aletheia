# Overlay game entries that do not verify EXACT (for the overlay game developer)

A read-only check (`python tools/match.py one` per entry, nothing rewritten) of the 841
entries added in commits 48aedd09, eb48b431 and 42e426c6 found 8 that compile to MATCH, not
EXACT, although their shards record EXACT. `python tools/build.py --split --pack` refuses
the first of them, so the plain ROM build currently stops there.

| file | address | verdict |
|---|---|---|
| src/matched/ov/ov010_func_02167BFC.c | 0x02167BFC | MATCH (call to ARM9 0x02008494: no label, the listing prints it as data) |
| src/matched/ov/ov010_func_021680C8.c | 0x021680C8 | MATCH |
| src/matched/ov/ov010_func_02169004.c | 0x02169004 | MATCH* |
| src/matched/ov/ov010_func_0216CB48.c | 0x0216CB48 | MATCH |
| src/matched/ov/ov011_func_02172BC0.c | 0x02172BC0 | MATCH |
| src/matched/ov/ov011_func_02172D70.c | 0x02172D70 | MATCH |
| src/matched/ov/ov011_func_02173590.c | 0x02173590 | MATCH |
| src/matched/ov/ov012_func_021743A4.c | 0x021743A4 | MATCH |

Three more gave no verdict under the per-entry check (ov010 0x02158378, ov011 0x02175710,
ov011 0x02175BE4); they are probably multi-function units and need `match.py tu`.

A MATCH means every byte is right but one relocation has no witness. The usual fix is a
witnessed seed in layout/function_starts.txt for the unlabelled callee (and matching it), or
a region hint on the symbols: line. Until then these entries should not count as matched:
`python tools/match.py manifest --verify --force --shard <region>/<shard>` removes them.

## Entries that lost a witness when the cross-overlay leak was closed (wave 6)

tools/match.py used to read a relocation target's witness from the first overlay in load
order whose window holds the address, so a label or branch in an unrelated overlay mapped
over the same RAM could attest a site; the fix (docs/sessions/2026-09-29/reports/w6_tools.md)
accepts only the site's own overlay inside its window, or an overlay fixed by a hint or a
unique window outside it. The ten entries below lost their witness this way (each target lies
in the site's own overlay window, but that overlay's listing traces no code there) and now
verify MATCH/MATCH*; the written word may still be right.

| file | address | lost site | old witness |
|---|---|---|---|
| src/matched/ov/func_021BB3C4.c (ov021) | 0x021BB3C4 | +08 ABS32 func_021BB13C | ov206 label and branch |
| src/matched/ov/func_021BD1D4.c (ov021) | 0x021BD1D4 | +04 func_021BD474 | ov217 label and branch |
| src/matched/ov/ov029_func_021EFEF8.c | 0x021EFEF8 | +04 func_021EFEE4 | ov033 label and branch |
| src/matched/ov/ov103_func_021B793C.c | 0x021B793C | +08 func_021B7C5C | ov016 label and branch (hint `ov016`) |
| src/matched/ov/ov105_func_021B78BC.c | 0x021B78BC | +08 func_021B7C04 | ov021 label, sole-ref/code (hint `ov021`) |
| src/matched/ov/ov102_func_021B78E4.c | 0x021B78E4 | +04 func_021B7C04 | ov021 label, sole-ref/code (hint `ov021`) |
| src/matched/ov/ov172_func_021BDFEC.c | 0x021BDFEC | +0C func_021B9F98 | ov218 label and branch |
| src/matched/ov/ov172_func_021B9574.c | 0x021B9574 | +08 func_021BA094 | ov093 branch (hint `ov217`) |
| src/matched/ov/ov172_func_021BE08C.c | 0x021BE08C | +10 func_021BE07C | ov203 label and branch |
| src/matched/ov/ov217_func_021BBAD0.c | 0x021BBAD0 | +08 func_021BC574 | ov209 label and branch (hint `ov209`) |

The fix for each is evidence from the site's own overlay (a function start seeded and
witnessed in that overlay's listing), not a hint naming another overlay: an overlay's own
window can only hold its own bytes, so such a hint is now refused.

## Resolved (2026-09-29)

All 18 entries above verify EXACT/EXACT* again (docs/sessions/2026-09-29/reports/w6_fix18.md): 15 witnessed function starts seeded in layout/function_starts.txt, 5 region hints corrected, 5 new ARM9 functions matched. The plain `python tools/build.py --split --pack` succeeds.
