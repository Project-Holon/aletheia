# An arg-less `bl` whose r0 still holds the previous result is a one-argument call, and it decides register allocation

summary: a `bl` with no argument setup right after `adds rN, r0, #0` (a copy of the
previous call's result) passes that result on; declare the callee with the parameter
and pass the local, even when the callee's result is dead. Left as a `(void)` call the
code is byte-identical but the local has fewer uses and mwcc hands out r4-r7 in a
different order.

Found in: src/matched/ov/ov039_func_021F3E24.c (0x021F3E24),
src/matched/ov/ov042_func_021F3834.c (0x021F3834),
src/matched/ov/ov042_func_021F3888.c (0x021F3888)

All three open with `s = func_0201210C(a); func_02188D2C(s); p = func_021897BC(s, 1);
func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(s))), n);`. `func_02188D2C`
is a leaf `ldr r0,[r0,#0x34]`, so the original passes `s` in r0 (already there, no
`adds`) and drops the result. Written as `func_02188D2C();` the object is identical
except for the allocation: `s` (two uses) got r7, `a` r6, `p` r4, where the original
has `s` r4, `p` r6, `a` r7 (3E24, 3888), and in 3834 the parameter `a` stayed in r7
while `s` was spilled instead of `a`. Declaring `int func_02188D2C(u32 a)` and calling
`func_02188D2C(s)` fixed all three at once; declaration order, local types and
`u8`/`u16` parameters changed nothing.

Check the callee with `show` before writing `(void)`: any leaf that dereferences r0
takes an argument.
