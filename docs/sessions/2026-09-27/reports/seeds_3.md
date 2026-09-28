# seeds_3 report (2026-09-28)

## Seeds (layout/function_starts.txt, witness in each comment)

arm9: 0201BC3C, 0201BC40, 0201BC78, 0201BCB4, 0201BCEC, 02009020, 02012F14, 02012F38*, 02012F44*, 02012F50*, 02012F5C, 02025C74, 02025C88*, 02025C9C, 02025CB0, 0202DC98, 0202DC9C, 0202DCB0, 02008A44*, 02008A54, 02047804 (ARM), 02047828 (ARM); ov111 021C7EF8*. (* already EXACT, now labelled.)

## Matched (EXACT, shards verified twice)

unit_0201BC3C (5, DISPCNT OBJ-mapping switches), func_02009020, func_02012F14, func_02012F5C, func_02025C74, unit_02025C9C (2), unit_0202DC98 (3), unit_02047804 (2, ARM).

## Promoted

ov111: 40DC, 61EC, 4B9C, 60CC, 7130, 5718, 7830, 7B20 (EXACT). ov208 021C52F0 (EXACT*). ov119 021E049C, 021E0200 (EXACT).

## Integrator

- Worklist: open=1, pkt_02008A54. It is still a near miss (17 bytes, register allocation only). 432 shapes plus a permuter run (seed 9551) did not move it. See docs/notes/pkt_02008A54.c.txt. Labelling it makes those 40 bytes count as open.
- ov111 7B20's call to 0x02008A54 attests only through sole-ref.
- The game-code denominator moved from 401422 to 401542 between my two refreshes.
