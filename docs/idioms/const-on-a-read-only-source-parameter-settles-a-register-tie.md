# const on a read-only source parameter settles a register tie that reads as allocator residue

summary: when a function copies fields from one parameter into another, a same-size residue of one
swapped register pair (the destination's parameter copy scheduled after the loads, or the loads
interleaved with the stores) can be the missing `const` on the source pointer; with it mwcc knows the
stores cannot alias the loads and picks the image's order and registers.

Found in: src/matched/func_0204D18C.c (0x0204D18C), src/matched/func_0204D224.c (0x0204D224),
src/matched/func_0204BE84.c (0x0204BE84)

Three clact.c record builders had been recorded as closed allocator ties (10, 9 and 8 bytes after
their other levers) and permuter-flat. All three open with stores from `a` into `p`:

    p->f04 = a->f0c;  p->f08 = a->f10;  ...

func_0204D18C: the image sinks `mov sb, r0` (the copy of `p`) above the two loads from `a`, which
frees r0 for the first load and makes the stmib pair {r0, r1}; without const the copy lands below
the loads and the pair is {r1, r2} (10 bytes). func_0204D224: the image hoists all four loads above
the four stores in field order; without const they interleave (9 bytes, or a `volatile` device and a
wrong field pairing that looked like 2). func_0204BE84: the f2/f6 halfwords swap r2/r3 (8 bytes).

In each case `const struct A *a` alone (no other change, or with a device such as a `volatile` on a
destination field removed) is the whole fix. Nothing in the permuter's mutation table adds `const`
to a struct pointer parameter that is only read, so a flat anneal is not evidence against it. Try it
on every read-only pointer parameter before calling a pair swap an allocator tie.
