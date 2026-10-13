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

#### Data mode: `gamelink.py --data` (2026-10-12, lanes DG1 and DM1)

    python tools/datagen.py companions 12          # build/datac/ov012/, build/gen/datac/ov012/
    python tools/gamelink.py 12 --data --extra=build/datac/ov012

`datagen.py companions` cuts the overlay's data tail into objects (registry starts,
literal-pool targets of the code, header data names, the borders of the data sections
the code files define themselves, the static-initialiser terminator). An all-zero
piece of `.data` joins its neighbour (mwccarm would put it in `.bss`); its names become
linker aliases at an offset. `.bss` is cut the same way at code references. Each object
gets an owner file (the file whose code refers to it, else the file of a function it
points at, else its neighbour); owners must rise in link order per section, otherwise
a blocker is listed. Each owner file gets a companion `<stem>.zdata.c` with the same
header, the definitions in layout order after an anchor function (mwccarm keeps
definition order only after a function), and initialisers `#include`d from
`build/gen/datac/ovNNN/*.inc`, made from the user's own extract. Function pointers are
the plain name; the linker sets the Thumb bit. `datalink.json` gives the tail borders
and the aliases (every other name a file uses for an object). Nothing is written to
src/ or to tracked files.

`gamelink.py --data` links the `.rodata` of all files in link order, `ALIGN(4)`, the
terminator (`WRITEW 0`), `ALIGN(32)` as one segment, the `.data` as a second and the
`.bss` as a third; a companion links right after its code file and its anchor function
goes outside the overlay. Output is in `build/gamelink_data/`. The plain mode is
unchanged.

Result over the 178 overlays: **156 PASS** byte-identical with all `.rodata/.data/.bss`
from C. Failures by class:

| class | overlays |
| --- | --- |
| own-data overflow (the files' own data plus the companions exceed a segment: data a file defines that the original holds elsewhere, or counted twice) | ov009, ov015, ov016, ov107, ov114, ov119, ov120, ov172 |
| code-word (a pool word into the tail differs: an object start moved, mostly a `.data` alignment or owner order) | ov021, ov093 (also fails in plain mode), ov121, ov128, ov132, ov204, ov214, ov225 |
| overlap (a file's code range runs into the tail) | ov013, ov036, ov067 |
| other | ov185 (`.bss` in the files, the overlay has none), ov215 (callee inside the overlay, not in a file or gap), ov230 (real static initialisers, not a lone terminator) |

Plain mode in the same run: 177 of 178 overlays, itcm and arm9_main PASS (ov093:
`btl_server` is being merged by another lane).

Three more `gamelink.py` fixes from lane LX2 (ov009, ov016), all PASS results kept:

- an ABS32 pool word that points outside the region takes no ARM/Thumb type from
  `match.isa_evidence` unless the answer is an asm/arm9 or asm/twl label: another
  overlay at the same RAM address turned the data name `gcd_gamename` into a Thumb stub
  (+1);
- a call to a function another file defines `static` gets a global alias of that local
  symbol in its own file (local functions are now in the first-link address map, keyed
  by file), not an absolute `.lcf` name: mwldarm misencodes a backward Thumb BL to an
  odd absolute address by 2 bytes. A global target gets its alias only in the file that
  defines it globally (ov016 has many files with a static `button`);
- a `.rodata` blob found more than once in the image drops the places that lie inside
  an object the headers name (registry size) before it gives up.

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

`python tools/gamelink.py itcm` PASS.

#### ARM9 static module (2026-10-12, lane LK1)

`python tools/gamelink.py arm9_main` (no skips) **PASS**: the linked module is
byte-identical to the original static ARM9 (0x02004000..0x020A9E80, 679552 bytes).
426 src/game/arm9 files link from objects (626436 bytes of code, 5 data sections in the
image range, 24 `.bss` sections placed at their addresses), 245 typed stubs (callees in
ITCM, TWL and other modules), 1041 absolute `.lcf` names (data, mostly `.bss`), 14 dead
data sections. Same run, all regions: itcm and 175 of 178 overlays PASS.

What changed in `gamelink.py` for this:

| blocker | fix |
| --- | --- |
| a file whose functions are not contiguous (MSL runtime parts p03, p05 of `unit_020911D4`: other parts lie between their functions) | mwccarm writes one `.text` section per function; the sections are cut into runs at each function whose known address (header, `func_` name, `layout/runtime_arm9.txt`) lies outside the room of the current run, and each run gets its own `.lcf` region. Smaller differences are left to the linker (veneers after a function; some `func_` names sit one word into their function). `layout/symbols_sdk.json` is not used for this: game files define functions under SDK names the SDK has elsewhere (`CARD_SetPulledOutCallback` in `unit_02066B84`, `OS_KillThread` in `mystery_data`) |
| a function-local `static const double` (MSL `k_sin`, `k_cos`) that the compiler puts in the literal pool and also emits as an unreferenced `.rodata` section; the string search placed it on top of the pool | a data section that no relocation uses and that has no global name is dead (the original link stripped it); it is parked outside every region |
| calls to entry points inside an asm function (`_ll_udiv`, `_ll_sdiv`, `_fsub`: labels in `_ll_divmod_entry_signed` and the float routines) were absolute symbols, so the linker made BL instead of BLX | a typed alias symbol at function+offset (from the first link) |
| a file with data and no code | no empty code region |
| address vote for a data section: a tie, or a base the section alignment forbids, was picked silently (ov107 showed it as a 0x1C overflow) | reported as an error that names the symbols |

New options: `--unplaced` also links `unplaced/*.c` stand-ins (arm9: `func_0209D850`,
PASS); `--extra=DIR` replaces or adds files from DIR, to try a source change without
touching src/.

Overlays that fail in the same run, all from sources other lanes have open:
ov009 (one word: `helper_threads_priority = 10` in `unit_021573C4_p01.c`, the original
holds 0x10), ov021 (split TU, a 0xC overflow), ov093 (`btl_server` being merged).

#### crt0 as one C file (src/game/arm9/crt0.c)

The TwlSDK object crt0.HYB.TWL.o (its DWARF names the source crt0.FLX.c) is one
file again: `src/game/arm9/crt0.c` at 0x02004800 holds the code and the data in the
order of the original source. The data comes first in the source (DWARF lines 88-182):
`_start_ModuleParams[9]`, `_start_LtdModuleParams[6]`, and the static tables
`microcode_ShakeHand[10]`, `microcode_WaitAgreement[7]` and
`microcode_SwitchCpuClock[13]`. Then the 14 functions in object order (lines 212-1084):
`_start`, `INITi_CpuClear32`, `INITi_InitCoprocessor`, `INITi_InitRegion`,
`INITi_DoAutoload`, `INITi_ShelterStaticInitializer`, `INITi_CallStaticInitializers`,
`MIi_UncompressBackward`, `_start_AutoloadDoneCallback`, `NitroStartUp`,
`OSi_ReferSymbol`, `INITi_IsRunOnTwl`, `INITi_Copy32`, `INITi_Fill32` (static where the
object has a local symbol). Compiler dsi/1.1p1 `-O4,p`, ARM, as the vendor object. The
text ends at 0x02004F7C; mwccarm puts the five tables in one `.rodata` (0xB4 bytes),
which the link places right after it at 0x02004F7C, in the object's order
(`_start_LtdModuleParams`, `microcode_WaitAgreement`, `_start_ModuleParams`,
`microcode_ShakeHand`, `microcode_SwitchCpuClock`). The module parameters are the
linker names `SDK_AUTOLOAD_LIST`, `SDK_AUTOLOAD_LIST_END`, `SDK_AUTOLOAD_START`,
`SDK_STATIC_BSS_START`, `SDK_STATIC_BSS_END`, `SDK_COMPRESSED_STATIC_END` and the
`SDK_LTD...` four, with values from `layout/layout.json`, plus the SDK version and the
magic words. The microcode words come from the user's ROM through `#include`
(build/gen, written by tools/gendata.py, not committed). `SDK_COMPRESSED_STATIC_END`
is written by the compressor in the original flow; here it is a name with the value
of the decompressed image. `_start_BuildParams` (line 103, a second `.rodata` of 0x20
bytes at 0x02005030) is not in the file yet. The four files it replaces
(`unit_02004800.c`, `unit_02004DF4.c`, `unit_02004EA8.c`, `unit_02004EB4.c`) and the
asm `dcd` bodies `unit_02004F94.c`, `unit_02004FD4.c` are gone. gameverify EXACT: the
table addresses are `symbols:` rows attested by the `sole-ref/data` class (the
listings' data-object starts), the same rule that attested `_start_ModuleParams`
before. gameverify reports a file without code (no executable section, at least one
data byte) as `DATA-ONLY ... (checked by gamelink)`, not as not exact.

#### What still comes from the image (arm9_main, 53026 bytes)

| range | bytes | what it is |
| --- | --- | --- |
| 0x0209D86C..0x020A9E80 | 50646 | `.rodata`/`.data` of the module, no file defines it yet: data into C (`datagen.py`) |
| 0x02004000..0x02004800 | 1980 | secure area around the SVC thunks: opaque bytes, stays a prebuilt binary |
| 0x02005030..0x02005124 | 244 | crt0's `_start_BuildParams` (0x20 bytes at 0x02005030) and the `.version` middleware strings (`[SDK+NINTENDO:DWC...]`); the crt0 tables at 0x02004F7C (180 bytes) are C now (above) |
| 14 x 2 bytes | 28 | zero padding after a Thumb file before the next 4-aligned one; a single-section link makes it itself |
| 0x02081E6C | 16 | SHA-1 round constants inside the code range (an SDK `.rodata`) |

Also image evidence, not bytes: the addresses of names missing from every header (read
from the original code), and the typed stubs and absolute names, which stand for code
and data of other modules and `.bss` addresses. The 3 small TWL/VRAM autoload blocks
(`asm/arm9/autoload*_main_twl.s`, `vram_lcdc.s`) have no src/game directory and are not
linked.

Remaining gap to a link with no image input: the gap data (typed C from
`datagen.py` compiled and linked as real objects instead of binary sections), the
stub objects (real callees: the arm9 static module and other overlays linked as
objects with their true code), the addresses of missing names, the 48 bytes of ov119,
and the overlay table and `.lcf` for the whole ROM instead of one region at a time.

### 3. Prebuilt pieces

Kept as binaries taken from the user's own dump (never committed): the ARM7 binary
and its overlays, the SDK and library objects that are not restructured (the ARM9
ranges without a src/game file), the autoload info table and the DTCM/TWL blocks
that have no TU yet. They are listed from `layout/layout.json` and bound into the
final image by `ndsrom.py build --override`, as `build.py --pack` already does.
