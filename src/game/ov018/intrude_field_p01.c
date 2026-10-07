/*
 * file:     intrude_field_p01.c
 * unit:     yes
 * function: func_0217AE20, func_0217AFC4, func_0217B044, func_0217B084, func_0217B1DC
 * address:  0x0217AE20
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
 *   func_02012138  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02026454  0x02026454  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0217B968  0x0217B968  thumb  ov018
 *   func_0217BBD8  0x0217BBD8  thumb  ov018
 *   func_0217C11C  0x0217C11C  thumb  ov018
 *   func_0217BAB4  0x0217BAB4  thumb  ov018
 *   func_02175004  0x02175004  thumb  ov011
 *   func_02175598  0x02175598  thumb  ov011
 *   func_02167590  0x02167590  thumb  ov010
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *   func_02167848  0x02167848  thumb  ov010
 *   func_021679C4  0x021679C4  thumb  ov010
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0217B214 0x0217B214 thumb ov018
 */
#include "../../matched/include/Obj09386.h"

struct Ctx;
struct SaveBlock;
struct Sub24;
struct Rec44;
struct Work;
struct BigObj;
struct Src;
struct Desc;
struct Obj;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int f0;
    u8 pad4[0x12];
    u16 lo : 9;
    u16 mode : 6;
    u16 hi : 1;
    u16 f18;
    u16 pad1a;
} Rec;

typedef struct {
    u8 a : 2;
    u8 state : 2;
    u8 rest : 4;
} Flags;

typedef struct {
    u8 pad0[8];
    int f8;
    u8 padc[0x78];
    u16 f84;
    u8 pad86[6];
    Rec recs[3];
    u8 padE0[0x81B];
    u8 f8fb;
    u8 pad8fc;
    u8 f8fd;
    u8 pad8fe[6];
    Flags f904;
    u8 pad905[0xB];
    u8 f910;
} Obj_0217AE20;

typedef short s16;

typedef struct {
    int f00;
    void *f04;
    int pad[2];
    int f10;
    u16 f14;
    u16 f16;
} Task;

typedef struct {
    unsigned char *f0;
    int f4;
    int f8;
    int fc;
    int f10;
    u16 f14;
} Obj_0217B084;

extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *obj);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012E40(const u8 *o);
extern u32 func_02026454(void *obj);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
extern u32 func_0200FB24(void);
extern int func_02012B70(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_0217B968(int a0, void *a1, void *a2, void *a3);
extern void func_0217BBD8(u8 *a, int b, u8 *c);
extern int func_0217C11C(u32 value);
extern void func_0217BAB4(int a0, void *a1, void *a2, u8 *p);
extern void func_02175004(u8 *p);
extern u16 func_02175598(u8 *o, u32 id);
extern void func_02167590(void *a, struct Work *w);
extern int func_021677E4(void *p, int i);
extern void func_021675D0(struct Work *w, int idx, int a2, struct Src *src);
extern void func_02167848(char *a0, int a1, char *a2);
extern int func_021679C4(struct Work *w, int i);
extern unsigned int func_021A3098(u8 *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern int func_021679A4(int, int, int, int, int *, int *);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D3CC(int a0);
extern u16 func_0216D5F8(void *p);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);
extern int func_0216D480(char *p);
extern void func_0216D9A0(void *map);
extern u32 *func_0216D9E4(void *c);
extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern int func_021907A8();
extern int func_0219077C(u8 *p);
extern void func_02190788(u8 *p);
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern int func_02190728(void *a);
extern u32 func_020362DC(void);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0217B214();
extern void func_02082BCC(void *, int, int);
void func_0217AE20(u8 *a0, int a1, int a2);
int func_0217AFC4(int *a, u8 *b, int *out);
void *func_0217B044(void *a, int b, int c, u16 d, u16 e, int f);
int func_0217B084(int a0, int *state, Obj_0217B084 *o, u32 a3);
void *func_0217B1DC(void *a, int b, int c, unsigned short d);


void func_0217AE20(u8 *a0, int a1, int a2)
{
    int h;
    Obj_0217AE20 *p;
    void *ctx;
    int skip;
    int i;
    int r;

    h = func_02012138((const struct Ctx *)a1);
    p = (Obj_0217AE20 *)func_02026474((void *)h);
    ctx = func_020120F4((const struct Ctx *)a1);
    if (func_02012E40(ctx) == 1)
        return;
    func_0217B968((int)a0, (void *)a1, (void *)h, (void *)a2);
    if (func_02026454((void *)h) != 2 || p == 0)
        return;
    h = func_02012AC8(func_020127A4(ctx));
    if (p->f910 == 0 && func_02013D5C(h) == 1)
        p->f910 = 1;
    func_0217BBD8(a0, a1, (u8 *)p);
    if (p->f8fd != 7 || func_0200FB24() != 0)
        return;
    if (func_02012B70(ctx) == 0) {
        if (p->f904.state == 0) {
            if (func_0217C11C(p->f84) == 1)
                p->f904.state = 1;
            else
                p->f904.state = 2;
        }
        if (p->f904.state == 2)
            return;
    }
    skip = func_02012B58(ctx);
    func_02175004((u8 *)p);
    func_02167590((void *)a1, (struct Work *)p->f8);
    for (i = 0; i < 3; i++) {
        if (i == skip || !(p->f8fb & (1 << i)))
            continue;
        if (func_021677E4((void *)p->f8, i) == 0) {
            func_02012950(ctx, i);
            r = func_02175598((u8 *)(&p->recs[i]), (u32)func_02012950(ctx, i));
            if (p->recs[i].f18 != 0 || func_02012B70(ctx) != 0)
                func_021675D0((struct Work *)p->f8, i, r, (struct Src *)(&p->recs[i]));
        } else {
            func_02167848((char *)p->f8, i, (char *)(&p->recs[i]));
            if (p->recs[i].f0 == 0) {
                if ((u16)(p->recs[i].mode + 0xFFFE) <= 1)
                    func_021679C4((struct Work *)p->f8, i);
            }
        }
    }
    func_0217BAB4((int)a0, (void *)a1, (void *)a2, (u8 *)p);
}


int func_0217AFC4(int *a, u8 *b, int *out)
{
    int r;
    int idx;
    int hit;
    int ret;
    s16 v[3];

    ret = 0;
    hit = ret;
    if (a == 0 || a[2] == 0)
        return 0;
    r = func_021A3098(b);
    if (r != 0 && r != 1)
        return ret;
    func_021A3460((u32)b, (u32)(v + 2), (u32)(v + 1), (u32)v);
    for (;;) {
        r = func_021679A4(a[2], v[2], v[1], v[0], &idx, &hit);
        if (r != 1)
            break;
        if (*(int *)((char *)a + idx * 28 + 0x8c) == 0) {
            *out = idx;
            return 1;
        }
    }
    return 0;
}


void *func_0217B044(void *a, int b, int c, u16 d, u16 e, int f)
{
    void *t;
    Task *p;

    t = func_020122C0(a, 0, func_0217B084, sizeof(Task));
    p = func_020124E8(t);
    MI_CpuFill8(p, 0, sizeof(Task));
    p->f00 = b;
    p->f04 = func_021A3074((void *)c);
    p->f16 = d;
    p->f14 = e;
    p->f10 = f;
    return t;
}


int func_0217B084(int a0, int *state, Obj_0217B084 *o, u32 a3)
{
    u16 m;
    int t;
    int h;

    switch (*state) {
    case 0:
        if (func_0216D3CC(o->f4) == 1) {
            if (o->f14 == 3)
                t = 3;
            else
                t = 2;
            m = t;
            if (o->f14 != func_0216D5F8((void *)o->f4)) {
                func_0216D410((void *)o->f4, m);
                *state += 1;
            } else {
                *state = 2;
            }
        }
        break;
    case 1:
        if (func_0216D454(o->f4, (u32)state, (u32)o, a3) == 1) {
            func_0216D480((char *)o->f4);
            *state += 1;
        }
        break;
    case 2:
        func_0216D9A0(func_02188C7C(o->f0));
        h = func_02188C54(o->f0);
        o->f8 = func_021904B0(h, 0x2D);
        o->fc = func_021907A8(h, o->f8);
        func_02190740(o->fc, 0, 0, o->f10 == 0 ? 0x52 : 0x4F);
        *state += 1;
        break;
    case 3:
        if (func_0219077C((u8 *)o->fc) == 1)
            *state += 1;
        break;
    case 4:
        if (o->f10 == 0) {
            if (func_020362DC() & 3)
                *state += 1;
        } else {
            if (func_020362DC() & 0xF3)
                *state = 8;
        }
        break;
    case 5:
        func_02190788((u8 *)o->fc);
        func_02190740(o->fc, 0, 0, 0x53);
        *state += 1;
        break;
    case 6:
        if (func_0219077C((u8 *)o->fc) == 1)
            *state += 1;
        break;
    case 7:
        if (func_020362DC() & 0xF3)
            *state += 1;
        break;
    case 8:
        func_02190728((void *)o->fc);
        func_02045C04((struct Rec *)o->f8);
        *state += 1;
        break;
    case 9:
        if (func_0216D3CC(o->f4) == 1) {
            func_0216D410((void *)o->f4, (u16)(o->f14 == 3 ? 10 : 11));
            *state += 1;
        }
        break;
    case 10:
        if (func_0216D454(o->f4, (u32)state, (u32)o, a3) == 1) {
            func_0216D480((char *)o->f4);
            func_0216D9E4(func_02188C7C(o->f0));
            return 1;
        }
        break;
    }
    return 0;
}

void *func_0217B1DC(void *a, int b, int c, unsigned short d) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, func_0217B214, 0x30);
    p = func_020124E8(t);
    func_02082BCC(p, 0, 0x30);
    ((struct Obj09386 *)p)->f0 = b;
    ((struct Obj09386 *)p)->f4 = (int)func_021A3074((u8 *)c);
    ((struct Obj09386 *)p)->f14 = d;
    return t;
}
