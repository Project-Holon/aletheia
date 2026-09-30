# A swapped store and read-modify-write in one if-arm recolours the whole loop

summary: when one arm of a loop holds two independent side-effecting statements
(a plain store and a load-modify-store through a pointer) and the loop's
callee-saved registers come out rotated with no declaration-order lever moving
them, the order of *those two statements* can be the whole fault. The vendor's
`.debug_line` gives the original statement order; matching it can recolour the
loop's saved registers even though the arm's own instructions end up in the
same slots.

Found in: src/pending/ov_sdk/ov016_func_021D657C.c (0x021D657C, readKey,
libdwcutil.TWL.HYB.a input.o)

The function masks a 14-bit key value and, inside `for (i = 0; i < 14; i++)`,
bumps a byte counter `g_021DE690[i]`. On the `== 47` arm the obvious C is

```c
} else if (g_021DE690[i] == 47) {
    g_021DE690[i] = 40;                               /* plain store  */
    g_021DE688.ks->repeat |= (unsigned short)(1 << i); /* load+RMW     */
}
```

which compiled with the loop's saved registers rotated: the hoisted constant 40
landed in `r7` and the byte/add temps in `r5`/`r6`, where the image has 40 in
`r5` and the temps in `r6`/`r7` (71 concrete bytes).

The vendor object's `.debug_line` for the arm is two source lines, **163 (the
`repeat` RMW) before 164 (`count[i] = 40`)**. Swapping the two statements to
that order:

```c
} else if (g_021DE690[i] == 47) {
    g_021DE688.ks->repeat |= (unsigned short)(1 << i); /* line 163 */
    g_021DE690[i] = 40;                                /* line 164 */
}
```

recolours the entire loop onto the image's allocation (40 in `r5`, temps in
`r6`/`r7`) and took the file from 71 to 54 concrete bytes. The arm's own
instructions stay in the same slots — the scheduler interleaves them the same
way either way — so the size is unchanged and nothing in the arm's own diff
hints at the cause; only the *loop-wide* register rotation moves.

When to reach for it: a whole-loop callee-saved rotation that survives every
declaration-order, scope, type and named-local sweep, when the loop has an arm
with a store and a load-modify-store of independent targets. Read the vendor
`.debug_line` (see docs/notes/vendor-debug-line-gives-statement-grouping.md) for
the original statement order and try it before a permuter run. This is a
statement-order lever, not the `.debug_line`-is-not-a-register oracle point: the
line table is what names the order to try, and the compile confirms it.
