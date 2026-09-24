# Wave 19, lane 19K (mcss_small_3)

## Per address
- 0x02034D60: 5 -> 0, EXACT, filed (dsi/1.1p1, 100/100). The region base is written `u32 lo = (u32)SDK_AUTOLOAD_MAIN_TWL_START;` (extern data, 0x02FE0000, literal x17) with `id <= lo + 0x4000 && id >= lo`. Keeping the symbol as a pointer folds base + 0x4000 into a second pool word (10 out). The integer cast keeps the add and the image's colouring. unsigned long is also exact. 6 measurements.
- 0x0204A7A0: 1 -> 0, EXACT, filed. Measured first: long i and long slot with 120-order sweeps (1/19 and 37/47), an inline scan, and a 0xFFFFFFFF compare. The missing return does not apply (r0 holds the singleton pointer at the exit). The lever: the guard inverted, `if (i != (u32)-1) { body; return i; } return -1;`. The -1 then comes back in the compare's register (sb). 10 measurements.
- 0x0204A6C8: 4 -> 0, EXACT, filed. The same inversion also fixes the `mov r8, r0` / `mov r7, #0` order, which had been flat for five waves. 2 measurements.
- 0x0209128C: 1 -> 1. Tried long flag and parameter, call-result (inline) flags, a struct field, an enum and a missing return: all 1, or 4 and 11. Final position recorded: no 1.1p1 form keeps the movne. 10 measurements.
- 0x02016C60: 29 -> 29. Long i2/j2 moves the frame (104). The 720-order sweeps give 94 and 96. The permuter (870 extent, 1500, seeds 3001/3002) gives 79. Long w2/h2/sx2/sy2 give 29, the sx2 sweep 29, an unsigned long record pointer 29. 14 measurements.
- 0x02067080: 2 -> 2 (../2.0/sp2). Long dx, dy, both, and halfH each swept (24 orders): 2 or 22. Long vector fields: 2. 6 measurements.

## Files
- src/matched/sub_02034D60.c, src/matched/func_0204A7A0.c, src/matched/sub_0204A6C8.c
- layout/matched/arm9/pkt_02034978.json, layout/matched/arm9/pkt_0204A6C8.json (new)
- docs/idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md
- docs/idioms/an-inverted-guard-returns-the-compare-constant-register.md
- notes, each with a wave-19 19K section: sub_02034D60, func_0204A7A0, sub_0204A6C8, func_0209128C, pkt_02016C60, pkt_02066E30

## Shards
- pkt_02034978: verified twice, second pass 0 rewritten, 9 EXACT.
- pkt_0204A6C8: verified twice, second pass 0 rewritten, 2 EXACT.

## Seeds
3001, 3002 (permuter). No unlabelled starts noticed.

## Integrator
- f134252 already committed sub_02034D60, its idiom and four of the notes. Still to stage: the two 0x0204A6C8-packet files, pkt_0204A6C8.json, the inverted-guard idiom and the two clact notes.
- Regenerate the idiom index.
- Try the inverted guard on other scan-then-claim near misses. It fixed a scheduling tie here as well as the return.
