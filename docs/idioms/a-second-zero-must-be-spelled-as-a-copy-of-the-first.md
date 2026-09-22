# A second zero must be spelled as a copy of the first, not as its own literal

summary: when the image materialises one `mov rA, #0` and then derives a second zero with `mov rB, rA`, the C has to make the second value textually depend on the first (`int j = i;`), because two independent `0` literals leave the allocator free to pick which register owns the constant and no declaration order fixes it.

Found in: src/matched/func_0206164C.c (0x0206164C), src/matched/func_0206168C.c (0x0206168C)

The original is a five-iteration copy loop with two zero-initialised
quantities, a counter and a destination index:

```
0206164C  push {r3, lr}
02061650  mov  r3, #0          <- i owns the literal
02061654  ldr  ip, [pc, #0x2c]
02061658  mov  lr, r3          <- j is a COPY of it
...
02061660  add  r3, r3, #1
0206167C  add  lr, lr, #2
```

The obvious C gives the two `mov`s the other way round:

```c
int i;
int j = 0;
struct Ent *t = g_020A816C;
for (i = 0; i < 5; i++) {
    dst[j] = t->w[0];
    dst[j + 1] = t->w[1];
    j += 2;
    t++;
}
```

`mov lr, #0` then `mov r3, lr`: ten concrete bytes out, size-exact. The two
statements are independent, both values are the constant 0, and mwccarm's
Chaitin allocator coalesces them into one value and then picks whichever
register it likes for the definition. Nothing about the *order* of the
declarations changes that: nine orders were swept over these two functions
(and sixty-four spellings over their sibling func_02061460) and the residue
moves between 10, 13, 15 and 37 bytes without ever reaching zero.

The lever is to make the second value a *use* of the first, so the dependency
is in the source and the allocator has no choice:

```c
int i = 0;
struct Ent *t = g_020A816C;
int j = i;                  /* not `= 0` */
for (; i < 5; i++) {        /* empty init clause: i is already initialised */
    dst[j] = t->w[0];
    dst[j + 1] = t->w[1];
    t++;
    j += 2;
}
```

This is byte-exact. Two details are load-bearing:

* the `for`'s init clause must be *empty*. Writing `for (i = 0; ...)` with
  `int j = i;` above it puts the assignment to `i` after the read of it, and
  the compiler re-materialises the literal for `j` again.
* declaration order still matters, but only *once the dependency is in place*,
  and it is not the same order in two functions written from one template.
  The save half (func_0206164C) wants `i, t, j`, which puts the table pointer
  in ip and the index in lr; its mirror func_0206168C wants `i, j, t`, the
  opposite assignment. Using either order in the other function is 10 or 15
  bytes out. So a declaration-order sweep that comes back "moves it but never
  removes it" is a sweep run against the wrong baseline, not evidence that the
  register choice is beyond reach.

Where it does not reach: func_02061460 at 0x02061460 has the visually identical
`mov r5, #0` / `mov lr, r5` residue and the lever does not close it, because
there the second zero is consumed by four predicated stores in two separate
if/else pairs rather than by one loop index, so there is no single use that can
be made to name it. The permuter is flat on that one from both hill and anneal.
See docs/notes/pkt_020611D4.c.txt for the measurements.
