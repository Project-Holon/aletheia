/*
 * file:     field_effect_p56.c
 * unit:     yes
 * function: func_021AC1EC, func_021AC1F0, func_021AC218, func_021AC260, func_021AC274, func_021AC2AC, func_021AC2C0, func_021AC2F0
 * address:  0x021AC1EC
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
 *   func_02022040  0x02022040  thumb
 *   func_02030734  0x02030734  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   d_021DE028     0x021DE028  data  a1
 *   d_021D908C     0x021D908C  data  a4
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02050278  0x02050278  arm
 *   d_021D9098  0x021D9098  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 */
#include "../../matched/include/Obj04241.h"
#include "../../matched/include/Obj12095.h"

struct Tagged;
struct Ctl;
struct BbActRec;
struct BbActSys;
struct BbActDesc;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Res { u8 pad[0x30]; u16 h30; u16 pad32; u32 f34; u32 f38; } Res;

typedef struct X { u8 pad[0x24]; u32 f24; } X;

typedef struct { int x; int y; int z; } V;

typedef signed int     s32;

typedef struct Tmpl { u32 res; u8 b4, b5, b6, b7; u32 w8; } Tmpl;

typedef struct Ctl { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } Ctl;

typedef struct Arg { u32 a; u32 b; } Arg;

typedef struct V3 { int x, y, z; } V3;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Sys { u8 pad[0x10]; u32 f10; u32 f14; u32 f18; } Sys;

typedef struct Arg4 { u8 b0; } Arg4;

typedef struct P {
    u32 f0;
    Sys *sys;
    u32 f8;
    u16 fc[4];
    u32 f14;
} P;

extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C88(u8 *p);
extern u32 func_02050080(u32 *p);
extern void ENV_SetResourceSet(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_0204F6DC(u8 *a0, int i, u8 *px);
extern void func_021AC178(u32 a);
void func_021AC1EC(u32 *p, u32 v);
void func_021AC1F0(X *x, void *b);
char *func_021AC218(int a, int heap);
void func_021AC260(u32 a, u8 *p);
void func_021AC274(Ctl *p);
void func_021AC2AC(u8 *p);
void func_021AC2C0(u32 a, u32 b);
void func_021AC2F0(u32 a, P *p);
extern char d_021DE028[];
extern V d_021D908C;
extern u8 d_021D9098[];


/*
 * Setter: stores the second argument at +0x24.  Unlabelled in the listing;
 * called from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC1EC(u32 *p, u32 v)
{
    p[9] = v;
}


void func_021AC1F0(X *x, void *b)
{
    Res *p;

    if (x->f24 != 0) {
        p = (Res *)func_0206E964(func_02046F48(b));
        func_02022040((u16 *)((u8 *)p + p->f38), p->h30 * 8u / 2, (const u8 *)x->f24);
    }
}


char *func_021AC218(int a, int heap)
{
    char *p;

    p = (char *)func_02030734(heap, 0x1c, 1, d_021DE028, 0x5c);
    *(int *)&((struct Obj04241 *)p)->f0 = a;
    *(V *)(p + 4) = d_021D908C;
    ((struct Obj04241 *)p)->f10 = func_02188C88((u8 *)func_021ABE14((u8 *)a));
    ((struct Obj04241 *)p)->f14 = func_02050080((u32 *)(((struct Obj04241 *)p)->f10));
    func_021AC274((struct Ctl *)p);
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC260(u32 a, u8 *p)
{
    func_021AC2AC(p);
    ENV_SetResourceSet(p);
}


void func_021AC274(Ctl *p)
{
    Tmpl t;

    t.res = (u32)func_02046E24(func_021ABE24((u8 *)p->f0), 0x2f);
    t.b4 = 2;
    t.b5 = 0x11;
    t.b6 = 0x10;
    t.b7 = 0x10;
    t.w8 = 1;
    p->f18 = func_020500F0((struct BbActSys *)p->f10, (const struct BbActRec *)(&t), 1);
}


/*
 * Tail call with two fields and a constant one.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC2AC(u8 *p)
{
    func_02050278((struct BbActSys *)(((struct Obj12095 *)p)->f10), (u16)((struct Obj12095 *)p)->f18, 1);
}


void func_021AC2C0(u32 a, u32 b)
{
    Arg s;

    s.a = func_021ABEA0(b, 0);
    s.b = a;
    func_021ABFA8(b, d_021D9098, 0, 0, &s, 0);
}


void func_021AC2F0(u32 a, P *p)
{
    u32 *q = (u32 *)func_021AC1AC(a);
    Arg4 t;
    Desc s;

    p->sys = (Sys *)q[0];
    p->f8 = q[1];
    func_0216E1A4(q[1], (int)p->fc);
    s.slot = 0;
    s.v12 = 0x1000;
    s.v14 = 0x1000;
    s.k = 0x13;
    s.flag = 1;
    s.w = 1;
    {
        V3 zero = {0, 0, 0};

        s.pos = zero;
    }
    s.f1c = 0;
    s.f20 = (u32)p;
    p->f14 = func_02050340((struct BbActSys *)p->sys->f10, (u16)p->sys->f18, (const struct BbActDesc *)(&s), 1, 3);
    if (p->f14 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    t.b0 = 2;
    func_0204F6DC((u8 *)p->sys->f14, p->f14, (u8 *)(&t));
    func_021AC178(a);
}
