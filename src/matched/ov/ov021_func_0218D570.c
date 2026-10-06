/*
 * function: func_0218D570
 * address:  0x0218D570
 * packet:   pkt_ov021_0218D570
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills the cell array for the two grid layers nearest the camera: the
 * layer containing cam->pos, then its neighbour on the side cam->pos leans
 * toward.  Each cell gets its table index (or -1 past the end) and its
 * centred position.  `size` is loaded into a local but FX_Div is passed the
 * field read, which keeps the hoisted sign-extension pair off size's slot
 * (see docs/idioms/an-unused-frame-word-under-a-sign-extension-spill-is-a-
 * field-passed-to-an-earlier-call.md).
 *
 * symbols:
 *   sub_0207C768   0x0207C768  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218DD80  0x0218DD80  thumb ov021
 *   func_0218DD9C  0x0218DD9C  thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int fx32;
typedef long long fx64;

typedef struct Cell {
    u32 id;
    int x;
    int y;
    int z;
} Cell;

typedef struct Cam {
    u32 f0;
    u32 pos;
} Cam;

typedef struct Obj {
    u16 heap;
    u8 pad02[2];
    fx32 size;
    fx32 height;
    u32 mode;
    u32 f10;
    u16 w;
    u16 h;
    u32 count;
} Obj;

extern u32 sub_0207C768(u32 a, u32 b);
extern void func_0218DD80(u8 *p, u32 v);
extern Cell *func_0218DD9C(Cell *c, fx32 x, fx32 y, fx32 z);

static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((fx64)a * b + 0x800) >> 12);
}

void func_0218D570(Obj *p, Cam *cam, Cell *cells)
{
    u32 layer;
    u32 total;
    fx32 height;
    fx32 half;
    fx32 y;
    fx32 size;
    u16 w;
    int row;
    int dir;
    int col;
    u32 rem;
    int i;
    u32 n;
    u32 id;

    w = p->w;
    total = w * p->h;
    size = p->size;
    half = (int)sub_0207C768((int)p->size, (int)0x2000);
    height = p->height;
    layer = (int)sub_0207C768((int)cam->pos, (int)height) >> 12;
    rem = cam->pos - layer * height;
    if (rem > height / 2)
        dir = 1;
    else
        dir = -1;

    n = 0;
    for (i = 0; i < total; i++, n++) {
        y = FX_MUL(layer << 12, height);
        col = i % p->w;
        row = i / p->w;
        id = layer * total + row * w + col;
        if (id >= p->count)
            id = -1;
        func_0218DD80((u8 *)(&cells[n]), id);
        func_0218DD9C(&cells[n], half + FX_MUL(col << 12, size), y, half + FX_MUL(row << 12, size));
    }
    for (i = 0; i < total; i++, n++) {
        y = FX_MUL((layer + dir) << 12, height);
        col = i % p->w;
        row = i / p->w;
        id = (layer + dir) * total + row * w + col;
        if (id >= p->count)
            id = -1;
        func_0218DD80((u8 *)(&cells[n]), id);
        func_0218DD9C(&cells[n], half + FX_MUL(col << 12, size), y, half + FX_MUL(row << 12, size));
    }
}
