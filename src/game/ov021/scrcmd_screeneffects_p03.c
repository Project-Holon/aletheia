/*
 * file:     scrcmd_screeneffects_p03.c
 * unit:     yes
 * function: func_021AE890, func_021AE8B4, func_021AE8D4, func_021AE930, func_021AE948, func_021AE994, func_021AE9CC, func_021AE9F0, func_021AEA3C
 * address:  0x021AE890
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_021AE79C  0x021AE79C  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021AE454  0x021AE454  thumb  ov021
 *   func_021AE430  0x021AE430  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */
struct BigObj;
struct Ctx;
struct Rec;
struct Desc;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; } S;

typedef struct R { u8 pad[0x14]; u32 f14; u32 f18; } R;

extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned func_0215A4D8(void *a, unsigned b);
extern void *func_02188C80(void *p);
extern int func_021AE884(u32 a);
extern u32 func_0216D5B8(void *p);
extern void *func_0216D67C(void *a0);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_021AE79C(u32 a);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern char *func_02159124(char *p, int i);
extern u16 func_0215A5CC(void *a0);
extern u32 func_021AE454(void *a, u32 b, u32 *c, u32 d);
extern void *func_0215A5DC(void *a0);
extern u32 func_021AE430(u32 a, u32 x, u32 y);
extern void func_0215897C(void *vm, void *task);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0216D588(void *p);
int func_021AE890(u32 a, u32 b);
void func_021AE8B4(S *s, u32 a, u32 b, u32 c);
u32 func_021AE8D4(u32 a, u16 b);
int func_021AE930(int a, u32 b);
int func_021AE948(u32 a, u32 b);
int func_021AE994(u32 a, u32 b);
int func_021AE9CC(u32 a, u32 b);
int func_021AE9F0(u32 a, u32 b);
int func_021AEA3C(u32 a, u32 b);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE890(u32 a, u32 b)
{
return func_0215A4D8((void *)func_0201296C(func_020120F4((const struct Ctx *)func_02188C80((void *)a))), func_021AE884(b));
}


void func_021AE8B4(S *s, u32 a, u32 b, u32 c)
{
    s->f4 = b;
    s->f8 = c;
    s->fc = func_0216D5B8((void *)a);
    s->f10 = func_021AE884(a);
    s->f0 = a;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021AE8D4(u32 a, u16 b)
{
    u32 out;
    u32 iter;
    u32 h;

    iter = 0;
    h = (u32)func_0216D67C((void *)a);
    while (func_0216DD1C((struct Ctx *)h, (struct Rec **)(&out), &iter) == 1) {
        if (out != a && (u16)(func_021AE79C(out) + 0xFFFF) <= 1 && b == func_021AE884(out)) {
            return out;
        }
    }
    return 0;
}


int func_021AE930(int a, u32 b)
{
return (int)func_02158768((int)func_02188C80((void *)a), (226 << 4), b, 1);
}


int func_021AE948(u32 a, u32 b)
{
    u32 k;
    void *p;
    u32 *q;
    u32 *e;

    p = func_0215A5F4((void *)b);
    q = (u32 *)func_02158F58((int)p);
    k = func_02159B10((void *)a, (void *)b);
    if (k == 0) {
        e = (u32 *)func_02159124(p, 0);
    } else if (k == 1) {
        e = (u32 *)func_02159124(p, 1);
    }
    e[6] = func_021AE454((void *)func_0215A5CC((void *)b), q[1], e, k);
    return 0;
}


int func_021AE994(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    R *p = (R *)func_02159124(x, 0);
    R *q = (R *)func_02159124(x, 1);

    func_0215897C(x, (void *)func_021AE430((u32)func_0215A5DC((void *)b), p->f18, q->f18));
    return 1;
}


int func_021AE9CC(u32 a, u32 b)
{
    R *p = (R *)func_02159124(func_0215A5F4((void *)b), 0);

    *func_02159AE8((void *)a, (void *)b) = p->f14;
    return 0;
}


int func_021AE9F0(u32 a, u32 b)
{
    u32 k;
    void *p;
    u16 *out;
    u32 *e;

    p = func_0215A5F4((void *)b);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    e = 0;
    if (k == 0) {
        e = (u32 *)func_02159124(p, 0);
    } else if (k == 1) {
        e = (u32 *)func_02159124(p, 1);
    }
    *out = e ? e[4] : 0;
    return 0;
}


int func_021AEA3C(u32 a, u32 b)
{
    u32 k;
    void *p;
    u16 *out;
    u32 *e;

    p = func_0215A5F4((void *)b);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    e = 0;
    if (k == 0) {
        e = (u32 *)func_02159124(p, 0);
    } else if (k == 1) {
        e = (u32 *)func_02159124(p, 1);
    }
    *out = e ? func_0216D588((void *)e[0]) : 0;
    return 0;
}
