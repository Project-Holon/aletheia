# A Vec copy as three field moves with its y/z registers swapped is an inline setter

summary: three `ldr`/`str` pairs copying a 12-byte vector (not `ldm`/`stm`, so
not a struct assignment) whose y and z land in r1 and r2 in the image but r2 and
r1 in your compile come from a `VEC_Set`-style `static inline` setter called as
`vset(&dst, src->x, src->y, src->z)`: its arguments are evaluated right to left,
and that order is what colours y into r1.

Found in: src/matched/ov/ov021_func_021C7878.c (0x021C7878),
src/matched/ov/ov021_func_021C78DC.c (0x021C78DC)

The image, 0x021C78C4..0x021C78D0:

```
ldr r0, [r7]
ldr r1, [r7, #4]
str r0, [r4, #0x10]
ldr r2, [r7, #8]
str r1, [r4, #0x14]
ldr r0, [sp, #4]            ; return value
str r2, [r4, #0x18]
```

Every plain spelling puts y in r2 and z in r1 (4 bytes), whatever the
declaration order of three temporaries: `x = c->x; y = c->y; z = c->z;` then
three stores, or the loads interleaved with the stores (16 bytes, different
schedule), or through an `int *` view. `o->f10 = *c` is `ldm`/`stm`.

What matches:

```c
static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x; d->y = y; d->z = z;
}
...
vset(&o->f10, c->x, c->y, c->z);
```

Spelling the right-to-left order out by hand (`z = c->z; y = c->y; x = c->x;`
then the three stores in x, y, z order) is also EXACT, which is the evidence for
why the inline works; the inline is the likelier original (NitroSDK's
`VEC_Set`). The same right-to-left rule for an inline wrapper's call arguments
is `an-inline-wrappers-arguments-are-evaluated-last-to-first.md`; this file is
the register-colouring face of it, where no call order gives it away.
