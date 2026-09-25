# A varargs counter increment is scheduled before a later format-pointer argument

summary: In a GSIDebugFormat-style varargs call, this front end evaluates a
`counter++` argument's load/increment/store before it loads the address of a
later pointer argument, even when the pointer sits earlier in the list; the
DWC build of the same routine has the pointer load first, so the two call
sites below cannot be byte-matched without a C spelling that forces the
original order (none found).

Found in: src/pending/ov009_func_021894D8.c (0x021894D8) and
src/pending/ov009_func_02189780.c (0x02189780).

Both are byte-correct except for the raw-traffic dump, e.g. in gpiSendData:

```c
func_0217D254(1, 0, 0x20, g_021A4528, g_021ADFC8++, id, buf);
/* SENT%04d(%s): %s\n */
```

The original emits, in this order:

```
ldr r1, [pc, #...]      ; &counter
ldr r2, [r1]            ; old count
ldr r3, [pc, #...]      ; format pointer
stm sp, {r2, r6}        ; spill count and id
add r2, r2, #1
str r2, [r1]            ; store increment
```

This front end instead emits the increment before the format load, then
rematerialises the format address in r3:

```
ldr r1, [pc, #...]
ldr r3, [r1]            ; old count
add r2, r3, #1
str r2, [r1]
str r3, [sp]            ; count
ldr r3, [pc, #...]      ; format pointer loaded afterwards
```

The count lands in r3 instead of r2 and the two vararg slots are written with
`str`+`stmib` instead of one `stm`, which is the 21-byte difference in
func_021894D8 (and the short-by-4 body of func_02189780).

Tried without changing the order: scalar, `int[2]` and struct-member forms of
the counter; a named `int count = counter++;` local; `register int`; exposing
the address through an `int *` local; keeping the format string in a local
`char *fmt`; an unprototyped callee and a `void` vs `int` return.  All
reproduce the compact order.  Declaring both the format and the count as live
locals does change the allocator, but globally (it 4- and 119-byte-shifts the
whole function), so that is not the original shape either.
