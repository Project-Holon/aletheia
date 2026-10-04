/*
 * function: func_021AD5E0
 * address:  0x021AD5E0
 * packet:   pkt_ov021_021AD5E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   d_021D91F8     0x021D91F8  data  a4
 */
typedef unsigned short u16;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct T5 {
    Vec v[5];
} T5;

typedef struct S16 {
    int a, b, c, d;
} S16;

typedef struct Tab {
    int f0;
    u16 h4, h6, h8, ha, hc;
} Tab;

typedef struct Obj {
    Vec v;
    int padc;
    u16 h10;
    u16 pad12;
    S16 s14;
} Obj;

extern T5 d_021D91F8;

typedef unsigned int   u32;
extern int func_021AC1AC(u32 a);
extern int func_021ABE18(int a);
extern u16 func_021C6590(int a, int b, int c, int d);
extern void func_021AC1B8(int a, Vec *v);
extern void func_021AC1CC(int a, Vec *v);

void func_021AD5E0(int a, int *bp)
{
    Obj *b = (Obj *)bp;
    Vec out;
    T5 tab;
    int r;
    int m;
    Tab *t;

    b->s14 = *((S16 *)func_021AC1AC(a));
    t = (Tab *)b->s14.b;
    r = func_021ABE18(t->f0);
    switch (b->s14.c) {
    case 0:
        m = ((Tab *)b->s14.b)->h4;
        break;
    case 1:
        m = ((Tab *)b->s14.b)->h6;
        break;
    case 2:
        m = ((Tab *)b->s14.b)->ha;
        break;
    case 3:
        m = ((Tab *)b->s14.b)->h8;
        break;
    case 4:
        m = ((Tab *)b->s14.b)->hc;
        break;
    default:
        goto skip;
    }
    b->h10 = func_021C6590(r, m, 0, 0);
skip:
    if (b->s14.d != 0) {
        tab = d_021D91F8;
        b->v = tab.v[b->s14.c];
        func_021AC1B8(b->s14.d, &out);
        out.x += b->v.x;
        out.y += b->v.y;
        out.z += b->v.z;
        func_021AC1CC(a, &out);
    }
}
