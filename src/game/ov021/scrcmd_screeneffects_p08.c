/*
 * file:     scrcmd_screeneffects_p08.c
 * unit:     yes
 * function: func_021AEF10, func_021AEF60, func_021AEFA4, func_021AEFD8, func_021AF044, func_021AF0BC, func_021AF0F8, func_021AF130, func_021AF174, func_021AF1B0, func_021AF1D0, func_021AF1E8, func_021AF21C, func_021AF23C, func_021AF26C, func_021AF294, func_021AF2BC, func_021AF2CC, func_021AF2E4, func_021AF2F4, func_021AF324, func_021AF370, func_021AF380, func_021AF3D8, func_021AF430, func_021AF448, func_021AF458, func_021AF484, func_021AF4B0, func_021AF4E8, func_021AF544, func_021AF594, func_021AF5E4, func_021AF634
 * address:  0x021AEF10
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02028A58  0x02028A58  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02028BDC  0x02028BDC  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02158F88  0x02158F88  thumb  ov010
 *   func_02005F38  0x02005F38  thumb
 *   func_020289B8  0x020289B8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215A6AC  0x0215A6AC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02005C64  0x02005C64  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_0215A6B8  0x0215A6B8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007F68  0x02007F68  thumb
 */
#include "../../matched/include/Obj18089.h"

struct Ctx;
struct BigObj;
struct SoundSys;
struct S;
struct Stream;
struct Sys;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; u32 f8; } S;

typedef struct {
    u16 a;
    u16 b;
    u32 f4;
    u32 f8;
} Rec;

extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *a);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void func_02159144(int n);
extern void func_02159168(int n);
extern void *func_0215A5F4(void *p);
extern u8 func_02012984(const struct BigObj *p);
extern u16 func_02188C9C(u8 *p);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u32 c, u32 d);
extern void func_0215897C(void *vm, void *task);
extern void func_02028BDC(struct S *s, u32 mask);
extern unsigned short func_02011330(struct Stream *s);
extern void *func_02029AF4(void *a, u32 b);
extern u8 *func_020295A4(u8 *p, u32 a);
extern void *func_02029620(void *a, u32 b, u32 c);
extern int func_02158F58(int a0);
extern u8 *func_02158F88(void *p);
extern int func_02006224(u32 a0);
extern int func_02006148(u32 a);
extern void func_020061F8(int i);
extern void func_020061E4(u32 a);
extern void func_020113D0(char *p, int val);
extern void *func_02029830(void *a, u32 b);
extern int func_02005F38(void);
extern u32 func_020289B8(struct Sys *s);
extern struct Desc *func_020122C0(void *a, void *b, void *c, unsigned int d);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02006BD0(u32);
extern u32 func_0215A6AC(u32, u32, u32, u32);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B578(u32 *p);
extern void func_0202C0D0(u8 *p, u32 a);
extern void func_0202C0E4(u8 *p, u32 a);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0202C0F8(int a0, int a1);
extern int func_02005C64(void);
extern void func_02006CAC(void **out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void func_0215A6B8(u32 *a, u32 b);
extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void *func_0201292C(const struct BigObj *p);
extern u16 func_02007E50(void *a, u32 b, u32 c, u32 d);
extern u16 func_02007F1C(void *, u32, u32, u32);
extern u16 func_02007E3C(void *, u32, u32, u32);
extern u16 func_02007F68(void *, u32, u32, u32);
int func_021AEF10(u32 a, u32 b);
int func_021AEF60(u32 a, u32 b);
int func_021AEFA4(u32 *a, u32 *st);
int func_021AEFD8(u32 a, u32 b);
int func_021AF044(struct Stream *a, u32 b);
int func_021AF0BC(u32 a, u32 b);
int func_021AF0F8(u32 a, u32 b);
int func_021AF130(u32 a, u32 b);
int func_021AF174(S *s, u32 *st);
int func_021AF1B0(u32 a, u32 b, u32 c, u32 d);
int func_021AF1D0(u32 a, u32 b, u32 c, u32 d);
void func_021AF1E8(u32 a);
void func_021AF21C(u32 a, u32 b);
int func_021AF23C(u32 a);
void func_021AF26C(u32 a);
int func_021AF294(u32 a, u32 b);
int func_021AF2BC(u32 a, u32 b, u32 c, u32 d);
int func_021AF2CC(u32 a, u32 b, u32 c, u32 d);
int func_021AF2E4(u32 a);
int func_021AF2F4(u32 a, u32 b);
int func_021AF324(u32 a, u32 b);
int func_021AF370(u32 a);
int func_021AF380(u32 a, u32 b);
int func_021AF3D8(u32 a, u32 b);
int func_021AF430(u32 a, u32 b, u32 c, u32 d);
int func_021AF448(u32 a);
int func_021AF458(u32 a, u32 b);
int func_021AF484(u32 a, u32 b);
int func_021AF4B0(u32 a, u32 b);
int func_021AF4E8(u32 a, u32 b, Rec *c);
int func_021AF544(u32 a, u32 b);
int func_021AF594(u32 a, u32 b);
int func_021AF5E4(u32 a, u32 b);
int func_021AF634(u32 a, u32 b);


/*
 * Addresses are Black-image addresses.
 */
int func_021AEF10(u32 a, u32 b)
{
    u32 y, z;
    void *x;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4(x);
    func_0201210C((void *)x);
    y = func_02012A30((const struct BigObj *)y);
    z = func_02159B10((void *)a, (void *)b);
    func_02028A58((struct SoundSys *)y, z, (u8)func_02159B10((void *)a, (void *)b));
    func_02159144(12);
    return 0;
}


int func_021AEF60(u32 a, u32 b)
{
    u32 y;
    void *x;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4(x);
    func_0201210C((void *)x);
    y = func_02012A30((const struct BigObj *)y);
    func_02028A58((struct SoundSys *)y, 0x7f, (u8)func_02159B10((void *)a, (void *)b));
    func_02159168(12);
    return 0;
}


int func_021AEFA4(u32 *a, u32 *st)
{
    u32 r = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)(*a)));

    switch (*st) {
    case 0:
        func_02028A58((struct SoundSys *)r, 0x7f, 0);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}


/*
 * .word 0x02029EB5) has no witness outside the range (evidence class: none;
 * arm9 leaf belongs to Ilias, not filed here).
 *
 * Addresses are Black-image addresses.
 */
int func_021AEFD8(u32 a, u32 b)
{
    u32 y, m, q, s;
    void *x;
    void *l;
    void *p;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4(x);
    l = func_0201210C((void *)x);
    m = func_02012A30((const struct BigObj *)y);
    p = func_0215A5F4((void *)b);
    q = func_02012984((const struct BigObj *)y);
    s = func_02029DF4((void *)y, func_02188C9C(l), q);
    func_0215897C(p, (void *)func_020298A0(x, s, 0x5a, 0x3c));
    func_02028BDC((struct S *)m, 2);
    func_02159168(13);
    return 1;
}


int func_021AF044(struct Stream *a, u32 b)
{
    u32 y, m, n, q, s;
    void *x;
    void *l;
    void *p;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4(x);
    l = func_0201210C((void *)x);
    m = func_02012A30((const struct BigObj *)y);
    p = func_0215A5F4((void *)b);
    n = func_02011330(a);
    q = func_02012984((const struct BigObj *)y);
    s = func_02029DF4((void *)y, func_02188C9C(l), q);
    func_0215897C(p, (void *)func_020298A0(x, s, n, 0x3c));
    func_02028BDC((struct S *)m, 2);
    func_02159168(13);
    return 1;
}


int func_021AF0BC(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x;

    func_020120F4(y);
    func_0201210C((void *)y);
    x = func_0215A5F4((void *)b);
    func_0215897C(x, func_02029AF4(y, func_02159B10((void *)a, (void *)b)));
    return 1;
}


int func_021AF0F8(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, func_020295A4(y, func_02159B10((void *)a, (void *)b)));
    func_02159144(10);
    return 1;
}


int func_021AF130(u32 a, u32 b)
{
    u32 u;
    void *x;
    void *p;

    x = func_0215A5DC((void *)b);
    p = func_0215A5F4((void *)b);
    u = func_02159B10((void *)a, (void *)b);
    func_0215897C(p, (void *)func_02029620(x, u, func_02159B10((void *)a, (void *)b)));
    func_02159168(10);
    return 1;
}


int func_021AF174(S *s, u32 *st)
{
    u32 x = s->f8;

    func_02158F58(x);
    switch (*st) {
    case 0:
        func_0215897C((void *)x, func_02029620((void *)s->f0, 0, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AF1B0(u32 a, u32 b, u32 c, u32 d)
{
func_02028BDC((struct S *)func_02012A30((const struct BigObj *)func_020120F4(func_0215A5DC((void *)b))), 2);
func_02159168(13);
return 0;
}


int func_021AF1D0(u32 a, u32 b, u32 c, u32 d)
{
func_02028BDC((struct S *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)(((struct Obj18089 *)((u8 *)(a)))->f0))), 2);
return 1;
}


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
void func_021AF1E8(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88((void *)a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i)) {
            if (func_02006224(i) == 0)
                *p &= ~(1 << i);
        }
    }
}


void func_021AF21C(u32 a, u32 b)
{
    u8 *p = func_02158F88((void *)a);

    *p |= 1 << func_02006148(b);
}


int func_021AF23C(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88((void *)a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i)) {
            if (func_02006224(i) == 1)
                return 1;
        }
    }
    *p = 0;
    return 0;
}


void func_021AF26C(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88((void *)a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i))
            func_020061F8(i);
    }
    *p = 0;
}


int func_021AF294(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    void *y = func_0215A5F4((void *)b);

    func_021AF1E8((u32)y);
    func_020061E4(x);
    func_021AF21C((u32)y, x);
    return 0;
}


int func_021AF2BC(u32 a, u32 b, u32 c, u32 d)
{
func_021AF26C((u32)func_0215A5F4((void *)b));
return 0;
}


int func_021AF2CC(u32 a, u32 b, u32 c, u32 d)
{
if (func_021AF23C((u32)func_0215A5F4((void *)b)) == 0) {
    return 1;
}
return 0;
}


int func_021AF2E4(u32 a)
{
    func_020113D0((char *)a, (int)func_021AF2CC);
    return 1;
}


int func_021AF2F4(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, func_02029830(y, func_02011330((struct Stream *)a)));
    return 1;
}


int func_021AF324(u32 a, u32 b)
{
    u32 y;
    void *x;
    void *p;

    x = func_0215A5DC((void *)b);
    p = func_0215A5F4((void *)b);
    y = func_02012A30((const struct BigObj *)func_020120F4(x));
    if (func_02005F38() == 0 && func_020289B8((struct Sys *)y) == 0) {
        func_0215897C(p, func_02029620(x, 0, 6));
        return 1;
    }
    return 0;
}


int func_021AF370(u32 a)
{
    func_020113D0((char *)a, (int)func_021AF324);
    return 1;
}


int func_021AF380(u32 a, u32 b)
{
    u32 u, v, h;
    void *p;
    void *x;
    Rec *r;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    u = func_02159B10((void *)a, (void *)b);
    v = func_02159B10((void *)a, (void *)b);
    h = (u32)func_020122C0(x, 0, (void *)func_021AF4E8, 12);
    r = func_020124E8((struct Obj *)h);
    r->a = u;
    r->b = v;
    r->f4 = 0;
    r->f8 = b;
    func_0215897C(p, (void *)h);
    return 1;
}


int func_021AF3D8(u32 a, u32 b)
{
    u32 u, v, h;
    void *p;
    void *x;
    Rec *r;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    u = func_02159B10((void *)a, (void *)b);
    v = func_02159B10((void *)a, (void *)b);
    h = (u32)func_020122C0(x, 0, (void *)func_021AF4E8, 12);
    r = func_020124E8((struct Obj *)h);
    r->a = u;
    r->b = v;
    r->f4 = 1;
    r->f8 = b;
    func_0215897C(p, (void *)h);
    return 1;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A6AC (0x0215A6AC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AF430(u32 a, u32 b, u32 c, u32 d)
{
if (func_02006BD0(func_0215A6AC(b, b, c, d)) == 0) {
    return 1;
}
return 0;
}


int func_021AF448(u32 a)
{
    func_020113D0((char *)a, (int)func_021AF430);
    return 1;
}


int func_021AF458(u32 a, u32 b)
{
    u32 x = func_0202B578((u32 *)func_02012134(func_0215A5DC((void *)b)));

    func_0202C0D0((u8 *)x, func_02159B10((void *)a, (void *)b));
    return 0;
}


int func_021AF484(u32 a, u32 b)
{
    u32 x = func_0202B578((u32 *)func_02012134(func_0215A5DC((void *)b)));

    func_0202C0E4((u8 *)x, func_02159B10((void *)a, (void *)b));
    return 0;
}


int func_021AF4B0(u32 a, u32 b)
{
    u32 x = func_0202B578((u32 *)func_02012134(func_0215A5DC((void *)b)));

    *func_02159AE8((void *)a, (void *)b) = func_0202C0F8(x, func_02159B10((void *)a, (void *)b));
    return 0;
}


int func_021AF4E8(u32 a, u32 b, Rec *c)
{
    u32 v, r;

    if (func_02005C64()) {
        return 0;
    }
    if (c->f4) {
        u32 x, y;
        y = c->b;
        x = c->a;
        func_02006CAC((void **)(&v));
        r = func_02006984(x, y, 0x40, 0, 0, 0, 0, (u32)(&v));
    } else {
        r = func_02006984(c->a, c->b, 0x40, 0, 0, 0, 0, 0);
    }
    func_0215A6B8((u32 *)c->f8, r);
    return 1;
}


int func_021AF544(u32 a, u32 b)
{
    u32 p;
    void *x;
    u32 u, v;
    u16 *h;

    p = func_0215A5CC((void *)b);
    x = func_0201292C(func_0215A5E4((void *)b));
    u = func_02159B10((void *)a, (void *)b);
    v = func_02159B10((void *)a, (void *)b);
    h = func_02159AE8((void *)a, (void *)b);
    *h = func_02007E50(x, u, v, p);
    return 0;
}


int func_021AF594(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e, f;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)a, (void *)b);
    f = func_02159B10((void *)a, (void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007F1C(d, e, f, c);
    return 0;
}


int func_021AF5E4(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e, f;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)a, (void *)b);
    f = func_02159B10((void *)a, (void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007E3C(d, e, f, c);
    return 0;
}


int func_021AF634(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e, f;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)a, (void *)b);
    f = func_02159B10((void *)a, (void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007F68(d, e, f, c);
    return 0;
}
