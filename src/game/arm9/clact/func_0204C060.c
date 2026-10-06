/*
 * function: func_0204C060
 * address:  0x0204C060
 * packet:   pkt_0204C060
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 2x2-matrix sibling of func_0204C214 (see docs/notes/pkt_0204C060.c.txt):
 * transform the sprite's four half-extents through the caller's 2x2 matrix in
 * 20.12 fixed point, translate by the camera delta, take the min/max of each
 * axis and cull against the viewport.
 *
 * Three levers, all measured, that this note's sibling row asked for:
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields),
 *    which only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dx` must be computed beside `dy`, before the `if`, not after it: with
 *    `dx` after the branch the whole 64-bit block reallocates (295 bytes out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(f & 0x3f)` then `(m6 << 2) & 0xff`. Every spelling that masks
 *    first and narrows the SHIFTED value -- `((f & 0x3f) << 2) & 0xff`,
 *    `(u8)((f & 0x3f) << 2)`, the u32 and the `* 4` forms -- lets 1.1p1 prove
 *    the field contiguous and fuse it into `lsl #26` + `lsr #24`, where the
 *    image keeps `and #0x3f` + `lsl #2` + `and #0xff`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C060.c \
 *       --func func_0204C060 --addr 0x0204C060 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;
typedef long long      s64;

struct A { u16 f00; u16 f02; u16 f04; u16 f06; s16 f08; s16 f0a; s16 f0c; s16 f0e; };
struct M { s32 f00; s32 f04; s32 f08; s32 f0c; s32 f10; s32 f14; };
struct C { s32 f00; s32 f04; s32 f08; s32 f0c; };

#define fxmul(a, b) ((s32)((((s64)(a) * (s64)(b)) + 0x800) >> 12))

int func_0204C060(struct A *a, struct M *m, struct C *c)
{
    u16 f = a->f02;
    s32 m6 = (s32)(u8)(f & 0x3f);
    s32 e = (m6 << 2) & 0xff;
    s32 dy = m->f10 - c->f00;
    s32 dx = m->f14 - c->f04;
    s32 v0, v1, v2, v3;
    s32 b04, b0c, b08, b00;
    s32 p0, p1, p2, p3;
    s32 t;

    if (((f >> 11) & 1) == 1) {
        v0 = a->f0e << 12;
        v1 = a->f0a << 12;
        v2 = a->f0c << 12;
        v3 = a->f08 << 12;
    } else {
        v1 = e << 12;
        v0 = (-e) << 12;
        v2 = v0;
        v3 = v1;
    }
    b04 = m->f04;
    b0c = m->f0c;
    b08 = m->f08;
    b00 = m->f00;

    p0 = dx + (fxmul(v0, b04) + fxmul(v0, b0c));
    p1 = dx + (fxmul(v1, b04) + fxmul(v1, b0c));
    p2 = dy + (fxmul(v2, b00) + fxmul(v2, b08));
    p3 = dy + (fxmul(v3, b00) + fxmul(v3, b08));

    t = p1;
    if (p1 < p0) {
        t = p0;
        p0 = p1;
    }
    if (p3 < p2) {
        s32 u = p3;
        p3 = p2;
        p2 = u;
    }
    if (t > 0 && p0 < c->f0c && p3 > 0 && p2 < c->f08)
        return 1;
    return 0;
}
