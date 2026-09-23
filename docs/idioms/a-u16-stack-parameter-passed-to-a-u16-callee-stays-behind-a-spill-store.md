# A u16 stack parameter passed to a u16 callee parameter stays behind a spill store

summary: when a stack-passed parameter's load is hoisted above a neighbouring
spill store (`ldr rN, [sp, #param]` scheduled early), declare the parameter u16
AND the callee's matching parameter u16; with both u32 the load floats up, and
u16 on the parameter alone changes the size.

Found in: src/matched/sub_0201B2B0.c (0x0201B2B0)

The image computes a spilled local and stores it, loads another spilled local
into r0, and only then loads the seventh (stack) parameter into r2 for the call:

    lsrs r0, r0, #0x10
    str  r0, [sp, #0x1c]      ; pidHigh spill
    ldr  r0, [sp, #0x24]      ; held
    ldr  r2, [sp, #0x68]      ; heap, the 7th parameter
    movs r1, #1
    bl   func_02020FE4

With `u32 heap` and `u32 func_02020FE4(u32, u32, u32)` 1.1p1 schedules the
`ldr r2, [sp, #0x68]` right after the load of pid, above the whole
ands/lsrs/lsls/lsrs/str chain (12 bytes out).  None of const, a local copy,
volatile, casts at the call, declaration order, an enum type or the permuter
moved it.  `u16 heap` with the u32 prototype is 4 bytes long and 1036 out;
`u16 heap` with the callee's third parameter also u16 is byte-exact.

The callee confirms the width: func_02020FE4 masks that argument to fifteen
bits and ORs in 0x8000 (a temporary heap id), and src/matched/unit_02007CB0.c
already declares it u16.  Heap ids in this code base are u16; when a heap id
parameter's load is in the wrong place, try u16 on both ends before anything
else.  The same "parameter stack load scheduled across a neighbouring stack
store" residue is recorded for 0x0201FDA0 and 0x02013528.
