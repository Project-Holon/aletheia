# Wave 17, lane 17I (library_code)

| address | identity | before -> after | verdict |
|---|---|---|---|
| 0x020979BC | fdlibm __ieee754_pow + MSL edits | 25 -> 25 | DIFF, r6/r7/r8 3-cycle only |
| 0x0209739C | MSL ansi_fp.c __dec2num | 718 -> 718 | DIFF, pin-independent |
| 0x02094798 | MSL string.c strcpy (word-at-a-time) | 2 -> 0 | EXACT (1.1p1 and 1.2), filed |
| 0x02098B44 | fdlibm __ieee754_rem_pio2 (unit, home push) | 18 (1.2) -> 0 | EXACT under dsi/1.2, filed |
| 0x0209D7D4 | shape of MSL __write_console, release build (both callees `bx lr`) | 43 -> 43 | DIFF |
| 0x020A8FE6 | not code: record 51 of a 237 x 20-byte table (SHA-1-like digests) | n/a | layout fix needed |

What moved things:
- strcpy: MSL's own spelling of the null-byte mask, `t = w + K1; t &= ~w; t &= K2;`,
  with `if (t) goto adjust;` in `do {} while (1)`. New idiom file.
- rem_pio2: the tu is EXACT under dsi/1.2 at the current listing extent. npio2_hw and
  two_over_pi now resolve through sole-ref/data, so the old MATCH cap no longer applies.
- pow: 22 measurements (tail through the 5.3 variable set, SET_HIGH_WORD, n reuse, the
  scope and order of every local, the ternary s, front ends 1.2p1 to 1.6sp1, -O3/-O4,s).
  None moved the rotation. Two came close (30, 45) but only added swaps.
- dec2num: 718 under 1.1, 1.1p1, 1.2, 1.2p2, 1.3 and 1.6sp2.
- 0x0209D7D4: 43 under 1.2, 1.2p2 and 1.3, and with the 4-parameter MSL signature.

Files written: src/matched/func_02094798.c, src/matched/unit_02098B44.c,
docs/idioms/mask-built-by-compound-statements-picks-the-accumulator.md, appendices in the
notes pkt_020979C0, pkt_0209739C, pkt_02094798, pkt_02098B44, func_0209D7D4, pkt_020A8FE6.

Shards verified (twice, 0 rewritten on the second pass): pkt_02094798, pkt_02098B44.
The pre-existing EXACT* entry 0x0209A7A8 in that shard is still flagged "not EXACT".

Integrator:
- Add a FRONTEND-PINS row: MSL double kernels (pow 0x020979BC, rem_pio2 0x02098B44) use
  dsi/1.2. The tell is the two `str` in place of `stm`, plus the image frame.
- Layout (not done): declare 0x020A8BE0..0x020A9E64 as one data object. Both ends are
  pool-attested by 0x0207915C/0x02079158, and the loader at 0x02079098 divides by 20.
  Then the Thumb prologue sweep stops seeding func_020A8FE6.

Seeds: none.
