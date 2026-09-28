# A flag argument written as a ternary statement into a local keeps the other argument loads in source order

summary: mwcc evaluates a `field != 0` call argument before its simpler siblings, and copy-propagates a plain `flag = field != 0;` local straight back into the call. When the image loads the arguments left to right with the flag's branch in the middle, the flag is a ternary statement (`sh = field != 0 ? 1 : 0;`) into a local, with the earlier argument also in a local.

Found in: src/matched/ov208_func_021C6E98.c (0x021C6E98)

The image, for a call `f(obj, id, forms, shiny != 0, species)`:

```
ldrb r2, [r1, r3]        ; forms first
adds r3, r3, #1
ldrb r1, [r1, r3]        ; then the flag
movs r3, #1
cmp  r1, #0
bne  1f
movs r3, #0
1:  ... ldrh species     ; last
```

Writing the call directly puts the flag's compare first, then the species
load, then the forms load. Moving the three into `f = ...; sh = ... != 0;`
statements changes nothing (all three are propagated back). Only the ternary
statement form stops the propagation of the flag, which also pins the forms
load ahead of it:

```c
f = *(p + H(0x54e) * 16 + 0x152);
sh = *(p + H(0x54e) * 16 + 0x153) != 0 ? 1 : 0;
func_0200CA98(obj, id, f, sh, *(u16 *)(p + H(0x54e) * 16 + 0x154));
```

The same function needed the entry fields as byte-pointer arithmetic rather
than a struct array: the image keeps `sel * 16` in a register but rebuilds
`p + sel * 16` for the species load, which a `p->ents[sel]` access (one
common base) does not reproduce.
