# An unsigned loop bound compiles to `blo`/`bls`, a signed one to `blt`/`ble`

summary: A counted loop whose branch is `blo` (or its zero test `bls`) is
unsigned; if your C compiles to `blt`/`ble` the counter or the bound is a
signed type and must be changed to `unsigned`.

Found in: src/matched/ov093_func_021B9864.c (0x021B9864)

A loop shape like

```c
int n = func();
for (int i = 0; i < n; i++) { ... }
```

because both `n` and `i` are `int`, the compiler emits a signed compare, and
the loop test reads

```
cmp r5, r0
blt ...
```

The original in this project is frequently

```
cmp r5, r0
blo ...
```

The difference is the type of the operands, not the loop's spelling. `blo` is
the unsigned lower-than (`b`elow, unsigned), `blt` the signed one, and `bls`
the unsigned `<= 0` in a `cmp x, #0; bls` guard. Declare the counter and the
bound `unsigned int` (or `unsigned short`, which promotes to `int` but makes
the compared expression unsigned) and the same C body emits `blo`/`bls`.

The bound is the tell, not the index: in `0x021B9A6C` the first loop hoisted
its count into a register and compared `blo`, but the second re-read the
halfword bound before every test. Both were unsigned; only the register
liveness differed. Fix the signedness first and re-diff before chasing the
register allocation.

The same distinction shows up in a single guard: `if (x > 1) return 0;` is
`cmp r0, #1; bhi` when `x` is unsigned and `bgt` when it is signed. A `bhi` in
the original where your compile says `bgt` is the same unsigned-operand bug.
