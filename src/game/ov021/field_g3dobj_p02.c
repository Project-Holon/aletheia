/*
 * file:     field_g3dobj_p02.c
 * unit:     yes
 * function: func_021C6078, func_021C60B8, func_021C61D4, func_021C61EC, func_021C622C, func_021C62F0, func_021C6368, func_021C63AC, func_021C6400, func_021C6470, func_021C64E0, func_021C6534, func_021C6538, func_021C6574, func_021C6580, func_021C6590, func_021C6628
 * address:  0x021C6078
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021A9F40  0x021A9F40  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021D3288  0x021D3288  thumb  ov021
 *   func_021D325C  0x021D325C  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 *   d_021DAAB4     0x021DAAB4  data  a2
 *   func_02040588  0x02040588  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE4A8     0x021DE4A8  data  ov021  a1
 *   func_021C6A90  0x021C6A90  thumb  ov021
 *   func_021C6940  0x021C6940  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021C6854  0x021C6854  thumb  ov021
 *   func_021C69B4  0x021C69B4  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_021C6874  0x021C6874  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 */
#include "../../matched/include/Obj06082.h"
#include "../../matched/include/Obj18307.h"
#include "../../matched/include/Obj06083.h"
#include "../../matched/include/Obj00458.h"
#include "../../matched/include/Obj18309.h"
#include "../../matched/include/Obj18310.h"

struct Ctx;
struct Desc;
struct Obj;
struct Obj00020;
struct Evt;
struct St021D3244;
struct St021D325C;
struct Arg;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    u8 f0;
    u8 pad1[3];
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
} Work_021C6078;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    void *f4;
} Ctx;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    void *fC;
} Work_021C62F0;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6400;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6400 *fC;
} Mgr_021C6400;

typedef struct {
    u32 kind : 2;
    u32 rest : 30;
    u16 f4;
    u16 f6;
    u8 pad8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6470;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6470 *fC;
} Mgr_021C6470;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 rest : 26;
    u16 f4;
    u16 f6;
    u8 f8[0x3C];
    void *f44;
    u8 pad48[0x20];
} Elem_021C64E0;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    Elem_021C64E0 *fC;
} Mgr_021C64E0;

typedef struct { u32 f0; u8 pad[0x28]; } Item_021C6078;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item_021C6078 *f8; } Mgr;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 rest : 29;
    u16 f4;
    u16 f6;
    Vec f8;
    int f14;
    int f18;
    int f1C;
    u8 f20[0x24];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6590;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6590 *fC;
} Mgr_021C6590;

typedef struct { u8 pad[0x2c]; } Item_021C6580;

typedef struct { u32 k:2; u32 rest:30; u16 f4; u8 pad[0x62]; } Elem_021C6628;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item_021C6580 *f8; Elem_021C6628 *fC; } Mgr_021C6628;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D480(char *p);
extern void *func_02189A00(u8 *p);
extern int func_021C1D68(int a, int b, int c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02188CE8(u8 *p);
extern int func_021A9F40(struct Ctx *ctx, int mode);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void *func_02188C7C(u8 *p);
extern u32 *func_0216D9E4(void *c);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern u32 func_02188E30(u8 *p);
extern void func_020061E4(u32 a);
extern void func_021D3288(void *a, int b, int c);
extern void func_021D325C(struct St021D325C *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021C6A90(u32 *p, u8 *q);
extern void func_021C6940(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_021C6854(u8 *s);
extern void func_021C69B4(Elem_021C6470 *e, u8 *s, int a, int b, int c, int d, int f);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_021C6874(Item_021C6078 *it, u32 b, void *c, int d, int e);
extern void func_0207ADC4(void *p);
void *func_021C6078(void *a, void *b, u8 c);
int func_021C60B8(void *task, int *state, Work_021C6078 *w);
int func_021C61D4(u32 a);
void func_021C61EC(void *a, void *b, void *c);
int func_021C622C(void *unused, int *st, Ctx *c);
void func_021C62F0(u8 *p);
void func_021C6368(u8 *p);
Work_021C62F0 *func_021C63AC(u32 heap, u32 n, u32 m);
void func_021C6400(Mgr_021C6400 *m);
void func_021C6470(Mgr_021C6470 *m);
void func_021C64E0(Mgr_021C64E0 *m);
void func_021C6534(u32 *p, u32 v);
u16 func_021C6538(Mgr *m, void *c, int d, int e);
int func_021C6574(u32 a, u32 b, u32 c);
void func_021C6580(u8 *p, int i);
u16 func_021C6590(Mgr_021C6590 *m, u16 idx, u16 a, Vec *src);
void func_021C6628(Mgr_021C6628 *m, int idx);
extern const Pt d_021DAAB4;
extern char d_021DE4A8[];








void *func_021C6078(void *a, void *b, u8 c)
{
    void *task;
    u8 *w;

    task = func_020122C0(a, 0, func_021C60B8, 0x14);
    w = func_020124E8(task);
    func_02082BCC(w, 0, 0x14);
    w[0] = c;
    ((struct Obj06082 *)w)->f4 = a;
    ((struct Obj06082 *)w)->fC = b;
    ((struct Obj06082 *)w)->f10 = func_02188CB4(b);
    ((struct Obj06082 *)w)->f8 = func_020120F4(a);
    return task;
}








int func_021C60B8(void *task, int *state, Work_021C6078 *w)
{
    void *t;

    switch (*state) {
    case 0:
        if (w->f0 >= 6) {
            *state = 5;
            break;
        }
        func_021A2F48(w->f10, 0x80);
        (*state)++;
    case 1:
        if (func_021A2F54(w->f10) != 1)
            break;
        func_0216D410(func_021A3074(w->f10), 0xa2);
        (*state)++;
        break;
    case 2:
        if (func_0216D480(func_021A3074(w->f10)) != 1)
            break;
        t = (void *)func_021C1D68(w->f4, (int)func_02189A00(w->fC), w->f0);
        if (t != 0)
            func_02012374(task, t);
        (*state)++;
        break;
    case 3:
        func_021A2F48(w->f10, 8);
        (*state)++;
    case 4:
        if (func_021A2F54(w->f10) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (func_021C61D4((u32)w) == 0) {
            *state = 8;
            break;
        }
        func_021C61EC(task, (void *)w->f4, w->fC);
        *state = 6;
        break;
    case 6:
        t = (void *)func_021A9F40((struct Ctx *)func_02188CE8(w->fC), 2);
        if (t == 0) {
            *state = 7;
            break;
        }
        func_02012374(task, t);
        *state = 9;
        break;
    case 7:
        func_02158780(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        func_02158780(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(w->fC));
        return 1;
    }
    return 0;
}








int func_021C61D4(u32 a)
{
if (func_021A1BF4((u8 *)func_02188C6C((u8 *)(((struct Obj18307 *)((u8 *)(a)))->fC))) == 0) {
    return 1;
}
return 0;
}








void func_021C61EC(void *a, void *b, void *c)
{
    void *task;
    u8 *w;

    task = func_020122C0(b, 0, func_021C622C, 8);
    w = func_020124E8(task);
    w[0] = 3;
    w[1] = 0;
    w[2] = 2;
    w[3] = 0;
    ((struct Obj06083 *)w)->f4 = func_02188E30(c);
    func_02012374(a, task);
}








int func_021C622C(void *unused, int *st, Ctx *c)
{
    switch (*st) {
    case 0:
        func_021C62F0((u8 *)c);
        func_020061E4(0x683);
        *st = *st + 1;
        break;
    case 1:
        if (c->f3++ >= c->f2) {
            c->f1++;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 >= 8) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (c->f3++ < 0x1e) {
            *st = *st + 1;
        }
        break;
    case 3:
        if (c->f3++ >= c->f2) {
            c->f1--;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 == 0) {
            *st = *st + 1;
        }
        break;
    case 4:
        func_021D325C(c->f4, 0, 0, 0, 0x1f);
        func_021D3244(c->f4, c->f0, 0);
        *st = *st + 1;
        break;
    default:
        func_021C6368((u8 *)c);
        return 1;
    }
    return 0;
}







void func_021C62F0(u8 *p)
{
    Pt pt;

    pt = d_021DAAB4;
    func_02040588(p[0], 0);
    func_02040E78(p[0], &pt, 8, 0x20);
    func_02040C14(p[0], 1, 1, 0x100);
    func_02041300(p[0], 0x100, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_021D325C(((struct Obj00458 *)p)->f4, 8, 0x37, p[1], 0x10 - p[1]);
    func_021D3244(((struct Obj00458 *)p)->f4, p[0], 1);
}







void func_021C6368(u8 *p)
{
    Pt pt = {0, 0};

    func_02040E78(p[0], &pt, 8, 0x20);
    func_02041300(p[0], 0, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_02040DA8(p[0], 1, 0x100);
}







Work_021C62F0 *func_021C63AC(u32 heap, u32 n, u32 m)
{
    Work_021C62F0 *w;

    w = func_02030734(heap, 0x14, 1, d_021DE4A8, 0x72);
    w->f8 = func_02030734(heap, n * 0x2c, 1, d_021DE4A8, 0x75);
    w->fC = func_02030734(heap, m * 0x68, 1, d_021DE4A8, 0x78);
    w->f0 = heap;
    w->f4 = n;
    w->f6 = m;
    w->f2 = 1;
    return w;
}







void func_021C6400(Mgr_021C6400 *m)
{
    u32 i;
    Elem_021C6400 *e;
    u8 *s;

    i = 0;
    m->f2 = 0;
    e = m->fC;
    if (i < m->f6)
        for (; i < m->f6; i++) {
            if (e->kind == 1 && e->f44 != 0)
                func_021C6A90((u32 *)e, m->f8 + e->f4 * 0x2c);
            e++;
        }
    func_020307B0(m->fC);
    i = 0;
    s = m->f8;
    if (i < m->f4)
        for (; i < m->f4; i++) {
            func_021C6940(s);
            s += 0x2c;
        }
    func_020307B0(m->f8);
    func_020307B0(m);
}







void func_021C6470(Mgr_021C6470 *m)
{
    int i;
    int j;
    Elem_021C6470 *e;
    u8 *s;

    if (m->f2 == 1) {
        e = m->fC;
        s = m->f8;
        for (i = 0; i < m->f4; i++) {
            if (s[0x29] == 2)
                func_021C6854(s);
            s += 0x2c;
        }
        s = m->f8;
        for (j = 0; j < m->f6; j++) {
            if (e->kind == 2)
                func_021C69B4(e, s + e->f4 * 0x2c, e->f4, e->f6, m->f0, 0, 0);
            e++;
        }
    }
}







void func_021C64E0(Mgr_021C64E0 *m)
{
    u32 i;
    Elem_021C64E0 *e;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 1) {
            if (e->b4 == 0 && e->b3 == 0) {
                if (e->b2 == 1)
                    func_02047AC8(e->f44, (struct Arg *)e->f8);
                else
                    func_02047A60(e->f44, (struct Arg *)e->f8);
            }
            e->b5 = 0;
        }
        e++;
    }
}





/*
 * Setter: stores the second argument at +0x10.  Unlabelled in the listing;
 * called from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6534(u32 *p, u32 v)
{
    p[4] = v;
}



u16 func_021C6538(Mgr *m, void *c, int d, int e)
{
    u16 i;
    Item_021C6078 *it = m->f8;
    for (i = 0; i < m->f4; i++, it++) {
        if (it->f0 == 0) {
            func_021C6874(it, m->f0, c, d, e);
            return i;
        }
    }
    return 0;
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C6574(u32 a, u32 b, u32 c)
{
    return func_021C6538((Mgr *)a, (void *)b, c, ((struct Obj18309 *)((u8 *)(a)))->f10);
}



/*
 * Tail call on a strided element of the array at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6580(u8 *p, int i)
{
    func_021C6940((u8 *)(((struct Obj18310 *)p)->f8 + i * 0x2c));
}



u16 func_021C6590(Mgr_021C6590 *m, u16 idx, u16 a, Vec *src)
{
    u16 i;
    Elem_021C6590 *e;
    u8 *s;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 0 && e->f44 == 0) {
            s = m->f8 + idx * 0x2c;
            if (s[0x29] == 2) {
                e->f4 = idx;
                e->f6 = a;
                e->kind = 2;
                e->b2 = 1;
                e->f14 = 0x1000;
                e->f18 = 0x1000;
                e->f1C = 0x1000;
                if (src != 0)
                    e->f8 = *src;
                func_0207ADC4(e->f20);
            } else {
                func_021C69B4((Elem_021C6470 *)e, (u8 *)s, (int)idx, (int)a, (int)m->f0, (int)src, 1);
            }
            return i;
        }
        e++;
    }
    return 0;
}


void func_021C6628(Mgr_021C6628 *m, int idx)
{
    Elem_021C6628 *e;
    e = &m->fC[idx];
    m->f2 = 0;
    if (e->k == 1)
        func_021C6A90((u32 *)e, (u8 *)(&m->f8[e->f4]));
    m->f2 = 1;
}
