# A scaled record base pointer spills the wrong loop value; index the struct array

summary: in a loop with high register pressure, a record reached through a
named base pointer (`q = p + k * 6; q->t[0].x`) adds a value that is live
through the inner block and tips the allocator: it spills the short-lived call
result and keeps the loop counter in a callee-saved register. The same element
written as a struct-array access (`p->c.t[k].x`) compiles to the same
`p + k*6` and load, but the allocator then spills the counter and keeps the
call result, as in the image.

Found in: src/matched/ov/ov217_func_021C13E8.c (0x021C13E8, GX line draw, closed
in wave D9r lane 52 after eight lanes left it at 166 to 198 bytes)

## Symptom

Size and instruction order match. The image keeps the per-iteration call result
`e` (and later `y`) in r7 and spills the loop counter `i` to `[sp,#4]`; the build
keeps `i` in r7, spills `e`, and needs one more stack slot (frame 0x2c, push
without r3). Declaration orders, loop forms, inline helpers and local types do
not move it.

## Fix

```c
/* before: a base pointer per record */
struct Big *q = (struct Big *)((u8 *)p + b[1] * 6);
x = px + q->c.t[0].x;
/* after: the struct array indexed directly */
x = px + p->c.t[b[1]].x;
```

The `p + k*6` add is still one value in the output (`adds r3,r5,r2`), so the
listing looks the same for both forms. Two smaller fixes finished the function:
the GX vertex word packed x first (`(u16)x | ((u32)(u16)y << 16)`, the order of
the SDK pair macro) and the counter declared before the bound (spill slots
follow the declaration order in reverse).

## Test

Adding two more uses of `e` also moved `i` to the stack, which showed that the
residue was the spill choice between `e` and `i`, not a colouring tie. Look for
a source value that the original did not have (a named base pointer) before
adding uses.
