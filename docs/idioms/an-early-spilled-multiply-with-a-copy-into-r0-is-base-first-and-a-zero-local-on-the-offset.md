# An early spilled multiply with a copy into r0 is base first and a zero local on the offset

Seen in ov021 func_021B7DE0 (Thumb, -O4,p). The image computes an element
offset right after the bound check, spills it, and passes the element
pointer with a self-copy:

```
movs r3, #0x48
muls r3, r0, r3        ; off = i * 0x48, early
ldr  r7, [r2, #0x14]   ; base kept in a callee-saved register
str  r3, [sp]          ; off spilled
...
adds r0, r3, #0        ; copy of off
adds r0, r7, r0        ; base + copy
bl   func_021B9278
...
ldr  r0, [sp]
adds r0, r7, r0        ; base + off for the second call
```

With `base + off` at both calls the compiler sinks the multiply to the first
call. An integer sum `(u8 *)(off + (u32)base)` brings it forward but spills
base and keeps off in r7 (roles reversed). Declaration order, `__restrict`,
arrays and inline helpers are inert.

What closes it, all three together:

```c
extern int func_021B9278(u8 *, void *, Tbl *);   /* real 3-argument callee */

base = t->x14;           /* base assigned before off */
off = a->h0 * 0x48;
pad = 0;                 /* zero-valued local */
v = func_021B9278(base + (off + pad), o->x1c, t);
w = func_021B9280(base + off, x, v, o->x24);
```

The `+ pad` add survives coalescing and becomes the `adds r0, r3, #0` copy
(see a-self-move-after-a-call-is-an-add-of-a-zero-valued-local.md); it also
makes off a value with two distinct users, so it is computed early and
spilled while base stays in r7. Assigning off before base gives 81 differing
bytes; the 2-argument prototype (table not passed, so r2 is free) leaves 14.
EXACT* (2 B trailing pad).
