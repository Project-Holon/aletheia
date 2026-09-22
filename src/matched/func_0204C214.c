/*
 * function: func_0204C214
 * address:  0x0204C214
 * packet:   pkt_0204C214
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The axis-aligned sibling of func_0204C060 (clact.c): take the sprite's four
 * half-extents in 20.12 fixed point, translate by the camera delta and cull
 * against the viewport.  Where func_0204C060 runs the extents through a 2x2
 * matrix, this one adds the deltas straight to them.  No relocations.
 *
 * Four levers, all measured against the image (docs/notes/pkt_0204C060.c.txt
 * had this row at 37-148 bytes out before the second pass):
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields).
 *    That only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dy` is declared before `dx` (the image's first `sub` is
 *    `b->f10 - c->f00`); swapping them costs 8 bytes.
 *  - The four sums must be computed as named locals in the order
 *    ay, ax, bx, by BEFORE the `&&` chain; computing them inside the chain
 *    makes the compiler interleave the adds with the branches (115 out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(w & 0x3f)` then `(m6 << 2) & 0xff`, exactly as
 *    func_0204C060 documents.  Every spelling that masks first and narrows
 *    the SHIFTED value -- `(u8)((w & 0x3f) << 2)`, `((w & 0x3f) << 2) & 0xff`,
 *    the u32 and the `* 4` forms -- lets 1.1p1 prove the field contiguous and
 *    fuse it into `lsl #26` + `lsr #24`, where the image keeps
 *    `and #0x3f` + `lsl #2` + `and #0xff`.  This was the final 6-byte residue;
 *    tools/permuter.py exhausted 261 single mutations on it without moving it,
 *    which is the "residue is in the reading, not the allocation" signature.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0204C214.c \
 *       --func func_0204C214 --addr 0x0204C214 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

struct A { u16 f00; u16 f02; u16 f04; u16 f06; s16 f08; s16 f0a; s16 f0c; s16 f0e; };
struct B { u8 pad_00[0x10]; s32 f10; s32 f14; };
struct C { s32 f00; s32 f04; s32 f08; s32 f0c; };

int func_0204C214(struct A *a, struct B *b, struct C *c)
{
    u16 w = a->f02;
    s32 m6 = (s32)(u8)(w & 0x3f);
    s32 v = (m6 << 2) & 0xff;
    s32 dy = b->f10 - c->f00;
    s32 dx = b->f14 - c->f04;
    s32 x0, y0, x1, y1;
    s32 ax, ay, bx, by;

    if (((w >> 11) & 1) == 1) {
        x0 = a->f0e << 12;
        y0 = a->f0a << 12;
        x1 = a->f0c << 12;
        y1 = a->f08 << 12;
    } else {
        x0 = -v << 12;
        y0 = v << 12;
        x1 = -v << 12;
        y1 = v << 12;
    }
    ay = y0 + dx;
    ax = x0 + dx;
    bx = x1 + dy;
    by = y1 + dy;
    return ay > 0 && ax < c->f0c && by > 0 && bx < c->f08;
}
