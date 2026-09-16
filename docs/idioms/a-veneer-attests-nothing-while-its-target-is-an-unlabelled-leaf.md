# A veneer attests nothing while its target is an unlabelled leaf

summary: the `veneer` class needs the stub's pointer word to name a function
the listing already labels, so a veneer in front of a leaf that saves no `lr`
resolves nothing and the call caps at `MATCH`; the fix is one seed into
`layout/function_starts.txt` for the target, not any change to the C.

Found in: `src/pending/func_0204CB44.c`, calling `func_02066748` (the veneer)
whose pointer word names 0x02067AA0

`attest_veneer()` reads the twelve bytes at the callee's address and accepts
them only if `names_known_code()` says the pointer word is a function:
`evidence().labels`, then `layout/symbols_sdk.json`, then the overlay labels.
Nothing else. Game code that is not in the SDK map therefore has to be
labelled, and `disasm.py` only auto-labels a prologue that saves `lr`
(`unlabelled-leaf-functions-hide-in-word-runs.md`). A veneer whose target is a
register-to-field setter is invisible to all three lookups and the class
silently does not fire.

## The tell

The callee is twelve bytes, is labelled itself, has exactly one `bl` image
wide, and `match.py` still reports the plain no-witness message rather than
anything about veneers:

```
+0028 PC24 func_02066748 -> unresolved: 02066748 (arm, from header) has no
      witness outside 0204CB44..0204CBB0
```

`match.py show --addr` on the callee prints the stub, which is the confirmation:

```
02066748  00 c0 9f e5  ldr ip, [pc]
0206674C  1c ff 2f e1  bx ip
02066750  a0 7a 06 02  .word 0x02067AA0
```

and `match.py show --addr` on the pointer word's value prints the leaf that
has no label:

```
02067AA0  08 10 80 e5  str r1, [r0, #8]
02067AA4  0c 20 80 e5  str r2, [r0, #0xc]
02067AA8  1e ff 2f e1  bx lr
```

The listing confirms it directly: the previous function's `pop {r4, pc}` sits
at 0x02067A9C and 0x02067AA0 opens a `.word` run.

## Why it is not a C problem

None of the other classes can help either. `label` needs a branch from
outside the compared range and the stub's only branch is the call being
compiled; `literal` needs the stub's address in some other pool and the whole
point of an ARM `bl` to a veneer is that no pool word holds it; `matched`
needs a manifest entry at the stub's address, and twelve bytes of
linker-emitted `ldr ip` / `bx ip` cannot be produced from C at all, so no
source file can ever earn that entry. Nor does decompiling the leaf itself
help: a manifest entry at 0x02067AA0 is not a label, and `names_known_code()`
never consults the manifest.

## Rule

When a fan-in-1 callee turns out to be a veneer, check its pointer word
before writing anything. If the target has no label, the unblock is a seed
for the **target** in `layout/function_starts.txt`, which is the integrator's
file: report the address and the evidence (the pointer word that names it,
read from outside your range, plus the preceding function's epilogue) rather
than editing it. Once the target is labelled, the veneer resolves with no
change to any source file.
