# Two field stores through a pointer local can rematerialise the symbol base

summary: binding a global's address to a `char *` local and then storing at two
offsets lets the ARM compiler spend a second literal-pool word on `symbol+off`;
declaring a typed extern array and indexing it keeps one base register.

Found in: src/matched/func_02179F28.c (0x02179F28)

The original is one base load for two stores:

```
ldr r0, [pc, #0x14]     ; d_0217ABA8
mov r1, #1
str r1, [r0, #0x14]
ldr r1, [r0, #4]
add r1, r1, #1
str r1, [r0, #4]
bx lr
```

Writing it as a `char *` local,

```c
extern char d_0217ABA8[];
char *p = d_0217ABA8;
*(int *)(p + 0x14) = 1;
*(int *)(p + 4) = *(int *)(p + 4) + 1;
```

makes the compiler materialise `d_0217ABA8 + 4` as a *second* ABS32 site and
emit two pool loads (two relocation sites, sixteen bytes longer). Declaring the
object as an `int` array and indexing in elements keeps the single base:

```c
extern int d_0217ABA8[];
d_0217ABA8[5] = 1;
d_0217ABA8[1] = d_0217ABA8[1] + 1;
```

Both forms are byte-correct; only the array form reproduces the original. When a
`-diff` run shows the right instructions but an extra resolved ABS32 for the
same symbol, switch the access to typed indexing before looking anywhere else.
