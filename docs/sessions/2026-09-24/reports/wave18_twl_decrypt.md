# Wave 18 lane 18H: TWL region decrypted and verified

## Byte order

The user's key file passed `tools/modcrypt.py`'s SHA-1 check as stored
(little endian, reversed from the printed big-number form). No in-memory
reversal was needed.

## Region

- `delink.py --dsi-key`: decrypted, BLZ stream consumed to its last byte,
  0x32DB4 bytes to `extract/arm9i_dec.bin` (gitignored).
- `disasm.py twl`: 305 functions, 18.1 percent classified code; the formerly
  corrupt front below 0x02707090 holds 168 of them and reads as ordinary ARM.
- `build.py --only twl`: PASS on the first `--write-quirks` round, no new
  quirks. Full build: 243 of 243 PASS.
- Worklist denominator unchanged at 400306; the region stays outside it.

## func_0206DC00: stays MATCH

0x027300F0 and 0x0272FEF4 are traced ARM function starts in `asm/twl/twl.s`
(rules 1 and 2 of the `twl` label rule hold). A raw scan of the decrypted twl
image, the ARM9 image and all 237 overlays found no bl, b, blx or pool word
targeting either address except the function's own two `bl` (0x0206DCA4,
0x0206DD40), which are inside the compared range. Rule 3 has no witness in
this ROM, so 12 of 14 relocations resolve, as before.

## Checks

`match.py selftest` 183 of 183; `build.py --split --only arm9` PASS; foldin
sha1 26ad0b99... holds.

## Figures

No effect (+0 bytes).

No key material is in the repo, in any commit, or in this report.
