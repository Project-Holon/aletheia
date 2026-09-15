# `mvn` of zero feeding a `mul` is a multiply by `0xffffffff`, not by `-1`

summary: mwccarm strength-reduces `x * -1` to a single `rsb x, x, #0`, so a
live `mvn r0, #0` followed by a real `mul` means the source multiplied by the
*unsigned* constant `0xffffffff`; the two are arithmetically identical and
compile to different code.

Found in: `src/matched/unit_0204E720.c` (0x0204E720)

## The shape

At the sign flip near the end of 0x0204E720:

```
cmp   r1, r0
ldrgt r1, [r2, #0x18]
mvngt r0, #0                  ; materialise 0xffffffff
mulgt r0, r1, r0              ; and actually multiply by it
strgt r0, [r2, #0x18]
```

Three instructions where a negation would be one. The obvious C,

```c
if (p->unk04 > p->unk0c)
    p->unk18 = p->unk18 * -1;
```

produces exactly that one instruction instead, and nothing else in the function
changes:

```
ldrgt r0, [r2, #0x18]
rsbgt r0, r0, #0
```

## What produces the original

```c
if (p->unk04 > p->unk0c)
    p->unk18 = p->unk18 * 0xffffffff;
```

with `unk18` declared `s32`. The usual arithmetic conversions promote the
signed field to `unsigned int` for the multiply and the result converts back on
assignment, so the value is the same `-x` in every case; but the constant is
now `4294967295`, which is not a value the strength reducer has a rule for. It
materialises it (`mvn r0, #0` is the cheapest encoding of `0xffffffff`) and
emits the multiply.

`p->unk18 *= -1` and `-p->unk18` both fold to the `rsb` as well, so the
compound form is not the lever either. The only spelling that survives is the
unsigned constant.

## The tell, stated generally

A materialised constant feeding a `mul` whose value has an obvious cheap
equivalent (`-1`, a power of two, `0`) is a *type* statement about the source
constant, not a missed optimisation: the reducer's rules are keyed on the
constant's type as written, and an `unsigned` spelling of the same bit pattern
walks straight past them. Read `mvn rX, #0` before a `mul` as "the source says
`0xffffffff`", the same way a pooled small integer is read as a relocation
rather than a literal.
