# A separate index local per loop reorders spill slots

summary: when two loops in one function each compute an entry index
(`idx = func(w, i)`) and the second loop spills it next to another local,
reusing one `idx` variable for both loops can swap the two spill slots
(`str rN, [sp, #4]` vs `[sp, #8]`). Giving the first loop its own index local
(`k`) puts the second loop's `idx` and `flag` in the original slots. Changing
the declaration order of `idx` and `flag` alone did nothing.

Found in: `src/matched/ov/ov094_func_021FEBAC.c` (0x021FEBAC)

The first loop keeps its index in a register; the second loop spills `idx`
to sp+8 and `flag` to sp+4. With one shared `idx`, mwcc placed `idx` at sp+4
and `flag` at sp+8 (10 bytes differ). With `int k;` for the first loop, EXACT.
The function also uses an enum loop counter (`typedef enum { KEY_0 } Key;`)
so both loops keep their `cmp r5, #8` entry guard.
