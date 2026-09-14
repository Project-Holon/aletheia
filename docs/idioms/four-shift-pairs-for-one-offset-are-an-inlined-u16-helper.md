# Four `lsls #16` / `lsrs #16` pairs on one value are an inlined helper with a `u16` parameter and a `u16` return

summary: a `u16` local truncates once and a redundant `(u16)` cast on it folds
away, so a value that is truncated four times in twenty instructions cannot be
a `u16` variable at all; it is a `u32` passing through the argument, the
parameter, the return value and the result of a small `u16`-shaped helper the
compiler inlined, and reproducing it means writing `u32` locals with the cast
spelled out at each of the four points.

Found in: `src/matched/unit_0201D7C4.c` (0x0201D7C4), against the still open
func_0201D6D8 at 0x0201D736, whose state is recorded in that file's header

`func_0201D7C4` computes one ring offset and loads the word there. Thirty-eight
bytes, no calls, and four truncations:

```
0201D7C8  subs r1, r1, r2
0201D7CA  lsls r1, r1, #0x10
0201D7CC  lsrs r1, r1, #0x10      /* (1) */
0201D7CE  lsls r1, r1, #0x10
0201D7D0  lsrs r1, r1, #0x10      /* (2) */
0201D7D2  adds r1, #0x1c
0201D7D4  lsls r1, r1, #0x10
0201D7D6  lsrs r2, r1, #0x10      /* (3) */
0201D7D8  ldrh r1, [r0, #4]
0201D7DA  cmp  r2, r1
0201D7DC  blo  .ok
0201D7DE  movs r2, #0
.ok:
0201D7E0  lsls r1, r2, #0x10
0201D7E2  lsrs r1, r1, #0x10      /* (4) */
```

Pairs (1) and (2) are adjacent and identical, which is the part that does not
happen. Declaring the value `u16` gives one pair and a thirty-byte function;
writing `(u16)(u16)x` folds to one pair; assigning through two `u16` locals
folds to one pair. mwccarm removes a redundant truncation of a value it already
knows is sixteen bits wide, and it knows that for anything held in a `u16`
object.

What it does not fold is a cast applied to a `u32`. So

```c
u32 off = (u16)((u8 *)q - &p->buf[0]);   /* (1) */

off = (u16)((u16)off + 0x1C);            /* (2) and (3) */
if (off >= p->unk04) {
    off = 0;
}
return *(void **)&p->buf[(u16)off];      /* (4) */
```

is `EXACT`, and the shape it describes is an inlined call: (1) is the argument
converted to the parameter's type, (2) is the parameter re-narrowed on entry,
(3) is the helper's own arithmetic and (4) is the caller narrowing the return
value before using it as an index. A `static u16 next(struct PrintSys *, u16)`
compiled out of line and then inlined produces exactly those four points.

The corroboration is a hundred bytes away. `func_0201D6D8` computes the same
offset for a *store* rather than a load, and its copy has only **two** pairs,
because there the helper's body was written out rather than called: same
arithmetic, same constants, two truncations instead of four. A single source
helper used twice would have given the same count in both places, so the pair
count is a direct reading of which site wrote the arithmetic out and which one
called it.

The general rule: count the truncations. One is a `u16` object. Two on a `u32`
is one written cast. Four, in a function with no calls, is a call that is no
longer there.
