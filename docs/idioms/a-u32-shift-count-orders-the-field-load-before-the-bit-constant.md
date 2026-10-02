# A u32 shift count orders the field load before the bit constant

summary: in `p->f & (1 << i)` with a `u8` counter `i`, mwcc evaluates the
shift first, so the `movs rX, #1` is live across the field load. When the
field's offset is a spilled loop invariant, that pushes the reload into r1 and
the scheduler slots `movs r0, #1` between the two loads. Writing the count as
`1 << (u32)i` makes the load come first: the reload takes r0 and `movs r0, #1`
follows the `ldrb`.

Found in: src/matched/ov/ov021_func_021CD6D0.c (0x021CD6D0), case 10.

Original:

```
ldr  r0, [sp]          /* spilled 0x578 offset */
ldrb r1, [r4, r0]
movs r0, #1
lsls r0, r5
tst  r1, r0
```

With `p->x578 & (1 << i)` the build had `ldr r1, [sp]; movs r0, #1;
ldrb r1, [r4, r1]` and was 5 bytes off. Changes that had no effect: operand
order, `!= 0`, casts on the field (`(int)`, `(u32)`, `(u16)`, `(u8)`), raw
offset spellings, a named bit local (also when assigned inside the condition),
and an inline helper with `u8` or `int` parameters. The fix is `(u32)` on the
count, either as a cast or as a `u32` parameter of an inline helper. A `u32`
on the field operand alone has no effect.

How to spot it: a bit test in which the image's reload of a spilled offset
uses r0 and the bit constant comes after the load, while your build puts the
constant between the reload and the load.
