# A clipped nested loop wants both bounds as expressions over fresh loop variables, not locals over the parameters

summary: `for (y = y0; y < y0 + h; y++)` and `for (x = x0; x < x0 + w; x++)`
hoist each bound into the preheader *after* the guard that precedes it, while
binding either bound to a local before the nest computes it before the guard;
when register pressure hides that difference the residue is not a moved
instruction but a rotation of the scratch registers holding the bounds.

Found in: `src/matched/func_02042ED8.c` (0x02042ED8), and the same nest in
`docs/notes/func_02042D2C.c.txt`

`src/matched/func_020413B0.c` already records half of this: the x bound must
stay the expression `x < x0 + w` rather than a local, because as an expression
it is loop-invariant and gets hoisted into the outer loop's preheader, which
is after the y guard, whereas a local is computed before it. The other half is
the y bound, and it is less visible because the wrong form usually costs no
instruction at all.

In `func_02042ED8` the y bound written the way `func_020413B0` writes it,

```c
int yEnd;
...
yEnd = y0 + h;
for (; y0 < yEnd; y0++) {          /* wrong here: eleven bytes */
```

gives an instruction stream that matches the original at every slot, with the
four values `yEnd`, `height`, `width` and `xEnd` living in `r3`, `ip`, `lr`
and `sb` against the original's `sb`, `r3`, `ip` and `lr`: a clean rotation by
one. All 120 orderings of the five local declarations give the same eleven
bytes, and so do type changes on the loop variables, which is the sign that
declaration order is not the lever.

The shape that compiles is symmetric with the x loop, a loop variable of its
own and the bound left as an expression:

```c
u8 x, y;
...
for (y = y0; y < y0 + h; y++) {
    if (y >= height) {
        return;
    }
    for (x = x0; x < x0 + w; x++) {
        if (x >= width) {
            break;
        }
        ...
    }
}
```

`y0 + h` is loop-invariant once `y` is a separate variable, so it is hoisted
exactly like `x0 + w`, and the four bound values are then allocated in the
original's order.

## The related tell in the same nest

Whether the row base is a hoisted pointer local or a subscript decides the
operand order of the store's addressing mode. `row = entries + width * y;
row[x] = v;` emits `strh v, [row, x_scaled]`, while
`entries[width * y + x] = v;` emits `strh v, [x_scaled, rowbase]` with the
scaled index in the base slot, which is what the original has. The pointer
local also computes the row base ahead of the inner loop's entry test instead
of in its preheader.
