# A ternary passed as a u8 argument is cast `(u8)`; a returned halfword stored raw with a second strh is a one-halfword struct return

summary: `lsls #24; lsrs #24` right after a two-branch merge (`b ? f(b) : 0x1f`)
before a `bl` is `(u8)(b ? f(b) : 0x1f)` when the callee's parameter is `u32`
(the same pair as the u16 idiom, at byte width); and `bl` then `strh r0,[sp+N]`
with no `lsls/asrs`, then a reload and a second `strh` at N+2, is the result of
a callee declared to return a one-halfword struct (`typedef struct { u16 v; } W;
W v = f(x);`), even when its own file says `s16`.

Found in: `src/matched/ov/ov093_func_021C2BF0.c`, `ov093_func_021C2C50.c`
(the cast), `ov093_func_021C3184.c` (the struct return; also a `const u16 *q`
made the `ldrh r3,[q]` argument load schedule first, and 4-byte struct
arguments by value: `ldr r1,[sp,#x]; add r0,sp,#4; str r1,[r0]`).

Other spellings that gave the same wrong code for the struct return: an `s16`
local with `*(W *)&v`, a `W` copied from another `W`, and an assignment
expression as the argument; all of them drop the second `strh` as dead.
