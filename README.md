# aletheia

A from-scratch decompilation project for Pokémon Black (NDS, USA/EUR "NDSi Enhanced", gamecode IRBO).

This project shares no code with any existing decompilation effort. All tooling
(ROM extraction/rebuilding, disassembly, build system) is written independently
for this repository.

## Goal

Fully decompile Pokémon Black to readable, buildable C source that produces a
byte-matching ROM.

## Status

- [x] Milestone 1: extract ROM and rebuild a byte-matching, launchable `.nds`
      with our own toolchain (`tools/ndsrom.py`)
- [x] Milestone 2: delink & disassemble the ARM9 binary + overlays with our
      own tools, reassemble byte-identically (`tools/build.py`: 242 of 242
      regions PASS) and split the ARM9 into ordered translation units
- [ ] Milestone 3: incrementally decompile to C, keeping the build matching

See [docs/ROADMAP.md](docs/ROADMAP.md) for the planned approach, and
[docs/NOTES.md](docs/NOTES.md) for technical findings recorded along the way.

## Requirements

- Python 3.11+
- Your own legally dumped ROM of Pokémon Black (USA, Europe) (NDSi Enhanced)
  - SHA1: `26ad0b9967aa279c4a266ee69f52b9b2332399a5`
  - Size: 268435456 bytes
  - Place it in the repo root (any `*.nds` filename works; commands below
    take the path as an argument)

## Usage

```
python tools/ndsrom.py extract "<your-rom>.nds" -o extract
python tools/ndsrom.py build extract -o build/pokeblack.nds
python tools/ndsrom.py verify extract build/pokeblack.nds
```

The rebuilt ROM runs in melonDS, DeSmuME, or on real hardware via flashcart.

To delink, disassemble and prove the disassembly reassembles byte-identically:

```
pip install capstone
python tools/delink.py
python tools/disasm.py arm9 --split
python tools/disasm.py overlay --all
python tools/build.py --arm9-image          # all 242 regions
python tools/build.py --split --only arm9   # ARM9 from its translation units
```

`tools/build.py` needs GNU binutils for `arm-none-eabi`. Unpack the xPack
`arm-none-eabi-gcc` Windows x64 zip into `tools/gcc-arm/` (no install needed)
or point `--toolchain` / `BW_ARM_TOOLCHAIN` at any `bin/` directory that has
`arm-none-eabi-as`. See [docs/NOTES.md](docs/NOTES.md) for details.

## Acknowledgments

Development of this project is assisted by Anthropic's Claude (via Claude
Code); tooling and documentation are produced with its help under human
direction and review.

## Legal

This repository contains no game assets, code, or ROMs, only original
tooling and, eventually, reimplemented source code. You must dump your own
cartridge to use any of this.

## Repository layout notes

`extract/` and `build/` are gitignored on purpose (they are generated from
your own ROM dump) and must never be committed.
