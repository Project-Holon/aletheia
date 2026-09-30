# A halfword bit clear needs a spelled-out assignment for bics

summary: `p->flags = p->flags & ~8` emits `movs #8; bics`, while `p->flags &= ~8` narrows the mask and emits a pooled `0xFFF7` and `ands`.

Found in: src/matched/ov/ov112_func_021F4C94.c and src/matched/ov/ov112_func_021F4D74.c.

Both functions clear bits of a u16 flags field. The original loads the halfword, loads the positive mask with movs, clears it with bics, and stores the halfword. A compound assignment narrows the complement to sixteen bits and costs a pool word; writing the assignment out leaves the complement at int width, so the compiler uses bics. In 4C94 the compound form compiled 176 bytes rather than 172. In 4D74 it added two pool words for masks 8 and 16; the explicit forms matched EXACT in both functions.
