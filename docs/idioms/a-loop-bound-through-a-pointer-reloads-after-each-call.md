# A loop bound read through the pointer reloads after each call

summary: Caching a count field in a local pins it in a register across the loop body's call; reading the field in the `for` condition instead makes the original's fresh `ldr` appear after every call.

Found in: src/matched/func_021B64A8.c (0x021B64A8), func_021B64D0, func_021B64F8, func_021B6520

The original is a walk of `n` records, stride 0x38, from `p + 0x20`:

```
ldr  r0, [r5, #4]      ; n
...
loop:
movs r0, #0x38
muls r0, r4, r0
adds r0, r6, r0        ; p + 0x20 + i*0x38
bl   func_021B69C8
ldr  r0, [r5, #4]      ; n reloaded every iteration
adds r4, r4, #1
cmp  r4, r0
blo  loop
```

The count is re-read after the call because `p` is a mutable pointer and the
callee may have written `p + 4`; the compiler may not assume otherwise.  Writing
the natural

```c
u32 n = *(u32 *)(p + 4);
for (i = 0; i < n; i++)
```

lets mwcc keep `n` live in a register across the call, drops the reload, and
reallocates the loop counter into the register the bound used to occupy: the
function shrinks from 40 to 36 bytes and the whole body is phase-shifted.

Reproduce it by leaving the bound in the condition:

```c
for (i = 0; i < *(u32 *)(p + 4); i++)
    func_021B69C8(p + 0x20 + i * 0x38, v);
```

The signedness of the counter is a second, independent tell here: the original
uses `blo` (unsigned), so the bound and index are `u32`, not a signed `int`.
