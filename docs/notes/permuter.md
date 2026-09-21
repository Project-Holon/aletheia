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
mutations to it, accepts any that lowers the mismatch count (or that reaches
the correct size when the size was wrong), and restarts from the baseline
when a batch produces no improvement, up to six restarts.

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
