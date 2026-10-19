# A pool constant kept live past a join is used in each arm

summary: mwcc shares a pool constant only where the first load dominates without a join. Write the
using statement in each arm of the if/else so both arms keep the first pool register.


Seen in wave D6 lane 16 (2026-10-05): ov198 func_0220ED54 (closed EXACT).

## Symptom

The image loads a large offset from the pool once (`ldr r4,=0x1ED8`) and derives
other offsets from that register (`adds r1,r4,#0; subs r1,#0x1c`) across calls and
also after an if/else (`subs r4,#0x1c; ldr r0,[r0,r4]`). The build loads the pool
word again after the join, and later folds other pool words onto that new register
(`adds r6,#0x9c`).

## Source fact

mwcc shares a pool constant only inside the region that the first load dominates
without a join. A use after an if/else join gets a new pool load. Write the
statement that uses the constant in EACH arm. Both arms then keep the first pool
register, and tail merging builds the one shared block of the image.

    if (flag == 0) {
        idx = k + 0x22;
        f(*(u8 **)(p + idx * 4 + 0x1ebc), &d);
    } else {
        idx = k + 0x1d;
        f(*(u8 **)(p + idx * 4 + 0x1ebc), &d);
    }

## Related

ov225 func_021BB854 closed in the same lane with the existing idiom
a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md.
