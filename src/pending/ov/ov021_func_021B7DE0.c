/*
 * function: func_021B7DE0
 * address:  0x021B7DE0
 * packet:   pkt_ov021_021B7DE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: control flow and both early-return blocks match. Residue: original computes off = h0*0x48 first (r3, spilled to [sp]) then loads h6, x14, and passes base+off via an extra 'adds r0, r3, #0'; this C computes x and y first. Tried statement and declaration orders, an Elem array index, off before the bound check.
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

extern int func_021B9278(u8 *, void *);
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

    if (a->b2 == 0) {
        if (a->h0 >= o->x24->h0) {
            return 0;
        }
    } else {
        t = o->x24;
        if (a->h0 >= t->h2) {
            return 0;
        }
        off = a->h0 * 0x48;
        base = t->x14;
        x = a->h6 << 4;
        y = a->h4 << 4;

        v = func_021B9278(base + off, o->x1c);
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
