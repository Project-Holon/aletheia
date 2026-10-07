/*
 * file:     pdw_postman_p07.c
 * unit:     yes
 * function: func_021B7DE0, func_021B7E60, func_021B7ED4
 * address:  0x021B7DE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9278  0x021B9278  thumb ov021
 *   func_021B9280  0x021B9280  thumb ov021
 *   func_021B7CD8  0x021B7CD8  thumb
 *   func_021B7D38  0x021B7D38  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_021B7DE0;

typedef struct {
    u16 h0;
    u8 b2;
    u8 pad3;
    s16_021B7DE0 h4;
    u16 h6;
} Arg;

typedef struct {
    u16 h0;
    u16 h2;
    u8 pad4[0x10];
    u8 *x14;
} Tbl;

typedef struct {
    u8 pad[0x1C];
    void *x1c;
    u8 pad20[4];
    Tbl *x24;
} Obj;

typedef signed char    s8;

typedef signed short   s16_021B7E60;

typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;

typedef struct { u16 a, b, c, d; } Rect4;

struct Cam {
    u8 pad00[0x50];
    VecFx32 f50;
    Rect4 f5C;
    u8 pad64[8];
    Rect4 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

typedef struct {
    u32 w[3];
} Triple;

extern int func_021B9278(u8 *, void *, Tbl *);
extern int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
extern u8 func_021B7CD8(void *m, Rect4 *r, u8 key, Rect4 *out);
extern void func_021B7D38(void *m, Rect4 *r, VecFx32 *out);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
int func_021B7DE0(Obj *o, Arg *a);
u8 func_021B7E60(struct Cam *c, u8 key, Rect4 *out, VecFx32 *pos);
void func_021B7ED4(u8 *o, Triple *out);


int func_021B7DE0(Obj *o, Arg *a)
{
    Tbl *t;
    u8 *base;
    int off;
    int x;
    int y;
    int v;
    int w;
    int pad;

    if (a->b2 == 0) {
        if (a->h0 >= o->x24->h0) {
            return 0;
        }
    } else {
        t = o->x24;
        if (a->h0 >= t->h2) {
            return 0;
        }
        base = t->x14;
        off = a->h0 * 0x48;
        pad = 0;
        x = a->h6 << 4;
        y = a->h4 << 4;

        v = func_021B9278(base + (off + pad), o->x1c, t);
        w = func_021B9280(base + off, x, v, (u8 *)o->x24);
        if (-w > y || y > w) {
            return 0;
        }
        if (x > v || x < 0) {
            return 0;
        }
    }
    return 1;
}


u8 func_021B7E60(struct Cam *c, u8 key, Rect4 *out, VecFx32 *pos)
{
    if (c->f74 == 0 || key != c->f76) {
        c->f75 = func_021B7CD8(c->f78, &c->f5C, key, &c->f6C);
        func_021B7D38(c->f78, &c->f6C, &c->f50);
        c->f74 = 1;
        c->f76 = key;
    }
    if (out != 0)
        MI_CpuCopy8(&c->f6C, out, 8);
    if (pos != 0)
        *pos = c->f50;
    return c->f75;
}


void func_021B7ED4(u8 *o, Triple *out)
{
    *out = *(Triple *)(o + 0x44);
}
