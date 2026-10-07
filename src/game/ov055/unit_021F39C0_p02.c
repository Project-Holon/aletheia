/*
 * file:     unit_021F39C0_p02.c
 * unit:     yes
 * function: func_021F3B48, func_021F3C2C, func_021F3CE4, func_021F3CF4
 * address:  0x021F3B48
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021F4620     0x021F4620  data  ov055  a4
 *   d_021F4620_b   0x021F4620  data  ov055  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_021F40F4  0x021F40F4  thumb  ov055
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216CF2C 0x0216CF2C thumb ov010
 *   d_021F45C0 0x021F45C0 data a4
 */
#include "../../matched/include/G_V.h"
#include "../../matched/include/Obj13122.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef short          s16;

typedef struct Entry {
    u8 active;
    u8 f1;
    u8 kind;
    u8 f3;
    u8 pad4[8];
    void *obj;
    u8 pad10[8];
} Entry;

typedef struct Table {
    u8 hdr[8];
    Entry e[32];
} Table;

typedef unsigned int u32;

typedef struct V V;

typedef struct O {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    int fc;
    void *f10;
    u16 h14;
    u16 h16;
} O;

typedef struct Ent {
    int key;
    u16 h[6];
} Ent;

typedef struct T {
    u8 pad0[0xd];
    u8 n;
    u16 h[21];
    Ent *f38;
    u32 f3c;
} T;

extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u32 func_020056EC(u32);
extern int func_0216CE60(int, void *, int);
extern u32 func_021F40F4(u8 *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern int func_0216DCCC(void *a0, int a1);
extern void func_0216D8C0(int, int *);
extern int func_0216CF2C(int a0, int a1);
Entry *func_021F3B48(Table *t, int x, int y, unsigned int dir, int unused, int *out);
void func_021F3C2C(O *o, int a, int b, const T *s, int i);
void func_021F3CE4(char *p, int a1);
void func_021F3CF4(unsigned char *p, int a, int b);
extern struct V d_021F4620;
extern struct V d_021F4620_b;


/*
 * The switch lists case 3 before case 2: the original lays the dx = 1 arm
 * out ahead of the dx = -1 arm.
 */
Entry *func_021F3B48(Table *t, int x, int y, unsigned int dir, int unused, int *out)
{
    int dx;
    int dy;
    int i;
    s16 ex;
    s16 ey;
    int px;
    int py;

    switch (dir) {
    case 0:
        dx = 0;
        dy = -1;
        break;
    case 1:
        dx = 0;
        dy = 1;
        break;
    case 3:
        dx = 1;
        dy = 0;
        break;
    case 2:
        dx = -1;
        dy = 0;
        break;
    }
    *out = 0;
    for (i = 0; i < 32; i++) {
        if (t->e[i].active != 0 && t->e[i].kind == 1) {
            px = func_0216D83C(t->e[i].obj);
            py = func_0216D86C(t->e[i].obj);
            ex = px - x;
            ey = py - y;
            if (ex != 0) {
                ex = ex / (ex < 0 ? -ex : ex);
            }
            if (ey != 0) {
                ey = ey / (ey < 0 ? -ey : ey);
            }
            if (ex == 0 && ey == 0) {
                *out = 1;
                return &t->e[i];
            }
            if (ex == dx && ey == dy) {
                return &t->e[i];
            }
        }
    }
    return 0;
}


void func_021F3C2C(O *o, int a, int b, const T *s, int i)
{
    u32 k;
    u32 r;
    u16 x;

    k = 0;
    x = s->h[func_020056EC(0) % s->n];
    d_021F4620.h2 = x;
    r = func_020056EC(0);
    o->h8 = i + 0x30;
    for (k = 0; k < s->f3c; k++) {
        if (x == s->f38[k].key) {
            o->h6 = s->f38[k].h[r % 6];
            break;
        }
    }
    o->fc = func_0216CE60(a, &d_021F4620_b, b);
    o->f0 = 0;
    o->f1 = 0;
    o->f2 = 0;
    o->f3 = 0;
    o->ha = func_021F40F4((u8 *)s);
    func_0216DAC8((unsigned int *)o->fc, 1);
    func_0216DCCC((void *)o->fc, 1);
    {
        int v[3] = {0, 0, 0};
        v[0] = func_020056EC(0x8000) - 0x4000;
        func_0216D8C0(o->fc, v);
    }
}

void func_021F3CE4(char *p, int a1) { func_0216CF2C((int)(*(unsigned char * *)&((struct Obj13122 *)p)->fC), a1); ((struct Obj13122 *)p)->fC=0; }

extern void (*d_021F45C0[])(unsigned char *,unsigned int,unsigned int);

void func_021F3CF4(unsigned char *p, int a, int b) { if (p[0]) d_021F45C0[p[2]](p,a,b); }
