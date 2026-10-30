# A u16 local widened in a loop call becomes a hoisted temp that loses colour ties

summary: a `u16` local passed to a `u32` parameter inside a loop is widened by a cast that IRO_MoveInvariantExpressions hoists into a new temp; the local itself disappears, and the temp is numbered below every named local, so a declaration-order change cannot move it. Declaring the local `u32` (it still holds the `(u16)` value) keeps it a named variable, and then declaration order decides the colour tie.

Found in: src/game/ov093/btl_server_flow.c (BTL_SERVER_FLOW_AddDefeatEffortValues, Japanese build)

The function reads `form = (u16)BTL_POKEPARAM_GetValue(...)` once and passes it to
`POKE_TOOL_GetPersonalParam(m, form, ...)` in a six-step loop. The file declares that
callee with `u32` parameters. With `u16 form`, the loop holds `(u32)form`, an invariant
cast: mwccdbg `cse --names` shows the temp is born in IRO_MoveInvariantExpressions
(0x59A670). The temp got a lower vreg number than the loop counter `i`; both were pushed
in the same simplify sweep, so `i` was coloured first and took r4. The Japanese image
gives r4 to `form`.

`u32 form;` declared before `u8 i;` gives the Japanese bytes. The value stays narrowed at
the assignment (`lsls`/`lsrs #16`) because the cast is on the right-hand side. Black
stays EXACT with the same declarations (its colour order was already form-friendly).

How to spot it: `regalloc` lists the variable's web under an `@N` name instead of the
variable name, and `cse --names` puts that `@N` in a different creator than the CSE
temps. Swapping declarations then changes nothing until the type matches the parameter.
