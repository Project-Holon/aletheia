# Switch arm bodies are laid out in source order, not in case-value order

summary: mwccarm builds the comparison tree from the *values* but places the
arm bodies in the order the case labels appear in the source. Two switches with
identical case sets compile to different code and different branch targets;
when the tree matches and the targets do not, reorder the cases rather than
touch the bodies.

Found in: `src/matched/func_02046CE0.c` (0x02046CE0)

The function classifies a 4-byte magic from a table of seven. Writing the cases
in ascending value order puts the shared `result = 4` arm first:

```
02046d34  bhi  #0x2046d30
...
02046d60  mov  r0, #4          <- the five-value arm, right after the tree
02046d64  b    #0x2046d94
02046d68  mov  r0, r4          <- the BMD0 arm
...
02046d90  strh r0, [r5, #2]
```

32 of 216 bytes differ, all of them branch displacements and body order. The
original puts BMD0 first, then BTX0, then the five-value arm, then the default:

```
02046d60  mov  r0, r4          <- BMD0
02046d80  mov  r0, #3          <- BTX0
02046d88  mov  r0, #4          <- the five-value arm
02046d90  mov  r0, #0          <- default
```

and writing the cases in that order -- BMD0, BTX0, then the five, then
`default:` -- reproduces the file exactly. The decision tree is identical in
both, because it is built from the sorted values; only `cmp`/`bhi`/`bhs`/`beq`
targets move.

What this means in practice: while the tree shape is right, the case bodies can
be permuted freely in the source to move the layout, and a mismatch in the
*offsets* of otherwise perfect arms is a source-order problem, not a codegen
one. It also means the relative order of case labels carries real information
about the original file that no byte of the arms themselves records.
