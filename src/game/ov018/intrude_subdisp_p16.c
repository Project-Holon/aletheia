/*
 * file:     intrude_subdisp_p16.c
 * unit:     yes
 * function: func_0217F938, func_0217F95C, func_0217FA1C, func_0217FA24, func_0217FA38, func_0217FAE0, func_0217FB2C, func_0217FB5C, func_0217FB94, func_0217FC08, func_0217FC6C
 * address:  0x0217F938
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217F2B4  0x0217F2B4  thumb  ov018
 *   func_0217F5A0  0x0217F5A0  thumb  ov018
 *   func_0217F4A0  0x0217F4A0  thumb  ov018
 *   func_0201210C  0x0201210C  thumb
 *   func_0217C458  0x0217C458  thumb  ov018
 *   func_0201235C  0x0201235C  thumb
 *   func_0217F318  0x0217F318  thumb  ov018
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02176230  0x02176230  thumb  ov011
 *   func_0217CE08  0x0217CE08  thumb  ov018
 *   func_02012374  0x02012374  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF10 0x0200BF10 thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217FDA0  0x0217FDA0  thumb ov018
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_02175368  0x02175368  thumb  ov011
 *   func_021803F0  0x021803F0  thumb  ov018
 *   func_0217FE6C  0x0217FE6C  thumb  ov018
 *   func_0217545C  0x0217545C  thumb ov011
 *   func_0217FCAC  0x0217FCAC  thumb ov018
 */
#include "../../matched/include/Obj07367.h"

struct Desc;
struct Obj;
struct Ctx;
struct S0201235C;
struct BigObj;
struct Evt;
struct Rec44;
struct Big;
struct Rec1B0;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef struct { int f0; int f4; int f8; u16 fC; } Req;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, u8, u32);
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void func_0217F2B4(void *a0, void *a1);
int func_0217F5A0(void *p);
void func_0217F4A0(void **p, unsigned int index, int a, int b);
void *func_0201210C(const struct Ctx *p);
struct Desc *func_0217C458(void *a0, void *a1, u8 *a2, int a3);
void func_0201235C(struct S0201235C *o, u32 *out);
void func_0217F318(void *p);
void *func_020120F4(const struct Ctx *p);
u8 func_02012B58(const struct BigObj *p);
u8 func_02176230(u8 *p, u8 *q);
void *func_0217CE08(void *a, void *b, int c, int d);
void func_02012374(struct Evt *evt, struct Evt **out);
u8 *func_020120F8(const struct Ctx *p);
u16 func_02012AC8(const struct Rec44 *p);
u32 func_02013D5C(u32 id);
u16 *func_02159AE8(void *a0, void *a1);
void *func_0215A5DC(void *a0);
u8 func_0215841C(void *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *);
extern u8 func_0200BF10(struct Rec1B0 *p);
void *func_02188C7C(unsigned char *p);
void func_0216D9A0(void *x);
u32 *func_0216D9E4(void *c);
void func_0217FDA0(int a, u8 *b, u8 *c, int d, int e, int f, u16 g);
void func_0217538C(u8 *w, int a);
void func_02175368(char *p);
int func_021803F0(u8 *a, u8 *b);
int func_0217FE6C(void);
void func_0217545C(u8 *p);
int func_0217FCAC(int x, int *st, int *obj);
void *func_0217F938(void *owner);
int func_0217F95C(void *a0, int *state, void *a2);
void func_0217FA1C(void *p);
void *func_0217FA24(void *owner);
int func_0217FA38(void *a, int *state);
int func_0217FAE0(void *unused, int a);
int func_0217FB2C(void *a, void *vm);
void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f);
int func_0217FB94(int a, int *state, Req *req);
void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f);
void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e);

void *func_0217F938(void *owner)
{
    void *task;
    task = func_020122C0(owner, 0, func_0217F95C, 0x30);
    func_02082BCC(func_020124E8(task), 0, 0x30);
    return task;
}


int func_0217F95C(void *a0, int *state, void *a2)
{
    void *h;
    u8 *w;
    struct Desc *r;

    h = func_020124E4(a0);
    w = (u8 *)func_02158344(func_02012138(h));
    if (w == 0 && *state < 3) {
        *state = 3;
    }
    switch (*state) {
    case 0:
        w[0x93F] |= 8;
        func_0217F2B4(a2, h);
        if (func_0217F5A0(w + 0x1AC) == 3) {
            *state = 2;
        } else {
            func_0217F4A0(a2, 0x1A, 0, 0);
            (*state)++;
        }
        break;
    case 1:
        switch (func_0217F5A0(w + 0x1AC)) {
        case 2:
            break;
        case 3:
        default:
            (*state)++;
            break;
        }
        break;
    case 2:
        r = func_0217C458(h, func_0201210C(h), w, 0x15);
        func_0217FA1C(a2);
        func_0201235C(a0, (u32 *)r);
        return 0;
    case 3:
        func_0217FA1C(a2);
        return 1;
    }
    return 0;
}


void func_0217FA1C(void *p)
{
    func_0217F318(p);
}

void *func_0217FA24(void *owner)
{
    return func_020122C0(owner, 0, func_0217FA38, 0);
}


int func_0217FA38(void *a, int *state)
{
    void *s;
    u32 h;
    void *p2;
    void *p3;
    u8 *w;
    void *r;

    s = func_020124E4(a);
    h = func_02012138(s);
    p2 = func_020120F4(s);
    p3 = func_0201210C(s);
    w = (u8 *)func_02158344(h);
    switch (*state) {
    case 0:
        if (w == 0) {
            func_02012B58(p2);
        } else {
            func_02176230(w, w + 0x1AC);
        }
        r = func_0217CE08(s, p3, 0x117, 1);
        if (r == 0) {
            return 1;
        }
        func_02012374(a, r);
        (*state)++;
        break;
    case 1:
        if (func_02013D5C(func_02012AC8((const struct Rec44 *)func_020120F8(s))) == 1) {
            func_02012374(a, func_0217F938(s));
        }
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


/*
 * What closed it: the store through `out` is written in each arm of the
 * if/else (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md)
 * rather than once after it through a shared `v`; the single store made
 * `v` live across the join and coloured out/q/temp as r6/r4/r5 instead of
 * r5/r6/r4 (docs/notes/pkt_ov018_0217FAE0.c.txt has the earlier miss).
 */
int func_0217FAE0(void *unused, int a)
{
    u16 *out;
    void *t;
    void *q;
    int v;

    out = func_02159AE8(unused, (void *)a);
    t = func_0215A5DC((void *)a);
    func_02012138(t);
    q = func_020120F4(t);
    if (func_0215841C(q) == func_02012B58(q)) {
        *out = 0;
    } else {
        v = func_0215841C(q) - func_02012B58(q);
        if (v < 0) {
            v += 3;
        }
        *out = v;
    }
    return 0;
}

int func_0217FB2C(void *a, void *vm)
{
    u16 *out;
    int v;
    out = func_02159AE8(a, vm);
    if (func_0200BF10((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4(func_0215A5DC(vm))))) != 0x30) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}

void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f)
{
    Req *work;
    void *task;
    task = func_020122C0(owner, 0, func_0217FB94, 0x10);
    work = func_020124E8(task);
    func_02082BCC(work, 0, 0x10);
    work->f0 = b;
    work->f4 = d;
    work->f8 = e;
    work->fC = f;
    return task;
}


int func_0217FB94(int a, int *state, Req *req)
{
    int s;
    u8 *w;

    s = (int)func_020124E4((struct Obj *)a);
    w = (u8 *)func_02158344(func_02012138((const struct Ctx *)s));
    switch (*state) {
    case 0:
        if (w == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((u8 *)req->f0));
        func_02012374((struct Evt *)a, func_0217FC08(s, req->f0, w, req->f4, req->f8, req->fC));
        (*state)++;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((u8 *)req->f0));
        return 1;
    }
    return 0;
}


void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_0217FE6C, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (u8 *)((int *)c), q, b, d, e, f);
    func_0217538C(c, e);
    func_02175368((char *)c);
    q[0x41] = func_021803F0(q, c);
    return r;
}


void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e)
{
    void *r = func_020122C0(p, 0, func_0217FCAC, 0x10);
    int *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x10);
    q[0] = a;
    q[1] = c;
    q[2] = d;
    ((struct Obj07367 *)q)->fC = e;
    func_0217545C((u8 *)b);
    return r;
}
