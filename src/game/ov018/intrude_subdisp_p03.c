/*
 * file:     intrude_subdisp_p03.c
 * unit:     yes
 * function: func_0217CE6C, func_0217CEE8, func_0217CF0C, func_0217CF68, func_0217CF88
 * address:  0x0217CE6C
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
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D324C  0x021D324C  thumb  ov093
 *   func_021A0F40  0x021A0F40  thumb  ov021
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_0217BF84 0x0217BF84 thumb ov018
 *   func_020120F4  0x020120F4  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0217BBCC  0x0217BBCC  thumb  ov018
 *   func_0217BBD8  0x0217BBD8  thumb  ov018
 *   func_0217BC94  0x0217BC94  thumb  ov018
 *   func_0217C194  0x0217C194  thumb  ov018
 */
struct Ctx;
struct Desc;
struct Obj_0217CEE8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } V12;

typedef struct { int f0, f4, f8; } Obj_0217CEE8;

typedef struct {
    int f0;
    int f4;
    int f8;
} Obj_0217CF0C;

extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern u32 *func_0217BEA8(u16);
extern void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj_0217CEE8 *p);
extern u32 func_02188E30(u8 *p);
extern void func_021D324C();
extern void func_021A0F40(u32 *p, u32 v);
extern void *func_0215A5DC(void *);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0217BF84(int a);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern u32 func_02026474(void *obj);
extern void func_0217BBCC(int a, int b, char *p);
extern void func_0217BBD8(u8 *a, int b, u8 *c);
extern void func_0217BC94(int a, int n);
extern void func_0217C194();
void *func_0217CE6C(void *a0, void *a1, int a2);
void *func_0217CEE8(void *p, int a, int b);
int func_0217CF0C(int a0, int *state, Obj_0217CF0C *o);
int func_0217CF68(void *unused, void *p);
int func_0217CF88(int a0, int a1);


void *func_0217CE6C(void *a0, void *a1, int a2)
{
    u8 *p;
    u32 *q;
    V12 v;
    u16 s;

    p = (u8 *)func_02158344(func_02012138(a0));
    if (p == 0 || !(p[0x8FB] & (1 << a2)))
        return 0;
    q = func_0217BEA8(*(u16 *)(p + a2 * 0x1C + 0xA0));
    if (q == 0)
        return 0;
    s = (*q << 2) >> 22;
    v = *(V12 *)(p + a2 * 0x1C + 0x90);
    v.z += 0x20000;
    return func_02184D38(a0, (int)a1, s, (const int *)(&v), 0, 0);
}

void *func_0217CEE8(void *p, int a, int b)
{
    void *task;
    int *work;
    task = func_020122C0(p, 0, func_0217CF0C, 12);
    work = func_020124E8(task);
    work[0] = a;
    work[1] = b;
    return task;
}


int func_0217CF0C(int a0, int *state, Obj_0217CF0C *o)
{
    switch (*state) {
    case 0:
        o->f8 += 1;
        if (o->f8 > 15) {
            func_021D324C(func_02188E30((u8 *)o->f0), -16);
            *state += 1;
        }
        break;
    case 1:
        func_021A0F40((u32 *)o->f4, 0);
        *state += 1;
        break;
    case 2:
        func_021D324C(func_02188E30((u8 *)o->f0), 0);
        *state += 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}

int func_0217CF68(void *unused, void *p)
{
    void *sys;
    void *obj;
    sys = func_0215A5DC(p);
    obj = func_0201210C(sys);
    func_02012138(sys);
    func_0217BF84((int)obj);
    return 0;
}


int func_0217CF88(int a0, int a1)
{
    void *w;
    void *c;
    int h;
    int v;

    w = func_0215A5DC((void *)a1);
    func_020120F4((const struct Ctx *)w);
    c = func_0201210C((void *)w);
    h = func_02012138(w);
    v = 0;
    if (func_02026454((void *)h) == 2)
        v = func_02026474((void *)h);
    if (v != 0) {
        func_0217BBCC((int)c, (int)w, (char *)v);
        func_0217BBD8((u8 *)c, (int)w, (u8 *)v);
    } else {
        func_0217BC94((int)c, 1);
    }
    func_0217C194(c);
    return 0;
}
