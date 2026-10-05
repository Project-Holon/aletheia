# A struct array field instead of a pointer local swaps a u8 spill slot

summary: when the original spills a row pointer `a1 + k` to the LOWER slot and
a u8 value read through it (`n = q[0x21EC] + 1`) to the slot above, a named
pointer local `u8 *q = a1 + k;` always gives the opposite order (the u8 local
takes the lowest slot). Write the access as a struct array field indexed by k
(`a1->cnt[k]`, with `a1` typed as a struct that has `u8 cnt[4]` at +0x21EC).
The compiler then makes its own CSE temp for `a1 + k`, and that temp takes the
slot below the u8 local, as in the original.

Found in: `src/matched/ov/ov039_func_021F4A18.c` (0x021F4A18)

Before: 6 bytes differ (`str r1, [sp, #8]` / `str r0, [sp, #0xc]` swapped), with
declaration order, scope moves, int/u16 widths and int prototypes all tried.
Raw `(a1 + k)[0x21EC]` gives a different temp placement (26 bytes). Only the
struct field form `((S *)a1)->cnt[k]` gave EXACT.
