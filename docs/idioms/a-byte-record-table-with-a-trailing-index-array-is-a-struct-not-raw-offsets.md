# A table of 3-byte records followed by an index array is a struct, not `u8 *` plus offsets

summary: `a[b*3+2]` and `a[0x12+v]` on a `u8 *` compile to a shifted-add plus a
register-offset `ldrb`/`strb`; the original's `adds r2, r0, r2; ldrb r2,[r2,#2]` and
`adds r0, r0, v; strb r1,[r0,#0x12]` come from `struct { Rec r[6]; u8 idx[6]; } *`
with `a->r[b].c` and `a->idx[v]`.

Found in: src/matched/ov/ov095_func_0689D544.c, ov095_func_0689D448.c,
ov095_func_0689D258.c (0x0689D544, 0x0689D448, 0x0689D258)

The raw-offset spelling gave the right instruction count but folded the `#2`
and `#0x12` into an extra `adds r2, #2` / `adds r2, #0x12` and used a register
offset (`ldrb r2,[r0,r2]`), four to eight bytes of diff per function.  With
`Rec { u8 a, b, c; }` (3 bytes, no padding) and `T { Rec r[6]; u8 idx[6]; }`
(the index array at 0x12) all three come out EXACT*.  A swap of two records is
plain struct assignment through a `Rec` temporary (ov095_func_0689D4F0.c).
