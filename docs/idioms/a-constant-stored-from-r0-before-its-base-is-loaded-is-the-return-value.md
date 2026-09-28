# A constant stored from r0 before its base is loaded is also the return value

summary: when `g->f = K` puts K in r0 before loading `g`, with the base in r1 or r2, the function
returns K (`return g->f = K;` in an `int` function). A `void` store loads the base into r0 first.

Found in: src/matched/ov/ov009_func_0215592C.c (0x0215592C)

Original, at four exits of one switch:

```
movs r0, #0xfa        ; ldr r0, =0x3e9
ldr  r1, [r5]         ; g
lsls r0, r0, #2
str  r0, [r1, r4]
pop  {r4, r5, r6, pc}
```

With `void f(int a)` and `g->err = 1000; return;`, the same instructions come out with r0 and r1
swapped (the base goes in r0 and the constant in r1). The diff has 17 bytes wrong across four sites and
is the same size. Wrapping the store in a static inline setter does not change it.

The register choice depends only on whether r0 is live out. Declaring the function `int` and writing
each exit as `return SetErr(K);`, with `static inline int SetErr(int e) { g->err = e; return e; }`,
makes it EXACT. The plain `return g->err = K;` spelling was not tested on its own. The rest of the function then has to return
something plausible too: `return callee();` where it tail-calls, and `r = callee(); if (r == 0) return
g->err = K; return r;` where it tests the result. A `return 0;` in a path that originally just popped
adds a `movs` and puts everything after it off by two bytes.
