# Wave 21, lane E: wipe_sub 0x0202350C, bmp_oam 0x0202627C, blink_palanm 0x0202E1F0

All verdicts below come from `tools/match.py one` (dsi/1.1p1, -O4,p, Thumb). About 190 hand compiles,
plus permuter runs.

## Results

| function | before | after | where |
|---|---|---|---|
| 0x0202627C bmp_oam (268 B) | DIFF 10 | **EXACT** | `src/matched/func_0202627C.c`, shard `pkt_0202627C` verified twice |
| 0x0202350C wipe_sub (90 B) | DIFF 4 | DIFF 2 | best source in `docs/notes/func_0202350C.c.txt` |
| 0x0202E1F0 blink_palanm (412 B) | DIFF 2 | DIFF 2 | `docs/notes/pkt_0202E1F0.c.txt` |

## The new lever: an enum-typed zero

The two zero-web ties had been shelved with the finding that every spelling of the zero that yields
`movs #0` is folded before allocation. That finding is true for integer spellings only. A zero held in an
enum-typed local (`typedef enum { Z0 } E; E z; z = Z0;`) is not folded under `-enum int`: it keeps its own
web, and where it is assigned now changes the code. The effect is written up as a new idiom,
`docs/idioms/an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-folded.md`.

- **bmp_oam**: the enum z is assigned first in the finish arm, and the reads go cb, a, b. The result is
  EXACT, with 7 of 7 relocations resolved (func_02026490 by label, g_0209FB5C by sole-ref/self). Three
  orders of the flag-word form are also EXACT.
- **wipe_sub**: the reads go kb, z = Z0, k8. The result is 2 out, with every register right and the zero
  materialised between the two loads as in the image. The only residue is the two `ldrb` swapped
  (+0x20/+0x24). The compile issues cfg[0x0b] first under every source order measured, including 36
  sweeps of read order, zero position and store order, five spellings of the reload, volatile reads,
  enum or u8 locals, and alternative address forms.
- **blink_palanm**: the enum lever does not help here. Enum copies of w, enum w, and enum i/n/cnt/zero/one
  were measured, and the enum copy is still rematerialised as `add r0, sp, #0x38`. The function stays at 2.

## Permuter finding (wipe_sub)

The permuter cannot be used on wipe_sub as it ranks candidates. The listing extent is 92 bytes because it
includes a 2-byte pad, and the permuter ranks a size of 92/92 above 90/92. Every run therefore drifts to a
92-byte mutation (ret-var or volatile) and reports that as its best. Three runs showed this:

- anneal 3000 --types, stopped at 1926 compiles;
- anneal 4000 --types, stopped at about 430;
- anneal 4000 without --types, stopped at about 540.

This probably explains why earlier permuter "bests" on this function added a volatile or a return type.
The tool needs to rank against the function extent. Tools were not edited.

On blink_palanm, a permuter run of anneal 4000 --types (seed 7124) from the 2-out source stayed at 2
(see the note).

## Files touched

- `src/matched/func_0202627C.c` (new, EXACT)
- `layout/matched/arm9/pkt_0202627C.json` (written only by `manifest --verify --shard pkt_0202627C`; run
  twice, 1 then 0 rewritten, all three entries EXACT)
- `docs/idioms/an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-folded.md` (new; the
  `docs/MATCHING.md` index is stale for the integrator's `match.py idioms` run)
- `docs/notes/func_0202350C.c.txt`, `docs/notes/pkt_0202627C.c.txt`, `docs/notes/pkt_0202E1F0.c.txt`
  (dated sections appended)
- `docs/sessions/2026-09-24/reports/wave21_laneE.md` (this file)
