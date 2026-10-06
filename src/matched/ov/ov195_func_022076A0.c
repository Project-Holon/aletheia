/*
 * function: func_022076A0
 * address:  0x022076A0
 * packet:   pkt_022076A0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02207868 0x02207868 thumb ov195
 *   func_022083DC 0x022083DC thumb ov195
 *   func_022083EC 0x022083EC thumb ov195
 *   func_02208420 0x02208420 thumb ov195
 *   func_0220851C 0x0220851C thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;
typedef s16 fx16;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct Cell {
    u32 f00;
    fx32 s0, s1, t0, t1;
    u8 visible;
    u8 pad15;
    fx16 v[4][3];
    u8 pad2e[0x68 - 0x2e];
    VecFx32 trans;
    u8 pad74[0x80 - 0x74];
} Cell;

typedef struct Row {
    Cell cell[0x12];
} Row;

typedef struct Grid {
    u8 pad00[0x28];
    int state;
    u8 pad2c[0x5a - 0x2c];
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    u8 pad62[0x68 - 0x62];
    fx32 f68;
    u8 pad6c[0x74 - 0x6c];
    Row row[0x12];
    u8 rows;
} Grid;

typedef struct Quad {
    u8 pad00[0x4e];
    u8 f4e;
} Quad;

typedef struct Work {
    u32 f00;
    u32 f04;
    Grid *cur;
    Grid *prev;
    Quad *quad;
} Work;

typedef struct Owner {
    u16 heap;
    u8 pad02[0x56];
    Work *work;
} Owner;

extern void func_02207868(char *p, u16 heap);
extern int func_022083DC(Grid *g, u16 heap);
struct Fade;
extern void func_022083EC(struct Fade *p, int x);
extern int func_02208420(char *p, u16 heap);
extern void func_0220851C(Quad *q, u16 heap);

void func_022076A0(Owner *o)
{
    Work *w = o->work;
    u16 heap = o->heap;
    Grid *s;
    Grid *d;
    u8 j;
    u8 i;
    s16 x;
    s16 y;
    int flag;

    if (w->f00 != 1)
        return;

    func_02207868((char *)w->cur, heap);
    s = w->cur;
    d = w->prev;
    d->f68 = s->f68;
    for (j = 0; j < 0x12; j++) {
        for (i = 0; i < 0x12; i++)
            d->row[j].cell[i].trans = s->row[j].cell[i].trans;
    }

    for (y = d->y0; y >= s->y0; y--) {
        if (y == d->y0)
            x = d->x0;
        else
            x = 17;
        for (; x >= 0; x--) {
            if (y == s->y0) {
                if (x <= s->x0)
                    break;
                flag = 1;
            } else {
                flag = 1;
            }
            if (flag)
                d->row[y].cell[x].visible = 31;
        }
    }
    d->x0 = s->x0;
    d->y0 = s->y0;

    for (y = d->y1; y <= s->y1; y++) {
        if (y == d->y1)
            x = d->x1;
        else
            x = 0;
        for (; x < 0x12; x++) {
            if (y == s->y1) {
                if (x >= s->x1)
                    break;
                flag = 1;
            } else {
                flag = 1;
            }
            if (flag)
                d->row[y].cell[x].visible = 31;
        }
    }
    d->x1 = s->x1;
    d->y1 = s->y1;
    d->rows = s->rows;

    s = w->cur;
    d = w->prev;
    d->state = s->state;
    if (func_022083DC(s, heap)) {
        func_022083EC((struct Fade *)s, heap);
        func_022083EC((struct Fade *)d, heap);
    }
    func_02208420((char *)s, heap);
    if (w->quad != 0) {
        w->quad->f4e = w->cur->rows;
        func_0220851C(w->quad, heap);
    }
}
