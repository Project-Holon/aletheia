# const on a descriptor parameter changes the order a call's argument loads are scheduled in

summary: when a spilled pointer parameter is re-read for two register arguments of a call, the order
of those reloads follows its constness: with `const T *` the base of the second argument is reloaded
before the first; without it the first comes first and an unrelated register copy moves in between.

Found in: src/matched/func_020163C4.c (0x020163C4), src/matched/func_02016630.c (0x02016630)

The two mcss.c bind routines call four arc_util constructors as
`w->fN = ctor(src->f00, src->fM, flag, &w->fK, heap);`. `src` is spilled at sp+0x10 and reloaded for
each use. The image schedules every site as

```
ldr  r0, [sp, #0xc]     heap
ldr  r1, [sp, #0x10]    src, for the SECOND argument
str  r0, [sp]
ldr  r0, [sp, #0x10]    src, for the first argument
adds r3, r4, #0         w, for the out pointer
ldr  r0, [r0]
ldr  r1, [r1, #0xc]
```

With `struct Src *src` every site comes out with `adds r3, r4, #0` in the second slot and the
second-argument reload after the first: 16 bytes wrong in one function, 21 in the other, and
thousands of permuter compiles, every front end, inline wrappers, temporaries, prototype width and
enum sweeps never moved it. Declaring the parameter `const struct Src *src` (the function never
writes through it) closes both functions with no other change.

When a residue is a pair of reloads of the same pointer in the wrong order at a call site, try
`const` on that pointer's declaration before touching the statement.
