# Function matching

A packet agent should start at `docs/AGENT-BRIEF.md`; come here only when the brief does not answer the question.

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
long. A `*` therefore only ever means an unlabelled follower, never a byte
difference; the first two cases are covered under "The two missing labels"
below, and `sub_0200F0CC` currently carries one (its follower at 0x0200F104
is a documented near miss, so the label will appear when that function is
matched). `manifest --verify` exits nonzero while any `*` entry exists,
which is a prompt to label the follower, not a build failure.

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

### The declared ISA of a call target is checked against the image

Because `BL` against `BLX` is decided from the `thumb` / `arm` tag on the
symbol's `symbols:` line, a wrong tag does not fail to resolve: it resolves to
the other instruction, and the entry comes out `DIFF` for a reason that has
nothing to do with the C. The tag is a claim about the image, so before a call
relocation is encoded `isa_evidence()` asks the image what is at the target:

1. a `func_XXXXXXXX` label in a generated listing, whose ISA is the one
   `disasm.py` traced there (`asm/arm9` first, then the overlays that hold the
   address);
2. an ARM linker veneer at the address, which is ARM by construction;
3. the per-symbol `thumb` flag of `layout/symbols_sdk.json`.

A disagreement is a bug in the source file rather than a matching result, so
`match.py` stops and names the symbol, the declared ISA and the evidence
instead of resolving. Where the image has nothing to say the declaration is
still trusted, and the per-site line says so (`declared thumb, no image
evidence for the ISA`) so that the unchecked claims are visible. The same code
path serves `one` and `tu`. `selftest` covers both directions of conflict and
the unevidenced case.

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

Ten classes of evidence are accepted, and every resolved site prints its
class, the number of witnesses and one witness address:

| class | what it means |
| --- | --- |
| `local` | the symbol is defined in the object we just compiled, so its address follows from where the unit was placed. No image evidence at all. |
| `matched` | an EXACT manifest entry covers the address: our own compiled proof, checked byte for byte against the original over a range that is not the one under test, says what lives there. The only class whose witness is not a reading of the image. |
| `label` | `disasm.py` put a `func_XXXXXXXX` label at that address, i.e. it traced real code there, **and** a branch somewhere in the image calls that label. The strong class. |
| `veneer` | the address holds an ARM linker veneer: a fixed twelve-byte (or eight-byte) encoding that loads a constant into `ip` or `pc` and branches to it, with the constant naming a known function. For a call the linker redirected through a stub, which nothing else can attest. |
| `literal` | the exact word appears in at least one literal pool at a different address. The weaker class, and the only one available for data. |
| `string` | the address is the start of a NUL-terminated ASCII string whose position is fixed by the terminator of the string before it. For `__FILE__` arguments, which nothing else can attest. |
| `runtime` | the address is listed in `layout/runtime_arm9.txt`, the curated identification of the mwccarm/MSL `runtime.a` routines (64-bit shift/multiply/divide, soft-float) linked in as hand-written ARM assembly that `disasm.py` never labels. The table entry, read from a file that is never part of any compared range, is the witness. ARM only. |
| `sdk` | the address is listed in `layout/symbols_sdk.json`, libmatch.py's signature-matcher recovery of the TwlSDK library symbol table — the same table `symbol_address()` already uses to resolve an SDK *name* to an address, now also trusted as a witness that a call or ABS32 *target* at that address is legitimate, the same evidentiary standing `runtime` has for `layout/runtime_arm9.txt`. Closes the case of a single-call leaf SDK wrapper (`DWC_GetCheckNintendoZoneWorkSize`, `PXI_InitFifo`) with no other caller or literal-pool reference anywhere in the image, where `label`/`literal`/`sole-ref` all have nothing to offer. Both ISAs are valid; the declared kind is checked against that symbol's own per-entry `thumb` flag. |
| `sole-ref` | the layout itself recognises what the address lands on, without a second referrer. Tried last of all. Four sub-kinds: `sole-ref/data` (an object *start* in a data section that the listings, the SDK symbol table, the file-anchor table or the `layout/data_objects.txt` map already carry, with the declared type's alignment satisfied); `sole-ref/code` (exactly a traced function start, respecting `.thumb_func`, or a recognised veneer); `sole-ref/string` (the start of a NUL-terminated printable run, even when the preceding object is a table rather than a string); `sole-ref/self` (the target is in a data section and the ROM word at the site already names it — relocation agreement is the proof). See "The sole-ref class" below. |
| `overlay_id` | an ABS32 data site whose declared value is an overlay index (`FS_OVERLAY_ID`), a small absolute no address-based class can reach. Three conditions, all required: the value is an overlay id listed in `layout/layout.json`; a pc-relative load in the function under test addresses exactly that site, decoded from the code so an unlabelled continuation word of a pool run counts; and the loaded value reaches the id register of a call to a known overlay loader (`OVERLAY_ID_CONSUMERS` in `match.py`), a call site that resolved on its own evidence. Tried after `sole-ref`. See "The overlay_id class" below. |

The `label` class reads branches from the whole image, not just from the region
being matched, and it reads labels from the whole image too. `func_02014468`
is called from exactly one place inside
`arm9_main`, and that call is inside the range under test, but `ov010` and
`ov020` each branch to it as well. Those are real instructions in the image, so
they are the same kind of evidence as an in-region `bl`; the only difference is
which generated file they are written in, and a leaf whose callers all live in
overlays is not less of a function for it. `disasm.py` cannot name a target it
cannot reach, so it emits the raw encoding with the target decoded in the
address comment, and `match.py` reads that:

```
.inst.w 0xF6B5FB9C   /* 0215ED2C  B5 F6 9C FB  bl 0x02014468  (outside this region) */
```

The 72 MB of overlay listings are scanned lazily, only after the ARM9 evidence
has already failed for an address, so the common path does not pay for it. Only
branch instructions feed this index. Pool words in overlays are deliberately
not admitted: `literal` is the weak class, its witness has to be a word
`disasm.py` classified as a literal pool, and widening it to 237 regions would
weaken it without closing anything.

#### Callees that live in an overlay

The index above answers "who calls this ARM9 address". The other direction,
"what is at this overlay address", used to have no answer at all: the `label`
class only ever looked at the ARM9 listings, so an ARM9 function that calls an
address inside an overlay could not attest the target and capped at `MATCH`.
0x0200A3D0 calls 0x021DFDB8 and is the case that raised it.

The rule is now the same rule with a wider index, and it has three parts, each
a separate refusal in `attest_overlay_label()`:

1. the address is inside at least one overlay region of `layout/layout.json`
   and **that overlay's own generated listing carries a `func_` label there**,
   so `disasm.py` traced real code at that address in that overlay;
2. the ISA the label records is the ISA the source declares. An overlay that
   decodes the address as Thumb is not evidence for an `arm` extern;
3. at least one branch anywhere in the image targets the address from outside
   the compared range, read from `image_call_sites()`, which unions the ARM9
   in-region branches, the cross-region branches of all 242 listings, and the
   in-region branches of whichever overlays hold the address.

Part 1 is the part that does work, because overlay address space is shared:
237 overlays are loaded into a handful of the same windows, so one address is
inside several of them and they disagree about what is there. 0x021DFDB8 is
inside seven overlays, and `ov093` has an instruction in the middle of a
function there, `ov119` a `movs`, `ov170` a data word and `ov228` an
eight-byte Thumb thunk. None of them labels it, so it is **not** attested and
0x0200A3D0 stays open. The rule reaches 430 of the 553 overlay-space branch
targets the cross-region index knows about, which is the measure of what it
buys; demanding a label is what keeps the other 123 out.

The scans are lazy and per region, so only the overlays that can hold the one
address being asked about are ever read.

#### The veneer class

`mwld` puts a stub in front of a call it will not encode directly, and fills
the caller's `R_ARM_ABS32` in with the stub's address rather than the callee's.
The stub is invisible to everything else: it has no register-saving prologue,
so `disasm.py`'s sweep never fires on it and the listing prints its twelve
bytes as data; and nothing in the image branches to it, because reaching it
through a pool word is the whole point of it.

```
02072788  E59FC000  ldr ip, [pc, #0]
0207278C  E12FFF1C  bx  ip
02072790  0208970C  .word SND_SetMasterVolume
```

The only two words in the 3.9 MB image that hold 0x02072788 are the two pool
words of `src/matched/unit_02005794.c`, which is the range under test, so
`label` has no label and `literal` discards its only witnesses. The stub
itself is the evidence, and it is read entirely from outside the compared
range, so the honesty rule is satisfied and a wrong claim still comes out
`DIFF` exactly as it does for `literal` and `string`.

Six conditions, each a separate refusal in `veneer_at()` and
`attest_veneer()`:

1. the declared kind is `arm`. A veneer body is ARM code; a claim that the
   address is Thumb or data is refused;
2. the address is four-aligned and inside a region;
3. the words there are one of exactly two encodings, compared whole and not
   masked: `E59FC000 E12FFF1C <ptr>` (`ldr ip, [pc, #0]; bx ip`) or
   `E51FF004 <ptr>` (`ldr pc, [pc, #-4]`);
4. `<ptr>` names code: with the Thumb bit stripped it is inside a region,
   aligned for the ISA its low bit declares, and it is either a `func_` label
   in that region's listing or a symbol of `layout/symbols_sdk.json`, with the
   same ISA. A stray triple of data words does not have a third word that
   names a known function, and this condition alone rejects 17 of the 116
   shape matches in `arm9_main`;
5. the veneer does not point at itself;
6. every byte of it, the pointer word included, lies outside the compared
   range.

**The Thumb shape is deliberately not recognised.** The linker emits
`ldr r3, [pc, #0]; bx r3; .word target` as well, and 0x021DFDB8 in `ov228` is
one, but mwccarm emits exactly those eight bytes for a Thumb tail call with no
argument set-up, and `src/matched/unit_02005C3C.c` is two committed instances
of it compiled from ordinary C. A shape both the linker and the compiler emit
carries no claim about what the address is. The ARM forms do: this front end
compiles an ARM tail call to a direct `b` with a relocation, and `ip` is the
procedure-call scratch register the ABI reserves for exactly this use.

`disasm.py` labels the recognised ones `veneer_02072788` in the listings, over
bytes that are still `UNK` or `DATA` after the trace has settled and only when
the pointer names code the trace already reached, so it adds a label and never
changes a classification. 59 of them are labelled in `arm9_main`, and a pool
word that loads one now reads

```
	.word	0x02072788                  /* 0200579C  -> veneer_02072788 */
```

How the C is written against one is
`docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md`:
the extern is declared at the veneer's address, marked `arm`, and the name
matches the listing's label.

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

Addresses in `layout/symbols_sdk.txt` and the `layout/matched/` shards feed the
map by name as well, but that lookup is not itself evidence: a name found
there still has to clear `attest()` before anything is written. What an
`EXACT` shard entry carries beyond the name is the subject of the next
section.

#### The sole-ref class

Approved after the wave-20 handoff, for the one shape `literal` and
`data_table` both leave stranded: a static object exactly one function
references, through one pool word, whose contents are not pointers.
`sub_0209E904_Tbl` in `src/pending/func_020213F8.c` is the canonical
instance — the pool word is inside the compared range, so `literal` discards
its only witness; the object is a run of `u16` pairs, so `data_table` refuses
it; and nothing branches to data, so `label` never applies. What the class
rests on is not a second reference but the **layout**: the delinked image's
own structure says something recognisable begins at that address, read
entirely from files that are never part of a compared range. It is the
weakest class in the set and is tried last of all, after every other class
has failed, so an address any stronger class can carry never reports as
`sole-ref`; and it stays falsifiable in the way `literal` and `string` are,
because the resolved word is still compared against the original and a wrong
declaration comes out `DIFF`.

**Widened 2026-09-21.** The owner decided to widen the class to the standard
other matching-decompilation projects use: the address the original pool
word names is accepted whenever it lands on something the layout
recognises, without requiring a second referrer. That is now four named
sub-kinds, each tried only after every stronger class has failed and each
recorded separately in the shard evidence so it can be listed or vetoed on
its own:

- **`sole-ref/data`** (`attest_sole_ref_data()`) is the original (wave-20)
  rule, unchanged. It **accepts** an address only when all three of (a) it
  is in a data section of `layout/layout.json` — a `.word`/`.byte`/`.ascii`
  datum in the listings, or a declared bss range — and neither in a code
  section nor inside any traced function's extent (an extent runs over
  contiguous instructions and ends at its last instruction's real length,
  the byte count the listing prints, so a Thumb function ending in a 2-byte
  instruction no longer swallows the datum after it); (b) it is the **start**
  of a known object, meaning a `pool_`/`veneer_`/`d_`/`g_`/`tbl_` label the
  listings carry at exactly that address, a data symbol of
  `layout/symbols_sdk.json`, a `__FILE__` anchor of
  `layout/file_anchors.txt`, or a `.word`-run start `disasm.py` emitted as
  its own block; and (c) the alignment the site's declared type demands is
  satisfied (a fourth `symbols:` token, `a1`/`a2`/`a4`/`a8`/`a16`; a data
  extern with none is assumed to want four). It **refuses** an address
  merely interior to a labelled object — which is exactly why 0x0209E904
  above is still refused — an address in code, and a misaligned address.
- **`sole-ref/code`** (`attest_sole_ref_code()`) covers a code-kind site
  (`thumb` or `arm`) whose address is exactly a traced function start in the
  listings: a `func_`/`sub_` label, respecting the `.thumb_func` marker for
  ISA (the same `disasm.py` evidence the `label` class reads), or a
  recognised veneer (the same shape `veneer_at()` reads for the `veneer`
  class). It needs no branch from outside the range to reach it — that is
  exactly the case the `label` class cannot carry, a function pointer stored
  in a pool or a callee with a single caller. It **accepts** the address
  whenever it is a label start or veneer with the declared ISA; it
  **refuses** an address that is merely interior to a traced function (an
  offset that is not itself a label) and any kind but `thumb`/`arm`.
- **`sole-ref/code` for TWL labels** (`attest_sole_ref_twl_code()`, added
  2026-09-24) is the overlay form of `sole-ref/code` with the TWL listing as
  its only candidate, tried as the last fallback in `attest_sole_ref()`. It
  covers a call whose `symbols:` line carries the fourth token `twl`
  (`func_027300F0  0x027300F0  arm  twl`). It **accepts** the address when it
  lies inside the `twl` window of `layout/layout.json` and is exactly a
  `func_` label in `asm/twl/twl.s` with the declared ISA. That listing is
  disassembled from the decrypted TWL region, which `delink.py` writes only
  after verifying it byte for byte: the key matches its recorded SHA-1, the
  decrypted BLZ stream decodes with every byte consumed, and the clear tail
  agrees with the undecrypted file. No branch from outside the range is
  required, which is what separates it from the `twl` branch of `label`: it
  carries the DSi-only callees of `func_0206DC00` (0x027300F0 and
  0x0272FEF4), whose only call sites lie inside that function. It
  **refuses** an interior address or a pool word (neither is a label), the
  wrong ISA, a site with no hint or an `ovNNN` hint, an address outside the
  window (an ARM9 address named with `twl`), and everything when
  `asm/twl/twl.s` does not exist (no key).
- **`sole-ref/string`** (`attest_sole_ref_string()`) covers a `__FILE__`-style
  site whose address begins a NUL-terminated printable run in the listings,
  even when the preceding object is a table rather than a string, the case
  `docs/idioms/a-string-after-a-data-table-has-no-witness.md` documents
  ("mail.c", "wifilist.c"): each is preceded by a static table, so
  `attest_string()`'s condition that a real string terminator fix the start
  cannot fire, and each name is passed by exactly one function, so `literal`
  has no outside witness either. It **accepts** an address that begins a
  printable, NUL-terminated run of at least four characters, entirely inside
  a data section (never a traced function's extent) and outside the compared
  range. It **refuses** an address that is not itself a run **start** —
  merely an offset into a longer printable run, the string counterpart of
  `sole-ref/data`'s interior refusal — and any address inside a traced
  function's extent, so it never fires on code that happens to decode as
  text.
- **`sole-ref/self`** (`attest_sole_ref_self()`, added 2026-09-21) is the
  community standard itself, with nothing asked of the layout beyond "is
  this data". objdiff, decomp.dev and the pret projects treat a relocation
  site as matched when the relocation names the same address the original
  word names; there is no second-referrer requirement, and a file-local
  table used by exactly one function is the normal case, not a suspicious
  one. Two guards, and they are the whole sub-kind: **(a)** the target is in
  a data section — rodata, data or bss — and not inside any code extent, the
  same `in_data_section()` test `sole-ref/data` condition (a) uses, so a
  target inside a traced function's extent never qualifies and code targets
  keep their existing rules; and **(b)** the ROM word at the relocation site
  equals the word this resolution is about to write there. A byte-correct
  compile implies (b), but it is asserted explicitly at the site so the
  sub-kind states its own evidence rather than borrowing the comparison's; a
  site with no readable ROM word (bss, off-image) is refused. Rationale: the
  ROM word names the address, so relocation agreement *is* the proof, and
  the site stays falsifiable exactly as the others are — a wrong declaration
  names a different address, the words disagree, and the sub-kind refuses
  before the comparison ever runs.

Every site that rests on any sub-kind is recorded in the shard entry as
`evidence: {"sole-ref": ["<subkind>:0xADDRESS", ...]}`, e.g.
`"code:0x02067998"` (`sole_ref_sites()`), so `grep sole-ref layout/matched`
lists every entry that depends on the class and `tools/worklist.py
--summary` prints its share of coverage, broken down by sub-kind, on its own
lines under the coverage figure rather than folding it in. `attest_sole_ref()`
dispatches to the four sub-kind functions by `kind`; `match.py selftest`
covers each sub-kind's acceptance and refusals.

Condition (b) of `sole-ref/data`'s boundaries come from
`layout/data_objects.txt`, the ARM9 data-object map, which
`attest_sole_ref_data()` loads once (cached) and consults in addition to
the listings' own block structure. That block structure alone is far too
coarse to be useful: `disasm.py` emits the whole rodata tail
`0x0209D86C-0x020A8FE4` as ONE block, so exactly one address in 47 kB is a
start and every other reference into it is refused as interior. The map
recovers the real starts from four sources, all outside any compared range:
**pool**, a literal-pool word in any ARM9 unit listing (`asm/arm9/src*/*.s`)
or any overlay listing (`asm/overlays/*.s`) whose value lands in an ARM9
data section — the strongest, since an instruction stream loads that exact
address; **data-decl**, a `symbols:` line of kind `data` in a
`src/matched/*.c` whose entry is `EXACT`/`EXACT*` in a shard; **string**, a
NUL-terminated printable run whose start is fixed by the preceding
terminator; and **table-guess**, a clearly-labelled heuristic (a run in
which a fixed record stride repeats) that is written for a reader and is
**never** accepted as evidence by the class. Regenerate it with `python3
tools/datamap.py`; it carries addresses, kinds and referrer sites only, and
no game data. A `pool` row records its referrers in full, because **a lone
reference never contributes its own start**: when every referrer of a
candidate lies inside the range under test, the map refuses it, exactly as
`label` and `literal` discard a witness inside the compared range. That is
why 0x0209E904 remains refused for `src/pending/func_020213F8.c` — the only
pool word naming it image-wide is the one inside that function. The other
refusals (code section, misalignment, an address interior to or between
known starts) are unchanged, and `match.py selftest` covers the map cases
too: an overlay-only start accepted, a lone in-range referrer refused, an
address between two map starts refused.

### The matched class

The classes above all ask the same question of the original bytes: does
something **outside** the compared range say what lives at this address? There
is a sixth answer, and it is not in the image at all. For an address this
project has already matched, our own compiled proof says what lives there.

An `EXACT` manifest entry is the statement "this source file, compiled with
this configuration and placed at this address, reproduces the original bytes
there, relocation fields included". Reproducing the 1736 bytes of the function
at 0x02019388 is a far stronger claim about 0x02019388 than "some pool word
elsewhere in the image holds that number": it pins the entry point, its
instruction set and its whole body. So a call site whose target is covered by
an `EXACT` entry has a witness, and the witness is a compilation rather than a
byte of the range under test.

This is what closes the case the cut remedy cannot reach. When the only branch
to a callee is the one inside the function that needs it, no cut helps,
because the range cannot be made smaller than that function; but if the callee
is matched, nothing has to be cut at all. `func_02018DB4` is reached from
exactly one place in the ROM, the `bl` at 0x02017E2E, and
`src/matched/sub_02018DB4.c` is an `EXACT` entry, so
`src/matched/unit_02017E1C.c` resolves that site and is `EXACT` itself.

#### Why this is not circular

Two arguments, one for each way the circularity could come back.

**A witness may not be the range under test.** The entry being verified cannot
witness itself: that is exactly "read the answer out of the bytes and then
confirm the bytes contain the answer", the tautology the honesty rule exists
to refuse. The refusal is by **source file**, which covers both
`manifest --verify` re-checking a committed entry and a pending file that
names its own address.

**One-way dependence on an already-verified entry is sound.** Every entry in
the manifest was verified against the *original bytes*, over its own address
range, using evidence that never mentions the file under test: the manifest is
`EXACT`-only, and the parked files under `src/pending/` are deliberately out of
it, so no committed entry's verification could have consulted one. The
dependence therefore has a direction, from the file being promoted to entries
that already stood without it, and the graph of "who witnessed whom at the
moment of verification" is acyclic.

The symmetric case that arises later, when a promoted file becomes a witness
for an entry that once witnessed it, is not a tautology either, because
neither check is a lookup: each of the two is a byte comparison against the
original image over a range disjoint from the other's. A wrong address still
resolves to a wrong instruction and still comes out `DIFF`, which is the same
falsifiability `literal` and `string` rest on. What would be circular, and is
refused, is a range attesting itself.

The refusals are in `attest_matched()` and `matched_index()`:

1. the entry's kind is one the project verifies against game bytes: `game`,
   `game_unit` or `sdk_calibration`;
2. its status is `EXACT` or `EXACT*`. A `MATCH` entry proves nothing about a
   relocation target, since its own relocation fields are still wildcards, and
   is refused;
3. the address is the entry's own address, or one of the member function
   addresses its unit layout records in `function:`. A unit that reproduced
   264 bytes covering two functions attests both entry points, because the one
   byte comparison covered both;
4. the entry's source file is not the file under test;
5. the ISA is the entry's, and it has to be the ISA the source declares. An
   entry compiled `-thumb` is not evidence for an `arm` extern.

The class never applies to `data`: an entry attests the code it reproduced,
not an object one of its instructions happens to load. That is why the parked
files whose blocker is a private table (`sub_02013FA8.c`, `unit_02018790.c`
and the rest) are untouched by it.

Unlike every other class, `matched` ignores the compared range: its witness is
not a byte of the image, so there is no range for the witness to fall inside.
The file identity is what does the work instead, and eleven selftest cases pin
it, the self-reference and `MATCH`-status refusals included.

### The string class

A `__FILE__` argument to the debug allocator is a pointer into the packed
string area, and the address of one string there normally appears in exactly
one literal pool: the pool of the single function that passes it. That pool is
the range under comparison, so the `literal` class discards its only witness
and the entry caps at `MATCH` with every concrete byte right. That is what held
`playtime.c`'s constructor open.

The evidence the other classes cannot see is in the data rather than in any
instruction. Strings are emitted end to end, each NUL-terminated and the next
aligned up, so the **start** of a string is fixed by the **end** of the string
before it:

```
020A70AC  6D 79 73 74 61 74 75 73 2E 63 00 | 00 | 70 6C 61 79 ...
          m  y  s  t  a  t  u  s  .  c  \0  pad  p  l  a  y
                                       ^          ^
                                 terminator     0x020A70B8 follows
                                 at 020A70B6    by construction
```

That derivation reads only bytes outside the compared range, so it satisfies
the honesty rule, and it is not circular: it never touches the pool word whose
value it is about to check. What it establishes is that 0x020A70B8 is a string
start, not that it is *the* string the source meant, exactly as `literal`
establishes that an object lives at an address without saying it is the right
one. A wrong claim still fails loudly, because the resolved word is then
compared against the original and comes out `DIFF`.

The rule is deliberately narrow. Every one of these has to hold, and each is a
separate refusal in `attest_string()`:

1. the declared kind is `data`; a string is not code,
2. the bytes at the address are at least four printable ASCII characters
   followed by a NUL, entirely inside one region,
3. immediately before it there are `k` NUL bytes with `1 <= k <= 12`: one
   terminator plus the padding after it, bounded as described under "the
   padding window" below,
4. the address is the **only** address in that padding window at which a
   string begins: every address strictly between the terminator and it is
   examined, and the rule refuses unless none of them starts a NUL-terminated
   printable run of at least four characters. Without this the previous
   terminator would fix a *range* of candidate starts rather than one address,
5. the bytes before those NULs are themselves at least four printable ASCII
   characters, so the NUL is a string terminator and not a zero word in a data
   blob,
6. no `func_` label falls anywhere in either string, so the rule is never run
   over code that happens to decode as text,
7. the whole witness neighbourhood lies outside the compared range.

The forward direction, a neighbouring string's *start*, adds nothing and is not
implemented: a string's own terminator already fixes its end, so only its start
needs an outside witness. The other route to that start, a reference from
outside the compared range, is the existing `literal` class and is tried first.

#### The padding window

Conditions 3 and 4 used to read `k <= 4` and "the first 4-aligned address after
the terminator", which is one terminator plus at most three bytes of alignment.
That refused 0x020A706C, which spells "box_savedata.c" and is the original
source file name of `src/matched/unit_020079BC.c`: the terminator of
"save_control.c" is at 0x020A7062, the next ten bytes are NUL, and the first
4-aligned address after the terminator is 0x020A7064 rather than 0x020A706C.
The function that passes it, `sub_02007AA4`, reproduced every concrete byte and
capped at `MATCH`, and that is why the file stopped one function short of the
end of its range.

The extra padding is real and it is not alignment. Measured over the whole ARM9
image, of the 404 string starts that have a well-formed string in front of them
the distribution of `k` is

```
k =  1   2   3   4   5   7  10
   265  47  40  47   2   2   1
```

and every `k > 4` sits at a 4-aligned address one or two whole words past the
one alignment alone would have chosen: the linker left one or two dead words
between two string sections. 10 is the largest run anywhere in the image, so
the bound is 12, the next multiple of four above it: a terminator, up to three
bytes of alignment, up to two dead words. A run of NULs longer than any the
string area actually contains is refused rather than walked across, which is
what the `ov009` case at 0x021A4618, with `k = 40`, checks.

Widening the window costs nothing in soundness as long as the address stays
uniquely determined, and that is what the new condition 4 checks directly
rather than by proxy: it is the property the old 4-alignment test was standing
in for. It is not vacuous. The nine bytes of padding in front of
"box_savedata.c" are not dead: 0x020A7068 is an **empty string**, and it is the
one the five assert calls in the same file pass. It is not a candidate start,
because it is not four printable characters, and 0x020A706C is the only address
in the run that is.

`python tools/match.py selftest` is the check. Its string cases are all
negative bar two: a witness inside the compared range is refused, a compared
range that merely touches the neighbouring terminator is refused, the middle of
a string is not a string start, the last character of one is not either, a code
address that decodes as text is refused, a zero blob is not a terminated
neighbour, the empty string inside a padding window is not a start, a NUL run
past the bound is refused, and the class never applies to a symbol declared
`thumb` or `arm`. The same command runs the three end-to-end behaviours below.

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

### The overlay_id class

`FS_OVERLAY_ID(name)` is an absolute linker symbol whose value is the
overlay's index in the y9 table, so a call that loads an overlay by name
carries an `R_ARM_ABS32` pool word holding a small integer (see
`docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md`). No
address-based class can attest it: 0x72 is not a location, nothing is traced
there, and the only pool word holding it is usually the one under comparison,
so `literal` discards its only witness and `sole-ref` finds nothing that
starts at 0x00000072.

What makes such a word an overlay id is what the code does with it, so the
class is a statement about the function under test. All three conditions
must hold, and each is a separate refusal in `attest_overlay_id()`:

1. **The value is a valid overlay index**: an `id` in the `overlays` array of
   `layout/layout.json` (237 entries, 0 to 236). The layout is the
   authority, never the ROM.
2. **The site is a real pool word of the function**: some pc-relative load in
   the function's own code (Thumb `ldr Rd, [pc, #imm]`, ARM
   `ldr Rd, [pc, #+-imm]`) addresses exactly that site. The load is decoded
   from the instruction bytes rather than read off a listing label, because
   the listings miss these words: a pool run gets a `pool_` label on its first
   word only (0x0200F228 and 0x0200F22C are unlabelled continuation words of
   `func_0200F17C`'s run), and some pools are printed as Thumb code or as
   unlabelled `.word` runs. The load instruction is a concrete byte of the
   comparison, so it is checked against the original like any other.
3. **The loaded value reaches a known overlay-loading call as the id
   argument**: walking forward from the load, the first call is to an entry
   of `OVERLAY_ID_CONSUMERS`, and the register that entry reads the id from
   still holds the loaded value. The walk follows register copies
   (`adds r0, r7, #0`, `mov`) and unconditional `b`, and refuses on a
   conditional branch, an instruction it does not model, a call to anything
   else, or more than `OVERLAY_ID_WALK` (24) steps. The bound is not evidence,
   only a stop for a `b` loop; it was 8 until 2026-09-27, when the ov010 main
   sequence (func_02155478) showed ids 10, 15 and 19 modelled steps from their
   calls, the record being filled field by field in between. The call itself (a `bl`/`blx`, or a pool
   word that a `bx Rm` jumps through) must have resolved on its own evidence,
   so the loader's identity is independently attested.

The loader table, with how each entry was verified:

| address | name | id register | verified by |
| --- | --- | --- | --- |
| 0x02079264 | `FS_LoadOverlay` | r1 | `layout/symbols_sdk.txt`; `FS_LoadOverlay(target, id)` |
| 0x020792B8 | `FS_UnloadOverlay` | r1 | `layout/symbols_sdk.txt`; `FS_UnloadOverlay(target, id)` |
| 0x02034AC4 | `sub_02034AC4` | r0 | `src/matched/sub_02034AC4.c`, passes it to `FS_LoadOverlay` |
| 0x02034A5C | `sub_02034A5C` | r0 | `src/matched/sub_02034A5C.c` and `sub_02034A3C.c`, reach `FS_UnloadOverlay(0, id)` |
| 0x02031538 | `func_02031538` | r0 | `src/matched/func_02031538.c` stores it at Proc+4; `src/matched/func_020315F0.c` loads and unloads that overlay |
| 0x020314F4 | `func_020314F4` | r1 | `src/matched/func_020314F4.c`, forwards r1 to `func_02031538` |
| 0x02031348 | `func_02031348` | r1 | `src/matched/func_02031348.c`, `ldr ip; bx ip` thunk to `func_020314F4` |
| 0x020312CC | `func_020312CC` | r0 | listing 0x020312CC..0x020312F0 (not matched): `mov r4, r0` ... `mov r1, r4; bl func_020314F4` |
| 0x020120B4 | `func_020120B4` | r1 | `src/matched/func_020120B4.c`, forwards r1 to `func_02031348` |
| 0x020124AC | `func_020124AC` | r1 | `src/matched/func_020124AC.c`, stores r1 and calls `func_02034AC4(r1)` |

The witness lies inside the compared range by construction, which the
honesty rule normally forbids. It is admissible for the reason `local` is:
the value is never read out of the word being checked. It comes from the
declaration, and the three conditions restrict what a declaration may say to
237 values fed to a loader's id parameter. A declaration with the wrong id
is still a valid index and still resolves, then comes out `DIFF` against the
original, exactly as a wrong `literal` does. A pooled small constant that
does not reach a loader (a size, a heap id, 0xED which is attested elsewhere
as a plain `literal`) is refused by condition 3 or never gets here.

### Where to cut a file: `--suggest-split`

The honesty rule refuses a witness inside the compared range, and when the only
callers of a helper are inside the file being matched, the remedy is not more
evidence, it is a smaller range:
`docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md`. Choosing the
cut by hand means listing every external reference of the proposed range and
counting its witnesses elsewhere in the image, which is what the attestation
indexes already know, so

```
python tools/match.py tu --src src/matched/unit_XXXXXXXX.c \
    --addr 0xXXXXXXXX --thumb --suggest-split
```

reports it. It **writes nothing**. It never edits a source, and a cut it calls
viable still has to be written and still has to come out `EXACT`; what it
establishes is the negative half, which is the expensive half to find by hand:
which cuts cannot work, and which function is over-constrained and has to be
left out.

Three things come out of it:

* **a witness census per site**: the target, how many witnesses exist image
  wide, how many of them are inside this range, and the first few addresses,
  so an unresolved site says at a glance whether it is short of evidence or
  merely short of a cut;
* **the viable cuts**, from a dynamic program over the unit's own function
  sections. A piece `[i, j)` is feasible when every relocation in it either
  targets a function inside the piece (the `local` class, which needs no
  evidence) or has a witness outside the piece. The two constraints pull
  against each other, and the program is what balances them: cutting a callee
  out of a range breaks a site that was fine, and keeping the only caller with
  the callee destroys the only witness there is. The answer minimises the
  number of functions left out first and the number of pieces second;
* **the neighbour option**: when an unresolved target is itself already
  matched, the entry and source file that hold it are named, because pulling
  that function across the boundary into this range would make the site
  `local`. That is the "re-cut a neighbouring matched unit" case.

`src/matched/unit_02005DF8.c` and `src/matched/unit_02005E30.c` are the first
pair this found. `func_02072F5C` is reached from exactly three `blx` sites in
the image, 0x02005E16 and 0x02005E22 in `sub_02005E04` and 0x02005E40 in
`sub_02005E30`; one range holding all three has no witness left and caps at
`MATCH`, and the cut between 0x02005E04 and 0x02005E30 leaves each file as the
other's witness. Both are `EXACT`.

#### The pairwise case across two files

Two units attesting each other needs no machinery, and the manifest already
handles it. `resolve_relocations()` sets the compared range to the one
translation unit being compiled and to nothing else, so a call site sitting in
a sibling file's range is simply *outside*, in exactly the way a call site in
an overlay is. The two files are separate compilations, separate manifest
entries and separate splices, and nothing about the pair is special except
that neither may contain both call sites.

`src/matched/unit_02008B08.c` and `src/matched/unit_02008B4C.c` are the
committed instance: `OS_GetOwnerRtcOffset` is reached from 0x02008B26 and
0x02008B7C and from nowhere else in the ROM, one in each file. So are
`unit_0200902C.c` and `unit_02009050.c` over `sub_02008F3C`, and now
`unit_02005DF8.c` and `unit_02005E30.c` over `func_02072F5C`. Two selftest
cases pin the behaviour: with the compared range set to one of the pair the
class is `label`, and with it set to the span of both there is no witness at
all.

The limit of the remedy is worth stating, because three of the open near
misses are on the wrong side of it. When the **only** witness for a target is
the call inside the very function that needs it, no cut helps: shrinking the
range to that one function keeps the call in it. `sub_02005DE4` is the only
caller of 0x02072E8C in the ROM, `sub_02005A98` the only caller of
0x02074A6C, and `sub_020057C4` the only caller of 0x02035108.

That used to mean "closes the day the image acquires a second caller and not
before". It no longer does, as long as the callee itself can be matched: the
`matched` class above needs no second caller and no cut, only an `EXACT` entry
covering the target. Seven parked files graduated on that alone. The three
addresses named here are still open because their targets are not matched.

### The near-miss backlog after the attestation wave

Wave 1 left thirteen documented near misses. The three new rules and the cut
finder close four of them; the rest are recorded here with the reason each one
stays open, so that nobody re-derives it.

Closed:

| address | bytes | what carried it |
| --- | --- | --- |
| 0x02005794..0x020057C4 | 48 | `veneer`: 0x02072788 is a linker stub in front of `SND_SetMasterVolume` |
| 0x02005DF8..0x02005E30 | 56 | cut: `func_02072F5C`'s other witness moved into the next file |
| 0x02005E30..0x02005E50 | 32 | the other half of the same cut |
| 0x02007AA4..0x02007AC8 | 36 | `string`: the padding window reaches "box_savedata.c" |

Still open, and the reason is the evidence rather than the C:

| address | why |
| --- | --- |
| 0x02005DE4 | only caller of 0x02072E8C in the ROM; the witness is the call itself |
| 0x02005A98 | only caller of 0x02074A6C |
| 0x020057C4 | only caller of 0x02035108, and needs 0x02005794 `local` as well |
| 0x02008AF0 | needs `sub_02008B9C` `local`, and any range that does spans both callers of `OS_GetOwnerRtcOffset` |
| 0x02009020 | needs `sub_02009074` `local`, and any range that does spans both callers of `sub_02008F3C` |
| 0x020090B4 | 0x020A7174 is named by one pool word, its own, and is a table rather than a string |
| 0x02008CF8 | 0x020A70C4 and 0x0209DDB4 are each named by one pool word, its own |
| 0x0200A3D0 | 0x021DFDB8 is inside seven overlays and none of them labels it (and two bytes are wrong regardless) |

Still open for codegen reasons, where the evidence was never the problem:
0x02008A54 (17 bytes of register allocation), 0x02008C28 (3 bytes of register
numbering), 0x020063B4 (64 bytes of block placement), 0x0200A908 (16 bytes of
scheduling), 0x0200B2A4 and 0x0200B37C (a register the original spends and the
source does not).

The one range where attestation stopped being the blocker without anything
being written is 0x02008D1C..0x02008E30: cut into two pieces of two functions
each, every one of its five callees keeps a witness outside. See the header of
`src/matched/unit_02008C58.c`.

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
to be an eighth entry here. It is now one of the twenty-four functions of
`unit_02008828.c` and its per-function file has been deleted; a unit file
replaces the per-function files it subsumes.

and five whole translation units, matched as byte ranges rather than function
by function:

| address | unit | bytes | functions | verdict | relocations |
| --- | --- | --- | --- | --- | --- |
| 0x020084BC | `src/matched/unit_020084BC.c` | 112 | 7 | EXACT | 4 ABS32 + 2 THM_CALL, all resolved |
| 0x0200852C | `src/matched/unit_0200852C.c` | 78 | 16 | EXACT | none |
| 0x0200857C | `src/matched/unit_0200857C.c` | 386 | 15 | EXACT | 7 THM_CALL + 3 ABS32, all resolved |
| 0x02008700 | `src/matched/unit_02008700.c` | 296 | 14 | EXACT | 15 THM_CALL + 1 ABS32, all resolved |
| 0x02008828 | `src/matched/unit_02008828.c` | 382 | 24 | EXACT | 5 THM_CALL + 2 ABS32, all resolved |

The last three are the milestone 3 batch and are described under "The
0x0200857C..0x020089A8 run" below.  Two of them used to be four: the
constructor of `playtime.c` and the pair at 0x0200892C were held out as near
misses, and closing both merged `unit_020085A0.c` and `unit_0200894C.c` into
their neighbours.

The two abut: 0x020084BC + 112 is 0x0200852C. Together they are 190
contiguous bytes and 23 functions, with no gap and no overlap, and they are
almost certainly two halves of one original source file. They are kept as two
files because that is how they were found; both are EXACT, the first only
since its six relocations became resolvable.

They do overlap the single-function entries at 0x020084BC and 0x02008534,
which are kept because they are the documented single-function results;
the manifest lists both, distinguished by `kind` (`game` against
`game_unit`).

Names are `sub_<address>` because the semantics are clear but the role in the
game is not; renaming them later is a mechanical change to one file and the
manifest. The inventory is the shard set under `layout/matched/`, regenerated
with `python tools/match.py manifest --verify`, which recompiles every entry
and records the verdict it actually gets rather than the one the header
claims.  See "The manifest is sharded" below.

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
  drop. The manifest therefore records `dsi/1.1p1`, but that is the
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

## The 0x0200857C..0x020089A8 run

Three consecutive translation units, 53 functions and 1068 bytes, taken in one
pass to turn the 190-byte beachhead at 0x020084BC into a contiguous stretch.
What they cover, in address order:

| range | bytes | functions | what it is |
| --- | --- | --- | --- |
| 0x0200857C..0x02008700 | 388 | 15 | `playtime.c`: its constructor, the play-time counter and the calendar stamp |
| 0x02008700..0x02008828 | 296 | 14 | the save block with id 0x1B and its accessors |
| 0x02008828..0x020089A8 | 384 | 24 | the save block with id 0x1C and its accessors |

It was five units for a while, split around two near misses; both are closed
and both files are whole again.  See "The two near misses in this run, both
closed" below.

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

### The two near misses in this run, both closed

Both were the same failure and neither was a codegen failure: every concrete
byte was reproduced and the verdict was `MATCH`, held there by a relocation
whose target address could not be attested from outside the bytes under test.
Both are `EXACT` now, and in each case what changed is the evidence the harness
can reach, not the C and not the rule.

**0x0200857C, 36 bytes, `playtime.c`'s constructor.** Written as

```c
void *sub_0200857C(u32 heap)
{
    struct PlayTime *p = sub_02030734(heap, sizeof(struct PlayTime), 1,
                                      sub_0200857C_File, 32);
    sub_020085A0(p);
    return p;
}
```

all 36 bytes were right and one word was a wildcard: the pool word holding
0x020A70B8, the `playtime.c` string. 0x020A70B8 appears in exactly one literal
pool in the whole image and that pool is this function's own, so `attest()`
discarded its only witness and the `literal` class had nothing left.

The `string` class closes it. `mystatus.c` ends with its NUL at 0x020A70B6, so
0x020A70B8 is where the next string has to begin, by construction from data
outside the compared range. See "The string class" above for the rule and its
seven conditions. The site now reads `[string x1, e.g. 020A70B6]`.

The constructor is the first function of `playtime.c`, so it is no longer a
file of its own: `src/matched/unit_020085A0.c` has become
`src/matched/unit_0200857C.c`, 386 bytes and 15 functions,
0x0200857C..0x02008700, which is the whole original file.

**0x0200892C and 0x0200893C, 32 bytes, two accessors on the id 0x1C block.**
One calls 0x02014468 and the other tail-calls 0x02014464 through a pool word,
and these two sites were the only references to either address anywhere the
harness looked. There is honest evidence for both, and it was in the overlays:

```
ov010 0x0215ED2C  bl 0x02014468        ov010 0x0215ED40  bl 0x02014464
ov020 0x02185A4E  bl 0x02014468        ov010 0x02164404  bl 0x02014464
```

Two changes make those reachable, and neither is a new class of evidence:

* `attest()` reads branches from the whole image rather than from `arm9` alone,
  which is what the `label` class always claimed to mean. See the honesty rule
  above.
* 0x02014464 carried no label, because it is four bytes with no prologue
  (`strb r1, [r0, #6]; bx lr`, the setter whose getter is the labelled
  0x02014468) and nothing inside `arm9_main` branches to it. It goes into
  `layout/function_starts.txt` naming the two `bl`s that attest it, exactly
  like the three addresses under "The two missing labels" above, and
  `disasm.py`'s trace and `validate()` still have to accept the bytes as code.
  They do; the listings reassemble byte-identically and the ARM9 function count
  goes from 5369 to 5370.

Both sites now read `[label x2]`. The 384-byte file is one unit again:
`src/matched/unit_02008828.c` covers 0x02008828..0x020089A8 and all 24 of its
functions, and `src/matched/unit_0200894C.c` is gone. It came out `EXACT` on
the first attempt with the two functions written as

```c
void sub_0200892C(struct Sub02008828Obj *obj, const void *src)
{
    obj->unk72 = sub_02014468(src);
}

void sub_0200893C(const struct Sub02008828Obj *obj, void *dest)
{
    sub_02014464(dest, obj->unk72);
}
```

What this does not change is the rule. Neither address is attested by anything
inside the range under test; both are attested by instructions elsewhere in the
image, which is what the rule asked for all along. A file that stays split
around an unverifiable function is still the right move when the evidence is
genuinely absent, because a unit is only worth committing if the whole of it is
`EXACT` and `csrc.py` refuses anything less.

## Compiler idioms

One file per idiom under `docs/idioms/`, so that two agents working different
packets never edit the same file. The index below is generated; regenerate it
with

```
python tools/match.py idioms          # rewrite the index
python tools/match.py idioms --check  # is it stale?
```

`docs/idioms/README.md` has the file format the generator expects.

<!-- idioms:begin -->

551 idioms, one file each under `docs/idioms/`.

- [A 4-byte-aligned out-header struct shifts its stack slot from the top of the frame](idioms/a-4-aligned-out-header-struct-shifts-its-frame-slot.md): when an out-parameter struct is only 2-aligned (every member is `u8` or `u16`) mwcc places it at the highest **2**-aligned offset, so it lands two bytes below the top of the frame in the *compiled* output; the original has it at the highest **4**-aligned offset. Giving the temporary struct a `u32` member (nothing else changes) pulls it back to the 4-aligned slot and the `add rN, sp, #0x..` / `ldrb rN, [sp, #0x..]` pair lines up.
- [A live `adc rd, zero, #0` after `adds` is the high word of a 64-bit add, not a 32-bit carry test](idioms/a-64-bit-add-high-word-is-adc-zero.md): `adds rA, rA, rB` / `adc rD, rz, #0` (with `rz` a hoisted zero) is produced by taking `(u32)(((u64)x + y) >> 32)`, i.e. the carry word of a 64-bit addition. The 32-bit overflow test `(x + y) < x` does **not** produce it.
- [A bitmask complement built from `eors` against -1 instead of `mvns` says the mask is 64 bit](idioms/a-64-bit-complement-is-eors-with-minus-one-not-mvns.md): mwccarm compiles `~x` on a 32 bit value to `mvns`, so a live `movs rN, #3` / `subs rN, rN, #4` / `eors` triple is the low half of a **64 bit** NOT whose high half was dead-code eliminated; the mask is a `long long` even where the field it is applied to is a `u32`, and spelling it `~mask` instead of `mask ^ -1` costs the whole function.
- [A 64-bit multiply-plus-add accumulates into the loaded addend's register only when the addend stays inline in the multiply's statement](idioms/a-64-bit-multiply-add-accumulates-into-the-addends-register.md): for `r = a * b + c` on 64-bit values, mwcc accumulates the low word into the register the addend came from when the addend is a dereference written inside the multiply's own statement and the result is stored back as one 64-bit store; with the addend in a named local, or with the two halves stored separately, the same expression accumulates into `ip` and the high half moves to a second scratch register, a five-instruction difference in register choice with identical lengths.
- [Clearing two adjacent 32-bit fields is a 64-bit zero store, not two 32-bit ones](idioms/a-64-bit-zero-store-picks-r2.md): Two adjacent 32-bit fields each assigned `0` make mwcc pick r1 for the zero; the same clear written as one 64-bit store (`*(unsigned long long *)&a = 0;`) picks r2, which is what some objects have.
- [A guard that returns a constant is predicated unless its exit block is shared](idioms/a-bare-constant-return-guard-is-predicated-unless-its-exit-is-shared.md): `if (c) return 0;` compiles to a conditional return (`movne r0, ip; popne {r3, pc}`) and never to a branch, so when the image shows a real `bne` into the function's shared failure exit, the guard has to be folded into that exit - the loop in the `==` arm and one `return 0;` after it - even though the early-return spelling is semantically identical.
- [A base pointer and the mask scratch of a read-modify-write can swap as an allocator tie](idioms/a-base-pointer-and-its-mask-scratch-swap-as-an-allocator-tie.md): when a short block computes `base = obj + off`, loads a halfword through it, masks that load with a constant for a compare, and ORs the constant back for the store, the register holding the base and the register holding the mask result are two scratch colours the allocator is free to swap. Every general source lever leaves the byte count identical; the tie recolours only the load sequence and is not movable from C.
- [A bitfield's base type shows up as a redundant truncation of the stored value](idioms/a-bitfields-base-type-shows-up-as-a-redundant-truncation-of-the-argument.md): a `u8`-based bitfield narrows the incoming value to eight bits before shifting it into place, even when the shift pair would discard those bits anyway; a `u32`-based bitfield of the same width and position does not, so one otherwise pointless `and rX, rX, #0xff` names the declared base type.
- [A `bl` target inside a function gets its own `func_` label and cuts the extent](idioms/a-bl-target-inside-a-function-cuts-its-extent.md): disasm.py labels every call target `func_XXXXXXXX`, including a call target that lies inside the function making the call. When a body uses a shared tail reached by `bl` (not only `b`), that tail is labelled, `target_extent` stops there, and `match.py show` reports the head as a fraction of its real size. The tail has no prologue and reads the head's registers; the two labels are one function.
- [A bool field set from a compare in if/else arms keeps the zero first, the relational form puts the one first](idioms/a-bool-field-set-from-a-compare-in-if-else-arms-keeps-the-zero-first.md): `mov rN, #0` ... `moveq rN, #1` then one `strb` is `if (f()) field = 0; else field = 1;`; writing the same store as `field = f() == 0;` gives `mov rN, #1` / `movne rN, #0`, a ternary `f() ? 0 : 1` materialises a second compare, and `if (f() == 0) field = 1; else field = 0;` keeps two stores. Only the zero-first if/else collapses to the image's pair.
- [A 0/1 argument passed to a call is the call written in each arm, not a value](idioms/a-boolean-argument-is-a-call-in-each-arm.md): When the original materialises a boolean argument for a call as `tst; beq .set1; movs r0,#0; b .end; .set1: movs r0,#1; .end: bl`, no value expression reproduces it. `(x & 3) == 0`, `(x & 3) == 0 ? 1 : 0`, `!(x & 3)`, an if/else assigning both polarities to a local, and a two-case switch with a call in each case all compile to the mirror `tst; bne .set0; movs r0,#1; b .end; .set0: movs r0,#0` — mwccarm canonicalises the value's true arm as the fall-through. The original orientation only comes back when the **call** is written in each arm and the optimiser tail-merges it:
- [A branch to a branch after a two-part test is a nested if with the call in all three arms](idioms/a-branch-to-a-branch-after-a-two-part-test-is-a-nested-if.md): when a 0/1 argument chosen by `a && b` compiles in the image to a `b` that lands on another `b` (the inner else hopping to the outer else), with the shared first argument loaded above each conditional branch, the source is a nested if/else whose three arms each call the function; `a && b` in one if/else, a ternary, a flag local or the test inside the argument list all thread the hop away and load the argument after the join.
- [A word assembled in r0 from four ldrb of one record is a 4-byte struct returned by value](idioms/a-byte-assembled-word-in-r0-is-a-small-struct-returned-by-value.md): four `ldrb` off one record pointer, shifted by 8/16/24 and `orrs`-ed into `r0`, loaded in the order byte 1, 0, 2, 3 with the pool constant at byte 1, is `return obj->table[i];` for a byte-aligned 4-byte struct. No shift/or expression reproduces its register allocation.
- [A byte compared through a `char *` object pointer is `ldrsb` unless read as `u8`](idioms/a-byte-compared-through-a-char-this-pointer-is-ldrsb-unless-cast-to-u8.md): with `-char signed`, `p[0x7f] != 0x30` on a `char *p` compiles to `movs r0, #0x7f; ldrsb r0, [p, r0]` (there is no immediate-offset `ldrsb`); the original's `adds r0, p, #0; adds r0, #0x7f; ldrb r0, [r0]` is `*(u8 *)(p + 0x7f)`, and keeping `char *p` for the stores is fine.
- [A byte count local preserves word spills and reloads](idioms/a-byte-count-local-preserves-word-spills-and-reloads.md): A count returned as `u8` can still occupy a word spill slot. Keeping the local `u8`, rather than widening it to `u32`, can restore an immediate reload of the spilled return value or change its slot order relative to another live integer without adding truncation instructions.
- [A byte kept live into a call argument register pushes its sign extension to a fresh register](idioms/a-byte-kept-live-into-a-call-argument-register-pushes-its-sign-extension-to-a-fresh-register.md): when a loaded byte is sign-extended into a different register (`ldrb r2, [..]; ...; lsls r3, r2, #24; asrs r3, r3, #24`) and nothing visible reads r2 afterwards, look for a later call that takes the byte as an argument in that same register. The value is already where the call wants it, so no `movs` appears, but the extra use keeps the byte live across the extension. That interference forces the extension, and the sum built from it, into a fresh register. Without the use, the extension happens in place, or the colouring rotates.
- [A byte local's signedness flips which callee-saved register it gets](idioms/a-byte-locals-signedness-flips-its-callee-saved-colour.md): when a small function differs from the image only by a swap of two callee-saved registers held by a byte local and a long-lived pointer, and every declaration order is flat, try changing the byte local from `unsigned char` to signed `char` (or the reverse) before calling it an allocator tie: 1.1p1 colours the two webs by the local's signedness, and one sign reproduces the vendor's pair on the nose.
- [A byte range guard with a decrement is tested inline, not through a u8 local](idioms/a-byte-range-guard-with-a-decrement-is-tested-inline-not-through-a-u8-local.md): `cmp r0,#0; beq X; subs r0,#1; lsls/lsrs #24; cmp r1,#0x18; blo` (the `subs` after the zero test) is `if (v == 0 || (u8)(v - 1) >= 0x18) t = 0x1f; else t = v - 1;`; a `u8 t = v - 1;` local ahead of the test hoists the `subs` above the zero compare.
- [A table of 3-byte records followed by an index array is a struct, not `u8 *` plus offsets](idioms/a-byte-record-table-with-a-trailing-index-array-is-a-struct-not-raw-offsets.md): `a[b*3+2]` and `a[0x12+v]` on a `u8 *` compile to a shifted-add plus a register-offset `ldrb`/`strb`; the original's `adds r2, r0, r2; ldrb r2,[r2,#2]` and `adds r0, r0, v; strb r1,[r0,#0x12]` come from `struct { Rec r[6]; u8 idx[6]; } *` with `a->r[b].c` and `a->idx[v]`.
- [A byte step added into a byte field is a narrow parameter](idioms/a-byte-step-added-into-a-byte-field-is-a-narrow-parameter.md): A wide step used only in byte additions can make mwcc hoist a signed-byte truncation onto the incoming step. Declaring the step s8 removes that extra shift pair.
- [A byte that is both a whole `u8` and a `{lo:7, hi:1}` split is a union, and its two writes stay two stores](idioms/a-byte-union-of-whole-and-split-bitfields-keeps-the-shift-pair-and-the-two-stores.md): to get the `lsls #24` / `lsrs #31` top-bit guard *and* the `bics r,#0x7f` then reload/`orrs r,#0x80` two-store sequence on one byte, the byte has to be declared as a union of the whole `u8` and a `struct { u8 lo:7; u8 hi:1; }`; plain masks, a signed test, or two whole-byte statements each lose one half of the shape.
- [A call-argument difference written as a local's initialiser takes a free argument register for the constant](idioms/a-call-argument-difference-folded-into-a-local-initialiser-takes-the-free-register-for-the-constant.md): `movs r1, #K; lsls r1, #n; subs r2, r0, r1` right after a call, feeding the third argument of the next call, is `int v = f(...) - K; g(a, b, v);`; writing `g(a, b, f(...) - K)` (or `v = f(...); g(a, b, v - K)`) builds the constant in r2 and copies the call result to r3 first, two bytes longer.
- [A call written before a goto into the shared tail is cross-jumped down to its bl](idioms/a-call-before-a-goto-into-the-shared-tail-is-cross-jumped-to-its-bl.md): when an arm of the original is only `mov r0, <arg>; b <tail>` and the tail begins with the `bl` of the same call that another path makes with a different argument, write the call in that arm followed by `goto` to a label placed after the other path's call; 1.1p1 cross-jumps the identical `bl` and keeps only the argument setup in the arm.
- [A call between a buffer handle and its first read keeps it in a register](idioms/a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register.md): a local `u32 p = (u32)buf;` holding a stack buffer's address is rematerialised (`add rX, sp, #0` at every use) when its first read follows the assignment with no call in between. A repeated constant (here the `0` passed five times) then takes the free callee-saved register instead. If a call lies between the assignment and the first read of `p`, mwcc keeps `p` as a register variable and the constant is rebuilt per call. Passing the buffer itself (`func(buf)`, not `func(p)`) to the first call after the assignment supplies that call without adding code: the address is still read from `p`'s register.
- [A call result narrowed in r0 and shifted into r1 is a `u8` local, not an inline cast](idioms/a-call-result-narrowed-before-a-u8-argument-is-a-u8-local-not-a-cast.md): when the image emits `lsls r0, r0, #24; lsrs r1, r0, #24` (narrow in r0, shift-copy into r1) for a call result that becomes the second argument of the next call, assign it to a `u8` local first; `f(b, (u8)g(k))` copies to r1 first (`adds r1, r0, #0; lsls r1; lsrs r1`) and is one instruction longer.
- [A call in a switch arm that sets up no arguments takes the already-loaded locals where they sit](idioms/a-call-that-sets-no-arguments-takes-the-loaded-locals-in-place.md): when locals loaded before a switch sit in r1/r2 (or the switch index sits in r1/r2/r3) and one arm calls with no argument moves at all, that call's parameters are those locals and the incoming r0; a callee declared without them keeps the locals in r0/r1 and misses.
- [A call to a function nested in a unit still needs an explicit symbols line](idioms/a-call-to-a-unit-nested-function-needs-an-explicit-symbols-line.md): match.py's name lookup (`matched_symbols()`) indexes only an entry's own name and address, never the nested `functions` list a `game_unit` entry carries, so `func_XXXXXXXX`-named calls to a unit member fail to resolve; the fix is an explicit `symbols:` line pinning the member at its address.
- [A `lsls #24/#16; lsrs` pair after a `bl` is a cast on a wide extern; a narrow extern emits none](idioms/a-callee-result-truncation-pair-is-a-cast-on-a-wide-extern-a-narrow-extern-emits-none.md): when the image truncates a call result right after the `bl` (`lsls r0,r0,#0x10; lsrs r0,r0,#0x10`, or `#0x18`) and your `u16`/`u8`-returning extern compiles with no such pair, declare the extern to return `u32`/`int` and write the cast at the call (`(u16)f(m)`, `(u8)g(a)`); conversely a result the image keeps raw (`adds r6, r0, #0`, no truncation, later stored with `strb`) wants the extern declared `u8` and the local `u8`, since a wide local makes the compiler spill and re-truncate it.
- [A cast local-array read hoists its base to entry; a pointer local CSEs the call argument too](idioms/a-cast-array-read-hoists-the-base-to-entry-a-pointer-local-cses-the-call-argument.md): when a stack array's base sits in a callee-saved register set at function entry (ahead of a parameter spill) yet one call still takes a fresh `add rN, sp, #k` for the same array, the reads go through a no-op cast, `((int *)ids)[i]`, not through a `p = ids` pointer local. The cast keeps the element address from folding into sp-relative form, so the compiler hoists the base to entry and reloads the element after each call; the plain `ids` call argument is a separate expression and is not commoned into the hoisted register.
- [A cast between two complements is what keeps both `mvn`s](idioms/a-cast-between-two-complements-is-what-keeps-both-mvns.md): `~(u32)~x` compiles to two live `mvn`s while `~n` with `n = ~x`, the inline-helper form and every arithmetic rewrite (`x ^ -1`, `-x - 1`, `0xffffffff - x`) all fold back to `x`; the intervening cast is the only thing that stops the double-negation fold, and the statement boundary that puts the first `mvn` before the surrounding `orr` is a separate lever.
- [A `(u8 *)` cast on an array-row argument keeps p + K as the loop invariant](idioms/a-cast-row-argument-keeps-struct-plus-offset-as-the-loop-invariant.md): an inlined bit helper called as `Reset(p->row[i], x)` (or `p->row[2]`) lets 1.1p1 reassociate the address as (p + x>>3) + K and keep K in a register; the same call with a redundant `(u8 *)` cast on the row keeps p + K as one operand, so p + K is hoisted out of the loop and indexed `[base, off]`, and p itself can then leave the register file.
- [A chained assignment stores the rightmost target first](idioms/a-chained-assignment-stores-the-rightmost-target-first.md): `a = b = x;` emits the store to `b` before the store to `a`, so when the image writes a field and then its backup copy, the source chain names the backup on the left (`ctx->fat_bak = ctx->fat = fat;`); the other order swaps the two stores and nothing else.
- [A redundant `char *` cast on the base pins the base-plus-index sum below the guard](idioms/a-char-cast-on-the-base-pins-the-base-plus-index-sum.md): a `base + i * K` address that the front end otherwise schedules ABOVE the guard branch (`ldr base` / `ldr v,[base,off]` / `add tmp,base,off` / `cmp v,#0` / `beq`, 7 instructions where 6 belong) is scheduled inside the guarded block once the same access spells the base through a `char *` cast - unsigned/`u8 *` arithmetic and `char *` arithmetic are two different DAG nodes to the scheduler, and only the second leaves the sum where the original has it.
- [A clear-then-set statement pair is what emits two stores per attribute field](idioms/a-clear-then-set-statement-pair-is-what-emits-two-stores-per-attribute-field.md): for a packed 16-bit attribute field, `f &= ~M; f |= v;` as two statements is what emits the original's two stores with a reload between them. The fused `f = (f & ~M) | v` emits one store per field, and the compound-assignment spelling can grow the whole function.
- [A `clz` in SDK output means a hand-written `asm` body, not an intrinsic](idioms/a-clz-means-a-hand-written-asm-body-not-an-intrinsic.md): dsi/1.1p1 maps no spelling of a count-leading-zeros intrinsic to the ARM `clz` instruction and never synthesises one from a loop, so a `clz` in an SDK object means the source was an `asm` function; calibrate the DWARF line table against a known `asm` file before deciding.
- [A `code` token in a `symbols:` line silently refuses the relocation](idioms/a-code-kind-symbols-token-is-not-arm.md): the third field of a `symbols:` line is the declared kind and must be `thumb`, `arm` or `data`; `code` is not recognised, so `read_header()` ends the `symbols:` block there and every later relocation reports "not in the symbols: block" and caps at `MATCH` however correct the C is.
- [The complement of a loop value is one hoisted `mvn` when spelled as `^ 0xFFFFFFFF`](idioms/a-complement-is-spelled-as-xor-minus-one-when-the-minus-one-hoists.md): `x = ~v;` inside a loop rematerialises `mvn r1, r0` at every iteration, while `x = v ^ 0xFFFFFFFF;` makes mwccarm keep the sentinel in a register and emit `eor` against it -- one extra instruction outside the loop but a byte-for-byte different loop body.
- [A compound add to a narrow parameter keeps the sum in its home register](idioms/a-compound-add-to-a-narrow-parameter-keeps-the-sum-in-its-home-register.md): `value += x;` on an s16 parameter in each arm keeps the narrowed sum in the parameter's callee-saved home and copies it into the argument register; `value = value + x;`, a fresh local or one expression lets 1.1p1 narrow straight into the argument register and elide the copy (four bytes short on ARM).
- [A compound assignment on a field flips the register pair of the guard above it](idioms/a-compound-assignment-on-a-field-flips-the-guards-register-pair.md): `p->f14 = p->f14 + 1;` and `p->f14 += 1;` compile to identical increment instructions, but the first form lands the two u16 loads of the *preceding* guard in the opposite r0/r1 pair and moves the `adds` that follows them, which is four concrete bytes in a four-instruction window; when an otherwise byte-perfect function is off by a handful of bytes inside its guard, try the compound spelling of a later store on the same field.
- [Thumb `movs r0,#0; mvns r0,r0; muls` is `x *= -1`, while `x = x * -1` folds to `rsbs`](idioms/a-compound-multiply-by-minus-one-keeps-the-mvns-muls-in-thumb.md): in Thumb, `*(int *)(s + 4) = *(int *)(s + 4) * -1;` compiles to `ldr; rsbs r0,r0,#0; str`, but the compound `*(int *)(s + 4) *= -1;` keeps a real multiply (`movs r0,#0; mvns r0,r0; muls r0,r1,r0`, or -1 CSE'd off an already-live 31 as `subs r4,#0x20`).
- [A conditional branch onto an unconditional b is a cross-jumped tail copy](idioms/a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md): when the image's conditional branch lands on a `b` whose own target is the real destination (a hop jump threading would have removed), the source wrote the shared tail out in that arm and the compiler cross-jumped the copy into a `b` after threading had already run. Falling into one shared label instead lets 1.1p1 thread the hop, and the branch target moves by one instruction.
- [A conditional self-assignment normalises a value in place; a boolean expression does not](idioms/a-conditional-self-assignment-normalises-in-place.md): mwccarm spells `x = x; if (x) x = 1;` as `cmp rX, #0; movne rX, #1`, leaving the zero case untouched, but spells the equivalent `x = x != 0` (or `x ? 1 : 0`) as a full 0/1 materialisation `cmp; movne; moveq`. The extra `moveq` is one instruction and four bytes.
- [A const parameter hoists field loads above a call result store into an address-taken local](idioms/a-const-parameter-hoists-field-loads-above-a-call-result-store-into-an-address-taken-local.md): `f(s, c, &y, &x); g(h, s->lo + (s->hi - s->lo) * (x = Div(x, y)) / 0x1000);` compiles with `str r_t, [sp]` (the store back to the address-taken x) before the two `ldrh` from s. When the original shows `ldrh lo; ldrh hi; str t, [sp]; subs`, declare the parameter `const S *s` (and give the callee that receives s a `const` parameter). `__restrict` on s, a const local copy of s, struct or array x/y, and a `restrict` pointer to x are all inert. Keep the assignment inside the multiply: as a separate `x = Div(x, y);` statement the loads still hoist but the call result moves from r3 to r2.
- [A const record pointer moves the outgoing stack store below the register copies](idioms/a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies.md): when a run of identical 5-argument calls differs only in that ours stores the stack argument (`str rN, [sp]`) before the last register copy (`adds r2, r5, #0`) in all but the final call, while the original copies first in every call, declare the pointer the in-between loads read through (`q[2]` feeding the argument-producing call) `const`. Same family as `a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md`, but the instruction that moves is the stack store, not the load.
- [A const source pointer hoists the last load of a struct copy into an address-taken local](idioms/a-const-source-pointer-hoists-the-last-load-of-a-struct-copy-into-an-address-taken-local.md): `Rect4 old = *r;` (four u16 fields) into a local whose address is later passed to a call compiles in source order, `ldrh; strh` x4. When the original pairs the last two loads (`ldrh r3,[r0,#4]; ldrh r0,[r0,#6]; strh r3; strh r0`), declare the source parameter `const Rect4 *r`. `__restrict` on r (or on a helper's destination) does not do it when the destination is a local; that lever only works when the destination is itself a `__restrict` parameter (see a-restrict-table-parameter-hoists-a-load-above-a-store-only-at-a-different-offset.md). Give the callee that receives r a `const` parameter rather than casting.
- [A `const` source pointer moves a field load up next to the call that precedes it](idioms/a-const-source-pointer-pulls-field-loads-up-next-to-the-call-result.md): when the only diff is scheduling (the original loads a field right after a `bl`, before copying r0 into the next argument register, and ours loads it after the stack-argument setup), declare the read-only record parameter `const T *`; the loads then schedule like the original with no other change.
- [A constant argument selected into a local if-converts where a call written in each arm does not](idioms/a-constant-argument-selected-into-a-local-if-converts-where-a-call-in-each-arm-does-not.md): `addr = cond ? WIN_A : WIN_B; G2x_SetBlendBrightness_(addr, ...)` is if-converted into `ldr`/`ldrne` and comes out eight bytes short, and the same select written as the whole call repeated in both arms keeps the `bne` / `ldr` / `b` / `ldr` join with one tail-merged `bl`, which is what the object has; the two forms also allocate registers differently, so the short one is not four bytes away from being a match.
- [A constant built as movs then adds or subs one is arithmetic on an enum local](idioms/a-constant-built-as-movs-then-adds-or-subs-one-is-an-enum-local.md): when the image builds a known value in two steps, `movs rN, #K` followed by `adds rN, #1` or `subs rN, #1` (with a `lsls/lsrs #0x18` pair if the result is narrowed), the source did the arithmetic on an enum-typed local. Every integer local folds the pair to a single `movs #K+1` / `movs #K-1`.
- [A constant compared from a register is a variable assigned in another switch arm](idioms/a-constant-compared-from-a-register-is-a-variable-assigned-in-another-arm.md): when the image does `mov rX, #imm; cmp rY, rX` for an immediate that fits the `cmp`, the source compares against a variable whose only assignment sits in another arm of the same state machine. The front end cannot fold it, so the back end rematerialises the constant at each use. A literal, an enum, a `static const` or an initialised local all fold to `cmp rY, #imm`.
- [A constant held in a register or frame slot after a switch join is a variable assigned the same value in every arm](idioms/a-constant-kept-in-a-register-after-a-switch-is-assigned-in-every-arm.md): when the image materialises a small constant once right after a switch's arms rejoin (`movs r0, #0x28; str r0, [sp, #0x14]`, `movs r6, #1`) and then reads it from that slot or register at every use, the source assigned it in each arm (`level = 40; flag = 1;` in both cases), and the compiler tail-merged the identical assignments to the join without folding the constant; one `level = 40;` after the switch is propagated and rematerialised at each use instead (229 concrete bytes out, 12 bytes short).
- [A constant loaded at entry into a callee-saved register is a declaration initialiser](idioms/a-constant-loaded-at-entry-into-a-callee-saved-register-is-a-declaration-initialiser.md): a `mov rN, #k` into a callee-saved register among the argument set-up of the first call, for a local that is only assigned on one path later, is that local's initialiser at declaration (`u16 x = k;`), not a hoisted constant.
- [A near-miss constant pair pools whichever one the code uses first, and only pointer arithmetic keeps the pair apart](idioms/a-constant-pair-pools-the-one-used-first-and-only-pointer-math-defeats-the-fold.md): two constants a small encodable distance apart cost one pool word plus an `add`/`sub`; the pooled one is whichever the *machine* code needs first, not whichever the source spells as the base, and every integer spelling of "base + delta" folds before the allocator ever sees the pair.
- [A constant kept in a callee-saved register and shifted in a merged tail is a statement repeated in each arm](idioms/a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md): when a large Thumb constant such as 0x2000 is built as `lsls rX, rK, #12` from a small value (`movs rK, #2`) held in a callee-saved register for the whole function, and the last use sits in a tail shared by both arms of an if, the source writes that statement in each arm. The compiler tail-merges the arms after it has pooled the small half of the constant, so the 2 stays live across every call.
- [A constant stored from r0 before its base is loaded is also the return value](idioms/a-constant-stored-from-r0-before-its-base-is-loaded-is-the-return-value.md): when `g->f = K` puts K in r0 before loading `g`, with the base in r1 or r2, the function returns K (`return g->f = K;` in an `int` function). A `void` store loads the base into r0 first.
- [A coordinate pair read from a copied local table by byte offset keeps the index in r1](idioms/a-coordinate-pair-read-from-a-copied-local-table-by-byte-offset-keeps-the-index-in-r1.md): when a loop copies x/y from a stack copy of a short-pair table into a create record, member access `t.pos[i].x` / `t.pos[i].y` gives the `i*4` temp r0 and the y address r1; the original's `i*4` in r1 and y in r0 come from reading the pair through byte offsets of the table.
- [A copy and a pointer step the image hoists above a call are written before it, and the call's address argument is re-expressed through the copy](idioms/a-copy-and-a-pointer-step-hoisted-above-a-call-are-written-before-it.md): when the image defines a local and steps a pointer *above* a call, the C has those two statements textually before the call and passes the address argument through the new local; written after the call, this compiler sinks both statements below it, and the difference cascades into a whole-block register rotation that no declaration order reaches.
- [A copy of the loop counter made before the loop label is a stored zero, not the counter](idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md): when a short store loop opens with `adds r1, rI, #0` one instruction before the loop label and stores r1 on every pass, the loop stores the constant 0 (`p->w[i] = 0;`), not `i`; mwcc reuses the counter's zero-initialised register for the constant and hoists the copy out of the loop. Read where the backward branch lands before deciding what the loop stores.
- [A counted loop written straight after its count leaves no separate guard: the pre-test folds to `cmp n, #0` and tail-merges with the exit epilogue](idioms/a-counted-loop-whose-only-entry-guard-is-the-pre-test.md): `n = f(); for (i = 0; i < n; i++)` with `i` known zero compiles to `cmp rN, #0` plus the function's own epilogue, so an explicit `if (n <= 0) return;` in front of the loop is a whole extra compare and branch; adding one also moves the loop's `i = 0`.
- [A counter initialized before a byte bound recolours the bound address](idioms/a-counter-initialized-before-a-byte-bound-recolours-the-bound-address.md): when a Thumb byte-index search matches except for the scratch register used to address and load a byte bound, assigning the counter before loading the bound can change that scratch register without adding instructions.
- [A counter stepped through a null pointer colours like a sign-extended one, at no cost](idioms/a-counter-stepped-through-a-null-pointer-colours-like-a-sign-extended-one.md): when a loop counter needs a lower allocation priority than the int webs around it (the image gives it a later callee-saved register) and only a sign-extending narrow type (`short i`) reproduces that ranking at the price of the extension instructions, keep `int i` and write the increment as `i = (int)((char *)0 + i + 1);`. It compiles to the same single `add`, but the loop-carried definition reaches the allocator as a pointer temporary, which ranks i the way the narrow type does.
- [Zero a loop counter before assigning an enum address base](idioms/a-counter-zero-before-an-enum-address-base-interleaves-the-base-shift.md): a Thumb loop whose enum address base emits `movs; lsls` can place the counter's zero between them when the counter is assigned before the base. Assigning the base first leaves its two instructions consecutive.
- [A cross-jumped tail reloads the base member, not the arm's hoisted pointer](idioms/a-cross-jumped-tail-reloads-the-base-member-not-the-hoisted-pointer.md): When a local pointer is hoisted before an if/else-if chain for the field accesses inside the arms, an arm whose argument expression follows a call must name the *base member* again, not the local pointer; otherwise the pointer is kept live across the call (callee-saved) and the whole function's register allocation drifts.
- [An overlay's Thumb call cannot be attested if the only label for its address lives in another overlay and is ARM](idioms/a-cross-overlay-thumb-call-to-an-address-labelled-arm-elsewhere.md): when an overlay `bl`s a Thumb routine whose only `func_` label image-wide is an ARM body in a different overlay, match.py refuses to resolve the site (`ISA conflict ... the image says arm`) and no header spelling fixes it: the call is a Thumb `bl` in the original but the resolver can only patch it to `blx`, so the function is a permanent DIFF unless the Thumb copy gets its own label or an EXACT entry.
- [A data-pair load hoisted into named locals before a clamp keeps the image's order](idioms/a-data-pair-load-hoisted-into-locals-before-a-clamp.md): when a call's arguments are two `u16` lookups into different tables plus a clamp on the fourth argument, 1.1p1 issues the `&locals` add and the clamp `cmp` *ahead* of the pair of `ldrh` and pairs each pool load with its own `ldrh` (base, use, base, use); binding both lookups to named locals **before** the clamp statement makes the compiler pool both bases first, issue both `ldrh` together and sink the `&locals` add to just before its store, which is the image's schedule.
- [A high-entropy data blob whose first word looks like a saved-lr prologue becomes a phantom `func_`](idioms/a-data-word-that-looks-like-a-saved-lr-prologue-becomes-a-phantom-function.md): `disasm.py` auto-labels a `func_` whenever the bytes at a `.word` boundary decode as a prologue that saves `lr`, so a certificate/string blob at the end of an overlay whose first data word happens to encode `push {..., lr}` is published as a real function and the worklist lists the whole blob as one ~20 kB `open` extent; the tell is that nothing in the image branches to or pools the address, and the "body" decodes to ASCII strings and certificate DER.
- [A semantically dead assignment in one switch arm cross-jumps its `break` onto another arm's body](idioms/a-dead-assignment-in-one-switch-arm-cross-jumps-its-break-onto-another.md): when two switch arms end by assigning the same constant to the same result variable, the compiler cross-jumps them, and the earlier arm's `break` then compiles to a branch onto the LATER arm's own copy of the assignment rather than onto the shared tail; the assignment can be semantically dead and you still cannot omit it, because omitting it moves that one branch target by two bytes and nothing else in the function changes.
- [A dead parameter reused as the index rotates the loop registers](idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md): When a byte index or cursor lands in the register of a parameter that is dead by then, the source reassigned that parameter (`start = start / 8;` or `start = idx + 1;`) rather than declaring a fresh local. A fresh local gets a new colour and rotates every register of the following loop (index, counter, constant) by one, a same-width permutation that no declaration order, type sweep or permuter run moves.
- [A dead second branch on the same flags is a nested if that tests the variable again](idioms/a-dead-repeated-branch-is-a-nested-retest.md): `cmp rN, #0; bne A; bne B` (the second branch can never be taken) comes from an inner test of the same variable inside the outer test's arm, such as `if (ret == 0) { if (ret != 0 || x == 1) break; }`; the flattened `if (ret == 0 && x == 1)` and the other nestings drop the second branch or point it at the wrong block.
- [A dead stack parameter reassigned to a local's address keeps a callee-saved register](idioms/a-dead-stack-parameter-reassigned-to-a-locals-address-keeps-a-callee-saved-register.md): When a stack-passed parameter is dead after its first use and the source reassigns it to the address of a local aggregate, the compiler keeps that address in a callee-saved register for the rest of the body. A fresh pointer local holding the same address is copy-propagated away and the address is rebuilt before each call.
- [A store into a stack local that the next statement overwrites is still emitted, and which value the second statement is computed from decides whether there are two stores or one](idioms/a-dead-store-to-a-spilled-local-survives-when-the-second-assignment-recomputes.md): `d = a; d = a + k;` over a spilled local emits both stores with the add in between and no reload, `d = a; d = d + k;` emits a reload, and `d = a + k;` emits one store; so a `str` immediately followed by an `adds` and a second `str` to the same slot is not an aggregate, not a `volatile` and not a missed optimisation, it is two ordinary statements whose second one recomputes from the source value rather than from the variable.
- [A declared struct local folds to sp-relative, a cast byte buffer keeps the pointer](idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md): when a stack scratch object's address is passed to a call and then read back, declaring it as the struct folds the read to `[sp, #off]` while declaring it as a byte array and casting keeps the read on the register that already holds the address; binding `&obj` to a pointer local does not change it, only the storage declaration does.
- [A defaulting wrapper spends one zero on both r3 and the stack word](idioms/a-defaulting-wrapper-spends-one-zero-on-r3-and-the-stack-word.md): a five-argument callee reached through a shorter entry point compiles to `push {r3, lr}` plus a single `mov r3, #0` that serves as both the fourth argument and the one outgoing stack word, so the push is the stack argument's home slot rather than a saved register; the same push followed by `ldr ip, [sp, #8]` is always a plain five-argument forwarder.
- [A small switch on dense case values dispatches first and lays the arms out after it; the equivalent if/else chain interleaves tests and bodies](idioms/a-dense-switch-dispatches-first-and-lays-the-arms-out-after.md): `switch (w) { case 3: ... case 4: ... case 5: ... }` with each arm an `if` that returns emits the whole compare chain first (`cmp #3 / beq`, `cmp #4 / beq`, `cmp #5 / beq`, `b default`) and then the three arm bodies in source order below it, while the same arms written as an `if`/`else if` chain emit each test immediately in front of its own body.
- [A derived wide local keeps the update before its first call](idioms/a-derived-wide-local-keeps-a-coordinate-update-before-its-first-call.md): when a wide parameter sum used by two later calls is updated in its callee-saved register before the first call, bind the sum to a fresh wide local; assigning back into the parameter can compute the first argument in a scratch register and delay the home-register update until the second use.
- [A divisor equal to a later table stride pools unless the quotient reuses an address-taken local](idioms/a-divisor-equal-to-a-table-stride-pools-unless-the-quotient-reuses-an-address-taken-local.md): when a `_u32_div_f` divisor equals the element stride of a table indexed after the call, 1.1p1 hoists the constant into a callee-saved register before the call (`movs r6, #0xc`) and reuses it for the `muls`; the image rematerialises it after the call. Writing the quotient back into the address-taken local it came from (`z = (z >> 3) / 12;` instead of a fresh `q`) removes the pooling, no other change.
- [A double boolean is what reproduces the image's second `cmp`/`movne`](idioms/a-double-boolean-reproduces-a-second-cmp-and-movne.md): when a comparison result is passed as an argument but the image materialises it twice (`cmp; movne #1; moveq #0` then `cmp #0; movne #1; moveq #0`), the source held the first result in a named local and then wrote `local != 0` again at the call; folding the two tests into one loses four instructions and twelve bytes. `_Bool` is not a keyword in this C99 front end, so writing the conversion explicitly is the only route.
- [Materialising a doubled loop index into the *other* loop's counter variable fixes both the `cmp` operand order and the register rotation](idioms/a-doubled-index-materialised-into-the-other-counter-fixes-cmp-order-and-colour.md): a 2-byte `cmp` operand-order residue and an 11-byte r4/r6 rotation in the same function are one problem, not two. The fix is a local holding `i * 2`, spelled with the SAME variable the next loop uses as its inner counter. Introducing the temporary in a spare variable gets you half the bytes; giving it the reused variable's name gets all of them.
- [A doubled loop entry guard is an explicit if in front of the for](idioms/a-doubled-loop-entry-guard-is-an-explicit-if-around-the-for.md): when the image tests a loop's entry condition twice in a row (`adds/bmi` then `cmp #0/blt`, or `cmp` then `cmpgt` on the same register), the source has an `if` with the loop condition in front of the loop. mwcc keeps both the `if` and its own rotation guard, and it does not merge them.
- [A duplicate `symbols:` line for one name shadows the right address](idioms/a-duplicate-symbols-line-for-one-name-shadows-the-right-address.md): two `symbols:` lines that give the SAME C identifier two different addresses leave every call site of that name resolving to whichever address the lookup index kept; when that address is contested across overlapping overlays the sites all go unresolved ("2 overlays overlap this address, none resolvable without a region hint"), and the fix is to delete the wrong line rather than add a hint. The vendor object shows which line is wrong.
- [A duplicated pool word is a second extern name for the same address](idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md): mwccarm emits one literal-pool word per (symbol, addend), so a pool that carries the same address twice in one function means the source named it through two different externs; one name makes 1.1p1 CSE both uses into a callee-saved register (and every 2.0 build share one word), two names give two independent pool loads.
- [Two short-lived pointer loads that cross neither a call nor a join can swap callee-saved and scratch as a front-end allocator tie](idioms/a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie.md): when a block loads two pointers from the same base, the first into a callee-saved register and the second into a scratch, and both die before the next call, the assignment is a graph-colouring tie rather than a live-range fact. Every general source lever (named locals, declaration order, statement order, inline-vs-local, init-at-declaration, compare polarity, declared widths) leaves the identical byte count, so the residue is the whole dependent tail and not the two loads. Record it; do not keep re-spelling.
- [A tail factored out after an if/else lets the compiler predicate the arms, writing it into both arms forbids it](idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md): the same statement after an if/else versus repeated inside both arms is not only a cross-jumping question, it decides whether mwccarm if-converts the arms at all; factored out, one-instruction arms become `addge`/`mlalt` and the function loses four bytes per branch pair, so a real `cmp`/`b<cond>` in the original means the arms were bigger than one statement in the source.
- [A field bound to a local is hoisted above an earlier store; reading the struct field in each statement keeps the original order](idioms/a-field-bound-to-a-local-is-hoisted-above-an-earlier-store-reading-it-twice-keeps-the-order.md): when the original stores one field (`str r0,[r4,#0x50]`) and only then loads another (`ldr r0,[r4,#0x48]`), or loads a bound into a scratch register after a branch (`ldr r2,[r0,#0x58]`) instead of keeping it in a callee-saved one, the source reads the struct field directly in each statement; binding it to a local (`t = q->f48;`, `lim = p->f58;`) makes mwcc hoist the load above the store and changes the register pair.
- [A field read from a table folds the field offset into the pool word, not into the load](idioms/a-field-read-from-a-table-folds-the-field-offset-into-the-pool-word.md): `&tbl[i].b` where `b` sits at +2 of a four-byte record is not `ldrh rD, [base + i*4 + 2]`; mwccarm puts the *base plus two* in the pool word and keeps `[rB, rI]`, so the pool word holds `tbl + 2` and not `tbl`. Reading the same bytes through a `u16[]` indexing trick gives the same instruction and the wrong pool word, which caps the function at MATCH forever.
- [A reload of a struct field right after a store to a sibling field cannot be forced](idioms/a-field-reload-after-a-sibling-store-cannot-be-forced.md): when the original re-loads a struct member immediately after storing to another member of the same struct, `-O4,p` forwards the stored value instead, and no C spelling tried recovers the extra `ldr`; expect to be exactly four bytes short and stop rather than grind.
- [A field spelled two ways is copy-propagated, not CSE-hoisted](idioms/a-field-spelled-two-ways-is-copy-propagated-not-cse-hoisted.md): Spelling a reused field once as a struct member and once as a raw offset prevents CSE from hoisting its load ahead of an independent index operand; copy propagation still supplies the later call argument.
- [A first field read through the object keeps a later subblock base apart](idioms/a-first-field-read-through-the-object-keeps-a-later-subblock-base-apart.md): When a function keeps `t = (Tail *)(q + K)` for later uses but originally loads the first index through `q + K + 4`, spell that early load through the object itself. Using `t->index` everywhere moves the subblock base setup early and removes the separate base-plus-offset loads.
- [A flag argument written as a ternary statement into a local keeps the other argument loads in source order](idioms/a-flag-argument-written-as-a-ternary-statement-keeps-left-to-right-argument-loads.md): mwcc evaluates a `field != 0` call argument before its simpler siblings, and copy-propagates a plain `flag = field != 0;` local straight back into the call. When the image loads the arguments left to right with the flag's branch in the middle, the flag is a ternary statement (`sh = field != 0 ? 1 : 0;`) into a local, with the earlier argument also in a local.
- [A flag bit at bit N of a word is a bitfield declared low bits first](idioms/a-flag-bit-in-a-word-is-a-bitfield-declared-low-bits-first.md): mwcc allocates bitfields from bit 0 upward, so a flag read as `lsls #(31-N); lsrs #31` (or written through a `bics`/`ands` with a pooled `~(1<<N)`) is `u32 lo:N; u32 f:1; u32 hi:31-N`, low padding declared first; MSB-first padding gives the mirrored shift.
- [A flag byte read as bit tests and set with bics/orrs is a bitfield struct cast over the byte pointer](idioms/a-flag-byte-in-a-byte-pointer-object-is-a-bitfield-struct-cast-over-it.md): When an object is addressed as a raw byte pointer and one byte of it is tested with `lsls #n; lsrs #0x1f` and set with `bics r,#1; orrs`, declare `typedef struct { u8 pad[OFF]; u8 a:1; u8 b:1; ... } B;` and write `((B *)p)->a = 1;` / `((B *)p)->b != 0`; the other fields stay raw offsets, and bit 0 is the first (least significant) field.
- [A flag dispatch four bytes short is the front end tail-merging the arms](idioms/a-flag-dispatch-four-bytes-short-is-the-front-end-tail-merging-the-arms.md): `if (flag) r = f(&A, &C, x, y); else r = f(&B, &C, x, y);` keeps both arms whole under `../2.0/sp2` and loses one `ldr rN,[pc]` under dsi/1.1p1; no spelling of the C reaches it, so the four missing bytes are a compiler question, not a source one.
- [A flag set after the call that consumes its input shares that input's register](idioms/a-flag-set-after-the-call-that-consumes-its-input-shares-that-inputs-register.md): `flag = 1; if (*f(t, 1) == 0) flag = 0;` gives the flag its own callee-saved register because `t` is still live at the `bl`; binding the call result first (`p = f(t, 1); flag = 1; if (*p == 0) flag = 0;`) lets the front end hoist the `movs` above the `bl` anyway and colours the flag with `t`'s register.
- [A flag ternary over enum constants keeps the bne-to-one polarity](idioms/a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md): `cmp rN, #0; bne L1; movs r0, #0; b end; L1: movs r0, #1` (zero on the fall-through) for a 0/1 local is `flag = e == 0 ? B_FALSE : B_TRUE;` with enum constants. Every int-constant spelling (`e != 0`, `!!e`, `e == 0 ? 0 : 1`, `if (e == 0) flag = 0; else flag = 1;`) is folded to a boolean first and comes out `beq L0; movs #1; b; L0: movs #0`. A flag built this way and tested at once (`...; cmp r0, #0; bne skip`) is `f = e == 0 ? B_TRUE : B_FALSE; if (f == B_FALSE)`.
- [A flag zeroed after a nested argument call frees a callee-saved register for a long-lived local](idioms/a-flag-zeroed-after-a-nested-argument-call-frees-a-callee-saved-register-for-a-long-lived-local.md): when the image zeroes a spilled flag (`movs r0, #0; str r0, [sp]; str r0, [sp, #N]`) only after an inner call that computes another argument of the same outer call, the source assigns the flag after that inner call (`k = inner(x); flag = 0; outer(..., k, ..., flag);`). Written as `flag = 0; outer(..., inner(x), ..., flag);` the zero is set before the inner call, the flag takes a callee-saved register, and a long-lived local elsewhere in the function is spilled, so the residue looks like a whole-body allocation wall.
- [A flat `a[row * 3 + i]` subscript is a shift-and-add, the `a[row][i]` spelling of the same 12 byte row is `muls`](idioms/a-flat-row-times-three-index-is-shift-and-add-a-two-dimensional-subscript-is-muls.md): indexing a `void *f[24]` member as `p->f[row * 3 + i]` emits `lsls rT, row, #1` / `adds row, row, rT` / `lsls row, row, #2` for the row base and keeps the member offset in the load immediate; declaring the member `void *f[8][3]` and writing `p->f[row][i]` emits `movs #0xC` / `muls` instead, and casting the member to `void **` moves the member offset into a separate `adds`.
- [A flattened copy of a pointed-to vector reads x and z into locals first](idioms/a-flattened-copy-of-a-pointed-vector-reads-x-and-z-into-locals-first.md): when a stack V is filled as `{pos->x, 0, pos->z}` and the image loads both pos fields before any store (and stores the zero y last), the source read `x = pos->x; z = pos->z;` into locals and then stored them; writing `m.x = pos->x; m.y = 0; m.z = pos->z;` in any order interleaves the loads with the stores and, in a function where pos lives long, gives pos a callee-saved register and spills another pointer instead (17 to 250 bytes out).
- [A float quotient computed three times behind an `_fgr` is the FX_F32_TO_FX32 macro](idioms/a-float-quotient-computed-three-times-behind-an-fgr-is-the-fx-f32-to-fx32-macro.md): `_fflt`/`_fdiv` run once for `_fgr(q, 0)`, then again in each arm before `_fmul(4096.0f, q)` and `_fadd(0.5f, ...)` / `_fsub(..., 0.5f)` and a shared `_ffix`: that is the SDK macro `FX_F32_TO_FX32(x)` with `x` an expression, pasted three times. Do not bind the quotient to a local.
- [A forwarded second argument keeps the indirect call target off r1](idioms/a-forwarded-second-argument-keeps-the-indirect-call-target-off-r1.md): For `return (*(T (*)(void *, int))((char *)p + 0x10))(p, a);` the compiler loads the function pointer into r2; the one-argument form loads it into r1 and is four bytes shorter than the original.
- [A forwarder that copies its stack argument has five parameters, not four](idioms/a-forwarder-that-copies-its-stack-argument-has-five-parameters.md): a small forwarder shaped `push {r3,r4,lr}; sub sp,#4; ldr r4,[sp,#0x10]; str r4,[sp]; bl` forwards five arguments; declaring only four makes the compiler drop the copy and emit a bare tail `bl`.
- [A call that leaves the incoming argument registers alone is a one-argument call, not a four-argument one](idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md): a `bl` at the top of a function with nothing between it and the prologue looks like it forwards all four parameters, and usually it forwards only the first; declaring the extra parameters keeps the caller's own arguments live across the call and reallocates every callee-saved register in the function, which reads as a scheduling problem twenty instructions later.
- [A four bit field in a byte container still needs the dword shift pair, and its signedness picks `lsrs` over `asrs`](idioms/a-four-bit-field-in-a-byte-needs-the-dword-shift-pair.md): `ldrb` followed by `lsls #28` / `lsrs #28` is an unsigned four bit bitfield in a byte; the same shifts written as a mask fold to `movs #0xf` / `ands`, and the same shifts on a plain `u8` pick `asrs` because the byte promotes to signed `int`.
- [A four byte ARM function inside a Thumb packet is a long branch veneer, and it cuts the translation unit in two](idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md): `ldr pc, [pc, #-4]` plus a pointer word, labelled by disasm.py as an ARM function in the middle of otherwise Thumb game code, is a linker stub for a call the Thumb `bl` could not reach; it is not compiled from any C, so no `tu` range may span it and the original file has to be matched as the pieces between the stubs.
- [A four-term `|` chain of shifts is emitted right-associated, and each pair's materialised operand is the right one](idioms/a-four-term-or-chain-is-right-associated-in-arm.md): in ARM, a chain like `v | (v<<4) | (v<<8) | (v<<12)` comes out as one bare `lsl` followed by three `orr`s with shifter operands, and reading the emission order back tells you the parenthesisation: the single `lsl` is the innermost pair's *second* operand, so the source is nested to the right and the two operands of each inner pair are the reverse of the order they appear in.
- [A variadic argument that costs no instruction is the value the guard compared](idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md): an assertion call whose r3 is never written is not passing three arguments with a leftover register, it is passing a fourth whose value the guard's own `cmp` already left in r3; declare the variadic tail one argument short and the value that should have gone to the stack lands in r3 instead.
- [A front end hoists a copy of a global base to fold a field load used as a call argument](idioms/a-front-end-hoists-a-base-copy-to-fold-an-argument-load.md): when a call's later argument is a global-array field load (`func(x, KEYSTR(i))`), one front end addresses the load off a scratch copy of the array base (`mov r0, base; ldr r1, [r0, i]`) and only then moves the first argument into r0, while the image addresses straight off the callee-saved base (`ldr r1, [base, i]`) and writes the first argument first. Binding the load to a named local, reordering the store/call, and taking an element pointer are all inert: the extra `mov` is the front end's choice of address register and no source spelling reaches it.
- [A full-word aggregate return kept as a scalar avoids an extra frame](idioms/a-full-word-aggregate-return-kept-as-a-scalar-avoids-an-extra-frame.md): When a four-byte aggregate getter returns the complete word in r0 and a restore function stores that unchanged word from r1, a proven scalar u32 interface can preserve the original register save while an aggregate local adds frame words.
- [A `func_` label can be the dead lead of a pool run, not a live function](idioms/a-function-label-can-be-a-dead-lead-past-earlier-pools.md): a `disasm.py` `func_` label whose first bytes happen to decode as a saved-`lr` prologue can be the dead lead of a preceding function's literal pool, so its extent is hundreds of bytes of `.word` data and no C ever matches; a 300+ byte extent with zero `bl`/`blx`/`[pc` in its body is a pool run, not an oversized function.
- [A global-base pointer colours above a plain loop index, and direct object access shifts it down one](idioms/a-global-base-pointer-colours-above-a-plain-loop-index.md): when a function caches the address of a global struct in a pointer local and also runs an indexed loop whose counter is live across the loop's call, the plain `int` loop index takes the lowest free callee-saved register and the base pointer is coloured one register higher; spelling the global as an object and accessing its fields directly (or a `#define` to `&obj`) frees the index's register and moves the base down exactly one. Neither form reaches the image when the image's base owns the very lowest register, because the index still outranks it.
- [A global pointer declared as an array loads into the pointer's own register, and `*g` does not](idioms/a-global-pointer-read-as-an-array-loads-into-the-pointer-register.md): for a relocation that is a global pointer to one word, `extern u32 g[];` read as `g[0]` makes mwccarm destroy the pointer register with the load and schedule the load before the argument saves, while `extern u32 *g;` read as `*g` picks a fresh destination register and delays the load until one is free; the two spellings emit the same instruction count in a different order, and only one of them is the original.
- [A global re-read across a call to a same-file static needs `volatile`](idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md): when the intervening call is to a `static` function defined in the same translation unit, this compiler can see that the callee never writes the global and keeps the first load live across the call; the original reloads it, which only reproduces by declaring the global `volatile`.
- [A global struct member is re-read, not cached in a local](idioms/a-global-struct-member-is-reread-not-cached-in-a-local.md): A module-global reached through a helper or a fixed base compiles differently if the source re-reads the member at every use instead of caching the pointer in a local; the image reloads the base after every call, and only the re-reading spelling reproduces the vendor allocation.
- [A shared `goto join` tail costs the parameter its register; repeat the call and the increment in each arm](idioms/a-goto-join-loses-the-registers-that-repeating-the-tail-in-each-arm-keeps.md): a switch whose arms all end in the same `call(ctx, r); (*st)++;` is spelled with that pair written out in every arm; a single `goto join` label lowers the use counts of `ctx` and `*st`, and the allocator then spills `ctx` and swaps the state and object pointers.
- [A guard load that folds into its dying base register is not a source shape](idioms/a-guard-load-that-folds-into-its-dying-base-register-is-not-a-source-shape.md): a load whose result is tested against 0 and then never used again (`if (g->task != 0) f(0);`) is written in the image as `ldr rN, [r0, #off]` / `cmp rN, #0`, with `rN` a register other than the base. Every spelling of the guard tried compiles the load into the base register it is loading through (`ldr r0, [r0, #off]` / `cmp r0, #0`), and the residue is exactly the register nibble of those two instructions. The tie is between the `tagMEMUSB *` base virtual register and the loaded value, and no source shape reaches the image form; record the residue instead of chasing it.
- [A test on a struct member is emitted even when the value stored in it is a constant](idioms/a-guard-on-a-struct-member-survives-constant-folding.md): mwccarm constant folds through a local scalar but not through a member of a local aggregate, so a live `tst`/`bics` pair on a value that a literal pool already holds is a guard the source really wrote, and rewriting it over a plain local silently folds it away and loses twelve bytes.
- [A guard on the parameter with its decremented copy computed after the call is `while (i-- != 0)` over a copy made before the call](idioms/a-guard-on-the-parameter-with-a-decremented-copy-after-the-call-is-a-while-post-decrement.md): when a downward u8 loop opens with a copy of the count parameter made before an intervening `bl` (`adds r4, r7, #0`), the `subs; lsls #24; lsrs #24` of that copy after the call, and an entry guard that tests the parameter (or its spill slot) rather than the copy, the C is `u8 i = n; x = f(...); while (i-- != 0) { ... p[i] ... }`; the explicit `i = n - 1; if (n != 0) do { ... } while (i-- != 0);` spelling folds the copy away or hoists the decrement above the call.
- [A guard read raw into its local and shifted later pushes the pointer off r0](idioms/a-guard-read-raw-into-its-local-and-shifted-later-pushes-the-pointer-off-r0.md): when a guarded block starts with `if (p->f != 0) { v = p->f >> 12; ...` and the image keeps the record pointer out of r0 (r0 holds the guard value and the header temporaries), read the field raw into the local before the guard (`v = p->f; if (v != 0) {`) and put `v >>= 12;` after some of the other header reads. The raw web then spans those reads and is coloured before the pointer.
- [A guard whose take branch is the function exit leaves a bare cmp before bx lr](idioms/a-guard-that-is-the-function-exit-leaves-a-bare-cmp.md): When a guard's body is the function's own return, the compiler folds the guard's branch onto the trailing `bx lr`; the condition's `cmp` survives with no branch after it. An equivalent value-returning ternary drops that `cmp` and comes out two bytes short.
- [A guard's value still sitting in r1 at the call is the callee's second argument](idioms/a-guard-value-still-in-r1-at-the-call-is-the-callees-second-argument.md): when a field load feeds a `cmp ... #0` guard and the *same* register is never reloaded before the guarded `bl`, the original call passes that value a second time - `f(block, p->f08)` - not `f(block)`. Writing the one-argument form does not just cost an argument: the compiler allocates the load into r0 (the call's first argument register) instead of r1, and six bytes differ.
- [A guard whose arm can carry the whole body is not predicated](idioms/a-guard-whose-arm-can-carry-the-body-is-not-predicated.md): `docs/idioms/an-arm-guard-block-of-five-instructions-or-fewer-is-predicated.md` says a five-instruction-or-shorter guard body is always predicated and a short `bx<cond> lr` in the original is unreachable; that is true of the *arm as written*, but not of the function, because moving the body into the arm pushes it past the threshold and restores the original's real branch at no cost.
- [A guard wrapper's two constants name the inner call's arity and the wrapper's return type](idioms/a-guard-wrappers-two-constants-name-the-arity-and-the-return.md): in a thin wrapper that sets a flag, calls one function and clears the flag again, the register each of the two constants lands in is the only evidence of the wrapper's own signature: `mov ip, #1` before the call says all four argument registers are live, so the wrapper forwards four parameters, and a constant after the call that avoids r0 says the wrapper returns the callee's result rather than discarding it; four bytes across two instructions, with a `void` one-parameter reading otherwise byte for byte right.
- [A halfword arithmetic update keeps a call result wide with explicit assignment](idioms/a-halfword-arithmetic-update-keeps-a-call-result-wide-with-explicit-assignment.md): Updating a `u16` through `*p = *p + f()` or `*p = *p * f()` keeps an unsigned word call result wide until `strh`. Compound `+=` or `*=` narrows the call result first with a redundant `lsls #16; lsrs #16` pair.
- [A halfword bit clear needs a spelled-out assignment for bics](idioms/a-halfword-bit-clear-needs-a-spelled-out-assignment-for-bics.md): `p->flags = p->flags & ~8` emits `movs #8; bics`, while `p->flags &= ~8` narrows the mask and emits a pooled `0xFFF7` and `ands`.
- [A halfword merged from two branches is re-truncated for a u16 parameter; one straight from ldrh is not](idioms/a-halfword-merged-from-two-branches-is-re-truncated-for-a-u16-parameter.md): an `lsls`/`lsrs #0x10` pair right before a call, just after an `ldrh` or a small constant that two branches feed, means the callee's parameter is `u16` and the merged value was an `int` (a ternary of two table loads, or an `int` local set in an if/else); a `u16` local set in the same if/else, or one `ldrh` passed directly, gets no pair.
- [A halfword OR update casts the whole expression, not the shifted operand](idioms/a-halfword-or-update-casts-the-whole-expression-not-the-shift.md): For a variable shifted bit ORed into a `u16`, `field = (u16)(field | (1 << index))` keeps the shift at int width until the final store. `field |= 1 << index` narrows the shifted operand first, adding a `lsls #16; lsrs #16` pair and changing instruction scheduling.
- [A returned halfword stored raw with a second strh is a one-halfword struct return](idioms/a-halfword-stored-raw-then-restored-is-a-one-halfword-struct-return.md): `bl` then `strh r0,[sp+N]` with no `lsls/asrs`, then a reload and a second `strh` at N+2, is the result of a callee declared to return a one-halfword struct (`typedef struct { u16 v; } W; W v = f(x);`), even when its own file says `s16`.
- [A hardware register write is the SDK inline with its enum parameters](idioms/a-hardware-register-write-is-the-sdk-inline-with-its-enum-parameters.md): A store to a 0x04xxxxxx display register, above all a read-modify-write whose constants stay unfolded or whose field extractions all happen before any shift, is an SDK `static inline` from `sdk/TwlSDK/include/nitro/gx/g2.h` or `gx_bgcnt.h`: copy the inline's body, its enum or BOOL parameters and its `volatile` register macro, and call it with the game's arguments; rewriting its effect by hand does not match.
- [A hoisted array base must be a named local written inside a guard before a do/while](idioms/a-hoisted-array-base-is-a-named-local-in-a-guarded-do-while.md): when a scan loop recomputes `p = base + i` and the image keeps `base` in a callee-saved register while the counter sits in `lr` and a third value in `ip`, the base is a **named** local (a compiler temporary goes to `ip`), and the `add` that materialises it lands **after** the loop-entry rotation guard only when the base is assigned inside an explicit `if (i < n) { base = ...; do { } while (i < n); }` gate. A plain `for` with the base assigned in front of it hoists the `add` above the guard and swaps the two lower registers.
- [A hoisted loop-invariant zero can steal the freshly-dead register the loop scratch wants, and no source shape moves it](idioms/a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register-from-the-scratch.md): when loop 1's index dies and loop 2 needs two short-lived values -- a loop-invariant constant (here the `k = 0` reset) and the arithmetic scratch -- the image may give the freshly-dead index register to the *scratch* and the other free register to the constant, while dsi/1.1p1 does the reverse. This is a genuine allocator tie that the usual rotation levers do not reach: it is not declaration order, statement order, a named zero, the `for` initialiser, an enum-typed zero, `const`, or the compound form.
- [A `push {r0,r1,r2,r3}` home area hides the real function start one word early](idioms/a-home-area-push-hides-the-real-function-start-one-word-early.md): when a function takes the address of a register parameter, its first instruction is the argument home-area push and its second is the ordinary callee-saved push; disasm.py labels the second one, so the listing's function start is four bytes too high and `match.py one` at that label reports an extent of 4 bytes.
- [A labelled function and the unlabelled `*p = k; return &d;` leaf behind it are one unit](idioms/a-labelled-function-and-the-unlabelled-store-and-return-address-leaf-behind-it-are-one-unit.md): an overlay extent that ends in `movs r1,#k; str r1,[r0]; ldr r0,[pc]; bx lr` plus a pool word is a second, unlabelled leaf (`int *f(int *p) { *p = k; return &d_X; }`); `tu` over the whole extent, with the leaf named on the `function:` line, gives EXACT and the leaf's data pool word resolves as sole-ref.
- [An ARM `ldr r1, [pc]; bx r1` stub to an even address is a hand-written SDK asm function](idioms/a-ldr-r1-bx-r1-stub-with-an-even-target-is-hand-written-sdk-asm.md): a compiled ARM tail call through a pool word spends ip, and a linker island would not be emitted for an ARM target in `b` range; an eight-byte `ldr r1, =f; bx r1` is an `asm void` body and matches written that way.
- [A literal multiply-then-divide in a pointer expression is what emits the signed-scale quartet](idioms/a-literal-multiply-then-divide-is-the-signed-scale-idiom.md): mwccarm compiles `idx * 32 / 4` to a five-instruction signed-scale sequence (`lsl #5`, `asr #1`, `add ..., lsr #30`, `add ..., asr #2`) that the algebraically identical `idx * 8` never produces -- `idx * 8` folds into a single `lsl #3` addressing operand. When the original scales an index by what looks like a power of two and still spends four instructions on it, the source is a byte offset divided by the element size, not a shift.
- [A live tail-call argument keeps r1 and moves the offset constant to r2](idioms/a-live-tail-call-argument-moves-the-offset-constant-to-r2.md): When a stored parameter is still live at the tail call, the compiler cannot reuse r1 for a large field offset and reaches for the pool scratch register r2 instead; dropping the forwarded argument frees r1 and changes only the register name, one instruction, and the whole function reads as DIFF.
- [A load the original schedules above an unrelated store is read through a const pointer](idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md): when the only residue is one load that the original issues before a store (to the outgoing-argument area, a global, or a struct copy's destination) and ours issues after it, declare the pointer the load reads through `const`; mwcc then treats the load as unable to alias the store and the scheduler hoists it, with no other change to the function.
- [A loaded byte bound inside a loop condition is what puts it in `cmp`'s first slot](idioms/a-loaded-byte-bound-in-the-condition-sets-cmp-operand-order.md): when a byte fetched from memory is compared against a register delimiter, every inline spelling emits `cmp <register>, <byte>`; binding the load to a named local **inside the condition** (`(c = p[i]) != '\0'`) is the only spelling that emits `cmp <byte>, <register>`.
- [A loaded overlay descriptor needs the loader's id as its data hint](idioms/a-loaded-overlay-descriptor-needs-the-loaders-id-as-its-data-hint.md): A byte-correct call to `func_02031348` with a pooled overlay id and callback descriptor can cap at MATCH until the descriptor's `symbols:` line names the overlay selected by that id.
- [A loaded unsigned address base bound to a local keeps the load before the stride](idioms/a-loaded-unsigned-address-base-bound-to-a-local-keeps-the-load-before-the-stride.md): In Thumb raw-address indexing, binding a loaded u32 base to a local before adding a scaled index restores the base load into r1 before the stride constant in r0. An inline base load swaps those registers and schedules the stride first.
- [A local declared at its first use schedules its store there, and a nested block is the only spelling](idioms/a-local-declared-at-its-first-use-schedules-its-store-there.md): moving a local's declaration down to where it is first used moves its initialising store there too, which reorders everything else in the function; this front end rejects the mixed declaration (`expression syntax error`, even at `-lang c99`), so the declaration has to go into a nested block instead.
- [A lone `p = q` arm if-converts to `movne`, branch over the other arm](idioms/a-lone-move-arm-if-converts-to-movne.md): In an ARM loop, a two-arm `if` whose entire body is one register move is if-converted by armcc to a predicated `movne` followed by a conditional branch over the other arm. Writing the same move as an unconditional tail statement instead puts the `mov` after the branch and shifts every following byte by four.
- [A long index colours apart from an int one](idioms/a-long-index-colours-apart-from-an-int.md): when a loop index or table index and one neighbouring value swap two registers at every use and no declaration order moves them, declare the index `long` / `unsigned long` instead of int / u32: mwcc keeps long and int as distinct types for register colouring, and the swap disappears.
- [A long loop counter keeps its copy of a parameter out of the entry guard](idioms/a-long-loop-counter-keeps-its-copy-of-a-parameter-out-of-the-entry-guard.md): when `for (i = n; i < K; ...)` compiles with an extra `adds r0, rN, #0` copy of the parameter and the entry guard tests that copy (`cmp r0, #K`) where the image tests the counter itself (`adds r7, r2, #0; ...; cmp r7, #K`), declare the counter `long`: the int-to-long assignment is no longer a plain copy, so 1.1p1 stops propagating `n` into the guard and drops the spare register. One function so far; try it as a lever, not a rule.
- [A clipped nested loop wants both bounds as expressions over fresh loop variables, not locals over the parameters](idioms/a-loop-bound-must-be-an-expression-over-a-fresh-loop-variable.md): `for (y = y0; y < y0 + h; y++)` and `for (x = x0; x < x0 + w; x++)` hoist each bound into the preheader *after* the guard that precedes it, while binding either bound to a local before the nest computes it before the guard; when register pressure hides that difference the residue is not a moved instruction but a rotation of the scratch registers holding the bounds.
- [A loop bound reread every pass with no stores in the body is a const record pointer](idioms/a-loop-bound-reread-every-pass-with-no-stores-is-a-const-record-pointer.md): when a read-only scan loop (`for (i = 0; i < r->n; i++, p++) if (...) return 1;`) reloads its u16 bound `ldrh rX, [r0, #n]` at the bottom of every pass, and the record pointer stays in r0 with a small push (`push {r3, r4}`), while yours hoists the bound into a callee-saved register (`push {r4, r5}`), declare the record pointer and the element pointers `const`. The body has no stores, so nothing else explains the reload; index forms and parameter reuse are inert.
- [A loop bound read through the pointer reloads after each call](idioms/a-loop-bound-through-a-pointer-reloads-after-each-call.md): Caching a count field in a local pins it in a register across the loop body's call; reading the field in the `for` condition instead makes the original's fresh `ldr` appear after every call.
- [A loop-carried local beside a re-read field keeps both loads](idioms/a-loop-carried-local-beside-a-re-read-field-keeps-both-loads.md): two loads of the same struct field, one at the bottom of a loop feeding the back-edge compare and one at the top of the body feeding the work, mean the loop condition is on a named local refreshed at the bottom while the body reads the field again; a bare `while (p->f != end)` with `n = p->f` inside CSEs the pair and loses four bytes at the body top.
- [A loop-carried value the compiler parks in r1 across a call is that call's second argument](idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md): `docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md` warns that a call which leaves r1 to r3 alone says nothing about its arity; this is the case where it says everything, because the register the value sits in is not a leftover but a *choice* the allocator made, and it only makes that choice when the value is an argument.
- [A loop counter zero before an offset assignment schedules before its spill](idioms/a-loop-counter-zero-before-an-offset-assignment-schedules-before-its-spill.md): when a Thumb tile loop has the correct stack slots and body but a computed row offset's spill precedes zeroing its counters, initialise the counter before assigning the offset; the multiplication can still schedule early while its spill stays after the zero.
- [A loop entered by a branch to its bottom test, with an unfolded constant first test, has a `? 1 : 0` condition](idioms/a-loop-entered-by-a-branch-to-its-bottom-test-has-a-ternary-condition.md): under 1.1p1 -O4,p a `for`/`while` whose condition is a plain relational test is rotated (the first test is peeled, or folded away when the start value is a constant); written as `(cond) ? 1 : 0` the loop keeps the unrotated shape: a `b` straight to the bottom `cmp`/`b<cc>` pair, even for `for (i = 0; ...)`. Try this before reaching for inline asm, which gives the same loop shape but also changes constant handling elsewhere in the function.
- [In a loop, an indexed field access indexes the base and keeps the field offset out of the pointer](idioms/a-loop-indexes-the-base-and-leaves-the-field-offset-in-place.md): `p->slots[i]`, or a block-local `slot = p + i * stride` followed by `*(T *)(slot + off)`, indexes the base before the fixed field offset in a loop, so folding the offset into the pointer in the C text (`*(T *)(p + off + i * stride)`) moves that add onto the loop-invariant base and loses the shape.
- [A loop inside a switch case leaves through `break` twice, not through `return`](idioms/a-loop-inside-a-case-leaves-through-break-to-share-the-function-tail.md): when a case's loop and the default arm both end in the same return value, the original shares one epilogue only if the loop exits with `break` out of the loop and then `break` out of the switch; writing `return v` at either site splits the tail into two copies and costs four bytes.
- [A loop subrecord offset written in the body sinks behind the entry guard](idioms/a-loop-subrecord-offset-written-in-the-body-sinks-behind-the-entry-guard.md): When the image builds a record base before a loop guard but adds its subrecord offset after the guard, keep the record base as a local and add the subrecord offset in the per-element expression inside the loop. Assigning both offsets before the loop hoists the second add and changes the entry register allocation.
- [A range test on a byte is written as the add of the complement, not as a sub](idioms/a-masked-byte-subtract-in-a-range-test-is-an-add-of-the-complement.md): `(u8)(v - 1) <= 3` and its neighbours compile to `sub r0, r0, #1` followed by `and r0, r0, #0xff` in one spelling and to `add r0, r0, #0xff` / `add r0, r0, #0xfd` in the original, so the constant in the source is the two's-complement add of the value the test subtracts; when the diff is a single `sub`/`add` swap with the `and` unchanged, respell the literal as `+ (256 - n)`.
- [A local that is only read back through masks has no width evidence in the diff, and its declared width still decides its register](idioms/a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register.md): when every read of a scalar local goes through a mask or a cast that truncates anyway, the declared type of the local produces no instruction of its own, so nothing in the disassembly names it; but mwccarm still ranks the value differently in the colouring, so getting it wrong is a register-allocation diff with no visible cause. Search the width, do not read it.
- [A shifted temporary the original keeps in a register is not reachable from the C, and no compiler flag moves it](idioms/a-materialised-shift-temporary-is-not-reachable-from-c-or-from-flags.md): when the only residue is a standalone `lsl` that mwccarm folds into a shifter operand, or the same instructions in a different slot, or two registers swapped, the decision is made below the source text; the whole documented flag matrix (every optimisation level, every `-opt` keyword, `-inline`, `-ipa`, `-char`, `-enum`, `-sdatathreshold`, all nine `dsi` builds) is byte-identical to `-O4,p`, so stop spending budget on further source spellings.
- [A path with no return statement hands back the parameter still in r0](idioms/a-missing-return-hands-back-the-parameter.md): When one path of an s32 function returns the untouched first parameter in r0 and the other returns a computed value, the original may have no return statement on that path at all; writing `return v;` makes the compiler join the paths through a register copy (+4 bytes), and an s64 return type recolours the early loads because r1 becomes part of the result.
- [A caller that does not truncate its argument pins the callee's parameter wider than the callee's own body suggests](idioms/a-missing-truncation-at-the-call-site-widens-the-parameter.md): a `u16` parameter costs the *caller* a `lsl`/`lsr` pair at every call site that passes a wider value, so an original whose call site has no such pair is telling you the real prototype takes `int`/`u32`, even when the callee's body only ever stores the value as a halfword.
- [A multi-bit field clear at a nonzero bit offset needs the padding fields declared](idioms/a-multibit-field-clear-at-an-offset-needs-the-padding-fields.md): a three-bit field clear at bit 3 of a byte emits `movs r1,#0x38; bics` only when the source is a bitfield assignment; the equivalent `p[0x4210] &= ~0x38` folds the mask to `0xC7` and emits `ands`, and the container's low padding bits must be a declared field to land the field on bit 3.
- [`mvn` of zero feeding a `mul` is a multiply by `0xffffffff`, not by `-1`](idioms/a-multiply-by-minus-one-is-strength-reduced-but-by-0xffffffff-is-not.md): mwccarm strength-reduces `x * -1` to a single `rsb x, x, #0`, so a live `mvn r0, #0` followed by a real `mul` means the source multiplied by the *unsigned* constant `0xffffffff`; the two are arithmetically identical and compile to different code.
- [Multiplication with a subtraction operand keeps source operand order](idioms/a-multiply-with-a-subtraction-operand-keeps-source-operand-order.md): when Thumb interpolation differs only at the two registers feeding a multiply, placing the subtraction before the halfword load in the C expression can reproduce the original without a temporary or type change.
- [A named 64-bit product over element pointers keeps the sum in place](idioms/a-named-64-bit-product-over-element-pointers-keeps-the-sum-in-place.md): a 3:1 fixed-point blend `((s64)v * 3 + v_sub) >> 2` canonicalises to `adds lo, v_sub, lo`; naming the product (`w = (s64)v * 3; (w + v_sub)`) gives the image's `adds lo, lo, v_sub` but only colours right when the two keys are read through element pointers, not by subscript.
- [A named column offset and inline row assignment hoist the shift before a call](idioms/a-named-column-offset-and-inline-row-assignment-hoist-the-shift-before-a-call.md): when a Thumb row lookup shifts the column before calling the row-index helper, name the byte column offset before the call and assign the row pointer inside the indexed load; separate row-index and row-pointer statements let the shift sink below the call.
- [A named destination index keeps two array offsets scaled separately](idioms/a-named-destination-index-keeps-two-array-offsets-scaled-separately.md): for a Thumb halfword move between adjacent array elements, bind the destination index before either store; an inline `a[index-1] = a[index]` lets the optimizer build and decrement a pointer, while the named index preserves two integer shifts and register-offset stores.
- [A named local for the loaded global base settles a field-store run](idioms/a-named-local-for-the-loaded-global-base-settles-a-field-store-run.md): when a struct-field run stores a self/pointer field first and a field computed off a loaded global second, putting the assignment in source order fixes the store order but recolours the block (the loaded global lands in the pointer register and a constant in the scratch); binding the loaded global to a named local and adding the offset to that local keeps the store order and the original colouring.
- [A named per-element pointer settles Thumb loop register colours](idioms/a-named-per-element-pointer-settles-thumb-loop-register-colours.md): when a Thumb loop already computes base plus scaled index correctly but swaps the computed element pointer with a constant or moves the counter to r0, bind each element address to a named local before accessing its fields. Inline repeated raw-offset expressions can have the same instruction count and different register allocation.
- [A named row index in a struct array keeps the base add before the column shift](idioms/a-named-row-index-in-a-struct-array-keeps-the-base-add-before-the-column-shift.md): a 12-byte row lookup that emits `muls`, then adds the object base before shifting the column, can require both a two-dimensional struct member and a named row-index local; raw byte arithmetic or an inline `1 - row` lets the column shift run first and swaps the scratch registers.
- [A named zero argument keeps a live zero in a callee-saved register and pins the caller-side truncation](idioms/a-named-zero-argument-pins-the-callers-truncation.md): in a loop that passes a constant zero as a call argument, spelling the zero as a named local (`int j = 0;`) keeps it live in a callee-saved register; spelling it as a literal `0` lets the compiler fold the zero and hoist a repeated `(u16)i` conversion into that same register, shifting every register in the loop.
- [A narrow callee parameter type is truncated at the call site, not in the callee](idioms/a-narrow-callee-parameter-truncates-at-the-call-site.md): passing a 32-bit argument to a callee whose parameter is declared `unsigned short` makes mwcc zero-extend the argument in the caller (`lsls`/`lsrs #0x10`, or `ldr` + mask for a stacked argument); if the parameter is declared wider the truncation disappears and the whole tail shifts.
- [A narrow flag local is spilled and reloaded, not constant-propagated](idioms/a-narrow-flag-local-is-spilled-not-constant-propagated.md): when the image stores a zero to a stack slot and reloads it before every use (`movs r0, #0; str r0, [sp, #4]; ldr r0, [sp, #4]; strb ...`) while a neighbouring array is addressed off its own `add rN, sp, #K`, the local is a plain u8 (or u16, or signed char) flag, not a volatile int: 1.1p1 forwards the zero of a plain int, and a volatile gets a home in the addressable-local area.
- [A narrow parameter pins its home store to the front of the prologue](idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md): a narrow parameter can move its home store before the other parameter copies; confirm the width from body and call-site narrowing, and preserve live full-word forwarding.
- [A narrow spilled parameter keeps its reload below the preceding store](idioms/a-narrow-spilled-parameter-keeps-its-reload-below-a-store.md): when a parameter is spilled at entry (`str rN, [sp]`) and reloaded later as a call argument, an `int`/`u32` parameter's reload is hoisted above the store just before it; declaring the parameter `u8`/`u16` keeps the reload after that store, as the original has it. A two-instruction swap next to a `ldr r0, [sp]` reload is the tell.
- [A narrowed parameter is a cast, not a `u16` parameter](idioms/a-narrowed-parameter-is-a-cast-not-a-u16-parameter.md): mwccarm does not narrow a `u16` parameter at function entry, so a two-variable four-shift narrowing run that sits at a call site is an explicit conversion in the C and the parameters it converts must be declared wider than `u16`: declaring them `u16` produces no shifts and the function comes out short.
- [Declaring a narrow pointer gives ldrsh/ldrh; a widening load plus a narrowing cast gives the shift pair](idioms/a-narrowing-cast-loads-wide-then-shifts-not-ldrsh.md): when the original sign- or zero-extends a 16-bit field with an `ldr`/`ldrh` followed by a matching `lsls`/`asrs` (or `lsls`/`lsrs`) pair, the source loaded a wider type and cast it down, not a `s16 *`/`u16 *` dereference.
- [A nearby absolute address is synthesized from the loaded base, not pooled](idioms/a-nearby-absolute-address-is-synthesized-from-the-loaded-base.md): When a function writes several absolute addresses that differ by a round immediate, mwcc loads only one from the literal pool and derives the others with `sub`/`add`; writing the accesses through a common pointer variable instead changes the register allocation and no longer matches.
- [A negated byte loaded with `ldrb` but read elsewhere with `ldrsb` is a u8 field, cast to s8 where it is passed plain](idioms/a-negated-byte-loaded-with-ldrb-but-read-elsewhere-with-ldrsb-is-a-u8-field-cast-to-s8.md): when one call passes `-(field)` as `ldrb; rsbs; lsls #24; asrs #24` and another call passes the same field as `ldrsb` with no narrowing, declare the field `u8`, pass the negated one as `-s->f` into an `s8` parameter and the plain one as `(s8)s->f`; declaring the field `s8` turns the negated load into `movs rN,#off; ldrsb` (one instruction longer, everything after shifts).
- [A negated-conjunction `if` is not the same codegen as returning the conjunction](idioms/a-negated-conjunction-return-is-not-the-same-as-returning-the-conjunction.md): `return a && b && c;` if-converts the last operand's epilogue into `addne sp` / `movne r0,#1` / `popne`, while `if (!(a && b && c)) return 0; return 1;` emits a plain `bne` to a separate success epilogue. Same source semantics, different bytes.
- [A nested FX_Mul keeps the inner product in r0:r1 only when FX_Mul is an inline function](idioms/a-nested-fx-mul-keeps-the-inner-product-in-r0-only-as-an-inline-function.md): `FX_Mul(FX_Mul(a, b), c)` written with the FX_MUL macro moves the inner product to r2:r3 and loads `c` into r0:r1 (and swapping the operands changes nothing); written as a `static inline fx32 FX_Mul(fx32, fx32)` the inner result stays in r0:r1 and `c` goes to r2:r3, which is the Nitro game-code shape.
- [A nested struct pointer keeps the base offset as its own `adds`, a flat byte offset folds it](idioms/a-nested-struct-pointer-keeps-the-base-offset-as-its-own-add.md): `adds r0, r4, #4` followed by `adds r0, #0x5e` is two separate values, the inner object's address and the field's offset within it; write the inner object as a real nested struct member and take a pointer to it. A flat `*(u8 *)(p + 0x62)` folds the pair into one `adds r4, #0x62`.
- [A no-code self-assignment reorders the register colouring](idioms/a-no-code-self-assignment-reorders-the-register-colouring.md): `s = s;` compiles to nothing but still changes the colouring order of the callee-saved registers around it. When a same-width permutation of three or four registers survives every declaration-order, scope and front-end lever, a self-assignment of one of the rotated variables at the point where its live range meets the others' can settle it. Declaration order does not help here because the colouring order does not follow it.
- [A null-guarded bool field test keeps the zero hoisted; a single conjunction branches](idioms/a-null-guarded-bool-field-test-keeps-the-zero-hoisted.md): For `result = (p != 0) && (p->f & 1);` (and the `if (p && (p->f & 1)) result = 1;` spellings) mwccarm selects the value in r0 with a branch; wrapping the same bool `!= 0` test in a null guard (`if (p != 0) result = (p->f & 1) != 0;`) hoists `mov r1,#0` above the branch and predicates `movne r1,#1`, which is what the image has.
- [A pointer local set to NULL and then tested compiles to `movs rN, #0; beq`](idioms/a-null-pointer-local-tested-reuses-the-movs-flags.md): 1.1p1 does not fold `p = 0; if (p != 0 && f(p) == 1) {...}`: it emits `movs rN, #0` and branches on the flags of that movs (`beq` always taken), keeping the dead arm; likewise `p = 0; if (f(p) == 0) g(p);` passes a live zero register. A `movs r6, #0` directly followed by a conditional branch is this shape, not a flag-setting compare you are missing.
- [A one-bit bitfield assigned `bic` + one predicated `orr` was written as two arms, not as a boolean](idioms/a-one-bit-bitfield-wants-two-arms-not-a-boolean.md): assigning a comparison result to a one-bit bitfield materialises the boolean in a register first (`moveq`/`movne`/`and #1`) and then inserts it; writing the same thing as an `if`/`else` with a literal in each arm lets the compiler clear the bit once with `bic` and predicate the set back onto the entry compare, twelve bytes shorter.
- [A one-bit field clear is `bics` with `movs #1`, not `ands` with a pool mask](idioms/a-one-bit-field-clear-is-bics-with-movs-one-not-ands.md): clearing an `unsigned short : 1` field compiles to `ldrh; movs r1,#1; bics r2,r1; strh`, while the equivalent `*p &= ~1` spends a literal-pool word on `ands`.
- [A one-element array initialiser keeps its address for the call, not the later store](idioms/a-one-element-array-initialiser-keeps-its-address-for-the-call-not-the-later-store.md): an arm that zeroes a u16 stack slot, stores a call result into it and passes its address on (`add rX, sp, #N; movs r0, #0; strh r0, [rX]; bl f; add r1, sp, #N; strh r0, [r1]; ... adds r1, rX, #0; bl g`) is a block-scope `u16 s[1] = {0}; s[0] = f(); g(x, s);`. A scalar `u16 c = 0; c = f(); g(x, &c);` (or any pointer-local, cast, helper or comma spelling of it) compiles the other way round: the callee-saved register holds the address for both stores and the call argument gets the fresh `add r1, sp`. The address is also computed before the zero (`add` then `movs`), which the scalar never does.
- [A one-trip loop survives only when a signed counter is compared against an unsigned (sizeof) bound](idioms/a-one-trip-loop-survives-only-with-a-signed-counter-against-a-sizeof-bound.md): when the original keeps a loop whose bound is 1 (`cmp rN,#1; blo`, often with the counter spilled to the stack), write the counter as `int` and the bound as `sizeof(tbl) / sizeof(tbl[0])` (or `1u`); an `int` counter against `1`, or an `unsigned` counter against any bound, is folded into a single straight-line pass.
- [A one-word struct result held in a local and passed by value costs a second frame word](idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md): when the original opens `push {r4-r6, lr}; sub sp, #8` and never touches `[sp]`, and one callee returns a one-word struct that is then passed by value to another callee, `t = f(); g(..., t);` reserves both temporaries (8 bytes); `g(..., f())` reserves only one (`push {r3-r6, lr}; sub sp, #4`).
- [A pair of adjacent zero stores is one `u64` zero store](idioms/a-pair-of-adjacent-zero-stores-is-one-u64-zero-store.md): two consecutive word stores with the same zero register (`str r2, [r0, #0x608]; str r2, [r0, #0x60c]`) are not two `int` field assignments writing a literal 0; they are a single `unsigned long long` store of zero over the two words. Written as two `int` stores the compiler materialises the zero in a different scratch register (r1 instead of r2) and the entry never lines up.
- [A parameter compared with a byte field keeps source operand order](idioms/a-parameter-compared-to-a-byte-field-keeps-source-operand-order.md): A one-byte cmp operand swap in a parameter-versus-byte-field equality can follow the expression operand order directly. Put the parameter first when the image compares its entry register against the field's scratch register.
- [A parameter moved out of r0 at entry names the tail call's arity](idioms/a-parameter-moved-out-of-r0-at-entry-names-the-tail-calls-arity.md): an opening `mov r1, r0` whose destination the body never reads is argument setup for the call at the end of the function, so the callee takes a second parameter; written as a one-argument call the function comes out four bytes shorter with everything shifted by one instruction.
- [A loop-peeled entry test under a short guard is not if-converted by 1.1p1](idioms/a-peeled-loop-entry-test-is-not-if-converted-by-11p1.md): when an `if (scalar > 0)` wraps a `for (i = 0; i < count; i++)` and `count` is read through a pointer, the image can predicate the whole peeled prologue -- load `count`, `cmp count, #0`, plus the loop's `i = 0` -- into the guard's condition, collapsing `scalar > 0` and `count > 0` into one unpredicated `ble`. `dsi/1.1p1` keeps the entry test as its own branch even though the peeled block is only five instructions, so the guard-arms predication budget does not apply to a block the compiler reached by loop rotation rather than by spelling an arm.
- [A phantom in the named overlay can be real SDK code in an overlapping one](idioms/a-phantom-in-the-named-overlay-can-be-sdk-code-in-the-overlapping-one.md): when `show --region R` reports a prologue-shaped data word, do not "fix" it by switching to the overlapping overlay that holds real code at the same address before checking `layout/symbols_sdk.json`: if that code is an SDK function the lane is told to ignore, the lane has no work at all and the only honest output is a phantom report.
- [A `+ 0xFFFF` bias is two `add`s; `- 1` is one `sub`](idioms/a-plus-0xffff-bias-is-two-adds-and-a-minus-one-is-one-sub.md): in ARM code a range test biased by minus one is four bytes longer when the source writes the bias as the unsigned 16-bit constant 0xFFFF, because that splits into `add #0xff` plus `add #0xff00` while `- 1` is a single `sub #1`.
- [A pointer cast on a struct-array member keeps the hoisted array base and the mla form](idioms/a-pointer-cast-on-an-array-member-keeps-the-hoisted-array-base.md): a sub-word field read out of `obj.arr[i]` where the field is not at offset 0 can be folded to `base + i*stride + off` addressed off the object base, which shrinks the function and recolours everything; writing the base through an explicit pointer type (`((Elem *)obj.arr)[i].field`) keeps the array base hoisted into its own register and emits the `mla rD, rI, rStride, rBase` form. The two spellings are semantically identical, so only the object listing shows the difference.
- [Two field stores through a pointer local can rematerialise the symbol base](idioms/a-pointer-local-can-rematerialise-the-symbol-base.md): binding a global's address to a `char *` local and then storing at two offsets lets the ARM compiler spend a second literal-pool word on `symbol+off`; declaring a typed extern array and indexing it keeps one base register.
- [Pointer + integer normalises to pointer-first; casting the pointer keeps the source order](idioms/a-pointer-plus-integer-add-is-normalised-but-a-cast-one-keeps-source-order.md): `p + n` and `n + p` both compile to `add rd, rp, rn` no matter which way round they are written, because the front end normalises pointer arithmetic before the operand-order rule ever sees it; writing the same address as `n + (u32)p` makes it an ordinary integer add and the source order is kept, which is the only way to reach `add rd, rn, rp`.
- [A constant-pool address takes `ip` only when the low scratch registers are already reserved](idioms/a-pool-address-takes-ip-only-when-the-low-scratch-is-reserved.md): a fixed-address constant loaded for an aggregate byte-copy lands in `ip` when `r0`/`r1`/`r2` are already committed to other live values of the same statement block, and in `r0` when they are not. When the diff is a cyclic rotation of three roles across `{r0, r1, r2, ip}` (base, scaled length, small constant, copy temps) the residue is the front end's preference order, not a source shape: naming the small constant, making the source `const volatile`, a named scaled-length local, and declaration reorders all leave the rotation intact.
- [A pool emission order residue is a list-scheduler tie, not a source order](idioms/a-pool-word-order-residue-is-a-list-scheduler-tie.md): when the only residue is two pool words trading places (the address a load-but-no-store statement needs versus the immediate a later store needs), the pool order follows the *scheduled* instruction order, not the source statement order. Reordering statements, naming locals, `const`, `volatile`, u32-vs-u64 stores and a second extern name all measure the same residue; the scheduler hoists the immediate load above an intervening `ldm`/`stm`.
- [A pool word used as an object's address must be declared as an array, not a pointer](idioms/a-pool-word-used-as-an-objects-address-is-an-array-not-a-pointer.md): when a pool word holds the address of a data object and the code dereferences it at an offset, declaring the extern as `T *x` costs an extra `ldr` (the pointer is loaded from the pool and then *its* value is loaded), while `extern T x[]` makes the pool word the object's address and the access compiles to the original's single load or store; a function-pointer pool word used as a value has the same shape, `(u32)func_XXXXXXXX` with the function declared normally.
- [A small constant that arrives from a literal pool instead of a `movs` is not a constant at all](idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): mwccarm materialises any integer literal from 0 to 255 with `movs`, so an argument of 0xBC that the original loads from a literal pool cannot be written as a number in any type; it is an `R_ARM_ABS32` against a symbol whose absolute value is small, which is what a linker-defined overlay id looks like on this SDK.
- [A pooled tail-call target needs a `thumb` (and overlay) `symbols:` hint](idioms/a-pooled-tail-call-target-needs-a-thumb-region-symbols-hint.md): A `ldr r3,pool; bx r3` tail call to a Thumb function caps at `MATCH` unless the target is declared with `thumb` in the `symbols:` block; when the address sits in more than one overlay it also needs the owning `ovNNN` token, because the bare `func_XXXXXXXX` name is read as ARM otherwise.
- [A `pos = 0; buf[pos++] = ...` accumulation settles a whole callee-saved rotation](idioms/a-pos-accumulation-settles-a-callee-saved-rotation.md): when the entire callee-saved register file is rotated one slot and the body is otherwise instruction-for-instruction correct, and every declaration order, scope and front-end lever has been measured inert, the lever can be the *shape* of the byte writes: writing a header as constant indices plus a folded `pos = 7` lets the allocator colour a live local late, while the vendor's `int pos = 0; buf[pos] = ...; pos++;` accumulation colours it early and rotates every callee-saved home back into place.
- [A post-decrement in the loop condition splits the compare from the subtract](idioms/a-post-decrement-in-the-loop-condition-splits-the-compare-from-the-subtract.md): `while (n-- != 0)` compiles to a `cmp n, #0` and a flagless `sub n, n, #1` with the branch reading the compare, while the equivalent `while (n != 0) { ...; n--; }` folds both into one `subs`; they are the same loop with the same trip count, but the post-decrement form is two instructions and eight bytes longer, once at the rotated entry test and once per body.
- [A `push {r0-r3}` frame whose home slot is only read is a by-value struct parameter](idioms/a-push-r0-r3-frame-without-a-callee-taking-the-address-is-a-struct-by-value-parameter.md): when a function opens with `push {r0, r1, r2, r3}` and an `add rN, sp, #K` base is used only to load (`ldr r1, [r7]`), never passed to a callee as the whole slot's address, the parameter is a small struct passed by value, not a scalar whose address is taken.
- [A loop bound that is re-read on every iteration means the field is volatile](idioms/a-re-read-loop-bound-is-a-volatile-field.md): when the original re-loads a length field through the same pointer on every pass of a loop (`ldrb r1, [r0, #4]` sitting between the payload test and the loop's compare) while a plain field lets mwcc hoist the load out of the loop and come out one instruction short, declare the field `volatile`; the volatile qualifier is what forces the per-iteration re-read, and the field's width and signedness are unchanged.
- [A re-read of a field the previous statement stored is one volatile read, not a volatile field](idioms/a-re-read-of-a-field-just-stored-is-one-volatile-read-not-a-volatile-field.md): when the original loads a word it has just stored, the compiler proves the load redundant and degrades it to `mov rN, rN`; the spelling that restores it is a single `*(volatile u32 *)&p->f` read into a local, because qualifying the field or the pointer `volatile` also un-predicates every read-modify-write around it.
- [A small integer parameter that is re-truncated at every use is a 32-bit parameter with casts, not a narrow parameter](idioms/a-re-truncated-parameter-is-a-wide-parameter-with-casts.md): when a parameter is spilled and then zero-extended again at each call that takes it, declare the parameter as the wide type and cast at each use; declaring it narrow makes mwcc skip the truncation entirely and drop two instructions per site.
- [A read-modify-write of the field just stored zero is what emits bic, a plain masked assignment folds away](idioms/a-read-modify-write-of-the-just-stored-field-is-what-emits-bic.md): `p->f = 0; p->f = (p->f & ~mask) | (x & mask);` emits the `bic rD, rZ, #imm` a bitfield clear shows, because the dead store is forwarded to the second statement as a register value. The obvious spelling `p->f = x & mask;` folds to a bare `and` (or to nothing) and loses the `bic` and the register that held the zero.
- [A record array type multiplies a dying index into a fresh register](idioms/a-record-array-type-multiplies-a-dying-index-into-a-fresh-register.md): when a Thumb leaf copies its index before multiplying by a record stride and folds the array header into field immediates, use an actual record array member. Raw integer address arithmetic and a pointer to stride-sized byte arrays multiply into the stride constant's register and omit the copy.
- [A redundant second assignment keeps an offset local out of the temp slots](idioms/a-redundant-second-assignment-keeps-an-offset-local-out-of-the-temp-slots.md): a local assigned once from a cheap expression (`off = idx * 4`) is folded into a compiler temporary, and spilled temporaries take stack slots above every spilled named local. When the image has that value in the lowest spill slot, assign it a second time with the same expression in a branch that does not change it; the local then keeps its own slot and obeys declaration order (last declared lowest).
- [A region symbol cast to u32 keeps base + N an add and colours the bound first](idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md): When the image pools a linker region base and derives a bound with `add rX, rY, #N`, write the base as the extern region symbol cast to u32 in a u32 local. A literal base colours base and bound the other way round, and the symbol kept as a pointer folds base + N into a second relocated pool word.
- [A register blx with a pop-lr return is a toolchain conflict: no -proc value emits both](idioms/a-register-blx-with-a-pop-lr-return-is-a-toolchain-conflict-no-proc-value-emits-both.md): a function that contains register `blx rN` (ARMv5T) *and* the ARMv4T epilogue `pop {..., lr}; bx lr` cannot be reproduced by mwccarm 1.1p1 under any `-proc` value it accepts. Every v5+ value emits `blx rN` but returns through `pop {..., pc}`; every ARMv4T value returns through `pop {..., lr}; bx lr` but reaches an indirect call with `mov lr, pc; bx rN`, which is two instructions where the original has one. The pop-lr epilogue is therefore necessary but not sufficient as an ARMv4T tell, so read `an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md` together with this one.
- [A register-carried index in an unrolled walk is the spelled-out form, not a loop](idioms/a-register-carried-index-means-the-arms-were-spelled-out.md): when a short fixed-count walk is fully unrolled but each element is loaded through `movs rN,#i; ldrsb rM,[r0,rN]` instead of `ldrsb rM,[r0,#i]`, the source spelled the arms out with a variable index re-assigned before each arm; the same work written as a `for` loop stays rolled, and literal indices use immediate offsets.
- [A loop-invariant load that is still reloaded inside the loop means the loop was never rotated, and only `goto` keeps it that way](idioms/a-reloaded-loop-invariant-means-the-loop-was-not-rotated.md): mwccarm rotates every structured loop (`while`, `do`/`while`, `for(;;)` with breaks) into a peeled first test plus a single back edge, and once a loop has one back edge it also hoists any invariant load out of the body; an original that reloads the invariant every iteration therefore had two exits and no rotation, which in C is a labelled block with explicit `goto`s.
- [A repeated constant pools only when its uses are in one block, so a hoist-shaped residue is a misplaced brace first](idioms/a-repeated-constant-pools-only-within-one-block-so-a-hoist-residue-is-a-misplaced-brace.md): when a function is one instruction longer than the image because a small literal got hoisted into a callee-saved register, check whether the literal's uses sit in the same basic block before blaming the front end. mwccarm pools a repeated constant only when the uses are in one block; move one use into a different block and the hoist disappears without touching the literal at all. A partial hoist -- some repeated constants pooled, some not -- is almost always a statement in the wrong place, not a compiler-version difference.
- [A repeated small constant takes a callee-saved register, and everything below it moves up one](idioms/a-repeated-small-constant-takes-a-callee-saved-register.md): under `-O4,p` this front end materialises a small literal that is used more than once into the lowest callee-saved register at the top of the prologue and copies it into every argument register, where the original rematerialises the immediate at each use; the pooled register then steals the first callee-saved slot and pushes every local, every pointer and the whole `push {...}` list one register higher, so a single shared `0` can move twenty instructions.
- [A restrict position parameter sinks a store past the next load](idioms/a-restrict-position-parameter-sinks-a-store-past-the-next-load.md): four stores `out->a = p[2] - K; out->b = p[2] + K; out->c = p[0] - J; out->d = p[0] + J;` compile in source order with `p[2]` reloaded after the first store, because `out` may alias `p`. When the original loads `p[2]` once, stores `out->b` first, then loads `p[0]` and only then stores `out->a` (held in a callee-saved register, so the prologue is `push {r3, r4}`), qualify the source parameter with `__restrict`. Locals, struct copies and reordered statements do not reproduce this order; the qualifier alone does. Use `__restrict`, not `restrict`, so the file also compiles without `--lang c99`.
- [A restrict table parameter hoists a load above a store only at a different offset](idioms/a-restrict-table-parameter-hoists-a-load-above-a-store-only-at-a-different-offset.md): a block that stores `pos.x = e[A]; pos.y = e[B];` (u8 loads, s16 stores into a stack struct) normally compiles in source order, `ldrb; strh; ldrb; strh`, because a char load may alias the store. When the original shows `ldrb x; ldrb y; strh x; strh y` in some arms and the plain order in others, qualify the table parameter `e` comes from with `__restrict`. mwcc then hoists the second load above the first store only when the load offset differs from the store offset (e[1] vs pos.x at 0), and keeps the source order when they are equal (e[0] vs pos.x). Use `__restrict`, not `restrict`, so the file also compiles without `--lang c99`. A `restrict` on a local pointer has no effect; only the parameter qualifier does.
- [A result computed in a dying local takes that local's register](idioms/a-result-computed-in-a-dying-local-takes-that-locals-register.md): when two fresh temporaries come out in each other's registers and no declaration order, type (int, u32, long) or statement order flips them, compute one of them IN a local that dies at that point (a loop-carried value about to be reassigned). The value then lives in that local's register, and values coalesced with it follow it.
- [A `return` at the end of an `if` body and another after it keep two epilogues; hoisting one return out merges them](idioms/a-return-at-the-end-of-an-if-and-after-it-keep-two-epilogues.md): when the tail of an `if` block and the code after it are the same `return 0;`, mwccarm emits two separate `movs r0,#0; pop` epilogues and branches the early-out to the second; wrapping the body so there is one `return` instead collapses them and moves the early-out target, changing the function's size and every branch displacement.
- [A `return 0;` shares its register with an earlier `= 0` store, keeping r0 out of the rotation](idioms/a-returned-zero-keeps-r0-out-of-the-rotation.md): when a function both stores the literal `0` into a field and returns `0`, the compiler materialises one zero in r0 and keeps it live all the way to the epilogue, so r0 is not handed out as scratch to any expression in between; drop the `return 0;` (or make the function `void`) and the whole tail shifts down into r0/r1, a register-number diff on every instruction that reads like a scheduler accident and is not one.
- [A temporary reused across lerps keeps each sum before the calls, quotient first](idioms/a-reused-temporary-across-lerps-keeps-each-sum-before-the-calls.md): three `from + (to - from) * t / 4096` values computed before three setter calls, each final `adds` with the quotient on the left (`adds r7, r1, r0`), the first two sums held in callee-saved registers and only the last sum done at its call: one shared local `v` reassigned per component (`v = to - from; v = v * t / 4096; x = v + from;`). Inline lerp helpers put `from` on the left of every add and nothing in their spelling moves it.
- [A row add after the key compare is an inline byte-offset argument](idioms/a-row-add-after-the-key-compare-is-an-inline-byte-offset-argument.md): when a table scan compares `ldrh rK, [tbl, off]` and only forms `row = tbl + off` inside the matching branch (reusing off), the row is an inline helper's argument written as `(u16 *)((u8 *)tbl + i * 12)`; a 2-D subscript, `&tbl[i]` or a row local assigned in the branch all CSE the add into the compare block. The helper's own colours then come from `for (i = 1, p = row; ...)`: a local pointer copy set in the for header.
- [A running counter bumped in the loop body colours differently from the same bump in the for header](idioms/a-running-counter-bumped-in-the-body-colours-apart-from-a-comma-increment.md): `for (i = 0; i < n; i++) { f(src + k * 32, ...); k++; }` and `for (i = 0; i < n; i++, k++) f(src + k * 32, ...);` compile to the same instructions, but the comma form hands the inner index a lower callee-saved register than a loop-invariant pointer; when `i` and a hoisted base swap registers across every nest of a copy loop, move the second counter's increment into the body.
- [A field saved by reading it back from the vector keeps the dead store and moves the zero ahead of the copy](idioms/a-saved-field-read-back-from-the-vector-keeps-the-dead-store-and-moves-the-zero.md): when a vector field is stored, then overwritten with 0, and restored later from a callee-saved register, write the save as a read of the vector (`a.y = p->y; y = a.y; a.y = 0;`), not as a separate load (`y = p->y; a.y = y;`). The read keeps the first store alive even with the zero store right after it, and lets the zero sit before a following struct copy, which is what sets the register colouring.
- [A scalar halfword stack argument avoids the aggregate partial store](idioms/a-scalar-halfword-stack-argument-avoids-the-aggregate-partial-store.md): When a fifth halfword input is loaded with ldrh but stored to the outgoing stack with str, declaring it as a scalar u16 reproduces the full-word store; a two-byte bitfield aggregate emits an add-to-sp and strh instead.
- [A scene-callback parameter takes a bare function name, and the vendor's DWARF prototype does not parse](idioms/a-scene-callback-parameter-takes-a-bare-name-and-the-vendor-prototype-does-not-parse.md): `DWCi_ChangeScene`'s DWARF prototype is `void (*)(...)`, but mwccarm 1.1p1 under `-lang c99` rejects that declarator outright (`')' expected`), and the house spelling `extern void DWCi_ChangeScene(void (*scene)());` is the one that compiles. The scene target must be an `extern void <name>(void)` *function* passed by bare name; declaring it as data and passing `&name` is the shape the unverified drafts of the `endScene2` pair shipped.
- [A function whose first instruction is a param-homing push is split by the next lr-saving push](idioms/a-second-push-saving-lr-splits-a-function-into-two-labels.md): `disasm.py` auto-labels any instruction that saves `lr`, so when a function opens with `push {r0, r1, r2, r3}` (it took the address of a register parameter) and the *real* frame push immediately follows, that second push gets a `func_` label and the outer function's listed extent collapses to the four bytes before it. The short extent is a labelling artefact, not a real 4-byte function; writing C for that extent is impossible.
- [A second same-typed local can flip which of two callee-saved registers a live value gets](idioms/a-second-same-typed-local-changes-callee-saved-allocation.md): When two values are live across the same call and both need a callee-saved register, reusing one variable for the second value can make the allocator give them `r5`/`r4` instead of `r4`/`r5`; declaring a *distinct* same-typed local for the reload and using that instead reproduces the original allocation. The instruction stream and byte count are identical, only the registers differ, so the function reads as a whole-body `DIFF`.
- [A second zero must be spelled as a copy of the first, not as its own literal](idioms/a-second-zero-must-be-spelled-as-a-copy-of-the-first.md): when the image materialises one `mov rA, #0` and then derives a second zero with `mov rB, rA`, the C has to make the second value textually depend on the first (`int j = i;`), because two independent `0` literals leave the allocator free to pick which register owns the constant and no declaration order fixes it.
- [A 1-or-2 selector written as a ternary first in a sum keeps its scratch register](idioms/a-selector-ternary-first-in-a-sum-keeps-the-selector-in-its-scratch-register.md): `x = (f ? 3 : 4) + p->a * 5;` gives the original's `movs r2,#3 ... adds r0,r2,r0` shape, while an if-assigned local `t` or `p->a * 5 + t` allocates the selector into r0 and the load into r1.
- [A self-move after a call is an add of a zero-valued local](idioms/a-self-move-after-a-call-is-an-add-of-a-zero-valued-local.md): Adding a local that holds zero to a call result can survive register coalescing as a self-move; a literal addition of zero folds away before code generation.
- [A self-narrowing cast statement recolours a table index](idioms/a-self-narrowing-cast-statement-recolours-a-table-index.md): a function-pointer table dispatch `d[t[0]].fn(a, out)` with a 12-byte entry compiles to `ldrb X; movs #12; adds P, X, #0; muls P, r2, P`. By default the loaded index X takes the low scratch register (r3) and the product P a callee-saved one (r4). When the original has X in r4 and P in r3 (often with the `movs r2, #12` scheduled early and the pointer reload in r0), load the index into a local and narrow it in a separate statement: `k = t[0]; k = (u8)k; d[k].fn(a, out);`. The second definition turns k into a two-definition web that is coloured after the product. The local may be `u8` or `int`. Inert: the cast inside the subscript (`d[(u8)t[0]]`, `d[(u8)k]`), `k &= 0xFF`, `k += 0`, `k = k`, named or reused index locals, function-pointer locals, entry-pointer locals, byte-offset spellings, and different table types.
- [Assigning an operand to a local and then recomputing into the same local pins it in a register before the other side's call](idioms/a-self-recompute-pins-an-operand-before-the-other-side-calls.md): `x / f()` evaluates the call first and rematerialises `x` out of its incoming stack slot afterwards; writing `n = x; n = n / f();` forces `x` into a callee-saved register in the prologue shuffle instead, which is two bytes longer and shifts the rest of the function.
- [A sentinel assigned before the calls keeps a mask constant in a scratch register](idioms/a-sentinel-assigned-before-the-calls-keeps-a-mask-constant-in-a-scratch-register.md): when `movs rN, #9` (a "none" sentinel) sits before the first call of a classify chain, write the assignment there; written after the calls, the compiler hoists an earlier `& 2` mask into a callee-saved register and reuses it for a later `cls = 2`, shifting every register below.
- [A sentinel test and a null test on the same word are two members of a union](idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md): when a loop tests one word twice with no store or call between the two tests and the original keeps both loads, the two tests are not the same access path; spelling the word as a union whose members are read by different types is what stops mwccarm forwarding the first load into the second, and no loop shape does it.
- [A separate index local per loop reorders spill slots](idioms/a-separate-index-local-per-loop-reorders-spill-slots.md): when two loops in one function each compute an entry index (`idx = func(w, i)`) and the second loop spills it next to another local, reusing one `idx` variable for both loops can swap the two spill slots (`str rN, [sp, #4]` vs `[sp, #8]`). Giving the first loop its own index local (`k`) puts the second loop's `idx` and `flag` in the original slots. Changing the declaration order of `idx` and `flag` alone did nothing.
- [Two switch arms ending in the same call and `b` are cross-jumped unless one arm is an if/else](idioms/a-shared-bl-b-tail-is-cross-jumped-unless-the-arm-is-an-if-else.md): in a switch whose arms end `mov r0, #k; bl f; b exit`, an arm written as `if (c != 3) { move = 2; break; } ...; f(0); break;` lets 1.1p1 fold another arm's `bl f; b exit` into a branch to it; writing the same arm as `if (c == 3) { ...; f(0); } else move = 2; break;` keeps both tails, as the original does.
- [A shared exit block is written out in every arm, and a bare goto in front of it is two bytes short](idioms/a-shared-exit-block-is-written-out-in-each-arm.md): when several paths end in the same store and return, the original reaches them with `bcc` over a `b` to one copy; reproducing that means writing the statements out in each arm and letting the compiler cross-jump them, not putting one copy behind a label and jumping to it.
- [An argument spelled identically in both arms of an if/else is loaded once, before the branch](idioms/a-shared-inline-argument-is-loaded-once-before-the-branch.md): when both arms of an `if`/`else` call the same function with the same expression for one argument, the compiler hoists that expression's load above the branch and branches first, unlike an unequal-expression pair where the load stays in its own arm.
- [A shared pointer load in a store run names a local](idioms/a-shared-pointer-load-in-a-store-run-names-a-local.md): when each store re-reads a global pointer (so the same `ldr` repeats before every `str`), the one place two stores share a single load is the one place the source bound that pointer to a local for just those stores.
- [A case/default arm whose only body is a register copy is hoisted above the compare chain; a pool load is not](idioms/a-shared-register-copy-arm-is-hoisted-above-the-compare-chain.md): when the image's compare chain has one shared `case 1: default:` block that is a lone `mov r6, r1` (`copyDest = sendBuf`) followed by `b join`, 1.1p1 store-motions that copy to the top of the function (`mov r6, r1; cmp r0, #1; beq join; cmp r0, #2; bne join; ...`) and drops the arm's `b`, costing four bytes and recolouring every register below. The identical switch shape with a pool load in the arm (`ldr r8, [pc, ...]`) keeps the block out of line. The difference is that a parameter already in a register is trivially rematerialisable at entry, so the arm is reduced to the entry value plus a predicated override; a load cannot be hoisted and stays in its block.
- [A shared running cursor and a reused counter settle a parse-loop register rotation](idioms/a-shared-running-cursor-settles-a-parse-loop-register-rotation.md): when two passes over one string are spelled with separate cursor locals (`p`, `q`) and separate counters, this front end colours four registers and the body is 4 bytes short; spelling it the way the algorithm actually works -- one running pointer advanced through both passes and one counter variable reused -- reproduces the image's allocation exactly.
- [A shift recomputed from a spilled value at each use differs by a cast between the uses](idioms/a-shift-recomputed-from-a-spilled-value-at-each-use-differs-by-a-cast-between-uses.md): when the image keeps a value raw in a stack slot and re-shifts it (`ldr rN,[sp]; lsls rN,rN,#k`) at every use while mwcc CSEs the shift into a saved temporary (an extra slot or register, a different frame), spell one use through a cast, `(u32)x << k` or `(u32)i * 16`, and the others plain: the two are different expressions to 1.1p1's CSE, so neither is cached.
- [A `lsl`/`and` pair on a tile offset is multiply-then-mask in the source, not mask-then-multiply](idioms/a-shift-then-mask-pair-is-multiply-then-mask-in-the-source.md): `(v & 7) * 8` compiles to a `lsl #0x1d` / `lsr #26` pair, so a literal `lsl #3` / `and #0x38` in the original means the source wrote `(v * 8) & 0x38`; the same spelling one field wider, `(v * 8) & 0x7fc0`, is how a tile index scaled to bytes reaches a single `and Rd, Rmask, Rn, lsl #3`.
- [A `(short)` cast makes a masked big-endian byte shift unwidened](idioms/a-short-cast-makes-a-masked-byte-shift-unwidened.md): `(short)(x & 0xff00) >> 8` emits `and #0xff00; lsl #16; asr #24`, while `(x & 0xff00) >> 8` or `(signed char)(x >> 8)` collapse to a single `lsr`/`asr #8`; declare the cast after the mask to reproduce the original.
- [A draft that compiles short self-limits the compared range to its own size](idioms/a-short-draft-self-limits-the-compared-range-to-its-own-size.md): `match.py one` compares exactly `len(fb.data)` bytes — the *compiled* function's length — at the target address, not the original's listed extent. `target_bytes(addr, n)` is called with `n = len(fb.data)` (tools/match.py ~5152-5155). So a skeleton draft whose body is a fraction of the real function silently compares only that fraction, and the range printed in the header (`021702A0..021705F4`) is an artefact of the draft, not evidence of a mid-body `func_` label cutting the original. The real extent is still reported separately as `listing extent for the original: N bytes`, and if the short prefix *did* match the verdict would carry the trailing `*` (`EXACT*`/`MATCH*`) with the note `listing says the original is N bytes, compiled M`.
- [A short switch's interior exit-valued table entry still has to be written as an empty arm](idioms/a-short-switchs-interior-gap-still-needs-an-empty-arm.md): the rule that an exit-valued jump-table entry between two real arms is a gap the source never labelled holds only while the switch is still dense enough to table; in a short switch (cases 0, 2, 3 over a range of 0..3) the missing interior case drops the whole thing to a `cmp`/`beq` chain, and writing `case 1:` back as an empty arm (sharing the default body) is what restores the PC-relative table.
- [A signed byte sentinel reuses a live small constant with subtract](idioms/a-signed-byte-sentinel-reuses-a-live-small-constant-with-subtract.md): a store of -1 to an s8 field lets mwcc derive the full signed value by subtracting from a nearby live small constant; spelling the destination u8 instead emits movs #255 and can change the constant's scratch register.
- [A signed decrement off a zeroed counter is `subs`, not `mvns`, only when the zero stays live](idioms/a-signed-decrement-off-a-zeroed-counter-is-subs-not-mvns.md): `x = 0; *(p+0x24) = x - 1; *(p+0x28) = x - 1;` normally compiles the zero into r1 and `mvns r1, r1`, but the original here does `movs r3, #0; subs r1, r3, #1` and stores r1 twice. The difference is whether the register holding zero is the same one the `-1` result is asked for: the if-expression form allocates the destination first and folds to `mvns`, while a value whose second live use is the zero (a loop counter or an uninitialised-then-decremented local) keeps a distinct `subs` off the zero.
- [A signed index under an unsigned bound keeps `i + k` out of a callee-saved register](idioms/a-signed-index-under-an-unsigned-bound-keeps-the-window-sum-uncached.md): when a loop passes `i + k` to several calls and the image recomputes it before each call (`adds r1, r4, #0` / `adds r1, #k`) while still testing the bound with `blo`, the index is an `int` compared against an unsigned literal (`i < 8u`); an `unsigned` index makes mwcc CSE `i + k` into a callee-saved register, which pushes a live value to a stack slot and grows the frame by 4 bytes.
- [The signed `% K` magic appears twice when the source scales by 0xFFFF and divides by K again](idioms/a-signed-modulo-magic-reappears-when-the-source-divides-by-the-same-constant-twice.md): A pool magic that looks like a source constant is the compiler's own division-by-constant magic; it is emitted only for a signed dividend, and when the same magic shows up a second time the source divides by the same constant twice. `>> 4` and `/ 16` on the quotient are different code.
- [A singleton global re-read through a macro, not cached in a local, frees the low callee-saved register](idioms/a-singleton-global-read-through-a-macro-not-a-cached-local.md): when one global's address is used throughout, writing `#define G ((T*)g)` and re-evaluating it at each use gives the compiler a pure value it can keep in the *lowest* callee-saved register and lets a nearby repeated constant take the next one; binding `T *p = (T*)g;` first instead hands `p` the next register and pushes the constant down, shifting every `[rN,#off]` and the cold-block layout.
- [A small constant is rematerialised off a register that already holds zero, unless an argument shares it first](idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md): mwccarm spells a loop counter's initial 1 as `adds rD, rZ, #1` off the register holding the loop index's zero, but only if nothing earlier in the function already needed the literal 1; move the initialisation across a call and the constant is common-subexpression-eliminated with an argument instead and the instruction disappears.
- [A soft-float add puts the constant first unless it is a compound assignment](idioms/a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-assignment.md): `t + 0.5f` compiles to `__fadd(0.5f, t)` and costs an extra `mov`; only `t += 0.5f` keeps the running value in the first operand.
- [A spilled local assigned twice occupies two stack slots, later value lower](idioms/a-spilled-local-assigned-twice-occupies-two-stack-slots.md): when a narrow local is spilled and its value is overwritten before the first value dies, mwcc gives each definition its own stack slot and puts the first definition at the *higher* address; naming the two values as separate locals reproduces the original slot order.
- [A real pointer parameter spilled so its twin can hold the higher callee-saved register is a front-end tie, not a source shape](idioms/a-spilled-pointer-parameter-tie-is-the-front-ends-not-a-source-shape.md): when two pointer parameters are both live across one loop and the image homes them to `{lower-callee-saved, fp}` while our build homes the first to `fp` and spills the second to a stack slot, the extra frame word and every downstream temporary colour follow from which pointer the allocator keeps, and no source spelling moves it. This is the genuine-spill sibling of `a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie.md` (two dying loads, no spill) and of `a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md` (a *redundant* live copy forced to a slot).
- [A spilled zero-init local's store schedules independently of the guard's loads](idioms/a-spilled-zero-init-store-schedules-independently-of-the-guards-loads.md): when a zero-initialised local whose address is taken is spilled to the frame, the position of its `str r5,[sp]` among the guard's base/field loads and parameter copies is a front-end list-scheduling tie, not a source-order property; 24 measured shapes (declaration order, assignment order, copy-of-first zero, named parameter locals, late assignment, `volatile`, uninitialised neighbour) all leave the identical residue.
- [A local array's `= {0}` initializer survives where equivalent element stores are dead-store-eliminated](idioms/a-stack-array-initializer-survives-element-store-elimination.md): for a stack array whose address is passed to a call, `u32 buf[3] = {0};` compiles to `movs r0, #0` plus three `str`, and those zero stores remain even though every element is overwritten before the first call; writing the same three zeros as statements after the declaration (`buf[0]=0; buf[1]=0; buf[2]=0;`) gets them eliminated, eight bytes short. A `volatile` array reproduces the stores but reallocates the registers.
- [A stack Vec filled field by field stores in source order, and that order decides who gets the zero register](idioms/a-stack-vec-filled-field-by-field-stores-in-source-order.md): a `{x, y, z}` local whose original stores run `y, x, z` (or `x, z, y`) is three member assignments written in that store order, never `Vec v = {0, K, 0};` (a rodata copy, +12-20 bytes) nor `= {0,0,0}` plus one member; and when the zero later feeds a stack argument and a field store after several calls, the order of the three assignments also decides whether 0 or another local takes the free callee-saved register.
- [A store scheduled between the argument setup and the `bl` names the call's second argument](idioms/a-store-between-arg-setup-and-the-call-names-the-second-argument.md): when a call result is both stored to a field and copied into `r1` that is *not* the store's source register, the value is a second argument of the next call: the store just got scheduled into the gap.
- [A store moved below the table loads recolours the values it computes](idioms/a-store-moved-below-the-table-loads-recolours-its-operands.md): When the schedule hoists table loads above a computed store regardless of source order, the store's source position still decides the colouring order of its operands; moving it below the loads can rotate three registers into place.
- [A store into a field that lands after the next call means the source held the value in a local first](idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md): `obj->f = alloc(); clear(obj->f);` stores before the second call and `p = alloc(); clear(p); obj->f = p;` stores after it, and the two spellings also disagree about which register is callee-saved and whether a shared constant stays live across the call, so the one displaced `str` drags seventeen bytes of register numbering with it.
- [A store written out in each arm (no early return) is cross-jumped into one shared store block](idioms/a-store-written-in-each-arm-becomes-one-shared-store-block-without-early-returns.md): when the image has one `movs r0,#0x73; lsls r0,r0,#2; str r1,[r5,r0]` block that several arms reach with `movs r1,#k; b`, and the last arm also ends at the shared epilogue with `b`, write the identical store in every arm and let the function fall out of the if/else chain; a `return v;` in the last arm or a single `s = k;` store after the chain gives a private epilogue or a hoisted constant.
- [A call result stored then passed on stays live through a named local](idioms/a-stored-call-result-passed-on-is-a-named-local-not-a-field-reload.md): When a call result is stored through a raw offset and then passed to another call, reading the field again can emit a fresh load. Keep the result in a named local when the original passes it without reloading, including across a switch whose default consumes it.
- [A __FILE__ string whose left neighbour is a table, not a string, cannot be attested](idioms/a-string-after-a-data-table-has-no-witness.md): the `string` class fixes a string's start from the terminator of the string before it, so a file name that happens to be the first thing after a block of static data has no outside witness at all and its constructor caps at MATCH however the C is written.
- [A struct-array element subscripted per field re-adds the base at each store; an element pointer caches it](idioms/a-struct-array-element-subscripted-per-field-re-adds-the-base-at-each-store.md): when the image recomputes `p + i*12` (or indexes one field from a separate `p + off` base register, `ldrsh r0, [r6, r5]`) for each field of the same array element, write every access as `p->ent[i].field`; an element pointer (`Ent *e = &p->ent[i]` or a `u16 *q = (u8 *)p + i * 12` cursor) computes the address once and loads every field off it at a fixed offset.
- [A struct-pointer field recomputes a base that a pointer-arith lvalue caches across a call](idioms/a-struct-field-recomputes-where-a-pointer-arith-lvalue-caches.md): when one connection pointer is read at several fields whose offsets are past the Thumb load reach, `*(T *)(p + K)` makes 1.1p1 materialise the whole `p + K` address and keep it in a stack slot across an intervening call, spilling a loop value and growing the frame; reading the same fields through a struct pointer (`p->field`) makes it recompute the base per access from the parameter register, matching an original that recomputes too.
- [A struct-typed pointer keeps loop invariants after one guard](idioms/a-struct-typed-pointer-keeps-loop-invariants-after-one-guard.md): reading fields through a struct-typed object pointer (and `p->cnt[i]++`) gives the original's single guard; raw `char *` plus byte offsets duplicates the guard, hoists invariants between the guards and CSEs the else-arm load.
- [A sub-word parameter type is what decides where a constant's live range ends](idioms/a-sub-word-parameter-type-decides-where-a-constant-live-range-ends.md): changing a parameter from `u32` to `u16` changed nothing in the body of the function, yet it moved the constant zero's live range, which moved six registers, which produced the missing instruction. Liveness-respelling attempts at source level all failed; the parameter's *type* is what did it, because a sub-word parameter makes the parameter's value sub-word-typed throughout the body.
- [A subscript whose index is a sum lands wherever the source groups the sum](idioms/a-subscript-over-a-pointer-sum-associates-the-way-it-is-parenthesised.md): `base[off + i]` and `t = base + off; t[i]` are the same address, but the first associates the index (`off + i`) and then indexes `base`, the second adds to the pointer first and indexes with `i` -- and the two emit `add r0, r0, sl` / `ldrb r0, [r1, r0]` versus `add r0, r1, r0` / `ldrb r0, [sl, r0]`. Two bytes of diff, but the register pair decides which is which.
- [A swap-and-add is a per-axis swap whose sums read the new value](idioms/a-swap-and-add-is-a-per-axis-swap-whose-sums-read-the-new-value.md): `a' = b; b' = a + b` over a 12-byte vector, compiled field-wise with one spill, where the image spills old a.z (and keeps b.z in ip) but your compile spills a middle b component, comes from a per-axis swap through temps from a (`tx = a.x; a.x = b.x;` for x, y, z in turn) followed by sums that read the new a: `b.x = tx + a.x`. Writing `tx + b.x`, `b.x + tx` or `a.x + tx` instead leaves the add operands reversed; grouping the three temps first moves the spill.
- [A swapped store and read-modify-write in one if-arm recolours the whole loop](idioms/a-swapped-store-and-rmw-in-one-arm-recolours-the-whole-loop.md): when one arm of a loop holds two independent side-effecting statements (a plain store and a load-modify-store through a pointer) and the loop's callee-saved registers come out rotated with no declaration-order lever moving them, the order of *those two statements* can be the whole fault. The vendor's `.debug_line` gives the original statement order; matching it can recolour the loop's saved registers even though the arm's own instructions end up in the same slots.
- [A switch arm with no block of its own returns a constant an earlier mask left in r0](idioms/a-switch-arm-with-no-block-returns-a-constant-an-earlier-mask-left-in-r0.md): a jump-table entry that lands on another arm's bare `bx lr` is a real arm whose return value equals a mask or bound the function already had live in r0, CSE'd rather than rematerialised; and two arms returning the same constant are two blocks, while stacked case labels over one `return` are one.
- [A switch compare chain is sorted by case value, but the blocks stay in source order](idioms/a-switch-compare-chain-is-sorted-but-the-blocks-are-source-order.md): for a switch too sparse for a jump table, the `cmp`/`beq` chain is emitted in ascending case order no matter how the source orders the arms, so only the block layout tells you the source order; and `case 0:` falling into `default:` is what produces the leading compare against zero.
- [A switch index in r1 with an argument-less `bl` in one arm names a hidden argument](idioms/a-switch-index-in-r1-with-an-argless-bl-in-an-arm-names-a-hidden-argument.md): when a dense switch's dispatch (or a compare chain on the switch value) runs in r1 although nothing visible reads r0 in the arms, look for a `bl` in some arm with no argument setup before it: that callee takes whatever r0 held at the switch (an incoming parameter, or the result of the last call before the switch), and declaring it with that argument is what keeps r0 live and moves the index to r1. Return type, locals, casts and `unsigned` on the switch value do not move it.
- [A dense switch returning a flag shares one exit only as a local set by the default, not as per-arm returns](idioms/a-switch-return-flag-shares-one-exit-only-through-a-local.md): a nine-case switch that returns 0 for some values and 1 for the rest compiles to one shared exit block (a single `movs r1, #1` / `adds r0, r1, #0` / `bx lr`) only when the source declares a result local initialised to the fall-through value and lets the empty cases and `default` set it; spelling each arm as its own `return 0` / `return 1` makes the compiler emit one return block per arm and miss by 32 bytes.
- [A two-node switch tree over a dense run plus one outlier fixes how many labels the run had](idioms/a-switch-tree-over-a-dense-run-plus-one-outlier-counts-the-labels.md): for cases {16..38, 47}, 1.1p1 emits `cmp #38; bgt` to a lone `cmp #47`, then `subs #16; bmi` into a 16..38 table, only when the 16..38 run holds 10 or 11 labels; with 9 or fewer it is a compare chain and with 12 or more one 16..47 table. Holes and labels jump to the same exit when the arms are empty, so only the count and the endpoints are recoverable.
- [A switch value loaded into r1 but dispatched in r0 is read again as a call argument in an arm](idioms/a-switch-value-loaded-into-r1-but-dispatched-in-r0-is-a-later-call-argument.md): when a state machine loads `*state` into r1 (`ldr r1, [r5]; cmp r1, #4`) yet computes the jump-table index in r0 (`adds r0, r1, r1`), and the arms that call through a function table avoid r1 for the pointer (`ldr r2, [r0, r2]; blx r2`), the switch value is still live in r1 as the callee's second argument: `*state = tbl[i].fn(p, *state)`. A one-argument callback puts the whole dispatch in r0; a hidden-argument `bl` (the other r1 idiom) puts the index computation in r1 as well.
- [A table base coloured after its index is a per-arm call with an integer base](idioms/a-table-base-coloured-after-its-index-is-a-per-arm-call-with-an-integer-base.md): when several arms each load a different table address into one callee-saved register and fall into a shared block that indexes it (`ldr r6, =tblN; b calc` ... `calc: lsls r4, idx, #2; adds r0, r6, r4; ldrh r1, [r0, #2]; ldrh r0, [r6, r4]`), and the base sits in a higher register than the scaled index and the other values of the shared block, the source did not hold the table in a pointer local. Each arm called (or expanded) the shared computation with its own table, the address cast to an integer, and the identical tails were cross-jumped into one block.
- [A table load hoisted past the loop guard names a const extern table](idioms/a-table-load-hoisted-past-the-loop-guard-names-a-const-extern-table.md): when two `tbl[k]` loads sit after a `for` loop's entry guard but before the loop label (in the preheader), and the body stores through a pointer, the tables are `extern const`; a plain `extern int tbl[]` keeps the loads inside the loop, and assigning them to locals above the `for` puts them before the guard.
- [A tail call has only three argument registers, because r3 is the branch target](idioms/a-tail-call-cannot-pass-a-fourth-argument.md): `ldr r3, [pc, #n]; bx r3` spends r3 on the callee's address, so a tail call can pass at most r0 to r2; the same call written with a fourth argument becomes `push {r3, lr}; blx; pop {r3, pc}` and is eight bytes longer, and a function that tail-calls a four-parameter callee is therefore evidence that *this* translation unit declared it with three.
- [A tail call's pool word is issued before the write of its last argument, and no C moves it](idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md): for a one-section `bx ip` tail call this front end emits the pool load naming the callee after every argument instruction, while the original issues it in the slot just before the last argument write, so a bare wrapper comes out with the two instructions transposed and eight bytes of diff.
- [A temporary in one inner arm keeps the inner if/else ahead of the outer else](idioms/a-temporary-in-one-inner-arm-keeps-the-inner-if-else-ahead-of-the-outer-else.md): when a then-block ends in an inner `if (f) r = A(); else r = B();` and the outer else returns, 1.1p1 sinks the inner if/else below the outer else (the then-head gains a `b`) so its join falls into the code after the outer if. Binding one arm's call to a temporary (`t = B(); r = t;`) keeps the inner if/else in source order, with its join ending in `b rest` and the else arm jumping back to the join's store, as in the original.
- [A constant ternary used as a call argument takes the opposite branch polarity and register from the equivalent if/else](idioms/a-ternary-constant-call-argument-takes-the-opposite-branch-polarity.md): `f(cond ? 0 : 1)` emits the two calls with the *inverted* test (`bne` where the original has `beq`) and colours the surrounding pointer and result the other way; spelling it as an explicit `if`/`else` with the call in each arm reproduces the original exactly.
- [A rounding flag written as a ternary is materialised first; the relational form is folded into the call](idioms/a-ternary-flag-is-materialised-first-a-relational-one-is-folded-into-the-call.md): `(x & m) ? 1 : 0` and `(x & m) != 0` are both `tst`/`movne`/`moveq`, but only the ternary is computed before the rest of the argument list, and the difference reschedules the whole call.
- [A ternary passed as a u8 argument is cast `(u8)`](idioms/a-ternary-passed-to-a-u8-parameter-is-cast-u8.md): `lsls #24; lsrs #24` right after a two-branch merge (`b ? f(b) : 0x1f`) before a `bl` is `(u8)(b ? f(b) : 0x1f)` when the callee's parameter is `u32` (the same pair as the u16 idiom, at byte width).
- [A conditional expression predicates a load that the equivalent `if` statement will not](idioms/a-ternary-predicates-a-load-that-an-if-statement-will-not.md): `ldrne`/`ldreq` in a loop body comes from `p = cond ? p->next : p;`, a conditional *expression*; the same guard written as `if (cond) p = p->next;` is never if-converted at -O4,p and costs a separate compare and branch.
- [A threshold chain pools one base constant and derives every sibling by `sub`](idioms/a-threshold-chain-pools-one-base-and-derives-siblings.md): a descending run of `if (err >= Tn) id = ...;` comparisons does not put each `Tn` in the literal pool. 1.1p1 pools **one** base (the first threshold of the run) and derives every later one in place with `sub rT, rBase, #delta`, so the machine shows a single `ldr` followed by many `sub`/`cmp` pairs. The deltas are therefore NOT enough to recover the source: if you guess the base wrong but keep the deltas, every instruction still reads correctly and only the four-byte pool word (and the whole register rotation it feeds) is off.
- [A Thumb leaf's call site needs `thumb` on the symbols line, not the ARM name default](idioms/a-thumb-leaf-call-needs-the-isa-declared-not-the-arm-name-default.md): when a `symbols:` block is silent, match.py reads a `func_0xADDR` name as ARM; an unlabelled Thumb leaf (disasm never traces it because it saves no `lr`) then fails every code class that checks ISA and the call stays wildcarded, so declaring the true ISA is the whole fix.
- [A truncated field load into an int local keeps its source order; the same load into a u16 local can sink](idioms/a-truncated-load-into-an-int-local-keeps-source-order-a-u16-local-lets-it-sink.md): `x0 = (u16)k[1];` with `int x0` and `u16 x0; x0 = k[1];` emit the same `ldr / lsls #16 / lsrs #16`, but with the u16 local mwccarm moved the load below the later loads, re-dealt every spill slot and (in a smaller frame) kept a 64-bit ratio in a register pair the original spills. When a run of truncated loads comes out in the wrong order or the wrong slots, make the locals `int` and cast at the load.
- [A 12-byte aggregate copy pins the destination pointer and keeps the source in r2](idioms/a-twelve-byte-aggregate-copy-pins-the-destination-first.md): writing a `u64` block plus the following `u32` as one `struct { u64; u32; }` assignment makes mwcc compute the destination address first and leave the source pointer in r2; splitting it into two stores makes the allocator evaluate the source first and move the source into a callee-saved register, losing the whole byte range.
- [A two-case switch reproduces branch form where `if`/`return` if-converts](idioms/a-two-case-switch-reproduces-branch-form-where-if-return-if-converts.md): ARM `-O4,p` if-converts a chain of `if (v == k) return r;` into predicated `moveq`/`bxeq`, so the branch form of the original can be recovered by rewriting the same tests as a `switch` with explicit `case` labels and a fall-through default.
- [A two-case switch whose arms both `return` puts the default epilogue before the arms](idioms/a-two-case-switch-with-returns-outlines-the-default-exit-first.md): For a two-case `switch` where every case ends in `return`, mwccarm emits the compare chain, then the default (fall-through) epilogue, and only then the case bodies each followed by its own epilogue.
- [A two-dimensional array at a byte offset is a struct member, not a cast](idioms/a-two-dimensional-array-at-a-byte-offset-is-a-struct-member-not-a-cast.md): when a loop stores or loads `u16` elements at `p + K + row*RS + col*2` and the image keeps `K` as its own register or spilled constant (`strh rX, [rBase, rK]` with rBase = p + row*RS + col*2), declare the array as a member of a padded struct (`u16 unk_K[R][C]`) and index `((struct W *)p)->unk_K[r][c]`; the cast spelling `((u16 (*)[C])(p + K))[r][c]` folds `p + K` into one base kept in `ip` or a spill slot and changes the whole loop.
- [A two-halfword struct result stored raw and copied at +4 is one initialised local](idioms/a-two-halfword-struct-result-stored-then-copied-is-one-initialised-local.md): `bl f; add rN,sp,#0; strh r0,[rN]; lsrs r0,r0,#16; strh r0,[rN,#2]` followed by a second halfword pair copied to `[rN,#4]`/`[rN,#6]` is `Pos b = f(...);` (f returns `struct {short x, y;}` in r0). Writing `Pos a = f(); Pos b = a;` adds a third copy and a bigger frame.
- [A negated sum must be two statements or mwcc folds `-(a + b) + C` into one `rsb #C`](idioms/a-two-statement-negation-blocks-the-rsb-fold.md): `-(x) + 0x1000` and `0x1000 - (x)` compile to a single `rsb dst, x, #0x1000`, four bytes and one live register short of the image's `rsb r1, r1, #0` followed by `add r2, r1, #0x1000`. Split the negation into its own statement - `n = a + b; n = 0 - n;` - and the image's two instructions come back, with the whole block's register plan behind them. The same statement boundary also survives constant propagation only when the negation is written `0 - n`, so keep that spelling.
- [A two-value byte test kept as two compares is a switch, because `x == 0 || x == 1` folds to one unsigned range check](idioms/a-two-value-byte-test-kept-as-two-compares-is-a-switch.md): mwcc turns `if (b == 0 || b == 1)` on a byte into `cmp r0, #1; bhi exit`. When the image shows `cmp r0, #0; beq body; cmp r0, #1; bne exit`, the source is `switch (b) { case 0: case 1: ...; break; }`, which keeps both compares and costs nothing else.
- [A two-word constant table copied onto the stack is a Pair assignment](idioms/a-two-word-const-table-copied-to-the-stack-is-a-pair-assignment.md): a stack copy of an 8-byte overlay table (`ldr r1,[r0]; ldr r0,[r0,#4]; str; str` off one pool address, then indexed by `i % 2` through `add r0, sp`) is `Pair t = d_table;` on an `extern const` struct, read back as `((int *)&t)[i % 2]`.
- [A two-word copy between different bases is a struct assignment](idioms/a-two-word-copy-between-different-bases-is-a-struct-assignment.md): Two loads into r2/r0 then two stores is an 8-byte struct assignment, not two field assignments; two locals hoist the loads but allocate the registers the wrong way round.
- [A two-word region as a struct pins the stack slots that scalars let mwcc reuse](idioms/a-two-word-region-as-a-struct-pins-the-slots-scalars-let-mwcc-reuse.md): whether two adjacent words are one `struct` or two scalars decides whether mwcc may reuse the dead scalar's stack slot for another local. Both spellings are needed in the same function when the original pins one region and reuses another.
- [A two-word struct copy from a returned record recolours the destination pointer](idioms/a-two-word-struct-copy-from-a-returned-record-recolours-the-destination-pointer.md): when a function copies two adjacent words from a returned record into a destination struct (`ldr [r0]; ldr [r0, #4]; str [d, #8]; str [d, #4]`) and then uses the same values as locals, writing it as two field assignments from locals leaves the codegen identical except for a rotated callee-saved assignment (the destination pointer coloured last, r7). Writing it as one struct assignment `d->src = *s;` and reading the locals back from `d->src` (the copy's loads are reused, no reload is emitted) gives the original colouring (destination pointer r5, loop counter r6, scaled index r7).
- [A u16 accessor result held in a u16 local moves the stack-argument stores ahead of the register arguments](idioms/a-u16-accessor-result-held-in-a-u16-local-moves-the-stack-argument-stores.md): when a many-argument call stores its stack arguments after the r1-r3 setup (or after the reloads of spilled values) but the original stores them first, check whether the values come from a u16-returning accessor such as ov010's func_02159B10: declared `u16` in the prototype and held in `u16` locals, they add no instruction, yet the stack stores move ahead of the register-argument setup.
- [A u16 cast before a heap mask survives the mask](idioms/a-u16-cast-before-a-heap-mask-survives-the-mask.md): `(u16)(((u16)heap & 0x7FFF) | 0x8000)` preserves a shift pair before the mask and another after the OR; omitting the inner cast removes the first pair even though the mask clears all upper bits.
- [A u16 cast over a whole register update keeps the full 32 bit complement mask, a compound `&=` narrows it](idioms/a-u16-cast-over-the-whole-register-update-keeps-the-full-complement-mask.md): `reg = (u16)((reg & ~0x8000) | (sel << 15))` (the SDK's GX_SetDispSelect shape, with sel 0) pools the mask as 0xFFFF7FFF, while `reg &= ~0x8000` and `reg &= 0xFFFF7FFF` on the same `volatile u16` pool 0x00007FFF; the instructions are identical and only the pool word differs.
- [A halfword shifted into a byte argument is widened before the shift](idioms/a-u16-load-shifted-into-a-u8-argument-is-widened-before-the-shift.md): `ldrh; lsls #21; lsrs #24` feeding a `u8` argument is `(u32)halfword >> 3`; shifting the promoted signed halfword or narrowing it before the shift leaves extra instructions.
- [A u16 stack parameter passed to a u16 callee parameter stays behind a spill store](idioms/a-u16-stack-parameter-passed-to-a-u16-callee-stays-behind-a-spill-store.md): when a stack-passed parameter's load is hoisted above a neighbouring spill store (`ldr rN, [sp, #param]` scheduled early), declare the parameter u16 AND the callee's matching parameter u16; with both u32 the load floats up, and u16 on the parameter alone changes the size.
- [A u16 stack parameter reloaded with ldrh before every call means the callees take it as u16](idioms/a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters.md): when the image re-reads a u16 stack parameter from its home slot (`ldrh rN, [rB]` off a base register pointing at the incoming arguments) before each call that passes it, the callees' matching parameters are u16; with u32 callee parameters the compiler loads it once into a callee-saved register, which costs an extra pushed register and a bigger frame. `volatile` on the parameter also reproduces the bytes, but the callee widths are the real cause.
- [A u16 table index taken as a value's high byte is divided by 256, not shifted](idioms/a-u16-table-index-taken-as-the-high-byte-is-divided-by-256-not-shifted.md): when the original indexes a table with a u16 field's high byte through `lsrs #8` followed by a kept `lsls #16 / lsrs #14` (truncate to u16, scale by 4), write the index as `x / 256` stored to or cast to `u16`; `x >> 8` promotes to int and gives `asrs`, and a `(u32)` cast lets mwcc drop the u16 truncation pair.
- [A u32 shift count orders the field load before the bit constant](idioms/a-u32-shift-count-orders-the-field-load-before-the-bit-constant.md): in `p->f & (1 << i)` with a `u8` counter `i`, mwcc evaluates the shift first, so the `movs rX, #1` is live across the field load. When the field's offset is a spilled loop invariant, that pushes the reload into r1 and the scheduler slots `movs r0, #1` between the two loads. Writing the count as `1 << (u32)i` makes the load come first: the reload takes r0 and `movs r0, #1` follows the `ldrb`.
- [Storing a constant into a `u64` field takes a different scratch register than storing it into a `u32`](idioms/a-u64-field-store-picks-a-different-scratch-register.md): `p->f = 0x1130;` compiles to the same `ldr` and `str` whether `f` is a `u32` or the low half of a `u64`, but not into the same register: the 64 bit form has to leave the register that already holds zero free for the high half, so the pool constant lands in r2 where the 32 bit form puts it in r1; two bytes in an otherwise byte for byte constructor is the whole of the evidence that the field is 64 bits wide.
- [A `u8` decrement is spelled as the wrap-around add](idioms/a-u8-decrement-is-spelled-as-the-wraparound-add.md): `add rX, rX, #0xff` followed by `and rX, rX, #0xff` is `x + 0xff` in the source, not `x - 1`; the two wrap to the same `u8` but this compiler emits the constant exactly as written, so `- 1` gives `sub rX, rX, #1` instead.
- [A u8 field read into an int counter keeps ldrb; the counter's own type decides the compare and the increment](idioms/a-u8-field-lends-ldrb-to-an-int-counter-but-only-narrows-a-u8-one.md): A `u8` struct field assigned to an `int` loop bound still loads with `ldrb` but the loop compare comes out signed (`ble`/`blt`), and the counter only gets the `lsls #0x18; lsrs #0x18` narrowing when the counter itself is declared `u8` — a twin pair of loops over the same field can differ by exactly those two choices.
- [A `u8` index and a `u8` bit number each keep their own `lsls #0x18`/`lsrs #0x18` pair](idioms/a-u8-index-and-bit-local-keep-their-truncation-pairs.md): a byte index and a bit number held in `u8` locals survive to the object as two separate truncation pairs even though both are provably in range, because each local's own conversion is emitted at its assignment; the same values written inline in the shift expression are proved to fit and lose the pairs.
- [A callee that returns a byte count is declared u8, and the caller's count is then spilled and reloaded](idioms/a-u8-returning-callee-is-declared-u8-so-the-count-spills-and-reloads.md): when the image stores a call result to the stack and reloads it before `movs rI,#0`, with no mask after the call, the callee returns a `u8` and the caller's counter is a `u8`; declaring the extern `int` or `u32` keeps the value in r0 and drops the reload.
- [A u8-stepped counter that is re-truncated at every narrow argument is a 32-bit counter with a u8 increment](idioms/a-u8-stepped-counter-re-truncated-at-each-narrow-argument-is-a-32-bit-counter.md): a loop counter whose increment is `adds #1; lsls #0x18; lsrs #0x18` (so it wraps as a `u8`) but which still gets its own `lsls`/`lsrs` pair each time it is passed to a `u8`/`u16` callee parameter is an `unsigned int` counter stepped with `i = (u8)(i + 1)`; declared `u8`, the front end knows the value already fits and drops every argument-side pair, and the spare register can even stop the counter spilling.
- [A unit attests only its own start address, not every function inside it](idioms/a-unit-attests-only-its-own-start-address.md): the manifest records one entry per unit at the unit's start address, so folding a labelled function into the middle of a `tu` file deletes its manifest entry and drops any other file that depended on it as a `matched` witness from EXACT back to MATCH; split the unit at the address someone else needs.
- [A value returned on the early path precolours its register to r0](idioms/a-value-returned-on-the-early-path-precolours-its-register-to-r0.md): when a value loaded before a branch keeps r0 through the next block while a constant built after the branch takes r1 (`ldr r0, [..]; cmp r0, rX; ble out; movs r1, #K; lsls r1, ...; subs r0, r0, r1`), and the branch target is the epilogue, the function returns that value on the early path. The void form always colours the block-2 constant first into r0 and gives `subs r0, r1, r0`.
- [A variadic function's last named parameter reloaded from its home slot is a volatile parameter](idioms/a-varargs-anchor-reloaded-from-its-home-slot-is-a-volatile-parameter.md): when a variadic function reads its last named parameter from the home area twice (`ldr r1, [sp, #0x1c]` at entry and again just before the final call) instead of holding it in a callee-saved register, declare that parameter `volatile`. The plain spelling caches it, which shifts every register and makes the body four bytes longer.
- [A varargs counter increment is scheduled before a later format-pointer argument](idioms/a-varargs-counter-increment-is-scheduled-before-a-later-format-pointer.md): In a GSIDebugFormat-style varargs call, this front end evaluates a `counter++` argument's load/increment/store before it loads the address of a later pointer argument, even when the pointer sits earlier in the list; the DWC build of the same routine has the pointer load first, so the two call sites below cannot be byte-matched without a C spelling that forces the original order (none found).
- [A varargs function is seeded four bytes late, and its `va_start` masks before it adds](idioms/a-varargs-function-is-seeded-four-bytes-late-and-va-start-masks-before-it-adds.md): a variadic function opens with TWO pushes, and `disasm.py` labels the second one, so the worklist seeds the function four bytes into its own body; subtract four and look the address up in `layout/symbols_sdk.txt`. The three instructions after that second push are the SDK's `va_start`, and they are `add` / `bic` / `add` -- mask to a word boundary FIRST, step one word SECOND. Any other order, and any spelling built on `sizeof(last)`, is byte-wrong.
- [A Vec copy as three field moves with its y/z registers swapped is an inline setter](idioms/a-vec-copy-as-three-field-moves-with-swapped-registers-is-an-inline-setter.md): three `ldr`/`str` pairs copying a 12-byte vector (not `ldm`/`stm`, so not a struct assignment) whose y and z land in r1 and r2 in the image but r2 and r1 in your compile come from a `VEC_Set`-style `static inline` setter called as `vset(&dst, src->x, src->y, src->z)`: its arguments are evaluated right to left, and that order is what colours y into r1.
- [A DWARF `bool` in a libdwcutil object is C99 `_Bool`, not an `unsigned char` typedef](idioms/a-vendor-bool-is-c99-bool-not-unsigned-char.md): libdwcutil's DWARF types flags and parameters as one-byte `bool`; declared as `unsigned char`, a converted argument such as `pushIpAuto(x != 0)` gains an `and r0, r0, #0xff` the original lacks, while `typedef _Bool bool;` under `-lang c99` gives the bare `movne r0, #1 / moveq r0, #0` and changes nothing in functions that only store or test.
- [A vendor front end's homed parameter and live pointer copy cannot be forced by source](idioms/a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md): When the vendor object was built by a front end the tree does not have (Metrowerks 3.0.0.126), it can home an incoming parameter to a frame slot and keep a redundant pointer copy live in a callee-saved register. Our nearest front ends (`dsi/1.1p1`, `../2.0/sp1p2`) copy-propagate the redundant pointer and leave the parameter in a register, so the frame and the spill never appear and no source spelling recovers them. Park the row; do not re-derive the spelling.
- [A veneer attests nothing while its target is an unlabelled leaf](idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md): the `veneer` class needs the stub's pointer word to name a function the listing already labels, so a veneer in front of a leaf that saves no `lr` resolves nothing and the call caps at `MATCH`; the fix is one seed into `layout/function_starts.txt` for the target, not any change to the C.
- [A call through a linker veneer is an ordinary extern declared at the veneer, not at the function](idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md): when the pool word a tail call loads holds the address of a twelve byte `ldr ip, [pc, #0]; bx ip; .word target` stub instead of the callee, the C declares the extern at the stub's address and marks it `arm`; declaring the real callee reproduces a different word and the unit comes out DIFF.
- [The register a dense switch computes its jump-table index in names the function's return type](idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md): the five-instruction dispatch of a PC-relative switch table takes r0 when the switch value's register is dead afterwards and r1 when it is not, and in a function whose every arm is a single tail call the only thing that decides that is whether the function returns the callee's result or returns `void`; six bytes across five instructions, with the rest of the function byte for byte right either way.
- [A volatile field load is a shape lever: it can be neither CSEd across arms nor merged into ldm](idioms/a-volatile-field-load-is-a-shape-lever-it-cannot-be-cse-d-or-merged-into-ldm.md): `volatile` on a struct field changes instruction *count* without changing instruction selection. Two arms that both load the same table pointer stop being common-subexpressioned into one load above the branch, and two adjacent field loads stop being merged into a single `ldm`. Both are correctness-neutral and both are what the original bytes show.
- [A `volatile`-qualified local pointer spills, and its reload un-predicates a short guard arm](idioms/a-volatile-qualified-local-pointer-spills-and-un-predicates-a-short-arm.md): `volatile` on a pointer-typed *struct member* is ignored for both the pointee and if-conversion, but putting `volatile` on a local pointer variable (`struct P * volatile p = ...`) forces that variable into a stack slot, so every use reloads it; when one reload lands inside an `if` arm, the arm crosses the five-instruction predication budget and the compiler emits the original's real `cmp` / `b<cond>` / body / `b` join instead of `ldr<cond>`/`add<cond>`/`str<cond>`.
- [A walker pointer absent from the DWARF is a reused parameter, not a local](idioms/a-walker-pointer-absent-from-dwarf-is-a-reused-parameter.md): when the DWARF local list for a function has no walking-pointer variable even though the C body needs one, the original source reused an incoming parameter (or an already-declared local) as the pointer; inventing a separate pointer local adds a live value, forces an extra callee-saved register into the prologue (`push {r3, ...}`) and spills a constant, and the whole function comes out several bytes long.
- [A top-tested while loop is inverted; `for(;;)` with an explicit break is not](idioms/a-while-loop-is-inverted-a-for-loop-with-break-is-not.md): `while (cond)` is rotated into `if (cond) do { } while (cond)`, so a faithful byte match needs the un-invertible `for (;;) { c = ...; if (!cond) break; ... }` form instead.
- [A window address passed to several calls is its own pointer local](idioms/a-window-address-passed-to-several-calls-is-its-own-pointer-local.md): when an object's sub-block address `p + K` is passed to three or more calls (a text window drawn to, then flushed) and the diff is register priority, the stack-argument zeros rematerialised in the original (`movs r0,#0; str r0,[sp]` at each call) but CSE'd into a callee-saved register in yours, or K pooled once and the other offsets derived from it (`adds rN, rK, #d`), bind the address to a `u8 *win = p + K;` local where the block starts: at the top of the function, or at the top of the `if` block for a second window used only there.
- [A word copy loop that loads the destination base first is a one-word struct assignment](idioms/a-word-copy-loop-that-loads-the-destination-base-first-is-a-one-word-struct-assignment.md): in a Thumb loop `dst[k] = src[k]` over 32-bit cells, the image loads the destination base before the source value and puts the value in the dying source-base register. Plain `u32` arrays compile the value load first into a fresh register, and no spelling of the subscripts (element pointers, named locals, casts, `*(p + k)`, counter types, declaration order) moves it. Making the cell a one-word struct (`typedef struct { u32 v; } Tile;`) and copying whole elements is EXACT.
- [A zero-initialised local flag with one conditional assignment keeps zero first](idioms/a-zero-initialised-flag-with-one-conditional-assignment-keeps-zero-first.md): `int flag = 0; if (field) flag = 1;` emits `movs #0; cmp; beq; movs #1` in these Thumb callers; `int flag = field != 0;` emits the opposite one-first materialisation and differs by three bytes.
- [A zero that is stored, passed and returned is one named local assigned in memory order](idioms/a-zero-stored-passed-and-returned-is-a-named-local.md): when the original keeps a `movs rN, #0` live across a call and reuses it as the return value, write `z = 0;` once (between the field stores, in memory order) and use `z` for the stores, the call arguments and `return z`; literals fold and the register is never kept.
- [The index is added in each arm of a two-table select so the element pointer is formed once](idioms/add-the-index-in-each-arm-of-a-table-select.md): `e = (s ? base1 : base2) + i` lets the compiler fold the index into the loads (`ldrh r0,[r2,r0]` plus a second sum for the byte loads); writing `if (s) e = base1 + i; else e = base2 + i;` keeps one shared element pointer (`adds r2,r2,r0; ldrh r0,[r2]; ldrb r1,[r2,#2]`).
- [Address-of-a-global reread across an extern call cannot be forced into a cache](idioms/address-of-a-global-reread-across-an-extern-call-cannot-be-cached.md): when the original takes the address of the same global twice, once before and once after an unrelated call to an ordinary (non-`static`) extern, `-O4,p` reloads it from the literal pool both times; every C spelling tried instead has the compiler cache the address in the register the reload would have used and reuse it, costing 4-8 bytes and a different schedule, with no spelling found that reproduces the second reload.
- [Taking the address of a register parameter opens the function with `push {r0, r1, r2, r3}`](idioms/address-of-a-register-parameter-is-a-push-of-all-four.md): a function whose prologue is `push {r0, r1, r2, r3}` before its real register save, and whose epilogue is `pop {r3}` / `add sp, #0x10` / `bx r3`, has taken the address of one of its first four parameters; the four words are the home area the ABI does not otherwise reserve, and `sp + 0x10 + <saved>` is which parameter it was.
- [Address sums recomputed after every call mean the function was built with CSE off](idioms/address-sums-recomputed-after-every-call-mean-cse-was-off.md): if the image rebuilds every `base + i * k` address (and `i * k` itself) after each call in a long loop body, while 1.1p1 -O4,p on any natural spelling keeps those sums in callee-saved registers or spill slots, no source spelling we know of reproduces it. The function was compiled with global common-subexpression elimination off. Index casts that differ per statement, temporaries and `(&t[i].x)[1]` only imitate that.
- [An aggregate assignment of about 32 bytes or less is inlined as ldm/stm](idioms/aggregate-assignment-is-ldm-stm.md): a run of `ldm rX!, {r0, r1}` / `stm rY!, {r0, r1}` pairs among field-by-field moves says those bytes are one nested struct in the source.
- [An add written as its own compound statement after `r = v - k;` is not folded into the subtract](idioms/an-add-split-off-as-its-own-compound-statement-is-not-folded-into-the-subtract.md): `subs r0, r0, #4; adds r0, #0xe` (two constants mwcc would normally fold to one add) comes from `r = v - 4; r += 14;` with `r` a result local returned after the switch; one expression `v - 4 + 14`, `14 + (v - 4)`, a static inline helper and even `r = v; r -= 4; r += 14;` all fold to `adds r0, #10`.
- [An address held in a u32 local is reloaded from the pool at every site, not cached](idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md): when the image loads one pool word into r0 before each of several calls (`ldr r0, [pc, #K]` three times, one literal) where 1.1p1 caches the address in a callee-saved register, assign `(u32)&sym` to a u32 local and cast it back at each call. 1.1p1 then rematerialises the address per site instead of value-numbering it once, and the register the cache would have taken stays with its original value.
- [An address literal that no `literal` witness reaches is attested by declaring it a code symbol](idioms/an-address-literal-is-declared-by-its-isa-not-as-data.md): two address words inside a function's own range have no outside witness as constants, but if either address is a function that already has an EXACT manifest entry, declaring it `arm` (or `thumb`) in the `symbols:` block turns the ABS32 into a relocation that resolves through the `matched` class - and declaring *both* of them as symbols is also what stops the pair folding into one pool word plus a `sub`.
- [An all-return branch tree emits the outer else before the inner else only with an early return](idioms/an-all-return-branch-tree-emits-the-outer-else-before-the-inner-else.md): For a nested `if/else` where every arm ends in `return`, mwccarm lays the out-of-line `else` blocks in a fixed order. Reproducing the original's arm order often needs the inner consumer written as an early-returning `if` (with the "middle" case falling through to a following block) rather than as an `else if` chain.
- [An arg-less `bl` whose r0 still holds the previous result is a one-argument call, and it decides register allocation](idioms/an-argless-bl-whose-r0-is-still-the-last-result-is-a-one-argument-call-and-decides-registers.md): a `bl` with no argument setup right after `adds rN, r0, #0` (a copy of the previous call's result) passes that result on; declare the callee with the parameter and pass the local, even when the callee's result is dead. Left as a `(void)` call the code is byte-identical but the local has fewer uses and mwcc hands out r4-r7 in a different order.
- [An argument bound through an inline wrapper is set up after the other argument registers](idioms/an-argument-bound-through-an-inline-wrapper-is-set-up-after-the-other-argument-registers.md): when one argument of a call (a NULL stack argument, a buffer address kept in a callee-saved register) is materialised AFTER the other argument loads in the image but BEFORE them in yours, and every other byte matches, route the call through a `static inline` wrapper that takes that value as a parameter (an SDK inline such as G3_Perspective, or a small `get(s, x, y, buf)` returning buf): the inlined parameter's copy is placed after the other arguments' setup.
- [An argument-defaulting thunk is an ordinary tail call and is producible from C](idioms/an-argument-defaulting-thunk-is-an-ordinary-tail-call.md): A wrapper that pins some arguments to constants and tail-calls the real callee compiles to `ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa; bx ip` (plus the pool word) from a plain `return f(a0, 0, 10);`, so `label`/`sole-ref/code` are not needed to file it -- matching the thunk gives its callers a `matched` witness.
- [An argument equal to a local's known constant names the local, not the literal](idioms/an-argument-equal-to-a-locals-known-constant-names-the-local.md): when the image passes a callee-saved local to a call on a path where that local's value is provably a specific constant, writing the literal at the call site (`f(1)`) is a byte diff from writing the local (`f(x)`); the register that held the local is still the argument source (`mov r0, rX` vs `mov r0, #1`) even though both compute the same value.
- [An argument passed through a register must be named in the C](idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md): when a call's r0-r3 already hold the value the callee reads (the caller's own incoming argument, or the previous call's return value), mwcc emits no `mov`, so a C call with too few arguments still matches EXACT. The native port then passes nothing. House rule: name every such value in the C; the bytes do not change.
- [An arithmetic loop-carried definition colours last, unless it goes through a copy](idioms/an-arithmetic-loop-carried-definition-colours-last-unless-it-goes-through-a-copy.md): when a pointer local takes the image's first callee-saved register everywhere except once it is re-defined in a loop by an arithmetic result (`m = base + (m - bias)`, even `m = m + 4`), 1.1p1 colours it after every other local whatever the declaration order. Compute the new value into a second local and end with a plain copy (`n = ...; m = n;`): the loop-carried definition is then a copy, and m is coloured in declaration order again.
- [An ARM epilogue of `pop {..., lr}` then `bx lr` names a `-proc arm7tdmi` translation unit](idioms/an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md): the pinned `-proc arm946e` returns by popping straight into pc, so a function that restores lr and then branches to it was built for ARMv4T; passing `-proc arm7tdmi` is the whole difference and it costs four bytes per function.
- [An ARM guard block of five instructions or fewer is always predicated](idioms/an-arm-guard-block-of-five-instructions-or-fewer-is-predicated.md): at `-O4,p` this compiler predicates the body of an `if` guard in ARM code whenever the body is five instructions or fewer, and only emits `bxne lr` at six; an original that spells a short guard as an early `bx<cond> lr` is therefore unreachable from any plain C spelling of the same guard.
- [An ARM link stub that points outside every region cannot be attested](idioms/an-arm-stub-pointing-outside-every-region-cannot-be-attested.md): `E51FF004 <ptr>` / `E59FC000 E12FFF1C <ptr>` at a 4-aligned address is the `veneer` class only when the pointer word names a *labelled* function or an SDK symbol *inside* a region of `layout/layout.json`; several stubs in the 0x02005xxx boot area point at 0x027004xx and 0x02730xxx, which no region covers, so `names_known_code()` refuses them on its first condition and every call site naming the stub caps at MATCH with all its concrete bytes right.
- [An ARMv4T-style return beside a register blx names a 1.2 front end, not a -proc value](idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md): mwccarm 1.2 under `-proc arm946e` emits register `blx rN` and the ARMv4T-style return `pop {..., lr}; bx lr` in the same function, and it materialises 64-bit constants in registers where every dsi build folds them into an immediate. Those two signatures identify functions built with the older toolchain, which the project's pinned `dsi/1.1p1` can never reproduce. The fix is a per-file compiler pin in the house header, not a `-proc` and not a spelling change.
- [An array of aggregates is laid out low-to-high, so a copy run starting at the frame top needs reversed indices](idioms/an-array-of-aggregates-is-laid-out-low-to-high.md): Eight 32-byte struct copies from a global table that land at descending stack offsets (`sp+0xec` first, `sp+0xc` last) are not an array indexed in source order; `T b[8]` always puts `b[0]` at the lowest address, so the source either used eight separate locals or the array was indexed high-to-low.
- [A GF_ASSERT expression string is an offset into the file-name symbol, not a symbol of its own](idioms/an-assert-expression-string-rides-the-file-name-symbol.md): the one-character `"0"` that `GF_ASSERT(0)` passes as its third argument is usually pooled by exactly one function and is too short for the `string` class, so declaring the translation unit's string area as one object whose second member starts just past the file name puts both relocations on the file-name address, which has witnesses everywhere.
- [An assignment written inside a call's argument list pins the load in a callee-saved register](idioms/an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md): mwccarm evaluates a call's arguments right to left, so when a value has to be read twice and the second read has to survive an inner call, spelling that second read as an assignment inside the outer call's argument list (`f(a, g(), v = x)`) puts the load *before* the inner call and keeps the value in r5; the same read written as its own statement lands too early, and the same read written inline in both calls is rescheduled after the inner call and costs a callee-saved register and six bytes.
- [An early return reached by branch, not by predication, is a `goto`](idioms/an-early-return-branching-to-a-shared-epilogue-is-a-goto.md): in ARM code a guarded `return K;` is normally predicated inline (`movhs r0, #0` / `pophs`); when the original branches to a separate `mov r0, K` / `pop` block at the bottom instead, the source wrote `goto`.
- [An early spilled multiply with a copy into r0 is base first and a zero local on the offset](idioms/an-early-spilled-multiply-with-a-copy-into-r0-is-base-first-and-a-zero-local-on-the-offset.md): assigning the base before the element offset and adding a zero-valued local at the first call keeps the multiply early, spills the offset, and preserves the base in a callee-saved register.
- [An eight byte out-parameter in a five argument call is what makes the frame four bytes bigger](idioms/an-eight-byte-out-parameter-widens-the-frame-by-four-bytes.md): a function whose only stack use is two out-parameters passed to a five-argument call compiles a `u32` pair to `push {lr}` plus `sub sp, #0xC`, but the original says `push {r3, lr}` plus `sub sp, #0x10`; the second local is eight bytes wide (`u64`), not four, and only that spelling reproduces the extra word, the pushed scratch register and the wider epilogue.
- [An 8-byte pair copy loads both words before either store](idioms/an-eight-byte-pair-copy-loads-both-words-first.md): An 8-byte `struct { int x, y; }` assignment compiles as two loads then two stores, which two separate `out[0]`/`out[1]` stores do not; the load-then-store shape and the scratch-register order are the register-colouring tell.
- [An element pointer reuses the dying base register; an indexed base does not](idioms/an-element-pointer-reuses-the-dying-base-register-an-indexed-base-does-not.md): two stores into one array element through the element's address (`e = &g->arr[k]; e->a = ..; e->b = ..;`, or `*(u32 *)&b[k]`) compile the base add in place and put the stored values in dying temporaries' registers; the same stores as member accesses on an indexed base (`b[k].a = ..; b[k].b = ..;`) give the same instructions but three fresh registers and a wider push.
- [An else arm short enough to predicate is emitted before the then arm](idioms/an-else-arm-is-predicated-and-placed-before-the-then-arm.md): when the else arm of an `if (x == 0) { call } else { stores }` is short enough to predicate, the compiler emits it first (movne/strne/popne) and falls through into the then arm; an image whose predicated block sits ahead of a call is therefore the `== 0` test with the call first, not the `!= 0` test with the stores first, and the `!= 0` spelling is branched and four bytes long.
- [An empty case label at the tree's split point forces the two-node switch tree](idioms/an-empty-case-label-at-a-trees-split-point-forces-the-two-node-switch-tree.md): a sparse switch {1,2,9} that 1.1p1 lowers as a linear compare chain becomes the image's two-node decision tree (`cmp #8 / bgt` to a lone `cmp #9`, `popge`, then the {1,2} chain) only when an *empty* `case 8:` label is present to give the split a real value; and adding that label breaks the `case 0:`/`default:` tail merge, so `case 0:` has to be written as the leading label of `default:` to keep one shared epilogue.
- [An empty switch arm's jump-table entry says whether the source wrote `break` or `return`](idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md): an arm with no statements compiles to a table entry pointing straight at an epilogue, and which epilogue it picks is the one-byte tell: `break` lands on the function's *last* epilogue, the one the `default` body falls into, while `return` lands on the *nearest* preceding one; everything else about the two spellings is identical.
- [An enum Boolean return keeps the zero arm first](idioms/an-enum-boolean-return-keeps-the-zero-arm-first.md): A Thumb function returning enum FALSE/TRUE keeps the source's zero-return arm before the one-return arm. An int or unsigned int return folds the same if/else to one-first Boolean materialisation and changes three bytes.
- [An enum guard keeps a dead compare an int guard folds, and it costs no instruction to do it](idioms/an-enum-guard-keeps-a-dead-compare-an-int-guard-folds-it.md): an image that tests a value it has just set to a known constant, and branches on the result, is reproduced by typing the tested value as an enum, not by re-assigning the constant in the guarded arm. Under `-enum int` mwccarm does not propagate an enum-typed value, so `cmp rN,#0 / b<cc>` survives with no store anywhere near it. With an `int` the whole guard chain is constant-propagated and the branch is deleted. It is the *type* of the tested value that does it: the guard's own constant may be an enumerator or a bare `0`.
- [An enum local breaks a `sub`-off-zero fold but does not stop the arm predicating](idioms/an-enum-local-breaks-a-sub-fold-but-not-arm-predication.md): when an `if` arm `x = C` is folded to `sub<cond> x, x, #k` off a `mov x, #0` that precedes the test, an enum-typed local holding `C` restores the image's separate `mvn`/`mov` materialisation of the constant and gets the byte count right, but the one-instruction arm is *still* if-converted to `mov<cond> x, rT`; the leftover branch is the front-end "kept branches" tell, so the enum local separates a fixable fold from an unfixable predication.
- [An enum-typed mask local keeps `ands` with a materialised complement instead of folding to `bics`](idioms/an-enum-local-mask-keeps-ands-instead-of-bics.md): when a source masks with `& -32` / `& ~0x1f` on an `int`, mwccarm recognises the complement of a power of two and lowers it to `bics rD, rN` (two instructions fewer in Thumb). Declaring the mask as a local of enum type (`AlignMask am = ALIGN_MASK;` with `ALIGN_MASK = -32`) makes the value opaque to the folder, so the backend materialises the complement and uses `ands`, which is the image's form. This is the same "enum type keeps a value out of constant folding" lever as an-enum-type-keeps-values-out-of-constant-folding.md and an-enum-local-materialises-a-large-complement-constant.md, applied to a small mask rather than a large bound.
- [An enum local materialises a large complement constant instead of folding it off an adjacent constant](idioms/an-enum-local-materialises-a-large-complement-constant.md): when a function passes a small constant (for example `1`) in one argument register and `0x7fffffff` in the next, mwccarm folds the large value as `reg - 0x80000002` off the register that already holds the small constant; declaring the large bound as an enum *local* (`HighMax hi = HIGH_MAX;`) stops the fold and emits the image's `mvn rd, #0x80000000`, where a bare enum constant or a plain `int` local still folds.
- [An enum scalar constructor preserves bitfield masks without an aggregate frame](idioms/an-enum-scalar-constructor-preserves-bitfield-masks-without-an-aggregate-frame.md): A zero-initialized enum scalar updated with explicit masks keeps the redundant bitfield operations while avoiding the unused frame emitted for a local aggregate or an address-taken scalar.
- [An enum type keeps a value out of mwcc's early folding: SDK enum parameters and enum loop counters](idioms/an-enum-type-keeps-values-out-of-constant-folding.md): with `-enum int`, a value typed as an enum is not folded or substituted the way an `int` is. An enum loop counter keeps the unfolded `cmp; bge` entry guard with a plain increment (no `int` or narrow type gives both), and an inline whose parameters are the SDK's enum types materialises its arguments into temporaries, right to left, before the body runs.
- [An enum-typed offset local keeps a far field offset in a callee-saved register and derives the next offset from it](idioms/an-enum-typed-offset-local-keeps-the-far-offset-in-a-callee-saved-register.md): when the image does `movs r4,#0x9d; lsls r4,r4,#2` before a call, keeps r4 across it and later reaches a second field as `subs r4,#0xa8; str rX,[r5,r4]` (the second offset is the first minus a delta), the source holds the first offset in an enum-typed local (`typedef enum { K274 = 0x274 } Off; Off o = K274;`) and writes `p + o` and `p + (o - 0xa8)`; an `int` local folds to two independent constants, `p + 0x274` / `p + 0x1CC` never share the register.
- [An enum-typed zero keeps its own web where a u32 zero is folded](idioms/an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-folded.md): when the image materialises `movs rN, #0` early, among loads, and keeps it in a register that the C's other values contend for, every integer spelling of the zero (named local, `x - x`, `x & 0`, `static const`, forwarding from a cleared field) is folded before allocation. A zero held in an enum-typed local (`typedef enum { Z0 } E; E z; z = Z0;`) is not folded and gets its own web.
- [An equal shift pair applied to a parameter proves the parameter is declared wider than the cast](idioms/an-equal-shift-pair-on-a-parameter-proves-the-parameter-is-wider.md): a cast to `u16` on something already declared `u16` folds away to nothing, so a live `lsls #16` / `lsrs #16` on an argument register is positive evidence that the parameter's declared type is `u32` (or `int`) and the source wrote the narrowing itself; declaring the parameter `u16` costs four bytes and a `SIZE` verdict.
- [A linked-list walk whose test is the increment is if-converted unless the source says `continue`](idioms/an-explicit-continue-keeps-a-list-walk-from-being-if-converted.md): `p = p->next; if (p == 0) break;` at the tail of a `for(;;)` / `while (1)` loop compiles with the update and the test fused into `ldrne`/`cmpne`/`beq`; writing it as `p = p->next; if (p != 0) continue; break;` keeps two separate instructions and the plain `bne <top>` / `b <end>` pair the object has. A `do { ... } while ((p = p->next) != 0)` does **not** reproduce it either.
- [An explicit `== 0` bit test keeps the source arm order; a logical `!` on the same test flips it](idioms/an-explicit-equals-zero-bit-test-keeps-the-arm-order-a-logical-not-flips-it.md): for two returning arms guarded by one bit, `if ((f & 1) == 0) return A; return B;` puts A on the fall-through after `tst; bne`, while `if (!(f & 1))`, `if (f & 1)` with the arms swapped and the ternary all normalise to `tst; beq` with the set-bit arm first.
- [An explicit narrowing cast into a bitfield survives; a narrow parameter type does not](idioms/an-explicit-narrowing-cast-into-a-bitfield-is-not-folded.md): a `lsl #16 / lsr #16` pair in front of a bitfield insert whose mask is narrower than 16 bits is an explicit `(u16)` in the source, not a `u16` parameter; declaring the parameter `u16` instead makes the compiler drop the pair, because the insert's own mask already covers it.
- [An extra inline level reverses the stack slots of two inline helpers' locals](idioms/an-extra-inline-level-reverses-two-helper-locals-stack-slots.md): two calls to one inline helper that each copy a struct into a helper-local get their slots in a fixed order (first call's copy higher); routing one of the calls through a second inline wrapper, one level deeper, swaps the two slots and leaves every instruction unchanged.
- [An FX_Mul whose second operand is a shared radius is the inline function with the table value first](idioms/an-fx-mul-with-a-shared-radius-is-the-inline-function-with-the-table-value-first.md): when two `_ll_mul` calls take a sin/cos table entry in r0:r1 and the same s32 radius in r2:r3 (the radius kept in a frame slot and its sign word `asrs rX, r0, #0x1f` in a callee-saved register across both calls), the source is the inline `FX_Mul(fx32 a, fx32 b)` with the table value as `a`; the `((s64)(a) * (b) + 0x800) >> 12` macro in either operand order, or the inline function with the radius first, puts the radius in r0:r1 and spills both of its words (368 bytes out of 500).
- [An if-converted break needs the break to be the loop's only exit](idioms/an-if-converted-break-needs-the-break-to-be-the-loops-only-exit.md): mwccarm folds a loop's `break` into the loop's continuation condition, producing the predicated shape `cmp / beq EXIT / cmp / ldrne / cmpne / bne`, only when that break is the loop's ONLY exit. Give the loop a second exit and the compiler emits the break as a real branch instead, which costs one extra branch at the end whose target is the fall-through of the complementary `bne`. On the function below that is the entire remaining difference, and 1.1p1 at `-O4,p` never performs the redundant-exit-branch deletion that would close it.
- [The destination register of an if-converted select is the front end's, not the C's](idioms/an-if-converted-selects-destination-register-is-the-front-ends.md): `cmp rC, #0; moveq r0, rZero; movne r0, rOne` and `cmp rC, #0; movne r5, rOne; mov r0, r5` are the same 0/1 select over constants already live in `r4 = 1` and `r5 = 0`; the vendor build writes both predicated moves straight into `r0`, 1.1p1 coalesces the result onto the live zero constant and copies to `r0`, and no ternary / if/else / enum-constant / dying-local / return-type spelling changes the destination without also flipping which constant lands in r4 and r5.
- [An if/else pair of field stores counts the base pointer twice where the same store as a ternary counts it once, and that can decide which local keeps a callee-saved register](idioms/an-if-else-store-counts-its-base-pointer-twice-where-a-ternary-counts-it-once.md): when several locals that are live from entry compete for the last callee-saved register, a store written as `t->f = c ? A : B;` counts `t` once and `if (c) t->f = A; else t->f = B;` counts it twice. That one extra use can move `t` into `r7` and push a different local onto the stack. The emitted code for the store is the same either way (two pool loads, one `strh`), so the diff shows up as a whole-function register swap, not at the store.
- [An if/else that stores to the same target in both arms keeps a `b` to the next instruction](idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md): `bpl L; rsbs r1,r1,#0; b next; L: next: str r1,[..]` (a branch to the very next instruction) is `if (c) p[3] = -step; else p[3] = step;`; a negate-in-place followed by one store (`if (c) step = -step; p[3] = step;`) or the `?:` form compiles without the `b`.
- [An in-range `add #0xfd` where `sub #3` would do says the source added, not subtracted](idioms/an-in-range-add-of-a-negative-byte-constant-is-an-addition-in-the-source.md): mwccarm does not canonicalise a byte-truncated `x - k` into `x + (256-k)` or back, so a bias whose immediate is the unsigned two's-complement of a small number is what the source literally wrote; `sub`/`add` is the one-instruction tell that separates the two spellings of the same range test.
- [An indexed array inside a section struct needs its own symbol when a loop indexes it](idioms/an-indexed-array-inside-a-section-struct-needs-its-own-symbol-in-a-loop.md): with an object's statics modelled as one struct per section, a loop over a member array at a non-zero offset hoists the section base and emits `add rX, base, i` / `ldrb rY, [rX, #off]`; when the original loads `ldrb rY, [rT, i]` from a pool word that names the member's own symbol, declare that member as its own extern at its vendor address.
- [An indexed far field keeps the field offset in the load immediate](idioms/an-indexed-far-field-keeps-its-offset-in-the-load-immediate.md): `g[i].fNNN` with a stride of 4 compiles to `add r1, g, i<<2` plus a load at `[r1, #NNN]`, but the algebraically identical `*(u32 *)(g + i * 4 + N)` folds N into the base and indexes off that instead; spell the index against the element type first, `*(u32 *)((u8 *)((u32 *)g + i) + N)`, to get the original's form.
- [An initialised local array takes its address before the stores](idioms/an-initialised-local-array-takes-its-address-before-the-stores.md): `u8 buf[6] = {0, 0, 0, 0, 0, 0};` materialises `add rN, sp, #0` first and stores through rN; six separate `buf[k] = 0;` assignments store off sp and sink the address to its first use.
- [a `static inline` asm wrapper still inlines a bare `clz` — do not park the caller](idioms/an-inline-asm-static-inline-wrapper-still-inlines-a-bare-clz.md): a `clz` in the caller of an SDK function does not mean the whole caller is hand-written asm: a `static inline u32 clz32(u32 x) { asm { clz x, x } return x; }` inlines to exactly `clz Rd, Rd`, so the surrounding C body can be ordinary C. The "a clz means hand-written asm" rule is about the function whose BODY is a `clz`, not about anything that computes one.
- [A call used directly as another call's argument is scheduled per site, so five identical statements do not all come out the same](idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md): `g(f(p), x, k)` lets the compiler choose whether to evaluate `f(p)` before or after `x`, and it makes that choice independently at every site, so one source shape can be byte for byte right at three call sites and three instructions wrong at the next two; binding the inner result to a local, `t = f(p); g(t, x, k);`, pins the order everywhere and is the only spelling that reproduces a run of identical statements identically.
- [An inline helper that writes through a field pointer keeps the offset constants apart](idioms/an-inline-helper-writing-through-a-field-pointer-keeps-offset-constants-apart.md): when an original rebuilds every out-of-reach field offset from scratch (`movs #7; lsls #6; subs #6` for 0x1BA right after 0x1C0 was built the same way), the source computed those accesses inside a `static inline` helper that takes `&p->field`; writing the same code open in the caller lets mwccarm pool one offset and derive its neighbours with `adds`, and no reordering of the open code undoes that.
- [An inline wrapper's arguments are evaluated last to first](idioms/an-inline-wrappers-arguments-are-evaluated-last-to-first.md): a load of the destination that sits BEFORE the source call, with the size call before both, is `GFL_STD_MemCopy(src(), dst, size())` through a `static inline` wrapper of MI_CpuCopy8: the inline's arguments are evaluated right to left. Calling MI_CpuCopy8 directly evaluates the calls left to right and sinks every plain load after them, and a block-scope `dst` local is forward-substituted past the call too.
- [An `(int)` cast on one subscript keeps the element address inside the guard](idioms/an-int-cast-on-one-subscript-keeps-the-element-address-inside-the-guard.md): when a loop reads `tbl[i].id` into a local, guards on it, and only then forms `&tbl[i]` for the guarded body, 1.1p1 CSEs the two subscripts and hoists `adds rE, rBase, rOff` above the `cmp`; the original computes it after the branch. Writing the guard's read as `tbl[(int)i].id` (with `u32 i`) makes the two subscripts different expressions, so the element address is built inside the guarded block and the function matches.
- [An int local passed through a (u32 *) cast to an inline getter keeps its stack slot](idioms/an-int-local-passed-through-a-u32-pointer-cast-keeps-its-stack-slot.md): when the original reserves `sub sp, sp, #8` for two int locals (DWARF `[fb+0]`, `[fb+4]`) that are never read from the stack, their addresses went into an inlined `G2_GetOBJPosition(oam, (u32 *)&x, (u32 *)&y)`; 1.1p1 keeps the frame only when the address reaches the u32-pointer parameters through a cast, and promotes both with no frame when the inline takes `int *`.
- [An int-spelled object base hoists its field addresses; a struct pointer parameter keeps them inline](idioms/an-int-spelled-object-base-hoists-field-addresses-a-struct-pointer-parameter-does-not.md): when a function reads/writes many fields of its second parameter through `*(int *)(b + 0xNN)` with `b` an `int`, mwcc hoists the loop-invariant `b + 0xNN` sums into spilled or extra registers (extra stack, `b` itself spilled, str/adds order changed); declare `b` as a pointer to a struct with the fields at those offsets and the original's per-use `adds r0, #0xNN; ldr r0, [r0]` reappears.
- [An element address spelled in integer arithmetic keeps the returned address apart from the hoisted loop base](idioms/an-integer-spelled-element-address-keeps-the-return-apart-from-the-hoisted-base.md): in a search loop that calls `f(&base[i])` and returns `&base[i]` on a hit, the struct subscript lets mwcc reuse the hoisted `p + 0x28` register for the return, and the offset stays in a register. When the image instead spills `i * size` to the stack and rebuilds `p + 0x28` from `p` in the hit block (`ldr r0,[sp]; adds r5,#0x28; adds r0,r5,r0`), write both addresses as `(u32)p + 0x28 + i * size`.
- [An integer table base makes Thumb multiply into a copy of the index](idioms/an-integer-table-base-multiplies-into-a-copy-of-the-index.md): when the image copies the index before `muls` (`adds r3, r2, #0; muls r3, r0, r3`) and loads the table base after the constant, hold the base as `u32 base = (u32)p->tbl` and address the row as `base + idx * N`; every pointer spelling multiplies the index in place and loads the base first.
- [An inverted guard with a trailing return -1 hands back the compare's constant register](idioms/an-inverted-guard-returns-the-compare-constant-register.md): When the image returns a sentinel from the register that the sentinel compare used (`cmp r6, sb` / `moveq r0, sb`), write the body inside `if (i != -1) { ...; return i; }` with `return -1;` after it. An early `if (i == -1) return i;` returns the index register, and an early `return -1;` materialises a second constant and recolours the function.
- [An invisible empty label inside a jump table moves a distant table boundary](idioms/an-invisible-empty-label-inside-a-jump-table-moves-a-distant-table-boundary.md): in a large sparse switch, 1.1p1 groups the case list into jump tables and compare nodes from the total label count. One extra empty label whose value falls inside an existing table (its entry is the `break`, so nothing in the image shows it) changes the grouping at the other end of the switch.
- [An overlay thunk's SDK callee can be the overlay's own build, not the catalogued address](idioms/an-overlay-thunk-sdk-callee-is-the-overlays-own-build.md): when an overlay SDK thunk's source object relocates its tail-call pool word against a named SDK routine but the linked word lands on a `func_` label elsewhere in the overlay, declare the extern at that overlay address (with `thumb ovNNN`); the catalogued `symbols_sdk` address belongs to a different SDK build and writing the canonical name resolves to the wrong word.
- [An explicit overlay token on a contested data site costs the attestation; drop it](idioms/an-overlay-token-on-a-contested-data-site-loses-the-attestation.md): When a pool word names a data object inside an overlay, naming the overlay on the `symbols:` line can turn a resolvable site into an unresolved one, because a *hint* is refused as soon as a second overlapping overlay also starts an object at the address. Omitting the token lets the function's own region fix the choice and the site resolves.
- [An s8 local that only holds s8 fields reloads a spilled value where an int one copies it](idioms/an-s8-local-holding-only-s8-fields-reloads-a-spilled-value-instead-of-copying.md): when a local is assigned only from s8 fields (a clipped coordinate), declaring it s8 instead of s32 is value-preserving and changes the allocator's choice: the clamp value is reloaded from its spill slot instead of copied between registers, and later stack-argument stores fall back into the image's order.
- [An SDK file names its C function `func_XXXXXXXX` and puts the vendor name on the `sdk:` line](idioms/an-sdk-file-names-its-c-function-func-and-the-vendor-on-the-sdk-line.md): a pending/overlay SDK source whose C function is named with the vendor's own identifier still compiles, but `match.py one --func func_XXXXXXXX` fails with "function 'func_XXXXXXXX' not found in tu.o; object defines: ... MBi_ChildCallback"; the C identifier must be `func_XXXXXXXX` and the vendor name belongs only on the `sdk:` header line, which is the spelling `manifest` keys off.
- [An sp-relative base hoisted above a branch is an out-argument on the other path](idioms/an-sp-base-hoisted-above-a-branch-is-an-out-argument-on-the-other-path.md): when `add rN, sp, #k` sits between a compare and its branch and one arm uses it as the base for struct-field loads, look for a callee in the other arm that takes a pointer to a local at sp+k. The address is computed in both successors (field base on one side, `&local` argument on the other), so mwcc CSEs it and hoists it into the compare block. A draft that leaves the slot at sp+k as padding (or calls the callee without the out pointer) keeps the `add` below the branch and never reaches the image.
- [An out-of-range ctype guard folds to one `cmp` only when the test is unsigned](idioms/an-unsigned-char-out-of-range-ctype-guard-is-one-cmp.md): A `__ctype_mapC[c]` guard folds to a single `cmp rX,#0x80; movhs` only in the `(unsigned)(c) >= 0x80u` spelling; the signed `c < 0 || c >= 0x80` form keeps a short-circuit pair and costs several instructions.
- [An unsigned counter keeps the `subs`/`bne` of a countdown loop](idioms/an-unsigned-counter-keeps-the-subs-bne-of-a-countdown-loop.md): a hand-unrolled clear loop written with a **signed** `n` is normalised by the front end into a bottom-tested `cmp n,#0` + `bgt` with the decrement hoisted into the body, and the two loop-local scratch registers come out in the opposite order; the same loop with an **unsigned** `n` keeps `subs n, n, #1` + `bne` with the decrement on the back edge, and declaring the counter before the cursor puts the counter in `r1` and the cursor in `r2`.
- [An unsigned guard plus a signed multiply means the guard is a cast, not the variable type](idioms/an-unsigned-guard-plus-a-signed-magic-means-the-guard-is-a-cast.md): `movhs` (unsigned compare) next to `smull` with a negative magic constant is the tell: the source guards with an unsigned cast but does the arithmetic in a signed type, so `u32 x; if (x >= K)` compiles to a different (`umull`-based) sequence five bytes shorter.
- [An unsigned hoisted sum moves its CSE slot below the loop's field reload](idioms/an-unsigned-hoisted-sum-moves-its-cse-slot-below-the-loop-field-reload.md): a loop body with `(a + b)` used twice (a fixed-point multiply and an index product) hoists the sum into a spilled CSE temporary. When `a + b` is `int`, that temporary takes a slot above the per-iteration reload of a field (`p->w` read for `%` and `/`); in the image it sits one slot lower. Making the sum unsigned (here a `u32 layer` with an `int dir`) swaps the two slots. The instructions stay the same.
- [A `ldrb` of a field the function otherwise loads with `ldrsb` is a `(u8)` cast at the call, and it also stops mwcc hoisting the offset constant](idioms/an-unsigned-load-of-an-s8-field-as-a-call-argument-is-a-u8-cast-and-stops-the-constant-hoist.md): when the same s8 field is read with `movs rN,#5; ldrsb rM,[rB,rN]` everywhere except one call argument, which is `ldrb rM,[rB,#5]`, write that argument as `(u8)p[5]`; leaving it `p[5]` makes mwcc keep `#5` in a callee-saved register across the whole function and spill a real local, shifting every register and the frame.
- [An unsigned loop bound compiles to `blo`/`bls`, a signed one to `blt`/`ble`](idioms/an-unsigned-loop-bound-compiles-to-blo-not-blt.md): A counted loop whose branch is `blo` (or its zero test `bls`) is unsigned; if your C compiles to `blt`/`ble` the counter or the bound is a signed type and must be changed to `unsigned`.
- [An unsigned suffix keeps a large constant add apart from a small one](idioms/an-unsigned-suffix-keeps-a-large-constant-add-apart-from-a-small-one.md): when Thumb code adds a small immediate and then a separately built large constant (`adds r1,#0x20; movs r0,#1; lsls r0,#20; adds r1,r0`) instead of loading their sum from the pool, the large constant is an unsigned literal (`+ 0x20 + 0x100000u`); with a plain int literal mwcc folds the two into one pool word.
- [An unsigned switch keeps negative sentinels out of the low case table](idioms/an-unsigned-switch-keeps-negative-sentinels-out-of-the-low-case-table.md): switch ((u32)r) keeps cases 0..4 in their own Thumb table and tests case -2 after its range guard; switch (r) merges the signed -2..4 range, and unsigned ordering also moves a lone positive case ahead of -2/-1 in a short compare chain.
- [An empty frame word with no stack traffic is a call returning a one-word struct](idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md): a Thumb function that opens `push {r3, ...}; sub sp, #4` but never touches `[sp]` is calling something that returns a 4-byte struct by value; declare that callee's return (and the field it lands in) as a one-word struct and the frame word appears. Dead locals, `(void)&x`, arrays and struct locals are all optimised away and do not reserve it.
- [An unused frame word under a sign-extension spill is a field passed to an earlier call](idioms/an-unused-frame-word-under-a-sign-extension-spill-is-a-field-passed-to-an-earlier-call.md): Passing a field expression to an earlier call, while retaining its local for a later 64-bit multiply loop, can keep a separate dead low-word spill slot beneath the hoisted sign-extension word.
- [An unused frame word under a hoisted sign word is a hoisted long long copy](idioms/an-unused-frame-word-under-a-sign-word-is-a-hoisted-long-long-copy.md): when a loop's fx32 multiplies read a spilled `s >> 31` sign word from a slot whose lower neighbour is never touched (one extra frame word, no `r3` pad push), the source keeps a `long long` copy of the scale assigned inside the loop body; LICM hoists it as a 64-bit temporary, reserving an 8-byte slot whose low word is copy-propagated away.
- [An exact argument-register match names a coerced extern](idioms/argument-register-match-names-a-coerced-extern.md): when mwcc's only divergence from the image is the register an argument sits in, the operand type the image's instruction implies (a signed load where the C has `int`, a `u16` truncation where the C passes an `int`) is the tell: declare the callee's parameter as the unsigned or signed type the image used and mwcc stops converting the value into a fresh register.
- [Arguments left in place keep the low registers out of the scratch pool](idioms/arguments-left-in-place-keep-the-low-registers-out-of-the-scratch-pool.md): When a call site sets only r0 and leaves r1/r2 untouched, those registers may be live incoming arguments rather than leftovers, and the constraint they impose on the allocator is visible as a higher-numbered scratch register.
- [The `-proc` decides whether a two-add bias hoists above the tail-call target load](idioms/arm946e-hoists-a-two-add-bias-above-the-tail-call-target-load.md): two `add`s feeding a tail call's argument are scheduled *above* the `ldr ip, =target` under `-proc arm946e` and *below* it under `-proc arm7tdmi`; the image's order (`ldr` first) is the arm7tdmi one, so a row whose proc_hints line reads arm946e can still close on a single `-proc` change.
- [Array bases spelled as pointer locals reopen a declaration-order search that was flat](idioms/array-bases-as-pointer-locals-reopen-a-flat-declaration-order.md): a base-plus-offset array address kept as a u32 offset local and added at each use can compile to the same bytes as a pointer local computed once, yet leave a register tie that no declaration order closes; respelling it as the pointer local (the NitroSystem pArrayXxx shape) and re-sampling declaration orders can close it.
- [Assign the loop counter before the loop bound, or the zero arrives from a literal pool](idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md): when a function computes a loop bound into a stack local and then stores zero into the counter, this compiler materialises the zero with a pool word instead of `movs`, which costs four bytes of literal pool the original does not have; assigning the counter first, `for (i = 0, lim = n - 1; ...)`, gives `movs r0, #0` and the right size.
- [Assigning back into a parameter keeps that parameter's register, a fresh local takes the next one](idioms/assigning-back-into-a-parameter-keeps-its-register.md): when a function overwrites one of its own arguments with a later value, the value inherits the register the argument was living in; spelling the same thing as a new local shifts that value, and often the whole tail of the function, one register along.
- [A large struct assignment is an inline ldm/stm loop, and its step is the struct's alignment](idioms/big-struct-assignment-is-an-ldm-stm-loop.md): above the size where the compiler stops unrolling, a struct assignment becomes an inline counted `ldm`/`stm` loop rather than a call, and whether the step is eight bytes or one byte depends only on the declared alignment of the struct.
- [Binding a field to a named local is what lets both if/else arms be predicated](idioms/binding-a-field-to-a-named-local-lets-both-if-else-arms-be-predicated.md): an if/else whose arms both read the same field compiles to one predicated arm plus a branch while the field is re-read inline, and to two predicated arms with no branch at all once the field is read once into a local.
- [A modulo result bound to a local moves the add's destination and the early return](idioms/binding-a-modulo-result-to-a-local-moves-the-add-destination.md): In `x = f() % n; return x + min;` the `%` result lands in a local first, so the compiler keeps `min` in a callee-saved register, emits the early-return guard as a conditional `popeq`, and returns with a direct `add r0, r1, r5`; folding it into one expression `return f() % n + min;` instead branches to a shared epilogue and adds a `mov r0, r5`.
- [Block locals declared without initialisers colour differently from initialised ones](idioms/block-locals-declared-without-initialisers-colour-differently.md): when a two-register swap inside a nested block survives every declaration order of `int x = ...;` locals, declare the block's locals bare and assign them in separate statements. Declaration order and assignment order then vary independently, and a set of orders that no initialised spelling reaches opens up.
- [Both arms of an if/else sharing a step are factored into one unpredicated instruction](idioms/both-arms-of-an-if-else-sharing-a-step-are-factored-into-one-unpredicated-instruction.md): when two arms of a one-condition `if`/`else` compute the same step over different bases, mwccarm hoists the common step out of the arms and runs it unpredicated, feeding it a predicated base; an original that predicated the step in *both* arms is therefore unreachable from the C, and the cost is four bytes.
- [Branch-to-branch stubs before a call are tail-merged call arms](idioms/branch-to-branch-stubs-before-a-call-are-tail-merged-call-arms.md): Making the call and storing its result in each comparison-tree arm lets the compiler merge their identical tails, leaving branch stubs and a later field reload; selecting a local before one shared call produces different register and branch scheduling.
- [__builtin__clear inlines an aggregate zero where memset compiles to a call](idioms/builtin-clear-inlines-where-memset-calls.md): An aggregate zero that appears as an inlined stm/str run in the object is `__builtin__clear(p, size)`, not `memset(p, 0, size)`; every dsi 1.1p1 build turns the named `memset` into a `bl` to 0x020923B0.
- [A signed compare of two byte lengths means the operands are int locals](idioms/byte-lengths-compared-signed-are-int-locals.md): `movgt`/`blt` on two values just loaded with `ldrb` means mwcc lost their range, which only happens when they were assigned to `int` locals first; comparing the `u8` members directly makes mwcc use the unsigned codes (`movhi`/`blo`) instead, and the two spellings differ by four bytes with everything else identical.
- [Clearing a small bitfield is `bics` with the field mask, not `ands` with its complement](idioms/clearing-a-small-bitfield-uses-bics-with-the-field-mask.md): `p->f = 0` on a 3-bit field compiles to `movs r2,#0x38; bics r3,r2`; the equivalent `p[4] &= ~0x38` compiles to `movs r2,#0xc7; ands r3,r2`, so the `bics`/`ands` choice and the constant (`0x38` vs `0xc7`) are the tell that a bitfield exists.
- [A call result compared against memory only reaches `cmp`'s left slot when a named local holds it](idioms/cmp-operand-order-names-the-temporary.md): `cmp r0, r1` against `cmp r1, r0` is the one-byte tell that the function result was assigned to a local before the comparison; written inline on either side of the `!=`, this compiler always puts the memory operand first.
- [A call result reaches a commutative operator's left slot only when a named local holds it](idioms/commutative-operand-order-names-the-temporary.md): `adds r2, r0, r7` against `adds r2, r7, r0` is the same one-byte tell as the `cmp` case, and it generalises: written inline in either operand order, this compiler puts the call result on the right of `+`, and only assigning it to a local first moves it to the left.
- [Compound assignment on a byte already loaded settles a register rotation](idioms/compound-assignment-on-a-loaded-byte-settles-a-register-rotation.md): `a[p] += k` after `val = a[p]` compiles to the same instructions as `a[p] = (u8)(val + k)` (the add runs on val's register, no second load), but it numbers the values differently, and that alone can move a three-register rotation that no declaration order, scope, type or permuter run moves.
- [A compound assignment re-reads the field, the spelled out assignment reuses the cached load](idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md): `x->f += 8` and `x->f = x->f + 8` are not the same code when a local already holds `x->f`: the compound form emits a fresh `ldrb`, the spelled out form folds into the register that has the value, and the difference is three bytes in the middle of an otherwise byte for byte function.
- [Compute a store's operands before the store, not after](idioms/compute-a-stores-operands-before-the-store.md): armcc hoists independent arithmetic above a store, but it will not hoist the store above the arithmetic. When the original writes a literal first and derives the bytes that follow from it, spell the C as `compute operands; store; store derived`; storing first and computing after produces the same value but a different byte order.
- [Several __LINE__ arguments in one function are one pool word and a chain of adds](idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md): a constructor that calls the debug allocator four times passes four different line numbers, and this front end materialises only the first of them from a literal pool and derives the rest with `adds r0, r0, #k`; the deltas are the distances between the calls in the original source, so the pool word plus the three immediates recover four exact line numbers rather than one.
- [Two `blx` to the 64 bit division helper in a row are one chained expression, because it returns in the register pair it takes](idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md): `_ll_udiv` takes the dividend in r0:r1 and returns it in r0:r1, so a second call that sets only r2:r3 is `a / b / c` on a 64 bit value and not two separate divisions; the `asrs r3, r2, #0x1f` in front of each is the sign extension an `int` operand costs on the way to the 64 bit type.
- [A `const` header pointer moves the loop-closing test's load to the top of the body](idioms/const-hoists-the-loop-test-load-above-the-body-stores.md): when a counted loop's bound is a struct field that is still reloaded every iteration, whether the reload sits above or below the body's stores says whether the pointer is `const`; the `const` form also costs one extra callee-saved register.
- [const on a descriptor parameter changes the order a call's argument loads are scheduled in](idioms/const-on-a-descriptor-parameter-orders-the-argument-loads.md): when a spilled pointer parameter is re-read for two register arguments of a call, the order of those reloads follows its constness: with `const T *` the base of the second argument is reloaded before the first; without it the first comes first and an unrelated register copy moves in between.
- [const on a read-only extern table settles a register tie that reads as allocator residue](idioms/const-on-a-read-only-extern-table-settles-a-register-tie.md): a lookup table declared `extern u16 tbl[4][4]` instead of `extern const u16 tbl[4][4]` can leave a function at the right size with every register of the table-indexing half renamed; declaring the table const alone can close it.
- [const on a read-only source parameter settles a register tie that reads as allocator residue](idioms/const-on-a-read-only-source-parameter-settles-a-register-tie.md): when a function copies fields from one parameter into another, a same-size residue of one swapped register pair (the destination's parameter copy scheduled after the loads, or the loads interleaved with the stores) can be the missing `const` on the source pointer; with it mwcc knows the stores cannot alias the loads and picks the image's order and registers.
- [`const` on a read-only struct parameter recolours the whole parameter register SET](idioms/const-on-a-readonly-struct-parameter-recolours-the-register-set.md): when every instruction of a function already matches but the callee-saved register each incoming parameter is homed into is wrong, `const` on the struct parameter the body only reads is a real lever, not a front-end tie. The vendor's own header declared it const; adding the qualifier (and relaxing the callees that receive `param->field` to accept a const source) recolours the set and can make the entire prologue and body match. Check the vendor prototype before concluding a register set "cannot be forced".
- [const on an array parameter keeps the index offset in a register, not the element pointer](idioms/const-on-an-array-parameter-keeps-the-index-offset-not-the-element-pointer.md): a loop over `s[i]` whose original keeps `s` and `i * sizeof *s` in callee-saved registers, spills `i`, and re-adds `s + off` at each use (with `ldr rX, [s, off]` for the field at offset 0) is a `const T *s` parameter; a plain `T *s` makes the compiler CSE `&s[i]` into one register and spill `s`.
- [`const` on a read-only source parameter restores the vendor's two-scratch argument shuffle](idioms/const-on-the-source-parameter-restores-the-argument-shuffle.md): a small forwarder whose only residue is one extra `mov` in the argument-move sequencer (the vendor parks both pointer arguments in scratch registers `lr` and `ip`; ours needs only `ip`) goes EXACT when the source pointer the function reads through is declared `const`, together with a callee prototype that accepts it. The qualifier changes the front end's parameter homing, not the load order.
- [A const struct pointer is what lets one field load serve three out-parameters](idioms/const-pointer-lets-a-field-load-survive-a-store.md): a getter that fills several `u32 *` out-parameters reloads the struct field before every store unless the struct pointer is `const`, because a store through an unrelated pointer may alias it; adding the qualifier removes the reloads and is worth twelve bytes with nothing else changed.
- [`const` on a read-only source parameter rotates the parameter pair into place but hoists its loads past aliasing stores](idioms/const-settles-the-source-parameter-pair-but-hoists-its-loads-past-aliasing-stores.md): the source pointer's `const` can settle the parameter register pair exactly as the image wants and *still* be wrong, because it also tells mwcc the stores through the destination global cannot alias the source fields, so the whole field-load block is hoisted above the stores. Read the first two instructions, not the byte count, before believing the fix.
- [A `const` source pointer schedules a struct assignment's block load before the destination address](idioms/const-source-pointer-schedules-the-block-load-first.md): in `dst->field = *src`, a `const`-qualified `src` emits the `ldm` of the source before the `add` that forms the destination address, and a plain pointer emits them the other way round; the two instructions are otherwise independent, so this qualifier is the only thing that picks the order.
- [A spilled constant temporary takes the slot of the local initialised first](idioms/constant-temp-reuses-first-assigned-slot.md): with `int sC = -1; int s8 = -1;` this compiler sinks the initialisers and parks the reused `0x70` stride constant in `sC`'s slot; dropping the initialisers and assigning `s8 = -1; sC = -1;` puts the constant in `s8`'s slot and orders the two `-1` stores the way the original does.
- [A transcription that is too big on a straight-line vendor listing is usually N copies of one image block; count the image's distinct call sites](idioms/count-distinct-image-call-sites-to-find-duplicated-blocks.md): when a long SDK function compiles much larger than the image, the source often spells out a setup/parse tail once per path where the image has a single cross-jumped copy. The number of copies is decidable without guessing: count the decodable `bl` sites of each callee in the image's own listing and in the object, and the callee whose object count exceeds the image count names the duplicated block. Write the source with the image's sharing (a shared label / fall-through), not one copy per path.
- [Two locals live across the same loop take registers in declaration order, and the order they are initialised in is not it](idioms/declaration-order-decides-which-register-a-local-gets.md): when two locals are live across one loop, the one declared first gets the lower callee-saved register, and swapping the two declarations swaps every occurrence of both registers; the order the zeroes are stored in the compiled code is the *reverse* of the declaration order as often as not, so reading the initialisation order back as the source order is what costs the time.
- [Declaration order picks the register, initialisation order picks the load](idioms/declaration-order-picks-the-register-initialisation-order-picks-the-load.md): for a block of locals that are all loaded from the same struct up front, the order they are declared in decides which register each one gets and the order they are assigned in decides the order of the loads; when the original's register assignment and load order disagree, the two orders in the source have to disagree too.
- [A block-scope declaration's position among its neighbours decides a register pair, one slot at a time](idioms/declaration-position-orders-block-scope-colouring.md): inside a nested block, moving one declaration by a single slot among the block's other locals can swap two registers held by other variables' webs (including function-scope ones); permutation sweeps that keep the moved local fixed at the end of the list never see it, so try each insertion point of the mis-coloured local before giving up on declaration order.
- [A dense switch is a PC-relative halfword table, and the table lists the cases](idioms/dense-switch-is-a-pc-relative-halfword-table.md): a `cmp`/`bhi` followed by `add r1, pc` / `ldrh` / `add pc, r1` is an ordinary C switch, and the table of signed halfword displacements says exactly which case labels the source had and which it did not.
- [A shared early-return block across several calls only appears when they are one source-level `||`/`&&`, not an equivalent sequence of ifs](idioms/disjunction-must-be-one-expression-to-share-its-exit.md): `if (a || b || c) return 0;` tail-merges the early return for every operand but the last into one shared block; the algebraically equivalent `if (a) return 0; if (b) return 0; if (c) return 0;` does not merge at all, and grouping only some of the operands into a smaller `||` still leaves the last operand of that smaller group with the odd-one-out codegen.
- [Distinct arithmetic types keep equivalent row addresses apart](idioms/distinct-arithmetic-types-keep-equivalent-row-addresses-apart.md): When two uses of the same row address need different lifetimes, distinct arithmetic types can keep their compiler expressions apart: signed versus unsigned stride multiplication, or pointer addition versus unsigned integer addition. A single spelling can merge the row values and change recomputation, spills and register colours.
- [Distinct goto labels parked at the function tail keep lone per-arm epilogue pops from tail-merging](idioms/distinct-goto-labels-at-the-function-tail-keep-per-arm-epilogue-pops.md): when a switch arm whose body is only `return;` must reproduce a fresh `pop` written into the arm (or its jump-table slot), two things are needed: the return must have its own *distinct* target, and that target must sit after the whole switch, not beside it. A plain shared `return;`, or `goto` labels placed next to their switches, makes mwccarm tail-merge the lone `pop` into a neighbouring `...; bl; pop` and emit `b <shared pop>` instead.
- [a / b and a % b on the same operands are two calls](idioms/div-and-mod-are-two-calls.md): the division helper returns quotient and remainder together but the compiler does not know that, so the original calls it twice in a row with identical arguments.
- [`x / 8` is `lsrs` but `x % 8` is the full signed sequence, in the same expression on the same `ldrb`](idioms/divide-and-modulo-on-one-u8-field-get-different-signedness.md): mwccarm lowers `/` on a byte load as unsigned and `%` on the same value as signed `int`, so a bare `lsrs #3` next to an `lsls #29` / `subs` / `rors #29` quartet is one expression on one `u8` field; copying the field into a `u32` local first collapses the modulo to `movs #7` / `tst` and loses bytes.
- [Draft an SDK function's declarations from the object DWARF, not the disassembly](idioms/draft-sdk-declarations-from-the-object-dwarf.md): for an open SDK row, `python tools/sdkobj.py <addr> --brief` prints the defining object's DWARF prototype and the exact local-variable list with each variable's type and frame offset/register; declaring the function from that list pins the frame size, stack slots and callee-saved registers in one step, where a reconstruction drafted from the disassembly alone gets the semantics right and the allocation wrong everywhere.
- [Identical loads written out in both arms are CSE'd and hoisted above the branch](idioms/duplicate-loads-in-both-arms-cse-and-hoist.md): writing the same `*(int *)(a0 + k)` load inline in both arms of an `if`/`else` lets mwcc common-subexpression-eliminate the pair into one load, which the scheduler is then free to hoist between the compare and the branch; binding the load to a local first makes the compiler sink it below the branch, four bytes and a reordering apart.
- [DWARF lists a function's locals in reverse declaration order](idioms/dwarf-lists-locals-in-reverse-declaration-order.md): when a vendor object carries DWARF, declare the locals in the reverse of the order `sdkobj.py` prints them; the forward order swaps callee-saved registers or stack slots.
- [Every byte written through a pointer re-reads the source field](idioms/each-byte-store-reloads-the-source-field.md): When a struct field is serialised one byte at a time into a buffer reached through a global pointer, the compiler must reload that field once per byte; the original C has no local copy, and adding one collapses N loads into one and loses bytes. Pair it with the mask living *before* the shift, or the `& 0xff` folds into the `strb` and each byte costs one instruction too few.
- [A jump table with entries pointing at the exit needs those cases in the source, or there is no table at all](idioms/empty-switch-arms-are-what-make-the-table.md): mwccarm only emits the PC-relative halfword table when the case labels it can see are dense from zero, so a switch whose real arms start at 4 has to carry `case 0` through `case 3` as empty arms; written with only the three real arms it becomes a `cmp`/`beq` chain, eight bytes longer and with every register reallocated.
- [A __FILE__ argument is an ABS32 into the packed string area, not a local string](idioms/file-string-is-an-abs32-into-the-string-area.md): declare the file-name string as an extern array pinned to its address in the `symbols:` block; writing `__FILE__` puts the string in the object's own rodata and the pool word then points at the wrong place.
- [Four halfword zero stores into a stack struct are its `= {0}` initialiser, and the block it opens places them](idioms/four-halfword-zero-stores-into-a-stack-struct-are-its-zero-initialiser-placed-by-block.md): `add rN, sp, #K; strh rZ, [rN]; strh rZ, [rN, #2]; strh rZ, [rN, #4]; strh rZ, [rN, #6]` clearing an 8-byte `{u16 a, b, c; u8 d, e;}` stack local is `Local s = {0};`: mwcc clears a zero-initialised halfword-aligned struct by halfwords, while zeroing the fields one by one ends in two `strb`. The initialiser runs where its block opens, so when the stores sit after an earlier call (or at the top of a loop body), declare the struct in a block that starts there; the block's position also moves the struct's stack slot against the function-scope locals.
- [Four `lsls #16` / `lsrs #16` pairs on one value are an inlined helper with a `u16` parameter and a `u16` return](idioms/four-shift-pairs-for-one-offset-are-an-inlined-u16-helper.md): a `u16` local truncates once and a redundant `(u16)` cast on it folds away, so a value that is truncated four times in twenty instructions cannot be a `u16` variable at all; it is a `u32` passing through the argument, the parameter, the return value and the result of a small `u16`-shaped helper the compiler inlined, and reproducing it means writing `u32` locals with the cast spelled out at each of the four points.
- [Function scope versus block scope decides the order of spill slots](idioms/function-scope-versus-block-scope-decides-spill-slot-order.md): in a switch whose cases repeat one body, variables declared in each case block and the same variables declared once at function scope compile to the same instructions but hand out the spill slots in a different order; a residue that is only two spill slots swapped between two cases is this declaration fact, not the body.
- [G2_SetOBJPosition is spelled mask first, then y, then x](idioms/g2-set-obj-position-is-mask-then-y-then-x.md): the inline OAM position setter that matches every libdwcutil scene is `attr01 = (attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16)`; the x-first spelling also matches when y is the constant 0 (the or vanishes), but reverses the two `orr`s whenever y is live.
- [Give a reused accumulator its own name so the coalescer can merge it](idioms/give-a-reused-accumulator-its-own-name.md): Writing `x = x + a + b` and then using `x` again colours the callee-saved registers differently from giving the second value a local of its own; the separate name lets the register coalescer put the two back in one register, and every other live value then lands where the original has it.
- [A run of guards that all branch to one exit block is a single `&&`, not a run of early returns](idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md): this compiler gives every `if (c) return v;` its own copy of the epilogue and only tail-merges the failure path when the tests are one conjunction, so counting the epilogues in the original says whether the source wrote a chain of early returns or a single `if (a && b && c)`.
- [Guards that are separated by statements can only share one exit block through `goto`](idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md): `docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md` reads several conditional branches to one block at the end of a function as one `&&`, and that reading is unavailable when statements sit between the guards; there the only source shape that produces the shared block is an explicit `goto`, and writing the guards as separate `return`s gives each one its own copy of the epilogue.
- [An indexed field must stay inline; a named base pointer flips the base and index registers](idioms/indexed-field-stays-inline-or-base-and-index-swap.md): `*(int *)(p + K + i * 4)` scales `i` first and keeps the base in the lower callee-saved register; binding `p + K` to a named `int *s` and writing `s[i]` instead materialises the base first and moves the scaled index into the lower register, swapping `r4` and `r5` at every `ldr`/`str` and nowhere else.
- [A table slot spelled with a subscript keeps the table base in its own register; the byte-offset spelling folds it away](idioms/indexed-form-keeps-the-table-base-recomputed.md): `a[i + 1]` on an `int *` table reproduces the image's register split (table base in one register, the scaled index added fresh each pass); `*(int *)((char *)a + 4 + i * 4)` folds `a + 4` into a base register and rotates every occurrence, a pure register diff with no byte-count change.
- [Initialise the result local before the input local, or every arm of the chain grows its own return](idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md): in a function that classifies one loaded value into a result local, the order of the two initialisations decides which register holds the result, and that decides whether the arms branch to one `adds r0, rN, #0; bx lr` tail or each carry its own `bx lr`; initialising the input first is 28 concrete bytes wrong and two bytes short with identical control flow.
- [Initialising the result at its declaration costs a register for the whole function](idioms/initialising-the-result-at-its-declaration-costs-a-register.md): `int r = 0;` at the top of a function whose result is only assigned after several calls materialises a zero into a callee-saved register before the first call and pushes the compiler into spilling a parameter instead; writing `int r;` and assigning `r = 0;` at the first place it is needed reproduces the original's prologue exactly.
- [Inline helper functions colour registers differently from the same code as macros](idioms/inline-functions-allocate-differently-from-macros.md): when a hot expression (a rotate, the MD5 F/G/H/I functions, a MIN) comes out right instruction by instruction but with registers permuted and loops recoloured, write it as a `static inline` function instead of a macro. The inlined parameters become their own variables and change allocation order. When the argument is volatile, an inline function also reads it once where a macro reads it twice.
- [Keeping a cursor pointer in a named local costs a callee-saved register; re-reading the field does not](idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md): `p = s->cursor; a = p[0]; s->cursor = p+1; b = p[1];` needs a register that survives the store, which is `r4`/`r5` and a `push`/`pop`; re-reading `*s->cursor` fresh after each `s->cursor = s->cursor + 1` needs only the scratch registers the two loads already use, and is four bytes shorter.
- [ldrb on a DWARF `char` means the object was built with plain char unsigned](idioms/ldrb-on-a-dwarf-char-means-the-object-was-built-char-unsigned.md): the house base flags carry `-char signed`, so a field or table the vendor DWARF types as plain `char` compiles to `ldrsb` loads and `mvn` for a constant like 0x80; when the original loads it with `ldrb` and stores 0x80 with `mov`, the vendor built that object with char unsigned, and the field is written `unsigned char` in the C.
- [ldrsh with a register offset is a signedness tell](idioms/ldrsh-register-offset-is-signedness.md): Thumb `ldrsh` has no immediate-offset form, so one register-offset load among immediate `ldrh`s is the only evidence that that field is `s16`.
- [Locals are laid out with the later declaration at the lower stack address](idioms/local-declaration-order-is-stack-order.md): the last local declared sits at `sp+0`, so a wrong declaration order shows up only as wrong stack offsets and nothing else.
- [Logical record initialization schedules parameter loads before early stores](idioms/logical-record-initialization-orders-parameter-loads-before-early-stores.md): when Thumb record initialization has a correct field-store multiset but misplaced entry copies or stack loads, write related fields in logical record order rather than the emitted instruction order.
- [Logical result store order hoists a spilled reload](idioms/logical-result-store-order-hoists-a-spilled-reload.md): after three calls, storing their results in acquisition order lets mwcc reload the spilled second result before storing the third, while spelling the assembly's final store order reloads it too late.
- [long long aligns to four inside a struct, so a u64 field can sit at a 4-aligned offset](idioms/long-long-aligns-to-four.md): this front end gives `long long` an alignment of four, not eight, so a pair of words at an offset like +0x24 or +0x624 is one `u64` field and a two-`str` sequence is one assignment rather than two.
- [A mask built by compound statements on one local picks a different accumulator register](idioms/mask-built-by-compound-statements-picks-the-accumulator.md): `t = w + K1; t &= ~w; t &= K2;` and the single expression `(w + K1) & ~w & K2` compile to the same three instructions but not the same destination register for the middle `and`; MSL's word-at-a-time string routines use the statement form, and only that form reproduces the image.
- [Match an unlabelled callee first, and its thunks resolve as matched](idioms/match-an-unlabelled-callee-first-so-its-thunks-resolve-as-matched.md): A pool-word offset-thunk whose callee is an unlabelled leaf in the same overlay caps at MATCH; reproducing that leaf as its own EXACT entry makes the thunk's ABS32 site resolve through the `matched` class, no new image evidence needed.
- [A missing callee parameter turns an early hoisted argument into apparent dead code](idioms/missing-callee-parameter-turns-early-hoisted-argument-into-apparent-dead-code.md): when a function ends with a call whose arguments are known constants or incoming frame addresses (like a trailing memset of a local buffer), the CodeWarrior scheduler hoists those argument loads all the way to the prologue and pins the scratch registers (r0, r2) across the entire function body; if the callee prototype is missing that parameter, the compiler never emits the hoisted setup, making the original's hoisted instructions look like unexplainable "dead code" and causing a multi-register cascade across every intervening statement.
- [A narrow register parameter reaches the front of the prologue only when the stack parameters are narrow too](idioms/narrow-stack-parameters-and-callee-prototype-free-the-narrow-home-store.md): when a spilled r3 parameter's home store should lead the prologue but narrowing it alone moves it only part way, narrow the stack parameters it travels with as well, in the function and in the callee prototype, to the callee's own matched widths.
- [Two nearby code addresses written as integers fold into one pool word and a `sub`; declare them as symbols](idioms/nearby-code-addresses-fold-into-a-sub-unless-declared-as-symbols.md): two code addresses a small encodable distance apart cost one pool word plus an `add`/`sub` when they are written as integer literals, because the front end folds them before the allocator sees the pair; the original's two separate pool words only come back when each address is an `extern` function, whose relocation cannot be folded.
- [A negated if-condition on a loop-invariant flag is materialised and hoisted, so the complement flag is not in the source](idioms/negated-if-condition-is-hoisted-as-a-loop-invariant.md): for `if (flag) A else B` inside a loop, 1.1p1 computes `!flag` as a 0/1 value (`mov rX, #1 / cmp rF, #0 / movne rX, #0`), hoists it to the preheader and branches `bne B` with A as the fall-through. A register holding `!flag` before a loop is that hoisted test, not a second variable; writing the complement out (`is_high = !is_low; if (!is_high)`) gives the same loop body but moves the loop's other invariants.
- [A negative return is `mvn #(N-1)`, not `mvn #N`](idioms/negative-return-is-mvn-of-one-less.md): `mvn rX, #K` is a bitwise NOT, so the C constant is `-(K + 1)`; writing the disassembler's `#K` verbatim as `-K` is off by one.
- [A terminal `switch` reached only through one `case` lays out earlier if you nest it there](idioms/nest-a-terminal-switch-in-its-case-to-fix-block-order.md): when an outer `switch` has one case whose body is followed by a second `switch`, and every other outer case `return`s, writing the second `switch` after the outer `switch` makes the compiler emit the other outer cases' blocks first; moving the second `switch` *inside* that one case (it is semantically identical, the trailing `break` becomes unreachable) puts it in the position the image has, ahead of the remaining outer-case blocks.
- [Omitting an overlay hint can attest where naming the overlay cannot](idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md): A data symbol in overlapping overlay bss is accepted by `sole-ref/data` when the `symbols:` line carries no overlay token (the function's own region then disambiguates), but is refused as "hint contested" when the line explicitly names that same overlay.
- [Only `func_` and `sub_` names carry an address by convention](idioms/only-func-and-sub-names-carry-an-address-by-convention.md): the naming convention that lets a source file omit a `symbols:` entry is exactly `^(?:func|sub)_[0-9A-Fa-f]{8}$`; a `tbl_`/`d_`/`g_`/`pool_` data name resolves to nothing and the ABS32 site stays wildcarded at MATCH, so a data table reached from a literal pool must be pinned in the `symbols:` block with a `data` kind and an alignment token.
- [An 8-bit-immediate-sized subtraction still costs a pool word when the constant is spelled as an unsigned 16-bit add](idioms/out-of-range-immediate-subtract-costs-a-pool-word.md): `x - 0x96` where 0x96 fits an 8-bit subs immediate compiles to `subs`, but the original instead loads a pool word and adds it; the source spells the constant as its positive unsigned 16-bit two's-complement form (`x + 0xff6a`), which mwccarm never folds back down to a subtract regardless of how the literal is written, because the addend does not fit the 8-bit add-immediate either.
- [Parenthesise the offset sum: `base + (i * stride + k)` and `(base + i * stride) + k` are different code](idioms/parenthesise-the-offset-sum-base-plus-index-plus-constant.md): a pointer plus a scaled index plus a constant folds two different ways -- the constant added to the scaled index first, or the base added to the scaled index first -- and which one the source wrote shows up as the order of the two `add`s, one instruction of size and the register the multiply is allowed to use.
- [Per-channel shift statements on u8 locals interleave the colour chains](idioms/per-channel-shift-statements-interleave-the-colour-chains.md): when an RGB555 loop body in the image computes the four channel chains (extract, truncate, shift, truncate, place) interleaved across r0-r3, the source halves each u8 channel in its own statement (`b = b >> 1;`) after all four extractions. Casts inline in the packing expression (`(u8)(b >> 1) << 10`) or `b >>= 1` serialise the chains (one channel after another through r0); the order of the shift statements decides which truncation the scheduler puts early.
- [`*(p + n - 1)` and `p[n - 1]` are different code, and the original says which](idioms/pointer-minus-one-scales-before-the-subtraction.md): the subscript form folds the subtraction into the index and scales once, `subs`/`lsls`/`strh` with a register offset; the pointer form scales `n`, adds it to the base and then subtracts the element size, `lsls`/`adds`/`subs #2`/`strh` with no offset, so the three instructions that reach the last element of an array name the spelling the source used.
- [A far constant added after a base-plus-index sum names a pointer local](idioms/pointer-sum-with-a-far-offset-associates-differently.md): `base[idx + 0x157]` makes the compiler bind the far offset to the index register and sum `base + (idx + 0x157)`; the original that sums `(base + idx) + 0x157` instead had the base-plus-index sum in a named pointer local before the far offset was added.
- [The pool word for a far field of a global is the symbol plus the field offset masked by the load's reach](idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md): a global too big for one Thumb immediate is reached through several different literal pool words, and each one is the symbol plus the field offset with the low bits of that access width's reach cleared, 0x7F for a word, 0x3F for a halfword, 0x1F for a byte; reading those pool words as separate objects splits one symbol into five and costs the file every relocation it has.
- [A post-increment used as a value spends a register copy and recomputes the field's offset](idioms/post-increment-of-a-field-spends-a-copy.md): `return p->f++;` and `n = p->f; p->f = n + 1; return n;` are not the same code: the post-increment copies the loaded byte into a second register before adding one and then rebuilds the address offset it had a moment ago, so it is two instructions and four bytes longer than the spelled out version that looks like its definition.
- [Whether short guard arms are predicated is the front end, not the shape](idioms/predication-of-short-guard-arms-is-the-front-end-not-the-shape.md): four independent `if (p) *p = ...` arms of four instructions each are if-converted into `ldrne`/`andne`/`strne` chains by `dsi/1.1p1` (100 bytes) and kept as `cmp`/`beq` arms by `dsi/../2.0/sp2` (116 bytes), so an image full of guard branches is evidence for the 2.0 front end and not for an unreachable C spelling.
- [A random number below N is the high word of a 64 bit multiply, and a `movs rN, #0` next to the call is that product's high half](idioms/random-below-n-is-a-64-bit-multiply-high.md): this codebase never writes `rand() % n` or `rand() >> k`; it writes `(u64)rand() * n >> 32`, so a draw below a constant power of two is an inlined `lsrs` / `movs #0` / `lsls` / `orrs` quartet whose *result* is the register the `orrs` accumulates into, and a draw below a variable is a `_ull_mul` call whose answer is r1 rather than r0. Reading the quartet as a plain shift gives the same value and a different register allocation, and reading the `movs r1, #0` as an argument invents a parameter that is not there.
- [Raw field offsets can share a constant without an enum local](idioms/raw-field-offsets-can-share-a-constant-without-an-enum-local.md): a far offset held across calls does not always require an enum local; raw field offsets can share the compiler's constant, while a named enum gives the offset a different register or hoists a pointer sum and adds a spill.
- [Writing a derived value back into the parameter keeps the parameter's register; a fresh local rotates the whole allocation](idioms/reassigning-a-parameter-keeps-its-register.md): when a function computes something from an argument and then uses only the result, storing it back into the parameter and binding it to a new local generate the same instructions in the same order but different callee-saved registers, because a fresh local is a new virtual register that is allocated after the parameters rather than coalesced onto one.
- [Reassigning a parameter to the callee result keeps it in the same register](idioms/reassigning-a-parameter-to-the-callee-result-keeps-its-register.md): When a function replaces a parameter with a later call's result (a builder that returns its own object), write `a = f(a, ...)` rather than a new local. mwccarm then treats the parameter and the result as one value, keeps it in the one callee-saved register it already chose, and the register colouring matches the original. A distinct result local instead shifts the whole allocation and spills values the original kept live.
- [Removing `const` from a read-only parameter sinks a grouped load below a store](idioms/removing-const-from-a-read-only-parameter-sinks-a-grouped-load-below-a-store.md): the inverse of `a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer`. When a parameter is already declared `const T *` and the only residue is that *our* build issues a grouped load (an `ldm`) above a store while the original issues it below, the qualifier is the cause: with `const` the front end treats the load as unable to alias the store and hoists it. Drop the `const` and the load sinks to the original's slot, with everything after it recolouring.
- [Repeated print blocks are one static inline with the first argument bound first](idioms/repeated-print-blocks-are-one-static-inline-with-the-first-argument-bound-first.md): when a function repeats the same four-call block (fetch a string, print it into a window bitmap, set a dirty byte, free the string) and the original loads the print call's first argument (`ldr r6, [r5, #0x68]`) between the `adds r0, #0xf0` and the `ldr r0, [r0]` of the nested bitmap-getter call, and rematerialises the colour constant (`movs r0, #0x11; lsls r0, #6`) in every block, write the block once as a `static inline` helper that binds that first argument to a local before the call; written out flat, every block loads it after the nested call and the colour is kept in a callee-saved register, which shifts every register in the function.
- [Returning a just-stored halfword reloads it rather than truncating](idioms/returning-a-just-stored-halfword-reloads-it-rather-than-truncating.md): a function that increments a `u16` in memory and returns the new value ends `ldrh / add / strh / ldrh`, reading its own store back, because one `ldrh` is cheaper than the `lsl`/`lsr` pair that truncating the value already in a register would cost; the trailing load is not evidence of `volatile` and not a missed optimisation.
- [Returning the callee's result keeps it live in r0 and pushes the next temp to r1](idioms/returning-the-callees-result-keeps-it-live-in-r0.md): A wrapper that hands its callee's return value back to its own caller must keep that value in r0 across the store it does in between, so the first free temporary of that store is allocated r1, not r0. Spelling the function `void` (or discarding the call result) frees r0 and lands the temp in r0 instead, a three-instruction `DIFF` with no size change.
- [Reusing one loop variable across two phases changes the register allocation; a fresh variable does not reproduce it](idioms/reusing-a-loop-variable-across-phases-changes-the-allocation.md): a same-size residue that rotates three registers around a loop counter, and that no statement-level permutation moves, can be the counter's VARIABLE IDENTITY: the original reused a variable from an earlier phase of the function (so its live ranges merge into one allocator value), and a dedicated loop variable gives a different colouring.
- [A compiler runtime helper is a named relocation](idioms/runtime-helper-reloc.md): integer division calls `_u32_div_f`, which mwccarm leaves as an ordinary undefined reference, so it is pinned in the `symbols:` block like any other extern.
- [An SDK defining object's DWARF pins the intended register homes and exposes hidden temporaries](idioms/sdk-defining-object-dwarf-pins-the-intended-register-homes.md): when the target is a function of a vendor `.a` and the residue is register colour / spill identity, the DWARF of the *defining object* states the exact home of every local (`totalRecvbyte r8`, `endFlag r14`, `i r12`, `tmpbuf [fb+16]`, ...). Read it before spending a wave on declaration and qualifier permutations: it separates a real source-shape lever from a front-end allocator tie, and it names temporaries the C shape would otherwise miss.
- [Many TwlSDK rows have their vendor source under sdk/TwlSDK/build/libraries](idioms/sdk-rows-have-vendor-source-under-sdk-build-libraries.md): sdk/TwlSDK/build/libraries carries about 90 vendor .c files (card, fs, fx_mtx44, os, mi, gx, wm, spi pm/tp, snd, mb, wxc, ...). Before drafting an SDK function, grep there: the vendor body usually compiles EXACT under dsi/1.1p1 with the header's types inlined.
- [A shift pair whose width is not an integer type is a bitfield, because every mask spelling folds back to `ands`](idioms/shift-pair-with-no-matching-type-is-a-bitfield.md): `lsls #8` / `lsrs #8` on a loaded word cannot be written as a mask or as two shifts, both of which this compiler turns into a pool word and an `ands`; only a 24 bit unsigned bitfield survives to the shift pair.
- [A signed byte field and an unsigned byte local do not share one truncation](idioms/signed-and-unsigned-byte-fields-do-not-share-a-truncation.md): when a function both stores a wider value into a byte field and keeps its own `u8` copy of the same value, the field's signedness decides whether the compiler computes `(u8)x` once and reuses it for the `strb`, or emits the plain `strb` and recomputes the truncation later; an `s8` field breaks the CSE.
- [Two callers of the same extern attest each other, so split the unit rather than give up on it](idioms/split-a-unit-so-two-call-sites-attest-each-other.md): when the only callers of an external function are inside the range under comparison, the `label` class has no witness and the whole unit caps at MATCH; putting those callers in different ranges makes each one the other's outside witness and both come out EXACT.
- [The statement order of four independent scratch temporaries decides which scratch register each lands in](idioms/statement-order-of-scratch-temporaries-decides-their-registers.md): when a function computes several byte temporaries from the same loaded bytes and the whole body is right except that the scratch registers (`r1`/`r2`/`r3`/`ip`/`lr`) are permuted, the lever is the *statement order* of the temporary assignments, not the order of their declarations. Declaring the locals in any order is inert; writing the four assignments in the image's order recolours every load and masked value at once.
- [A 64-byte struct assignment is four ldm!/stm! pairs with both pointers reloaded from the stack](idioms/struct-assignment-copy-is-ldm-stm-with-spilled-pointers.md): `*dst = tmp;` for a 64-byte struct compiles to `ldr r4,[sp,#s]; ldm r4!,{r0-r3}; str r4,[sp,#s]; ldr r4,[sp,#d]; stm r4!,{r0-r3}; str r4,[sp,#d]` repeated, which looks like inline asm. Its stack-resident pointers raise register pressure for the whole function, so the rest of the function spills early too.
- [Field stores through a struct type keep source order; raw pointer offsets get rescheduled](idioms/struct-field-stores-keep-source-order-raw-offsets-do-not.md): two field stores at fixed offsets written through a typed struct keep their source order and the object base in r0, while the same stores spelled `*(int *)(p + n)` are reordered and the base register is freed for a later pool load.
- [A compare-chain switch tests its cases in label order but emits its arm blocks in source order](idioms/switch-arm-blocks-are-laid-out-in-source-order-not-case-order.md): when mwccarm turns a small dense switch into a chain of `cmp`/`beq` instead of a table, the chain is always in ascending case-label order whatever the source does, but the blocks those branches point at are laid out in the order the cases appear in the source; so the arms have to be written in the image's block order, which is not necessarily numeric order.
- [Switch arm bodies are laid out in source order, not in case-value order](idioms/switch-arm-bodies-are-laid-out-in-source-order.md): mwccarm builds the comparison tree from the *values* but places the arm bodies in the order the case labels appear in the source. Two switches with identical case sets compile to different code and different branch targets; when the tree matches and the targets do not, reorder the cases rather than touch the bodies.
- [Switch arm stubs are laid down in source order, not case order](idioms/switch-arm-stubs-are-laid-down-in-source-order.md): when several case labels share one body, mwcc emits each arm at its source position and tail-merges the duplicates into a `b` stub to the last copy, so the arm addresses (and therefore the jump-table stubs) appear in the order the cases were written; a non-monotonic source list can be the only spelling that reproduces the image.
- [What both arms of a switch do is emitted once, and the default jumps over it](idioms/switch-arms-tail-merge.md): an assignment made by every case of a switch is tail-merged into a single block the default case branches past, so writing it after the switch instead moves one branch target and reallocates every register in the function.
- [Switch case bodies are emitted in source order, table entries are indexed by case value](idioms/switch-case-bodies-are-laid-out-in-source-order.md): A dense `switch` whose bodies are not laid out in numeric case order means the source listed its cases in that order, not 0..N; reordering the `case` labels to the body order is what fixes the jump table.
- [The boundaries of a switch's jump-table run depend on the whole case-value set](idioms/switch-run-boundaries-depend-on-the-whole-value-set.md): mwccarm builds one decision tree over all the case values and only a leaf subtree whose values are dense and numerous enough becomes a PC-relative table; a single case value you have not accounted for elsewhere in the switch can move the tree's split points, so a contiguous run that tables by itself becomes a shorter run that falls back to a compare chain. When the image has a compare chain where you produce a second jump table, suspect a missing case value near the run, not the run itself.
- [Table loads held in temporaries before the stores are read through a cast pointer](idioms/table-loads-held-before-the-stores-are-read-through-a-cast-pointer.md): when the image loads all three components of a table triple (often in z, y, x order, one spilled, the table's pool word reloaded for each) and only then stores them, but your compile interleaves load, store, load, store, read the table through a pointer cast (`((s16 *)tbl)[k + 2]`) of an object declared with another type. mwccarm treats a plain extern array element as unable to alias a store through a pointer parameter and sinks each load to its store; through the cast it must keep the loads above the stores, so an inline setter's right-to-left arguments survive as temporaries.
- [A tail call is always `ldr r3, [pc, #n]` and `bx r3`, even to the next function in the same file](idioms/tail-call-is-a-pool-word-and-bx.md): one PROGBITS section per function means the compiler cannot encode a displacement to any other function, so a tail call materialises the target's address through an ABS32 pool word and `bx`; a four to eight byte function with no prologue at all is that and nothing else.
- [In a chain of commutative operators the result register is the second operand's, and the first is folded into it](idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md): `e1 ^ e2 ^ e3 ^ e4` evaluates every operand into its own register but accumulates into the one holding `e2`, so the operand the original folds in first is the source's *first*, not the one whose value the accumulator starts with; swapping just the leading pair costs a fifth register and a `push`.
- [The arm that falls through is the one the source wrote first](idioms/the-fall-through-arm-is-the-source-order.md): this compiler never reorders the two arms of an `if`, so the code immediately after the conditional branch is the source's `then` and the code the branch jumps to is what came after it; getting the polarity wrong is a whole-function diff, not one instruction.
- [The last labelled function in an overlay has no follower, so show reports a 64-byte stub extent](idioms/the-last-labelled-function-in-an-overlay-shows-a-64-byte-stub-extent.md): `match.py show` sizes a function by the next `func_` label; when the function is the last labelled one in the overlay there is no next label, `target_extent` returns nothing, and `show` silently falls back to `0x40`. The real extent runs to the literal pool (and its 4-byte alignment nop), found by following the return path or passing `--size`.
- [The register a scratch temporary lands in counts the arguments a forwarding call still holds](idioms/the-register-a-temporary-lands-in-counts-a-forwarding-calls-arguments.md): when a function computes something into a scratch register and then calls an extern that never sets r1, r2 or r3, the temporary's register number is the argument count: it lands in the lowest scratch register the incoming arguments do not already occupy, so r1 means one parameter, r2 two, r3 three, and reading those untouched registers as "leftovers" leaves the arity one, two or three short.
- [The second term of a two-multiply sum is the one that becomes the `mla`](idioms/the-second-term-of-a-multiply-sum-takes-the-mla.md): in `a * k1 + b * k2` the compiler emits `mul` for one product and `mla` for the other, and which term gets the `mla` follows the *source order* of the terms - so the same values with the two terms written the other way round lose the paired load that goes with them.
- [Three field stores fuse into one `stm` in only one source order, and it is not field order](idioms/three-field-global-store-fuses-only-in-one-write-order.md): a run of `str` into consecutive words of one global fuses into a single `stm` only when the parameter that is already in its argument register is written first and the two that need a `mov` are written last; any other order leaves the first store stranded as a separate `str` and costs four bytes.
- [The reach of the Thumb immediate decides whether a field access costs an adds](idioms/thumb-immediate-reach-costs-an-adds.md): `ldr` reaches +124, `ldrh` +62, `ldrb` +31, so a field past the limit costs an extra `adds rN, #imm` that is an encoding artefact and not a pointer in the source.
- [Two adjacent equality tests on a u16 fold to a pooled 0xFFFE add, not `subs #2`](idioms/two-adjacent-equality-tests-fold-to-an-add-of-minus-n-from-the-pool.md): `x == 2 || x == 3` on a u16 compiles to `ldr rN, =0xFFFE; adds rN, x, rN; lsls/lsrs #16; cmp rN, #1; bhi` (and is hoisted out of a loop into a spill slot); the hand-folded `(u16)(x - 2) <= 1` gives `subs rN, x, #2` instead, and `x >= 2 && x <= 3` keeps two compares.
- [Two arms write the shared tail out and the third branches backward into one of them](idioms/two-arms-write-the-tail-out-and-the-third-branches-back-into-one.md): a BACKWARD branch from a late block into the middle of an earlier one says the source has the shared statements written out in some arms and an explicit `goto` into one of those copies from another. Writing them once behind a label lets the compiler cross-jump every arm into a single block and moves every branch target after it.
- [Two case labels that assign the same value are one arm with the default fallen into](idioms/two-cases-with-one-body-are-written-as-case-then-default.md): when the image's compare chain has one `cmp` per distinct case value but only one block for several of them, the C has the extra label written as a fall-through into `default:`; giving the two arms their own identical assignment instead leaves the second one inline in the chain and adds an unconditional branch past it.
- [Two DMA calls that share one NDMA test are one explicit branch, not two MI_Dma inlines](idioms/two-dma-calls-under-one-ndma-test-are-one-explicit-branch.md): when two DMA fills or copies in a row reload `GXi_DmaId` but test `dmaNo > 3` only once, with the statement between them duplicated into both arms, the source branched on the channel itself (`MI_NDmaFill` in one arm, `MIi_DmaFill32` in the other); two calls through the `MI_DmaFill32` inline test the channel twice and come out 20 bytes longer.
- [Two failure returns need two distinct labels, or the compiler merges them into one predicated tail](idioms/two-failure-returns-need-two-labels-or-the-compiler-merges-them.md): when the image carries two near-identical `mov r0,#0` / `pop` blocks, one per guard, a plain `return 0;` in each guard (or one shared `fail:` label) is cross-jumped into a single predicated `moveq r0,#0` / `popeq` and the function comes out four bytes short; two DISTINCT labels at the end of the function, one per guard, is what keeps both copies.
- [Two identical calls in the arms of an if/else are cross-jumped: only the differing argument is set up in each arm](idioms/two-identical-calls-in-if-else-arms-are-cross-jumped.md): writing the same call in both arms of an `if`/`else` whose only difference is one constant argument produces one call site with the constant materialised separately in each arm, not two calls; the equivalent shape that assigns the constant to a local first materialises the value early and reallocates registers, and a ternary sends the constant through a different path again.
- [Two live pool-global bases: the one whose store comes first in the source gets `lr`, the other gets `ip`](idioms/two-live-pool-global-bases-swap-ip-and-lr.md): with two fixed-address globals both live in the opening block, mwccarm hands the first base to `lr` and the second to `ip`, and which is "first" is decided by the source order of their first stores, not by the emitted instruction order; putting the second global's store after a pointer local, `volatile`, or a repositioned clamp does nothing, but moving it ahead of the other global's stores flips the pair.
- [Two unsigned range booleans combined with AND test a rectangle](idioms/two-unsigned-range-booleans-combined-with-and-test-a-rectangle.md): two subtract-and-unsigned-compare sequences that each materialise 0 or 1 before an AND are independent inclusive range tests combined with bitwise `&`; preserve both materialised booleans rather than short-circuiting.
- [A size local typed like its u8 getter keeps each loop guard on a spilled `w - 1`](idioms/u8-size-locals-keep-the-loop-guard-on-a-spilled-cse.md): if a SIZE diff has stack slots for both `w - 1` and `(w - 1) * 8`, a loop guard of the form `ldr [sp]; cmp #1; ble` on that stored `w - 1`, and a loop bound that is computed again from `w`, declare the size locals `unsigned char` like the getters they come from. As `int` locals the guard stops sharing the corner offsets' common subexpression, and the function comes out shorter.
- [A shift pair with unequal amounts is a narrowing cast folded with a shift, not a bitfield](idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md): `lsls #a` / `asrs #b` with `a != b` is `(s<32-b>)(x << (a - b))`, and `lsls #a` / `lsrs #b` is the unsigned twin; only the equal-amount pair is the type conversion or bitfield that `shift-pair-with-no-matching-type-is-a-bitfield.md` describes, so reading an unequal pair as a bitfield invents a struct that is not there.
- [Unfolded shift sums come from shifted locals computed before the stores](idioms/unfolded-shift-sums-come-from-shifted-locals-computed-before-the-stores.md): when the image keeps `(a << 12) + (b << 12)` as two shifts and an add (not `(a + b) << 12`), and one shifted value is stored late from a third register, the source holds each `pos << 12` in a local, computes both locals before any of the stores, and declares the second local first. Any spelling where both shifts sit in one expression tree (plain statements, inline helpers with int parameters, nested helpers, casts, `* 0x1000`) folds the sum.
- [Half the accessors in a file are printed as .word data, not as code](idioms/unlabelled-leaf-functions-hide-in-word-runs.md): `disasm.py` labels a function only if it opens with a prologue that saves `lr`, so every leaf accessor that saves nothing lands in the listing as a run of `.word`s between two literal pools, and a unit that stops at the last labelled function leaves most of the original file unmatched.
- [Unsigned address scaling preserves an index admitted by a signed guard](idioms/unsigned-address-scaling-preserves-a-full-word-index.md): A signed `index < 3` guard also admits negative full-word values. Spell the following scaled address as unsigned 32-bit multiply/add to preserve the original wrapping `lsl` and address addition; a signed multiply can emit identical bytes while its C has overflow.
- [An unsigned loop counter emits `blo`, a signed one `blt`](idioms/unsigned-loop-counter-emits-blo-not-blt.md): The bound compare at the bottom of a counted loop encodes the counter's signedness, so `blt` versus `blo` says whether the C declared `int` or `unsigned`.
- [A vendor front end's parameter-to-callee-saved register SET cannot be forced by source](idioms/vendor-front-end-parameter-register-set-cannot-be-forced.md): When a function is byte-identical in instruction *schedule and opcodes* and the only difference is which callee-saved register each incoming parameter is homed into, that is the front end's register allocator, not a source shape. Declaration-order permutations, statement reorders, moving a local's declaration across others, and adding a same-typed local are all inert. Park the row and log the register set; do not re-derive the spelling.
- [Volatile on a just-stored field forces the object's reload](idioms/volatile-on-a-just-stored-field-forces-the-objects-reload.md): when a ternary assigns a struct field and the else-arm passes that same field to a call, mwccarm forwards the value it just stored and needs a `mov` to move the call result into the select's result register; making the field `volatile` re-reads it at the call, which is what the original does, and the whole downstream register rotation follows.
- [`volatile` on a pointer-typed struct member is ignored, qualify the pointed-to struct instead](idioms/volatile-on-a-pointer-typed-member-is-ignored.md): mwcc 1.1p1 forwards a store to a following load of the same member even when the member is spelled `struct Node * volatile next`; the same member declared `volatile int`, or reached through a `volatile struct Node *`, keeps the load.
- [Two reads of a hardware address are two named locals, and the address is a cast constant](idioms/volatile-reread-needs-two-locals.md): `(X << 8) | X` on a volatile lvalue interleaves the shift between the two loads and relocates the address as an extern; the original loads twice into locals and reaches the address through a cast integer constant, which is a different register allocation and no relocation at all.
- [Write the complemented compound condition so the short else is the fall-through](idioms/write-the-complemented-compound-condition-so-the-short-else-is-the-fall-through.md): when the image lays a short `else` arm *before* a long `if` body and enters the body with a taken `bne` off a two-part (`&&`) test, write the source as `if (!(A && B)) { short } else { long }` and put the callee result in a named local before zeroing the returned value; the obvious `if (A && B) { long } else { short }` instead branches to a trailing else and moves the post-call zero.

<!-- idioms:end -->

## The manifest is sharded

`layout/matched.json` used to be one file, which made a manifest write the one
genuinely serial step of a parallel wave: every agent that finished a packet
had to queue behind the integrator. It is one file per packet now,

```
layout/matched/<region>/<shard>.json
```

with `<shard>` taken from a `packet:` line in the source file's header, so an
agent working `pkt_0209CE10` writes
`layout/matched/arm9/pkt_0209CE10.json` and nothing else. Two agents never
touch the same file, so merging a wave is a directory union.

Shard ids are archival, not live. `worklist.py` dissolves a packet as soon as
its functions stop being open, but the shard that recorded that work keeps its
name for ever. That is why the id comes out of the source header rather than a
lookup in `layout/worklist.json`, which would move entries between shards on
every refresh. Everything matched before `worklist.py` existed sits in
`arm9/legacy.json`, and the SDK calibration entries in `arm9/calib.json`.

```
python tools/match.py manifest                     rebuild every shard
python tools/match.py manifest --verify            recompile and verify all
python tools/match.py manifest --verify --shard pkt_0209CE10
python tools/match.py manifest --migrate           one-time, from matched.json
```

`--verify` rewrites only the shards whose entries actually changed, so a wave
that adds one packet produces a one-file diff. `--shard` verifies one shard and
writes one shard, which is what a packet agent runs against its own work
without reading or touching anyone else's.

`match.load_manifest_entries()` is the one reader: `csrc.py`, `build.py` and
`worklist.py` all go through it rather than opening manifest files of their
own, so there is one implementation of the shard union and one of the
compatibility check. That check exists because leaving both the old
`layout/matched.json` and the shards in the tree is the one way this refactor
could silently lose work: two tools would disagree about what is matched, and
the build would splice one set while the manifest recorded another. Any
`layout/matched.json` found next to the shards is a hard error naming the
migration, whether or not its content agrees.

## How C enters the build

`src/` is no longer inventory. `tools/build.py` compiles every entry of
every manifest shard and puts the resulting bytes into the image it verifies
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
error: matched C source regression: unit_02008828
       (src/matched/unit_02008828.c) is DIFF at 0x02008828, not EXACT;
       refusing to splice
  offset     ORIGINAL @ 0200894C                    | COMPILED
  ------------------------------------------------------------------------
    +0008    adds r0, #0x73                         | adds r0, #0x73
    +000A    ldrb r0, [r0]                          | ldrb r0, [r0]
  * +000C    strb r0, [r1]                          | adds r0, r0, #1
  * +000E    bx lr                                  | strb r0, [r1]
```

### Overlapping entries

The manifest deliberately records both `sub_020084BC` and the unit
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

These numbers move with every wave; the authoritative current count is what
`python tools/csrc.py` prints (at the time of the matched-class work: 234
entries, 34938 bytes, from a manifest of 236). Entries subsumed by the units
that contain them are not spliced separately. All 242 regions stay `PASS` with those bytes in place
and the ROM still verifies at
`26ad0b9967aa279c4a266ee69f52b9b2332399a5`.

Across the whole of `arm9_main`, `tools/worklist.py --summary` reports 202 of
5370 functions and 5888 of 406204 game code bytes matched, 1.4495%. That count
is of functions the listings carry a label for, so it is lower than the
manifest's 329: an accessor with no register-saving prologue is matched all the
same, it just was never labelled.

The attestation wave that followed wave 1 added 172 of those bytes and four
entries, three of them new files:

| range | bytes | what closed it |
| --- | --- | --- |
| 0x02005794..0x020057C4 | 48 | the `veneer` class |
| 0x02005DF8..0x02005E30 | 56 | a cut `--suggest-split` found |
| 0x02005E30..0x02005E50 | 32 | the other half of that cut |
| 0x02007AA4..0x02007AC8 | 36 | the `string` class, padding window widened |

```
python tools/csrc.py              # what the build would splice, and from where
python tools/build.py --split --pack
python tools/build.py --no-c      # the same, pure assembly
```

`tools/provenance.py` is a read-only report over an existing build (`build/` and `extract/`) that
classifies every byte of the ROM: compiled from our C, reassembled from listings (code or data words),
filesystem files, ARM7 and other binaries copied from the extract, header and banner, and padding. Overlay
and ARM9 bytes are counted on the decompressed image; a second table sums the stored, BLZ-compressed bytes
to the ROM size. It learns the extent of each spliced entry by compiling it once, caches the result outside
the repository, and never rebuilds or writes into the tree. `--json` gives the same numbers for scripts,
`--verify` checks the ROM slices against their sources, and `--assets` adds the count of filesystem files
the asset converters round-trip.

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

# one shard only: what a packet agent runs on its own work
python tools/match.py manifest --verify --shard pkt_0209CE10

# the attestation rules: 57 cases, the label, veneer, literal, string, matched
# and pairwise classes with their negatives, plus the three resolver behaviours
python tools/match.py selftest

# where a MATCH-capped unit could be cut, and what the census says
python tools/match.py tu --src src/matched/unit_02005DF8.c \
    --addr 0x02005DF8 --thumb --suggest-split

# the three ranges the new classes closed
python tools/match.py tu --src src/matched/unit_02005794.c \
    --addr 0x02005794 --thumb     # veneer
python tools/match.py tu --src src/matched/unit_02005E30.c \
    --addr 0x02005E30 --thumb     # the split
python tools/match.py tu --src src/matched/unit_020079BC.c \
    --addr 0x020079BC --thumb     # string, "box_savedata.c"

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
python tools/match.py tu --src src/matched/unit_0200857C.c \
    --addr 0x0200857C --thumb
python tools/match.py tu --src src/matched/unit_02008700.c \
    --addr 0x02008700 --thumb
python tools/match.py tu --src src/matched/unit_02008828.c \
    --addr 0x02008828 --thumb

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
