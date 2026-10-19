# A clamp written as a ternary on itself sets the spill slot order

summary: `n = (n > 9999) ? 9999 : n;` reads n a different number of times than the if form, and
the read count orders the spill slots; use the ternary when spilled locals sit in rotated slots.

Residue: three spilled int locals (a selector and two clamped numbers) sit in rotated
stack slots; no declaration order or scope change moves them.

Cause: `if (n > 9999) n = 9999;` and `n = (n > 9999) ? 9999 : n;` give the same code but a
different number of reads of `n`. The reads count in the spill priority, which orders the slots.

Fix: write the clamp as `n = (n > 9999) ? 9999 : n;`. Declaration order, block scope, int vs
unsigned selector, if/else vs ternary for the selector and all six pragmas changed nothing.

Found in: src/matched/ov/ov183_func_021DD684.c
