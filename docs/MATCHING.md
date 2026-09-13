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

Seven functions from `asm/arm9/src/`, none of them in
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

## What the sweep says about the compiler

Every one of the seven game functions, and all four calibration functions,
produce **byte-identical code under all nine compiler versions** at
`-O4,p`. The matrices are flat:

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

* the **optimisation level is pinned**: `-O4,p` and only `-O4,p`.
  `sub_020084BC` separates it cleanly, matching at `-O4,p` and failing with
  24 differing bytes at `-O4,s`, `-O4`, `-O3`, `-O2` and `-O1`. Every other
  matched function is indifferent between `-O4,p`, `-O4,s`, `-O4`, `-O3` and
  `-O2`, so it is the single discriminating function that carries this.
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

## C or C++

Open, and not decided by anything here.

* All eleven matched functions compile to identical bytes under `-lang c99`
  and `-lang c++`. Nothing in them distinguishes the two languages, so they
  are no evidence either way. (`match.py` demangles both the Itanium-style
  `_Z<len><name>` that mwccarm 4.0 emits in C++ mode and the older
  CodeWarrior `name__<signature>` form, so `--func` still takes the source
  name.)
* No function examined so far shows a prologue or argument pattern that has
  to be a non-static member function. An implicit `this` in r0 and a C
  struct pointer in r0 are the same thing at this level.
* One piece of negative evidence is concrete. The static-initialiser
  machinery in the startup code is inert. `INITi_CallStaticInitializers` at
  0x02004DA0 walks only the list `INITi_ShelterStaticInitializer` builds, and
  that list is fed exclusively by the `static_init_start` arrays of the four
  autoload blocks. All four arrays are empty: the first words at 0x01FF8000,
  0x02FE0000, 0x02400000 and 0x06898000 are zero. So this ROM runs no global
  constructors at boot. That rules out C++ objects with dynamic
  initialisation at file scope in the ARM9; it does not rule out classes,
  methods or virtuals.

The overlays have not been looked at for this yet, and overlay 9 and 16
(which hold the networking stack) are the wrong place to look anyway. When a
game function turns up whose first argument is used in a way only a `this`
explains, `--cpp` is already wired into the sweep.

## A documented near miss

`0x0200A6BC` is 60 bytes and sets one bit in each of two byte arrays inside a
large structure, indexed by a value checked against 100. It reaches the right
size and the right first 20 bytes but not a match; the best attempt is 31
concrete bytes wrong, all of them in the tail, and the difference is register
allocation and scheduling around the two read-modify-write pairs rather than
anything structural. It is recorded here rather than committed because a
near miss in `src/matched/` would be misleading.

```c
typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct S { u8 pad[0x258]; u8 a[0x20]; u8 b[0x20]; };

void f(struct S *s, u32 n)
{
    if (n >= 100) { return; }
    {
        u8 sh  = (u8)((s32)n % 8);
        u8 idx = (u8)(n >> 3);
        u8 bit = (u8)(1 << sh);
        s->a[idx] |= bit;
        s->b[idx] |= bit;
    }
}
```

Three things this attempt did establish, each worth about ten minutes to the
next person:

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

# every matched function, recompiled and re-verified
python tools/match.py manifest --verify

# the matrix that pins -O4,p
python tools/match.py sweep --src src/matched/sub_020084BC.c \
    --func sub_020084BC --addr 0x020084BC --cpp
```

`match.py` needs `capstone` for the diff and `show` output only; the verdict
itself is computed from raw bytes and has no third-party dependency.
