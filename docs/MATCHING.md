# Function matching

Milestone 4 work: a harness that compiles a C translation unit with one of
the nine CodeWarrior / Freescale TWL-line front ends, extracts a named
function from the resulting object, and compares it byte for byte with the
original code at a target address.

The tool is `tools/match.py`. It reuses the ELF32 reader, the relocation
width table and the region loader from `tools/libmatch.py`, and the compiler
discovery from `tools/cw.py`, so there is still exactly one implementation of
each of those in the repository.

Nothing from `sdk/` or `vendor/` is copied into the tree. SDK headers are
reachable at compile time through `-I+sdk/TwlSDK/include`, which `match.py`
adds automatically when that directory exists; none of the matched sources so
far actually need it.

## Verdicts

| verdict | meaning |
| --- | --- |
| `EXACT` | every byte identical, relocation fields included |
| `MATCH` | identical except where the linker would have written a value |
| `SIZE` | the compiler produced a different number of bytes |
| `DIFF` | same size, concrete bytes differ; a two-column diff is printed |
| `ISA` | the original is Thumb and the object is ARM, or the reverse |
| `CCERR` | the compiler rejected the translation unit |

Wildcards come from the object's own relocation table, not from a heuristic:
an `R_ARM_ABS32` blanks four bytes, `R_ARM_PC24` the low three bytes of the
word, a Thumb `BL` pair all four. That is the same policy `libmatch.py` uses
to pattern SDK library functions, and it is what lets a function that
references a global or calls out be judged before the project has a link
step.

A trailing `*` on `EXACT` or `MATCH` means the comparison itself passed but
the size disagrees with the extent `disasm.py` inferred for the original.
The extent is the distance to the next `func_` label in the generated
listing, which is a heuristic: a follower with no register-saving prologue
(a tail call through `bx r3`, say) is not labelled, so the extent runs long.
`sub_020084BC` is exactly that case and the `*` is expected there.

## Usage

```
python tools/match.py show  --addr 0x02008534
python tools/match.py one   --src src/matched/sub_02008534.c \
    --func sub_02008534 --addr 0x02008534 --cc 1.1p1
python tools/match.py one   ... --diff
python tools/match.py sweep --src ... --func ... --addr ...
python tools/match.py sweep ... --cpp --extra --json matrix.json
python tools/match.py tu   --src src/matched/unit_0200852C.c \
    --addr 0x0200852C --thumb
python tools/match.py manifest --verify
```

`show` disassembles the original bytes at an address and is the writing aid:
it resolves the region from `layout/layout.json`, the instruction set from
the listings, and the extent from the next function label.

The instruction set is not guessed. `resolve_isa` reads the `.thumb_func`
marker that `disasm.py` emits before each Thumb entry point, falling back to
the per-symbol `thumb` flag in `layout/symbols_sdk.json`, and only then to
ARM. `--thumb` and `--arm` override it. Getting this wrong is silent and
expensive: an ARM compile of a Thumb function produces a plausible-looking
diff in which nothing lines up.

`sweep` crosses every compiler under `tools/mwccarm/mwccarm/dsi/` with seven
optimisation spellings, optionally `-lang c++` (`--cpp`) and four
inline/ipa variants (`--extra`), and prints a matrix. Cells read `EXACT`,
`MATCH`, `D<n>` for n differing concrete bytes, `S<n>` for a size mismatch
or `err`.

`tu` compares a whole translation unit against a byte range instead of one
function against one address. It lays every executable section of the object
end to end the way a linker would, aligning each and filling the gaps, and
prints the resulting per-function map before the verdict. See "TU
granularity" below for why that is the right model and what it establishes.
`tu` does not infer the instruction set, because the first function of a unit
often has no label in the generated listing; pass `--thumb` for game code.

## Flags

The base set every configuration carries:

```
-proc arm946e -enum int -Cpp_exceptions off -interworking -char signed
-msgstyle gcc
```

plus `-thumb` when the target function is Thumb, `-lang c99` or `-lang c++`,
and the optimisation flags under test. Two spelling notes:

* the speed/space bias is a suffix on `-O4`, written `-O4,p` and `-O4,s`.
  `-Otime` and `-Ospace` are not accepted by this front end, so the sweep
  does not carry them.
* `-I` wants the directory joined to the flag (`-I+<dir>`), not as a
  separate argument; passed separately, mwccarm reports
  "is a directory, not a filename".

## Calibration against a known compiler

`docs/SYMBOLS.md` establishes from `.comment` strings that the SDK libraries
the game links were built with Metrowerks C/C++ for ARM 4.0.0.1024, which is
`tools/mwccarm/mwccarm/dsi/1.1p1`. Four SDK functions were reimplemented in
C from their disassembly alone, without opening any source under `sdk/`, and
run through the harness at `-O4,p` under that compiler.

| address | function | bytes | ISA | verdict | source |
| --- | --- | --- | --- | --- | --- |
| 0x02075DD8 | `CARD_GetResultCode` | 20 | ARM | MATCH | `src/calib/card_getresultcode.c` |
| 0x02075DF8 | `CARD_GetOwnRomHeader` | 12 | ARM | EXACT | `src/calib/card_getownromheader.c` |
| 0x0207C958 | `FX_DivS32` | 60 | ARM | EXACT | `src/calib/fx_divs32.c` |
| 0x0207D41C | `GX_GetBankForLCDC` | 16 | ARM | MATCH | `src/calib/gx_getbankforlcdc.c` |

The two MATCH results are MATCH rather than EXACT only because their single
literal is an `R_ARM_ABS32` relocation against a global the project has not
named yet. The two EXACT results have no relocations at all: one returns a
constant address, the other only touches hardware registers.

`FX_DivS32` is the one that says something. Written the obvious way, with the
divider's denominator as two separate 32-bit stores, it comes out DIFF with
31 concrete bytes wrong and one instruction short: the original carries a
`mov r0, r3` the obvious version does not. Writing the denominator as one
64-bit register assigned a 32-bit *unsigned* value makes the zero-extended
high word the second half of a register pair, which is exactly that move, and
the function goes to EXACT. A 60-byte function with a poll loop reproduced to
the byte, including register numbering, is a real calibration of the flag set
and not an accident of triviality.

Conclusion: `-proc arm946e -O4,p -enum int -char signed -interworking
-Cpp_exceptions off`, `-lang c99`, ARM for SDK code, is a working
configuration under `dsi/1.1p1`.

## Matched game functions

Eight functions from `asm/arm9/src/`, none of them in
`layout/symbols_sdk.txt`, chosen as leaves with clear data flow. All of them
are Thumb; the game's own code in the ARM9 static module is Thumb throughout,
in contrast to the SDK libraries, which are ARM (`docs/SYMBOLS.md` shows the
game links the non-`.thumb` library variants by a factor of twelve).

| address | name | bytes | verdict | what it does |
| --- | --- | --- | --- | --- |
| 0x0200575C | `sub_0200575C` | 12 | MATCH | pointer table lookup, unchecked index |
| 0x0200590C | `sub_0200590C` | 24 | MATCH | address of a member of a 0x1C-byte table entry |
| 0x02005E50 | `sub_02005E50` | 20 | MATCH | boolean test of a field of a global |
| 0x02006E2C | `sub_02006E2C` | 20 | MATCH | round a field up to a multiple of 32 |
| 0x020084BC | `sub_020084BC` | 24 | EXACT* | are all eight halfwords zero |
| 0x02008534 | `sub_02008534` | 8 | EXACT | word field read back as a halfword |
| 0x02008954 | `sub_02008954` | 8 | EXACT | byte field copied out through a pointer |
| 0x0200A6BC | `sub_0200A6BC` | 60 | EXACT* | set one bit in each of two parallel bitmaps |

and two whole translation units, matched as byte ranges rather than function
by function:

| address | unit | bytes | functions | verdict |
| --- | --- | --- | --- | --- |
| 0x020084BC | `src/matched/unit_020084BC.c` | 112 | 7 | MATCH |
| 0x0200852C | `src/matched/unit_0200852C.c` | 78 | 16 | EXACT |

The two abut: 0x020084BC + 112 is 0x0200852C. Together they are 190
contiguous bytes and 23 functions, with no gap and no overlap, and they are
almost certainly two halves of one original source file. They are kept as two
files so that the relocation-free half can carry an EXACT verdict rather than
being diluted to MATCH by the other half's six relocations.

They do overlap the single-function entries at 0x020084BC and 0x02008534,
which are kept because they are the documented single-function results;
`layout/matched.json` lists both, distinguished by `kind` (`game` against
`game_unit`).

Names are `sub_<address>` because the semantics are clear but the role in the
game is not; renaming them later is a mechanical change to one file and the
manifest. The inventory is `layout/matched.json`, regenerated with
`python tools/match.py manifest --verify`, which recompiles every entry and
records the verdict it actually gets rather than the one the header claims.

Two of the seven pinned their source shape on a detail rather than on luck:

* `sub_02008534` truncates a word to a halfword with a `lsls`/`lsrs` pair.
  Writing `& 0xFFFF` instead produces `movs`/`ands`, because Thumb has no
  immediate AND. The shift pair is what a conversion in the type system
  looks like.
* `sub_020084BC` uses `blt`, not `blo`, for its loop condition, so the
  counter is a signed `int`; and the `movs r0, #0; bx lr` pair sits in the
  middle of the loop body, so the failure path is an early `return 0` and
  not a flag variable tested after the loop.

## TU granularity

The question this answers: per-function matching is only useful if it scales
to whole source files, because the original was compiled as multi-function
translation units and the final link consumes files, not functions. It does
scale, and the reason is structural rather than lucky.

**mwccarm emits one PROGBITS section per function.** Not one `.text` per
file: sixteen functions produce sixteen sections, all named `.text`, all with
`sh_addralign` 4, in the order the functions appear in the source. That is
the same property `docs/SYMBOLS.md` relies on to pattern SDK library
functions, and it is what makes the compiler's output order-preserving and
the *linker* the thing that decides addresses. So the byte image of a
translation unit is the sections laid end to end, each aligned up, with the
gaps filled. `match.py tu` builds exactly that and compares it with a byte
range.

Two ranges were matched this way.

`0x0200852C..0x0200857C`, 78 bytes plus its trailing fill, is sixteen
consecutive accessors on one object: nine word and byte getters, six
setters, and a set-if-zero. The range is closed on
both sides, the function before it ending exactly at 0x0200852C and the one
after starting exactly at 0x0200857C. Written as a single C file in address
order it comes out **EXACT on the first attempt**, every function at its
original address. Four of the sixteen carry no label in the generated listing
at all, because `disasm.py` only labels a function that opens with a
register-saving prologue and a two-instruction accessor has none; they were
read out of the bytes.

`0x020084BC..0x0200852C`, 112 bytes, is the seven functions immediately
before it, chosen because they have what the accessor run lacks: four
literal pools, a padding gap, tail calls in both directions across the
interworking boundary, and a call from one function of the unit to another.
It comes out **MATCH**, its six relocations being ABS32 pool words and a
Thumb BL. The two ranges abut, so 190 contiguous bytes and 23 consecutive
functions of the original are now accounted for by two source files.

What the two ranges settle:

* **Function order is source order.** The compiler does not reorder. Swapping
  two adjacent four-byte accessors in the source swaps their bytes in the
  output and the unit goes from EXACT to two differing bytes. A matched unit
  is therefore direct evidence of the order the functions were written in.
* **Literal pools are per function, not per unit.** Each function's pool sits
  at the end of that function's own section. The original says this
  independently of anything this project compiles: 0x020084D4 and 0x020084F8
  both load the address 0x0201F41C, thirty-six bytes apart, and the word is
  stored twice, once in each pool. A per-unit pool would have stored
  it once.
* **There are two kinds of padding and they are different bytes.** Inside a
  section, where the compiler aligns a pool behind an odd number of Thumb
  instructions, the filler is `C0 46`, a Thumb `mov r8, r8`; 0x0200850A is
  one. Between sections, where the linker aligns the next function, the
  filler is `00 00`; 0x0200854A, 0x0200857A and 0x020084F6 are all that. Both
  kinds are reproduced by the two matched units. Getting this backwards would
  have shown up as a two-byte diff in the middle of an otherwise clean unit.
* **Static versus extern linkage is invisible in the bytes.** Marking all
  sixteen accessors `static` changes nothing: same code, same order, same
  padding, still EXACT. Unreferenced statics are still emitted, because
  dead-stripping is the linker's job and each function is its own section.
  Linkage is therefore not recoverable from the image at this level, and a
  matched unit makes no claim about it either way.
* **The result is version-independent.** Both units are EXACT and MATCH
  respectively under all nine front ends at `-O4,p`.

The practical consequence is that a translation unit boundary is a testable
hypothesis rather than a guess: propose a range, write the file, and `tu`
either reproduces the whole range including its internal padding or it does
not. `layout/units_arm9.json` is not that: it is `disasm.py`'s mechanical
180-functions-per-file split of the listings and has no relation to the
original file boundaries.

What this does *not* establish is that a large, realistic translation unit
with inlining across its own functions, static data and a switch table will
behave as tamely. Both units here are leaf-heavy and small. The mechanism
(one section per function, source order, linker-assigned addresses) does not
depend on size, but the codegen inside a big unit has more room to diverge.

## What the sweep says about the compiler

Every one of the eight game functions, both translation units, and all four
calibration functions, produce **byte-identical code under all nine compiler
versions** at `-O4,p`. The matrices are flat:

```
  sub_020084BC       -O4,p   -O4,s  -O4    -O3    -O2    -O1    -O0
  1.1 .. 1.6sp2      EXACT*  D24    D24    D24    D24    D24    D32
```

That is not a limitation of the harness. The same holds for input the game
had no part in: compiling the `cw.py` smoke translation unit with all nine
front ends, in both ARM and Thumb, gives bit-identical bytes for all three of
its functions. The nine TWL-line front ends in this collection (builds 1018,
1024, 1026, 1027, 1028, 1034, 1036 and 1051, the last shared by `1.6sp1` and
`1.6sp2`, which are the same executable) are not distinguishable by codegen
on this class of code.

So the honest statement is:

* the **optimisation level is pinned**: `-O4,p` and only `-O4,p`. Two
  functions now separate it independently. `sub_020084BC` matches at `-O4,p`
  and fails with 24 differing bytes at `-O4,s`, `-O4`, `-O3`, `-O2` and
  `-O1`. `sub_0200A6BC` matches at `-O4,p`, loses two instructions and four
  bytes at `-O4,s` and `-O4`, and is 40 bytes wrong at `-O3` and `-O2`. Every
  other matched function is indifferent between `-O4,p`, `-O4,s`, `-O4`,
  `-O3` and `-O2`, so these two carry the claim, and they agree.

  The setting is pinned, not the spelling. This front end accepts
  `#pragma optimization_level 4` and `#pragma optimize_for_size off`, and a
  file carrying that pair compiles to the same bytes with `-O0` on the
  command line: `sub_0200A6BC` is still EXACT. So the original build may have
  set the level per file in a header rather than on the command line, and the
  image cannot tell the difference. What is excluded is any *other* level.
  `#pragma scheduling` and `#pragma inline_depth` are rejected as illegal
  pragmas by this front end, so there is no per-file scheduling control to
  look for; `optimization_level`, `optimize_for_size`, `opt_common_subs`,
  `opt_dead_code`, `peephole`, `ipa` and `thumb` are accepted.
* the **instruction set is pinned**: Thumb for game code, ARM for the SDK.
* the **compiler version is not pinned by matching**, and on present evidence
  cannot be: the candidate set after the sweep is still all nine. The only
  evidence that narrows it is indirect, from `docs/SYMBOLS.md`: the libraries
  the game links were built by build 1024 (`dsi/1.1p1`), and a project
  normally builds its own code with the compiler that came with its SDK
  drop. `layout/matched.json` therefore records `dsi/1.1p1`, but that is the
  SDK's compiler standing in for the game's, not a measurement.

Narrowing this further needs a function big enough for the versions to
disagree on: something with inlining decisions across several calls, or
floating point, or a switch dense enough to become a jump table. Those are
not leaf functions and are the natural next step.

### The versions are not identical, they just agree on this code

`sub_0200A6BC` produced the first construct in this project on which two
front ends disagree, and it is worth recording precisely because it looked
for an hour like a version discriminator and is not one.

Write the bit set as `obj->unk258[byte] |= 1 << shift;`, leaving the
truncation back to `u8` to the implicit conversion in `|=`. Build 1018
(`dsi/1.1`) decides the truncation is dead, drops the `lsls #24` / `lsrs #24`
pair, and emits 56 bytes. Builds 1024 and later keep it and emit the
original's 60. On that source, `dsi/1.1` is 35 concrete bytes wrong and the
other eight are EXACT, which is exactly the shape of a discriminator.

It is not one, because a different spelling of the same C recovers the match
under 1018 as well: with the cast written out, `|= (u8)(1 << shift)`, all
nine front ends produce the original. The version-neutral form is the one
committed. So the finding is real but weaker than it first appeared:

* the nine front ends are **not** codegen-identical, and the boundary is
  between build 1018 and build 1024, which is also the boundary between
  `dsi/1.1` and the version the SDK libraries were built with;
* but they are indistinguishable **on the original's bytes**, because for
  every version there is a source shape that reproduces them. The candidate
  set after this experiment is still all nine.

The lesson for the rest of the project is that a version disagreement is only
a discriminator if no source shape recovers the match under the losing
version, and checking that means sweeping source shapes against that version,
not just flags. Seven hundred (source shape, level, language) combinations
were tried against `dsi/1.1` before it was cleared here.

## Language evidence: C or C++

**Verdict: no evidence of C++.** The game should be written and matched as C.

The measurements are in `tools/cppscan.py`, which reads the regions through
`libmatch.load_regions` and uses `asm/*.s` read-only as an oracle for function
entries and for the code/data and Thumb/ARM splits. `layout/symbols_sdk.json`
separates SDK code from game code, which matters: the DWC and GameSpy stack in
ov009, ov016 and ov114 is known C and is full of callback tables, so anything
not attributed would be measuring the SDK.

### What C++ would have to look like on this toolchain

Not assumed, measured. A probe translation unit compiled with `dsi/1.1p1`
`-lang c++` establishes that this front end uses Itanium mangling (`_ZTV`,
`_ZTI`, `_ZTS`), not the older CodeWarrior `__vt__` / `__ct__` scheme; that a
vtable is laid out `[offset-to-top = 0][typeinfo pointer][fn0][fn1]...` with
the object's vptr pointing at `fn0`; that pointer-to-member calls are inlined,
so there is no `__ptmf` thunk to look for; and that any non-trivial C++
translation unit leaves undefined references to `_Znwm`, `_ZdlPv`,
`__cxa_vec_new`, `__cxa_vec_delete` and `__register_global_object`, plus the
`__cxxabiv1` class-type-info vtables when RTTI is on.

### The four measurements

| measurement | result |
| --- | --- |
| pointer tables with the CodeWarrior vtable header | 36 of 536, against a control of 47 |
| game-code indirect calls with the virtual-call shape | 67 of 535 Thumb sites |
| C++ runtime or RTTI strings anywhere in the image | 0 of 10191 strings in 242 regions |
| global constructors in the whole 3.9 MB image | 0 |

**Pointer tables.** 536 runs of three or more consecutive word-aligned
pointers into code, 4036 slots, across all 242 regions. 36 of them are
preceded by the `[0][pointer]` header a CodeWarrior vtable carries. The
control for that test is the meaningless mirror image, `[non-zero][0]`, which
occurs 47 times: the signal is *below* its own base rate, so the header shape
here is a stray zero word and nothing more. The large tables argue the same
way from the other end: the biggest are 252, 243, 154 and 91 slots, all in
ov021, which is far past any plausible class, and 308 of the 536 have all
their targets within 0x400 of each other, which is a switch jump table.

Restricted to the five regions the question was asked about, the same scan
gives 138 tables and 1444 slots, of which 8 carry the header shape against a
control of 11:

| region | tables | slots | header | header and referenced | control | SDK targets | jump table |
| --- | --- | --- | --- | --- | --- | --- | --- |
| arm9 | 33 | 195 | 4 | 3 | 2 | 4 | 19 |
| ov009 | 13 | 66 | 0 | 0 | 1 | 10 | 7 |
| ov016 | 18 | 69 | 0 | 0 | 1 | 15 | 4 |
| ov021 | 72 | 1108 | 4 | 3 | 7 | 0 | 56 |
| ov114 | 2 | 6 | 0 | 0 | 0 | 2 | 2 |

**Indirect dispatch.** Every `blx <reg>` in the image, classified by how the
called register was produced. In Thumb, which is the game's own instruction
set, there are 603 sites, 535 of them outside recovered SDK code:

| shape | sites | what it is |
| --- | --- | --- |
| `ldr rF, [rT, rI]; blx rF` | 251 | `table[i]()`, indexed at run time |
| `ldr rF, [rB, #j]; blx rF` | 225 | a function-pointer field of a struct |
| `ldr rA, [rB, #i]; ldr rF, [rA, #j]; blx rF` | 67 | two constant offsets: the virtual-call shape, and equally `obj->ops->hook()` |
| everything else | 60 | literal, stack, unclassified |

The 251 run-time-indexed calls cannot be virtual dispatch at all: a vtable
slot offset is a compile-time constant. The 67 two-level sites are the only
ones a C++ hypothesis could hang on, and they do not survive inspection. 34 of
the 67 test the loaded pointer against zero before calling it, which is a C
optional hook and is something CodeWarrior never emits for a virtual call;
only 24 load the outer pointer from offset 0 of the object, where a vptr
lives. The sampled sites are all `obj->ops->hook(obj)` at non-zero field
offsets. One of them, at 0x02005644, is the whole argument in five
instructions:

```
ldr  r1, [r0, #8]     ; the hook
cmp  r1, #0           ; ... which is allowed to be absent
beq  skip
ldr  r0, [r0]         ; the argument, from offset 0, not a vptr
blx  r1
```

There are no occurrences image-wide of the pre-ARMv5 `mov lr, pc; bx rN`
indirect-call form, so this classification is not missing a second calling
idiom.

**Strings.** 33 tokens covering both mangling schemes, the RTTI objects, the
allocation and array-construction helpers, and the runtime diagnostics
(`pure virtual`, `bad_cast`, `typeinfo`, `__cxa`, `_ZTV`, `__vt__`, and so
on), against every printable run of five characters or more in all 242
regions. 10191 strings, zero matches. This is the weakest of the four, since
`-RTTI off` removes the type names; it is the next two that carry the claim.

**The C++ runtime is absent from both ends.** No library under `sdk/` defines
any of `_Znwm`, `_ZdlPv`, `__cxa_vec_new`, `__cxa_vec_delete` or
`__register_global_object`, and there are no C++-only mangled symbols at all
in 10592 object members across 1446 archives. There is no MSL C++ runtime in
this SDK drop, so a C++ game would have had to link one out of the compiler
distribution, and nothing in the image references one. The naive test fails
here: a plain `_Z` grep reports 823 hits, because mwccarm mangles
function-local statics as `_ZZ<fn>E<var>` in C as well as C++. Those 5714
symbols have to be excluded, and once they are, nothing is left.

**No global constructors anywhere.** Any global object with a constructor or
destructor forces a `__sinit_<file>` entry into its module's
static-initialiser list. All four ARM9 autoload lists are empty, which the
previous revision of this document already established, and so are 236 of the
237 overlay lists: the overlay table gives each of them a `static_init_count`
of 1, which is the NULL terminator alone.

### The one exception, ov230

ov230 is the single region in the ROM with a non-empty static-initialiser
list: five entries at 0x02189974, pointing at 0x02188408, 0x021889B0,
0x02188CB0, 0x02189448 and 0x02189908, all inside the overlay. They are not
constructors. Each is an ARM thunk of exactly this shape:

```
orr r0, pc, #0        ; r0 = the inline table below
add r0, r0, #4
b   0x02188A48        ; a common walker
.word start, end      ; ... repeated, terminated by a zero word
```

and the walker at 0x02188A48 does range arithmetic (`sub #0x1600`, `bic #3`, a
loop over start..end) on the pairs, not object construction: there are no
per-object pointers and no calls through a constructor slot. The prologue
`orr r0, pc, #0; add r0, r0, #4` occurs exactly five times in the entire ROM,
all of them here, so this is a mechanism unique to this one overlay. ov230 is
also the odd one out in every other way: it is ARM where the game is Thumb,
`disasm.py` recognises only seven functions in it, and `libmatch.py` recovers
no SDK symbols from it. The range tables address memory above the overlay's
own end at 0x021899A0, so their subject is something else resident at the same
time.

So the static-initialiser mechanism is used exactly once in the ROM, and what
it runs is not a constructor. This does not move the verdict, but it is the
one loose end, and it should be revisited when the overlay loader is
understood.

### What this does and does not claim

It claims that the game contains **no C++ feature that leaves a trace in the
binary**: no vtables, no virtual dispatch, no RTTI, no `new` or `delete`, no
globals with constructors, no C++ runtime.

It does not claim the sources were `.c` files. C++ written as classes with
non-virtual member functions, no dynamic allocation through `new`, and no
globals with constructors compiles to code indistinguishable from C, and all
four measurements would read exactly as they do. That possibility is
untestable from the image, and it does not matter for matching: every matched
entry compiles to identical bytes under `-lang c99` and `-lang c++`, so the
choice changes nothing about the bytes. `match.py` demangles both schemes, so
`--func` takes the source name either way, and `--cpp` stays wired into the
sweep.

The practical conclusion is to write C.

### Caveats

* The code/data split, the function-entry set and the Thumb/ARM extents all
  come from `asm/*.s`, that is from `disasm.py`. A systematic blind spot
  there, a whole data region misclassified as code hiding a vtable, would
  propagate into the first two measurements. `cppscan.py --entry prologue`
  reruns the table scan without using the generated labels at all and gives
  the same counts to within one table, which is the available mitigation.
* The ARM-mode dispatch sites are attributed to the SDK by instruction set
  rather than by symbol: 895 of 1498 sites image-wide are in ARM code and only
  527 of those fall inside a function `libmatch.py` actually recovered. That
  rests on the project's existing finding that game code is Thumb. Game code
  compiled ARM would currently be counted as SDK.
* `layout/symbols_sdk.json` records function extents only, so a vtable in an
  SDK library's data cannot be attributed by address. The table scan
  attributes a table by the SDK fraction of its targets instead, which is the
  right test but is bounded by the 4426 symbols recovered so far.

### Reproduce

```
python tools/cppscan.py all      --regions all --isa thumb
python tools/cppscan.py all      --regions named
python tools/cppscan.py vtables  --regions all --entry prologue
python tools/cppscan.py dispatch --regions named --isa thumb --verbose --show
python tools/cppscan.py strings  --regions all
python tools/cppscan.py runtime  --cc 1.1p1
```

## The 0x0200A6BC near miss, resolved

This section used to record `0x0200A6BC` as a 60-byte function that reached
the right size and the right first 20 bytes but was 31 concrete bytes wrong
in the tail, the difference being register allocation and scheduling around
two read-modify-write pairs. It is matched now, and it is committed as
`src/matched/sub_0200A6BC.c`.

The whole of the fix is where one cast goes. The near miss held the bit mask
in a byte variable:

```c
u8 bit = (u8)(1 << sh);
s->a[idx] |= bit;
s->b[idx] |= bit;
```

which truncates once, immediately after the shift. The original truncates at
the uses:

```c
obj->unk258[byte] |= (u8)(1 << shift);
obj->unk278[byte] |= (u8)(1 << shift);
```

Common subexpression elimination still computes the shift once, but the
`lsls #24` / `lsrs #24` truncation pair is now free to sink, and it does: the
`lsls` lands before the address arithmetic and the `lsrs` after the first
`ldrb`. That split pair, four bytes apart in the middle of the tail, is the
visible signature. Nothing else changed. Same eighteen instructions either
way; with the byte temporary they come out in a different order with every
general register shifted by one, which is what those 31 bytes were.

How it was found, because the method matters more than the answer: the search
was mechanical, not inspired. Three parameter spellings crossed with two
guard spellings crossed with eleven body shapes, generated from a template
and scored by `match.py`'s own diff count. Sixty-six candidates, compiled and
ranked in about a minute, and the ranking was completely flat except for the
two shapes that place the cast at the use, which came out EXACT. The other
sixty-four were all 31, 46 or 48 bytes wrong, so the parameter spelling and
the guard spelling turned out to matter not at all and only the cast
mattered. When a near miss is scheduling-shaped, enumerate source shapes
rather than reasoning about the scheduler; the generator is in the session
scratchpad and is about sixty lines.

Four details pin the source, in decreasing order of how long they took:

* `1 << shift` must not be held in a `u8` temporary, as above; and the cast
  at the use has to be explicit rather than left to the implicit conversion
  in `|=`, which is what keeps build 1018 in agreement with the rest. See
  "The versions are not identical" above.
* the guard is an unsigned compare (`cmp #0x64` / `bhs`) even though the
  index is otherwise signed, so it has to be written against an unsigned
  parameter; written as `if (n < 0 || n >= 100)` on a signed parameter, this
  compiler emits two compares and two branches rather than folding them.
* the same value is `% 8` in one place and `>> 3` in another. `% 8` on a
  signed value compiles to the `lsrs #31` / `lsls #29` / `subs` / `rors #29`
  sequence the original shows; `& 7` would be a two-instruction `movs`/`ands`
  and `/ 8` adds a rounding correction the original does not have.
* the shift amount is truncated to `u8` before the shift, not after. That
  intermediate is visible as a `lsls #24` / `lsrs #24` pair sitting between
  the modulo and the `movs r3, #1`, and moving it changes four instructions.

The verdict is EXACT* rather than EXACT: the function at 0x0200A6F8 opens
`push {r3, r4}` with no lr to save, so `disasm.py` does not label it and the
inferred extent for 0x0200A6BC runs 88 bytes to the next label at 0x0200A714.
The 60 bytes compared are the whole function.

## Not wired into the build

`tools/build.py` still assembles `asm/` and links that. None of `src/` is
compiled or linked by it, and `layout/matched.json` is inventory, not a build
input. Wiring a matched function into the link means replacing the
corresponding range in its translation unit and keeping the region
byte-identical, which needs the linker script and symbol work that is the
next milestone. Until then a matched function is a proven claim about what
the original source said, verified on demand by `match.py`, and the
byte-identical rebuild continues to come from `asm/`.

## Reproduce

```
# calibration, against a compiler we know built this code
python tools/match.py one --src src/calib/card_getresultcode.c \
    --func CARD_GetResultCode --addr 0x02075DD8 --cc 1.1p1
python tools/match.py one --src src/calib/card_getownromheader.c \
    --func CARD_GetOwnRomHeader --addr 0x02075DF8 --cc 1.1p1
python tools/match.py one --src src/calib/fx_divs32.c \
    --func FX_DivS32 --addr 0x0207C958 --cc 1.1p1
python tools/match.py one --src src/calib/gx_getbankforlcdc.c \
    --func GX_GetBankForLCDC --addr 0x0207D41C --cc 1.1p1

# every matched function and unit, recompiled and re-verified
python tools/match.py manifest --verify

# the two matrices that pin -O4,p
python tools/match.py sweep --src src/matched/sub_020084BC.c \
    --func sub_020084BC --addr 0x020084BC --cpp
python tools/match.py sweep --src src/matched/sub_0200A6BC.c \
    --func sub_0200A6BC --addr 0x0200A6BC --thumb --cpp

# whole translation units
python tools/match.py tu --src src/matched/unit_0200852C.c \
    --addr 0x0200852C --thumb
python tools/match.py tu --src src/matched/unit_020084BC.c \
    --addr 0x020084BC --thumb --diff

# the language evidence
python tools/cppscan.py all --regions all --isa thumb
python tools/cppscan.py runtime --cc 1.1p1
```

`match.py` needs `capstone` for the diff and `show` output only; the verdict
itself is computed from raw bytes and has no third-party dependency.
`cppscan.py` has no third-party dependency at all.
