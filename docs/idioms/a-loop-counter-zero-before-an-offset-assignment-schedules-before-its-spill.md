# A loop counter zero before an offset assignment schedules before its spill

summary: when a Thumb tile loop has the correct stack slots and body but a
computed row offset's spill precedes zeroing its counters, initialise the
counter before assigning the offset; the multiplication can still schedule
early while its spill stays after the zero.

Found in: `src/matched/ov/ov120_func_021D6CCC.c` and
`src/matched/ov/ov120_func_021D6C7C.c`.

Both loops compute `off = 6 * n`, then issue tile writes with `y + off`.
An initialised declaration `int off = 6 * n;` followed by `for (y = 0; ...)`
puts the offset spill before the counter zero. Declare the offset without
an initializer and write:

```c
y = 0;
off = 6 * n;
for (; y < 6; y++) {
    /* tile loop */
}
```

The multiplication remains before the zero in the emitted instructions,
but its `str [sp]` moves after it. This repaired the three scheduling-byte
differences in 021D6C7C. In 021D6CCC the same change plus declaring `x`
before `y` repairs the scheduling and the inner/outer register swap;
declaration order is independently covered by its existing idiom.

The earlier counter-before-bound idiom concerns a zero literal pool and
spilled counter. Here the counters remain in registers and no pool changes:
only the computed offset's spill is scheduled around their initialisation.
