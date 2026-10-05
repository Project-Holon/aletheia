# A callee declared void that returns a value changes later constant copies

summary: when later register arguments of 0 or another small constant are copied from a
register (`adds rN, rM, #0`) where the original loads them fresh (`movs rN, #0`), check every
callee declared `void` against its matched definition. A callee that really returns a value
must be declared with that return type, even when the caller ignores the result.

Found in: src/matched/ov/ov068_func_021B9980.c, src/matched/ov/ov072_func_021BB820.c,
src/matched/ov/ov106_func_021B7D14.c, src/matched/ov/ov121_func_021DB018.c (all through
func_02049658, which tail-returns sub_0204968C), src/matched/ov/ov071_func_021B6100.c
(func_021B652C and func_021B6540 return int).

Shape in the listing: after a call, a constant that an earlier statement already put in a
callee-saved register is built again with `movs` in the original. Ours copies it from that
register, keeps the register live longer, and pushes a later constant into another register.
Size is usually equal; the residue is a few copies and the colours that follow.

Wrong C: `extern void func_02049658(...);` while the definition returns u32. A void call
leaves r0 dead, so the front end treats the constant web as unbroken across the call.

Right C: declare the real return type (`extern u32 func_02049658(...);`) and keep ignoring the
result. Find the type in the callee's matched definition, or in a matched caller that uses it.

How to find candidates: for each `extern void` in a draft, grep the callee's definition in
src/matched. If the definition is non-void, or is a void wrapper whose last statement is a call
to a non-void function (a tail-return), fix the declaration first. The same check closed five
drafts parked for months as "zero pooled in a register" walls.

Port note: a void definition whose last call returns a value is a port bug when callers use r0.
Fix the definition to return the value; the bytes do not change.
