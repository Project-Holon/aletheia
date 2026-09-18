# Both arms of an if/else sharing a step are factored into one unpredicated instruction

summary: when two arms of a one-condition `if`/`else` compute the same step over
different bases, mwccarm hoists the common step out of the arms and runs it
unpredicated, feeding it a predicated base; an original that predicated the
step in *both* arms is therefore unreachable from the C, and the cost is four
bytes.

Found in: `src/pending/func_02068A18.c` (0x02068A18) and its row-loop twin
`src/pending/func_02068A68.c` (0x02068A68).

The pixel-expansion at the top of a surface fill is

```c
    if (bpp == 4) {
        px = arg | (arg << 4);
        px = px | (px << 8);
    } else {
        px = arg | (arg << 8);
    }
    px = px | (px << 16);
```

The original's arms are three predicated instructions into one register, with
the shared step *inside* the `eq` arm:

```
cmp   r2, #4
orreq r0, r1, r1, lsl #4     -> px = arg | (arg << 4)
orreq r0, r0, r0, lsl #8     -> px = px | (px << 8)
orrne r0, r1, r1, lsl #8     -> px = arg | (arg << 8)
orr   r1, r0, r0, lsl #16
```

This compiler instead notes that the `ne` arm's base is `arg` itself, so the
step is the same operation on a value that is either `arg` or `arg | (arg << 4)`;
it predicates only the *base* and runs the step once, unconditionally, into a
scratch register:

```
orreq r1, r1, r1, lsl #4     -> base = arg | (arg << 4), otherwise arg
orr   lr, r1, r1, lsl #8     -> lr = base | (base << 8)   (unpredicated)
```

Two instructions instead of three, four bytes shorter, and every later register
moves.  Four spellings were tried against it - a nested temporary for the `eq`
arm's intermediate, each arm as a single expression with the subexpression
repeated, `if (bpp != 4)` with the arms swapped, and writing the result back
through the parameter - and all four produce the factored form.  A nested
temporary is the interesting failure: putting the `eq` arm's intermediate in its
own variable is exactly what *should* stop the merge, and mwccarm folds it away
anyway, because for the `ne` path that variable's value is the base itself.

The rule to remember: an `if`/`else` whose arms end in the same operation over a
predicated value is recognised as one operation, and there is no source
spelling that keeps the duplicate.  When the original's two arms each carry the
step, expect to be exactly four bytes short and stop.
