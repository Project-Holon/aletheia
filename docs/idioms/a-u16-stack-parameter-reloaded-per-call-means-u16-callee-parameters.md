# A u16 stack parameter reloaded with ldrh before every call means the callees take it as u16

summary: when the image re-reads a u16 stack parameter from its home slot (`ldrh rN, [rB]`
off a base register pointing at the incoming arguments) before each call that passes it,
the callees' matching parameters are u16; with u32 callee parameters the compiler loads
it once into a callee-saved register, which costs an extra pushed register and a bigger
frame. `volatile` on the parameter also reproduces the bytes, but the callee widths are
the real cause.

Found in: src/matched/ov/ov208_func_021C0B6C.c (0x021C0B6C)

The image starts `push {r4-r7, lr}; sub sp, #0x1c; add r4, sp, #0x30` and then reads the
heap id as `ldrh r1, [r4]` before `func_020490F4`, again before `func_0204A6C8` and again
before `func_0204B294`. With the three callees declared `(…, u32 heap)` the draft loads the
parameter once into r4, pushes r3 as well, and the frame grows to 0x20 (126 bytes out, 4
bytes short). Declaring the callees with the widths of their own matched bodies
(`sub_0204A6C8(…, u16 flags)`, `sub_0204B294(…, u16 f, u16 g)`) makes the argument a u16 to
u16 pass, which the compiler rematerialises from the slot at each call, and the function is
EXACT. Derive the width from the callee's body, not from the call site.
