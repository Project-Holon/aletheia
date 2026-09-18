# A two-word region as a struct pins the stack slots that scalars let mwcc reuse

summary: whether two adjacent words are one `struct` or two scalars decides whether mwcc may reuse the
dead scalar's stack slot for another local. Both spellings are needed in the same function when the
original pins one region and reuses another.

Found in: `func_02060888` (packet `pkt_02060814`), EXACT at 384 bytes, and its counterpart
`func_02060E30` (packet `pkt_02060CD0`), EXACT at 60 bytes

The expand-heap carve takes three region descriptors. The first is two words:

```c
/* pins both slots: mwcc cannot fold the pair or reuse either slot */
struct MemRegion r0;
/* lets mwcc reuse a dead scalar's slot, which is what the original does here */
u32 start, end;
```

Written as a struct *everywhere*, the first region's address folds into `r4` and the function grows by
24 bytes and needs `r9`. Written as scalars everywhere, the region that must stay pinned loses its
slot stability. The original wants one of each, in the same function:

- first region: two scalars, with `&end - 1` spelled at the second call site, where the `- 1` applies
  to the local's address rather than to a struct member;
- the other two regions: `struct MemRegion`.

This is the mirror image of the `func_02060E30` finding, where two scalars beat an `int[2]` for the
opposite reason: an `int[2]` made mwcc cache `sp+0` across a call, and two separate scalars stopped it.
Between the two, the general rule is that aggregate-ness of a small stack object is a lever on slot
allocation, not a style choice, and the same function can need both answers at different sites.

Secondary levers from the same function, each verified by compile-and-compare:

- read the heap attribute as `(u8)value`, since a bare `& 0xff` on an already-narrow load folds away;
- assign the clear size to a local before the `if`, which hoists `ldr`/`ldr`/`sub` above the branch
  and leaves the branch on the attribute's `tst`;
- build the attribute with a clear-then-set statement pair rather than the fused expression, see
  `a-clear-then-set-statement-pair-is-what-emits-two-stores-per-attribute-field.md`.
