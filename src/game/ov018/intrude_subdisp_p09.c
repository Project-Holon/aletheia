/*
 * file:     intrude_subdisp_p09.c
 * unit:     yes
 * function: func_0218034C, func_021803F0, func_021804F8, func_02180538, func_021808C4, func_021808E8, func_02180978, func_02180980, func_021809A4, func_02180B14, func_02180B38, func_02180BDC, func_02180C00, func_02180CA4, func_02180CC8, func_02180DE8, func_02180E0C, func_02180EB0, func_02180ED4, func_02180FA8, func_02180FCC, func_0218111C, func_02181140, func_021811E4
 * address:  0x0218034C
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
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021829F8  0x021829F8  thumb ov018
 *   d_02183B30  0x02183B30  data ov018 a1
 *   d_02183B44  0x02183B44  data ov018 a1
 *   d_021837C4  0x021837C4  data ov018 a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175DCC  0x02175DCC  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217620C  0x0217620C  thumb  ov011
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188C84  0x02188C84  thumb ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_021756A4  0x021756A4  thumb  ov011
 *   func_0217F2B4  0x0217F2B4  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02175DE4  0x02175DE4  thumb  ov011
 *   func_0200BE24  0x0200BE24  thumb
 *   func_0200BE00  0x0200BE00  thumb
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0217F528  0x0217F528  thumb
 *   func_0217F574  0x0217F574  thumb
 *   func_0217F58C  0x0217F58C  thumb
 *   func_0217F4A0  0x0217F4A0  thumb
 *   func_02029830  0x02029830  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0200823C  0x0200823C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF78  0x0200BF78  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_0217CA84  0x0217CA84  thumb
 *   func_0201235C  0x0201235C  thumb
 *   str_02183B48   0x02183B48  data   ov018  a1
 *   func_0201232C 0x0201232C thumb
 *   func_02082D44 0x02082D44 arm
 *   func_02158344  0x02158344  thumb ov010
 *   func_02012950  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0217F420  0x0217F420  thumb ov018
 *   func_0217FE38  0x0217FE38  thumb ov018
 *   d_0218383C     0x0218383C  data ov018 a2
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_02012944  0x02012944  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_020061E4  0x020061E4  thumb
 *   d_02183870     0x02183870  data   a2
 *   d_0218387A     0x0218387A  data   a2
 *   d_02183884     0x02183884  data   a2
 *   d_02183848     0x02183848  data ov018 a2
 *   d_02183866     0x02183866  data ov018 a2
 *   func_020124AC  0x020124AC  thumb
 *   func_021F5260  0x021F5260  thumb  ov083
 *   ov083_id       0x00000053  data
 *   d_02183852     0x02183852  data   a2
 *   d_0218385C     0x0218385C  data   a2
 *   d_021838B8     0x021838B8  data ov018 a2
 *   d_02183890     0x02183890  data  a2
 *   d_021838A4     0x021838A4  data  a2
 *   d_021838AE     0x021838AE  data  a2
 *   d_0218389A     0x0218389A  data ov018 a2
 *   func_0218123C  0x0218123C  thumb  ov018
 */
#include "../../matched/include/Obj12503.h"
#include "../../matched/include/Obj19375.h"
#include "../../matched/include/Obj12504.h"
#include "../../matched/include/Obj09400.h"
#include "../../matched/include/Obj05933.h"
#include "../../matched/include/Obj05935.h"
#include "../../matched/include/Obj05937.h"
#include "../../matched/include/Obj05940.h"
#include "../../matched/include/Obj05941.h"

struct Ctx;
struct BigObj;
struct Desc;
struct Obj;
struct Big;
struct Evt;
struct Rec1B0;
struct S0201235C;
struct WordSet;
struct Rec44;
struct Sub24;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u8 pad : 5; u8 f : 1; u8 rest : 2; } Bf;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    u32 f00;
    u32 lo : 4;
    u32 mid : 14;
    u32 f18 : 11;
    u32 hi : 3;
    u8 rest[0x3C - 8];
} Rec3C;

typedef struct {
    u16 f00;            /* 0x00 */
    u16 pad02;
    Ov018Obj obj;       /* 0x04 */
    void *f34;          /* 0x34 */
    u8 pad38[0xEC - 0x38];
    Rec3C fEC;          /* 0xEC */
    u16 f128;           /* 0x128 */
    u16 f12A;           /* 0x12A */
    int f12C;           /* 0x12C */
    u32 f130;           /* 0x130 */
    u8 f134;            /* 0x134 */
    u8 f135;            /* 0x135 */
    u16 f136;           /* 0x136 */
} Outer_0218034C;

typedef struct {
    u8 f0 : 1;
    u8 rest : 7;
} B1;

typedef signed int     s32;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
} Outer_021809A4;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0xA0 - 0x78]; /* 0x78 */
    int fA0;            /* 0xA0 */
} Outer;

typedef struct {
    u32 a;
    u32 zero;
} Args;

typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[4];          /* 0x78 */
} Ov018Outer_0218034C;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
} Ov018Outer_02180FA8;

typedef struct {
    u8 pad00[0x40];
    u8 f40;
    u8 pad41[0x17];
    u16 f58;
} Ov018Src;

void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
void func_02034714(const char *expr, u32 line, const char *file);
void MI_CpuCopy8(const void *src, void *dst, unsigned int n);
void func_021829F8(void *a, void *b);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_02175DCC(void *p);
extern u8 *func_02175BCC(u8 *p);
extern int func_02175B14(u8 *);
extern int func_02175B8C(u8 *);
extern int func_0217620C(u8 *, int);
void *func_0201210C(const struct Ctx *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02082BCC(void *p, int v, int n);
u16 func_02188C84(u8 *p);
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
u32 func_02026454(void *);
u32 func_02026474(void *obj);
u32 func_0200FB24(void);
int func_02175E90(void *p, u8 *q);
int func_02175DA8(u8 *);
u8 func_021756A4(char *p);
void func_0217F2B4(Ov018Obj *p, void *sub);
void *func_020127B8(void *);
int func_02175DE4(void *p, u8 *a1);
void func_0200BE24(struct Rec1B0 *p, s32 v);
void func_0200BE00(struct Rec1B0 *p, s32 v);
void func_021762D8(void *, void *, void *, u32);
void func_0217F528(Ov018Obj *p, void *sub, int b, int c, int d, int e);
void func_0217F574(void **p, unsigned int index, int a, int b);
void func_0217F58C(Ov018Obj *p);
void func_0217F4A0(void **p, unsigned int index, int a, int b);
void *func_02029830(void *a, u32 b);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_02005F38(void);
void *func_02029620(void *a, u32 b, u32 c);
void *func_0201292C(const struct BigObj *p);
u32 func_02007FB8(u8 *base, u16 id, u16 d);
u32 func_0200823C(u32 a);
u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *sys);
u32 func_0200BF78(struct Rec1B0 *p);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
void func_0217F318(Ov018Obj *p);
int func_0217CA84(void *a, int b);
void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_0201232C(char *p, int a1, int a2);
extern void func_02082D44(const void *, void *, u32);
int func_02158344(int a0);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
int func_0217F420(void);
void func_0217FE38(void *m, u8 *obj);
int func_0217405C(char *a, char *b);
int func_02175CF4(char *p, u8 *q);
u8 *func_02012944(void *p);
void func_0201F184(struct WordSet *p, u32 i, s32 v);
void func_020061E4(u32 a);
struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
void *func_021F5260(void *a0, int *a1);
int func_0218123C(void);
void func_0218034C(int x, u8 *y);
int func_021803F0(u8 *a, u8 *b);
void *func_021804F8(void *p, int a);
int func_02180538(void *a, int *state, Outer_0218034C *c);
void func_021808C4(void *task, const void *src);
int func_021808E8(int x, int *st, u8 *obj);
void func_02180978(int id, void *dst);
void func_02180980(void *task, const void *src);
int func_021809A4(void *a, int *state, Outer_021809A4 *c);
void func_02180B14(void *task, const void *src);
int func_02180B38(int x, int *st, u8 *obj);
void func_02180BDC(void *task, const void *src);
int func_02180C00(int x, int *st, u8 *obj);
void func_02180CA4(void *task, const void *src);
int func_02180CC8(void *a, int *state, Outer *c);
void func_02180DE8(Obj *task, const void *src);
int func_02180E0C(int x, int *st, u8 *obj);
void func_02180EB0(Obj *task, const void *src);
int func_02180ED4(void *a, int *state, Ov018Outer_0218034C *c);
void func_02180FA8(Obj *task, const void *src);
int func_02180FCC(void *a, int *state, Ov018Outer_02180FA8 *c);
void func_0218111C(Obj *task, const void *src);
int func_02181140(int x, int *st, u8 *obj);
void func_021811E4(void *a, Ov018Src *src);
extern char d_02183B30[];
extern char d_02183B44[];
extern char str_02183B48[];
extern u16 d_0218383C[];
extern u16 d_02183870[];
extern u16 d_0218387A[];
extern u16 d_02183884[];
extern u16 d_02183848[];
extern u16 d_02183866[];
extern u8 ov083_id[];
extern u16 d_02183852[];
extern u16 d_0218385C[];
extern u16 d_021838B8[];
extern const u16 d_02183890[];
extern const u16 d_021838A4[];
extern const u16 d_021838AE[];
extern u16 d_0218389A[];










extern void (*d_021837C4[])(int, void *);











void func_0218034C(int x, u8 *y)
{
    void *p = func_02030734((u16)((((struct Obj12503 *)y)->f0 & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x354);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        func_02180978(x, p);
    } else if (c == 1) {
        func_021829F8((void *)x, p);
    } else if (c == 2) {
        func_02180978(x, p);
    } else if (c >= 3) {
        if (d_021837C4[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_021837C4[y[0x41] - 8](x, p);
    } else {
        func_02180978(x, p);
    }
    func_020307B0(p);
}











static inline int state(u8 *a, u8 *b, u8 cur)
{
    if (func_02175BCC(b + 0x1AC) == 0 && func_02175B14(b + 0x1AC) == 1) {
        if (func_02175B8C(b + 0x1AC) == 1) {
            if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
                return 3;
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 4;
            return 5;
        }
        if (func_0217620C(b + 0x1AC, cur) == 1) {
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 6;
            return 7;
        }
        if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
            return 1;
        if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
            return 2;
        return 0;
    }
    return 0;
}











int func_021803F0(u8 *a, u8 *b)
{
    u8 cur;
    int kind;
    int r;

    cur = (int)func_02012B58((const struct BigObj *)((int)func_020120F4(func_02188C80(((struct Obj19375 *)a)->fC))));
    kind = func_02175DCC(b + 0x1AC);
    r = state(a, b, cur);
    if (r >= 3) {
        switch (kind) {
        case 0: r += 8; break;
        case 1: r += 13; break;
        case 2: r += 18; break;
        case 3: r += 23; break;
        case 4: r += 28; break;
        case 5: r += 33; break;
        }
        r -= 3;
    }
    return r;
}











void *func_021804F8(void *p, int a)
{
    void *v = func_0201210C(p);
    void *r = func_020122C0(p, 0, func_02180538, 0x138);
    u16 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x138);
    *q = func_02188C84(v);
    ((struct Obj12504 *)q)->f34 = a;
    return r;
}











/*
 * Task callback: a 13-state sequence driving the Ov018Obj at +0x04. State 0
 * waits for the link partner and snapshots its 0x3C-byte record into +0xEC.
 */
int func_02180538(void *a, int *state, Outer_0218034C *c)
{
    void *sub;
    void *t;
    void *w;
    u8 *v;
    Rec3C *e;
    void *h;
    void *m;
    u32 x;
    u32 n;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    w = func_020120F4(sub);
    func_0201210C(sub);
    switch (*state) {
    case 0:
        v = 0;
        if (func_02026454(t) == 2) {
            v = (u8 *)func_02026474(t);
        }
        if (c->f34 == 0) {
            if (v != 0 && func_0200FB24() == 0 && func_02175E90(v, v + 0x1AC) == 1) {
                ((B1 *)(v + 0x904))->f0 = 1;
            }
            return 1;
        }
        if (v != 0 && func_02175DA8(v + 0x1AC) == 1 && func_021756A4((char *)v) == 1) {
            if (func_02175E90(v, v + 0x1AC) == 0) {
                return 1;
            }
            c->f134 = v[0x358];
            c->f135 = v[0x359];
            func_0217F2B4(&c->obj, sub);
            e = (Rec3C *)func_02175BCC(v + 0x1AC);
            h = func_020127B8(w);
            if (e == 0) {
                func_02034714(str_02183B48, 0, str_02183B48);
            }
            c->fEC = *e;
            c->f128 = e->lo;
            c->f12A = e->f18;
            c->f12C = func_02175E90(v, v + 0x1AC);
            c->f130 = func_02175DE4(v, v + 0x1AC);
            func_0200BE24(h, c->f135);
            func_0200BE00(h, c->f134);
            (*state)++;
            break;
        }
        if (v == 0 || func_0200FB24() != 0) {
            return 1;
        }
        break;
    case 1:
        func_021762D8(&c->fEC, (u8 *)c + 0x104, c->obj.f00, c->f00);
        func_0217F528(&c->obj, sub, 1, 4, 0x1E, 0x10);
        func_0217F574((void **)(&c->obj), c->f128, 8, 0);
        func_0217F574((void **)(&c->obj), c->f12A, 8, 0x10);
        (*state)++;
        break;
    case 2:
        c->f136++;
        if (c->f136 > 60) {
            func_0217F58C(&c->obj);
            *state = 3;
        }
        break;
    case 3:
        if (c->f12C == 1) {
            func_0217F4A0((void **)(&c->obj), 0x19, 0, 0);
            func_02012374(a, func_02029830(sub, 0x52C));
            *state = 4;
        } else {
            func_0217F4A0((void **)(&c->obj), 0x17, 0, 0);
            func_02012374(a, func_02029830(sub, 0x52D));
            *state = 11;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(sub, 0, 6));
            m = func_0201292C(w);
            x = func_02007FB8(m, 0x23F, c->f00);
            n = c->f130;
            if (func_0200823C(0x23F) < x + n) {
                n = func_0200823C(0x23F) - x;
            }
            func_02007E50(m, 0x23F, n, c->f00);
            func_0200BF78((struct Rec1B0 *)func_0200BE48(func_02012EBC(w)));
            func_0201EFA4(c->obj.f00, 0, c->f130, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x18);
            (*state)++;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (c->f135 != 0) {
            func_0201EFA4(c->obj.f00, 0, c->f135, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x30);
            (*state)++;
        } else {
            *state = 8;
        }
        break;
    case 7:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (c->f134 != 0) {
            func_0201EFA4(c->obj.f00, 0, c->f134, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x31);
            (*state)++;
        } else {
            *state = 10;
        }
        break;
    case 9:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 10;
        }
        break;
    case 10:
        *state = 12;
        break;
    case 11:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(sub, 0, 6));
            *state = 12;
        }
        break;
    case 12:
        func_0217F318(&c->obj);
        func_0201235C(a, (void *)func_0217CA84(sub, 0));
        return 0;
    }
    return 0;
}










void func_021808C4(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_021808E8, 0xA8);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}










int func_021808E8(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    int w = (int)func_020120F4((const struct Ctx *)v);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj09400 *)obj)->f10), 0, func_02012950((struct Sub24 *)w, obj[0x40]));
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_0218383C[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = *st + 1;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}










void func_02180978(int id, void *dst)
{
    func_021808C4((void *)id, dst);
}









void func_02180980(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_021809A4, 0xA4);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}








/*
 * Task callback in the shape of func_02182AA4: an 8-state sequence driving
 * the Ov018Obj at +0x10, with an early skip to state 5 while the owner
 * object is absent.
 */
int func_021809A4(void *a, int *state, Outer_021809A4 *c)
{
    void *sub;
    u8 *v;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 1) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 5) {
            func_0217F3C4(&c->obj, 4);
            *state = 5;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if (func_02175CF4((char *)v, v + 0x1AC) != 0) {
            c->f9C = 1;
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_02183870[c->f42]);
        (*state)++;
        break;
    case 3:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_0218387A[c->f42]);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_02183884[c->f42]);
            func_020061E4(0x5E0);
            (*state)++;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 6;
        }
        break;
    case 6:
        if (func_0217F420() == 1) {
            *state = 7;
        }
        break;
    case 7:
        func_0217FE38(v, (u8 *)c);
        func_0201235C(a, func_021804F8(sub, c->f9C));
        return 0;
    }
    return 0;
}








void func_02180B14(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_02180B38, 0xA4);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}









int func_02180B38(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05933 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05933 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05933 *)obj)->f10), 2, ((struct Obj05933 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_02183848[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}








void func_02180BDC(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_02180C00, 0xA4);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}









int func_02180C00(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05935 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05935 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05935 *)obj)->f10), 2, ((struct Obj05935 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_02183866[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}








void func_02180CA4(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_02180CC8, 0xA4);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}







/*
 * Task callback in the shape of func_02182AA4: a 7-state sequence driving
 * the Ov018Obj at +0x10; state 2 pushes an ov083 child task.
 */
int func_02180CC8(void *a, int *state, Outer *c)
{
    void *sub;
    int v;
    Args args;

    sub = func_020124E4(a);
    v = func_02158344((int)((void *)func_02012138(sub)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        c->fA0 = c->f42;
        func_0217F3C4(&c->obj, d_02183852[c->fA0]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318(&c->obj);
        args.a = c->f58;
        args.zero = 0;
        func_02012374(a, (struct Evt **)func_020124AC(sub, (u32)ov083_id, (u32 (*)(void *, u32))func_021F5260, (u32)(&args)));
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_0217F2B4(&c->obj, sub);
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4(&c->obj, d_0218385C[c->fA0]);
        (*state)++;
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1 && func_0217F420() == 1) {
            (*state)++;
        }
        break;
    case 6:
        func_0217FE38((void *)v, (u8 *)c);
        return 1;
    }
    return 0;
}







/*
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 */
void func_02180DE8(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180E0C, 0xA0);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}





int func_02180E0C(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05937 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05937 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05937 *)obj)->f10), 2, ((struct Obj05937 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_021838B8[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}





void func_02180EB0(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180ED4, 0xA0);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}





int func_02180ED4(void *a, int *state, Ov018Outer_0218034C *c)
{
    void *sub;
    int v;
    Args args;

    sub = func_020124E4(a);
    v = func_02158344((int)((void *)func_02012138(sub)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_02183890[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318(&c->obj);
        args.a = c->f58;
        args.zero = 0;
        func_02012374(a, (struct Evt **)func_020124AC(sub, (u32)ov083_id, (u32 (*)(void *, u32))func_021F5260, (u32)(&args)));
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_0217FE38((void *)v, (u8 *)c);
        return 1;
    }
    return 0;
}




void func_02180FA8(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180FCC, 0xA0);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}




int func_02180FCC(void *a, int *state, Ov018Outer_02180FA8 *c)
{
    void *sub;
    u8 *v;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 1) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 4) {
            func_0217F3C4(&c->obj, 4);
            *state = 4;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if (func_02175CF4((char *)v, (u8 *)(v + 0x1AC)) != 0) {
            c->f9C = 1;
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_021838A4[c->f42]);
        (*state)++;
        break;
    case 3:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_021838AE[c->f42]);
            func_020061E4(0x5E0);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 5;
        }
        break;
    case 5:
        if (func_0217F420() == 1) {
            *state = 6;
        }
        break;
    case 6:
        func_0217FE38(v, (u8 *)c);
        func_0201235C(a, func_021804F8(sub, c->f9C));
        return 0;
    }
    return 0;
}



void func_0218111C(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181140, 0xA0);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}



int func_02181140(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    void *m;

    m = (void *)func_02158344((int)func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05940 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05940 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05940 *)obj)->f10), 2, ((struct Obj05940 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_0218389A[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}



void func_021811E4(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_0218123C, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj05941 *)t)->fA4 = 0;
    ((struct Obj05941 *)t)->f9C = r;
    t[0xA0] = src->f40;
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}
