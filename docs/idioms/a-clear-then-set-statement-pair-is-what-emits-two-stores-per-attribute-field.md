# A clear-then-set statement pair is what emits two stores per attribute field

summary: for a packed 16-bit attribute field, `f &= ~M; f |= v;` as two statements is what emits the
original's two stores with a reload between them. The fused `f = (f & ~M) | v` emits one store per
field, and the compound-assignment spelling can grow the whole function.

Found in: `func_02060888` (packet `pkt_02060814`), closed EXACT at 384 bytes (376 code + 8 pool), the
expand-heap carve the eidos port was blocked on

The attributes are built three times over, once per region:

```c
f &= ~M;  f |= v;      /* two stores per field, reload between: the original */
f = (f & ~M) | v;      /* one store per field: shorter, and not the original */
```

and the whole-function effect is larger than the field-level one: the compound `&=` / `|=` spelling
grows the function to 400 bytes, so a 16-byte difference at the attribute sites is the visible tail of
a register-allocation change upstream of them.

Two further levers in the same function, both needed together with the one above:

- A two-word region declared as a `struct MemRegion` pins its stack slots, where the same two words
  as separate scalars let mwcc reuse a dead scalar's slot. That is the counterpart of the
  `func_02060E30` idiom and the two spellings are used in the *same* function deliberately: the first
  region is two scalars with `&end - 1` at the second call site (a struct there folds the address into
  `r4` and costs `r9` plus 24 bytes), while the other two regions are structs.
- The clear size must be assigned to a local *before* the `if`, which is what hoists `ldr`/`ldr`/`sub`
  above the branch and leaves the branch testing the attribute's `tst` (the `sub` itself has no S bit).
  Written inline, mwcc adds a second `subs`/`beq` pair.

Related: `a-read-modify-write-of-the-just-stored-field-is-what-emits-bic.md` covers the sibling case
where the read-modify-write targets a field that was just stored, and the emitted instruction is a
`bic`. That idiom would predict the fused form here; this function is the case where the original
bytes want the pair instead, which is why both spellings have to be tried per site rather than
globally.
