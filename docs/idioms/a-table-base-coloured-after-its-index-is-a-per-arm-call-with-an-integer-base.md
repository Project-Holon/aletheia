# A table base coloured after its index is a per-arm call with an integer base

summary: when several arms each load a different table address into one
callee-saved register and fall into a shared block that indexes it
(`ldr r6, =tblN; b calc` ... `calc: lsls r4, idx, #2; adds r0, r6, r4;
ldrh r1, [r0, #2]; ldrh r0, [r6, r4]`), and the base sits in a higher
register than the scaled index and the other values of the shared block, the
source did not hold the table in a pointer local. Each arm called (or
expanded) the shared computation with its own table, the address cast to an
integer, and the identical tails were cross-jumped into one block.

Found in: src/matched/ov/ov021_func_021CBD90.c (0x021CBD90, ov021, Thumb)

A `const Range *tbl` local assigned in each arm and indexed once after them
is a named variable: it is coloured first and takes r4, pushing the index
and the span to r5/r6. More than 150 spellings of that shape (declaration
order, scoping, self-assignments, statics, helper functions taking the
pointer, gotos, block layout) never moved it. Written per arm, the base is a
short-lived load coloured after the index and the span, which is the
image's order.

Two details decide the bytes of the per-arm form:

- a pointer base (`d_X[round].hi`, or an inline helper taking `const Range *`)
  is constant-propagated and folds the field offset into a second pool word
  (`ldr r0, =d_X+2; ldrh r1, [r0, r4]`); an integer base, `(u32)d_X`, keeps
  `adds r0, base, off; ldrh r1, [r0, #2]`;
- `((const Range *)(u32)d_X)[round]` shifts the index before loading the base,
  so the arms keep their own `lsls` and only the tail after it merges; byte
  arithmetic on the integer, `(const Range *)(tbl + round * 4)`, loads the base
  first and the shift moves into the merged block.

```c
static inline u16 RandInRange(void *ctx, u32 tbl, u32 round)
{
    u16 span = ((const Range *)(tbl + round * 4))->hi - ((const Range *)(tbl + round * 4))->lo + 1;
    return func_021CBF98(ctx) % span + ((const Range *)(tbl + round * 4))->lo;
}
...
        if (stage < 6) {
            id = RandInRange(ctx, (u32)d_021DB3E4, round);
            goto end;
        }
        id = RandInRange(ctx, (u32)d_021DB3F4, round);
```

Tell: a register that held a dead parameter is reused for the table base,
the index scaling sits at the top of the shared block, and the lo field is
read with a register offset `[base, off]` both before and after a call.
