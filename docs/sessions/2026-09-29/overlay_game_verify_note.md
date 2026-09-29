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
