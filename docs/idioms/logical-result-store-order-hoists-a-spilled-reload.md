# Logical result store order hoists a spilled reload

summary: after three calls, storing their results in acquisition order lets mwcc reload the spilled second result before storing the third, while spelling the assembly's final store order reloads it too late.

Found in: `src/matched/ov/ov217_func_021BA910.c`, `src/matched/ov/ov217_func_021BA978.c`.

Both functions acquire three resources into `a`, `b`, and `c`. The second result spills to the stack. The image reloads `b` before storing `c`, then stores `a` and `b`. Spell the stores in logical acquisition order:

```c
p->slots[0] = a;
p->slots[1] = b;
p->slots[2] = c;
```

With dsi/1.1p1 `-O4,p` Thumb this schedules the reload before the last-return store and emits the image's `c,a,b` store order. Writing `c,a,b` directly instead gave 9 and 10 concrete differing bytes respectively, despite equal compiled lengths. In 021BA910, converting raw offsets to the observed struct alone left the same nine-byte difference; acquisition-order stores then gave EXACT*. 021BA978 used the same struct and order change and gave EXACT*. This differs from retaining source order through struct fields: the winning assembly still reorders the three stores.
