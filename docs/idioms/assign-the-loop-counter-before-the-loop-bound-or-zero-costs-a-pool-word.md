# Assign the loop counter before the loop bound, or the zero arrives from a literal pool

summary: when a function computes a loop bound into a stack local and then
stores zero into the counter, this compiler materialises the zero with a pool
word instead of `movs`, which costs four bytes of literal pool the original
does not have; assigning the counter first, `for (i = 0, lim = n - 1; ...)`,
gives `movs r0, #0` and the right size.

Found in: `src/matched/unit_02007CB0.c` (0x02008058, 0x020080A0, 0x020080FC)

Three sort routines in that file open the same way: a call, then a counter and
a bound, both address-exposed enough to live on the stack. The original is

```
bl   sub_02008038
movs r0, #0
str  r0, [sp]            /* i = 0 */
subs r0, r6, #1
str  r0, [sp, #4]        /* lim = n - 1 */
beq  .done               /* 0 < lim is lim != 0, from the subs */
```

Writing the two statements in the order a person would,

```c
lim = n - 1;
for (i = 0; i < lim; i++) {
```

gives the same six instructions with the two stores swapped, and the `movs`
becomes a `ldr r0, [pc, #0x34]`:

```
subs r0, r6, #1
str  r0, [sp, #4]
ldr  r0, [pc, #0x34]     /* the constant 0, out of the pool */
str  r0, [sp]
```

The function goes from 72 bytes to 76, because the pool word is part of the
function's own section. The fix is to assign the counter first:

```c
for (i = 0, lim = n - 1; i < lim; i++) {
```

Two things make this worth its own note. The size change is what is visible
first, and a four byte growth in a function that is otherwise byte for byte
right reads like a missing instruction rather than like a statement order. And
the diff is misleading in the other direction too: the two `str`s are to the
same two slots either way, so the stack layout is right, the declaration order
is right, and `docs/idioms/local-declaration-order-is-stack-order.md` is not
the rule that applies. It is the order of the *assignments*, not of the
declarations, and only the one that stores zero first is free.

The same shape without the `subs` in front, or with the bound in a register
rather than on the stack, does not show it; all three instances here spill both
values because the body of the loop makes calls.
