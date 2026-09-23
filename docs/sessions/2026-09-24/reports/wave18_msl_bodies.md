# Wave 18, lane 18B (msl_bodies)

Nothing reached EXACT or MATCH. Nothing was filed or committed, and no shards were verified.

## 0x0209953C: fdlibm __kernel_rem_pio2 (old revision)

This is fdlibm __kernel_rem_pio2 from the old revision. Its prec 1/2 arm has `fw = fq[0]-fw;`, where the later text has `fq[0]-y[0]`.

- Evidence: the caller is __ieee754_rem_pio2. The frame is 0x264. The pool holds init_jk and PIo2, plus 0x2AAAAAAB for the /24 in `jv = (e0-3)/24`.
- Callees: scalbn at 0x02097990 and floor at 0x0209A524.
- Result: none -> 12 bytes short. The best source under dsi/1.2 compiles to 2980 of 2992 bytes, and all 62 relocations resolve. Every instruction matches except three missing duplicate loop guards:
  - +0x84 `cmp r8,#0 / blt`
  - +0x194 `cmpgt r0,#0`
- Measurements: 20 plus one permuter run (800 compiles). The note lists every front end tried. None of them produces the guards.

## 0x02094B8C: MSL __strtold (C99 revision)

This is the whole MSL __strtold from the C99 revision: the INF, NAN(n) and hex-float states plus both conversions. It is not just __scan_float.

- The old MATCH cap is lifted. The bl at +0xC54 is __dec2num (func_0209739C.c, now EXACT) and it resolves as sole-ref.
- Result: no C before -> 3916 bytes against 3864 (1.1p1, 1.2 identical). This is the first body ever written.
  - Offsets 0x000 to 0xD08 are identical except the entry zero chain.
  - The remaining difference is all in the hex path:
    - mantissa is cleared through a register (the C uses sp-relative stores);
    - the `mov r0,#0xe; cmp` form;
    - a frac-to-int cross-jump the C does not reproduce (+14 words);
    - three registers rotated in the hex tail.
- Measurements: 17 plus one permuter run (tools/permute.py, 993 compiles). tools/permuter.py cannot parse the file.

## Files written

- docs/notes/pkt_02098B44.c.txt (wave 18 section and best source)
- docs/notes/pkt_02094B8C.c.txt (wave 18 section, state and slot map, best source)

## Seeds

None found:
- 0x0209953C has no home-area push in front of it.
- The 0x02094B8C neighbours are already labelled.
- 0x020946D8 (__StringRead) is already in function_starts.

## For the integrator

- 0x02094B8C stays capped at MATCH even with perfect bytes, for two reasons:
  - __double_huge (0x020A881C) has no witness outside the function.
  - The two string-literal pool words compile as anonymous `@N` symbols with unstable numbering.
- Both rows are MSL library C. layout/runtime_arm9.txt already names them.
