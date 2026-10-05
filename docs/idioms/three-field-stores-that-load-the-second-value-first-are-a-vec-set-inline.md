# Three field stores that load the second value first are a VEC_Set inline

summary: when the image writes x, y, 0 to three adjacent fields but loads the
y value before the x value (and before the first store), the source called
the SDK inline `VEC_Set(v, x, y, z)`. The inline evaluates its arguments
into parameter temps before the body runs, so both loads sit above the
stores. Three plain stores load each value just before its own store, because
a store through a pointer may alias an address-taken local.

Found in: `src/pending/ov/ov112_func_021F56BC.c` (0x021F56BC, ov112), wave D9r.

Image:

```
ldr r2, [sp, #0xcc]     @ cb.y2 first
ldr r1, [sp, #0xc8]     @ cb.x2
ldr r0, [sp, #0xac]     @ 0x100
str r1, [r4, r0]
ldr r0, [sp, #0xa8]     @ 0x104
movs r1, #0
str r2, [r4, r0]
ldr r0, [sp, #0xa4]     @ 0x108
str r1, [r4, r0]
```

Source:

```c
static inline void VEC_Set(Vec *a, int x, int y, int z)
{
    a->x = x;
    a->y = y;
    a->z = z;
}
...
VEC_Set((Vec *)(obj + 0x100), cb.x2, cb.y2, 0);
```

Writing the three stores directly (in any order) loads cb.y2 after the
first store.
