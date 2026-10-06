# opt_loop_invariants off keeps loop invariants as declared locals

summary: with loop-invariant motion on, a value used two or more times inside a loop gets new
loop webs. Those webs spill below all declared locals, and a narrowing conversion moved out of
the loop can fold into a nearby shift. `#pragma opt_loop_invariants off` before the function
(`reset` after it) keeps such values as plain declared locals, and the backend still hoists
what it needs.

Found in:
- src/matched/ov/ov132_func_021FB3E0.c: x, y, z (two or three loop uses each) spilled below the
  other locals in every source form. With the pragma, the slots follow declaration order.
- src/matched/ov/ov121_func_021DAB50.c: an s16 weight computed from `/ 2` always folded into
  `lsls #0xf; asrs #0x10`. With an int `factor` before the loop, the s16 conversion done in the
  loop and the pragma on, the original `asrs #1; lsls #0x10; asrs #0x10` comes back.

Check first: if loop values spill in an order no declaration order reaches, or a conversion
folds in every spelling, try this pragma before reworking the source.
