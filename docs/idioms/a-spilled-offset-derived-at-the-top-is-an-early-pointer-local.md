# A spilled offset derived at the top is an early pointer local

Seen in wave D8 lane 03 (2026-10-05): ov223 func_021BB18C (closed EXACT).

## Symptom

At the top of the function the image builds a field offset from a nearby
constant and spills it, then reloads it only for one store at the end:

```
movs r4, #9 ; lsls r4, r4, #6     @ 0x240, kept in r4 for p[0x240] and p[0x234]
adds r0, r4, #0
str  r0, [sp, #0x18]              @ spill the copy
adds r0, #0xc
str  r0, [sp, #0x18]              @ spill again: 0x24C
...
ldr  r0, [sp, #0x18]
str  r6, [r5, r0]                 @ *(u32 *)(p + 0x24C) = 0 at the end
```

The offset takes the last stack slot, after all named locals.

## Source

A pointer local to the far field, set early and written through at the end:

```c
desc = *(struct Descriptor **)(p + 0x240);
flag = (u32 *)(p + 0x24C);
...
*flag = 0;
```

mwcc derives 0x24C from the 0x240 base that the desc load holds in a register.
It keeps only the offset, not the pointer, and uses reg+reg addressing at the store.

## What does not work

Integer locals (`k = 0x240; off = k + 0xC;`, `off = k; off += 0xC;`, inline
parameters) all fold to a late `movs #0x93; lsls #2`. An enum-typed `off` keeps
the add but puts the slot first (and is a stand-in).
