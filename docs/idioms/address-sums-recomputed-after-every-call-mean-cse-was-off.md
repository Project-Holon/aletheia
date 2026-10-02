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

Update (2026-10-02, after the user approved the pragma for this function):

* Scope is per function. The EXACT neighbour func_022050F0 in the same
  likely file keeps `i * 12` and `p + i * 12` in spill slots and reuses them
  after calls, which CSE off cannot do. Use `#pragma opt_common_subs off`
  before the function and `#pragma opt_common_subs reset` after it.
* CSE off alone was not enough there. The image also kept the copies that
  propagation leaves dead: adding `#pragma opt_dead_assignments off` (or
  `#pragma opt_propagation off`, same output) took it to byte-identical.
  That second pragma needs its own user decision.
* With dead copies kept, local spellings matter again that are inert under
  normal settings: u8 colour locals assigned b, g, r and passed r, g, b
  recolour the whole body (the call result stays in r0, which moves the
  callee-saved picture, spill slot order and which temp spills), and a
  `const` pointer parameter moves a `q + i` add above the stack-argument
  stores of the next call. Re-measure every lever once the pragmas are on.
* Measured as no help: opt_lifetimes off, optimization_level 0 to 3,
  global_optimizer off, optimize_for_size, opt_dead_code off,
  opt_strength_reduction off, scheduling off.
