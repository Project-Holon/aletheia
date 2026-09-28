# ldrb on a DWARF `char` means the object was built with plain char unsigned

summary: the house base flags carry `-char signed`, so a field or table the vendor DWARF
types as plain `char` compiles to `ldrsb` loads and `mvn` for a constant like 0x80; when
the original loads it with `ldrb` and stores 0x80 with `mov`, the vendor built that object
with char unsigned, and the field is written `unsigned char` in the C.

Found in: src/matched/ov016_func_021BE618.c (0x021BE618, key in keyboard.o); also touch,
touchRelease

keyboard.o's MEMKB.input, KEY_OUT (`char *[3]`), SKEY_OUT and BTN_OUT are `char` in the DWARF.
With `char` the draft of key differs in exactly three loads (`ldrsb r1, [r1, r4]` for the
original's `ldrb`), and touch stores `MemKb->input = 0x80` as `mvn r0, #0x7f`. Declaring the
four as `unsigned char` closes both. The same object spells its genuinely signed members
`signed char` (push, touchLast, focusLast, focus), which is the other half of the tell: a
vendor that writes `signed char` explicitly is compiling with an unsigned default.
