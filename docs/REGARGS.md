# Implicit register arguments (tools/regargs.py)

## What the check means

A matched function can hand a value to a callee through r0-r3 without the C
naming it. Two shapes are common:

- **passthrough**: a function forwards its own incoming argument to a callee
  whose prototype in the caller is too short, e.g. `func_021C2EDC(u8 *p)`
  calls `func_021C2F50(&t)`, but `func_021C2F50` is `(char *dst, const char
  *src)` and reads `src` from whatever the caller received in r1.
- **return chain**: a call's return value silently becomes the next call's
  first argument, e.g. `func_02045730(r); func_020409B4();` in
  `func_0217D890`, where `func_020409B4` reads r0, which still holds
  `func_02045730`'s result.
- **set**: a value the caller computed for something else reaches the
  callee, e.g. `func_02062F90` ends `ldr ip, =func_02062D4C; mov r1, #0; ...;
  bx ip`, and the `mov r1, #0` that stores `currentTime = 0` is also
  `func_02062D4C`'s `frames` argument.
- **thunk**: `void f(void) { g(); }` compiled to a jump that leaves r0-r3
  (and g's return value) untouched, so f forwards arguments and a result it
  never names.

The ARM bytes are identical whether or not the C names the value, so
`match.py` reports EXACT either way. A native build (eidos, the PC port)
follows the C and passes garbage. `regargs.py` finds these calls. It compares
each call's argument count with the callee's matched definition, then reads
the caller's original bytes to find what is in each missing register at the
call. It then reads the callee's original bytes to check that the callee
really reads that register. A callee's C often declares parameters its
original code never touches (an unused `c, d`, or a value overwritten before
use). Such rows are kind `phantom`, and the caller is fine.

The definition can also be too short in the other direction: void, or
declaring fewer parameters than its code reads. The callee may also not be
matched at all. A broader check covers this. For every call, including tail
calls, it takes the registers the callee's original code reads and flags any
that the C call does not supply, whatever the definition says. These rows
end in `[broader check]`, and their detail says `callee definition too
short` or `callee not matched`. In this check anything undecidable counts as
not read, so these rows never rest on a guess.

```
python tools/regargs.py                          report on the whole tree
python tools/regargs.py --file src/matched/ov/ov021_func_021C2EDC.c
python tools/regargs.py --check --file A.c B.c   exit 1 on a high a/b/set/thunk row
python tools/regargs.py --summary                counts per kind, confidence, region
python tools/regargs.py -o rows.tsv              TSV
python tools/regargs.py selftest
```

`--file` reports the call sites in the named files plus every call to a
definition those files contain. The whole tree is indexed either way, so a
`--file` run takes 20 to 50 s, depending on machine load. A full scan takes
about 4 minutes, because it reads every definition's and every callee's
original code. Both need
`extract/`, because they read the original bytes.

## Reading a row

TSV columns: `caller_file caller_func callee callee_def_file kind detail
confidence`. The text report puts the kind and confidence first.

| kind | meaning |
|---|---|
| `a` | the missing register holds the caller's own incoming r0-r3 on every path (passthrough) |
| `b` | the missing register holds an earlier call's return value on every path (return chain) |
| `set` | the missing register holds a value the caller's own instructions wrote for something else, and the callee reads it |
| `thunk` | `void f(void) { g(); }` forwards r0-r3 unchanged to g; one row per thunk, listing the registers g reads and whether g returns a value |
| `c` | anything else: clobbered by a call (garbage on the DS too), mixed origins, or a stack-passed argument |
| `phantom` | the callee's original code never reads the register; the detail keeps the kind the row would have had (`was a/high`) |
| `reverse` | a definition declares more parameters than any matched caller passes, or declares parameters its original code never reads; caller columns are `*` |

The `detail` column starts with the register(s) and where the value came from:

- `r1 = caller's incoming r1, which the caller's definition does not declare
  (caller has 1 params)`: the caller's own signature is too short as well.
  The fix runs up the call chain (see below).
- `r2 = caller's own param 2 'ctx'`: the caller already has the value under a
  name and only needs to pass it.
- `r0 = return value of (func_020173D0)`: capture that return and pass it.
- `(restored from a copy of the incoming r2)` / `(restored from a copy)`: the
  compiler moved the value through a callee-saved register or a stack spill
  first. It is still the same value.
- `callee's original code reads r1`: checked on the callee's bytes. The read
  is followed through copies, spills, and calls the callee passes the
  register on to (up to twelve levels deep). The ISA at each level comes
  from the definition's `isa:` or `symbols:` row, then from the call
  instruction, then from the listing. A store to an outgoing stack-argument
  slot counts as a read.
- Switch tables are data, not code. A Thumb `add pc, rN` and an ARM `addls
  pc, pc, rN, lsl #2` go to their case targets only. Conditional writes
  that cover both paths (`ldrhne r3` / `ldrheq r3`, `movgt r2` + `bgt`)
  count as one write. `push {r0-r3}` with one slot's address taken reads
  that slot only.
- `undecidable: the callee jumps to 0x...` (row `low`): the callee
  tail-jumps out of the image, or from DS code into the DSi-only TWL region.
- `callee definition too short (... declares N params)` / `callee not
  matched` `[broader check]`: the callee's code reads a register that its
  definition does not declare. Fix the callee's definition and prototypes as
  well as the call.
- `callee's original code never reads r2 (phantom parameter ...; was a/high)`:
  a phantom row.
- `callee does NOT use param N`: only when the callee's bytes could not be
  read. The callee never names the parameter, so the row is lowered one step.
  `but callee forwards it implicitly ... (chain)` raises it back.
- `passed K of N (proto M params)`: the caller's prototype for the callee.
  `proto () params` is an unprototyped declaration, and `no proto` means there
  is none in scope.
- `defined as sub_XXXXXXXX (resolved by address)`: the caller spells the
  callee differently from its definition, and the two were matched by
  address.
- `[union over N bl sites]`: the C calls and the bl sites could not be paired
  one to one, so the origins of all sites are merged.
- `param N takes 2 words`: a 64-bit or struct-by-value parameter that spans
  two registers.

Confidence is `high` when every path agrees and the callee's original code
reads the register. The `--check` gate fails on high `a`, `b`, `set` and
`thunk` rows. `c` rows are mostly calls where the callee really receives
garbage on the DS as well. They are worth a look in a port, but they are not
a C bug in the caller. `phantom` rows are never a caller bug.

A thunk row is `high` when g reads at least one forwarded register, `low`
when it reads none (the thunk is harmless apart from the return value), and
`med` when g's bytes could not be read.

## House rule for fixing a row

1. Name the argument and pass it explicitly. Put the parameter in the
   callee's prototype in the caller's file (matching the definition's type),
   and make the call pass the value:
   - passthrough of a parameter the caller already declares: pass that name;
   - return chain: store the return in a local and pass it, e.g.
     `u32 i = func_02045730(r); func_020409B4(i);`;
   - set: pass the value the register holds (`func_02062D4C(p, 0)`);
   - thunk: give f the parameters g reads (and g's return type when g returns
     a value), and pass them: `u32 f(void *p) { return g(p); }`.
2. When the caller's own signature lacks the parameter (`which the caller's
   definition does not declare`), add it to the caller's definition. Then
   change the caller's prototype in every file that calls the caller, and
   those calls too. Grep `src/matched` for the caller's name, and for its
   address with other prefixes (`func_`, `sub_`). This can cascade: re-run the
   tool on each newly touched file.
3. Every touched function must stay EXACT under `match.py`, both with and
   without `--lang c99`
   (`python tools/match.py one --src F.c --func NAME --addr 0x... --cc ...`,
   then the same with `--lang c99`). The header of each file gives its
   compiler and flags.
4. Re-run `python tools/regargs.py --check --file <every touched file>`. It
   must exit 0. A new row on a file you touched means the cascade is not
   finished.

Do not silence a row by widening the callee's definition, adding casts to
unrelated arguments, or changing what the callee reads. The fix belongs on the
caller side, where the value is lost.

A `phantom` row, and a `reverse` row that says `original code never reads`,
points the other way. The caller is fine, and the callee's C declares too
much. Trailing unread parameters can be dropped from the definition and
from every prototype of it, under the same EXACT rule. An unread parameter
before a read one stays as a placeholder. A function whose address is taken
may need the full signature as a callback, so its row is `med`.

## What it cannot see

The module docstring of `tools/regargs.py` lists the blind spots. The main
ones are:

- calls to or from unmatched code, and calls through function pointers;
- calls inside an inline helper with several callers, or a callee reached
  through several unpaired bl sites (origins are unioned);
- values copied through any memory other than the caller's own stack slots;
- the hidden struct-return pointer in r0 (no matched definition needs it
  today);
- for phantom verdicts, callee reads lean towards "read". Past twelve
  nested calls, in a call cycle, at an unresolved register jump, or when a
  value is only stored to memory, the register counts as read. A phantom
  verdict is therefore safe, but some phantoms are missed. The broader
  check leans the other way, so it misses reads it cannot prove;
- thunks are recognised only in the exact `g();` body shape with no
  parameters.
