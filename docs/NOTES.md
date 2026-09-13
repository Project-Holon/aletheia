# Technical notes

Findings recorded during ROM analysis, for contributors picking up later
milestones.

## General

- The game is built on SDK5 / TWL (DSi-enhanced), not an older NitroSDK
  version.
- Secure area in No-Intro dumps of this title is already decrypted (the
  `E7FFDEFF` marker is present at ROM offset 0x4000). No ARM7 BIOS is needed
  to work with this dump.

## ARM9 binary

- ROM offset: 0x4000
- Size (as stored/compressed on ROM): 0x6F898
- Load address: 0x2004000
- Entry point: 0x2004800
- Compressed with BLZ.
- Build info structure lives at `arm9 + 0xFB0`.

## Build info (from ROM)

- `autoload_infos`: 0x20AA780..0x20AA7C0 (4 entries, 16 bytes each). SDK5
  uses 16-byte autoload entries; earlier (pre-SDK5) NitroSDK builds use a
  12-byte layout, so tooling that assumes the old size will misparse this.
- Autoload blocks start at: 0x20A9E80
- `.bss` range: 0x20A9E80..0x21542C0
- Compressed code end: 0x2073898
- `sdk_version` field: 0x503757C

## Nitrocode footer

There is no nitrocode footer after the ARM9 binary in this ROM; the bytes
where one would normally sit are 0xFF padding. Instead, the build-info offset
is read from the ROM header at offset 0x88 (value: 0xFB0, ARM9-relative).

This is why third-party tools that assume a footer is always present (e.g.
current versions of ds-rom, dsd) fail to parse this ROM's build info
correctly, and why this project uses its own tooling instead.
