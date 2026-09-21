# Agent brief

The condensed operating manual for a packet decompilation agent. Read this
instead of `docs/PARALLEL.md` and `docs/MATCHING.md` for routine work. Fall
back to those two documents (and the relevant `docs/idioms/*.md` file) only
when this brief does not resolve the question in front of you.

## 1. The job

You are handed one packet: a contiguous run of `open` functions in the
Black image, drawn from `layout/worklist.json`. Inside it:

1. Pick a function (or a short contiguous run of functions) from your
   packet's address range. `python tools/worklist.py --packet <id>` prints
   the range IN FULL and marks every line `matched` or `OPEN`; only the
   `OPEN` lines are work, and `--open-only` hides the rest. A packet's
   boundaries survive a refresh, so a line can read `matched` because a
   lane filed that address after your packet was cut: re-deriving one
   costs a whole slot of your budget and adds no coverage, so check the
   mark (or re-run `match.py one`) before you write a body.
2. Write C for it under `src/matched/` or `src/pending/` (see below), with
   the house header block filled in.
3. Verify it with `match.py one` (single function) or `match.py tu` (a
   translation-unit range), and iterate the C until the verdict is `EXACT`.
4. When several adjacent functions in your packet are all `EXACT`
   individually, try consolidating them into one unit file and re-verify
   with `tu`: a unit that reproduces its whole range, padding included, is
   stronger evidence than N separate function files and is the preferred
   shape once a run is clean.
5. If the best you can reach is byte-correct but capped at `MATCH` (a
   relocation site has no outside witness), do not throw the work away:
   park the file in `src/pending/`, not `src/matched/`. A pending file is
   never spliced into the build and never enters a shard.
6. If you find real `DIFF` evidence worth recording, whether a closed near
   miss or an informative dead end, write it to `docs/notes/*.c.txt`, not
   into `src/matched/` or `src/pending/`.
7. Gate your own work with `manifest --verify --shard <your packet id>`
   before calling it done.

Nothing here is asking you to guess. Every verdict is a `match.py` output;
never hand-wave a file to `EXACT` in the header without the tool agreeing.

When you are choosing which packet to take next rather than working a packet
you were already handed, `python tools/worklist.py --targets [N]` (default
30) prints the top N open, non-SDK addresses ranked by
`fan_in + 5 * unlock_weight` (the mwccarm/MSL runtime helper library listed
in `layout/runtime_arm9.txt` is excluded from `open` the same way SDK code
is, so it never shows up here either): `fan_in` is every branch reference to
the address anywhere in the image (arm9 and all overlays), and
`unlock_weight` is how many `src/pending/` files name the address in their
header, a plain regex heuristic over `0x02......` tokens, not a semantic
read of the prose.
A high-scoring address is one whose packet is worth prioritising, either
because decompiling it attests many other call sites at once or because it
would unstick an existing `MATCH`-capped pending file. It is read-only and
never touches `layout/worklist.json`.


**Keep the header comment well formed.** Appending to a header is normal (blockers, levers, a run of
tried spellings), but the block must close exactly once. Two shapes have silently broken the compiler
and cost a wave each: a line ending in the three characters star slash slash, which closes the comment
and leaves a stray slash, and a second closing line after the real one. Both make every file that has
them unverifiable, so the park never reaches a shard and reads as a wall when it is finished work. If a
source compiles to nothing or reports a declaration syntax error at the first line of the body, read the
header before rewriting the C.

## 2. Verdicts, then the commands

| verdict | meaning |
| --- | --- |
| `EXACT` | every byte identical, relocation fields included |
| `EXACT*` | same, but the inferred extent ran long because the next function has no label (unlabelled follower, never a byte difference) |
| `MATCH` | identical except at relocation sites that stayed wildcarded for lack of an outside witness |
| `SIZE` | the compiler produced a different number of bytes |
| `DIFF` | same size, concrete bytes differ; `--diff` prints a two-column comparison |
| `ISA` | Thumb/ARM mismatch between original and compiled object |
| `CCERR` | the compiler rejected the translation unit |

Only `EXACT` (or `EXACT*`) goes to `src/matched/` and into a shard.
`MATCH` goes to `src/pending/` and stays out of both the shard and the
build splice: `csrc.py` refuses anything that is not `EXACT` and refuses
even an `EXACT` that still carries a wildcard byte. `SIZE`, `DIFF`, `ISA`
and `CCERR` are "keep working" signals, not filing decisions, unless you
have exhausted the function and are documenting a near miss (section 6).

The instruction set is never guessed: `resolve_isa` reads the
`.thumb_func` marker `disasm.py` emits, falls back to the per-symbol
`thumb` flag in `layout/symbols_sdk.json`, and only then defaults to ARM.
Getting it wrong is silent and expensive, an ARM compile of a Thumb
function produces a plausible-looking diff where nothing actually lines
up, so pass `--thumb` or `--arm` explicitly whenever you are not
confident `show`'s own guess is right, and always pass `--thumb` to `tu`
(it never infers ISA, since a unit's first function often has no label).

## 3. The commands

```
python tools/match.py show  --addr 0xADDR
python tools/match.py one   --src src/matched/sub_ADDR.c \
    --func sub_ADDR --addr 0xADDR --cc 1.1p1
python tools/match.py one   ... --diff
python tools/match.py tu    --src src/matched/unit_ADDR.c \
    --addr 0xADDR --thumb
python tools/match.py tu    ... --suggest-split
python tools/match.py sweep --src ... --func ... --addr ...
python tools/match.py manifest --verify --shard pkt_ADDR
python tools/match.py idioms --check
python tools/match.py selftest
```

`show` disassembles the original bytes and is the writing aid: it resolves
the region, the instruction set and the extent (to the next function
label) for you. Read this before writing any C.

`one` compiles one function and compares it at its address. `tu` compares
a whole translation-unit layout (every section laid end to end the way the
linker would) against a byte range; use it once several functions in a row
are individually `EXACT` and you want to fold them into one file, or when
the natural unit of work already spans more than one function. `tu` does
not infer the ISA (the first function in a unit often has no label), pass
`--thumb` for game code.

`--suggest-split` is read-only: it never edits a source. Run it the moment
a range comes out `MATCH` with every concrete byte right. It prints, per
unresolved relocation site, how many witnesses the address has image-wide
and how many fall inside your range, then the cuts (if any) that would
leave every site a witness outside the new, smaller range. A site whose
only witness is the call inside the function that needs it cannot be cut
free at all, the report says so, and that function is left out while the
rest of the range matches. See "Where to cut a file" in `docs/MATCHING.md`
for the full mechanics; you should not need it for a normal packet.

`manifest --verify --shard pkt_ADDR` is your gate. It recompiles every
entry of your one shard, records the verdict each actually gets, and
writes that one shard file. It reads every other shard (the symbol map is
drawn from all of them) but writes none of them.

### Compiler config

Fixed for this project, not a per-agent choice:

```
-proc arm946e -enum int -Cpp_exceptions off -interworking -char signed
-msgstyle gcc -lang c99 -O4,p
```

plus `-thumb` for game code (the ARM9 static module is Thumb throughout;
SDK library code is ARM). `--cc 1.1p1` selects `tools/mwccarm/mwccarm/dsi/1.1p1`,
the build the SDK libraries were compiled with and the only calibrated
compiler in the collection. Two spelling notes: the optimisation suffix is
written `-O4,p` (not `-Otime`/`-Ospace`, which this front end rejects), and
`-I` wants the directory joined to the flag, `-I+<dir>`, not passed
separately.

Do not sweep other optimisation levels or other compiler versions looking
for a better match on a stuck function, the whole nine-front-end,
seven-level sweep has already been run project-wide and `-O4,p` /
`dsi/1.1p1` is pinned. If `-O4,p` genuinely will not reproduce a function
after a real attempt at the C, that is a near miss to document, not a cue
to change flags.

One exception is real, per file rather than per project: if
`tools/worklist.py --packet pkt_ADDR` (or `--targets`) prints a `proc
hint` other than arm946e (from `layout/proc_hints.txt`, see
`docs/idioms/an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md`),
put the whole line in that entry's `flags:` header field, e.g.
`-O4,p -proc arm7tdmi`, which `match.py`/`csrc.py` then compile with.

## 4. File formats

### The house header block

Every source file under `src/matched/` or `src/pending/` opens with a
comment carrying these fields (blank ones omitted, not left empty):

```c
/*
 * unit:     yes                    (present only for a tu-verified range;
 *                                    omit for a single-function file)
 * function: sub_ADDRESS            (or the unit's lead function)
 * address:  0xADDRESS
 * packet:   pkt_ADDRESS            (your packet id, from the worklist)
 * status:   EXACT | MATCH          (the verdict this file actually gets)
 * symbols:
 *   name           0xADDRESS  thumb|arm|data
 *   ...
 */
```

`packet:` is what routes the entry into your own shard on the next
`manifest --verify`; without it, the entry lands in the shared
`arm9/legacy.json` and defeats the point of sharding: never omit it.
`status:` records the verdict `match.py` gave you for this file's own
verification, not an aspiration; it is what tells a later reader whether
a file in `src/pending/` is stuck at `MATCH` for lack of evidence or is
mid-edit. `symbols:` is three columns per line: the identifier as the C
spells it, its address, and `thumb`/`arm`/`data`. It is required for every
external address the file's relocations depend on; the naming convention
(`sub_0204ABCD` / `func_0204ABCD` implies address `0x0204ABCD`) still works
as a fallback and needs no block entry.

### `packet:` in the worklist sense

Separate from the header field above: `layout/worklist.json` carries one
`packet:`-keyed record per packet with its own `status` (`open` /
`claimed:<agent>` / `done` / `blocked`). You do not edit that file. The
orchestrator sets `claimed:<agent>` before dispatching you; you never
touch `layout/worklist.json` yourself.

### Shard write rules

Your manifest shard is `layout/matched/<region>/pkt_ADDRESS.json`, named
from the `packet:` header field. `manifest --verify --shard pkt_ADDRESS`
is the only command that writes it, and it writes only that one file. The
shard id outlives the packet: once `worklist.py --refresh` dissolves your
packet (its functions leave the `open` pool), the shard file keeps its
name forever, it is the historical record of the work, not a view of the
live worklist.

### The write-set contract

Inside your packet, you may write exactly three kinds of file, and
nothing else in the tree:

| what | where |
| --- | --- |
| your C sources | `src/matched/*.c` and `src/pending/*.c`, addresses inside your packet only |
| your manifest shard | `layout/matched/<region>/pkt_ADDRESS.json` |
| your idiom notes | `docs/idioms/<slug>.md`, one new file per finding |
| your DIFF evidence notes | `docs/notes/*.c.txt`, for documented near misses |

Never touch: another packet's addresses, another packet's shard,
`layout/worklist.json`, `docs/MATCHING.md`, `docs/PARALLEL.md`,
`layout/function_starts.txt`, or anything under `asm/`, the rest of
`layout/`, or `tools/`. Those belong to the integrator and are regenerated
or reviewed once per wave, outside your run. Two agents working different
packets at once never conflict, because every file above is per-packet or
per-finding, but only if you respect this list.

## 5. The honesty rules, in brief

A relocation may only be resolved when its target address is attested by
evidence *outside* the byte range under comparison. Reading the answer out
of the bytes you are checking and then confirming the bytes contain the
answer is not a test. Eight evidence classes, each printed per site by
`match.py`:

- **local**: the symbol is defined in the same object you compiled; its
  address follows from where the unit was placed. No image evidence
  needed at all.
- **matched**: an existing `EXACT`/`EXACT*` manifest entry already
  reproduces the byte range that defines the target; that compiled proof
  is the witness, not a reading of the image. Never a `MATCH` entry, and
  never the file under test itself.
- **label**: `disasm.py` traced a real `func_XXXXXXXX` at the address,
  and some branch anywhere in the image (ARM9 or any overlay) targets it
  from outside your range.
- **literal**: the exact word appears in a literal pool at a different
  address. The weak class, and the only one available for plain data.
- **string**: the address is a NUL-terminated ASCII run whose start is
  fixed by the terminator of the string immediately before it. Used for
  `__FILE__` arguments, which nothing else can attest.
- **veneer**: the address holds a recognised ARM linker-stub encoding
  (`ldr ip,[pc,#0]; bx ip; .word target` or `ldr pc,[pc,#-4]; .word
  target`) whose pointer names known code; the stub itself, read from
  outside your range, is the evidence.
- **runtime**: the address is listed in `layout/runtime_arm9.txt`, the
  curated identification of the MSL/runtime.a routines mwccarm links in for
  64-bit shift/multiply/divide and soft-float arithmetic (wave 18B). These
  are hand-written ARM assembly, never compiled from this project's C, so
  `disasm.py` never traces a `func_` label at one, and a call site is
  frequently the only branch anywhere in the image that reaches it (every
  witness would then be inside your own range, which `label` refuses). The
  table entry is the witness, read from a file that is never part of any
  compared range: the same evidentiary standing `layout/symbols_sdk.json`
  carries for an SDK symbol, given a class of its own because a runtime
  routine is never also `label`-attestable the way an SDK symbol usually
  is. ARM only; declare it `arm` in your `symbols:` block.

- **sole-ref**: the layout itself says a data object begins at that
  address. `data` sites only, and tried last, after every other class has
  failed, so an address any stronger class can carry never reports as
  `sole-ref`. It accepts an address when all three hold: it lies in a data
  section of the delinked image (a `.word`/`.byte`/`.ascii` datum in the
  listings, or a bss range of `layout/layout.json`) and neither in a code
  section nor inside any traced function's extent; it is the **start** of an
  object something already carries at exactly that address (a `pool_`,
  `veneer_`, `d_`, `g_` or `tbl_` label in the listings, a data symbol of
  `layout/symbols_sdk.json`, a `__FILE__` anchor from
  `layout/file_anchors.txt`, or a `.word`-run start `disasm.py` emitted as
  its own block); and the alignment the declared type demands is satisfied
  (state it as a fourth `symbols:` token, `a1`/`a2`/`a4`/`a8`/`a16`; without
  one a data extern is assumed to want four). It **refuses** an address
  merely interior to a labelled object, an address in code, a misaligned
  address and any non-`data` kind, which is what keeps it from licensing an
  arbitrary offset into rodata. It is recorded per site in the shard entry
  (`evidence: {"sole-ref": ["0x..."]}`), so `grep sole-ref layout/matched`
  lists every entry that depends on it, and `tools/worklist.py --summary`
  reports its share of coverage on its own line rather than folding it into
  the coverage figure. Like `literal` and `string` it stays falsifiable: the
  resolved word is still compared against the original, so a wrong
  declaration comes out `DIFF`. `attest_sole_ref()` in `tools/match.py` is
  the implementation.

The `label` class also covers an ARM9 `bl`/`blx` into an overlay-resident
function: the address needs a `func_` label in exactly one overlay's own
listing (`asm/overlays/`) with the ISA you declared, plus an outside branch,
same as any other `label` site. Overlays overlap in address space, so when
more than one overlay's window holds the address, name the one you mean as
a fourth token on the `symbols:` line (`func_021D21C0  0x021D21C0  thumb
ov021`); without it, more than one labelled candidate is refused rather
than guessed at, and `match.py one`'s per-site report lists the candidate
overlays so you can tell a genuine ambiguity from an address nothing labels
at all. `attest_overlay_label()` in `tools/match.py` is the implementation.

No back-filling: you may not declare an address correct because the bytes
you are trying to match happen to contain it, and you may not reuse the
range under test as its own witness. **Self-reference is refused**: a
manifest entry can never be its own witness, and `attest_matched()`
enforces this by source file identity, not just address.

`EXACT*` (a trailing `*`) means the byte comparison passed but the
inferred extent ran long because the *next* function has no label
(`disasm.py` only auto-labels a prologue that saves `lr`); it is never a
byte difference. It is a prompt to seed the follower into
`layout/function_starts.txt` (that file is the integrator's): report
the unlabelled follower rather than editing it yourself.

If you are stuck at `MATCH` for lack of a witness, run `--suggest-split`
before giving up: a cut across two files that each attest the other's
call site converts two stuck `MATCH` results into two `EXACT` ones with no
new evidence invented, only a smaller compared range.

## 6. Idiom index

One file per idiom under `docs/idioms/`, so two agents never edit the same
file. **Open the file only when your diff's shape actually matches its
one-line summary below**: do not read the idiom directory speculatively.
When you find a compiler quirk that cost you real time and is not already
here, add one new file in the same format (see `docs/idioms/README.md`)
rather than folding it into an existing one.

- [64-bit complement via `eors`/-1](idioms/a-64-bit-complement-is-eors-with-minus-one-not-mvns.md): a live `eors` triple instead of `mvns` for `~x` means the mask is 64-bit, not 32-bit.
- [Dead store to a spilled local](idioms/a-dead-store-to-a-spilled-local-survives-when-the-second-assignment-recomputes.md): whether the second statement recomputes from the source value or the variable decides one store versus two.
- [Forwarding call passes one argument](idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md): a `bl` at the top of a function with nothing before it usually forwards only its first parameter, not all four.
- [4-byte ARM function in a Thumb packet is a long-branch veneer](idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md): it is not compiled C, and no `tu` range may span it.
- [Global re-read across a call to a same-file static needs `volatile`](idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md): otherwise the compiler proves the callee never writes it and keeps the load live.
- [Guard on a struct member survives constant folding](idioms/a-guard-on-a-struct-member-survives-constant-folding.md): the same guard on a plain local folds away and loses bytes.
- [Loop-carried value in a callee's argument register names the arity](idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md): here the "leftover" register really is a passed argument.
- [Pooled small constant argument is a linker symbol](idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): a small integer loaded from a pool instead of `movs` is an `R_ARM_ABS32`, not a literal.
- [Shared exit block written out in each arm](idioms/a-shared-exit-block-is-written-out-in-each-arm.md): write the shared statements in every arm and let the compiler cross-jump them, don't factor them behind a label.
- [Small constant rematerialised off a zero register](idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md): unless an earlier call already needed the same literal, in which case it's CSE'd from an argument instead.
- [Store landing after the next call names a local temporary](idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md): `p = alloc(); clear(p); obj->f = p;` versus storing before the second call, seventeen bytes apart.
- [`__FILE__` string after a data table has no witness](idioms/a-string-after-a-data-table-has-no-witness.md): the `string` class needs a preceding string's terminator, not a table's; caps at `MATCH` regardless of C.
- [Tail call can't pass a fourth argument](idioms/a-tail-call-cannot-pass-a-fourth-argument.md): `bx r3` spends r3 on the target address, so only r0-r2 remain.
- [`u64` field store picks a different scratch register than `u32`](idioms/a-u64-field-store-picks-a-different-scratch-register.md): the 64-bit form must leave the zero-holding register free for the high half.
- [Veneer call is an ordinary extern declared at the veneer](idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md): declare the extern at the stub's address, marked `arm`, not at the real callee.
- [Void return frees r0 for the switch dispatch index](idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md): whether the dispatch index lands in r0 or r1 says whether the function returns a value or `void`.
- [Address of a register parameter opens with `push {r0,r1,r2,r3}`](idioms/address-of-a-register-parameter-is-a-push-of-all-four.md): all four argument registers get a home area once any one of them has its address taken.
- [Aggregate assignment ~32 bytes or less is inlined ldm/stm](idioms/aggregate-assignment-is-ldm-stm.md): a run of paired `ldm`/`stm` among field moves is one nested struct copy.
- [Empty switch arm's table entry says `break` vs `return`](idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md): `break` lands on the function's last epilogue, `return` on the nearest preceding one.
- [Inline call argument is scheduled per site, a local is not](idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md): `g(f(p), x, k)` can schedule differently at every call site; binding `f(p)` to a local pins the order everywhere.
- [Assign the loop counter before the bound, or zero costs a pool word](idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md): counter-then-bound gives `movs r0, #0`; bound-then-counter costs four bytes of pool.
- [Large struct assignment is an ldm/stm loop, step is the struct's alignment](idioms/big-struct-assignment-is-an-ldm-stm-loop.md): above the unroll threshold it becomes a counted loop whose step reflects declared alignment.
- [`cmp` operand order names the temporary](idioms/cmp-operand-order-names-the-temporary.md): a call result only reaches `cmp`'s left slot when it was first assigned to a named local.
- [Commutative operand order names the temporary](idioms/commutative-operand-order-names-the-temporary.md): same tell as `cmp`, generalised to `+` and friends.
- [Compound assignment re-reads the field; spelled-out reuses the cached load](idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md): `x->f += 8` versus `x->f = x->f + 8` differ by one fresh `ldrb`.
- [Consecutive `__LINE__` args are one pool word and a chain of adds](idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md): only the first is materialised from a pool; the rest are derived by constant `adds`.
- [Two `blx` to `_ll_udiv` in a row are one chained 64-bit expression](idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md): it returns in the same pair it takes, so a second call setting only r2:r3 is `a / b / c`.
- [const struct pointer lets a field load survive a store](idioms/const-pointer-lets-a-field-load-survive-a-store.md): without `const`, an unrelated store may alias the field and forces a reload before every use.
- [Declaration order decides which register a local gets](idioms/declaration-order-decides-which-register-a-local-gets.md): for two locals live across a loop, not the order they're initialised in.
- [Dense switch is a PC-relative halfword table listing the cases](idioms/dense-switch-is-a-pc-relative-halfword-table.md): the table's displacements say exactly which case labels existed.
- [Disjunction must be one expression to share its exit](idioms/disjunction-must-be-one-expression-to-share-its-exit.md): `if (a||b||c) return 0;` tail-merges; the equivalent chain of separate `if`s does not.
- [`a/b` and `a%b` on the same operands are two calls](idioms/div-and-mod-are-two-calls.md): the helper returns both together, but the compiler doesn't know that.
- [Empty switch arms are what make the table exist at all](idioms/empty-switch-arms-are-what-make-the-table.md): a table only appears when case labels are dense from zero; missing low cases must be written as empty arms.
- [`__FILE__` argument is an ABS32 into the packed string area](idioms/file-string-is-an-abs32-into-the-string-area.md): declare it as an extern pinned by address in `symbols:`, never as a literal `__FILE__`.
- [Four shift-pairs for one offset are an inlined `u16` helper](idioms/four-shift-pairs-for-one-offset-are-an-inlined-u16-helper.md): repeated truncation says the value passes through a small inlined helper, not a single `u16` local.
- [Guard chain sharing one exit block is a single `&&`](idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md): the epilogue count in the original tells you chain-of-returns versus one conjunction.
- [Guards separated by statements share an exit only through `goto`](idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md): when statements sit between guards, only an explicit `goto` reproduces the shared exit.
- [Initialise the result before the input, or every arm duplicates the return](idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md): initialisation order decides whether arms share one tail or each carry their own `bx lr`.
- [Keeping a cursor in a named local costs a callee-saved register](idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md): re-reading the field fresh each time is four bytes shorter and needs no push/pop.
- [`ldrsh` with a register offset is a signedness tell](idioms/ldrsh-register-offset-is-signedness.md): the only evidence that a field is `s16`, since immediate-offset `ldrsh` doesn't exist.
- [Locals laid out with the later declaration at the lower stack address](idioms/local-declaration-order-is-stack-order.md): a wrong declaration order shows up only as wrong stack offsets.
- [`long long` aligns to four, not eight](idioms/long-long-aligns-to-four.md): a `u64` field can sit at a plain 4-aligned struct offset.
- [Out-of-range immediate subtract still costs a pool word](idioms/out-of-range-immediate-subtract-costs-a-pool-word.md): the original spells the constant as its unsigned 16-bit two's-complement add form.
- [`*(p+n-1)` and `p[n-1]` are different code](idioms/pointer-minus-one-scales-before-the-subtraction.md): subscript form scales once with an offset; pointer form scales, adds, then subtracts the element size.
- [Pool word for a far field is symbol+offset masked by the load's reach](idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md): reading separate pool words as separate objects splits one symbol into several and loses every relocation.
- [Post-increment used as a value spends a register copy](idioms/post-increment-of-a-field-spends-a-copy.md): `return p->f++;` is two instructions and four bytes longer than the spelled-out equivalent.
- [Random below N is the high word of a 64-bit multiply](idioms/random-below-n-is-a-64-bit-multiply-high.md): never `rand()%n`; a constant power-of-two bound is an inlined shift/mul quartet, a variable bound is `_ull_mul`.
- [Compiler runtime helper is a named relocation](idioms/runtime-helper-reloc.md): e.g. `_u32_div_f` for integer division, pinned in `symbols:` like any other extern.
- [Shift pair with no matching type is a bitfield](idioms/shift-pair-with-no-matching-type-is-a-bitfield.md): only a 24-bit unsigned bitfield survives to a plain shift pair; masks and shifts both fold to `ands`.
- [Two callers of the same extern attest each other, split the unit](idioms/split-a-unit-so-two-call-sites-attest-each-other.md): when the only callers are inside the compared range, cut them into separate files so each attests the other.
- [What both switch arms do is emitted once, default jumps over it](idioms/switch-arms-tail-merge.md): writing it after the switch instead moves the branch target and reallocates every register.
- [Tail call is always a pool word and `bx`](idioms/tail-call-is-a-pool-word-and-bx.md): one section per function means no displacement branch is possible, even to the next function in the same file.
- [Accumulator of a commutative chain is its second operand](idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md): `e1^e2^e3^e4` folds `e1` into the register holding `e2`, not the other way round.
- [Fall-through arm is the source order](idioms/the-fall-through-arm-is-the-source-order.md): this compiler never reorders `if`/`else`; getting the polarity wrong is a whole-function diff.
- [Reach of the Thumb immediate decides whether a field access costs an `adds`](idioms/thumb-immediate-reach-costs-an-adds.md): `ldr` +124, `ldrh` +62, `ldrb` +31; past the limit is an encoding artefact, not evidence of a different pointer.
- [Unequal shift pair is a narrowing cast folded with a shift](idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md): only an equal-amount pair is the bitfield/type-conversion idiom above.
- [Half the accessors in a file print as `.word` data, not code](idioms/unlabelled-leaf-functions-hide-in-word-runs.md): `disasm.py` only labels functions whose prologue saves `lr`; a leaf that saves nothing is invisible in the listing.
- [Two reads of a hardware address are two named locals](idioms/volatile-reread-needs-two-locals.md): `(X<<8)|X` on a volatile lvalue interleaves the shift between two loads; the address is a cast constant, not a relocation.

Regenerate this index (and the one in `docs/MATCHING.md`) with
`python tools/match.py idioms`; you never hand-edit either copy.

## 7. Workflow discipline

**Sweep by address, not by label.** `disasm.py` only auto-labels a
function whose prologue saves `lr`. A leaf accessor that saves nothing
prints as an anonymous run of `.word`s between two literal pools, see
`unlabelled-leaf-functions-hide-in-word-runs.md`. If you only pick
functions that already have a `func_`/`sub_` label, you will silently skip
roughly half of a typical block. Work your packet's address range in
order, using `match.py show --addr` at each step, not the listing's own
labels.

**Skip oversized functions after a quick look.** A packet can be up to
3072 bytes / 30 functions; individual functions inside it vary. If a
function is clearly large (say, well past what you can hold in your head
for one C rewrite) and does not look like a mechanical accessor or a short
leaf, take one `show`, form a one-line judgment of whether it is
worthwhile, and move on if not. Do not spend your budget forcing a hard
function to `EXACT` when there is easier ground left in the packet.

**Near misses go in the header, not left silent.** If you spend real
effort on a function and land at `MATCH` or `DIFF` with no further
evidence available, do not just abandon the file. Record it: put the
file in `src/pending/` if it is byte-correct (`MATCH`), write the
attestation class you're blocked on (or "none, needs a second caller" /
"codegen, N bytes wrong" etc.) directly into the header, and consider a
`docs/notes/*.c.txt` entry if the DIFF itself is instructive. This is what
lets the next agent, or the integrator, avoid re-deriving your dead end.

**Budget rules.** Aim for 30-50 functions attempted per packet run, not
30-50 `EXACT` results, most of that budget is legitimately spent on
functions that turn out to be near misses or oversized. Stop early rather
than grinding: if you have made real, systematic attempts (not one
half-hearted try) at everything reasonable in your range and the rest is
oversized or evidence-starved, stop and hand back what you have. Do not
loop `match.py one` dozens of times on the same function hoping for a
different answer without changing the C in a principled way between
attempts, that is a no-op shell call and wastes both your budget and
compile time.

**Read only what you need.** Never open a whole large `.s` listing.
`match.py show --addr` gives you the disassembly of exactly the function
you are working. When you need more context (a caller, a neighbouring
function, a literal pool), use `grep` for the address or symbol, or a
targeted offset read of the listing, never a full-file read of
`asm/arm9/src*/*.s` (these are multi-megabyte generated files).

## 8. Version discipline

Every address you write, in every `address:`, `symbols:`, and `packet:`
line, and every address in a shard, is an address in the **Black** image.
This project's addresses are Black-image addresses throughout; there is no
implicit White offset and none should be invented.

Pokemon White (IRAO) is a planned second target sharing this tree. Do not
invent schema fields that assume a single version. When a function or
table looks version-specific, a version-flag branch, a species table sized
differently between versions, anything that smells like it reads a build
identifier, say so explicitly in the source file's header comment as a
plain-English note, rather than encoding a guess about the White layout
into the C or the symbols block. Content constants (table sizes, species
counts, string offsets) are exactly the kind of thing to flag this way;
addresses and code shape are not expected to need it, since the two
versions are believed to share code layout more than data layout.

## Quick checklist, per function

1. `match.py show --addr 0xADDR` (confirm ISA and extent before writing).
2. Write the C, with the header block (`function:`/`address:`/`packet:`,
   `unit:` if applicable, `symbols:` for every external address).
3. `match.py one --src ... --func ... --addr 0xADDR --cc 1.1p1` (`--thumb`
   for game code); iterate the C, not the flags.
4. `EXACT`/`EXACT*`: set `status: EXACT`, file goes in `src/matched/`.
   `MATCH` after a real attempt including `--suggest-split`: set
   `status: MATCH`, file goes in `src/pending/` with the blocking
   evidence class named in the header. Persistent `DIFF`/`SIZE`: consider
   a `docs/notes/*.c.txt` entry instead of a source file.
5. Once a contiguous run in the packet is individually `EXACT`, try one
   `tu` file over the whole run before moving on.
6. New compiler idiom worth keeping: one new `docs/idioms/<slug>.md`,
   never an edit to an existing one.
7. Before handing back: `match.py manifest --verify --shard pkt_ADDR`.
