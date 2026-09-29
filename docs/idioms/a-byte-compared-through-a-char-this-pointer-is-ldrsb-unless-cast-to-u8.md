# A byte compared through a `char *` object pointer is `ldrsb` unless read as `u8`

summary: with `-char signed`, `p[0x7f] != 0x30` on a `char *p` compiles to
`movs r0, #0x7f; ldrsb r0, [p, r0]` (there is no immediate-offset `ldrsb`);
the original's `adds r0, p, #0; adds r0, #0x7f; ldrb r0, [r0]` is
`*(u8 *)(p + 0x7f)`, and keeping `char *p` for the stores is fine.

Found in: `src/matched/ov/ov032_func_021F1B94.c`,
`src/matched/ov/ov032_func_021F1CF0.c` (task callbacks whose owner object is
passed around as `char *`, the ov032 house type).

Spelling:

```c
char *p = *(char **)(t + 0x1c);
if (*(u8 *)(p + 0x7f) != 0x30) {   /* ldrb via adds/adds */
    p[0x7f] = 0x30;                /* a store has no sign: plain p[] is fine */
    ...
```

Other spellings: `p[0x7f] != 0x30` (and `p[0x79] != 0`) gave `movs; ldrsb`
with the same instruction count, which shifts every following branch by the
one-instruction difference in the arm and turns a 348-byte function into a
full-body DIFF (or a SIZE of -2 bytes when the arm is the shorter one). The
tell in the original is the `adds rX, rP, #0; adds rX, #K; ldrb` triple for
a byte field past +31 in a compare, where a signed read would use a register
offset.
