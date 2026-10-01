# A named destination index keeps two array offsets scaled separately

summary: for a Thumb halfword move between adjacent array elements, bind the destination index before either store; an inline `a[index-1] = a[index]` lets the optimizer build and decrement a pointer, while the named index preserves two integer shifts and register-offset stores.

Found in: src/matched/ov/ov217_func_021BBDF0.c and src/matched/ov/ov217_func_021BBE7C.c, dsi/1.1p1 -O4,p Thumb.

The matched loop binds the row helper result and computes the destination separately:

```c
base = func_021BBF1C(object, slot);
index = column + 2 + (base + row) * 32;
destination = index - 1;
first[destination] = first[index];
second[destination] = second[index];
```

The corresponding right-shift loop uses `column + 1` and `destination = index + 1`. Both produce separate `lsls` instructions for source and destination, followed by register-offset loads and stores. Binding the helper result also restores `adds r0,r0,r6` rather than commuting the helper result to the right.

Inline destination expressions yielded 144 versus 140 bytes for the left shift and 136 bytes with 28 differing bytes for the right shift. Changing the index from unsigned to signed or enum alone did not repair the left shift. The named destination reduced its residue to 13 register-colour bytes; the declaration order `first`, `row`, `second`, `column` then matched both loops. The integer-offset binding is separate from the explicit pointer-arithmetic choice described in `pointer-minus-one-scales-before-the-subtraction.md`.
