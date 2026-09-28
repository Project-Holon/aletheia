# A variadic function's last named parameter reloaded from its home slot is a volatile parameter

summary: when a variadic function reads its last named parameter from the home area twice (`ldr r1, [sp, #0x1c]` at entry and again just before the final call) instead of holding it in a callee-saved register, declare that parameter `volatile`. The plain spelling caches it, which shifts every register and makes the body four bytes longer.

Found in: src/matched/ov/ov093_func_021CD4B0.c (0x021CD4B0)

`func_021CD4B0(void *w, u32 id, ...)` looks up `cmd = tbl[id]`, copies `cmd & 0xF`
varargs into a global buffer, and then calls `func_021CCC0C(w, id, cmd, buf)`.
The image keeps `w` in r7, the count in r6, the index in r5 and the cursor in r4.
`cmd` stays in r2 across the call-free loop, and `id` is read again from
`[sp, #0x1c]` for the call.

With `u32 id`, mwccarm keeps `id` in r6 even though `va_start` takes its
address. That leaves no callee-saved register for `w`, so `w` goes to ip
(`mov ip, r0`), and the result is 80 bytes against the image's 76. None of
these change it: `int cmd`, putting the loop bound inline, a `while` loop,
moving `va_start` or the declarations, or a `u32` buffer.

`void func_021CD4B0(void *w, volatile u32 id, ...)` is EXACT on the first compile.
The two uses become two loads from the home slot, and the colouring then
matches the image.
