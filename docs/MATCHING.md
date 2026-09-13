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
| `MATCH` | identical except at relocation fields that stayed wildcarded |
| `SIZE` | the compiler produced a different number of bytes |
| `DIFF` | same size, concrete bytes differ; a two-column diff is printed |
| `ISA` | the original is Thumb and the object is ARM, or the reverse |
| `CCERR` | the compiler rejected the translation unit |

The harness does the linker's job wherever it honestly can: it places the
compiled code at its target address and writes each relocation field itself,
so the comparison covers every byte and the verdict is `EXACT`. A site whose
target address cannot be attested independently keeps its wildcard, and an
entry with any such site is `MATCH` and prints why, per site. See
"Relocation resolution" below; that is where the interesting rule lives.

Wildcard widths, where a wildcard is still used, come from the object's own
relocation table rather than a heuristic: an `R_ARM_ABS32` blanks four bytes,
`R_ARM_PC24` the low three bytes of the word, a Thumb `BL` pair all four.
That is the same policy `libmatch.py` uses to pattern SDK library functions.

A trailing `*` on `EXACT` or `MATCH` means the comparison itself passed but
the size disagrees with the extent `disasm.py` inferred for the original.
The extent is the distance to the next `func_` label in the generated
listing, so a follower function that carries no label makes the extent run
long. No entry carries a `*` any more; the two that did are covered under
"The two missing labels" below.

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

## Relocation resolution

A compiler cannot know what address `sub_0201F41C` will end up at, so it
emits a zero word and a relocation, and the linker fills it in. Comparing
compiler output with a linked image therefore has a hole in it exactly where
the interesting cross-references are. The old harness wildcarded those
fields, which made every function that touches a global or calls out cap at
`MATCH`; six of the fourteen entries were stuck there and one of them was
stuck at `MATCH` while reproducing 112 bytes and seven functions.

`match.py` now resolves them. It places the object at its target address,
looks each relocation's target symbol up in a symbol map, and writes the
value the linker would have written:

* `R_ARM_ABS32`: the word becomes `(S + A) | T`, where `T` is the Thumb bit.
  That bit is why the original's pool word at 0x020084E0 is 0x0201F41**D**
  and the one at 0x020084F0 is 0x02045A3**8**: one target is Thumb, the other
  ARM, and the same C produces both.
* `R_ARM_THM_CALL` / `R_ARM_THM_XPC22`: the Thumb `BL` pair is encoded for
  the displacement, **and the instruction is rewritten to `BLX` when the
  target is ARM**. mwccarm always emits `BL` for a call to an extern, because
  it cannot see the callee's instruction set; picking `BLX` is the linker's
  decision and so it is made here. `BLX` word-aligns the PC before adding the
  displacement, which is the `(P + 4) & 3` term in the encoder and the reason
  the `blx` at 0x0200851A reproduces to the byte.
* `R_ARM_PC24` / `R_ARM_CALL` / `R_ARM_JUMP24`: the ARM branch displacement.
* anything else: left wildcarded rather than guessed at.

mwccarm writes `SHT_RELA`, so addends are explicit, and they carry the PC
bias (-4 for Thumb, -8 for ARM). The encoders use `X = (S + A) - P` straight
out of the ARM ELF ABI rather than re-adding a bias of their own.

### The honesty rule

The rule is one sentence: **a relocation may only be resolved when its target
address is attested by evidence outside the byte range under comparison.**

Without it the whole exercise is circular. The address of
`sub_0200575C_Table` is sitting right there in the pool word at 0x02005764,
but that pool word is part of what the comparison checks. Reading the answer
out of the bytes and then confirming that the bytes contain the answer is not
a test; it would pass for any address whatsoever, and it would turn `EXACT`
from a claim about the source into a tautology. So `match.py` records, for
every address it knows, *where in the image it learned it*, and discards any
witness that falls inside the range being compared.

Three classes of evidence are accepted, and every resolved site prints its
class, the number of witnesses and one witness address:

| class | what it means |
| --- | --- |
| `local` | the symbol is defined in the object we just compiled, so its address follows from where the unit was placed. No image evidence at all. |
| `label` | `disasm.py` put a `func_XXXXXXXX` label at that address, i.e. it traced real code there, **and** a branch somewhere else in the image calls that label. The strong class. |
| `literal` | the exact word appears in at least one literal pool at a different address. The weaker class, and the only one available for data. |

The `literal` class needs a word of justification, because it does read an
address out of the image. What it does not do is read it out of *this*
function. `sub_02005E50` loads 0x020AA260; eighteen other functions load the
same address from their own pools, at 0x02005B60, 0x02005BB8 and so on.
Those eighteen words establish that a data object lives at 0x020AA260
independently of the four bytes under test, and if the declared address were
wrong the comparison would fail rather than pass. Witnesses are restricted to
words at addresses `disasm.py` classified as literal pools, so the witness is
always a word some instruction demonstrably loads, not a stray coincidence in
a data blob. This matters for data because nothing else can ever attest it:
bss is not in the image, so 0x020AA260 will never have a label.

Addresses in `layout/symbols_sdk.txt` and `layout/matched.json` feed the map
by name as well, but they are *lookups*, not evidence: a name found there
still has to clear `attest()` before anything is written.

All the evidence is read out of `asm/arm9/src/*.s` and `asm/arm9/src_itcm/*.s`,
which are generated and not committed. On a fresh clone, run
`python tools/disasm.py arm9 --split` before `match.py`, or every site will
come back unresolved and every entry with a relocation will read `MATCH`.
`match.py` says so on stderr rather than failing.

Three behaviours are worth checking against, and all three hold:

```
declared address right   -> resolved, EXACT
declared address wrong   -> resolved, DIFF        (the check still bites)
declared address unknown -> unresolved, MATCH     (with the reason printed)
```

The middle line is the point. Resolution does not make the comparison easier
to pass; it makes it cover four more bytes, and a wrong claim now fails
loudly where it used to be hidden under a wildcard.

### Where the addresses are written down

In the source file's header comment, as a `symbols:` block:

```c
/*
 * function: sub_0200590C
 * address:  0x0200590C
 * ...
 * symbols:
 *   sub_0200590C_Cur    0x020AA1AC  data
 *   sub_0200590C_Table  0x020AA1B8  data
 */
```

Three columns: the identifier as the C source spells it, its address, and
`thumb` / `arm` / `data`. This was chosen over encoding the address in the
identifier because it keeps names free to say what a thing *is*
(`cardi_common`, `sVramLcdcMask`) while still pinning the address, and
because it puts every external address a file depends on in one auditable
block instead of scattered through the declarations.

The naming convention still works as a fallback and needs no block: an extern
called `func_02045A38` or `sub_02045A38` is taken to live at 0x02045A38, the
same convention the generated listings use. `unit_020084BC.c` was written
against that convention before any of this existed and resolved all six of
its relocations without a single edit to its code.

Either way the declaration is a *claim*. `attest()` is what decides whether
to believe it.

## The two missing labels

Two entries used to be `EXACT*`: the comparison passed but `disasm.py`'s
inferred extent for the original ran long, because the function immediately
after the one being matched carried no label and the extent is measured to
the next label.

Both followers turned out to be real functions that the analysis could not
reach, for the same two reasons:

* `disasm.py`'s prologue sweep only recognises prologues that save `lr`
  (`push {..., lr}`, `stmfd sp!, {..., lr}`, `str lr, [sp, #-4]!`). A leaf
  that saves nothing, or saves registers without `lr`, is invisible to it.
* the analysis runs one region at a time, so a function called only from an
  overlay is never named by any branch inside the ARM9 static module.

| address | what it is | why it was invisible |
| --- | --- | --- |
| 0x020084D4 | 16 bytes: shuffle `r0`..`r2`, load `func_0201F41C` from the pool, `bx r3`. An argument-swapping tail call. | no prologue at all; called from ov021 at 0x02193BA0 and 0x021CC026 and from ov135 |
| 0x020084E4 | the same shape, tail-calling the ARM `func_02045A38` | no prologue; called from ov088, ov116, ov120, ov128, ov175 |
| 0x0200A6F8 | 28 bytes: `push {r3, r4}`, then a loop storing zero into 32 bytes at offset 0x278 of the object. It clears the second of the two bitmaps `sub_0200A6BC` sets a bit in. | saves registers but not `lr`, because it calls nothing; called from ov133 at 0x021B62A2 |

Loosening the prologue rule to accept any `push` was rejected: it would fire
all over the data of a 3.9 MB image on the strength of one halfword, and
`validate()` is not a strong enough filter to carry that. Seeding from
cross-region branch targets is the sound general rule, but it needs a
whole-image pass that `disasm.py` does not have yet.

So the three addresses go in `layout/function_starts.txt`, a committed
override list `disasm.py` reads as extra seeds, one line each, naming the
instruction elsewhere in the image that attests the entry point:

```
arm9_main  0x020084D4  thumb   # bl from ov021 at 0x02193BA0 and 0x021CC026, ...
```

This is an escape hatch, not a licence to guess. An entry is fed through
`add_seed` like any other seed, so the trace and `validate()` still have to
accept the bytes as code: a wrong address changes nothing rather than
producing plausible nonsense. The regenerated listings reassemble
byte-identically, 5 of 5 regions.

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

| address | function | bytes | ISA | verdict | relocations | source |
| --- | --- | --- | --- | --- | --- | --- |
| 0x02075DD8 | `CARD_GetResultCode` | 20 | ARM | EXACT | 1 ABS32, `literal` x18 | `src/calib/card_getresultcode.c` |
| 0x02075DF8 | `CARD_GetOwnRomHeader` | 12 | ARM | EXACT | none | `src/calib/card_getownromheader.c` |
| 0x0207C958 | `FX_DivS32` | 60 | ARM | EXACT | none | `src/calib/fx_divs32.c` |
| 0x0207D41C | `GX_GetBankForLCDC` | 16 | ARM | EXACT | 1 ABS32, `literal` x4 | `src/calib/gx_getbankforlcdc.c` |

Two of the four have no relocations at all: one returns a constant address,
the other only touches hardware registers. The other two each hold a single
`R_ARM_ABS32` against a file-scope object, `cardi_common` at 0x02150200 and
`sVramLcdcMask` at 0x020A84BC; both were `MATCH` until those addresses were
declared and attested, and both are `EXACT` now.

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

| address | name | bytes | verdict | relocations | what it does |
| --- | --- | --- | --- | --- | --- |
| 0x0200575C | `sub_0200575C` | 12 | EXACT | 1 ABS32, `literal` x1 | pointer table lookup, unchecked index |
| 0x0200590C | `sub_0200590C` | 24 | EXACT | 2 ABS32, `literal` x14 and x12 | address of a member of a 0x1C-byte table entry |
| 0x02005E50 | `sub_02005E50` | 20 | EXACT | 1 ABS32, `literal` x18 | boolean test of a field of a global |
| 0x02006E2C | `sub_02006E2C` | 20 | EXACT | 1 ABS32, `literal` x5 | round a field up to a multiple of 32 |
| 0x020084BC | `sub_020084BC` | 24 | EXACT | none | are all eight halfwords zero |
| 0x02008534 | `sub_02008534` | 8 | EXACT | none | word field read back as a halfword |
| 0x0200A6BC | `sub_0200A6BC` | 60 | EXACT | none | set one bit in each of two parallel bitmaps |

`sub_02008954`, an eight-byte "byte field copied out through a pointer", used
to be an eighth entry here. It is now one of the twelve functions of
`unit_0200894C.c` and its per-function file has been deleted; a unit file
replaces the per-function files it subsumes.

and six whole translation units, matched as byte ranges rather than function
by function:

| address | unit | bytes | functions | verdict | relocations |
| --- | --- | --- | --- | --- | --- |
| 0x020084BC | `src/matched/unit_020084BC.c` | 112 | 7 | EXACT | 4 ABS32 + 2 THM_CALL, all resolved |
| 0x0200852C | `src/matched/unit_0200852C.c` | 78 | 16 | EXACT | none |
| 0x020085A0 | `src/matched/unit_020085A0.c` | 352 | 14 | EXACT | 4 THM_CALL to a compiler runtime helper, 1 ABS32, 2 THM_CALL, all resolved |
| 0x02008700 | `src/matched/unit_02008700.c` | 296 | 14 | EXACT | 15 THM_CALL + 1 ABS32, all resolved |
| 0x02008828 | `src/matched/unit_02008828.c` | 260 | 10 | EXACT | 4 THM_CALL + 1 ABS32, all resolved |
| 0x0200894C | `src/matched/unit_0200894C.c` | 92 | 12 | EXACT | none |

The last four are the milestone 3 batch and are described under "The
0x020085A0..0x020089A8 run" below.

The two abut: 0x020084BC + 112 is 0x0200852C. Together they are 190
contiguous bytes and 23 functions, with no gap and no overlap, and they are
almost certainly two halves of one original source file. They are kept as two
files because that is how they were found; both are EXACT, the first only
since its six relocations became resolvable.

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
It comes out **EXACT**, including all six of its relocations: four ABS32 pool
words, an interworking call the compiler emitted as `BL` and the linker turns
into `BLX`, and one `BL` internal to the unit. The two ranges abut, so 190
contiguous bytes and 23 consecutive functions of the original are now
accounted for by two source files.

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
* **The result is version-independent.** Both units are EXACT under all nine
  front ends at `-O4,p`.

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
  1.1 .. 1.6sp2      EXACT   D24    D24    D24    D24    D24    D32
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

The verdict was EXACT* for a while, because the function at 0x0200A6F8 opens
`push {r3, r4}` with no lr to save, so `disasm.py` did not label it and the
inferred extent for 0x0200A6BC ran 88 bytes to the next label at 0x0200A714.
That follower is now seeded from `layout/function_starts.txt` and the verdict
is a clean EXACT; see "The two missing labels" above. It is, fittingly, the
routine that clears the second of the two bitmaps this one sets a bit in.

## The 0x020085A0..0x020089A8 run

Four consecutive translation units, 48 functions and 1000 bytes, taken in one
pass to turn the 190-byte beachhead at 0x020084BC into a contiguous stretch.
What they cover, in address order:

| range | bytes | functions | what it is |
| --- | --- | --- | --- |
| 0x0200857C..0x020085A0 | 36 | 1 | the constructor of the play-time object. Near miss, see below |
| 0x020085A0..0x02008700 | 352 | 14 | `playtime.c`: the play-time counter and its calendar stamp |
| 0x02008700..0x02008828 | 296 | 14 | the save block with id 0x1B and its accessors |
| 0x02008828..0x0200892C | 260 | 10 | the save block with id 0x1C, first half |
| 0x0200892C..0x0200894C | 32 | 2 | two accessors on the same block. Near miss, see below |
| 0x0200894C..0x020089A8 | 92 | 12 | the same block, second half |

The file boundaries are not guesses. Each of the three blocks opens with a
four-byte function that returns its own size (0x68, 0x9C, and 0x658 for the one
after this run), and the size it returns is exactly what the constructor two
instructions later clears, so the seam between two of these files is visible in
the bytes. Every accessor in a block file reaches its object through the same
`sub_020071CC(sys, <id>)` call with the same constant id, and the id changes
exactly at the seam.

`playtime.c` is named by the image rather than inferred. The constructor at
0x0200857C loads 0x020A70B8 as an argument to the debug allocator at
0x02030734, and the bytes at 0x020A70B8 spell `playtime.c`; the string before
it is `mystatus.c`. That is the first original source file name this project
has recovered. The functions keep their `sub_<address>` names, because the file
identity is attested and the individual entry points are not.

### New compiler idioms

Six, in the order they cost time.

* **A compiler runtime helper is a named relocation and can be pinned like any
  other extern.** `a / b` on `u32` compiles to a call to `_u32_div_f`, and
  mwccarm leaves that as an undefined reference carrying exactly that name, so
  a `symbols:` line `_u32_div_f 0x0209C2B0 arm` resolves it. The address is
  attested as a `label` by 57 callers elsewhere in the image, so this is an
  ordinary attested lookup and not a special case. Without the line the four
  calls in `sub_020085D4` are wildcards and the unit caps at `MATCH`; with it
  the unit is `EXACT`. Any function doing integer division needs this.
* **`a / b` and `a % b` on the same operands are two calls, not one.** The
  helper returns the quotient in `r0` and the remainder in `r1`, and the
  original visibly calls it twice in a row with identical arguments. Common
  subexpression elimination does not touch a call, so writing the division once
  into a temporary and deriving the remainder from it is a different function.
* **Locals are laid out with the later declaration at the lower stack
  address.** `sub_02008658` puts a 0x10-byte `RTCDate` at `sp+0xC` and a
  0xC-byte `RTCTime` at `sp+0`. Declaring the date first and the time second
  produces that; the other order puts the date at `sp+0` and the function is
  seven bytes wrong in the stack offsets and nothing else. This is a one-line
  fix that is invisible unless the diff is read as offsets rather than as code.
* **An aggregate assignment of up to about 32 bytes is inlined as ldm/stm.**
  `obj->unk04 = src->unk20` on a 0x20-byte struct is four `ldm`/`stm` pairs and
  no call, and 28 bytes comes out as three pairs plus a trailing `ldr`/`str`.
  The size used is the padded `sizeof`, not the sum of the declared members.
  The practical consequence is the reverse reading: a run of `ldm rX!, {r0, r1}`
  / `stm rY!, {r0, r1}` in the middle of field-by-field moves says that those
  particular bytes are one nested struct in the source, and getting that
  grouping wrong changes the whole function rather than one instruction.
* **`ldrsh` with a register offset is a signedness tell.** Thumb `ldrsh` has no
  immediate-offset form, so a signed halfword field past the reach of the other
  loads costs an extra `movs rN, #imm` and a register-offset load, sitting in a
  function where every neighbouring read is a plain immediate `ldrh`. In
  `sub_020088B8` that one instruction is the only evidence that the field at
  +0x98 is `s16` and the ones on either side of it are not.
* **The reach of the Thumb immediate decides whether a field access costs an
  `adds`.** `str`/`ldr` scale a 5-bit immediate by 4 and reach 124;
  `strh`/`ldrh` scale by 2 and stop at 62; `strb`/`ldrb` do not scale and stop
  at 31. So in `unit_0200894C.c` the word at +0x78 is one instruction and the
  halfword at +0x7C is two, with no difference in the source. Reading that
  `adds r0, #imm` as an offset computation in the source rather than as an
  encoding artefact invents a pointer variable that is not there.

### The two near misses in this run

Both are the same failure and it is not a codegen failure: every concrete byte
is reproduced and the verdict is `MATCH`, held there by a relocation whose
target address cannot be attested from outside the bytes under test. This is
the honesty rule doing its job, and it is a real ceiling rather than a bug.

**0x0200857C, 36 bytes, `playtime.c`'s constructor.** Written as

```c
void *sub_0200857C(u32 heap)
{
    struct PlayTime *p = sub_02030734(heap, 8, 1, sub_0200857C_File, 32);
    sub_020085A0(p);
    return p;
}
```

it is `MATCH` with all 36 bytes right and one wildcard: the pool word holding
0x020A70B8, the `playtime.c` string. Both calls resolve. The string does not,
because 0x020A70B8 appears in exactly one literal pool in the whole image and
that pool is this function's own, so `attest()` discards its only witness. The
`literal` class needs a witness at a different address and there is none.

Writing the string as `__FILE__`, which is almost certainly what the original
said, does not help and makes it worse: the compiler then emits the string into
this object's own `.rodata` and relocates against a local symbol, and `tu` lays
out only executable sections, so the pool word would be filled with an address
that has nothing to do with 0x020A70B8.

There is honest evidence available that the harness cannot currently use.
Strings are packed end to end and `mystatus.c` ends with its NUL at 0x020A70B6,
so `playtime.c` begins at 0x020A70B8 by construction from the data, entirely
independently of the pool word. A `string` attestation class, admitting the
address of a NUL-terminated printable run whose start follows from the run
before it, would resolve this and every other `__FILE__` argument in the image,
of which there are many. That is a change to `attest()` and is left for a
separate piece of work rather than smuggled in here.

**0x0200892C and 0x0200893C, 32 bytes, two accessors on the id 0x1C block.**
One calls 0x02014468 and the other tail-calls 0x02014464 through a pool word.
These two sites are the only references to either address anywhere the harness
looks: 0x02014468 is labelled in the listings, but the single `bl` that reaches
it is the one inside this range, and 0x02014464 carries no label at all. So
both targets fail `attest()` for want of an outside witness and the pair stays
at `MATCH`.

The consequence is structural rather than cosmetic. The functions sit in the
middle of an otherwise contiguous 384-byte file, so that file is committed as
two units, `unit_02008828.c` and `unit_0200894C.c`, with a 32-byte hole between
them that the build still takes from the assembly. Splitting a translation unit
around an unverifiable function is the right move: a unit is only worth
committing if the whole of it is `EXACT`, and `csrc.py` refuses anything less.

Neither near miss is a third consecutive failure: everything between them and
on both sides of them is `EXACT`.

## How C enters the build

`src/` is no longer inventory. `tools/build.py` compiles every entry of
`layout/matched.json` and puts the resulting bytes into the image it verifies
and packs, so the shipping ROM is built from the C wherever C exists and from
`asm/` everywhere else. `--no-c` builds pure assembly, which is what to reach
for when an assembly problem needs to be looked at without the compiler in
the way.

The bridge is `tools/csrc.py`. It imports the compiler invocation, the ELF
reader, the translation-unit layout and the relocation resolver from
`match.py` rather than restating any of them, so there is one implementation
of each and the rules that decide `EXACT` are literally the rules that decide
what ships. Per entry it:

1. reads the compiler version, optimisation flags, language and instruction
   set back out of the manifest, so the build compiles the configuration the
   entry was *verified* under rather than a default;
2. calls `match.run_one` for a function entry or `match.run_tu` for a unit,
   which compiles, extracts or lays out, and resolves every relocation at the
   entry's real address;
3. refuses anything that is not `EXACT`, and refuses an `EXACT` that still
   carries a wildcard byte, because a byte a relocation left undetermined is
   not a byte the source produced;
4. hands `build.py` a `(address, bytes)` splice.

`build.py` assembles and links the region as before and then overwrites those
ranges. Splicing at function granularity falls out of this for free: an entry
covering seven functions in the middle of a 0x5000-byte assembly translation
unit replaces exactly those 112 bytes and the rest of the unit stays
assembly.

**A regression fails the build.** If a matched C file stops reproducing its
range, `build.py` prints the same two-column diff `match.py` prints and exits
non-zero. It never falls back to the assembly for that range. A silent
fallback would mean the ROM still verifies while the C in the tree is wrong,
which is the one failure mode worth engineering against here.

```
error: matched C source regression: unit_0200894C
       (src/matched/unit_0200894C.c) is DIFF at 0x0200894C, not EXACT;
       refusing to splice
  offset     ORIGINAL @ 0200894C                    | COMPILED
  ------------------------------------------------------------------------
    +0008    adds r0, #0x73                         | adds r0, #0x73
    +000A    ldrb r0, [r0]                          | ldrb r0, [r0]
  * +000C    strb r0, [r1]                          | adds r0, r0, #1
  * +000E    bx lr                                  | strb r0, [r1]
```

### Overlapping entries

`layout/matched.json` deliberately records both `sub_020084BC` and the unit
`unit_020084BC` that contains it, because both are documented results. For
the build only one of them may own a byte, so `csrc.py` keeps the widest
non-overlapping set and says which entries it dropped. A *partial* overlap
is not resolvable and is a hard error: it would mean the manifest describes
two different sources for the same bytes.

### Byte splicing, not linking, and why that is honest

The mechanism is a byte splice into the flat region image rather than an
object-level `mwld` link. That is sufficient because both sides are already
placed: the assembly is linked at the region's load address and each compiled
unit is laid out and relocated at its own address by the resolver `match.py`
already had to write. At that point the two are just bytes at known offsets.

It is also not the end state. A real link, feeding the C objects and the
assembly objects to one linker script, is what the project wants once whole
translation units line up with the assembly split and symbols are shared
rather than resolved per entry. Nothing here forecloses that: the placement
and relocation work a link needs is exactly what `csrc.py` drives today, and
the switch would move it from "resolve and splice" to "emit a linker input".
What the splice cannot do, and a link would, is let the C define a symbol the
assembly refers to by name: today the assembly still carries its own encoding
of every call, and the C has to be byte-identical for the image to come out
right, which the `EXACT` requirement guarantees.

### What is spliced today

15 entries, 1428 bytes: the seven matched game functions and six units above
(minus the two single-function entries their units subsume), and the four SDK
calibration functions. All 242 regions stay `PASS` with those bytes in place
and the ROM still verifies at
`26ad0b9967aa279c4a266ee69f52b9b2332399a5`.

Coverage of the 0x02005000..0x0200B000 window the milestone 3 batch worked in:
1326 bytes of the 17978 bytes the listings classify as instructions there are
now produced by C, 7.4%, in one 908-byte contiguous stretch
(0x020085A0..0x0200892C), one 92-byte stretch, the earlier 190-byte pair of
units at 0x020084BC, and five single functions.

```
python tools/csrc.py              # what the build would splice, and from where
python tools/build.py --split --pack
python tools/build.py --no-c      # the same, pure assembly
```

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
python tools/match.py tu --src src/matched/unit_020085A0.c \
    --addr 0x020085A0 --thumb
python tools/match.py tu --src src/matched/unit_02008700.c \
    --addr 0x02008700 --thumb
python tools/match.py tu --src src/matched/unit_02008828.c \
    --addr 0x02008828 --thumb
python tools/match.py tu --src src/matched/unit_0200894C.c \
    --addr 0x0200894C --thumb

# the language evidence
python tools/cppscan.py all --regions all --isa thumb
python tools/cppscan.py runtime --cc 1.1p1

# the listings the symbol map is read from, and the proof they still
# reassemble to the original bytes after the function_starts.txt additions
python tools/disasm.py arm9 --split
python tools/build.py --split --only arm9
```

`match.py` needs `capstone` for the diff and `show` output only; the verdict
itself is computed from raw bytes and has no third-party dependency.
`cppscan.py` has no third-party dependency at all.
