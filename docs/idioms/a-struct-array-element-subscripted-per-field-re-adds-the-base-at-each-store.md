# A struct-array element subscripted per field re-adds the base at each store; an element pointer caches it

summary: when the image recomputes `p + i*12` (or indexes one field from a
separate `p + off` base register, `ldrsh r0, [r6, r5]`) for each field of the
same array element, write every access as `p->ent[i].field`; an element
pointer (`Ent *e = &p->ent[i]` or a `u16 *q = (u8 *)p + i * 12` cursor)
computes the address once and loads every field off it at a fixed offset.

Found in: src/matched/ov/ov026_func_021EFC3C.c (0x021EFC3C),
src/matched/ov/ov026_func_021EF9D8.c (0x021EF9D8)

Both functions work on the same object: a header of bytes/halfwords at
+0..+7, then 12-byte entries from +8. The image, for the last entry that
func_021EFC3C fills:

    adds r5, r4, #0     ; i
    movs r0, #0xc
    muls r5, r0, r5     ; i * 12
    adds r4, r6, #0
    adds r4, #0xc       ; separate base p + 0xC for the first field
    ...
    strh r0, [r4, r5]   ; ent[i].c
    adds r2, r6, r5     ; p + i*12 again for .a / .b
    ...
    adds r1, r6, r5     ; and again for .d / .e / .f

Spelling it as `q = (u16 *)((u8 *)p + i * 12); q[6] = ...; q[4] = ...` (the
shape of the twin func_021EFBA4's loop) gives one `adds r4, r6, r0` and
every store at `[r4, #off]`: 62 bytes out at the same size range. Writing
`p->ent[i].c = ...; p->ent[i].a = ...; ...` with `Ent ent[4]` in the struct
is EXACT. In func_021EF9D8's state 4, `e = &p->ent[p->cur]; p->t3c = e->e;
...` was 100+ bytes out; `i = p->cur; p->t3c = p->ent[i].e; ...` closed the
case. The loop half of func_021EFC3C, which the compiler strength-reduces,
comes out the same either way.

Found alongside (func_021EF9D8, state 6): re-reading the index field into a
local right after a store through it (`p->ent[p->cur].d--; i = p->cur; if
(p->ent[i].d <= 0) { if (p->count > i + 1) p->cur = i + 1;`) swapped the
two registers that `p->cur` spelled throughout left in r0/r1 (7 bytes out;
the permuter was flat).
