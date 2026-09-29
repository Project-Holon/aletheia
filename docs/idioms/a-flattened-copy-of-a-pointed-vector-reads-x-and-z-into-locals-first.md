# A flattened copy of a pointed-to vector reads x and z into locals first

summary: when a stack V is filled as `{pos->x, 0, pos->z}` and the image loads both pos fields before any store (and stores the zero y last), the source read `x = pos->x; z = pos->z;` into locals and then stored them; writing `m.x = pos->x; m.y = 0; m.z = pos->z;` in any order interleaves the loads with the stores and, in a function where pos lives long, gives pos a callee-saved register and spills another pointer instead (17 to 250 bytes out).

Found in: src/matched/ov/ov021_func_021B9E84.c (0x021B9E84),
src/matched/ov/ov021_func_021B9FC8.c (0x021B9FC8)

The image (0x021B9E84, Thumb, dsi/1.1p1 -O4,p), pos in r4, A a stack V:

```
ldr  r0, [r4]          ; pos->x
ldr  r1, [r4, #8]      ; pos->z, both before any store
str  r0, [sp, #0x44]   ; m.x
ldr  r0, [sp, #0x5c]   ; A.x
movs r4, #0
str  r0, [sp, #0x38]   ; n.x
ldr  r0, [sp, #0x64]   ; A.z
str  r1, [sp, #0x4c]   ; m.z
str  r0, [sp, #0x40]   ; n.z
add  r0, sp, #0x44
add  r1, sp, #0x38
str  r4, [sp, #0x48]   ; m.y = 0, after the argument set-up
str  r4, [sp, #0x3c]   ; n.y = 0
blx  VEC_Distance
```

The C:

```c
x = pos->x;
z = pos->z;
m.x = x;
n.x = A.x;
m.z = z;
n.z = A.z;
m.y = 0;
n.y = 0;
```

Every direct spelling (`m.x = pos->x` with the y stores first, last, or
between; `const V *pos`; a chained `n.y = m.y = 0`) kept one load per store
and stayed 17 bytes out; a struct copy `m = *pos; m.y = 0;` is an ldm/stm
and longer. In func_021B9FC8, where pos is also read inside a loop, the
direct spelling additionally changed the register allocation: pos took r5
for the whole function and the loop's object pointer went to the stack
(187 bytes); the two locals made it EXACT. There the original even loads z
before x (`ldr r1, [r0, #8]; ldr r0, [r0]` off the reloaded pos), which the
same two locals reproduce.
