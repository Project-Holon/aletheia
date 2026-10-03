# A dead store between a temp and its use blocks copy propagation and costs no code

summary: When the image keeps a field in its own temp (as `#pragma opt_propagation off`
would), put a dead store to the same destination between the temp's definition and its
use. The compiler removes the dead store, but the store still kills the temp's source,
so the temp is not copy-propagated. No pragma is needed.

Found in: src/matched/ov/ov093_func_021EE96C.c (0x021EE96C)

The target stores `b` to `d[0]` first, then extracts the bitfield `x` into its own
register (with `r1` as scratch, since `b` is dead), then builds the header byte `d[1]`.
A temp read after the `d[0]` store is copy-propagated into the OR tree, and the tree is
then evaluated in a different order (cnt first, 27 bytes off). A temp read before the
store blocks propagation, but the scheduler then places the `strb` to `d[0]` after the
extraction (10 bytes off). The pragma `opt_propagation off` gives EXACT.

This spelling gives EXACT with no pragma:

```c
p->d[0] = b;
type = p->x;
p->d[1] = 0;      /* dead, removed, but it blocks propagation of type */
p->d[1] = ((p->f & 1) << 7) | ((type & 7) << 4) | (p->cnt & 0xf);
```

A later store of a different type (for example `*out = p->len` before the header) also
blocks propagation, but it emits its code in the wrong place.
