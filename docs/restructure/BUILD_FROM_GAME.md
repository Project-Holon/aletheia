# Building from src/game

`python tools/build.py --game --only <regions>` takes the code of a region from the
src/game translation units instead of the per-function files of src/matched.
The work is done by `tools/gamebuild.py`; `build.py` only attaches the result to
the region and keeps its usual compare step.

## What --game does

For every top-level `.c` file of `src/game/<dir>/` (folders hold member copies,
`unplaced` holds stand-ins; both are ignored) whose header address lies in a
region being built:

1. compile the file once with the compiler, flags, lang and isa of its header
   (`match.run_tu`);
2. lay out its code sections end to end (`match.layout_tu`) and resolve every
   relocation at the file address (the same resolver `run_tu` uses);
3. accept it only if the result is EXACT: every byte resolved by the resolver
   and equal. A MATCH file keeps wildcarded relocation fields the resolver could
   not attest. Those bytes could only come from the image, so the file is
   refused and its range stays assembled from asm/. Refusals are printed and
   counted; `--game-strict` turns them into a failure. Any other verdict
   (DIFF, SIZE, compiler error) always fails the build;
4. overwrite that range of the region image that was assembled from asm/.

`--game-skip STEM...` leaves files with that name stem to asm/ (for files an
editing lane has open). Default `build.py` behaviour is unchanged.

Still read from the image in this mode: linker veneers between two code sections
of one file (`match.linker_gap`). The run prints the count
("veneers from image"). Everything outside the spliced ranges (all of .data,
.rodata, .bss, and code no src/game file covers) comes from the asm/ listings.

## Results (2026-10-11)

| group | regions | result |
| --- | --- | --- |
| 3 small whole overlays | ov011, ov012, ov014 | PASS, 16 files |
| 157 overlays with no split and no open edit | every overlay not in split_tus.tsv and not in a wave-17 lane list | 157 PASS, 0 FAIL; 406 of 409 files spliced, 0 veneers |
| ITCM | itcm | PASS, 3 files |
| ARM9 static | arm9_main with 11 open TU stems skipped | PASS, 392 files, 0x73E46 bytes, 6 veneers (48 bytes) from the image |

The 3 refused files are MATCH (unresolved relocation sites), so they stayed asm:
`ov114/nhttp_rap.c` (2 sites), `ov132/script_command.c` (5), `ov214/btl_rec_sel_graphic.c` (1).
Overlays with split TUs (`_pNN.c` parts) were not tried as a group because other lanes were
editing them; ARM9 parts are compiled one by one at their own addresses, as
`gameverify.py` does, and passed.

The first failure seen was not a build failure: while a lane merged
`pokeparty_p03..p05` the run found a file gone and two `unit_020911D4` parts DIFF
(files being rewritten). The lane lists give the skip stems used above.

## Next steps to drop the image as an input

### 1. Data into C

Today `.data/.rodata/.bss` come from asm/. Tools that exist:

- `tools/datamap.py` builds the object map `layout/data_objects.txt` (where an object
  begins), from literal-pool references.
- `tools/datagen.py gen|check` writes typed C for the objects of
  `layout/data_objects.json` from the user's image into `build/data/` (not committed)
  and `check` compares every object with the image. Run it per region to see the
  share that already round-trips.
- `tools/datascan.py` finds code that disasm filed as data; run it first so no
  function hides inside a data block.

Steps: make `datagen check` pass for a region, compile the generated data with the
code TU of the same region so the data layout is part of the same link, and let the
resolver treat these objects as defined in the unit rather than as image evidence.
This is also what removes the MATCH refusals: a relocation to a data object that is
defined in the build needs no witness.

### 2. A real link with mwldarm

`python tools/gamelink.py <overlay ids>` links whole overlays with
`tools/mwccarm/mwccarm/dsi/1.1p1/mwldarm.exe` and compares the result with the
original overlay. Output goes to `build/gamelink/ovNNN/` (not committed).

Measured on ov012 (first attempt, one link per file, callees as absolute symbols in
the `.lcf`): 91 to 271 bytes per file differed. Every difference was a BL where the
original has BLX (plus the offset that follows from it). Causes and fixes, each
measured on ov012:

| try | result |
| --- | --- |
| absolute `.lcf` symbol, thumb bit set | BL instead of BLX |
| `.thumb_set` typed symbol in a GNU as object | no change |
| absolute symbols plus `-interworking` | no change (colosseum: 91 bytes differ) |
| typed stub objects, no `-interworking` | no change (80 bytes differ) |
| typed stub objects plus `-interworking` | 0 bytes differ in all 3 files |

So the linker takes the ARM/Thumb type from the object, not from the address: a
symbol needs its own input section and a `$a` or `$t` mapping symbol (what mwccarm
writes), and `-interworking` makes it emit BLX. A symbol value must be the plain offset
(0), not offset|1, or Thumb targets come out 2 bytes late.

What gamelink.py does for one overlay:

1. compiles every file of `src/game/ovNNN/` with the flags of its header;
2. writes a stub object (`stubs.o`) with one tiny typed function section per callee
   outside the overlay, placed by the `.lcf` at the callee's address (the callee's
   code is not needed, only its address and ISA). The ISA comes from the `symbols:`
   blocks, else from `match.isa_evidence`, else the name (`func_XXXXXXXX`);
3. second names for functions a file defines (`DWCi_...` next to `func_...`) are added
   as extra symbols of that file's object, so they stay typed (an `.lcf` alias loses
   the Thumb bit for data references);
4. data symbols stay absolute `.lcf` assignments;
5. links in two passes: pass 1 measures the true size of each file's code (the linker
   aligns each function, so it is larger than the sum of the sections), pass 2 adds the
   gaps;
6. the gaps between files (all data, literal pools of uncovered code, code no file
   covers) are binary sections copied from the extracted overlay image, with typed
   symbols for callees that lie inside a gap. THIS IS STILL THE IMAGE AS AN INPUT:
   the check proves only that the bytes the src/game files produce, placed at their
   addresses and linked, equal the original. The gap bytes are equal by construction;
7. needs `-nodeadstrip` (otherwise the linker drops a gap that nothing references,
   unless it holds a symbol) and a marker symbol in every gap.

Results (2026-10-12), overlays with no `_pNN` split files, 166 overlays: **166 PASS**
(whole overlay byte-identical to the original), plus ITCM (3 files) PASS. The ten
failures of the first run had these causes, all fixed in `gamelink.py`:

| overlays | cause | fix |
| --- | --- | --- |
| ov204, ov214, ov215, ov217, ov225 | the same local name (`site`, `config`, `queue`, ...) means a different address in different files; the first header won for the whole overlay | each distinct (name, address) gets its own symbol, renamed in the object of the files that use it |
| ov214 (one word left) | `btl_rec_sel_graphic.c` used `config` for two different objects (0x021BB588 and 0x021BB53C). The old build hid this with a wildcarded relocation | source fixed: new symbol `config2`; the file is now EXACT in `build.py --game` instead of refused |
| ov095 | mwldarm shares one veneer between calls to the same far function; the original link made one veneer per call site (also across files) | every call site after the first of a function outside the overlay gets its own symbol (`name__vN`, same stub address), so the linker makes one veneer each |
| ov015, ov114, ov119, ov172 | files with their own `.data`, `.rodata`, `.bss` | see below |

Data sections of a file (`.data`, `.rodata`, `.bss`) are given a section name of their
own in the object and a memory region at the original address, and the image gap is
cut around them. The address comes from the file header: a symbol with a known address
minus its offset in the section (the most common answer wins; a struct member name can
disagree), else, for a string, the place where the same bytes occur in the image and
the file's own literal pool points to. Two files that both define the same statics
(ov015 `irc.o` statics) place one copy; the second file's references are rewritten to
point at the first. Other fixes needed on the way: a name defined in two files (ov114
`DWCi_Ndi_memcpy`, two different functions), header lines with `@` names (the shared
parser stops at the first), names such as `g_021C88AC` that carry their address.

Findings that the old build could not see:

- ov119 `pokemontrade_3d.c`: `d_021E8190` (48 bytes) is declared as an uninitialised
  static but the original holds a table there. The code is right; the 48 bytes are
  taken from the image (reported as `bss_standin_bytes`). Fixing it needs the table
  as game data, which is not committed.

### Other regions

`python tools/gamelink.py itcm` PASS. `python tools/gamelink.py arm9_main --skip=unit_020911D4`
links 408 files (575564 bytes of code, 103902 bytes between them from the image) and
all of them are byte-identical except one:

- `unit_0205D91C`: `s_nspot` lies at +8 of a 0x14-byte `.bss` in our object, in the
  original at +0. Seven literal-pool words differ by 8. The old build accepted the file
  because it resolves such words from the header address, not from the object layout.
  Some static declared before `s_nspot` (8 bytes) belongs somewhere else.

Extra rules `arm9_main` needed (also used by the overlays, 166 still PASS):

- a file at a halfword address (`unit_0200421A`, `unit_02004632`, `swi` thunks): the
  section alignment is lowered to 2 so the linker does not move it;
- names missing from every header (`MIC_AdjustLimitedSampling`, the `sub_..._Ptr`
  pointers): the address is read from the original code at the place the file uses it
  (pool word or branch target; a branch to a linker veneer is followed to the veneer's
  target). This uses the image;
- a first link with placeholder addresses, then a second with the inferred ones, so the
  veneers the original has are counted in the file sizes;
- the same name with two different SDK addresses (`ENV_SetResourceSet`,
  `GXS_LoadBG0Char`): a header that gives a defined name another address than the
  linked one makes a second name for that reference.

`unit_020911D4` (parts p01..p08) is skipped because another lane is rewriting it; its
range comes from the image. Without the skip the link fails in the first pass: part p03
needs 0x188 bytes more than the room the original gave it.

Remaining gap to a link with no image input: the gap data (typed C from
`datagen.py` compiled and linked as real objects instead of binary sections), the
stub objects (real callees: the arm9 static module and other overlays linked as
objects with their true code), the addresses of missing names, the 48 bytes above,
and the overlay table and `.lcf` for the whole ROM instead of one region at a time.

### 3. Prebuilt pieces

Kept as binaries taken from the user's own dump (never committed): the ARM7 binary
and its overlays, the SDK and library objects that are not restructured (the ARM9
ranges without a src/game file), the autoload info table and the DTCM/TWL blocks
that have no TU yet. They are listed from `layout/layout.json` and bound into the
final image by `ndsrom.py build --override`, as `build.py --pack` already does.
