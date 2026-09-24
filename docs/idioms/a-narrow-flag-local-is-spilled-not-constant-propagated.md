# A narrow flag local is spilled and reloaded, not constant-propagated

summary: when the image stores a zero to a stack slot and reloads it before every use (`movs r0, #0; str r0, [sp, #4]; ldr r0, [sp, #4]; strb ...`) while a neighbouring array is addressed off its own `add rN, sp, #K`, the local is a plain u8 (or u16, or signed char) flag, not a volatile int: 1.1p1 forwards the zero of a plain int, and a volatile gets a home in the addressable-local area.

Found in: src/matched/func_0201C8BC.c (0x0201C8BC)

The image clears a three-byte buffer from a 0/1 flag that is later set to 1
and tested at the end of the function:

```
movs r0, #0
str  r0, [sp, #4]      <- the flag's spill slot
ldr  r0, [sp, #4]
add  r1, sp, #8        <- buf, the first addressable local
strb r0, [r1]
ldr  r0, [sp, #4]
strb r0, [r1, #1]
ldr  r0, [sp, #4]
strb r0, [r1, #2]
```

Measured under dsi/1.1p1 -O4,p, same body, only the flag's declaration changed:

* `int done = 0;` 180 bytes: the zero is forwarded into the three stores and
  the reloads disappear.
* `volatile int done = 0;` 184 bytes, 17 out: the reloads are right, but done
  becomes an addressable local beside buf and the stores go off
  `add r0, sp, #4` plus offsets 4/5/6 (and the final reads the same way).
  Eight waves of spellings (block scope, struct wrappers, pointer aliases,
  `volatile long`) stayed at 17 from here.
* `u8 done = 0;` (also `u16`, `signed char`): EXACT. The narrow local is a
  register candidate, is spilled to [sp,#4] with word loads, and its zero is
  not propagated into the byte stores.

So a reload-before-every-use of a constant flag is not by itself a volatile
tell: try the narrow plain type first, and reach for volatile only if the
array's base register is also the flag's.
