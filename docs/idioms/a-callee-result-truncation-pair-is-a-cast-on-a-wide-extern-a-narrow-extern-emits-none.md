# A `lsls #24/#16; lsrs` pair after a `bl` is a cast on a wide extern; a narrow extern emits none

summary: when the image truncates a call result right after the `bl` (`lsls r0,r0,#0x10; lsrs r0,r0,#0x10`, or `#0x18`) and your `u16`/`u8`-returning extern compiles with no such pair, declare the extern to return `u32`/`int` and write the cast at the call (`(u16)f(m)`, `(u8)g(a)`); conversely a result the image keeps raw (`adds r6, r0, #0`, no truncation, later stored with `strb`) wants the extern declared `u8` and the local `u8`, since a wide local makes the compiler spill and re-truncate it.

Found in: src/matched/ov/ov093_func_021CC558.c (`t = (u16)func_021D5B40(m)`),
src/matched/ov/ov093_func_021CC4AC.c (`(u16)func_021D5B40(m)` into a `u16` parameter, `(u8)func_021C84AC(...) == 0`),
src/matched/ov/ov093_func_021CC178.c and ov093_func_021CC214.c (`u8 func_021D5440` with a `u8 id` local, `(u8)func_021D805C(...)` from a `u32` extern),
src/matched/ov/ov093_func_021CC768.c (`(u8)res == want` with `int res`, `int want`)

A `u16`-returning extern (the matched `func_021D5B40` is one) gives no truncation at the
call site, so the caller's `lsls; lsrs` pair cannot come from the prototype. Declaring the
extern `u32` and casting where the image truncates reproduces the pair and, in
func_021CC558, also stops the result from being spilled (`str r0,[sp]` where the image has
`lsrs r6, r0, #16` feeding a `beq`). The same applies to a `u8` compare: `res == want`
with `u8 res` folds the cast away, while `(u8)res == want` with `int res` keeps it.

The reverse case: func_021D5440 is called eleven times in ov093 and every matched caller
that stores the result with `strb` and passes it on raw declares it `u8`. With an `int`
extern and an `int` local the compiler kept the value in a stack slot and re-truncated a
copy inside the loop (func_021CC214: `sub sp,#0x14`, one slot too many).

Related: locals declared later sit at lower stack addresses, which fixed the last residue of
func_021CC214 (slot order lim/ok/n) once the widths were right; declaring `n, ok, lim`
in that order put them at [sp,#0xc], [sp,#8], [sp,#4].
