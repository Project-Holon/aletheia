# Wave 17 lane 17J: evidence for three byte-correct MATCH files

No rule was added. match.py, its selftest (167) and all three files are unchanged; nothing moved to src/matched.

## func_0206DC00 (0x027300F0, 0x0272FEF4)

Both targets are in the TWL autoload block of arm9i. The TWL build info at arm9+0xF7C gives infos 0x02432DA4..0x02432DB4. Once arm9i.bin is BLZ-decompressed (0x12F24 bytes become 0x32DB4), its single entry reads ram 0x02700000, size 0x32DA0, bss 0x2DA0, payload at 0x02400004. So 0x027300F0 is at payload offset 0x300F0 and 0x0272FEF4 at 0x2FEF4. The project extracts arm9i.bin but does not decompress, delink or list it, so no label exists. Closing this needs three things: (1) delink.py decompresses arm9i and splits the TWL autoload as a region (for example `twl`, base 0x02700000), (2) disasm.py lists it and traces function starts, (3) match.py label lookup gets a token for that region, with a selftest. Stopped here; no exclusion added.

## func_02010AC4 and func_02010C34 (0x021D6338, 0x021D654C)

The premise does not hold. Neither function loads ov021: both load ov115 (id 0x73), and AC4 also loads ov123 (0x7B), C34 ov187 (0xBB). The procs are passed together with id 0x73. Both addresses are inside ov115 (0x021D4240..0x021D6640). In ov115 each is a three-function-pointer proc table (0x021D6338 -> func_021D4BFC/4CE4/4D10; 0x021D654C -> func_021D603C/6104/...). But ov115's listing has no object start there (they sit inside pool_021D6324 and the following pool), so even an ov115 coupling fails condition (b). Stopped as instructed.

Hazard: `attest_sole_ref_overlay_data(0x021D6338, region_hint='ov021')` returns an attestation today. Any symbol-line hint naming ov021 would accept the wrong overlay. Whoever edits these headers must not hint ov021. Real basis would be either ov115 data starts for the proc tables (a data-start seed in ov115's listing) or both functions' literal pools seeded as .word, which the file headers already propose. Both are outside this lane's permitted files.
