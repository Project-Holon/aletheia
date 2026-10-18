# src/game: the game rebuilt as source files

`src/matched/` holds the matching work as it was done: one function (or one small
unit) per file, each verified byte-exact on its own. It stays as the record.

`src/game/` is the same code arranged as the original program was most likely
written: one `.c` file per original source file (translation unit), with shared
types and one declaration per function and global where that could be settled.

## Layout

- `src/game/<region>/<name>.c` is a whole source file. `<region>` is `arm9`, an
  overlay (`ov000` ... `ov236`), `twl` or the ITCM block.
- `src/game/<region>/<name>_p01.c`, `_p02.c`, ... are parts of one source file
  that could not be merged into one file yet, in address order.
- `src/game/<region>/<name>/` holds member files that could not join a part, plus
  `MERGE.md`, which lists what blocks the merge (a global or function declared two
  ways, a struct viewed differently, a merge that changes the bytes).
- Names come from the game's own `__FILE__` strings where they are known
  (`config.c`, `bmp.c`, `save_control.c`); elsewhere a file is named after its
  first function (`unit_02077634.c`) until it gets a real name.

## How it is checked

- Every merged file compiles to the original bytes as one translation unit:
  `python tools/gameverify.py` (match.py `tu` with the file's header settings).
- Every verified function is defined exactly once in the tree:
  `python tools/gamecheck.py`.
- File boundaries come from evidence (`tools/tuboundary.py`): `__FILE__` names,
  shared strings and data, compiler settings, linker veneers. A change of
  compiler or flags, or a linker veneer, always ends a file.

## Tools

- `tools/restructure.py` builds the tree from `src/matched/` (merges members,
  splits on failure, writes folders with `MERGE.md`).
- `tools/gamefix.py` removes duplicate copies and puts back missing functions.
- `tools/gameincludes.py` points every include at the real header.
- `tools/restorenotes.py` puts the descriptive notes of the matched files back
  above each function.

Every function has a real name; no address names (`func_XXXXXXXX`) remain.
The naming rules and their evidence are in `docs/NAMING.md`.
