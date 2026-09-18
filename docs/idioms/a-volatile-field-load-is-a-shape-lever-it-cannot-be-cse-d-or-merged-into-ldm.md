# A volatile field load is a shape lever: it can be neither CSEd across arms nor merged into ldm

summary: `volatile` on a struct field changes instruction *count* without changing instruction
selection. Two arms that both load the same table pointer stop being common-subexpressioned into one
load above the branch, and two adjacent field loads stop being merged into a single `ldm`. Both are
correctness-neutral and both are what the original bytes show.

Found in: `func_02048DDC` (packet `pkt_02048DDC`), closed EXACT at 88 bytes (84 code + 4 pool) as the
first member of `unit_02048DDC.c`

The function reads a header, then walks a table from one of two arms. Three separate levers:

```c
u32 * volatile unk00;      /* field: the arms' table-pointer loads are no longer CSEd */
volatile u32 end;          /* extent field: the two loads no longer merge into ldm */
u32 *tbl = rec->unk00;     /* named local: re-seats every register in the arm */
```

1. Without the `volatile` on the pointer-typed field, mwcc commoned the two arms' loads of the same
   field and hoisted one above the `bne`, giving 76 bytes. A volatile field cannot be CSEd, so each
   arm reloads and the size is 88. Fifteen non-volatile spellings failed to keep them apart.
2. Without the `volatile` on the extent's end field, the two adjacent field loads merged into
   `ldm r2, {r1, r2}`, giving 84 bytes.
3. With the subscript expression inlined instead of bound to a local first, every register in the
   record arm sat one slot off: table `r1` / address `r2` where the original has table `r3` /
   address `r1`. Naming the loaded pointer gave the original's arm, and `mov r5, r0; mov r4, r1`
   fell out of it for free.

This is a narrower statement than the neighbouring idiom
`volatile-on-a-pointer-typed-member-is-ignored.md`, and the two are consistent: `volatile` on a
pointer-typed member is ignored for *the pointee*, but here the annotation sits on a load the compiler
would otherwise duplicate or fuse, and there it is honoured. The lever is the load, not the object.

The generalisation worth carrying: when a residue is a missing or extra instruction that is itself
correct, and the difference is whether one load happens once or twice, the first thing to try is
`volatile` on the load, and the second is naming the loaded value in a local before the expression
that consumes it.
