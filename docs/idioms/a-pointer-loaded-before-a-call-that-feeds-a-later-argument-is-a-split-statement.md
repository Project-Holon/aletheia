# A pointer loaded before a call that feeds a later argument is a split statement

summary: when the image loads a field pointer into a callee-saved register,
calls a getter, and then passes the getter's result in r0 and the saved pointer
in r1 (`ldr r5,[r4,rK]; adds r5,#0xc; blx get; adds r1,r5,#0; blx copy`),
write the pointer, the getter call and the copy as three statements:
`dst = base + 0xc; src = get(); copy(src, dst, n);`. The one-expression form
`copy(get(), base + 0xc, n)` loads the pointer after the call.

Found in: src/matched/ov/ov175_func_021DA6B8.c (0x021DA6B8, three
MI_CpuCopy8 sites of a DWC state machine).

What does not work: a `dst` local assigned before `copy(get(), dst, n)`
(1.1p1 propagates the single-use local into the argument and sinks the load
past the call), a `static inline` helper that takes `dst` as a parameter (same
propagation), an inline accessor for the destination, and casts or struct
member forms of the address. Only the separate `src = get();` statement keeps
the load first.

The fix also moved the register colouring of the whole function: with the
load sunk, the shared `0x12c` state-offset constant took r5; with the split
statement it takes r6 as in the image.

Related, same function: two stores `f134 = 0; f170 = 1;` whose constants sit in
r1 and r2 (not r1 and r1) before a one-argument call show a hidden second
argument: the callee (func_021DEE3C, DWC_Init-like, `(gameId, ssl_type)`) takes
the 0 in r1, so the 1 cannot reuse r1.
