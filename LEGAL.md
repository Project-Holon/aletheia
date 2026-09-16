# Legal notice

## What this repository is

aletheia is a reverse-engineering project: the Pokémon Black (Nintendo DS)
ARM9 program is disassembled and rewritten as C that the original compiler
turns back into the same bytes. The C under `src/` is derived from the game's
own binary by that process. It is not a clean-room reimplementation, and this
project does not claim it is.

## What is licensed, and what is not

- `tools/`, `layout/`, `docs/`, the build scripts and every other file that is
  original work of this project's contributors are licensed under the MIT
  License (see `LICENSE`).
- `src/` (the reverse-engineered game source) is distributed without any
  license grant. The contributors claim no ownership of it. Pokémon, the game's
  code, design and assets are the property of Nintendo, Creatures Inc. and GAME
  FREAK inc. Use of that source is at your own risk under the law that applies
  to you.

## What is never distributed

No game data is in this repository or accepted into it: no ROM images, no
extracted archives, no converted assets, no disassembly listings, no vendor
SDK or compiler. Building requires the user's own legally obtained ROM dump;
the tools read it and derive everything locally.

## Companion project

The native port, eidos (https://github.com/OukilIl/eidos), is original code
under the MIT License. It contains no game data and no reverse-engineered game
source; it consumes those from the user's own checkout of this repository.

## Trademarks

Pokémon and Nintendo DS are trademarks of Nintendo. This project is not
affiliated with or endorsed by Nintendo, Creatures Inc. or GAME FREAK inc.
