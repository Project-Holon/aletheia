# A self-narrowing cast statement recolours a table index

summary: a function-pointer table dispatch `d[t[0]].fn(a, out)` with a
12-byte entry compiles to `ldrb X; movs #12; adds P, X, #0; muls P, r2, P`.
By default the loaded index X takes the low scratch register (r3) and the
product P a callee-saved one (r4). When the original has X in r4 and P in r3
(often with the `movs r2, #12` scheduled early and the pointer reload in r0),
load the index into a local and narrow it in a separate statement:
`k = t[0]; k = (u8)k; d[k].fn(a, out);`. The second definition turns k into
a two-definition web that is coloured after the product. The local may be
`u8` or `int`. Inert: the cast inside the subscript (`d[(u8)t[0]]`,
`d[(u8)k]`), `k &= 0xFF`, `k += 0`, `k = k`, named or reused index locals,
function-pointer locals, entry-pointer locals, byte-offset spellings, and
different table types.

A real second use of the index (a range check such as `if (k < N)`) gives the
same colouring, which is why this shape also shows up in functions that do
compare the index before the multiply.

Found in: `src/matched/ov/ov021_func_0218BFB4.c` (0x0218BFB4, ov021)

```
movs r2, #0xc
...
ldr  r0, [sp, #8]
ldrb r4, [r0]
ldr  r0, [sp]
adds r3, r4, #0
muls r3, r2, r3
ldr  r2, =d_021D3D58
ldr  r2, [r2, r3]
blx  r2
```
