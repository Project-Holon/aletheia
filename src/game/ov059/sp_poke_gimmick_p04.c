/*
 * file:     sp_poke_gimmick_p04.c
 * unit:     yes
 * function: func_021F3B68, func_021F3B90, func_021F3C6C, func_021F3CB8, func_021F3CFC
 * address:  0x021F3B68
 * region:   ov059
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021F3D9C  0x021F3D9C  thumb  ov059
 */
struct Ctx;
struct Desc;
struct Obj;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int b;
    V c;
    V d;
    int e;
    u16 f;
    u16 g;
} W_021F3B90;

typedef struct {
    u8 pad[0x24];
    u16 *p24;
} W_021F3CFC;

extern void *func_0201210C(const struct Ctx *p);
extern int *func_021897BC(char *p, int idx);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern int func_02188D2C(int *p);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern int func_021BE6E8(int a, int b, int c, int d);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern int func_021BE6BC(int *p);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(void *p, int i, u16 j, u16 k, int flag);
extern int func_021F3D9C(void *a);
void func_021F3B68(void *p, int v);
int func_021F3B90(void *a);
int func_021F3C6C(void *a);
int func_021F3CB8(void *a);
void func_021F3CFC(void *a, V *b, u16 c, u16 d);


void func_021F3B68(void *p, int v)
{
    int *o;
    o = func_021897BC(func_0201210C(p), 1);
    func_020122C0(p, 0, func_021F3CB8, 0);
    *o = v;
}


/*
 * note:     the task callback func_021F39B8 installs: steps w->g towards
 *           w->f and interpolates a position between w->c and w->d with a
 *           bump of w->e on the middle axis. Each difference goes through
 *           the named temporary k (the original computes it into r1 and
 *           copies it to r0 for muls; inline, it lands in r0 and the
 *           function is 6 bytes short). The tail is one if with the
 *           return 1 inside it (the inverse early return flips the blo).
 */
int func_021F3B90(void *a)
{
    void *t;
    void *s;
    W_021F3B90 *w;
    int flag;
    int n;
    int d;
    int k;
    V pos;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    flag = 1;
    w = (W_021F3B90 *)func_021897BC(t, 1);
    if (w->b == 0)
        flag = 0;
    w->g++;
    n = w->g;
    d = w->f;
    k = w->d.a - w->c.a;
    pos.a = w->c.a + k * n / d;
    k = w->d.b - w->c.b;
    pos.b = w->c.b + k * n / d;
    k = w->d.c - w->c.c;
    pos.c = w->c.c + k * n / d;
    if (n >= (d + 1) / 2)
        n = d - n;
    pos.b += w->e * n / d;
    *func_021BE480(s, 0, flag) = pos;
    if (w->g >= w->f) {
        if (w->b == 1)
            func_021BE4B4(s, 0, (u16)flag, 1);
        return 1;
    }
    return 0;
}


int func_021F3C6C(void *a)
{
    void *t;
    void *s;
    int lim;
    int flag;
    int *p;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    p = func_021897BC(t, 1);
    flag = 1;
    if (*p == 0) {
        lim = 0x5000;
        flag = 0;
    } else {
        lim = 0x22000;
    }
    if (func_021BE6E8((int)s, 0, (u16)flag, 0) >= lim) {
        return 1;
    }
    return 0;
}


int func_021F3CB8(void *a)
{
    void *t;
    void *s;
    int flag;
    int *p;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    p = func_021897BC(t, 1);
    flag = 1;
    if (*p == 0) {
        flag = 0;
    }
    if (func_021BE6BC(func_021BE674(s, 0, (u16)flag, 0))) {
        return 1;
    }
    return 0;
}


void func_021F3CFC(void *a, V *b, u16 c, u16 d)
{
    int i;
    void *t;
    void *s;
    W_021F3CFC *w;
    u16 *q;

    t = func_0201210C(a);
    w = (W_021F3CFC *)func_021897BC(t, 1);
    s = (void *)func_02188D2C(t);
    q = w->p24;
    q[0] = c;
    q[1] = d;
    *func_021BE480(s, 0, 2) = *b;
    func_021BE4B4(s, 0, 2, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, (u16)2, (u16)i), 0);
        func_021BE700(s, 0, 2, i, 1);
        func_021BE6CC(s, 0, 2, i, 0);
    }
    func_020122C0(a, 0, func_021F3D9C, 0);
}
