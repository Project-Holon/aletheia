# Distinct arithmetic types keep equivalent row addresses apart

summary: When two uses of the same row address need different lifetimes, distinct arithmetic types can keep their compiler expressions apart: signed versus unsigned stride multiplication, or pointer addition versus unsigned integer addition. A single spelling can merge the row values and change recomputation, spills and register colours.

Found in: src/matched/ov/ov112_func_021F36C0.c (0x021F36C0), src/matched/ov/ov112_func_021F3F00.c (0x021F3F00), both EXACT with dsi/1.1p1 -O4,p Thumb.

In 021F36C0 the original computes the 88-byte row before an inner fill loop,
then computes it again for the fixed stores after that loop. The successful
spelling uses the same byte pointer but distinguishes the multiplication types:

```c
for (i = 0; i < 4; i++) {
    u8 *q;
    q = cfg + 88U * i;
    /* row header and inner eight-slot fill */
    q = cfg + 88 * i;
    /* fixed stores in the same row */
}
```

The byte counter is bounded by four, so both products have the same value.
Using the unsigned row spelling throughout gave 688 bytes with 577 concrete
bytes different. Keeping the signed second product gave 688 bytes with only
12 different. A block-local slot pointer then fixed the inner register colours;
a u32 allocation-length local fixed the remaining schedule, producing EXACT.

In 021F3F00 the final loop keeps one row spilled across calls while separately
forming the branch-local actor address. The successful spelling retains a u32
offset but distinguishes integer addition from pointer addition:

```c
offset = 4 * i;
row = (u8 *)((u32)p + offset);
/* a branch below uses: */
actor = (u8 *)p + offset;
```

Spelling the first address as `(u8 *)p + offset` instead gave 452 bytes with
233 concrete bytes different. The integer row expression restored the original
464-byte function and original frame, leaving 20 different bytes confined to other
loop counters and their update order. Reusing the earlier counter in the second
loop and advancing the final mask before the index completed EXACT.

These are lifetime changes, rather than an operand-order swap at one add.
Keep the observed offsets and load/store widths; do not narrow an address or
invent an array bound. The related pointer-add operand-order and integer-return
address idioms describe different symptoms.
