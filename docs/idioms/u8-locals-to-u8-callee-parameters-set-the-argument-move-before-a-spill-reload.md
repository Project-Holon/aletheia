# u8 locals passed to u8 callee parameters put the argument move before a spill reload

summary: before a call, the original does `adds r1,rX` (a register local) in the load-delay slot and
reloads a spilled local into r2 last, just before the `bl`; ours reloads r2 first and moves r1 last.
The two arguments are u8 values (the getter returns u8) that go to u8 callee parameters. Declare the
locals `u8` and the callee prototype `(u8 *p, u8 a, u8 b, ...)`; with `int` locals and `int`
parameters the scheduler picks the reload first.

Found in: src/matched/ov/ov096_func_02189D48.c (0x02189D48)

The callee func_021C7E14 (ov093) passes a and b on to func_021B9934 with no extension, and it also
compiles EXACT with `u8 a, u8 b`, so the narrow parameters are consistent on both sides. A u8
prototype with `int` locals is wrong (it adds truncations). Tried without success: declaration order,
inline wrapper, unprototyped callee, volatile or array storage for the reloaded local.
Same family (not yet checked): ov096 func_0218A390, func_02188D5C.
