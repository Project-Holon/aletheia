# tools/permute.py -- a source permuter for near misses

`permute.py` takes a C file that already compiles to nearly the right bytes
and searches source-level rewrites of the function body, looking for the
spelling that closes the gap. It is a mechanical version of what a lane does
by hand when a note says "seventeen spellings measured": it enumerates the
rewrites this compiler is known to be sensitive to, applies them, compiles,
and ranks the results.

It does not invent semantics and it never changes what the function computes
(a rewrite that is not value-preserving is refused rather than scored). It is
a search over *spellings* of a body that is already believed correct, so it
is only worth running once `match.py one` says the size is right, or nearly
right, and the residue is small.

## How it scores

It imports `match.py` and calls `match.run_one()`, which is the same path
`match.py one` takes: `compile_tu()` into a fresh temp dir, `extract_function()`,
`resolve_relocations()` against the header's `symbols:` block, then
`compare()`. A mismatch count printed by the permuter is therefore the same
number `match.py one --diff` prints for the same file, relocation attestation
and wildcarding included. Nothing about the evidence rules is bypassed: a
wildcarded site stays wildcarded, and a variant whose only remaining
difference is at wildcarded relocation fields is reported `MATCH`, not
`EXACT`, with the unresolved sites named.

Candidates are written to per-process temp directories, never into `src/`.
The only file the tool writes in the tree is the one named by `--out`.

## Usage

```
python3 tools/permute.py --src FILE --func NAME --addr 0xADDR (--thumb|--arm) \
    [--cc 1.1p1] [--flags "-O4,p"] [--budget N] [--seed S] \
    [--out FILE] [--mode random|hill] [--jobs 4] [--list]
```

The ISA is never inferred here; pass `--thumb` or `--arm` explicitly, for the
reason the brief gives (an ARM compile of a Thumb function produces a
plausible-looking diff where nothing lines up). `--list` prints the mutations
available on a source without compiling anything, which is the cheap way to
see whether the tool has any purchase on a given function.

## The mutations

Each is one named mutation with a target line, so a result reads as
"`decl-swap@L43`, `const-param@L41`".

| name | what it does |
| --- | --- |
| `decl-swap`, `decl-reverse` | permute declarations within one declaration block |
| `decl-split` | `int a, b;` -> `int a; int b;` |
| `decl-join` | two adjacent same-type declarations -> one comma declaration |
| `stmt-swap` | swap two adjacent statements when neither reads what the other writes |
| `init-split` | move an initialiser out of the declaration into a statement |
| `init-fold` | the reverse, when the assignment is the first statement after the block |
| `arg-temp[f#n]` | lift a call argument that is itself a call or an expression into a named temporary |
| `volatile-add`, `volatile-drop`, `volatile-param` | add or remove `volatile` on a pointer-typed local or parameter |
| `const-param`, `const-drop` | add or remove `const` on a pointer-typed parameter |
| `case-swap` | reorder two adjacent `case` arms textually |
| `swap'+'`, `swap'*'`, `swap'&'`, `swap'\|'`, `swap'=='`, `swap'!='` | swap the operands of one commutative operator |
| `ne0->!!`, `!!->ne0` | rewrite `x != 0` in a value context as `!!x`, and back |
| `param-signedness[name]` | toggle one parameter's or local's signedness: `u32<->int`, `s32<->u32`, `u16<->s16`, `u8<->s8` |

The rewriter is deliberately textual and conservative. Three guards matter:

* **Dependence.** `stmt-swap` refuses a pair when either statement reads an
  identifier the other assigns, when both contain calls, or when a call would
  cross an assignment it might observe.
* **Precedence.** An operand swap is refused whenever either operand abuts an
  arithmetic operator that is not the one being swapped, because the operand
  extents are found textually and a neighbour of another precedence means the
  true operand is wider than what was found. `(a + b - 1) * 2 + 0x37ad` is
  swapped around the outer `+` or not at all, never around the inner one with
  `2` mistaken for the left operand.
* **Types.** `arg-temp` gives the temporary the type of a leading cast, or the
  return type of a prototype the file declares. When neither is available the
  mutation is dropped rather than guessing `u32`, since a wrong type would
  change the compiled bytes for reasons unrelated to the shape under test.

`const` and `volatile` on a pointer parameter are in the table because they
are shape levers in this project, not stylistic choices: see
`docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md`,
`const-hoists-the-loop-test-load-above-the-body-stores.md` and
`a-volatile-field-load-is-a-shape-lever-it-cannot-be-cse-d-or-merged-into-ldm.md`.
The validation below is a case of exactly that.

## Search and ranking

`--mode random` samples budgets of single and double mutations of the
baseline. `--mode hill` keeps the best source so far, applies single
mutations to it, and accepts any that lowers the mismatch count (or that
reaches the correct size when the size was wrong). On a plateau it does
**not** restart immediately: it keeps sampling untried single mutations of
the current point until they run out, then untried *pairs* of mutations
composed together, and only restarts from the baseline once both are
exhausted, up to six restarts. This keeps the search spending its whole
budget on a stuck residue rather than quitting a few compiles in (see the
2026-09-21 fixes section below). `hill` prints its own compile count and the
number of untried mutations remaining at exit.

Variants are ranked by `(size correct, mismatch count)`, so a variant that
fixes a wrong size outranks one that merely lowers a count at the wrong size.
The best ten are printed with their mutation lists and the best source is
written to `--out`. The search stops early on a variant with no concrete
mismatches, reporting `EXACT`, or `MATCH` when wildcarded relocation sites
remain.

Compiles are cached by source SHA-1, so a mutation that re-derives to an
already-seen text costs nothing, and they run in a pool of four threads.
That is safe because `run_one()` makes its own temp directory per call and
the only shared state in `match.py` is its read-only evidence and symbol memo
dicts, which the permuter warms once before starting the pool.

## Validation

Three documented residues, `--cc 1.1p1 -O4,p`, `--mode hill`. "before" is the
baseline the note's own best C reaches under `match.py one` today; "after" is
the permuter's best.

| target | ISA | before | after | best mutations |
| --- | --- | --- | --- | --- |
| `0x020454E0` | ARM | 536 bytes, 2 mismatches | 536 bytes, 2 mismatches | none improved (baseline retained) |
| `0x02051C88` | ARM | **348** bytes (size wrong; 306 mismatches) | **352** bytes (size correct), 234 mismatches | `const-param@L41` then `decl-swap@L43` |
| `0x0202D4A8` | Thumb | 292 bytes, 4 mismatches | 292 bytes, 4 mismatches | none improved (baseline retained) |

None reached 0, so nothing was filed; all three remain DIFF.

**`0x020454E0`** behaved as its note predicts. The note records seventeen
hand-measured spellings all landing on the same two bytes, and the permuter's
twenty-one compiles agree: eight distinct operand-order rewrites are byte-identical
to the baseline at 2 mismatches, the rest are worse. This is the expected
outcome on a residue the note already diagnoses as register allocation for one
parameter copy, and it is useful as a negative: the tool reproduces a
conclusion that cost a lane a full pass, in under a minute.

**`0x02051C88`** is the interesting one, and it corrects the note.
`docs/notes/pkt_02051C88.c.txt` describes the residue as "ONE instruction out
of 352 bytes" and a 4-byte gap. Under `match.py one` today the note's own C
compiles to **348** bytes against a 352-byte original: that is a size error,
which `compare()` scores by truncating the target, and the honest count is
306 concrete bytes out, not 4. The note's "4" appears to have been read off an
instruction-aligned eyeball of the diff rather than off the tool.

The permuter found a one-character change that fixes the size:

```c
s32 func_02051C88(const struct Ctx *c)   /* was: struct Ctx *c */
```

352 bytes, all five relocation sites still resolved, 306 -> 235 concrete out.
Swapping the two declaration lines on top of it takes it to 234. This is
`const-pointer-lets-a-field-load-survive-a-store` acting on `c->n`, the loop
bound re-read across the body's stores: with `const` the compiler keeps the
extra load the image has, and the function grows to the original's length.

That does not solve the function -- 234 bytes still differ, and the note's
real finding (the fourth live copy of the constant 1, forcing the ten-register
push) is untouched -- but it moves the work off a wrong baseline. Whoever
takes `0x02051C88` next should start from the `const` parameter at 352 bytes,
not from the note's 348, and should re-measure the nine spellings the note
records, because every one of them was measured at the wrong size.

**`0x0202D4A8`** confirmed the note's closing paragraph. The note reports
fourteen further spellings all holding at exactly 4 bytes, and says the two
frame slots are assigned from something no statement-, declaration-, type- or
naming-level edit reaches. The permuter's search over 62 available mutations
agrees: nothing below 4, in `hill` (seed 3) and in `random` (seed 42)
alike, across 37 compiles. Note that the tool *does* generate `case-swap`, the
mutation that closed this function's residue (b) -- so had it existed one pass
earlier, it would have found the 48 -> 4 step by itself.

## Known limitations

* The rewriter is textual. It finds the target function by brace matching and
  will not cope with a function-like macro spanning the body, a `#if` inside
  it, or a declaration whose type it cannot recognise. When in doubt run
  `--list` first; an empty or implausible list means the source shape is
  outside what it parses.
* `stmt-swap` and `init-fold` only ever consider single-line, block-free
  statements, so they do not reach anything inside an `if` or a loop body.
  Multi-line statements are invisible to both.
* It searches spellings, not semantics. It will never discover a different
  structure -- a `goto` for a shared epilogue, a disjunction folded into one
  expression, a field re-read made `volatile`, a loop rotated -- which is
  where most of this project's real levers live. The idiom files remain the
  place to look first.
* Operand swaps are refused around mixed-precedence neighbours, so a
  commutative rewrite that needs the operand tree rather than the text is out
  of reach. That is a deliberate false-negative: a wrong rewrite would score
  as a shape result.
* A compile is about two and a half seconds under wine, so a useful budget is
  tens of candidates, not thousands. `hill` is the better use of a small
  budget; `random` is for when the baseline may need two simultaneous changes.
* `--mode hill` accepts any strict improvement, so it can settle in a local
  minimum that a different seed escapes. Run two or three seeds before
  concluding a function is unmoved.

## Field report, 2026-09-21 (closer lane, seven-target run)

Not a crash and not a wrong count: `run_one()` agreed with `match.py one
--diff` on the baseline of all seven targets, to the byte. Two behaviours are
worth recording anyway, because both cost a seed to discover.

**`--mode hill` terminates far under its budget on a wide mutation space, and
the budget number does not bound the search it actually runs.** On
`0x0206A3CC` (`--cc ../2.0/sp2`, 105 mutations available) `--budget 40 --seed 1`
did **5 compiles** and stopped; on `0x02063378` (`--budget 40`) it did 14, and
on `0x02072374` 16. The cause is the documented restart rule -- hill restarts
from the baseline when a batch yields no improvement, and on a residue where
*nothing* improves, every batch is a no-improvement batch, so the six restarts
are consumed almost immediately. The effect is that on exactly the functions
this tool is aimed at (a settled residue where the answer is "nothing moves"),
`hill` samples the least. `--mode random` with the same budget did 41 compiles
on each of the three and sampled the mutation space far more widely.

Practical rule for the next lane: on a target with a large `--list`, run
`hill` first for the cheap escape, then **`random` as the second seed**, not a
second `hill` seed. Two `hill` seeds on a stuck residue re-derive nearly the
same handful of candidates.

**`CCERR` rows in the ranking are usually real C errors, not rewriter bugs.**
On `0x0204FFFC` five of nine candidates came back `CCERR`, which reads like a
broken rewriter. It is not: `const-param@L62` produces `const struct Blk *p`
against externs taking `void *`, which mwccarm rejects as an illegal implicit
conversion, and `volatile-param` the same way. Verified by hand. The tool is
reporting honestly; `const`/`volatile` on a parameter whose fields are passed
to non-const externs is simply not a legal mutation of that source, and the
permuter cannot know that without a type checker. Worth knowing so a lane does
not go looking for a rewriter defect that is not there.

One genuine rewriter mis-parse, benign because it only wastes a compile:
`swap'*'` is offered on pointer *declarators*. On `0x0204FFFC` line 70 is
`void *h = p->f04;` and the tool listed `swap'*'@L70`, reading the declarator
star as a multiplication operator. It compiles to `CCERR` rather than to a
wrong-shape result, so it is a false positive in `--list`, not a scoring
hazard.

## Field report, 2026-09-21 (closer lane, seven Thumb near misses)

Seven targets run, `--cc 1.1p1 -O4,p`, budgets 30-35, two seeds each where
the tool had purchase.  The permuter improved none of them; the two that
reached EXACT* this pass both fell to hand structural changes the tool
cannot generate (a fused post-increment, and a parameter's signedness).
The negative results are still useful and are recorded in each note.

| target | ISA | baseline | permuter best | mutations available / compiles |
| --- | --- | --- | --- | --- |
| `0x020234C0` | Thumb | 74 B, 2 miss | 2 (baseline) | 17 / 13 (hill s1), 36 (random s7) |
| `0x0201DC88` | Thumb | 208 B, 17 miss | 17 (baseline) | ~30 / 22 (hill s1) |
| `0x02023768` | Thumb | 80 B, 15 miss | 15 (baseline) | ~20 / 10 (hill s1), 28 (random s5) |
| `0x02022490` | Thumb | 72 B, 29 miss | 29 (baseline) | **32 / 1** (hill s1) |
| `0x02022490` | Thumb | 76 B, 16 miss | 16 (baseline) | **26 / 3** (hill s2) |
| `0x0202D3D0` | Thumb | 216 B, 39 miss | 39 (baseline) | ~25 / 19 (hill s1) |

### Defect 1: `--mode hill` can stop after one compile

The one to watch.  On `0x02022490` the tool printed

    baseline  DIFF      72 bytes  29 mismatches
    mutations available: 32
    ...
    1 compiles, 0 cached

Exact command:

    python3 tools/permute.py --src <29-byte source> --func func_02022490 \
        --addr 0x02022490 --thumb --mode hill --budget 35 --seed 1 \
        --out /tmp/.../f02022490_p1.c

No error, no traceback, exit 0; it simply reported the baseline as best
after compiling nothing else.  Re-run on the 16-byte source with `--seed 2`
it did the same thing with 3 compiles out of 26 available.  Both sources are
ordinary: one `if`, an `if`/`else`, four statements, no macros, no `#if`.

This is NOT the documented "restarts from the baseline when a batch produces
no improvement, up to six restarts" behaviour, which would still show tens of
compiles.  It looks like the hill climber is discarding most of the generated
batch before compiling it.  The practical consequence is that a `mutations
available: N` line followed by a compile count far below N is a signal that
the search did not actually run, not that the function is unmoved: on this
target `--mode random` was not tried and should be next time.

Guidance until it is fixed: always read the "N compiles" line.  If it is not
within about half of "mutations available", treat the run as void and re-run
with `--mode random`, or fall back to hand permutation.

### Defect 2: some generated mutations do not compile

On `0x02023768`, `--mode hill --budget 35 --seed 1` scored two of its ten
candidates `CCERR 0 size`:

    9     CCERR        0   size  volatile-param@L28
    10    CCERR        0   size  arg-temp[func_020056A0#0]@L45

`volatile-param@L28` targets `u32 func_02023768(u8 *p)` and produces a
declaration the front end rejects; `arg-temp[func_020056A0#0]` lifts the
`(void *)func_02022D98` argument into a temporary whose type it guesses
wrong despite the leading cast the docs say it honours.  Minor: they cost a
compile each and rank last, so they never mislead.  But they do burn budget,
and on a target with few mutations that matters.

### Useful negative: the tool does reproduce documented conclusions cheaply

On `0x020234C0`, `0x02023768` and `0x0202D3D0` the permuter agreed with what
the notes had already established by hand, in well under a minute each, and
in the `0x02023768` case it confirmed nine operand-order spellings the second
pass had measured individually.  That remains the tool's best use: closing
out a note's "tried and rejected" list, not finding new levers.  Both levers
that actually closed a function this pass -- `cnt = *p++;` at `0x0201DC88`
and `int weight` rather than `u32 weight` at `0x02021F64` -- are outside its
mutation table, the first being a statement fusion and the second a change of
a parameter's signedness rather than its const/volatile qualification.  A
`param-signedness` mutation (u32 <-> int, u16 <-> s16 on a scalar parameter)
would be a cheap and, on this evidence, high-yield addition.

## Fixes, 2026-09-21

Four defects from the two field reports above, and one addition the second
report asked for, are fixed in `tools/permute.py`.

**1. `--mode hill` no longer stops far under its budget on a stuck residue.**
The old code shuffled the mutation list on every iteration and only ever
compiled the first `jobs` entries of that shuffle; a plateau (a batch with
no improvement) counted as one of six restarts and threw the rest of that
shuffle away, so on a residue where nothing improves almost the whole budget
went unused (5 compiles of a 40 budget with 32 mutations available; 5 of 40
with 105 available, per the first report). `search_hill` now tracks, per
point on the climb, the single mutations of that point not yet tried, and
keeps popping from that set until it is exhausted; once singles run out it
draws from untried *pairs* of mutations composed together; only once both
are exhausted does it restart from the baseline. Moving to a new best point
resets the untried set to that point's own mutations. The function prints
`hill: N compiles, M untried mutations remaining at exit` so a run's
coverage is visible without cross-checking the ranking table. Verified on
`func_020454E0` (28 mutations available): `--budget 30` now spends all 30
compiles (was under-spending before the fix, matching the field report's
description of the defect on other targets).

**2. `volatile-param`/`const-param` no longer offered where they produce
CCERR.** The second report found that qualifying a parameter whose value is
handed bare to an extern taking `void *` or a differently-qualified pointer
is an illegal implicit conversion for this compiler, not a shape result.
`gen_qualifier` now collects every identifier that appears as a bare
(unadorned) call argument in the body -- `f(p)` counts, `f(p->x)`, `f(*p)`,
`f((const T *)p)` do not, since those do not hand the pointer's own type to
the callee -- and skips the `*-param` mutation for any parameter in that
set. This is a conservative textual check with no type information behind
it, matching the brief's "at minimum skip when the name appears as a bare
call argument" floor.

**3. `arg-temp` no longer produces a placement CCERR that looked like a
mistyped cast.** Re-diagnosing the second report's `func_02023768` case: the
lifted temporary's type was already correct (`void *`, taken from the
leading cast in `(void *)func_02022D98`, as `_temp_type` has always
preferred) -- the CCERR was `mwccarm` rejecting a declaration inserted after
a non-declaration statement in the same block (this compiler enforces
declarations-before-statements). `gen_arg_temp` now tracks, per line,
whether everything since the block's last opening brace is blank or a
declaration, and only offers to insert a temp before a line where that
still holds. Confirmed by hand: moving the same declaration to the top of
its block turns the CCERR into a normal DIFF compile. Re-running
`0x02023768` (`--mode hill --budget 35 --seed 1`) now shows zero CCERR rows
and spends the full 35-compile budget, versus two CCERR rows (`volatile-param`
and `arg-temp`) reported previously.

**4. Added `param-signedness`.** Toggles `u32<->int`, `s32<->u32`,
`u16<->s16`, `u8<->s8` on one scalar parameter or local declaration per
mutation (pointer and multi-declarator lines are skipped). This is the lever
the second report flagged as missing after it closed `func_02021F64` by hand
with `int weight` in place of `u32 weight`. `--list` on `func_020454E0` now
shows `param-signedness[base]`, `param-signedness[pal]` (both parameters)
and `param-signedness[pn]` (the one local), and both appear in the hill
ranking on that target (still DIFF at 2 mismatches, same as before -- this
residue's fix is elsewhere, per the existing validation table above).

**Validation.** `0x020454E0`, `--cc 1.1p1 -O4,p --mode hill --budget 30
--seed 1`: 28 mutations available (up from 25, the three new
`param-signedness` entries), 30/30 compiles spent (was well under budget
before this fix on the residues the field reports measured), result
unchanged (536 bytes, 2 mismatches, DIFF -- this target's gap is a known
register-allocation residue the note already diagnoses, not something any
of these mutations reach). Runtime under 5 seconds. `--list` confirms the
new mutation is offered.
