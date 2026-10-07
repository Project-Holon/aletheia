/*
 * file:     pdw_postman_p03.c
 * unit:     yes
 * function: func_021B7740, func_021B7794, func_021B77E4, func_021B7834, func_021B785C, func_021B7864, func_021B7884, func_021B791C, func_021B7934, func_021B7954, func_021B7970
 * address:  0x021B7740
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
 *   func_0201292C  0x0201292C  thumb
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb
 *   func_021B7640  0x021B7640  thumb
 *   func_021B7574  0x021B7574  thumb
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A104  0x0200A104  thumb
 *   func_0200A000  0x0200A000  thumb
 *   func_0200A13C  0x0200A13C  thumb
 *   func_02030734  0x02030734  arm
 *   func_021B9164  0x021B9164  thumb
 *   g_021DE2A0     0x021DE2A0  data  a1
 *   func_020307B0  0x020307B0  arm
 *   func_021B9464  0x021B9464  thumb  ov021
 *   func_021B87C8  0x021B87C8  thumb  ov021
 *   func_021B87BC  0x021B87BC  thumb  ov021
 *   func_021B91A8  0x021B91A8  thumb ov021
 */
#include "../../matched/include/Obj18099.h"
#include "../../matched/include/Obj18100.h"

struct BigObj;
struct Sub02009210Obj;
struct Ctx;
struct Desc;
struct Work;
struct Big;
struct Sub02009448Obj;
struct Obj;
struct Pair;
struct Ent;
typedef unsigned char  u8;

typedef unsigned short u16;

struct Rec { unsigned short *f0; char pad04[4]; void *f8; char fC[4]; u16 f10; };

typedef unsigned int   u32;

struct Ent { u8 pad00[0xB3]; u8 fB3; };

struct Elem { u16 f0; u16 f2; char pad[0x78]; };

struct Obj {
    u16 f0;
    u16 f2;
    u16 f4;
    char pad06[2];
    struct Elem *f8;
    u32 fC;
    int f10;
    int f14;
    int f18;
    struct Elem *f1C;
    char f20[4];
};

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad[0x78];
} Elem;

typedef struct {
    u8 pad[8];
    Elem *arr;
    int count;
} Ctx;

extern void *func_0201292C(const struct BigObj *p);
extern u16 func_02009310(const struct Sub02009210Obj *obj, int i);
extern u8 func_02009330(const struct Sub02009210Obj *obj, int i);
extern int func_02007E3C(void *ctx, void *a, int b, int key);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02188C84(u8 *p);
extern struct Pair *func_021B7640(u32 a, u32 b, u32 c, int *d);
extern int func_021B7574(void *task, int *st, struct Work *w);
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A104(char *p, unsigned int idx);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_0200A13C(u8 *p, u32 i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021B9164(struct Elem *e, void *p, struct Obj *o);
extern u32 func_020307B0(void *p);
extern u32 func_021B87C8(u32, u32);
extern u16 *func_021B9464(u16 *p);
extern void func_021B87BC(u32 a);
extern u16 func_021B91A8(u8 *p);
void *func_021B7740(void *p, int key, void *q, int idx);
void *func_021B7794(void *p);
struct Ent *func_021B77E4(void *a, void *b, struct Ent *c);
void *func_021B7834(void *a, int *out, void *buf);
void func_021B785C(u8 *p, u32 i);
u8 func_021B7864(void *a);
struct Obj *func_021B7884(u16 heap, u32 n, int a2);
void func_021B791C(void **o);
int func_021B7934(u32 a, u32 b);
u32 func_021B7954(u32 a);
void func_021B7970(Ctx *c);
extern const char g_021DE2A0[];


void *func_021B7740(void *p, int key, void *q, int idx)
{
    void *ctx;
    int i;
    int n;
    void *a;
    int b;

    ctx = func_0201292C(p);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        a = (void *)func_02009310(q, i);
        b = func_02009330(q, i);
        if (a != 0) {
            if (func_02007E3C(ctx, a, b, key) == 0) {
                if (n == idx)
                    return a;
                n++;
            }
        }
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void *func_021B7794(void *p)
{
    void *a;
    void *b;
    void *res;
    struct Rec *r;

    a = func_020120F4(p);
    b = func_02009448(func_02012EBC(a));
    res = func_020122C0(p, 0, (void *)func_021B7574, 0x14);
    r = func_020124E8(res);
    r->f0 = func_0201210C(p);
    r->f10 = 0;
    r->f8 = func_021B7640((u32)a, func_02188C84((u8 *)r->f0), (u32)b, (int *)r->fC);
    return res;
}


struct Ent *func_021B77E4(void *a, void *b, struct Ent *c)
{
    u8 v;

    if (func_0200A0E4(a, (u32)b) == 0)
        return 0;
    if (func_0200A104(a, (unsigned int)b) == 1)
        return 0;
    if (func_0200A000(a, (int)b, c) == 0)
        return 0;
    v = c->fB3;
    if (v == 0)
        return 0;
    if (v > 3)
        c = 0;
    return c;
}


void *func_021B7834(void *a, int *out, void *buf)
{
    int i;

    for (i = 0; i < 12; i++) {
        if (func_021B77E4(a, (void *)i, buf)) {
            *out = i;
            return buf;
        }
    }
    return 0;
}


void func_021B785C(u8 *p, u32 i)
{
    func_0200A13C(p, i);
}


u8 func_021B7864(void *a)
{
    int idx;
    u8 buf[0xCC];
    u8 *p;

    p = func_021B7834(a, &idx, buf);
    if (p == 0) {
        return 0;
    }
    return p[0xB3];
}


struct Obj *func_021B7884(u16 heap, u32 n, int a2)
{
    u32 i;
    struct Obj *o;

    o = func_02030734(heap, 0x74, 1, g_021DE2A0, 302);
    o->f0 = heap;
    o->f2 = 0;
    o->f4 = 1;
    o->f10 = a2;
    o->f14 = 0;
    o->f8 = func_02030734(heap, 0x7c * n, 1, g_021DE2A0, 311);
    o->fC = n;
    for (i = 0; i < n; i++)
        func_021B9164(&o->f8[i], o->f20, o);
    o->f1C = func_02030734(heap, 0x7c, 1, g_021DE2A0, 319);
    func_021B9164(o->f1C, o->f20, o);
    o->f1C->f2 = 1;
    return o;
}


void func_021B791C(void **o)
{
    func_020307B0(o[7]);
    func_020307B0(o[2]);
    func_020307B0(o);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B7934(u32 a, u32 b)
{
((struct Obj18099 *)((u8 *)(a)))->f2 = 1;
func_021B9464((u16 *)(a + 80));
return func_021B87C8((a + 32), b);
}


u32 func_021B7954(u32 a)
{
((struct Obj18100 *)((u8 *)(a)))->f2 = 0;
func_021B87BC((a + 32));
return (u32)func_021B9464((u16 *)(a + 80));
}


void func_021B7970(Ctx *c)
{
    Elem *found = 0;
    int i;

    for (i = 0; i < c->count; i++) {
        if (func_021B91A8((u8 *)(&c->arr[i])) == 0) {
            found = &c->arr[i];
            break;
        }
    }
    found->f2 = 1;
}
