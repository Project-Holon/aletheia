/*
 * file:     trial_house_p13.c
 * unit:     yes
 * function: func_021CFFDC, func_021D0014, func_021D004C, func_021D0084, func_021D00B8, func_021D0114, func_021D0140, func_021D0160, func_021D0174, func_021D01D8, func_021D0218, func_021D024C, func_021D028C, func_021D029C, func_021D0308
 * address:  0x021CFFDC
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
 *   func_02009470  0x02009470  thumb
 *   sub_020095FC  0x020095FC  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   sub_02009618  0x02009618  thumb
 *   func_02009628  0x02009628  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021CFC4C  0x021CFC4C  thumb  ov021
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02012F38  0x02012F38  thumb
 *   func_02011330  0x02011330  thumb
 *   func_021CFD08  0x021CFD08  thumb  ov021
 *   func_0200856C  0x0200856C  thumb
 *   func_02012944  0x02012944  thumb
 *   d_021DE608     0x021DE608  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   data_021DB8C4  0x021DB8C4  data  a2
 *   data_021DB8CC  0x021DB8CC  data  a2
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021DB8DC     0x021DB8DC  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1E0  0x021AC1E0  thumb
 *   func_02047804  0x02047804  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 */
#include "../../matched/include/Obj06104.h"

struct Big;
struct Ctx;
struct Sub02009470Obj;
struct Stream;
struct Sub0200852CObj;
struct Rec;
struct Tagged;
struct B;
struct AnmCtl;
struct G3dSys;
struct Owner;
struct G3dOwner;
struct G3dRec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct B {
    u32 f0;
    u32 f4[4 + 4];
    u32 f24[4];
    u32 f34[8];
} B;

typedef struct Arg021D0218 {
    u32 h;
    u32 v;
} Arg021D0218;

typedef struct {
    int pad[9];
    int a24[4];
    int a34[1];
} Tbl;

typedef struct {
    Tbl *tbl;
    int cnt;
} Src;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    Src src;
    int obj;
    int sub[4];
} Dst;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern unsigned int func_02159B10(void *a, void *b);
extern void sub_020095FC(struct Sub02009470Obj *obj, int value);
extern void sub_02009618(struct Sub02009470Obj *obj, int value);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern int func_021CFC4C(void *, int, void *);
extern void *func_02158F74(void *p);
extern int func_02012F38(int base);
extern u16 func_02011330(struct Stream *s);
extern int func_021CFD08(u32 a, u32 b, u8 *c, int d, u32 e);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *b, u32 c, u32 d, void *e, u32 f);
extern int func_021AC1E0(u32 a);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern int func_020477D4(struct Owner *owner, u32 index);
extern int func_021AC1AC(u32 a);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
int func_021CFFDC(u32 a, u32 b);
int func_021D0014(u32 a, u32 b);
int func_021D004C(u32 a, u32 b);
int func_021D0084(u32 a, u32 b, u32 c, u32 d);
int func_021D00B8(u32 a, u32 b);
int func_021D0114(u32 a, u32 b);
void *func_021D0140(u32 v, u32 heap);
void func_021D0160(u32 a, u8 *p);
void func_021D0174(B *p, int i);
void func_021D01D8(u32 *p);
void func_021D0218(void *a, u32 v, u32 c);
void func_021D024C(void *obj, u32 sel);
void func_021D028C(void *obj, u32 v);
void func_021D029C(void *p, Dst *d);
void func_021D0308(void *unused, u32 *p);
extern char d_021DE608[];
extern const u16 data_021DB8CC[];
extern const u16 data_021DB8C4[];
extern char d_021DB8DC[];


int func_021CFFDC(u32 a, u32 b)
{
    void *x;
    u8 v;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    v = func_02159B10((void *)a, (void *)b);
    sub_020095FC(func_02009470(func_02012EBC(func_020120F4((void *)x))), v);
    return 0;
}


int func_021D0014(u32 a, u32 b)
{
    void *x;
    u8 v;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    v = func_02159B10((void *)a, (void *)b);
    sub_02009618(func_02009470(func_02012EBC(func_020120F4((void *)x))), v);
    return 0;
}


int func_021D004C(u32 a, u32 b)
{
    void *x;
    u16 *q;

    func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    q = func_02159AE8((void *)a, (void *)b);
    *q = func_02009628(func_02009470(func_02012EBC(func_020120F4((void *)x))));
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D0084(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4((void *)b);
func_021CFC4C(func_0215A5DC((void *)b), func_02159B10((void *)a, (void *)b), (void *)func_02159B10((void *)a, (void *)b));
return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021D00B8(u32 a, u32 b)
{
    u32 s, k, g;
    void *p;
    void *x;
    u8 *f;
    u16 *out;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    f = (u8 *)func_02012F38((int)func_020120F4(x));
    s = (u32)func_02158F74(p);
    k = func_02159B10((void *)a, (void *)b);
    g = func_02011330((struct Stream *)a);
    out = func_02159AE8((void *)a, (void *)b);
    *out = func_021CFD08(s, (u32)x, f, k, g);
    return 0;
}


int func_021D0114(u32 a, u32 b)
{
    u16 *q = func_02159AE8((void *)a, (void *)b);

    *q = func_0200856C((const struct Sub0200852CObj *)func_02012944(func_020120F4((void *)func_0215A5DC((void *)b)))) != 0 ? 1 : 0;
    return 0;
}


void *func_021D0140(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0x54, 1, d_021DE608, 0x5f);

    p[0] = v;
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021D0160(u32 a, u8 *p)
{
    func_021D01D8((u32 *)p);
    func_020307B0(p);
}


void func_021D0174(B *p, int i)
{
    u32 x;
    const u16 *s;
    const u16 *t;
    int j;

    x = func_021ABE24((u8 *)p->f0);
    s = data_021DB8CC;
    if (p->f4[i] == 0) {
        p->f4[i] = (u32)func_02046E24(x, s[i]);
        func_02046FF8((int *)p->f4[i]);
        p->f34[i] = (u32)func_02047400((void *)p->f4[i], 0, (void *)p->f4[i]);
    }
    t = data_021DB8C4;
    for (j = 0; j < 4; j++, t++) {
        if (p->f24[j] == 0) {
            p->f24[j] = (u32)func_02046E24(x, *t);
        }
    }
}


void func_021D01D8(u32 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (p[1 + i] != 0) {
            func_02047504((struct Rec *)p[13 + i]);
            func_020470D0((u32 *)p[1 + i]);
            func_02046EFC((struct Tagged *)p[1 + i]);
        }
    }
    for (i = 0; i < 4; i++) {
        if (p[9 + i] != 0) {
            func_02046EFC((struct Tagged *)p[9 + i]);
        }
    }
}


void func_021D0218(void *a, u32 v, u32 c)
{
    Arg021D0218 arg;

    arg.h = func_021ABEA0((u32)a, 0xe);
    arg.v = v;
    func_021D0174((struct B *)arg.h, v);
    func_021ABFA8(a, d_021DB8DC, c, 0, &arg, 0);
}


/*
 * Highlights button sel of four and records it.
 *
 * Addresses are Black-image addresses.
 */
void func_021D024C(void *obj, u32 sel)
{
    int i;
    u8 *q;

    if (obj == 0)
        return;
    q = (u8 *)func_021AC1E0((u32)obj);
    for (i = 0; i < 4; i++) {
        func_02047804((struct AnmCtl *)(((struct Obj06104 *)q)->fC), (u16)i);
        if (i == sel)
            func_020477A4((struct G3dSys *)(((struct Obj06104 *)q)->fC), (u16)i);
        else
            func_020477D4((struct Owner *)(((struct Obj06104 *)q)->fC), (u16)i);
    }
    q[2] = sel;
    q[3] = 0;
}


/*
 * Stores v at +1 of the object's state.
 *
 * Addresses are Black-image addresses.
 */
void func_021D028C(void *obj, u32 v)
{
    if (obj != 0)
        ((u8 *)func_021AC1E0((u32)obj))[1] = v;
}


void func_021D029C(void *p, Dst *d)
{
    Src *s;
    Tbl *tbl;
    int cnt;
    int j;
    int i;

    s = (Src *)func_021AC1AC((u32)p);
    d->src = *s;
    tbl = d->src.tbl;
    cnt = d->src.cnt;
    for (i = 0; i < 4; i++)
        d->sub[i] = (int)func_02047564((struct G3dOwner *)tbl->a34[cnt], (const struct G3dOwner *)tbl->a24[i], 0);
    d->f2 = 4;
    d->obj = (int)func_0204767C((int)tbl->a34[cnt], (u32 *)d->sub, 4);
    for (j = 0; j < 4; j++)
        func_020477D4((struct Owner *)d->obj, (u16)j);
}


void func_021D0308(void *unused, u32 *p)
{
    int i;

    func_02047738((struct Rec *)p[3]);
    for (i = 0; i < 4; i++) {
        func_0204762C((struct Rec *)p[4 + i]);
    }
}
