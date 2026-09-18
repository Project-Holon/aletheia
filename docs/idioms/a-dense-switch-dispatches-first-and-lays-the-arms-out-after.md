# A small switch on dense case values dispatches first and lays the arms out after it; the equivalent if/else chain interleaves tests and bodies

summary: `switch (w) { case 3: ... case 4: ... case 5: ... }` with each arm an `if` that returns emits the whole compare chain first (`cmp #3 / beq`, `cmp #4 / beq`, `cmp #5 / beq`, `b default`) and then the three arm bodies in source order below it, while the same arms written as an `if`/`else if` chain emit each test immediately in front of its own body.

Found in: src/matched/func_0201A26C.c (0x0201A26C)

A three-case switch whose values are dense but do not start at zero does not
become a table; mwcc emits a compare chain and then the arm bodies one after
another, so the chain's branches all jump forward and the last arm's `break`
falls through to the default.  Written as `if (w == 3) ... else if (w == 4)
... else if (w == 5) ...` the compiler emits exactly the same instructions in
a different order, with every test glued to its body, and the function comes
out the same size but with a completely different branch layout: 58 bytes
against 60, with the two extra bytes being the `b default` the if/else form
does not need.

The tell in a diff, if the source is wrong, is that every arm body sits two
or four bytes earlier than the original's and every branch displacement is
short, while the compare constants are all correct.

If the case values were dense *from zero* the arm order would come from a
halfword table instead (`docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md`),
and a value with an empty arm still needs the arm written out
(`docs/idioms/empty-switch-arms-are-what-make-the-table.md`).
