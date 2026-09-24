# An integer table base makes Thumb multiply into a copy of the index

summary: when the image copies the index before `muls` (`adds r3, r2, #0;
muls r3, r0, r3`) and loads the table base after the constant, hold the base
as `u32 base = (u32)p->tbl` and address the row as `base + idx * N`; every
pointer spelling multiplies the index in place and loads the base first.

Found in: src/matched/func_02011688.c (0x02011688)

The image, after `idx %= n` (the remainder homed in the parameter's r2):

    movs r0, #0xc
    adds r3, r2, #0       ; copy of idx
    ldr  r1, [r5, #0x1c]  ; table base, after the 12
    muls r3, r0, r3
    ldr  r0, [r1, r3]     ; first field at base + off
    adds r1, r1, r3       ; cursor advanced in place for +4 / +8

Source that matches (dsi/1.1p1, Thumb):

    idx %= n;
    if (p->f18 == n) {
        u32 off = idx * 12;
        u32 base = (u32)p->f1c;
        dst->a = *(s32 *)(base + off);
        base += off;
        dst->b = *(s32 *)(base + 4);
        dst->c = *(s32 *)(base + 8);
        return 1;
    }
    return 0;

Wrong spellings measured (six waves): `&p->f1c[idx]`, `t[idx].a/b/c`, a
struct cursor, a `u8 *base` with the same byte offset (50 bytes, 25 out), an
`s32 *` cursor: the multiply lands in idx's own register and the base is
loaded before the 12 (25 to 26 out). The integer base without `idx %= n`
(a named `i = idx % n`) is 52/31: the remainder then coalesces with the
helper's r1 return. Both levers are needed together.

Tell: a `muls` whose destination is a fresh copy of a dying index, and a
base loaded between the constant and the multiply. Related:
docs/idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md (an
integer cast changing the colouring order of a base and its offset).
