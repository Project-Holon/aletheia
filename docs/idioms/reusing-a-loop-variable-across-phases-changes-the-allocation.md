# Reusing one loop variable across two phases changes the register allocation; a fresh variable does not reproduce it

summary: a same-size residue that rotates three registers around a loop
counter, and that no statement-level permutation moves, can be the
counter's VARIABLE IDENTITY: the original reused a variable from an earlier
phase of the function (so its live ranges merge into one allocator value),
and a dedicated loop variable gives a different colouring.

Found in: src/matched/func_0206AB18.c (0x0206AB18, a 4x4 Gauss-Jordan
inverse, ../2.0/sp2)

The elimination phase `for (j = 0; j < 4; ++j) if (j != i) { a = t[j][i]; ... }`
with `j` used nowhere else compiled 520/520 with 17 bytes out: j, a and
a >> 31 in r2 / ip / r3 where the image has ip / r3 / r2.  Declaration order,
a's type and scope, `continue` against a guarded block, do-while, and a
permuter hill (252 singles) plus anneal (700 compiles) all stayed at 17.

Sweeping WHICH variable plays each role (the pivot-row record, the pivot
scan, the swap/scale/elimination column index, the elimination row) found
ten EXACT assignments out of ninety, and every one shares the elimination-row
variable with an earlier role.  The one filed stores the pivot row in `j`
(`j = i; ... if (|t[r][i]| > max) j = r;`) and then reuses `j` as the
elimination row.

When to reach for it: a residue that is purely a register rotation, at the
correct size, involving a loop counter, in a function with several loops.
Try making the counter the same variable as one an earlier loop or phase
already uses before any more spelling sweeps.
