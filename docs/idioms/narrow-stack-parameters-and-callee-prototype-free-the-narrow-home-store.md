# A narrow register parameter reaches the front of the prologue only when the stack parameters are narrow too

summary: when a spilled r3 parameter's home store should lead the prologue but narrowing it alone moves it only part way, narrow the stack parameters it travels with as well, in the function and in the callee prototype, to the callee's own matched widths.

Found in: src/matched/func_0202173C.c (0x0202173C), src/matched/func_02021848.c (0x02021848)

The image opens with `str r3, [sp, #8]` (the spill of the fourth parameter)
ahead of `adds r5, r0` and the self-copies of the stack parameters
(`ldr r0, [sp, #0x38] / str r0, [sp, #0x38]` and so on). With `s32 step`
and u32 stack parameters the store is scheduled as a load-delay filler after
`ldr r0, [sp, #0x3c]` (33 bytes out, for eight waves). Narrowing `step`
alone to s16 moved it two slots (34 out), and narrowing the stack parameters
without the callee prototype cost 4 bytes (236 against 232).

What closes both: the callee's matched body (func_020219C4) takes
`s32 a, u8 b, u8 c, u16 d`; declare the prototype that way, declare the
caller's own stack parameters `u8 b, u8 c, u16 d` to match, and make the
register parameter narrow (`s16 step`; u16 and s8 give the same bytes).
Then the narrow home store is emitted first, the stack copies stay
word-wide (`ldr`/`str`, no narrowing instructions), and every filler
(`movs r6, #0`, `movs r4, #0`) lands where the image has it.

Rule: read every parameter width from the callee's own body, including the
stack-passed ones, before concluding a prologue store order is out of reach.
