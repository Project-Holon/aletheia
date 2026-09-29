# A shared `goto join` tail costs the parameter its register; repeat the call and the increment in each arm

summary: a switch whose arms all end in the same `call(ctx, r); (*st)++;` is spelled with that pair written out in every arm; a single `goto join` label lowers the use counts of `ctx` and `*st`, and the allocator then spills `ctx` and swaps the state and object pointers.

Found in: `src/matched/ov/ov020_func_02184730.c` (0x02184730),
`src/matched/ov/ov020_func_0218466C.c` (0x0218466C),
`src/matched/ov/ov020_func_02184AB4.c` (0x02184AB4),
`src/matched/ov/ov020_func_0218495C.c`, `ov020_func_02184B54.c`, `ov020_func_02184A14.c`

State-machine handlers `int f(ctx, int *st, u8 *p)` share one shape: read
`p[0]`, `p[1]`, `p[2]`, dispatch on `*st`, most arms `func_02012374(ctx, callee(...))`
then `(*st)++`. The original code has one `bl 0x02012374` and one increment because the
compiler cross-jumps the identical tails; the C has one per arm.

Writing the shared tail once (`r = callee(...); goto join;` with `join:` inside the first
arm) produces the right layout for some of them but wrong registers: `ctx` is spilled
to the stack and a loaded local takes its callee-saved register, and `st`/`p` (r4/r5)
come out swapped. The source has fewer uses of `ctx` and `st` than the original had
before the merge, and the allocator ranks by use count. Repeat
`func_02012374(ctx, callee(...)); (*state)++; break;` in every arm and both the
allocation and the merged tail come out byte for byte.

Two follow-ons: a default that also increments (0x0218466C, cases 1-7 and out of range)
is a written `default: (*state)++; break;`; and a duplicated `(*state)++;` typo in the
last arm makes the compiler write that arm's tail out in full instead of jumping back.
