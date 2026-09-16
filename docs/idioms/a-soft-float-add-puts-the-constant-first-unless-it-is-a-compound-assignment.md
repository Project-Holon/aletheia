# A soft-float add puts the constant first unless it is a compound assignment

summary: `t + 0.5f` compiles to `__fadd(0.5f, t)` and costs an extra `mov`;
only `t += 0.5f` keeps the running value in the first operand.

Found in: `src/pending/func_0204CC6C.c` (0x0204CC6C, six sites)

A float add with one constant operand is a call to the runtime helper at
0x0209CB8C, and mwccarm canonicalises the commutative operands before it sets
up the call: the constant always lands in r0 and the computed value in r1.
When the computed value is already in r0, because it is the return of the
preceding `_fflt` call, that canonicalisation costs two instructions instead
of one:

```
t + 0.5f        ->   mov r1, r0            0.5f + t is identical
                     mov r0, #0x3f000000
                     bl  __fadd

t += 0.5f       ->   mov r1, #0x3f000000
                     bl  __fadd
```

The second form is what the image has. Writing the arm as an expression, in
either operand order, is four bytes longer per site; in `func_0204CC6C` that
is 24 bytes over six conversions and it is the whole size difference between
`SIZE` and `MATCH`.

Subtraction is not affected, because it is not commutative: `0.5f - t`
already compiles to `__fsub(0.5f, t)` with the `mov r1, r0` that the operand
order genuinely requires.

Two things that do not help: spelling the constant as `0.5f + t` (same
canonical form), and writing `t - (-0.5f)` (mwccarm does not fold the
negative constant into an add; it calls `__fsub` with `#0xbf000000`).
