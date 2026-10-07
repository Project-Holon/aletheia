/*
 * file:     btlv_effvm_p94.c
 * unit:     yes
 * function: func_022042E4, func_022043AC, func_022043C0, func_02204438
 * address:  0x022042E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022056B4 0x022056B4 thumb ov094
 *   func_022053DC 0x022053DC thumb ov094
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B22C 0x0204B22C arm
 *   func_022044C0 0x022044C0 thumb ov094
 *   func_02204960 0x02204960 thumb ov094
 *   func_0220687C 0x0220687C thumb ov094
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_022044A0  0x022044A0  thumb  ov094
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_0207AD58  0x0207AD58  thumb
 *   func_02040820  0x02040820  arm
 */
#include "../../matched/include/Obj21763.h"

struct Bank;
struct Cfg;
struct Descriptor;
struct S02030EE8;
struct Ctx;
typedef struct Main_022042E4 {
    char pad00[0x68];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
} Main_022042E4;

typedef struct { Main_022042E4 *main; int state; } Ctx_022042E4;

typedef struct { int a, b; } Pair;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Main_022043C0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022043C0;

typedef struct Obj {
    Main_022043C0 *main;
    int f4;
    int f8;
    int fc;
    int f10;
} Obj;

typedef struct Ctx_02204438 {
    char *main;
    int cur;
    int target;
    int step;
    int ang;
} Ctx_02204438;

extern void func_022056B4(Main_022042E4 *);
extern void func_022053DC(char *m);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_022044C0(Main_022042E4 *, int, int, int, int);
extern void func_02204960(Main_022042E4 *, int, int, int, int, int, int, int);
extern void func_0220687C(char *p, void *q);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *cb, void *ctx, int a);
extern void func_022044A0(void *h);
extern void func_0220684C(char *p, int a, int b);
extern void func_0207AD58(void *dst, int a, int b);
extern void func_02040820(u32 layer, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_022042E4(void *h, Ctx_022042E4 *c);
void func_022043AC(void *h);
void func_022043C0(Main_022043C0 *m, int a1, int a2, int a3, int a4);
void func_02204438(int a0, Ctx_02204438 *c);
extern const Pair d_0220A4EC[];
extern const char d_0220AEB0[];

void func_022042E4(void *h, Ctx_022042E4 *c)
{
    switch (c->state) {
    case 0:
        func_022056B4(c->main);
        c->state++;
        break;
    case 1:
        func_022053DC((char *)c->main);
        func_02045374(c->main->obj228);
        func_020409B4(6);
        func_022044C0(c->main, d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
        func_02204960(c->main, -1, 0, 0, 1, 1, 2, 0);
        c->state++;
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            func_02045334(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}


void func_022043AC(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((struct Obj21763 *)p)->f68 &= ~1;
}


void func_022043C0(Main_022043C0 *m, int a1, int a2, int a3, int a4)
{
    Obj *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x14, 0, d_0220AEB0, 0xb97);
    o->main = m;
    o->f4 = a1;
    o->f8 = a2;
    o->fc = a3;
    o->f10 = a4;
    func_0220684C((char *)m, (int)func_020056A0((void *)func_02204438, o, 0), (int)func_022044A0);
    m->st = m->st + 1;
}


void func_02204438(int a0, Ctx_02204438 *c)
{
    int m[4];

    c->cur = c->cur + c->step;
    if (c->step > 0)
        c->ang = c->ang - 2;
    else if (c->step < 0)
        c->ang = c->ang + 2;
    func_0207AD58(m, c->cur, c->cur);
    func_02040820(7, 0, 0x80, (u32)m, 0x100, 0x100);
    func_02040820(7, 3, c->ang, (u32)m, 0x100, 0x100);
    if (c->cur == c->target)
        func_0220687C(c->main, (void *)a0);
}
