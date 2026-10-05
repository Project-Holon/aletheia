# A table load kept below the stack argument stores is a non-const extern

summary: when the image loads one argument from a data table only after the
`str rX, [sp, #K]` stores of the stack arguments, and our build hoists that load
above them, declare the table without `const`. A load from a plain extern cannot
move past a store; a `const` table load can, and the scheduler fills the load
latency slot with it.

Found in: src/matched/ov/ov208_func_021C2238.c (0x021C2238), wave D6.

## The shape

The loop calls a six-argument function. Arguments 2 to 5 come from a `[3][4]` u8
table, argument 6 from a second table:

```
image                          const table (ours before)
ldrb r0, [r3, #3]              ldrb r0, [r3, #3]
str  r0, [sp]                  ldrb r1, [r4, r1]     <- x0 hoisted
ldrb r2, [r7, r5]              str  r0, [sp]
...                            ...
str  r0, [sp, #4]              ldrb r3, [r3, #2]
ldrb r2, [r3, #1]              str  r0, [sp, #4]
ldrb r1, [r4, r1]              movs r0, #7
ldrb r3, [r3, #2]
```

In the image every table load after the first sits below the stack stores. With
`extern u8 data_021C8E1A[3][4];` (no `const`) the build is EXACT. Three earlier
lanes tried local pointers, a struct table and declaration orders: none of them
moves a load past a store.

## How to use it

- A load that the image keeps after an unrelated store (to the stack or to a
  struct) while ours moves it up: drop `const` from the source table or pointer.
- The other direction also holds: a load that the image hoists above a store
  needs `const` (see the const-on-source-pointer levers).
