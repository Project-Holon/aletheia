# Initialising the result at its declaration costs a register for the whole function

summary: `int r = 0;` at the top of a function whose result is only assigned after several calls materialises a zero into a callee-saved register before the first call and pushes the compiler into spilling a parameter instead; writing `int r;` and assigning `r = 0;` at the first place it is needed reproduces the original's prologue exactly.

Found in: src/matched/func_02019DA4.c (0x02019DA4)

The function reads two records, compares them against a threshold, and only
then starts building a result.  With the result initialised in its declaration
the compiler reserves a register for it from the entry point on, which pushes
one of the live parameters out of the callee-saved set and into the frame:
`push {r4, r5, r6, r7, lr}` + `sub sp, #0xC` and a `str r1, [sp]` for the
second argument, 176 bytes of function with 144 bytes differing.

Moving the initialiser to the statement that first needs it (`r = 0;` just
before the fourth call) shrinks the frame to `push {r3, r4, r5, r6, r7, lr}`
plus `sub sp, #8`, keeps both parameters in registers, and the function goes to
EXACT with no other change.

This is the companion of
`docs/idioms/declaration-order-decides-which-register-a-local-gets.md`: there,
the order of two declarations decides a register; here, whether a local is
*defined* at its declaration decides whether it occupies a register at all
during the region before its first use.
