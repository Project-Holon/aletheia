# A counted loop written straight after its count leaves no separate guard: the pre-test folds to `cmp n, #0` and tail-merges with the exit epilogue

summary: `n = f(); for (i = 0; i < n; i++)` with `i` known zero compiles to
`cmp rN, #0` plus the function's own epilogue, so an explicit
`if (n <= 0) return;` in front of the loop is a whole extra compare and
branch; adding one also moves the loop's `i = 0`.

Found in: src/matched/func_020390BC.c (0x020390BC)

The original reads a count, then loops:

```
0202ED1C  bl #0x203d680            ; n
0202ED20  mov r7, r0
0202ED24  mov r5, #0               ; i = 0, straight after the call
0202ED28  cmp r7, #0
0202ED2C  pople {r3, r4, r5, r6, r7, r8, sb, pc}
```

there is no `if (n <= 0) return;` in the C, and the compare against the loop
bound was folded from `i < n` to `n > 0` because `i` is a known zero at the
first test.  With the guard written out

```c
    n = func_0203D680();
    if (n <= 0)
        return;
    for (i = 0; i < n; i++)
```

the compiler emits the guard and then the loop's own pre-test as well (two
`cmp`/`pop` pairs, and `i = 0` sinks below the guard), and the loop-exit
epilogue stops being the same block as the early return.  Between the two
spellings the function is ten bytes and one register apart.
