# An enum stack parameter copied to a u32 local gets its own spill slot

summary: a `u32` stack parameter that spills goes back to its incoming slot and
is reloaded from there. When the image copies the stack word to a new frame
slot (`ldr r0, [sp, #0x30]` ... `str r0, [sp, #0x18]`), declare the parameter
as an enum and copy it into a `u32` local after the other locals' initialisers.

Found in: src/game/ov218/un_select.c (UN_SELECT_DrawFrameListRow, 0x021B9AE4)

The function takes a fifth parameter on the stack (a row index). A `u32`
parameter, a `u32` local copy of it, or a static inline copy all give the same
code: mwcc treats the incoming slot as the parameter's spill home, so the frame
is one word smaller and later uses reload `[sp, #0x30]`.

With an enum parameter the local copy is a real conversion to mwcc, so the
local keeps its own virtual register. That register is numbered after the
named locals, and it wins a cost/degree tie against `t` (`tools/mwccdbg`
regalloc: both 3/11 at the pick; ties keep the highest number). The copy then
spills to a new slot:

```c
void f(u8 *p, u8 *a, void *b, struct GfFont *c, enum Row idx)
{
    u32 r = 12;
    u32 d = idx;          /* after r: the spill store follows the r load */
    u32 t = 0x83 - d;
    ...
}
```

The declaration order decides where the spill store is scheduled. With
`u32 d = idx;` before `u32 r = 12;` the store moves above the `movs r6, #0xc`
(6 bytes differ).

The same source is EXACT for the English build too, where the allocation goes
the other way (t spills, d stays in r7) because `t` is passed straight to the
call instead of `t - 1`. It replaced the split u64 stand-in of
`a-stack-word-kept-in-a-register-while-a-temp-spills-is-the-high-half-of-a-split-u64.md`.
