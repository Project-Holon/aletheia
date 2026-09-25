# A multi-bit field clear at a nonzero bit offset needs the padding fields declared

summary: a three-bit field clear at bit 3 of a byte emits `movs r1,#0x38; bics`
only when the source is a bitfield assignment; the equivalent `p[0x4210] &= ~0x38`
folds the mask to `0xC7` and emits `ands`, and the container's low padding bits
must be a declared field to land the field on bit 3.

Found in: src/matched/func_021855C8.c (0x021855C8), func_021855EC.c (0x021855EC),
func_02185670.c (0x02185670)

The original clears bits 3..5 of a byte at a large base offset:

```
ldrb r3, [r0, r2]
movs r1, #0x38
bics r3, r1
strb r3, [r0, r2]
```

`unsigned char *p; p[0x4210] &= ~0x38;` folds the complement into a 32-bit mask
and emits `movs r1, #0xc7; ands r1, r3`, which is the same value but two bytes
different and in the other register. The fix is a bitfield assignment, and the
container must place the field on bit 3 by declaring the bits below it:

```c
struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};
((struct bf4210 *)(p + 0x4210))->b = 0;
```

That reproduces the `bics` form. This is the multi-bit sibling of
`a-one-bit-field-clear-is-bics-with-movs-one-not-ands.md`: the mask width does
not matter, but the field's bit position must be modelled by the fields before
it, or the compiler cannot know the clear is a field clear.
