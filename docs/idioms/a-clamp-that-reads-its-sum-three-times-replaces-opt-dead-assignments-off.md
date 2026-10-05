# A clamp that reads its sum three times replaces opt_dead_assignments off

summary: when `#pragma opt_dead_assignments off` fixes a function's frame and spill slots, look
for a value the original reads several times instead of a real dead store; a channel clamp
written as `if (a + d > 31) x = 31; else if (a + d < 0) x = 0; else x = a + d;` keeps the delta
alive and spilled exactly as the pragma did.

Found in: src/pending/ov/ov091_func_021B6B24.c (0x021B6B24, palette fade; DIFF, residue elsewhere)

Shape: a per-channel colour blend with a clamp to 0..31. With a single-use delta (`s = a + d;`
then a clamp on `s`) the compiler propagates the delta into the clamp, the delta never gets a
stack slot, and the frame is 8 bytes small. `#pragma opt_dead_assignments off` restores the slot,
which suggests a dead store, but the listing has none.

Right C: write the clamp so that it recomputes `a + d` in each test and in the final assignment,
as a macro like `CLAMP(a + d, 0, 31)` that repeats its argument would expand. The delta then has
three uses per channel, stays live, and is spilled to the original slot (here the row pointer at
[sp+4] and a delta at [sp+0x14], frame 0x28) with no pragma.

Human reading: macro-style clamps that repeat their argument are common in game code. Try this
before filing the pragma.
