/*
 * file:     event_poke_status_p14.c
 * unit:     yes
 * function: func_0215A064, func_0215A07C, func_0215A0E8, func_0215A168, func_0215A214, func_0215A2E4, func_0215A370, func_0215A438, func_0215A460, func_0215A480, func_0215A490, func_0215A4A0, func_0215A4B4
 * address:  0x0215A064
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
 *   func_02159F84  0x02159F84  thumb  ov010
 *   func_02159F80  0x02159F80  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02030734  0x02030734  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   d_021728CC  0x021728CC  data
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_020307B0  0x020307B0  arm
 *   ov131_id       0x00000083  data
 *   d_021DC800     0x021DC800  data  ov131
 *   func_020120B4  0x020120B4  thumb
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 */
#include "../../matched/include/Obj07281.h"
#include "../../matched/include/Obj04920.h"
#include "../../matched/include/Obj03073.h"

struct BigObj;
struct Ctx;
struct Obj;
struct Desc;
struct Blk37;
struct Evt;
struct IcaAnime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    u32 *f8;
    void *fC;
    u16 *f10;
    u16 *f14;
} Task;

typedef struct { u32 pad[15]; int f3c; } O8_0215A214;

typedef struct {
    void *f0;
    void *f4;
    O8_0215A214 *f8;
    void *fC;
    u16 *f10;
    u16 *f14;
} Ctx_0215A214;

typedef struct { u8 pad[0x11]; u8 f11; u8 f12; } O8_0215A370;

typedef struct {
    void *f0;
    void *f4;
    O8_0215A370 *f8;
    u16 *fC;
    u16 *f10;
} Ctx_0215A370;

typedef struct {
    int w[6];
} S24;

typedef signed short   s16;

typedef signed char    s8;

extern int func_02159F84(int a0);
extern int func_02159F80();
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_0201AA18(void *p);
extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *);
extern u32 func_020307B0(void *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern int func_021589D0(int);
extern char *func_02159124(char *p, int i);
extern u32 func_0202A230(void *a, u32 idx);
int func_0215A064(int a0);
void *func_0215A07C(int a, u16 *b, u16 *c);
void *func_0215A0E8(int a, int b, int c, int d, unsigned short e);
void *func_0215A168(int a, int b, int c);
int func_0215A214(void *a, u32 *st, Ctx_0215A214 *c);
int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g);
int func_0215A370(void *a, u32 *st, Ctx_0215A370 *c);
void func_0215A438(int a, int b, S24 *src);
u32 func_0215A460(u32 a);
u16 func_0215A480(unsigned a);
u16 func_0215A490(unsigned a);
int func_0215A4A0(unsigned a);
int func_0215A4B4(int a0);
extern const char d_021728CC[];
extern u8 ov131_id[];
extern u8 d_021DC800[];


int func_0215A064(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02159F84(a0);
loc_0215A06C:
    if (a0 != 0) goto loc_0215A076;
loc_0215A070:
    a0 = func_02159F80();
loc_0215A074:
t4 = a0 + 0;
loc_0215A076:
a0 = t4 - 1;
    return a0;}


void *func_0215A07C(int a, u16 *b, u16 *c)
{
    void *h = func_02012934(func_020120F4((void *)a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x40);
    void *r;
    Task *q;
    ((struct Obj07281 *)p)->f0 = h;
    p[0x34 / 4] = 3;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q->f0 = (void *)a;
    q->f4 = func_0201210C((void *)a);
    q->f8 = p;
    q->fC = 0;
    q->f10 = b;
    q->f14 = c;
    return r;
}


void *func_0215A0E8(int a, int b, int c, int d, unsigned short e)
{
    void *h = func_02012934(func_020120F4((const struct Ctx *)a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x66);
    void *r;
    u32 *q;
    p[0] = (u32)h;
    p[0x34 / 4] = 0x18;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    *((unsigned char *)p + 0x5e) = d;
    ((struct Obj04920 *)p)->f46 = e;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = (u32)func_0201210C((void *)a);
    q[2] = (u32)p;
    q[3] = 0;
    q[4] = b;
    q[5] = c;
    return r;
}


void *func_0215A168(int a, int b, int c)
{
    void *h = func_020120F4((const struct Ctx *)a);
    void *l = func_02012934(h);
    int m = (int)func_0200CA1C(h);
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x90);
    u32 *s;
    void *r;
    u32 *q;
    p[0] = (u32)l;
    p[0x34 / 4] = 0x19;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    s = func_02030734(4, 0x28, 1, d_021728CC, 0x97);
    s[0] = (u32)l;
    s[2] = (u32)h;
    ((u8 *)s)[0xc] = 1;
    ((u8 *)s)[0xd] = 1;
    ((u8 *)s)[0xe] = func_0201AA18(l);
    ((u8 *)s)[0x10] = 0;
    s[0x18 / 4] = func_0200CA38((struct Blk37 *)m);
    s[0x20 / 4] = 0;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = (u32)func_0201210C((void *)a);
    q[2] = (u32)p;
    q[3] = (u32)s;
    q[4] = b;
    q[5] = c;
    return r;
}


int func_0215A214(void *a, u32 *st, Ctx_0215A214 *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    int v;
    switch (s) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)func_020144DC((int)p0, (int)c->f4));
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
        v = c->f8->f3c;
        if (v <= 5) {
            *c->f14 = v;
            *c->f10 = 1;
        } else {
            *c->f14 = 0;
            *c->f10 = 0;
        }
        func_020307B0(c->f8);
        if (c->fC != 0)
            func_020307B0(c->fC);
        return 1;
    }
    return 0;
}


int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g)
{
    int t8 = (int)func_020120F4((const struct Ctx *)a);
    void *t12 = func_02012934((void *)t8);
    char *p = (char *)func_02030734(4, 0x98, 1, (const char *)&d_021728CC, 0x11d);
    int r;
    int *q;

    ((struct Obj03073 *)p)->f0 = (int)t12;
    p[0xc] = 1;
    p[0xe] = func_0201AA18(t12);
    p[0xf] = c;
    p[0x10] = 1;
    ((struct Obj03073 *)p)->f14 = g;
    p[0xd] = (f == 1) ? 3 : 2;
    ((struct Obj03073 *)p)->f20 = 0;
    ((struct Obj03073 *)p)->f8 = t8;
    r = (int)func_020122C0((void *)a, 0, func_0215A370, 0x14);
    q = func_020124E8((struct Obj *)r);
    q[0] = a;
    q[1] = b;
    q[2] = (int)p;
    q[3] = d;
    q[4] = e;
    return r;
}


/*
 * Case 2 loads 0x00000083 from the pool: an absolute symbol (overlay id),
 * see docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 */
int func_0215A370(void *a, u32 *st, Ctx_0215A370 *c)
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
        *st = 2;
        break;
    case 2:
        func_020120B4(p0, (u32)ov131_id, d_021DC800, c->f8);
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
        if (c->f8->f12 == 0) {
            *c->f10 = c->f8->f11;
            *c->fC = 1;
        } else {
            *c->f10 = 0;
            *c->fC = 0;
        }
        func_020307B0(c->f8);
        return 1;
    }
    return 0;
}


void func_0215A438(int a, int b, S24 *src)
{
    int *q = (int *)func_02159124((char *)func_021589D0(a), b);

    *(S24 *)q = *src;
    q[6] = 0;
}

/*
 * Map a tick count onto a 3000/5000 ms window, truncated to 16 bits.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215A460(u32 a)
{
if (a < 5000)
return (u16)(a - 3000);
return (u16)(a - 5000);
}

u16 func_0215A480(unsigned a) { return a + 3000; }

/*
 * extent: includes unlabelled range-test func_0215A4A0; function-start seed.
 */
u16 func_0215A490(unsigned a) { return a + 5000; }

int func_0215A4A0(unsigned a) { if (a >= 5000) return 1; return 0; }


int func_0215A4B4(int a0)
{
    int a1;

a1 = 2;
    a0 = func_0202A230((void *)a0, a1);
loc_0215A4BC:
    if (a0 != 1) goto loc_0215A4C4;
loc_0215A4C0:
a0 = 1;
    return a0;
loc_0215A4C4:
a0 = 0;
    return a0;}
