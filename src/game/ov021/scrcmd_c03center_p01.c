/*
 * file:     scrcmd_c03center_p01.c
 * unit:     yes
 * function: func_021B5A18, func_021B5B0C, func_021B5B4C, func_021B5B8C, func_021B5BFC
 * address:  0x021B5A18
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0218ED50  0x0218ED50  thumb  ov021
 *   func_0218FE70  0x0218FE70  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DE25C     0x021DE25C  data  a1
 *   g_021EE724     0x021EE724  data  a2
 *   g_021EE724_ref 0x021EE724  data  a2
 *   _s32_div_f     0x0209C0A4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A07C  0x0215A07C  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200C11C  0x0200C11C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0200C2B0  0x0200C2B0  thumb
 */
#include "../../matched/include/Obj20016.h"

struct Ctx;
struct Node;
struct Blk34;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Ramp;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u32 func_02159B10(void *, void *);
extern void func_0216CDB8(u8 *p, u32 v);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188D30(u8 *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern void *func_02188C7C(u8 *p);
extern u8 *func_0218ED50(u8 *p);
extern u8 *func_0218FE70(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(u32, void (*)(), void *, u32);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A07C(int a, u16 *b, u16 *c);
extern void func_0215897C(void *vm, void *task);
extern int func_0215B4AC(void *a0, unsigned int a1, void **out);
extern void *func_02012F08(int *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0200C11C(struct Blk34 *p, u16 a, u32 b, u32 c, u32 d);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *a0);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0200C2B0(struct Blk34 *p, u32 i, const u16 *src);
int func_021B5A18(void *a, void *b);
void func_021B5B0C(int a0, Ramp *p);
int func_021B5B4C(void *a0, void *a1);
int func_021B5B8C(void *a, void *b);
int func_021B5BFC(void *a, void *b);
extern const char d_021DE25C[];
extern u16 g_021EE724;
extern u16 g_021EE724_ref;


/*
 * Allocates the Ramp record func_021B5B0C steps (its own matched source
 * names the fields) and starts it as a task.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5A18(void *a, void *b)
{
    void *sys;
    u32 task;
    u32 heap;
    u8 *obj;
    u8 *snd;
    Ramp *p;
    u32 n;
    u8 *q;
    int v;
    u32 m;
    int d;

    func_0215A5F4(b);
    sys = func_0215A5DC(b);
    func_0215A5E4(b);
    sys = func_0201210C(sys);
    task = func_02188D30(sys);
    heap = func_02188C84(sys);
    obj = func_02188C58(sys);
    snd = func_02188C7C(sys);
    n = func_02159B10(a, b);
    p = func_02030734(heap, 0x10, 1, d_021DE25C, 0x5d);
    g_021EE724 = *(u16 *)func_0218ED50(obj);
    func_0216CDB8(snd, (u32)&g_021EE724_ref);
    q = func_0218FE70(obj);
    p->f0 = g_021EE724;
    v = ((struct Obj20016 *)q)->f26;
    p->f4 = v;
    m = v % 0x4000;
    if (m >= 0x2000) {
        p->f4 = v + (0x4000 - m);
    } else {
        p->f4 = v - m;
    }
    p->f4 -= p->f0;
    d = p->f4;
    if ((d < 0 ? -d : d) >= 0x8000) {
        if (d > 0) {
            p->f4 -= 0x10000;
        } else {
            p->f4 += 0x10000;
        }
    }
    p->f8 = 0;
    p->fc = n;
    func_02030DA8(task, (void (*)())func_021B5B0C, p, 0);
    return 0;
}


void func_021B5B0C(int a0, Ramp *p)
{
    p->f8++;
    g_021EE724 = (p->f4 * p->f8) / p->fc;
    g_021EE724 = g_021EE724 + (u16)p->f0;
    if (p->f8 >= p->fc) {
        func_020307B0(p);
        func_02030EAC((struct Node *)a0);
    }
}


int func_021B5B4C(void *a0, void *a1)
{
    u16 *a = func_02159AE8(a0, a1);
    u16 *b = func_02159AE8(a0, a1);
    void *r4;

    func_02159B10(a0, a1);
    r4 = func_0215A5F4(a1);
    func_0215897C(r4, func_0215A07C((int)func_0215A5DC(a1), a, b));
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B5B8C(void *a, void *b)
{
    void *rec;
    struct Blk34 *x;
    u16 v5, v6f, v4c, v6e;

    if (func_0215B4AC(b, func_02159B10(a, b), &rec) == 1) {
        x = func_02012F08(func_0215A5E4(b));
        v5 = func_02017E1C(rec, 5, 0);
        v6f = func_02017E1C(rec, 0x6f, 0);
        v4c = func_02017E1C(rec, 0x4c, 0);
        v6e = func_02017E1C(rec, 0x6e, 0);
        func_0200C11C(x, v5, v6f, v4c, v6e);
    }
    return 0;
}


int func_021B5BFC(void *a, void *b)
{
    u16 buf[6];
    void *sav;
    unsigned int r;
    void *bag;
    void *mon;
    int i;
    int j;
    int n;

    sav = func_0215A5E4(b);
    bag = func_02012934(sav);
    r = func_02159B10(a, b);
    for (i = 0; i < 6; i++)
        buf[i] = 0;
    for (j = 0, n = 0; j < (int)func_0201AA18(bag); j++) {
        mon = func_0201AB28(bag, j);
        if (func_02017E1C(mon, 0x4C, 0) == 0)
            buf[n++] = func_02017E1C(mon, 5, 0);
    }
    func_0200C2B0(func_02012F08(sav), r, buf);
    return 0;
}
