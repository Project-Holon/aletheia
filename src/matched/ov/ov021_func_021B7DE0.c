/*
 * function: func_021B7DE0
 * address:  0x021B7DE0
 * packet:   pkt_ov021_021B7DE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three things together give the early multiply, the spilled offset and
 * the `adds r0,r3,#0` copy: func_021B9278 takes the table as a third
 * argument (as in func_021B7EE4), base is assigned before off, and the
 * first call adds a zero-valued local to off.
 *
 * symbols:
 *   func_021B9278  0x021B9278  thumb ov021
 *   func_021B9280  0x021B9280  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u16 h0;
    u8 b2;
    u8 pad3;
    s16 h4;
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

extern int func_021B9278(u8 *, void *, Tbl *);
extern int func_021B9280(u8 *, int, int, Tbl *);

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
        w = func_021B9280(base + off, x, v, o->x24);
        if (-w > y || y > w) {
            return 0;
        }
        if (x > v || x < 0) {
            return 0;
        }
    }
    return 1;
}
