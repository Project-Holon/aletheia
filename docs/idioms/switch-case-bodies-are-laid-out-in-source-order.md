# Switch case bodies are emitted in source order, table entries are indexed by case value

summary: A dense `switch` whose bodies are not laid out in numeric case order
means the source listed its cases in that order, not 0..N; reordering the
`case` labels to the body order is what fixes the jump table.

Found in: src/matched/ov186_func_021FBE54.c (0x021FBE54)

`func_021FBE54` (ov186) is a 14-way `switch (idx)` that sets up a sprite per
category. Disassembling the original shows the case bodies at these addresses:

```
0x21FBEB4 case4   0x21FBECC case5   0x21FBEF8 case0   0x21FBF10 case1
0x21FBF34 case2   0x21FBF4C case3   0x21FBF70 case6   0x21FBF94 case8
0x21FBFB8 case7   0x21FBFD0 case11  0x21FC012 case12  0x21FC04A case9
0x21FC062 case10  0x21FC086 case13
```

i.e. the emitted body order is `4,5,0,1,2,3,6,8,7,11,12,9,10,13`. Writing the
switch in numeric order (`case 0:` first) compiles to the right size and the
right set of instructions, but every body lands at a different address and the
jump table (the halfword run right after `add pc, r0`) holds different
displacements: the diff is only in the bodies' order and the small immediate
constants they reference. The compiler lays the case bodies out in the order
the `case` labels appear in the source, so the original source listed them
`4,5,0,1,2,3,6,8,7,11,12,9,10,13`. Reordering the labels to match makes the
body addresses and the table identical and the function `EXACT`.

Fall-through and shared tails are unaffected: cases that all end in the same
`bl`/`store` still cross-jump to one shared copy, so each case can be written
out in full.
