# Address sums recomputed after every call mean the function was built with CSE off

summary: if the image rebuilds every `base + i * k` address (and `i * k`
itself) after each call in a long loop body, while 1.1p1 -O4,p on any
natural spelling keeps those sums in callee-saved registers or spill slots,
no source spelling we know of reproduces it. The function was compiled with
global common-subexpression elimination off. Index casts that differ per
statement, temporaries and `(&t[i].x)[1]` only imitate that.

Found in: src/pending/ov/ov094_func_02204CC0.c (0x02204CC0, ov094, Thumb)

Tell, all together:

* `lsls rX, i, #2; adds rY, p, rX` repeated before every call that takes
  `p->obj[i]`, the same for `q + i` and `i * 2`, never spilled;
* pointer parameters sit in callee-saved registers, and plain locals that
  live across calls (a call result used twice, for example) are spilled
  instead;
* a pure `i * 8` used only as an index into tables does stay in a register
  across calls;
* offset constants are still hoisted out of the loop one by one and constants
  are still built with `movs/lsls`, so the optimiser was on (with `asm { nop }`
  in the body, constants go to the literal pool instead).

Measured on that function: `#pragma opt_common_subs off` before the function
with the plain spelling gives the image's size, frame, register picture and
prologue slots (308 bytes out against 664 for the best cast-based draft).
None of these turns the CSE off: loop counter type (int, u8, u16, s16, u32,
long, enum), `register`, a volatile struct pointer, void pointer parameters
cast at each use, static inline accessors, raw `char *` offsets in any
association, extra locals, thousands of extra statements or branches, switch,
static locals, function pointers, struct copies, varargs, bit-fields, float,
division, long long. The pragma changes codegen, so a lane cannot file it
without a decision from the user.
