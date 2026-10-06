/*
 * file:     clact_p04.c
 * unit:     yes
 * function: func_0204C214, func_0204C2C8, func_0204C3CC
 * address:  0x0204C214
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   tbl_020A17D8   0x020A17D8  data
 *   tbl_020A17F0   0x020A17F0  data
 *   func_0204C3CC  0x0204C3CC  arm
 */
struct C;
struct M;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_0204C214;

typedef int            s32_0204C214;

struct A { u16 f00; u16 f02; u16 f04; u16 f06; s16_0204C214 f08; s16_0204C214 f0a; s16_0204C214 f0c; s16_0204C214 f0e; };

struct B { u8 pad_00[0x10]; s32_0204C214 f10; s32_0204C214 f14; };

struct C { s32_0204C214 f00; s32_0204C214 f04; s32_0204C214 f08; s32_0204C214 f0c; };

typedef signed short s16_0204C2C8;

typedef signed int s32_0204C2C8;

typedef union {
    u32 attr01;
    struct {
        u32 y : 8;
        u32 rsMode : 2;
        u32 objMode : 2;
        u32 mosaic : 1;
        u32 colorMode : 1;
        u32 shape : 2;
        u32 x : 9;
        u32 rsParam : 5;
        u32 size : 2;
    };
} OamAttr;

struct Elem {
    u8 pad_00[0x30];
    u32 visible;
    u8 pad_34[4];
    OamAttr oam;
};

struct Pair {
    s32_0204C2C8 x;
    s32_0204C2C8 y;
};

struct Box {
    u8 pad[0x10];
    s32_0204C2C8 f10;
    s32_0204C2C8 f14;
};

typedef int s32_0204C3CC;

typedef long long s64;

struct M { s32_0204C3CC f00; s32_0204C3CC f04; s32_0204C3CC f08; s32_0204C3CC f0c; s32_0204C3CC f10; s32_0204C3CC f14; };

extern int func_0204C3CC(s32_0204C2C8 dx, s32_0204C2C8 dy, s32_0204C2C8 x0, s32_0204C2C8 x1, s32_0204C2C8 y0, s32_0204C2C8 y1, const struct M *m, const struct C *c);
extern const u16 tbl_020A17D8[4][4];
extern const u16 tbl_020A17F0[4][4];


/*
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
int func_0204C214(struct A *a, struct B *b, struct C *c)
{
    u16 w = a->f02;
    s32_0204C214 m6 = (s32_0204C214)(u8)(w & 0x3f);
    s32_0204C214 v = (m6 << 2) & 0xff;
    s32_0204C214 dy = b->f10 - c->f00;
    s32_0204C214 dx = b->f14 - c->f04;
    s32_0204C214 x0, y0, x1, y1;
    s32_0204C214 ax, ay, bx, by;

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


static inline s32_0204C2C8 RepeatX(s16_0204C2C8 x)
{
    if (x > 0xff)
        x |= ~0xff;
    return x;
}


static inline s32_0204C2C8 RepeatY(s16_0204C2C8 y)
{
    if (y > 0x7f)
        y |= ~0xff;
    return y;
}

static inline u16 SizeX(s32_0204C2C8 shape)
{
    return tbl_020A17F0[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}


static inline u16 SizeY(s32_0204C2C8 shape)
{
    return tbl_020A17D8[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}


/*
 * The OAM cull callback func_0204BE38 installs at element +0x40: read the
 * element's GXOamAttr attr01 word (+0x38), wrap x (9 bits) and y (8 bits),
 * size the object from the OBJ width/height tables indexed [shape][size],
 * and store func_0204C3CC's verdict into the element's visible flag (+0x30).
 * box is the 2x2 matrix plus translation (f10/f14), p the viewport.
 *
 * Lever (wave 16, declaration facts): the two OBJ size tables are
 * read-only data and are declared `const`.  Without const every register
 * name of the second half shuffled (58 bytes, flat under 120 declaration
 * orders, 80 index casts and two anneals); with it, EXACT.  const on the
 * p parameter is wrong (264 bytes); const on box and on the callee's
 * pointer parameters is neutral.
 */
void func_0204C2C8(struct Elem *e, struct Pair *p, s32_0204C2C8 u2, s32_0204C2C8 u3, struct Box *box)
{
    s32_0204C2C8 shape = e->oam.attr01 & 0xC000C000;
    s32_0204C2C8 x0 = RepeatX(e->oam.x) << 12;
    s32_0204C2C8 x1 = (RepeatX(e->oam.x) + SizeX(shape)) << 12;
    s32_0204C2C8 y0 = RepeatY(e->oam.y) << 12;
    s32_0204C2C8 y1 = (RepeatY(e->oam.y) + SizeY(shape)) << 12;

    e->visible = func_0204C3CC(box->f10 - p->x, box->f14 - p->y,
                               x0, x1, y0, y1, (const struct M *)box, (const struct C *)p) != 0;
}


#define fxmul(a, b) ((s32_0204C3CC)((((s64)(a) * (s64)(b)) + 0x800) >> 12))


/*
 * The 2x2-matrix cull test behind func_0204C2C8 (its only caller): transform
 * the four corners (x0,y0) (x0,y1) (x1,y0) (x1,y1) of an OAM rectangle through
 * the matrix m (20.12, rounded +0x800), take min/max per axis, translate by the
 * camera delta (dx, dy) and test against the viewport c->f08 / c->f0c.  Eight
 * arguments: dx, dy, x0, x1 in r0-r3; y0, y1, m, c on the stack.
 *
 * Levers, all measured (wave 10):
 *  - the four translated bounds are added EAGERLY as statements
 *    (`minx += dx; maxx += dx; miny += dy; maxy += dy;`) before the `&&`
 *    chain, same lever as func_0204C214; inline in the chain: 41-66 out.
 *  - declaration order `maxx, minx, maxy, miny` and the seed order
 *    `min = p; max = p;` put the minimum in p's register and the maximum in
 *    the copy (r4/lr, sb/r7), as the image has it; any other order swaps the
 *    pair (25-37 out).  Found by tools/permuter.py (decl-order + reorder),
 *    then closed by sweeping all 240 decl/seed orders.
 *  - the umull/mla (not smull) products from the second use of each
 *    coordinate on are the CSE'd `(s64)` sign halves, not a different macro.
 */
int func_0204C3CC(s32_0204C3CC dx, s32_0204C3CC dy, s32_0204C3CC x0, s32_0204C3CC x1, s32_0204C3CC y0, s32_0204C3CC y1,
                  const struct M *m, const struct C *c)
{
    s32_0204C3CC maxx, minx, maxy, miny;
    s32_0204C3CC p;

    p = fxmul(x0, m->f00) + fxmul(y0, m->f08);
    minx = p;
    maxx = p;
    p = fxmul(x0, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y0, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;

    p = fxmul(x0, m->f04) + fxmul(y0, m->f0c);
    miny = p;
    maxy = p;
    p = fxmul(x0, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y0, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;

    minx += dx; maxx += dx; miny += dy; maxy += dy;
    if (maxy > 0 && miny < c->f0c && maxx > 0 && minx < c->f08)
        return 1;
    return 0;
}
