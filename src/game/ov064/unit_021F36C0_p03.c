/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F3970, func_021F3A44, func_021F3AC0, func_021F3ADC, func_021F3AF8, func_021F3BAC
 * address:  0x021F3970
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3BD8  0x021F3BD8  thumb  ov064
 *   func_020124E4  0x020124E4  thumb
 *   func_021BE6E8 0x021BE6E8 thumb ov021
 */
struct Ctx;
struct Desc;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct {
    u8 pad[0x18];
    V3 v18;
    V3 v24;
    int f30;
    u16 h34;
    u16 h36;
} W_021F3970;

typedef unsigned int   u32;

typedef struct {
    u8 pad[0x18];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    u16 h34;
    u16 h36;
} W_021F3AF8;

extern void *func_0201210C(const struct Ctx *p);
extern int *func_021897BC(char *p, int idx);
extern int func_02188D2C(int *p);
extern void func_020061E4(u32 a);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern void func_021BE6CC(int a, int b, int c, u16 d, int e);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3BD8(void *p);
extern void *func_020124E4(struct Obj *p);
extern int func_021BE6E8(int a, int b, int c, int d);
void func_021F3970(int a, const V3 *p0, const V3 *p1, int f30, int n);
void func_021F3A44(int a, V3 *v);
void *func_021F3AC0(void *p);
void *func_021F3ADC(void *p);
int func_021F3AF8(void *task);
int func_021F3BAC(void *p);


void func_021F3970(int a, const V3 *p0, const V3 *p1, int f30, int n)
{
    int i;
    void *sys;
    int s;
    W_021F3970 *w;

    sys = func_0201210C((void *)a);
    w = (W_021F3970 *)func_021897BC((char *)sys, 1);
    s = func_02188D2C(sys);
    func_020061E4(0x566);
    *(V3 *)func_021BE480((char *)s, 0, 1) = *p0;
    func_021BE4B4((char *)s, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674((char *)s, 0, (int)1, (u16)i), 1);
        func_021BE700(s, 0, 1, i, 0);
        func_021BE6CC(s, 0, 1, i, 0);
    }
    w->v18 = *p0;
    w->v24 = *p1;
    w->h34 = n;
    w->h36 = 0;
    w->f30 = f30;
    func_020122C0((void *)a, 0, (void *)func_021F3AF8, 0);
}


void func_021F3A44(int a, V3 *v)
{
    int i;
    int s;

    s = func_02188D2C(func_0201210C((void *)a));
    func_020061E4(0x567);
    *(V3 *)func_021BE480((char *)s, 0, 1) = *v;
    func_021BE4B4((char *)s, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674((char *)s, 0, (int)1, (u16)i), 0);
        func_021BE700(s, 0, 1, i, 1);
        func_021BE6CC(s, 0, 1, i, 0);
    }
}


void *func_021F3AC0(void *p)
{
    func_0201210C(p);
    return func_020122C0(p, 0, func_021F3BAC, 0);
}


void *func_021F3ADC(void *p)
{
    func_0201210C(p);
    return func_020122C0(p, 0, func_021F3BD8, 0);
}


int func_021F3AF8(void *task)
{
    V3 v;
    W_021F3AF8 *w;
    void *sys;
    int s;
    int n;
    int m;
    int a;
    int d;

    sys = func_0201210C(func_020124E4(task));
    s = func_02188D2C(sys);
    w = (W_021F3AF8 *)func_021897BC((char *)sys, 1);
    w->h36++;
    a = w->f18;
    n = w->h36;
    d = w->f24 - a;
    m = w->h34;
    v.a = a + d * n / m;
    a = w->f1c;
    d = w->f28 - a;
    v.b = a + d * n / m;
    a = w->f20;
    d = w->f2c - a;
    v.c = a + d * n / m;
    if (n >= (m + 1) / 2)
        n = m - n;
    v.b += w->f30 * n / m;
    *(V3 *)func_021BE480((char *)s, 0, 1) = v;
    if (w->h36 >= w->h34)
        return 1;
    return 0;
}


/*
 * checks: 1 own BE6E8 confirms four args/int return and matched accessor chain confirms pointer forwarding; 2 ov064/065 callers refreshed; 3 _Bool zero/flag retained, 4 two initialisation-order variants stayed DIFF4, 5 idioms/neighbours refreshed. W75 three fixed runs, baseline explain, first permuter300 reached EXACT* at candidate102; fixed one and shard verify confirmed it.
 * lever: initialise flag after the callee result has been captured; the
 * saved zero is then materialised before the saved one. The trailing
 * halfword at 021F3BD6 is zero alignment padding.
 */
int func_021F3BAC(void *p)
{
    unsigned char zero;
    unsigned char flag;
    int v;
    int s;
    int tmp;
    s = func_02188D2C(func_0201210C(func_020124E4(p)));
    zero = 0;
    tmp = func_021BE6E8(s, zero, 1, zero);
    v = tmp;
    flag = 1;
    if (v < 0x5000)
        flag = zero;
    return flag;
}
