# A const parameter hoists field loads above a call result store into an address-taken local

summary: `f(s, c, &y, &x); g(h, s->lo + (s->hi - s->lo) * (x = Div(x, y)) / 0x1000);`
compiles with `str r_t, [sp]` (the store back to the address-taken x) before
the two `ldrh` from s. When the original shows `ldrh lo; ldrh hi; str t, [sp];
subs`, declare the parameter `const S *s` (and give the callee that receives
s a `const` parameter). `__restrict` on s, a const local copy of s, struct or
array x/y, and a `restrict` pointer to x are all inert. Keep the assignment
inside the multiply: as a separate `x = Div(x, y);` statement the loads still
hoist but the call result moves from r3 to r2.

Found in: `src/matched/ov/ov021_func_021ABD08.c` (0x021ABD08, ov021)

Related: `a-const-source-pointer-hoists-the-last-load-of-a-struct-copy-into-an-address-taken-local.md`.
