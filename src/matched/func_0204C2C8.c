/*
 * function: func_0204C2C8
 * address:  0x0204C2C8
 * packet:   pkt_0204C2C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   tbl_020A17D8   0x020A17D8  data
 *   tbl_020A17F0   0x020A17F0  data
 *   func_0204C3CC  0x0204C3CC  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

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
    s32 x;
    s32 y;
};

struct Box {
    u8 pad[0x10];
    s32 f10;
    s32 f14;
};

extern const u16 tbl_020A17D8[4][4];
extern const u16 tbl_020A17F0[4][4];

extern int func_0204C3CC(s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1,
                         struct Box *box, struct Pair *p);

static inline s32 RepeatX(s16 x)
{
    if (x > 0xff)
        x |= ~0xff;
    return x;
}

static inline s32 RepeatY(s16 y)
{
    if (y > 0x7f)
        y |= ~0xff;
    return y;
}
static inline u16 SizeX(s32 shape)
{
    return tbl_020A17F0[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}

static inline u16 SizeY(s32 shape)
{
    return tbl_020A17D8[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}

void func_0204C2C8(struct Elem *e, struct Pair *p, s32 u2, s32 u3, struct Box *box)
{
    s32 shape = e->oam.attr01 & 0xC000C000;
    s32 x0 = RepeatX(e->oam.x) << 12;
    s32 x1 = (RepeatX(e->oam.x) + SizeX(shape)) << 12;
    s32 y0 = RepeatY(e->oam.y) << 12;
    s32 y1 = (RepeatY(e->oam.y) + SizeY(shape)) << 12;

    e->visible = func_0204C3CC(box->f10 - p->x, box->f14 - p->y,
                               x0, x1, y0, y1, box, p) != 0;
}

