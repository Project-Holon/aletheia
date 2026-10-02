# The index is added in each arm of a two-table select so the element pointer is formed once

summary: `e = (s ? base1 : base2) + i` lets the compiler fold the index into the
loads (`ldrh r0,[r2,r0]` plus a second sum for the byte loads); writing
`if (s) e = base1 + i; else e = base2 + i;` keeps one shared element pointer
(`adds r2,r2,r0; ldrh r0,[r2]; ldrb r1,[r2,#2]`).

Found in: src/matched/ov/ov093_func_021D55D8.c (0x021D55D8)

The image selects between the record arrays at +0x104 and +0x10a, multiplies
the index by 14, adds once, and reads a halfword and two bytes from the same
register. Every ternary spelling (`p + (s ? 0x104 : 0x10a)`, with the index added
after, in a helper, or as `e[i].a`) produced a second address register and a
register-offset `ldrh`. The `if/else` with `+ i` written in both arms matched.
