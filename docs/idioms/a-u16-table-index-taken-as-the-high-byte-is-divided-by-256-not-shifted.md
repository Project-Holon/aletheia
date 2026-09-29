# A u16 table index taken as a value's high byte is divided by 256, not shifted

summary: when the original indexes a table with a u16 field's high byte
through `lsrs #8` followed by a kept `lsls #16 / lsrs #14` (truncate to u16,
scale by 4), write the index as `x / 256` stored to or cast to `u16`; `x >> 8`
promotes to int and gives `asrs`, and a `(u32)` cast lets mwcc drop the u16
truncation pair.

Found in: `src/matched/ov/ov021_func_02198550.c` (0x02198550),
`src/matched/ov/ov021_func_02199970.c` (0x02199970)

Both read one row of `d_021DDBD4` (a table of s32 rows) with the high byte
of a u16 angle field, after clamping that field to 0xF00:

```c
k = *(u16 *)(h + 10) / 256;            /* u16 k: 0x02198550 */
v.y = d_021DDBD4[i][k];

s = d_021DDBD4[1][(u16)(p->angle / 256)];   /* inline cast: 0x02199970 */
```

What the other spellings give, with the same surrounding C:

- `x >> 8`: the u16 is promoted to int first, so the shift is `asrs #8`.
- `(u32)x >> 8`: `lsrs #8`, but mwcc then knows the value fits in 8 bits and
  drops the `lsls #16 / lsrs #14` pair for a single `lsls #2`.
- `(u16)(x >> 8)` in 0x02198550: the inline cast is folded away as well;
  there only a `u16` local assigned from `x / 256` kept the pair. In
  0x02199970 the inline `(u16)(x / 256)` is enough.

In 0x02198550 the `u16 k` assignment also had to come before the `s8` row
index's, which fixed the register of the row-offset constant.
