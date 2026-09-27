# tree_ov010 report (2026-09-27)

Root candidates: 0x02170EA4 (7420 B) and 0x02170A3C (1128 B) are phantoms: Thumb code-pointer tables whose first word decodes as a `push {..., lr}`. 0x0216FEAC is real but only 44 bytes; the rest of its extent is rodata.

## Tree 1: root func_02155478 (1388 B, 28-state machine), 9 functions

| function | verdict | what closed it |
| --- | --- | --- |
| 0x02155160 | EXACT | first draft |
| 0x02155200 | EXACT* | declaration order (i before n) |
| 0x02155224 | EXACT* | first draft |
| 0x02155A4C | EXACT* | first draft |
| 0x02155A6C | EXACT* | first draft |
| 0x0215518C | EXACT | declaration-order sweep (t, e, i, list, h); func_0200BAC8 returns a value in this unit |
| 0x02155244 | EXACT | u32 byte local, `t` declared before `v` |
| 0x02155328 | MATCH (pending) | byte-correct; blocked by a tool bug, see below |
| 0x02155478 | MATCH (pending) | byte-correct; the tail is written out in both arms in states 18 and 19, and the call is written in each arm in state 10; 11 evidence gaps |

## Tree 2: root func_0216FEAC, 2 functions

0x0216FE2C EXACT* (mask held in an int local), 0x0216FEAC EXACT* (enum-typed counter declared first; the extent runs into rodata).

Shards verified twice (the second pass rewrote nothing): pkt_ov010_{02155160, 0215518C, 02155200, 02155224, 02155244, 02155A4C, 02155A6C, 0216FE2C, 0216FEAC}. `manifest --check` is clean.

## For the integrator

- Tool bug: in `overlay_data_structure()`, an extent ends at the last code address + 4. When a Thumb function ends in a 2-byte instruction, the extent swallows the first data word, so 0x0216FED8 is refused. Fixing it makes 0x02155328 EXACT.
- `OVERLAY_ID_CONSUMERS` lacks 0x020124AC (r1, forwards to func_02034AC4).
- The overlay_id walk limit of 8 steps is too short for ov100_id, ov119_id and ov195_id in 0x02155478.
- The `literal` class ignores overlay pool words (for example 0x021F03C4 at ov010 0x0216C970).
- Seed 0x02013128 (arm9, unlabelled Thumb thunk).
- Unlabelled leaf setters follow 0x02155A6C (0x02155A8C..).

## Next lane

func_02157E9C (1148 B), func_0216F40C (944 B, caller of 0x0216FEAC).
