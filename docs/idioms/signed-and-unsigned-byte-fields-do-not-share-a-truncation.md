# A signed byte field and an unsigned byte local do not share one truncation

summary: when a function both stores a wider value into a byte field and keeps
its own `u8` copy of the same value, the field's signedness decides whether the
compiler computes `(u8)x` once and reuses it for the `strb`, or emits the plain
`strb` and recomputes the truncation later; an `s8` field breaks the CSE.

Found in: `src/matched/sub_0202CB4C.c` (0x0202CB4C, 268 bytes)

The original opens with two plain byte stores straight out of the argument
registers, and only much later, after four guards, materialises the same low
byte again:

```
0202CB5C  strb r0, [r4, #6]        ; win->x = x
0202CB5E  strb r3, [r4, #7]        ; win->y = y
...
0202CB98  lsls r5, r0, #0x18       ; sx = x        (sx is u8)
0202CB9A  lsrs r5, r5, #0x18
0202CB9C  str  r5, [sp, #0x30]
```

Declaring the field as `u8 x;` makes `win->x = x` and `sx = x` the *same*
conversion node, `(u8)x`. mwcc then computes it once, at the earliest of the
two points, and feeds the truncated register to the store:

```
  * +0010    strb r0, [r4, #6]        | lsls r1, r0, #0x18
  * +0012    strb r3, [r4, #7]        | lsrs r1, r1, #0x18
  * +0014    movs r1, #0xd            | str  r1, [sp, #0x2c]
  * +0016    ldrsb r1, [r4, r1]       | strb r1, [r4, #6]
```

That single hoist knocks every later register and spill slot out of place: the
verdict was 212 of 268 bytes wrong. Changing nothing but `u8 x, y` to
`s8 x, y` in the struct took it to 24 bytes wrong, all of them stack-slot
numbering.

## The tell

A `strb` that sources an argument register directly, with the *same* value
truncated by an explicit `lsls`/`lsrs` pair somewhere later in the same
function. If the field were unsigned there would be only one truncation in the
function and the store would consume it.

The reverse reading also holds: a leading `lsls`/`lsrs` pair feeding a `strb`
says the field and the local agree in signedness.

## Why

The conversion to a signed char and the conversion to an unsigned char are
distinct nodes in mwcc's expression tree even though the resulting low byte is
identical, so the common-subexpression pass never considers merging them. It is
a structural comparison, not a value one.

## Rule

When a byte field is written from a wider parameter and the same parameter is
also kept in a `u8` local, read the position of the truncation before choosing
the field's signedness. Truncation adjacent to the store means both are
unsigned; a bare `strb` with the truncation recomputed later means the field is
`s8`. Here `s8` was independently plausible anyway, since the four clip bounds
the coordinates are compared against at +0xc..+0xf are all `ldrsb`.
