# Wave 18 lane 18A: TWL region `twl` (plumbing in, key step blocked)

## Added

- `tools/modcrypt.py`: DSi modcrypt (AES-128-CTR over area 1, retail and debug key schedules, stdlib AES with a FIPS-197 self-test). The scrambler constant is read at run time from `--dsi-key` / `ALETHEIA_DSI_KEY` (16-byte file) or `--dsi-bios` / `ALETHEIA_DSI_BIOS` (scanned dump), checked against its SHA-1. Without a source the region is skipped.
- `delink.py`: region `twl` declared in layout.json (0x02700000, code 0x32DA0, bss 0x2DA0 excluded; key-free, the table is in the clear tail). With a key it writes `extract/arm9i_dec.bin` only if the decrypted BLZ stream is consumed exactly (all 229 overlays are; ciphertext leaves 8172 bytes).
- `disasm.py twl` (swept into commit bdbbb9f by another lane), `build.py` region `twl` (`--only twl`; outside `--only arm9`, `--arm9-image`, `--pack`), `match.py` `twl` symbols token plus 7 selftests (183 of 183 pass).
- `.gitignore`: `*.key`, BIOS-like names.

## Verification

The supplied `NDS_Bios9i.bin` does not contain the constant (full scan, both byte orders, all rotations): it lives in the AES hardware, not the BIOS. Decryption is therefore unverified on real data. Plumbing ran end to end on the undecrypted payload (listing, reassembly PASS after quirk rounds, in a scratch layout; trial files deleted).

Region count: 242 without a key (unchanged); 243 with one.

## func_0206DC00

Symbols lines now carry `twl`; still MATCH. The only branches in the image to 0x027300F0 / 0x0272FEF4 are its own two `bl`, so even with a key it needs a branch from the decrypted TWL code.

## Figures

No effect: denominator 400306 unchanged, foldin passes (sha1 26ad0b99...).

No key material is in the repo, in any commit, or in this report.
