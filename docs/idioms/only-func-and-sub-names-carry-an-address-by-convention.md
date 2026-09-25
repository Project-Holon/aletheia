# Only `func_` and `sub_` names carry an address by convention

summary: the naming convention that lets a source file omit a `symbols:`
entry is exactly `^(?:func|sub)_[0-9A-Fa-f]{8}$`; a `tbl_`/`d_`/`g_`/`pool_`
data name resolves to nothing and the ABS32 site stays wildcarded at MATCH,
so a data table reached from a literal pool must be pinned in the `symbols:`
block with a `data` kind and an alignment token.

Found in: `src/matched/func_021E3208.c` (0x021E3208)

The function reads a function-pointer table out of the pool and calls through
it:

```
021E3214  lsls r2, r1, #3          ; index * 8
021E3216  ldr r1, [pc, #0xc]       ; pool word 0x021E7AC4
021E3218  adds r0, r4, #0
021E321A  ldr r1, [r1, r2]
021E321C  blx r1
```

Written with the natural name and no header entry, the table is not
address-bearing:

```c
extern Fn tbl_021E7AC4[];
...
    tbl_021E7AC4[v * 2](p);
```

produces the exact bytes but reports

    +0024 ABS32 tbl_021E7AC4 -> unresolved: no address for 'tbl_021E7AC4':
        not in the symbols: block, not an address-bearing name, not in
        layout/symbols_sdk.json

`symbol_address()` in `tools/match.py` only reads an address out of a *name*
when it matches `^(?:func|sub)_(0[0-9A-Fa-f]{7})$`; every other identifier
needs an explicit `symbols:` line. Adding

```
 * symbols:
 *   tbl_021E7AC4   0x021E7AC4  data  ov119  a4
```

turns the site into a normal ABS32 relocation and, because the address is the
start of a data object in the chosen overlay, `sole-ref/data` witnesses it and
the function is EXACT with no C change. The `a4` is the fourth token (the
alignment the declared type wants); without it a data extern is assumed to
want four, which is correct for a table of 4-byte pointers but must be stated
for wider ones.

The same trap catches a data object spelled as an array (`extern u8 d_X[]`),
and any code address whose symbol is not a `func_`/`sub_` label - a bare
`bx lr` filler - which is why those are declared by their ISA instead (see
`an-address-literal-is-declared-by-its-isa-not-as-data.md`).
