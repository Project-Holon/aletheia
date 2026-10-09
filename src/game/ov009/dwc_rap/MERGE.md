# dwc_rap (ov009): 30 parts left (was 26 parts + 24 folder members)

All parts verify EXACT. Remaining boundaries between parts (greedy pass, both function orders):
- Global at 0x021A8264 (aliases d_021A8264 and g_021A8264) is viewed through about 40 different
  local structs (`G`, `G_0215568C`, `G_02156888`, `_anon_Work`, `Obj18651`), `u8 *`, `char *`,
  `int`, `int *`. Merging fails with "not a member of class" or "redeclared". Needs one struct
  with all field offsets (union of the views; check offsets agree), then casts removed.
- Global at 0x021A8268 (`struct Obj`, `Obj`) is viewed in p24..p26 only; merges there already.
- c99=DIFF at ov009_func_02155244 / 02155294 / dwc_rap_p03 boundaries (0x02155244..0x02155338):
  merging changes the code; left as separate parts.

Round 3 (r3_ov01) notes: code not covered by any function between parts (unmatched code or veneers):
- 0x02155234..0x02155244 (16 bytes, p01|p02), 0x0215528C..0x02155294 (8 bytes, p02|p03), 0x02155330..0x02155338 (8 bytes, p03|p04): these are the c99=DIFF boundaries above.
- 0x02155D3A..0x02155D3C and p14|p15: 2-byte Thumb alignment padding only.
