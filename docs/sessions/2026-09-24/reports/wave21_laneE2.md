# Wave 21, lane E2: wipe_sub 0x0202350C

All verdicts below come from `tools/match.py` (dsi/1.1p1, -O4,p, Thumb). About 180 hand compiles, plus
two permuter runs.

## Result

| function | before | after | where |
|---|---|---|---|
| 0x0202350C wipe_sub (90 B) | DIFF 2 | **EXACT*** | `src/matched/func_0202350C.c`, shard `pkt_0202350C` verified twice (1 then 0 rewritten) |

`EXACT*` means every byte matches and both relocations resolve. The star comes from the 2-byte pad in the
92-byte listing extent.

## What the residue was

For the three leading instructions (`ldrb k8`, `movs #0`, `ldrb kb`), the post-allocation scheduler keeps IR
order whenever the registers are right. Reads in the order k8, kb, z come out k8, kb, z (4 out), and reads
kb, z, k8 come out kb, z, k8 (2 out). To get the image's order k8, z, kb, the source has to read in that
order. With reads k8, z, kb, though, the allocator gives r0 to whichever of {z, kb} is defined later, which
here is kb. The r0 anti-dependence on the a5 load then lifts kb above k8, giving 12 out.

None of these levers changed that allocation:

- declaration order (6 orders);
- self-assignments at every position (27);
- dead initialisations;
- nested blocks (6 shapes);
- the type of kb or k8 (8);
- volatile stores or reloads;
- read and store interleavings (about 60).

## The lever

Put a5's load (r0, the call's first argument) inside kb's live range, so that kb cannot take r0. Moving the
`f48` store up does this: the load window becomes exact, and only the store is out of place (6 out). A plain
copy of a5 gets propagated back to the store and changes nothing. A volatile read works:
`v5 = *(volatile u32 *)&a5;` placed between the f40 and f44 stores, with `f48 = v5` and `v5` passed as the
call's first argument. That gives EXACT*.

## Other measurements

- Front-end probe, one compile each on the lane E source: `../1.2/sp2` gave 96 bytes (68 out) and
  `../2.0/sp2` gave 92 bytes (55 out). No pin is warranted.
- The permuter, with the fixed 90/90 ranking, did not find the lever. Anneal 2500 `--types` from the 2-out
  source reached 2 at best. Anneal `--types` from the k8,kb,z 4-out source was stopped at 1135 compiles,
  also at 2.

## External sources

No other decompilation or reconstruction was consulted (none before or after the owner's rule change).

## Files touched

- `src/matched/func_0202350C.c` (new, EXACT*)
- `layout/matched/arm9/pkt_0202350C.json` (written only by `manifest --verify --shard pkt_0202350C`)
- `docs/notes/func_0202350C.c.txt` (dated lane E2 section appended, with every spelling and its bytes-out)
- `docs/sessions/2026-09-24/reports/wave21_laneE2.md` (this file)

A possible idiom for the integrator, not written: a volatile read of a stack parameter pins its load inside
another value's live range when a plain copy would be propagated back to the use.
