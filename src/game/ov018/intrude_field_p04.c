/*
 * file:     intrude_field_p04.c
 * unit:     yes
 * function: func_0217B82C, func_0217B930, func_0217B94C, func_0217B968, func_0217BA48, func_0217BA54, func_0217BAB4, func_0217BBCC, func_0217BBD8, func_0217BC94, func_0217BCDC
 * address:  0x0217B82C
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
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217C658  0x0217C658  thumb  ov018
 *   func_0217C688  0x0217C688  thumb  ov018
 *   func_02185214  0x02185214  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0202648C  0x0202648C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02012204  0x02012204  thumb
 *   func_020120D8  0x020120D8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02026454  0x02026454  thumb
 *   func_020392B8  0x020392B8  arm
 *   func_02026474  0x02026474  thumb
 *   func_02026400  0x02026400  thumb
 *   func_0202640C  0x0202640C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020263D8  0x020263D8  thumb
 *   d_02183AE0     0x02183AE0  data   a1
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02175274  0x02175274  thumb  ov011
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02161FEC  0x02161FEC  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159BBC  0x02159BBC  thumb
 *   func_0218CD20  0x0218CD20  thumb  ov021
 *   func_02012114  0x02012114  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175598  0x02175598  thumb  ov011
 *   func_021A3220  0x021A3220  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021A322C  0x021A322C  thumb  ov021
 */
#include "../../matched/include/Obj09388.h"

struct Evt;
struct Obj;
struct Rec;
struct Ctx;
struct Fx;
struct Obj2;
struct Obj00020;
struct Comm;
struct Rec44;
struct SaveBlock;
struct VecFx32;
struct BigObj;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    u8 f8[1];
} Work;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef unsigned short u16;

typedef struct {
    int f00;
    int f04;
    int pad;
    u16 pad2;
    u8 f0e;
} Rec;

typedef struct { u16 f : 3; u16 g : 13; } Fh;

typedef struct { u8 lo : 4; u8 b4 : 1; u8 hi : 3; } Fb;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_02188C7C(unsigned char *p);
extern void func_0216D9A0(void *);
extern u32 func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern struct Obj2 *func_02190F64(struct Fx *a, u32 b);
extern void func_02190E74(u32 *p, u32 b, u32 c, u32 d);
extern u32 func_02190EF0(u32 *p);
extern int func_02190E40(u32 a);
extern u32 func_02045C04(struct Rec *rec);
extern int func_02188BE8(void *);
extern void *func_02188CB4(struct Obj00020 *p);
extern int func_021A3238(u8 *p);
extern void func_0217C658(void *, int, void *, int, int, int);
extern int func_0217C688(void *, int);
extern int func_02185214(int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 *func_0216D9E4(void *c);
extern u32 func_0202648C(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_0200FB24(void);
extern int func_02035390(void);
extern int func_020353B0(void);
extern u32 func_02012204(const struct Ctx *p);
extern int func_020120D8(char *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern u32 func_02026454(void *obj);
extern int func_020392B8(void);
extern u32 func_02026474(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_0202640C(struct Comm *p, u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern u8 *func_020120F8(const struct Ctx *p);
extern unsigned int func_02012AE4(const struct Rec44 *p);
extern int func_02175E90(void *p, u8 *q);
extern void func_021A3044(u8 *p, void *v);
extern void func_02175274(u8 *, int);
extern u16 func_02039338(void);
extern void func_02175710(u8 *o, u32 v);
extern void func_02161FEC(char *p, u16 v);
extern unsigned int func_02188C98(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern u16 *func_02159B48(int a);
extern int func_02159B94(int a0, int a1, int a2, int a3);
extern void func_02159BBC(int);
extern void func_0218CD20(int, int, int);
extern u32 func_02012114(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern u16 func_02175598(u8 *o, u32 id);
extern void func_021A3220(u8 *p, u32 res);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D8C0(void *, Vec *);
extern void func_021A322C(u8 *p);
int func_0217B82C(int a0, int *state, Work *w);
int func_0217B930(int *p);
int func_0217B94C(int *p);
void func_0217B968(int a0, void *a1, void *a2, void *a3);
void func_0217BA48(int a, int b);
void func_0217BA54(void *a);
void func_0217BAB4(int a0, void *a1, void *a2, u8 *p);
void func_0217BBCC(int a, int b, char *p);
void func_0217BBD8(u8 *a, int b, u8 *c);
void func_0217BC94(int a, int n);
void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag);
extern const char d_02183AE0[];


int func_0217B82C(int a0, int *state, Work *w)
{
    int sys;
    void *obj;
    int hnd;

    sys = (int)func_020124E4((struct Obj *)a0);
    obj = func_0201210C((void *)sys);
    func_02012138((const struct Ctx *)sys);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(obj));
        hnd = func_02188C54(obj);
        w->f0 = func_021904B0(hnd, 0x2D);
        w->f4 = (int)func_02190F64((struct Fx *)hnd, w->f0);
        func_02190E74((u32 *)w->f4, 0, 0, 0x60);
        (*state)++;
        break;
    case 1:
        if (func_02190EF0((u32 *)w->f4) == 1) {
            func_02190E40(w->f4);
            func_02045C04((struct Rec *)w->f0);
            (*state)++;
        }
        break;
    case 2:
        obj = func_0201210C((void *)sys);
        if (func_02188BE8(obj) == 1) {
            if (func_021A3238(func_02188CB4((void *)obj)) == 0) {
                func_0217C658(w->f8, sys, obj, 0, 0, 0);
                (*state)++;
            } else {
                *state = 4;
            }
        }
        break;
    case 3:
        if (func_0217C688(w->f8, 0) == 1)
            (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185214(sys));
        (*state)++;
        break;
    case 5:
        if (obj != 0 && func_02188BE8(obj) == 1) {
            func_0216D9E4(func_02188C7C((void *)obj));
            return 1;
        }
        break;
    }
    return 0;
}

int func_0217B930(int *p) { if (*p >= 0x348000 || *p <= 0xb8000) return 1; return 0; }

int func_0217B94C(int *p) { if (*p > 0x308000 || *p < 0xe8000) return 1; return 0; }


void func_0217B968(int a0, void *a1, void *a2, void *a3)
{
    Vec v;

    if (func_0202648C(a2) != 0)
        return;
    if (func_02026460(a2) == 1)
        return;
    if (func_0200FB24() != 0)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    if (func_02012204(a1) == 1)
        return;
    if (func_020120D8(a1) == 1)
        return;
    if (func_02013D5C(func_02012AC8((const struct Rec44 *)func_020127A4(func_020120F4(a1)))) == 0)
        return;
    func_021A3038(a3, (struct VecFx32 *)&v);
    switch (func_02026454(a2)) {
    case 0:
        if (func_0217B930((int *)(&v)) == 1)
            func_0217BA54(a1);
        break;
    case 2:
        if (func_0217B930((int *)(&v)) != 0)
            return;
        if (func_020392B8() > 1)
            return;
        if (((u8 *)func_02026474(a2))[0x8FD] == 4)
            return;
        func_02026400(a2);
        break;
    case 1:
        if (func_0217B930((int *)(&v)) == 1)
            func_0202640C(a2, (u32)func_0217BA48, (u32)a1);
        break;
    }
}


void func_0217BA48(int a, int b)
{
    if (b == 0)
        func_0217BA54((void *)a);
}


void func_0217BA54(void *a)
{
    int h;
    Rec *r;

    h = func_02012138(a);
    if (func_0200FB24() != 0)
        return;
    if (func_02012204(a) == 1)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    r = func_02030734(0x8005, 0x10, 1, d_02183AE0, 0x528);
    r->f0e = 1;
    r->f00 = (int)a;
    r->f04 = h;
    func_020263D8((struct Comm *)h, 2, (u32)r);
}


void func_0217BAB4(int a0, void *a1, void *a2, u8 *p)
{
    int x;
    int idx;
    Vec cur;
    Vec tmp;
    int flag;
    int prev;
    int limit;
    int sys;

    x = (int)func_020120F8(a1);
    sys = func_02012AC8((const struct Rec44 *)x);
    func_02012AE4((const struct Rec44 *)x);
    x = func_02012138(a1);
    flag = 0;
    func_020120F4(a1);
    if ((int)func_02026454((void *)x) != 2)
        return;
    if (p == 0)
        return;
    if (func_02013D5C(sys) == 0)
        return;
    if (p[0x902] < 2)
        return;
    if (func_02175E90(p, p + 0x1AC) == 1)
        return;
    func_021A3038(a2, (struct VecFx32 *)&cur);
    tmp = cur;
    x = cur.x;
    prev = ((Fh *)(p + 0x86))->f;
    limit = (p[0x901] + 1) << 22;
    if (x < 0) {
        tmp.x = limit + x;
        flag = 1;
    } else if (x > limit) {
        tmp.x = x - limit;
        flag = 1;
    }
    if (flag == 1) {
        x = tmp.x;
        if (func_020120D8(a1) == 1) {
            tmp = cur;
            flag = 0;
        }
    }
    idx = x / 0x400000;
    if (flag == 1) {
        func_021A3044(a2, &tmp);
        func_02175274(p, tmp.x);
    }
    idx += func_02039338();
    if (idx > p[0x901])
        idx -= p[0x901] + 1;
    if (prev == idx)
        return;
    func_02175710(p, idx);
    p[0x900] = 1;
    func_02161FEC((char *)(p + 0x35C), (u8)idx);
}

void func_0217BBCC(int a, int b, char *p)
{
    p[0x901] = 0;
}


void func_0217BBD8(u8 *a, int b, u8 *c)
{
    Vec v;
    int n;
    void *h;
    int buf;

    if (c == 0 || a == 0)
        return;
    if (func_02188C98(a) == 0)
        return;
    if (func_02013D5C(func_02188C9C((u8 *)a)) == 0)
        return;
    n = c[0x902] - 1;
    if (n <= 0)
        n = 1;
    if (((unsigned)(c[0x8f8] << 26) >> 31) == 1)
        n = 1;
    if (c[0x901] >= n)
        return;
    h = func_02188CB4((void *)a);
    if (h == 0)
        return;
    func_021A3038(h, (struct VecFx32 *)&v);
    v.x = v.x % 0x400000;
    if (func_0217B94C((int *)(&v)) == 1)
        return;
    buf = (int)func_02159B48(0x8015);
    func_02159B94(buf, 0x76, 0x76 + 0xa1, 0x8015);
    do {
        func_0218CD20((int)a, func_02188C98(a), buf);
        c[0x901]++;
    } while (c[0x901] < n);
    func_02159BBC(buf);
}


void func_0217BC94(int a, int n)
{
    int r;

    if (n >= 3)
        n = 2;
    r = (int)func_02159B48(0x15);
    func_02159B94(r, 0x76, 0x76 + 0xa1, 0x8015);
    while (n > 0) {
        func_0218CD20(a, func_02188C98((u8 *)a), r);
        n--;
    }
    func_02159BBC(r);
}


void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag)
{
    int res;
    void *obj;
    int has;
    int x;
    int y = (int)func_020120F4(a1);
    Vec v = { 0, 0, 0 };

    if (func_02012114(a1) == 0)
        return;
    x = (int)func_02012944(func_020120F4(a1));
    has = func_02008550((const struct Sub0200852CObj *)x);
    if (p != 0) {
        if (id == 0xFFFF) {
            if (((Fh *)(p + 0x86))->f == func_02012B58((const struct BigObj *)y))
                id = 0;
        }
        if (id == 0) {
            kind = has == 0 ? 3 : 4;
            flag = has;
        }
        if (((struct Obj09388 *)p)->f88 == id)
            return;
        ((struct Obj09388 *)p)->f88 = id;
        ((Fb *)(p + 0x8A))->lo = kind;
        ((Fb *)(p + 0x8A))->b4 = flag;
        p[0x900] = 1;
        res = func_02175598(p + 0x70, x);
    } else {
        id = 0;
        res = 1;
        if (has)
            res = 4;
    }
    obj = func_02188CB4(func_0201210C(a1));
    func_021A3220(obj, (u16)res);
    func_0216D8C0(func_021A3074(obj), &v);
    if (id == 0)
        func_021A322C(obj);
}
