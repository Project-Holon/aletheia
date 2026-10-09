/*
 * file:     field_wfbc_p04.c
 * unit:     yes
 * function: func_02194354, func_02194384, func_021943EC, func_02194418, func_02194434, func_021944BC, func_021944C8, func_021944D8, func_02194588, func_021945A0, func_021945A4, func_021945E0, func_02194670, func_02194704, func_0219470C, func_02194760, func_02194764, func_02194798, func_021947E8, func_02194848, func_02194888, func_021948CC, func_0219492C, func_02194940, func_02194950, func_02194960, func_02194974, func_02194984, func_02194990, func_0219499C, func_02194A00, func_02194A24, func_02194A34, func_02194A48, func_02194A58, func_02194A74, func_02194A84, func_02194A94
 * address:  0x02194354
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
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_02163C04  0x02163C04  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   d_021D3F68     0x021D3F68  data  ov021  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DC98  0x0216DC98  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216DC64  0x0216DC64  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_020129D0  0x020129D0  thumb
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0203101C  0x0203101C  arm
 *   func_021954CC  0x021954CC  thumb  ov021
 *   d_021DDAC4     0x021DDAC4  data  a4
 *   d_020A8140     0x020A8140  data  a4
 *   d_020A8148     0x020A8148  data  a4
 *   func_02195530  0x02195530  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_0219545C  0x0219545C  thumb  ov021
 *   func_021953D4  0x021953D4  thumb  ov021
 *   func_02194B84  0x02194B84  thumb  ov021
 *   func_02194C60  0x02194C60  thumb  ov021
 *   func_02195490  0x02195490  thumb  ov021
 *   func_0206DB80  0x0206DB80  arm
 *   func_02194CE8  0x02194CE8  thumb  ov021
 *   func_02194B3C  0x02194B3C  thumb  ov021
 *   d_020A814C     0x020A814C  data  a4
 *   d_020A8144     0x020A8144  data  a4
 *   func_02031140  0x02031140  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02194AC8  0x02194AC8  thumb  ov021
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_02194B70  0x02194B70  thumb  ov021
 *   func_02194B78  0x02194B78  thumb  ov021
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02195E54  0x02195E54  thumb  ov021
 *   func_02195E90  0x02195E90  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 */
#include "../../matched/include/Obj07448.h"
#include "../../matched/include/Obj12622.h"
#include "../../matched/include/Obj05859.h"
#include "../../matched/include/Obj19625.h"
#include "../../matched/include/Obj19627.h"
#include "../../matched/include/Obj19628.h"
#include "../../matched/include/Obj02693.h"
#include "../../matched/include/Obj07451.h"
#include "../../matched/include/Obj01351.h"
#include "../../matched/include/Obj09485.h"
#include "../../matched/include/Obj02376.h"
#include "../../matched/include/Obj09486.h"
#include "../../matched/include/Obj17941.h"
#include "../../matched/include/Obj02343.h"
#include "../../matched/include/Obj17942.h"

struct Actor;
struct VecFx32;
struct Desc;
struct Obj;
struct BigObj;
struct Tcbl;
struct S02031140;
struct Rec3;
struct FrameStyle;
struct Descriptor;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_02194354;

typedef signed char    s8;

typedef struct { u32 key; u32 x4; u32 x8; } Item;

typedef struct { u16 n; u16 pad; u32 x4; Item *items; } List;

typedef short s16_02194384;

typedef struct Rec {
    u32 key;
    u32 f4;
    u32 val;
} Rec;

typedef struct Tbl {
    u16 n;
    u16 pad;
    u32 f4;
    Rec *recs;
} Tbl;

typedef signed short   s16;

typedef struct { unsigned w[9]; } T;

typedef struct { unsigned w[6]; } T24;

typedef struct { u16 kind; u8 f2; u8 rest[97]; } Ent;

typedef struct { u8 pad[0x18]; Ent ents[32]; } Top;

typedef struct {
    u32 f0;
    u32 f4;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
    u16 fc;
    u16 fe;
    u32 f10;
} Cfg;

typedef struct { u8 pad[0x10]; u32 x10; u8 x14; u8 x15; } Obj;

extern int func_0216D854(void *p);
extern int func_02163C04(int a, int x, int y, int flag);
extern u32 func_02082BCC(u32, u32, u32);
extern int func_0216CF2C(int a0, int a1);
extern void *func_0216CE60(void *a, void *b, int c);
extern void func_0216E014(void *a, int *p, int b);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DC98(void *a0, int a1);
extern void func_0216DB80(unsigned int *p, unsigned int v);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern int func_0216DC64(void *a0, int a1);
extern int func_0216DCCC(void *a0, int a1);
void *func_0216D684(int a0, int a1);
extern void *func_0216D69C(void *p);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u16 func_0216D5F8(void *p);
extern u16 func_0216D598(void *p);
extern void func_0216D674(void *a, int v);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern u32 func_02188CCC(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021A0ED4(u32 a);
extern void *func_02188C7C(u8 *p);
extern void *func_020124E4(struct Obj *p);
extern u32 func_020120F4(void);
extern void func_0216D9A0(void *a);
extern void func_020129D0(struct BigObj *p, u8 v);
extern int func_021A0F30(u32 a, u32 b);
extern void func_020129B8(struct BigObj *p, u32 v);
extern u32 *func_0216D9E4(void *c);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, u16 tag);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_021954CC(u32 p, u8 *e);
extern void func_02195530(char *p);
extern void func_020310C4(struct Tcbl *p);
extern int func_0219545C(void *a);
extern void func_021953D4(u8 *p, int m);
extern void func_02194B84(u8 *p, u8 *e);
extern void func_02194C60(u8 *p, u8 *e);
extern int func_02195490(void *a);
extern void func_0206DB80(void);
extern void func_02194CE8(int a, u16 *b);
extern void func_02194B3C(u8 *p, u8 *e);
extern void func_02031140(struct S02031140 *p);
extern u32 func_020307B0(void *p);
extern void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s);
extern u32 func_0206DF3C(u32 a, int *x, int *y);
extern void func_02194B70(u16 *p, int i);
extern void func_02194B78(u8 *e, int i);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_02195E54(u32 a, u32 b, u8 c, u32 d);
extern u32 func_020409B4(u32);
extern void func_02195E90(struct FrameStyle *style, void *win);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
void func_02194354(List *p, u32 key);
int func_02194384(u16 *a, s16_02194384 b, int c, s16_02194384 d, int *e, unsigned *f);
u32 func_021943EC(Tbl *t, u32 key);
int func_02194418(u32 a, int a1);
void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f);
void *func_021944BC(int a);
void func_021944C8(u32 a);
void func_021944D8(void *a);
void func_02194588(u32 a, u32 b, u32 c, u32 d, u32 e);
int func_021945A0(int x);
void *func_021945A4(void *a, u32 b, u32 c);
int func_021945E0(void *a, int b, u8 *c);
void *func_02194670(u16 *a);
void func_02194704(char *a0);
void func_0219470C(unsigned char *a);
void func_02194760(u32 a);
void func_02194764(Top *a);
void func_02194798(unsigned char *a);
void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n);
void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x);
void func_0219492C(u8 *p, int i);
void func_02194940(u8 *p, int i);
void func_02194950(u8 *p, int i);
u32 func_02194960(u32 a, u32 b, u32 c, u32 a3);
int func_02194974(u8 *p, int i);
u32 func_02194984(u32 a, u32 b);
u32 func_02194990(u32 a, u32 b);
void func_0219499C(u8 *p, int i, u32 b, u32 c);
u32 func_02194A00(u32 a, u8 b, u8 c, u8 d, u8 e, u32 f);
int func_02194A24(u32 a, u32 b, u32 c, u32 d);
int func_02194A34(u32 a, u32 b);
u32 func_02194A48(u32 a, struct Descriptor *b);
int func_02194A58(u32 a);
int func_02194A74(u32 a);
int func_02194A84(u16 *p, int i);
u32 func_02194A94(Obj *a, u32 b, u32 c, u32 d, u8 e);
extern T d_021D3F68;
extern int d_021DDAC4;




/*
 * Addresses are Black-image addresses.
 */
void func_02194354(List *p, u32 key)
{
    Item *it;
    u16 i;

    it = p->items;
    for (i = 0; i < p->n; i++) {
        if (it->x8 != 0 && it->key == key) {
            func_02194418((u32)it, key);
            return;
        }
        it++;
    }
}




int func_02194384(u16 *a, s16_02194384 b, int c, s16_02194384 d, int *e, unsigned *f)
{
    unsigned n = *a;
    unsigned char *q;
    short dlt;

    if (*f < n) {
        q = *(unsigned char * *)&((struct Obj12622 *)a)->f8 + *f * 0xc;
        do {
            (*f)++;
            if (((struct Obj07448 *)q)->f8 != 0) {
                dlt = func_0216D854(((struct Obj07448 *)q)->f8) - c;
                if (dlt < 0)
                    dlt = -dlt;
                if (dlt < 1) {
                    if (func_02163C04((int)(((struct Obj07448 *)q)->f8), b, d, 1)) {
                        *e = ((struct Obj07448 *)q)->f0;
                        return 1;
                    }
                }
                q += 0xc;
            }
        } while (*f < n);
    }
    return 0;
}




/*
 * Unlabelled Thumb leaf (push {r4, r5} saves no lr): finds the record whose
 * key equals the argument among n 12-byte records and returns its +8 field,
 * or 0. Sole blocker of ov010 func_021679C4's callee relocation.
 */
u32 func_021943EC(Tbl *t, u32 key)
{
    u16 i;
    Rec *r;
    u16 n;

    n = t->n;
    i = 0;
    r = t->recs;
    for (; i < n; i++, r++) {
        if (r->val != 0 && r->key == key)
            return r->val;
    }
    return 0;
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02194418(u32 a, int a1)
{
if (((struct Obj05859 *)((u8 *)(a)))->f4 == 0) {
    func_0216CF2C(((struct Obj05859 *)((u8 *)(a)))->f8, a1);
}
return func_02082BCC(a, 0, 12);
}




void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f)
{
    void *m = ((struct Obj19625 *)a)->f4;
    T local = d_021D3F68;
    void *o;

    *(u16 *)((unsigned char *)&local + 2) = x;
    o = func_0216CE60(m, &local, 0);
    func_02194588((u32)o, (u32)q, d, e, f);
    func_0216E014(o, (int *)d, func_021945A0(*q));
    func_0216DB4C(o, 1);
    func_0216DC98(o, 1);
    func_0216DB80(o, 1);
    func_0216DAE0(o, 0);
    func_0216DC64(o, 1);
    func_0216DCCC(o, 1);
    return o;
}


void *func_021944BC(int a)
{
    return func_0216D684(a, 0x10);
}








/*
 * Addresses are Black-image addresses.
 */
void func_021944C8(u32 a)
{
    ((struct Obj19628 *)(*(u8 * *)&((struct Obj19627 *)((u8 *)func_0216D69C((void *)a)))->fC))->f4 = 1;
}








void func_021944D8(void *a)
{
    int v[3];
    int *r4;
    int r6;
    int *p;
    int s;
    int t;

    r4 = func_0216D69C(a);
    func_0216D5E0((int)a, func_021945A0(*(u16 *)r4[0]));
    r6 = 0;
    func_0216D88C(a, (struct VecFx32 *)v);
    p = (int *)r4[1];
    if (v[0] != p[0] || v[1] != p[1] || v[2] != p[2]) {
        func_0216E014(a, (int *)r4[1], func_0216D5F8(a));
        r6 = 3;
        if (*(u16 *)(r4[3] + 6) != 0) {
            s = func_0216D598(a);
            if (s == 1 || s == 4) {
                int sum = 0;
                p = (int *)r4[1];
                t = v[0] - p[0];
                if (t < 0)
                    t = -t;
                sum += t;
                t = v[2] - p[2];
                if (t < 0)
                    t = -t;
                sum += t;
                if (sum >= 0x4000)
                    r6 = 10;
            }
        }
    }
    func_0216D674(a, r6);
    if (r4[2] != 0)
    {
        int f = 0;

        if (*(int *)r4[2] == 1)
            f = 1;
        func_0216DAC8(a, f);
    }
}








void func_02194588(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 *p;

    p = func_0216D69C((void *)a);
    p[0] = b;
    p[1] = c;
    p[2] = d;
    p[3] = e;
}








/*
 * An empty function.
 */
int func_021945A0(int x)
{
    return x;
}








void *func_021945A4(void *a, u32 b, u32 c)
{
    void *t;
    u32 *w;

    func_02188CCC((u8 *)b);
    t = func_020122C0(a, 0, func_021945E0, 0x14);
    w = func_020124E8(t);
    func_02082BCC((u32)w, 0, 0x14);
    w[1] = (u32)a;
    w[0] = (u32)t;
    w[2] = b;
    w[3] = c;
    return t;
}








int func_021945E0(void *a, int b, u8 *c)
{
    void *r6;
    u32 r4;

    switch (c[0x10]) {
    case 0:
        if (func_021A0ED4(func_02188CCC(((struct Obj02693 *)c)->f8)) == 1) {
            r6 = func_02188C7C(((struct Obj02693 *)c)->f8);
            func_020124E4(a);
            r4 = func_020120F4();
            func_0216D9A0(r6);
            func_020129D0((struct BigObj *)r4, 1);
            func_021A0F30(func_02188CCC(((struct Obj02693 *)c)->f8), ((struct Obj02693 *)c)->fC);
            c[0x10]++;
        }
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(((struct Obj02693 *)c)->f8)) == 1) {
            func_020124E4(a);
            func_020129B8((struct BigObj *)func_020120F4(), ((struct Obj02693 *)c)->fC & 0xff);
            c[0x10]++;
        }
        break;
    case 2:
        func_0216D9E4(func_02188C7C(((struct Obj02693 *)c)->f8));
        return 1;
    }
    return 0;
}







extern void *(*d_020A8140)(int, int, int);







extern void *(*d_020A8148)(int, int, int);








void *func_02194670(u16 *a)
{
    unsigned char *r6;
    int i;

    r6 = (unsigned char *)func_02030734(*a, 0xcd0, 1, (const char *)&d_021DDAC4, 0xec);
    *(T24 *)r6 = *(T24 *)a;
    ((struct Obj07451 *)r6)->fC98 = func_0203101C(*a, *a, 0x20, 0x20);
    for (i = 0; i < 0x20; i++)
        func_02194A58((u32)(r6 + 0x18 + i * 0x64));
    ((struct Obj07451 *)r6)->fCC8 = d_020A8140(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fCCC = d_020A8148(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fC9C = func_021954CC((u32)r6, r6) >> 5;
    return r6;
}








/*
 * Tail-call thunk: forwards to func_02195530 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02194704(char *a0)
{
    func_02195530(a0);
}







void func_0219470C(unsigned char *a)
{
    int i;

    func_020310C4(((struct Obj01351 *)a)->fC98);
    func_0219545C(a);
    func_021953D4(a, 0);
    for (i = 0; i < 0x20; i++) {
        if (a[i * 0x64 + 0x1a] == 0)
            func_02194B84(a, a + 0x18 + i * 0x64);
        else
            func_02194C60(a, a + 0x18 + i * 0x64);
    }
    func_02195490(a);
}







void func_02194760(u32 a)
{
}







void func_02194764(Top *a)
{
    int i;

    func_0206DB80();
    func_021953D4((u8 *)a, 1);
    for (i = 0; i < 32; i++) {
        if (a->ents[i].f2 == 0) {
            func_02194CE8((int)a, (u16 *)(&a->ents[i]));
        }
    }
}







extern void (*d_020A814C)(void *p);






extern void (*d_020A8144)(void *p);







void func_02194798(unsigned char *a)
{
    int i;

    for (i = 0; i < 0x20; i++)
        func_02194B3C(a, a + 0x18 + i * 0x64);
    d_020A814C(((struct Obj09485 *)a)->fCCC);
    d_020A8144(((struct Obj09485 *)a)->fCC8);
    func_02031140(((struct Obj09485 *)a)->fC98);
    func_020307B0(a);
}







void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n)
{
    Cfg s;
    u8 *e;

    s.f0 = 0;
    s.f4 = 0;
    s.f8 = b;
    s.f9 = c;
    s.fa = d;
    s.fb = f;
    s.fc = 0x7FFF;
    s.fe = h;
    s.f10 = k;
    e = p + 0x18 + i * 100;
    func_02194AC8(p, e, 0, a, (u8 *)(&s));
    e[0x5C] = m;
    e[0x5D] = n;
    e[2] = 1;
}







void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x)
{
    Cfg s;

    s.f0 = 1;
    s.f4 = w;
    s.f8 = 1;
    s.f9 = 1;
    s.fa = 0x1E;
    s.fb = 4;
    s.fc = 0x7FFF;
    s.fe = v;
    s.f10 = x;
    func_02194AC8(p, p + 0x18 + i * 100, a, b, (u8 *)(&s));
}







void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x)
{
    Cfg s;

    s.f0 = 2;
    s.f4 = w;
    s.f8 = 1;
    s.f9 = 0x13;
    s.fa = 0x1E;
    s.fb = 4;
    s.fc = 0x7FFF;
    s.fe = v;
    s.f10 = x;
    func_02194AC8(p, p + 0x18 + i * 100, a, b, (u8 *)(&s));
}







void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x)
{
    int px;
    int py;

    func_0206DF3C(a, &px, &py);
    if (py < 0x60)
        func_02194888(p, i, a, b, u, v, 0, x);
    else
        func_02194848(p, i, a, b, u, v, 0, x);
}







/*
 * Tail call with the object and a strided element address.
 *
 * Addresses are Black-image addresses.
 */
void func_0219492C(u8 *p, int i)
{
    func_02194B3C(p, p + 0x18 + i * 100);
}







/*
 * Tail call with a strided element address and the index.
 *
 * Addresses are Black-image addresses.
 */
void func_02194940(u8 *p, int i)
{
    func_02194B70((u16 *)(p + 0x18 + i * 100), i);
}






void func_02194950(u8 *p, int i)
{
    func_02194B78(p + 0x18 + i * 100, i);
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02194960(u32 a, u32 b, u32 c, u32 a3)
{
if (*(u16 *)((u8 *)((a + (b * 100))) + 24) == 0) {
    return 1;
}
return 0;
}






int func_02194974(u8 *p, int i)
{
    return func_02194A84((u16 *)(p + 0x18 + i * 100), i);
}






u32 func_02194984(u32 a, u32 b)
{
return *(u32 *)((u8 *)((a + (b * 100))) + 32);
}






u32 func_02194990(u32 a, u32 b)
{
return *(u32 *)((u8 *)((a + (b * 100))) + 36);
}





void func_0219499C(u8 *p, int i, u32 b, u32 c)
{
    u8 *e;

    e = p + 0x18 + i * 100;
    if (((struct Obj02376 *)e)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj02376 *)e)->f8));
        ((struct Obj02376 *)e)->f8 = 0;
    }
    if (b != 0) {
        ((struct Obj02376 *)e)->f60 = c;
        ((struct Obj02376 *)e)->f14 = b;
        ((struct Obj02376 *)e)->f8 = func_0201CCE4(((struct Obj02376 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02376 *)e)->f14,
                                        ((struct Obj09486 *)p)->f8, c, ((struct Obj09486 *)p)->fC98, 0, ((struct Obj09486 *)p)->f0, 15);
        ((struct Obj02376 *)e)->f0 = 4;
    }
}





u32 func_02194A00(u32 a, u8 b, u8 c, u8 d, u8 e, u32 f)
{
    u32 r;

    r = func_02194A94((Obj *)a, b, c, d, e);
    func_02195E54(a, r, f, 0);
    return r;
}





int func_02194A24(u32 a, u32 b, u32 c, u32 d)
{
return func_02195E54(a, b, ((c << 24) >> 24), 0);
}





int func_02194A34(u32 a, u32 b)
{
func_02195E90((struct FrameStyle *)a, (void *)b);
return func_020409B4(((((struct Obj17941 *)((u8 *)(a)))->f10 << 24) >> 24));
}





u32 func_02194A48(u32 a, struct Descriptor *b)
{
func_02195E90((struct FrameStyle *)a, (void *)b);
return func_020452E8(b);
}





int func_02194A58(u32 a)
{
((struct Obj02343 *)((u8 *)(a)))->f0 = 0;
((struct Obj02343 *)((u8 *)(a)))->f8 = 0;
((struct Obj02343 *)((u8 *)(a)))->f2C = 0;
((struct Obj02343 *)((u8 *)(a)))->f2E = 0;
((struct Obj02343 *)((u8 *)(a)))->f30 = 0;
((struct Obj02343 *)((u8 *)(a)))->f32 = 0;
((struct Obj02343 *)((u8 *)(a)))->f34 = 0;
((struct Obj02343 *)((u8 *)(a)))->f36 = 0;
((struct Obj02343 *)((u8 *)(a)))->f38 = 0;
((struct Obj02343 *)((u8 *)(a)))->f3A = 0;
((struct Obj02343 *)((u8 *)(a)))->f3C = 0;
return a;
}





int func_02194A74(u32 a)
{
if (((struct Obj17942 *)((u8 *)(a)))->f0 == 0) {
    return 1;
}
return 0;
}





/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): predicate
 * on a u16 field.  Listing bytes 00 88 04 28 01 D1 01 20 70 47 00 20 70 47.
 *
 * Addresses are Black-image addresses.
 */
int func_02194A84(u16 *p, int i)
{
    return *p == 4;
}





u32 func_02194A94(Obj *a, u32 b, u32 c, u32 d, u8 e)
{
    u32 w;

    w = func_020450F0((u8)a->x10, b, c, d, e, a->x15, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w)), 15);
    func_02045334((struct Descriptor *)w);
    return w;
}
