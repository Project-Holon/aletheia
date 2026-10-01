# A loop subrecord offset written in the body sinks behind the entry guard

summary: When the image builds a record base before a loop guard but adds its subrecord offset after the guard, keep the record base as a local and add the subrecord offset in the per-element expression inside the loop. Assigning both offsets before the loop hoists the second add and changes the entry register allocation.

Found in: src/matched/ov/ov217_func_021BEC84.c (0x021BEC84), src/matched/ov/ov217_func_021BED10.c (0x021BED10).

The image computes the record selector and `p + 60` before its `count > 0` guard. After the guard it adds the scaled selector, spills that record base, adds 8, then spills the subrecord base into the same slot. The loop walks twelve-byte inputs and sixteen-byte stack outputs.

The matching spelling is:

```c
base = (struct Input *)(p + 60 + p[696] * 212);
for (i = 0; i < count; i++) {
    struct Input *q = (struct Input *)((u8 *)base + 8 + i * 12);
    /* read q and fill the output */
}
```

Assigning `base = (struct Input *)((u8 *)base + 8)` before the loop put both additions before the guard and produced 136 rather than 138 bytes in 021BEC84. An explicit outer `if (count > 0)` added a second guard and produced 140 bytes. The body expression reproduced all bytes; the twin with a different object-table offset matched on its first compile using that spelling. The local output array has seventeen sixteen-byte elements, as proven by the 0x11c frame including three spill words.
