# Identical literal loads with different pool words need the correct call constants

summary: when every Thumb literal-load instruction already matches and only pooled immediate bytes differ, audit the value at each addressed slot before changing scheduling. Correcting which constant belongs to each call can fix an apparent pool-order residue without any C control-flow change.

Found in: `src/matched/ov/ov175_func_021DBDAC.c` (0x021DBDAC, EXACT*504-byte lead), `src/matched/ov/ov175_func_021DBFB4.c` (0x021DBFB4, EXACT480), dsi/1.1p1 -O4,p Thumb.

Both earlier spellings compiled the correct instructions and pool-load offsets, but three constants were attached to the wrong calls. Each left three concrete pool bytes different. Scheduling and type changes had not fixed them.

For a Thumb literal load, its slot is `((instruction_address + 4) & ~3) + displacement`. Read the four bytes at that slot as a little-endian value. These are the three decisive loads in each function:

| Function | Load address | Displacement | Pool slot | Correct constant |
| --- | --- | --- | --- | --- |
| 021DBDAC | 021DBECC | C8 | 021DBF98 | 11A0 |
| 021DBDAC | 021DBF00 | 98 | 021DBF9C | 11BE |
| 021DBDAC | 021DBF30 | 6C | 021DBFA0 | 11CA |
| 021DBFB4 | 021DC0C8 | BC | 021DC188 | 125C |
| 021DBFB4 | 021DC0F2 | 98 | 021DC18C | 126F |
| 021DBFB4 | 021DC122 | 6C | 021DC190 | 127B |

The first function needs error/cancel/timeout calls with `0x11a0`, `0x11be`, `0x11ca`; the previous spelling supplied `0x11ca`, `0x11a0`, `0x11be`. The second needs success/cancel/timeout calls with `0x125c`, `0x126f`, `0x127b`; it previously supplied `0x127b`, `0x125c`, `0x126f`.

Changing only those call arguments reached EXACT*/EXACT with the same instructions, load offsets, and sizes. The scheduler-pool-order idiom has differing load order or relocation positions; identical literal-load bytes in this shape justify checking the source constants first.
