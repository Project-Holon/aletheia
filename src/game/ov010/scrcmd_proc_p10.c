/*
 * file:     scrcmd_proc_p10.c
 * unit:     yes
 * function: func_0215CDB8, func_0215CDF0, func_0215CE70, func_0215CE98, func_0215CEBC, func_0215CEE8, func_0215CF00, func_0215CF54, func_0215CF84, func_0215CFB4, func_0215CFD8, func_0215CFFC, func_0215D034, func_0215D06C, func_0215D0A4, func_0215D0D4, func_0215D110, func_0215D14C, func_0215D198, func_0215D1E4, func_0215D2A4
 * address:  0x0215CDB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021F3724 0x021F3724 thumb ov037
 *   ov037_id 0x00000025 data a1
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021F3768  0x021F3768  thumb  ov037
 *   func_021F3800 0x021F3800 thumb ov037
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3400  0x021C3400  thumb  ov021
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02012934 0x02012934 thumb
 *   func_021C32F4 0x021C32F4 thumb ov021
 *   func_021C335C  0x021C335C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021C3204 0x021C3204 thumb ov021
 *   func_021C3270 0x021C3270 thumb ov021
 *   func_021C340C  0x021C340C  thumb
 *   func_021C34C4  0x021C34C4  thumb
 *   func_021C34F8 0x021C34F8 thumb ov021
 *   func_02017E1C 0x02017E1C thumb
 *   func_021C341C 0x021C341C thumb ov021
 *   func_021C3490 0x021C3490 thumb ov021
 *   func_021C34B4 0x021C34B4 thumb ov021
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_02172900     0x02172900  data
 */
#include "../../matched/include/Obj17693.h"
#include "../../matched/include/Obj17694.h"
#include "../../matched/include/Obj17695.h"

struct Ctx;
struct BigObj;
struct Big;
struct Evt;
struct Desc;
struct Obj;
struct Blk37;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u32 pad[15]; u32 f3c; } O8;

typedef struct { u8 pad[15]; u8 fF; } OC;

typedef struct {
    void *f0;
    void *f4;
    O8 *f8;
    OC *fC;
    u16 *f10;
} Ctx_0215D1E4;

typedef struct {
    void *f00;
    u32 pad04[2];
    u32 f0c;
    u32 pad10[9];
    u32 f34;
    u32 f38;
    u32 f3c;
} A;

typedef struct {
    void *f00;
    u32 f04;
    u32 f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
    u8 f10;
    u8 pad11[7];
    u32 f18;
} B;

typedef struct {
    void *f0;
    u32 f4;
    A *f8;
    B *fC;
    u32 f10;
} Ctx_0215D2A4;

extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void func_021F3724(unsigned int a0, int a1);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern void func_021F3768(unsigned int a0, unsigned short **a1);
extern void func_021F3800(unsigned int a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D50(void *a0);
extern int func_021C3400(void *a);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(const struct BigObj *p);
extern void func_021C32F4(unsigned int *, unsigned int);
extern void func_021C335C(void **p);
extern void *func_0215A5F4(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BDB0(void *);
extern void func_0215897C(void *, void *);
extern void func_021C3204(unsigned int *, unsigned int, unsigned int);
extern void func_021C3270(unsigned int *, unsigned int, unsigned int);
extern int func_021C340C();
extern u8 func_021C34C4(void **p);
extern void *func_021C34F8(void *, unsigned int);
extern unsigned int func_02017E1C(void *, unsigned int, unsigned int);
extern int func_021C341C(unsigned int *, unsigned int);
extern int func_021C3490(void **,int);
extern int func_021C34B4(void **,int);
extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *);
extern u32 func_020307B0(void *p);
extern void *func_020120F4(const struct Ctx_0215D2A4 *p);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0201AA18(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
int func_0215CDB8(void *a, void *b);
int func_0215CDF0(void *a, void *b);
int func_0215CE70(void *a, void *b);
int func_0215CE98(int a0, int a1);
int func_0215CEBC(void *a, void *b);
int func_0215CEE8(int a0, int a1);
int func_0215CF00(void *a, void *b);
int func_0215CF54(void *a, void *b);
int func_0215CF84(void *a, void *b);
int func_0215CFB4(int a0, int a1);
int func_0215CFD8(int a0, int a1);
int func_0215CFFC(void *a, void *b);
int func_0215D034(void *a, void *b);
int func_0215D06C(void *a, void *b);
int func_0215D0A4(void *a, void *b);
int func_0215D0D4(void *a,void *b);
int func_0215D110(void *a,void *b);
int func_0215D14C(void *a, void *b);
int func_0215D198(void *x);
int func_0215D1E4(void *a, u32 *st, Ctx_0215D1E4 *c);
void *func_0215D2A4(void *a, u32 b, u32 c);
extern char ov037_id[];
extern const char d_02172900[];


int func_0215CDB8(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    int v = func_02159B10(a, b);
    func_02034AC4((int)ov037_id);
    func_021F3724((unsigned int)p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}


int func_0215CDF0(void *a, void *b)
{
    unsigned short *v[8];
    void *h = func_0215A5DC(b);
    v[0] = func_02159AE8(a, b);
    v[1] = func_02159AE8(a, b);
    v[2] = func_02159AE8(a, b);
    v[3] = func_02159AE8(a, b);
    v[4] = func_02159AE8(a, b);
    v[5] = func_02159AE8(a, b);
    v[6] = func_02159AE8(a, b);
    v[7] = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F3768((unsigned int)h, v);
    func_02034A5C((u32)ov037_id);
    return 0;
}


int func_0215CE70(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    func_02034AC4((int)ov037_id);
    func_021F3800((unsigned int)p);
    func_02034A5C((int)ov037_id);
    return 0;
}


/*
 * unblocked: func_021C3400 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 */
int func_0215CE98(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CEA0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CEA8:
    v2 = func_0201210C(v1);
loc_0215CEAC:
    a0 = func_021C3400(func_02188D50(v2));
loc_0215CEB0:
loc_0215CEB4:
((struct Obj17693 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}


int func_0215CEBC(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C32F4(func_02188D50(func_0201210C(p)), (unsigned int)q);
    return 0;
}


int func_0215CEE8(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215CEF0:
    v1 = func_0201210C(v0);
loc_0215CEF4:
    func_021C335C((void **)func_02188D50(v1));
loc_0215CEF8:
loc_0215CEFC:
a0 = 0;
    return a0;}


int func_0215CF00(void *a, void *b)
{
    void *t = func_0215A5F4(b);
    unsigned short *v = func_02159AE8(a, b);
    void *p = func_0215A5E4(b);
    void *h = func_0215A5DC(b);
    void *s = func_0201210C(h);
    func_02012934(p);
    func_0200BDB0(func_02012EBC(p));
    func_0215897C(t, func_0215D2A4(h, (u32)s, (u32)v));
    return 1;
}


int func_0215CF54(void *a, void *b)
{
    int v = func_02159B10(a, b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C3204(func_02188D50(func_0201210C(func_0215A5DC(b))), (unsigned int)q, v);
    return 0;
}


int func_0215CF84(void *a, void *b)
{
    int v = func_02159B10(a, b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C3270(func_02188D50(func_0201210C(func_0215A5DC(b))), v, (unsigned int)q);
    return 0;
}


int func_0215CFB4(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFBC:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFC4:
    v2 = func_0201210C(v1);
loc_0215CFC8:
    a0 = func_021C340C(func_02188D50(v2));
loc_0215CFCC:
loc_0215CFD0:
((struct Obj17694 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}


int func_0215CFD8(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFE0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFE8:
    v2 = func_0201210C(v1);
loc_0215CFEC:
    a0 = func_021C34C4((void **)func_02188D50(v2));
loc_0215CFF0:
loc_0215CFF4:
((struct Obj17695 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}


/*
 * interface: func_021C34F8 has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 */
int func_0215CFFC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 5, 0);

    return 0;
}


int func_0215D034(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 111, 0);

    return 0;
}


int func_0215D06C(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 110, 0);

    return 0;
}


int func_0215D0A4(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    *p = func_021C341C(func_02188D50(func_0201210C(func_0215A5DC(b))), v);

    return 0;
}

int func_0215D0D4(void *a,void *b)
{
 u16 *p = func_02159AE8(a,b);
 int i = func_02159B10(a,b);
 void **q = func_02188D50(func_0201210C(func_0215A5DC(b)));
 func_021C34F8(q,i);
 *p = func_021C3490(q,i);
 return 0;
}

int func_0215D110(void *a,void *b)
{
 u16 *p = func_02159AE8(a,b);
 int i = func_02159B10(a,b);
 void **q = func_02188D50(func_0201210C(func_0215A5DC(b)));
 func_021C34F8(q,i);
 *p = func_021C34B4(q,i);
 return 0;
}


int func_0215D14C(void *a, void *b)
{
    int f;
    u16 *p;
    void *r;
    void *s = func_02188D50(func_0201210C(func_0215A5DC(b)));
    p = func_02159AE8(a, b);
    f = func_02159B10(a, b);
    r = func_021C34F8(s, func_02159B10(a, b));
    if (f == 0)
        *p = func_0215D198(r);
    else
        *p = 0;
    return 0;
}


int func_0215D198(void *x)
{
    int a = func_02017E1C(x, 5, 0);
    int b = func_02017E1C(x, 0x6e, 0);
    if (a == 0x20 || a == 0x1d) {
        a = 0;
        if (func_02017E1C(x, 0x75, 0) == 0)
            return a;
    }
    switch (b) {
    case 2:
    default: return 0;
    case 0: return 1;
    case 1: return 2;
    }
}


int func_0215D1E4(void *a, u32 *st, Ctx_0215D1E4 *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    switch (s) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)func_020144DC((int)p0, (int)c->f4));
        c->f8->f3c = c->fC->fF;
        *st = 2;
        break;
    case 2:
        func_02012374(a, func_02014910(p0, (int)c->f4, (int)c->f8, (int)c->fC));
        *st = 3;
        break;
    case 3:
        func_02012374(a, func_020145CC(p0));
        *st = 4;
        break;
    case 4:
        func_02012374(a, func_021BE92C(p0, c->f4, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        *c->f10 = c->f8->f3c;
        func_020307B0(c->f8);
        func_020307B0(c->fC);
        return 1;
    }
    return 0;
}


void *func_0215D2A4(void *a, u32 b, u32 c)
{
    void *r7 = func_020120F4(a);
    void *v = func_02012934(r7);
    u32 w = (u32)func_0200CA1C(r7);
    A *x = func_02030734(4, 0x98, 0, d_02172900, 0x22B);
    B *y;
    Ctx_0215D2A4 *ctx;
    void *h;
    x->f00 = v;
    x->f34 = 0x12;
    x->f38 = 0;
    x->f3c = 0;
    y = func_02030734(4, 0x28, 0, d_02172900, 0x232);
    y->f00 = x->f00;
    y->f04 = x->f0c;
    y->f08 = (u32)r7;
    y->f0c = 1;
    y->f0e = func_0201AA18(v);
    y->f0d = 0;
    y->f10 = 0;
    y->f0f = 0;
    y->f18 = func_0200CA38((struct Blk37 *)w);
    h = func_020122C0(a, 0, (void *)func_0215D1E4, 0x14);
    ctx = func_020124E8(h);
    ctx->f0 = a;
    ctx->f4 = b;
    ctx->f8 = x;
    ctx->fC = y;
    ctx->f10 = c;
    return h;
}
