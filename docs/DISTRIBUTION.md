# Distribution and data layout (design draft)

Status: design, 2026-09-16. Nothing here is implemented yet except the asset
converters it relies on. Decisions marked OPEN are for the owner to settle.

## Principles

1. The executable never contains game data. The user supplies their own ROM
   once; everything else is derived from it on their machine.
2. The data the engine reads is unpacked and human-readable on disk: PNG,
   WAV, plain text, JSON tables, OBJ/MTL. Modding is editing files in a
   folder, not patching archives.
3. One code path on every platform: the engine locates a data root, checks
   its manifest, and if the root is missing or stale runs the extraction
   flow. Installers and bundles only decide where that root lives.
4. Every converter that writes a readable form has a byte-identical
   re-encoder (this is already true for all 247 files), so an edited file can
   be turned back into what the engine needs when a binary form is required.

## First run

    pick ROM file  ->  verify SHA-1 (26ad0b99 ... for Black; White later)
                   ->  extract NitroFS (tools/assets/narc.py logic in C)
                   ->  convert every archive to its readable form
                   ->  write data/manifest.json (game, version, hash, tool version)
                   ->  start

Extraction runs in-process with a progress screen; on a laptop the Python
tools take minutes, the C port should take well under one. The ROM itself is
not kept; only the hash is recorded.

## Data root per platform

| platform | data root                                             | app form                  |
|----------|-------------------------------------------------------|---------------------------|
| Windows  | `%LOCALAPPDATA%\<name>\data` (or `data\` beside exe)  | exe + installer           |
| macOS    | `~/Library/Application Support/<name>/data`           | signed `.app` bundle      |
| Linux    | `$XDG_DATA_HOME/<name>/data`                          | AppImage, tarball         |
| iOS      | app Documents directory (file picker for the ROM)     | app                       |
| Android  | app-specific external files dir (SAF picker for ROM)  | app                       |

A `--data-root PATH` flag and an environment variable override the default
everywhere (portable installs, modders keeping several roots).

OPEN: on Windows, default to the per-user folder (survives reinstall, no admin
rights) or beside the exe (what most modders expect)? Suggestion: per-user by
default, "portable mode" if a `data\` folder already exists beside the exe.

## Windows installer

NSIS or Inno Setup. It installs the exe, the uninstaller and a shortcut, and
optionally runs the same first-run flow during setup so the game opens ready.
The uninstaller asks whether to remove the data root (default: keep, since it
holds the user's mods). Nothing in the installer is game data; it is the same
extraction code the exe runs.

## Folder layout of the data root

    data/
      manifest.json           game id, ROM hash, tool version, file list with hashes
      text/                   message banks as UTF-8 text, one file per bank
      tables/                 personal, moves, items, learnsets, evolutions,
                              egg moves, cries, zones, encounters, events as JSON
      scripts/                field scripts as text disassembly (assembler later)
      effects/                battle effect VM scripts, same form
      maps/
        matrices/             JSON grids of map ids
        models/               OBJ + MTL + PNG textures per map chunk
        terrain/              per-chunk terrain records as JSON (surface, height, attribute)
      sprites/
        pokemon/              per species: PNG sheets + JSON rig (cells, nodes, frames)
        trainers/             per class: PNG + JSON
        overworld/            PNG sheets + JSON walk cycles
        icons/                PNG
        effects/              PNG frames + JSON timing
      backgrounds/            PNG per screen plus the tile and palette sources
      fonts/                  PNG contact sheets + JSON metrics + the raw glyph tables
      audio/
        sequences/            SSEQ as MIDI-like JSON (the softsynth format) or MIDI
        banks/                instrument tables as JSON
        waves/                WAV
      cinematic/              PNG frames
      raw/                    the original sub-files, kept for formats the engine
                              still consumes in binary form (NSBMD until the
                              model loader is native, SDAT until the sequencer
                              is native); shrinks as the port matures

    mods/
      <modname>/              same layout as data/; files here shadow data/
      order.txt               load order

## Runtime loading

The engine resolves a logical asset name ("sprites/pokemon/0006") through the
mod overlay then the data root. Readable forms are parsed at load; where a
binary form is cheaper at runtime (tile data, palettes, sequences), a
`cache/` directory holds re-encoded blobs keyed by the source file hash, so
editing a PNG invalidates only its own cache entry. The cache is disposable.

## Mods

- A mod is a folder; distribution is a zip of that folder.
- Shadowing is per file. JSON tables are shadowed whole for now (OPEN:
  per-record merge for tables like personal data, so two mods can each edit
  different species).
- Scripts: the disassembly form is round-trippable once the assembler exists
  (the operand table for all 609 opcodes is already in tools/assets/scripts.py).
- No code mods in the first version; the port's own build is the way to change
  code.

## Pokémon White

Same executable, second manifest. The ROM hash selects the game id; every
tool is parameterised by the extracted layout, so the data root layout is
identical and mods can declare which game they target.

## What this fixes now for the port lane

- The extraction step is C code in the port, sharing the format knowledge in
  tools/assets/ (the Python stays the reference and the test oracle).
- The engine's file layer takes logical names and a root; no NARC access at
  runtime except through `raw/`.
- Table loaders read JSON; the port tests compare the JSON loaders' results
  against the Python decoders' output for the same ROM.
