# A `return` at the end of an `if` body and another after it keep two epilogues; hoisting one return out merges them

summary: when the tail of an `if` block and the code after it are the same
`return 0;`, mwccarm emits two separate `movs r0,#0; pop` epilogues and branches
the early-out to the second; wrapping the body so there is one `return` instead
collapses them and moves the early-out target, changing the function's size and
every branch displacement.

Found in: `src/matched/ov204_func_021BF2F4.c` (0x021BF2F4)

The original is the shape

```c
int f(char *a)
{
    if (*(int *)(a + 0x14) != 0) {
        g(...);
        switch (h(*(int *)(a + 0x14))) {
        case 2: ...; return 1;
        case 1: ...; break;
        case 0: ...; break;
        }
        return 0;              /* inside the if  */
    }
    return 0;                  /* after the if   */
}
```

and the two `return 0` sites are **not** tail-merged: the function ends with two
identical four-byte `movs r0,#0; pop {r4, pc}` blocks, the top guard branches to
the outer one, and the switch's fall-through uses the inner one.

The tempting simplification is to hoist the constant out of both:

```c
    if (*(int *)(a + 0x14) != 0) {
        ...
    }
    return 0;                  /* one return only */
```

That compiles to the same logic but **four bytes shorter** (124 against 128),
there is only one epilogue, and the top guard's `beq` lands on that single
epilogue. Every branch after it shifts and the whole function is DIFF even
though nothing is semantically different.

An early `if (*(int *)(a + 0x14) == 0) return 0;` at the top is a third shape
again: mwccarm inlines that epilogue at the function's head as `bne` over a
`movs r0,#0; pop {r4, pc}`, so the size is right but the guard's branch polarity
and every offset differ.

The reliable reading is the epilogue count: two identical `movs r0,#0; pop`
blocks four bytes apart at the end of a function mean the source really wrote
the same `return` in two different blocks (commonly one at the end of an `if`
body and one after it), and the C must be written that way too.
