# A callee that returns a byte count is declared u8, and the caller's count is then spilled and reloaded

summary: when the image stores a call result to the stack and reloads it
before `movs rI,#0`, with no mask after the call, the callee returns a `u8` and
the caller's counter is a `u8`; declaring the extern `int` or `u32` keeps the
value in r0 and drops the reload.

Found in: src/matched/ov/ov093_func_021D8D9C.c (0x021D8D9C),
src/matched/ov/ov093_func_021DC170.c (0x021DC170)

Both functions call func_021C7F68 (it ends `adds r0,r4,#0; pop`, a `u8 j`
that is already normalised) and then loop `for (i = 0; i < n; i++)`. The image
has

```
bl   func_021C7F68
str  r0, [sp]        ; n spilled
ldr  r0, [sp]        ; and reloaded at once
movs r4, #0          ; i = 0
cmp  r0, #0
bls  exit
```

With `extern int f(...)` or `u32 n` the compiler keeps n in r0 for the first
test (`movs r4,#0; str r0,[sp]; cmp r0,#0`). With

```c
extern u8 func_021C7F68(void *p, u16 b, u8 *out);
u8 n;
u8 i;
...
n = func_021C7F68(a, key, buf);
for (i = 0; i < n; i++) { ... }
```

the same registers and the str/ldr pair match, and no `lsls/lsrs` mask is
emitted after the call because a `u8` return is already zero-extended.
