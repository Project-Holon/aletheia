# An exact argument-register match names a coerced extern

summary: when mwcc's only divergence from the image is the register an argument
sits in, the operand type the image's instruction implies (a signed load where
the C has `int`, a `u16` truncation where the C passes an `int`) is the tell:
declare the callee's parameter as the unsigned or signed type the image used and
mwcc stops converting the value into a fresh register.

Found in: `src/pending/func_021BEA54.c` (0x021BEA54), `src/pending/func_021B6984.c`
(0x021B6984), `src/pending/ov217_func_021BE934.c` (0x021BE934),
`src/pending/ov218_func_021BA0B0.c` (0x021BA0B0)

The shape is a single load feeding a compare or a call, where every other byte
of the function is already exact and only the destination register is wrong:

```
021BE934  ldr  r1, [r0, #0x34]   /* image: signed ldr -> the field is s32 */
021BE936  cmp  r1, #4
compiled  ldr  r0, [r0, #0x34]   /* our C typed it u32 -> unsigned ldr */
          cmp  r0, #4
```

The image's `ldr` (not `ldrsh`) only proves the field is 32-bit, but the *choice
of r1* says the loaded value is not the quantity being tested directly: mwcc
emits the unsigned form in r0 and then materialises the comparison in a second
register. Declaring the field `s32` (or the helper's parameter `int` rather than
`unsigned`) makes the load land where the image put it. The same tell resolves
`func_021B6984`, where `int v = *(s32 *)(p + 0x1c)` puts the dead comparison
temporary in r1 rather than r0, and `func_021BA0B0`.

The mirror case is an argument passed through a narrowing conversion. When a
`u16` parameter is forwarded to an `s16` parameter of a callee, the image hands
the value on in a second register (the compiler would have wanted a fresh one for
the sign extension anyway) instead of clobbering the argument register:

```c
extern void func_0204E804(s16, int, int);      /* image passes r1 on in r2 */
void f(char *p, u16 a) { func_0204E804(a, b, v); }
```

Builds that diverge on one or two instructions with no relocation or scheduling
change are almost always this: read the destination register of the divergent
instruction as a type declaration for the operand, not as an allocator hiccup.
