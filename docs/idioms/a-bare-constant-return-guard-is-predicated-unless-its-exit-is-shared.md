# A guard that returns a constant is predicated unless its exit block is shared

summary: `if (c) return 0;` compiles to a conditional return
(`movne r0, ip; popne {r3, pc}`) and never to a branch, so when the image shows
a real `bne` into the function's shared failure exit, the guard has to be folded
into that exit - the loop in the `==` arm and one `return 0;` after it - even
though the early-return spelling is semantically identical.

Found in: func_0204589C @ 0x0204589C (pkt_0204589C), filed EXACT as
`src/matched/func_0204589C.c`

The guard first written the obvious way, with the loop after it:

```c
if (a->w[0] != b->w[0]) {
    return 0;
}
i = 0;
do {
    if (a->w[i] == sStrbufEnd) return 1;
    i++;
} while (a->w[i] == b->w[i]);
return 0;
```

loses four slots: mwccarm predicates the guard, so the image's

```
cmp   r3, r2
bne   #0x20458ec          <- the shared failure exit
```

comes out as

```
cmp   r3, r2
movne r0, ip              <- ip is the zero the counter was initialised into
popne {r3, pc}
```

and every later instruction is displaced by one. The image's `bne` target is the
*same* block the loop's own failure test falls into, which is the tell: the exit
is shared, so it cannot be a bare conditional return. Inverting the test and
putting the loop inside the taken arm gives the branch back:

```c
if (a->w[0] == b->w[0]) {
    do { ... } while (a->w[i] == b->w[i]);
}
return 0;                 <- one copy, reached from both failures
```

The identical `goto fail; ... fail: return 0;` spelling compiles to the same
bytes, so any shape that makes both failures reach one `return 0;` works.

Two corollaries from the same function:

* `int i = 0;` at its declaration puts the counter's `mov ip, #0` ahead of the
  guard's `cmp`; assigning `i` after the guard leaves it after the terminator
  pool load instead.
* the terminator read is loop-invariant and mwcc hoists it out of the loop but
  not above the guard, so the loop's back edge lands *after* the pool load - the
  back-edge target in the listing is the `a->w[i]` compare, not the block top.
