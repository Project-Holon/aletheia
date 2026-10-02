# Implicit register arguments (tools/regargs.py)

## What the check means

A matched function can hand a value to a callee through r0-r3 without the C
naming it. Two shapes are common:

- **passthrough**: a function forwards its own incoming argument to a callee
  whose prototype in the caller is too short, e.g. `func_021C2EDC(u8 *p)`
  calls `func_021C2F50(&t)`, but `func_021C2F50` is `(char *dst, const char
  *src)` and reads `src` from whatever the caller received in r1.
- **return chain**: a call's return value silently becomes the next call's
  first argument, e.g. `func_020173D0(x); func_02005B24();` where
  `func_02005B24` reads r0, which still holds `func_020173D0`'s result.

The ARM bytes are identical whether or not the C names the value, so
`match.py` reports EXACT either way. A native build (eidos, the PC port)
follows the C and passes garbage. `regargs.py` finds these calls. It compares
each call's argument count with the callee's matched definition, then reads
the caller's original bytes to find what is in each missing register at the
call.

```
python tools/regargs.py                          report on the whole tree
python tools/regargs.py --file src/matched/ov/ov021_func_021C2EDC.c
python tools/regargs.py --check --file A.c B.c   exit 1 on a high a/b row
python tools/regargs.py --summary                counts per kind, confidence, region
python tools/regargs.py -o rows.tsv              TSV
python tools/regargs.py selftest
```

`--file` reports the call sites in the named files plus every call to a
definition those files contain. The whole tree is indexed either way, so a
`--file` run takes about 20 s and a full scan about 35 s. Both need
`extract/`, because they read the original bytes.

## Reading a row

TSV columns: `caller_file caller_func callee callee_def_file kind detail
confidence`. The text report puts the kind and confidence first.

| kind | meaning |
|---|---|
| `a` | the missing register holds the caller's own incoming r0-r3 on every path (passthrough) |
| `b` | the missing register holds an earlier call's return value on every path (return chain) |
| `c` | anything else: clobbered by a call (garbage on the DS too), set by an unrelated instruction, mixed origins, or a stack-passed argument |
| `reverse` | a definition declares more parameters than any matched caller passes; caller columns are `*` |

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
- `callee does NOT use param N`: the callee never names it, so the row is
  lowered one step. It may still matter if the callee forwards the register
  (`but callee forwards it implicitly ... (chain)` raises it back).
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

Confidence is `high` when every path agrees and the callee reads the
parameter. The `--check` gate fails on high `a` and `b` rows only. `c` rows
are mostly calls where the callee really receives garbage on the DS as well.
They are worth a look in a port, but they are not a C bug in the caller.

## House rule for fixing a row

1. Name the argument and pass it explicitly. Put the parameter in the
   callee's prototype in the caller's file (matching the definition's type),
   and make the call pass the value:
   - passthrough of a parameter the caller already declares: pass that name;
   - return chain: store the return in a local and pass it, e.g.
     `void *p = func_020173D0(x); func_02005B24(p);`.
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

## What it cannot see

The module docstring of `tools/regargs.py` lists the blind spots. The main
ones are:

- calls to or from unmatched code, and calls through function pointers;
- calls inside an inline helper with several callers, or a callee reached
  through several unpaired bl sites (origins are unioned);
- values copied through any memory other than the caller's own stack slots;
- the hidden struct-return pointer in r0 (no matched definition needs it
  today).
