# tree_ov175 report (relaunched, 2026-09-28)

## Salvaged from the cut run (all re-verified, shards verified twice, 0 rewritten)

src/matched/func_{021D97C4, 021D9804*, 021D9868, 021D9BC4, 021DA384, 021DA390, 021DA4B8*, 021DA5B0, 021DAE18, 021DB218, 021DB228, 021DB238, 021DB248, 021DB3A4, 021DC1A0*, 021DC1E4, 021DC268, 021DC2D8, 021DCA28, 021DCAEC, 021DCE40, 021DCE48, 021DCE50, 021DCEE0, 021DCFDC, 021DD02C, 021DD034, 021DD038, 021DD040}.c with shards pkt_<addr> (29; * = headers corrected from EXACT to EXACT*, the real verdict). Pending MATCH*: src/pending/func_{021D9A9C, 021D9B2C, 021D9D50}.c (unlabelled arm9/ov114 thunks).

## New

ov175 root func_021D7E18 (tree 38 open incl. blx callees; 0x021D885C is the root's tail, not a function). EXACT: 021DCE60*, 021DAE54, 021DA4F8, 021DA4F0u, 021DA4E8u, 021DA0D4, 021DA1E4, 021DB6A0u, 021DB72C, 021DB478*, 021DADB4u, 021DAE00u, 021DADCC* (u = unlabelled, code-pointer or bl witness).
ov172: both named roots are libssp SDK rows (Yos_JPEGEncode, Mel_JPEGDecode), skipped. Game tree func_021BBF2C: EXACT ov172_func_{021BD134, 021BD0A4, 021BE0D0*, 021BE0D4u, 021BD038, 021BCE2C, 021BCEF8, 021BCB88, 021BC5E8}; MATCH src/pending/ov172_func_021BCC40.c.
Levers: arm order follows image (else-first), block-scoped `= {0}` struct, inline helper parameter to coalesce registers, `(char *)(p + 4) + 0x30` keeps two adds.

Near misses, notes in docs/notes/pkt_{021D9F04, 021D98E4, 021D9C34, 021DA6B8}.c.txt.

## Integrator

- Tool bug: 0x021DF490 ISA refused (ov119 label beats ov175 SDK row); blocks 021DA6B8.
- 0x021BE0D4 has no witness site; flag before counting.
- Seeds: 0x021E8844 (ov177), 0x0202E930/938 (arm9 thunks), 0x021DA044, 0x021DADAC.

## Next lane

ov175: 021D7E18, 021D965C, 021D98E4, 021D9C34, 021D9F04, 021DA6B8. ov172: 021BBF2C, 021BC7FC. Permuter seeds used 7601-7603.
