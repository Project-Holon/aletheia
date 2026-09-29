# A u16 accessor result held in a u16 local moves the stack-argument stores ahead of the register arguments

summary: when a many-argument call stores its stack arguments after the r1-r3
setup (or after the reloads of spilled values) but the original stores them
first, check whether the values come from a u16-returning accessor such as
ov010's func_02159B10: declared `u16` in the prototype and held in `u16`
locals, they add no instruction, yet the stack stores move ahead of the
register-argument setup.

Found in: src/matched/ov/ov021_func_021AED24.c (0x021AED24),
src/matched/ov/ov021_func_021B636C.c (0x021B636C)

Both functions read several script arguments through `func_02159B10(a, b)`
and pass them on to one wide call (`func_0216EAB0`, 8 arguments;
`func_0215A2E4`, 7). The original stores the stack arguments before it
sets up the register arguments:

    str r4,[sp]; str r6,[sp,#4]; adds r1,r0,#0; ldr r0,[sp,#0x10]; adds r2,r7,#0;
    str r0,[sp,#8]; str r5,[sp,#0xc]; ... ldr r1,[r1,#4]; movs r3,#0

With `u32 func_02159B10(u32, u32)` and u32 locals, which is how most files
declare it, the same bytes come out in a different order: `adds r1` / `adds
r2` first, then the stores (9 instructions out in 0x021AED24, 4 in
0x021B636C). Earlier lanes parked both as DIFF after trying inline versus
local spellings, argument types on the callee, and flag spellings.

Declaring `u16 func_02159B10(u32 a, u32 b);` and the locals `u16 x, y, z, w;`
makes both EXACT. No truncation shows in the bytes: the callee's
zero-extended return is trusted, and the u16 values reach `u32`/`int`
parameters without a shift pair. Only the scheduling changes. In
0x021B636C the callee's real prototype (`..., unsigned short g)`, from
src/matched/ov/ov010_func_0215A2E4.c) is needed as well: a u32 local passed
to that u16 parameter adds a shift pair (SIZE +4).

This is related to
`a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register.md`.
There the invisible width changes register allocation; here it changes the
order of the argument stores.
