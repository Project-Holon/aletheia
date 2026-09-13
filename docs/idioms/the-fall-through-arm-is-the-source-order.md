# The arm that falls through is the one the source wrote first

summary: this compiler never reorders the two arms of an `if`, so the code
immediately after the conditional branch is the source's `then` and the code
the branch jumps to is what came after it; getting the polarity wrong is a
whole-function diff, not one instruction.

Found in: `src/matched/unit_02008B4C.c` (0x02008BE0),
`src/matched/unit_02008F80.c` (0x02008FC8)

Two shapes in one packet turned on this, and both looked like a scheduling
problem until the arms were read the other way round.

`sub_02008FC8` is a bounds-checked table lookup, sixteen bytes:

```
cmp  r1, #3
bhs  out_of_range
adds r0, #0x20
lsls r1, r1, #3
adds r0, r0, r1
bx   lr
out_of_range:
adds r0, #0x20
bx   lr
```

The branch is taken when the index is **out** of range, so the in-range arm is
the fall-through and therefore the `then`:

```c
if (i < 3) {
    return &obj->unk20[i];
}
return &obj->unk20[0];
```

Writing the guard first instead, `if (i >= 3) return &obj->unk20[0];`, produces
exactly the same six instructions with the condition inverted and the two arms
swapped, which is ten of the sixteen bytes wrong.

`sub_02008BE0` is the same lesson on an `if`/`else`:

```
cmp r2, r1
bcs subtract
movs r1, #0
str  r1, [r0, #0x34]
bx   lr
subtract:
subs r1, r2, r1
str  r1, [r0, #0x34]
bx   lr
```

`bcs` is unsigned `>=`, so the fall-through is the `<` case and the source is
`if (x < n) x = 0; else x -= n;`. The natural reading, `if (x >= n) x -= n; else
x = 0;`, swaps the arms and is four bytes wrong in the middle of a function that
is otherwise byte for byte right.

The rule generalises: read the condition on the branch, negate it, and that is
the condition the source wrote. The compiler emits the `then` inline and the
`else` out of line, always, and it does not invert a test to shorten a branch.
