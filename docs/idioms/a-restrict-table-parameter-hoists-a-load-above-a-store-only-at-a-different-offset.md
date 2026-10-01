# A restrict table parameter hoists a load above a store only at a different offset

summary: a block that stores `pos.x = e[A]; pos.y = e[B];` (u8 loads, s16
stores into a stack struct) normally compiles in source order, `ldrb; strh;
ldrb; strh`, because a char load may alias the store. When the original shows
`ldrb x; ldrb y; strh x; strh y` in some arms and the plain order in others,
qualify the table parameter `e` comes from with `__restrict`. mwcc then hoists
the second load above the first store only when the load offset differs from
the store offset (e[1] vs pos.x at 0), and keeps the source order when they
are equal (e[0] vs pos.x). Use `__restrict`, not `restrict`, so the file also
compiles without `--lang c99`. A `restrict` on a local pointer has no effect;
only the parameter qualifier does.

Found in: `src/matched/ov/ov094_func_022064CC.c` (0x022064CC, ov094)

The six-arm switch sets `pos` from `tab[k]`. Arms 0 and 1 read `e[0]` for y
and stay unscheduled; arms 2 to 5 read `e[1]` and come out as

```
ldrb r1, [r0, #3]
ldrb r0, [r0, #1]
strh r1, [r5]
strh r0, [r5, #2]
```

Temporaries (`a = e[3]; b = e[1]; pos.x = a; pos.y = b;`) also schedule the
loads first, but mwcc then emits the loads in reverse store order, so the
register pairing and cross-jumped tails differ. With
`u8 (* __restrict tab)[4]` the whole function is EXACT.
