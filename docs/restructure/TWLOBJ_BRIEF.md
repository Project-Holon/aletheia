# twl restructure: one file per original object

Goal from the user: src/game must hold one .c per original source file, read
like the developers' source, and build the ROM. For twl we now know the
original files exactly: 323 of 341 twl functions are byte-identical
(relocations masked) to functions in the TWL SDK and TWL wireless libraries.
docs/restructure/twl_vendor.tsv gives, per function, the vendor archive,
object, symbol name and DWARF source file; docs/restructure/twl_objects.tsv
gives, per object, its address range and the src/game/twl files that cover it
today. Some objects are spread over many of our files (camera_api.o over 13),
and some of our files mix objects. Your lane rebuilds its objects as one file
each. Read docs/restructure/FINISH_BRIEF.md (rules, levers) first.

## Per object
1. Take the object's address range from twl_objects.tsv. Collect every
   function in that range from the src/game/twl files listed (and any function
   with no file, marked `-`: its C is in src/matched/twl or twl_sdk).
2. Write one file `src/game/twl/<stem>.c`, where `<stem>` is the DWARF source
   file name (`dwarf_source` column, e.g. `camera_api.c`); when the object name
   is truncated by the archive format (`nwm_setpowersave`), use the DWARF name.
   Functions in address order, one set of types per object (merge the copies
   the parts carry; keep a duplicate only where the bytes need it, with a
   comment), prototypes that follow the definitions.
3. Header: the usual fields (file, unit: yes, function list, address = the
   object's first function, region twl, compiler from the `comment` column:
   Metrowerks 4.0.0.1024 is dsi/1.1p1, flags, lang, isa) plus a line
   `sdk:      <archive> <object>`. Run `python tools/gamesyms.py --file F --apply`.
4. Keep function names as they are (`func_XXXXXXXX`). The integrator applies
   the vendor names tree-wide afterwards with one script, so callers in other
   files stay consistent. Do not rename.
5. Verify: `python tools/gameverify.py --file F` EXACT. Then delete the old
   files whose functions are now all in object files (only files of your
   objects; a file that also holds another lane's object stays until both are
   done: report it).
6. If a file range has functions that are in no object (the `NO_MATCH` rows),
   keep them where they are and report them.

## Rules
Only touch the files of your objects. Do not run match.py manifest. No
permuter, sweeps or brute force. Never open SDK source (the tables already
hold what you need). No git stash/checkout/reset/mv; nothing staged or
committed. No em dashes or emoji. Keep context under 150k.

## Report
Per object: new file, functions (count), old files removed, anything that did
not verify, functions left outside any object. List the old file names so the
integrator can update docs/restructure/split_tus.tsv and the manifest paths.
