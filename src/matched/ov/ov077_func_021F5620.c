/*
 * function: func_021F5620
 * address:  0x021F5620
 * packet:   pkt_ov077_021F5620
 * region:   ov077
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the ov077 task (callback func_021F5744) and lays out a grid of
 * 0x40-byte cells in a 0x307C-byte work block: 0x20/w columns by 0x18/h
 * rows, each cell's x/y in fx32 centred on the grid.  Same shape as ov076's
 * func_021F52D8 (fade plane 0xC or 3 from the flag).
 *
 * Levers: p->w / p->h read into locals first (the divide reuses r1);
 * `(cols / 2) * a8` in the centring offsets reloads the spilled a8/b8 per
 * use (4 bytes short with `a8 * (cols / 2)`); the column and row read into
 * named locals give the rem copy into r2 and the in-place row multiply.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F5744  0x021F5744  thumb  ov077
 */
typedef unsigned char  u8;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Cell {
    s32 x;
    s32 y;
    s32 f8;
    u8 padC[0xC];
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0x10];
    s32 f34;
    s32 f38;
    u32 f3C;
} Cell;

typedef struct Work {
    Cell cell[0xC0];
    u8 pad3000[8];
    s16 cols;
    s16 rows;
    u8 pad300C[0x64];
    u32 f3070;
    u32 f3074;
    u32 f3078;
} Work;

typedef struct Param {
    int w;
    int h;
    void (*cb)(Work *w);
    u32 fC;
    u32 f10;
} Param;

struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 *func_021CF52C(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F5744(void *task, int *st);

void *func_021F5620(void *task, const Param *p, int flag)
{
    Work *w;
    void *h;
    int i;
    int a;
    int b;
    int cols;
    int rows;
    int a8;
    int b8;
    int ox;
    int oy;
    int n;
    int col;
    int row;

    w =(Work *)func_021CF52C((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(task))), sizeof(Work), 0x50);
    h = func_020122C0(task, 0, func_021F5744, 0);
    a = p->w;
    b = p->h;
    a8 = a * 8;
    b8 = b * 8;
    cols = 0x20 / a;
    rows = 0x18 / b;
    w->cols = cols;
    w->rows = rows;
    ox = (cols / 2) * a8 - a8 / 2;
    oy = (rows / 2) * b8 - b8 / 2;
    n = cols * rows;
    for (i = 0; i < n; i++) {
        col = i % cols;
        w->cell[i].x = (col * a8 - ox) << 12;
        row = i / cols;
        w->cell[i].y = (oy - row * b8) << 12;
        w->cell[i].f8 = 0;
        w->cell[i].f18 = 0;
        w->cell[i].f1C = 0;
        w->cell[i].f20 = 0;
        w->cell[i].f34 = 0;
        w->cell[i].f38 = 0;
        w->cell[i].f3C = p->f10;
    }
    w->f3070 = p->fC;
    if (p->cb != 0) {
        p->cb(w);
    }
    if (flag != 0) {
        w->f3074 = 0xC;
        w->f3078 = 0x7FFF;
    } else {
        w->f3074 = 3;
        w->f3078 = 0;
    }
    return h;
}
