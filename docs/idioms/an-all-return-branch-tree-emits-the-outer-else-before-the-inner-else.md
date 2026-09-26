# An all-return branch tree emits the outer else before the inner else only with an early return

summary: For a nested `if/else` where every arm ends in `return`, mwccarm lays
the out-of-line `else` blocks in a fixed order. Reproducing the original's arm
order often needs the inner consumer written as an early-returning `if` (with
the "middle" case falling through to a following block) rather than as an
`else if` chain.

Found in: src/matched/ov100_func_021B9EF8.c (0x021B9EF8)

The original has three arms that all end in `pop`/`bx lr`:

```
cmp  p, #0
beq  A            ; p == 0  -> a later, out-of-line block
bl   check
cmp  r0, #0
beq  C            ; check == 0 -> another later block
cleanup           ; fall-through: p != 0 && check != 0
pop
A:  call_other
pop
C:  ...long arm...
pop
```

so A is emitted *before* C. Written as the obvious nested tree —

```c
if (p != 0) {
    if (check(p) != 0) { cleanup; return; }
    else               { C; }
} else {
    A;
}
```

— mwccarm emits cleanup, then **C, then A**: the outer else lands last. The
spelling that reproduces the original swaps the nesting so that the `else` arm
returns, and the middle arm falls through to a trailing block:

```c
if (p != 0) {
    if (check(p) != 0) {
        cleanup;
        func_021B95B8(a, ptr);
        return;
    }
} else {
    A;
    return;
}
C;   /* trailing block, reached only when p != 0 && check(p) == 0 */
```

The `return` in each consumed arm is what lets the compiler sink A ahead of C.
Without it, the trailing-block C is placed before the outer else and the two
arms trade places (49 concrete bytes differed in this 136-byte function).

The same trick fixed the `if (r == 2) return; switch (r) {...} else {...}`
shape at 0x021D4AB0: writing the outer tail as an `else` (not an early
`return`) put the tail out-of-line where the original had it.
