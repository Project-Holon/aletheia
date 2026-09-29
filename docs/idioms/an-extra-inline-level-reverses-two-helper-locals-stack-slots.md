# An extra inline level reverses the stack slots of two inline helpers' locals

summary: two calls to one inline helper that each copy a struct into a helper-local get their slots in a fixed order (first call's copy higher); routing one of the calls through a second inline wrapper, one level deeper, swaps the two slots and leaves every instruction unchanged.

Found in: src/matched/ov/ov021_func_021C1AF4.c (0x021C1AF4)

The function builds two cameras. Each call copies a position and an up
vector from tables and zeroes a target on the stack. The image lays the six
VecFx32 out, high to low, as pos1, tgt1, pos2, tgt2, up2, up1. The code runs
pos1 copy, tgt1 = {0}, up1 copy, call 1, then the same for call 2.

- Caller block locals `{ VecFx32 p1 = ...; VecFx32 t1 = {0, 0, 0}; ... }` take
  the top slots in textual order.
- Putting the up copy inside an inline helper
  (`static inline void *mk(..., const VecFx32 *upsrc, ...) { VecFx32 up = *upsrc; return func(..., &up, ...); }`)
  moves both up vectors below the caller's locals and keeps the copy after
  the target zeroing. Called directly at both sites, it gives up1 above up2
  (2 bytes out: two `add rN, sp, #k`).
- Calling the first site through `mk_persp(pos, up, tgt, heap)`, an inline
  that only forwards to `mk` with that call's constants, puts up1 below up2
  and matches.

Things that did not change the order: a nested block around the helper's
local, two identical helpers (either definition order), and passing up by
value. Nesting the second call instead of the first also leaves it unchanged.
When helper-local slots come out swapped, try one more inline level on the
site whose local should be lower. The wrapper is a matching aid. The
original may have had a real wrapper there, such as a default-camera
constructor.
