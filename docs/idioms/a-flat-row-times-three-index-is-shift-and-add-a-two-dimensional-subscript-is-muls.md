# A flat `a[row * 3 + i]` subscript is a shift-and-add, the `a[row][i]` spelling of the same 12 byte row is `muls`

summary: indexing a `void *f[24]` member as `p->f[row * 3 + i]` emits
`lsls rT, row, #1` / `adds row, row, rT` / `lsls row, row, #2` for the row base
and keeps the member offset in the load immediate; declaring the member
`void *f[8][3]` and writing `p->f[row][i]` emits `movs #0xC` / `muls` instead,
and casting the member to `void **` moves the member offset into a separate
`adds`.

Found in: src/matched/ov111_func_021C80E8.c (0x021C80E8),
src/matched/ov111_func_021C832C.c (0x021C832C)

Original loop head:

```
lsls r2, r1, #1
adds r1, r1, r2
lsls r1, r1, #2
adds r5, r0, r1        ; p + row * 12, hoisted
lsls r0, r4, #2
adds r0, r5, r0
ldr  r0, [r0, #0x7c]   ; member offset stays in the load
```

Only the flat member array with the multiply written as `row * 3` inside the
subscript reproduces all three parts. A row stride that is a multiple of 3
words and shows up as shift-and-add, not `muls`, says the source indexed a
flat array.
