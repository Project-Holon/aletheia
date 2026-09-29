# Clearing two adjacent 32-bit fields is a 64-bit zero store, not two 32-bit ones

summary: Two adjacent 32-bit fields each assigned `0` make mwcc pick r1 for the
zero; the same clear written as one 64-bit store (`*(unsigned long long *)&a = 0;`)
picks r2, which is what some objects have.

Found in: src/matched/ov_sdk/ov009_func_02172254.c (0x02172254)

The tail of `DWCi_PostProcessConnection` clears two adjacent members that sit at
`+0x5f0` and `+0x5f4`:

```
mov r2, #0
str r2, [r0, #0x5f0]
str r2, [r0, #0x5f4]
```

The obvious C

```c
p->f5f0 = 0;
p->f5f4 = 0;
```

compiles the same size but with the scratch register one lower:

```
mov r1, #0
str r1, [r0, #0x5f0]
str r1, [r0, #0x5f4]
```

so the function is a three-byte `DIFF` no matter which spelling the two stores
take (`0`, `0u`, `0L`, chained `a = b = 0`, a named zero local, `void *` fields,
a cast through `u32 *`, and an inlined `memset` all still land on r1). Writing the
pair as a single 8-byte clear moves the allocator onto r2 and matches:

```c
*(unsigned long long *)&p->f5f0 = 0;
```

The 64-bit constant needs a register pair, and mwcc materialises it in r2 (with
the low half re-used for both `str`s); the 32-bit constant is allocated to the
first free scratch, r1. The two members must be adjacent, 8-byte aligned, and no
other live value may sit in the pair, so reach for this only once the plain
32-bit form has actually come out one register short.
