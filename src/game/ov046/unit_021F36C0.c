/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3838, func_021F38D4, func_021F3A04, func_021F3A28, func_021F3A88, func_021F3AD0, func_021F3B18, func_021F3B5C, func_021F3BC8, func_021F3BE8, func_021F3BFC, func_021F3C8C, func_021F3D40, func_021F3DE8, func_021F3EFC, func_021F3FA8, func_021F4020, func_021F4064, func_021F4078
 * address:  0x021F36C0
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F40D8  0x021F40D8  thumb  ov046
 *   d_021F4120     0x021F4120  data  a4
 *   d_021F4108     0x021F4108  data  a2
 *   d_021F4194     0x021F4194  data  a4
 *   d_021F4170     0x021F4170  data  a4
 *   d_021F4204     0x021F4204  data  a4
 *   d_021F41B8     0x021F41B8  data  a4
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   d_021F41C4  0x021F41C4  data  a4
 *   func_020124E4  0x020124E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006210  0x02006210  thumb
 *   func_021A3044  0x021A3044  thumb  ov021
 *   d_021F4130  0x021F4130  data  a4
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3DC  0x021BB3DC  thumb  ov021
 *   d_021F4430  0x021F4430  data  ov046  a4
 */
#include "../../matched/include/Obj20520.h"
#include "../../matched/include/Obj03644.h"

struct Big;
struct Ctx;
struct Rec94;
struct Obj00020;
struct VecFx32;
struct Desc;
struct Obj;
struct Evt;
struct Rec;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef signed int     s32;

typedef signed short s16;

typedef struct Q {
    int a0;
    int a4;
    int *a8;
    u8 c;
    u8 d;
    u8 e;
    u8 pad;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
} Q;

extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE760(u32 p, void *a, int b);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F40D8(int *p);
extern int func_021BE480(char *p, unsigned i, int j);
extern void  func_021BE4A4(void *p, int i, u16 j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void  func_0207AF1C(void *m, int a, int b);
extern void func_021BE6CC(u32 a, int b, u16 c, u16 d, int e);
extern int func_021BE748(u32 a);
extern int *func_021897BC(char *,int);
extern void func_021897A0(u8 *,int);
extern void func_021BE418(u8 *,u16);
extern void func_021BE580(u32);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021BE6BC(int *p);
extern void func_020061E4(u32 a);
extern void func_02006210(void);
extern void func_021A3044(u8 *p, void *v);
extern void func_021BE4B4(char *ctx, int b, int c, u32 d);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 func_0216D588(void *p);
extern void func_0216DAC8(u32 *,u32);
extern u32 func_02188C5C(u8 *p);
extern void func_021BB3DC(u32 *p, int b, int c);
void func_021F36C0(void *a0);
void func_021F3838(void *a0, int a1, V *a2, u16 *a3, int a4, int a5);
void func_021F38D4(u8 *base, u32 t, int idx);
void func_021F3A04(u32 a);
void func_021F3A28(void *a);
void func_021F3A88(void *a, int b, int c);
void func_021F3AD0(void *a, int b, int c);
void func_021F3B18(void *a, int b);
void *func_021F3B5C(void *a, int b);
int func_021F3BC8(int *p);
int func_021F3BE8(int *p, int i);
int func_021F3BFC(u32 a, int *b);
int func_021F3C8C(u32 a, int *b);
int func_021F3D40(u32 a, int *b);
int func_021F3DE8(void *a, int *st);
int func_021F3EFC(u32 a, int *b);
void func_021F3FA8(char *a, u32 b, u32 c);
int func_021F4020(u32 a, int b);
void func_021F4064(u32 a,int b,u32 c);
void func_021F4078(u32 a, int b, int c);
extern int d_021F4120;
extern u16 d_021F4108[];
extern V d_021F4194[];
extern V d_021F4170[];
extern V d_021F4204[];
extern V d_021F41B8;
extern s16 d_020A1B38[];
extern int d_021F41C4[][4];
extern int d_021F4130[];
extern int d_021F4430[][4][6];



void func_021F36C0(void *a0)
{
    V tmp;
    int vec[3];
    u16 v;
    int i;
    u32 t;
    u8 *w;
    u8 *x;
    int n;
    int f;

    t = func_02188D2C(a0);
    w = (u8 *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(a0))), 10);
    x = func_02189764(a0, 1, func_02188C84(a0), 0x28);
    func_021BE760(t, &d_021F4120, 0);
    for (i = 0; i < 3; i++) {
        v = 0;
        v = d_021F4108[i];
        n = i * 5;
        func_021F3838((void *)t, n, &d_021F4194[i], &v, 8, 0);
        func_021F3838((void *)t, n + 1, &d_021F4170[i], &v, 2, 0);
        func_021F3838((void *)t, n + 2, &d_021F4170[i], &v, 2, 0);
        func_021F3838((void *)t, n + 3, &d_021F4204[i * 2], 0, 1, 1);
        func_021F3838((void *)t, n + 4, &d_021F4204[i * 2 + 1], 0, 1, 1);
        func_021F38D4(w, t, i);
    }
    tmp = d_021F41B8;
    func_021F3838((void *)t, 0xf, &tmp, 0, 0, 0);
    func_021BE700((void *)t, 0, 0xf, 0, 1);
    func_021A3038(func_02188CB4((void *)a0), (struct VecFx32 *)vec);
    f = func_021F40D8(vec) != 0 ? 1 : 0;
    func_021F3FA8((char *)t, (u32)a0, f);
    ((struct Obj20520 *)x)->f24 = f;
    for (i = 0; i < 3; i++)
        func_021F4078((u32)a0, i, *(int *)(w + i * 12));
}



void func_021F3838(void *a0, int a1, V *a2, u16 *a3, int a4, int a5)
{
    char *e;
    void *b;
    int i;
    int k;

    e = (char *)func_021BE480(a0, (int)0, (u16)a1);
    *(V *)e = *a2;
    if (a3) {
        k = (*a3 >> 4) * 2;
        func_0207AF1C(e + 0x18, d_020A1B38[k], d_020A1B38[k + 1]);
    }
    func_021BE4A4(a0, 0, a1, a5);
    for (i = 0; i < a4; i++) {
        b = func_021BE674(a0, 0, a1, i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
        func_021BE700(a0, 0, a1, i, 0);
    }
}









void func_021F38D4(u8 *base, u32 t, int idx)
{
    int *e;
    int n;
    int k;
    u8 *p;
    int m;
    int n1;
    u8 *q;
    int k3;
    int n2;
    u8 *r;

    e = (int *)(base + idx * 12);
    switch (e[0]) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 5;
        break;
    case 3:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    default:
        k = 1;
        break;
    }
    n = idx * 5;
    p = func_021BE674((void *)t, 0, n, k);
    func_021BE6B0(p, 0);
    func_021BE700((void *)t, 0, n, k, 1);
    func_021BE6CC(t, 0, n, k, func_021BE748((u32)p));
    m = 1;
    n1 = n + 1;
    if (e[1] == 0)
        m = 0;
    q = func_021BE674((void *)t, 0, n1, m);
    func_021BE6B0(q, 0);
    func_021BE700((void *)t, 0, n1, m, 1);
    func_021BE6CC(t, 0, n1, m, func_021BE748((u32)q));
    k3 = 1;
    n2 = n + 2;
    if (e[2] == 0)
        k3 = 0;
    r = func_021BE674((void *)t, 0, n2, k3);
    func_021BE6B0(r, 0);
    func_021BE700((void *)t, 0, n2, k3, 1);
    func_021BE6CC(t, 0, n2, k3, func_021BE748((u32)r));
}








void func_021F3A04(u32 a) { u32 p; p=func_02188D2C((int *)a); func_021897BC((char *)a,1); func_021897A0((u8 *)a,1); func_021BE418((u8 *)p,0); }









void func_021F3A28(void *a)
{
    int v[3];
    u32 r7 = func_02188D2C(a);
    int *r6 = func_021897BC(a, 1);
    int r4 = 1;

    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(a))), 10);
    func_021BE580(r7);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)v);
    if (func_021F40D8(v) == 0)
        r4 = 0;
    if (r6[9] != r4) {
        func_021F3FA8((char *)r7, (u32)a, r4);
        r6[9] = r4;
    }
}









void func_021F3A88(void *a, int b, int c)
{
    void *x = func_0201210C(a);
    int p;
    int *q;

    p = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[1] = c;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3BFC, 0);
}









void func_021F3AD0(void *a, int b, int c)
{
    void *x = func_0201210C(a);
    int p;
    int *q;

    p = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[1] = c;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3C8C, 0);
}









void func_021F3B18(void *a, int b)
{
    void *x = func_0201210C(a);
    int p;
    int *q;

    p = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3D40, 0);
}









/*
 * The negation is a multiply by 0xffffffff (see the idiom on
 * multiplying by minus one), and the +12 base is a separate local that
 * is formed after the func_020122C0 call.
 */
void *func_021F3B5C(void *a, int b)
{
    void *x = func_0201210C(a);
    char *q;
    int *w;
    void *r;
    int v[3];

    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = (char *)func_021897BC(x, 1);
    r = func_020122C0(a, 0, func_021F3EFC, 0);
    w = (int *)(q + 12);
    ((unsigned char *)w)[3] = 0;
    w[1] = 0x2000;
    func_021A3038(func_02188CB4((void *)x), (struct VecFx32 *)v);
    w[2] = v[1];
    if (b == 2)
        w[1] = w[1] * 0xffffffff;
    return r;
}








int func_021F3BC8(int *p)
{
    if (p[1] == 0) {
        if (p[2] == 0)
            return 0;
        return 3;
    }
    if (p[2] == 0)
        return 2;
    return 1;
}








/*
 * Unlabelled leaf (no lr push) between func_021F3BC8 and func_021F3BFC.
 */
int func_021F3BE8(int *p, int i)
{
    return d_021F41C4[*p][i] - 5;
}








/*
 * The 3/4 selector must be a ternary inside the sum with the ternary
 * first: an if-assigned local or `a0 * 5 + (...)` gets other registers.
 */
int func_021F3BFC(u32 a, int *b)
{
    void *h = func_020124E4((void *)a);
    void *x = func_0201210C(h);
    Q *q;
    int t;
    int i;

    func_02188D2C(x);
    q = (Q *)func_021897BC(x, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        q->c = (q->a4 == 0 ? 3 : 4) + q->a0 * 5;
        q->d = 1;
        q->p18 = 0;
        q->e = 1;
        q->p1c = 0x6d3;
        q->p20 = -1;
        func_02012374((void *)a, (struct Evt **)func_020122C0(h, 0, func_021F3DE8, 0));
        (*b)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






int func_021F3C8C(u32 a, int *b)
{
    void *h = func_020124E4((void *)a);
    void *x = func_0201210C(h);
    Q *q;
    int r;

    func_02188D2C(x);
    r = 1;
    q = (Q *)func_021897BC(x, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        if ((q->a8 + q->a4)[1] != 0)
            r = 0;
        q->c = (q->a4 == 0 ? 1 : 2) + q->a0 * 5;
        q->d = 1;
        q->p18 = r;
        q->e = 2;
        q->p1c = 0x6fc;
        q->p20 = 0x6fd;
        func_02012374((void *)a, (struct Evt **)func_020122C0(h, 0, func_021F3DE8, 0));
        (q->a8 + q->a4)[1] = r;
        (*b)++;
        break;
    case 1:
        return r;
    }
    return 0;
}





int func_021F3D40(u32 a, int *b)
{
    void *h = func_020124E4((void *)a);
    void *x = func_0201210C(h);
    Q *q;
    int t;
    int y;

    func_02188D2C(x);
    q = (Q *)func_021897BC(x, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        t = func_021F3BC8(q->a8);
        y = func_021F3BE8(q->a8, t);
        q->c = q->a0 * 5;
        q->d = 1;
        q->p18 = y;
        q->e = 8;
        q->p1c = 0x6d4;
        q->p20 = 0x6d9;
        func_02012374((void *)a, (struct Evt **)func_020122C0(h, 0, func_021F3DE8, 0));
        q->a8[0] = t;
        (*b)++;
        break;
    case 1:
        func_021F4078((u32)x, q->a0, *q->a8);
        return 1;
    }
    return 0;
}




int func_021F3DE8(void *a, int *st)
{
    void *s;
    u32 t;
    u8 *w;
    u8 k;
    int i;
    u8 v;

    s = func_0201210C(func_020124E4(a));
    t = func_02188D2C(s);
    w = (u8 *)func_021897BC(s, 1) + 0xc;
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(s))), 10);
    switch (*st) {
    case 0:
        k = w[0];
        for (i = 0; i < w[2]; i++) {
            func_021BE6B0((void *)func_021BE674((void *)t, 0, k, i), 1);
            func_021BE700((void *)t, 0, k, (u8)i, 0);
        }
        for (i = 0; i < w[1]; i++) {
            v = *(int *)(w + 0xc + i * 4);
            func_021BE6B0((void *)func_021BE674((void *)t, 0, k, v), 0);
            func_021BE700((void *)t, 0, k, (u8)v, 1);
            func_021BE6CC(t, 0, k, v, 0);
            func_020061E4(((struct Obj03644 *)w)->f10);
        }
        (*st)++;
        break;
    case 1:
        if (func_021BE6BC((void *)func_021BE674((void *)t, 0, w[0], (((struct Obj03644 *)w)->fC)))) {
            func_02006210();
            if (((struct Obj03644 *)w)->f14 != -1)
                func_020061E4(((struct Obj03644 *)w)->f14);
            return 1;
        }
        break;
    }
    return 0;
}




/*
 * The ov046 token is dropped from d_021F4130 (contested hint).
 */
int func_021F3EFC(u32 a, int *b)
{
    void *x;
    int *w;
    int r = 1;
    void *c;
    int v[3];

    x = func_0201210C(func_020124E4((void *)a));
    func_02188D2C(x);
    w = func_021897BC(x, 1) + 3;
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        func_020061E4(0x55e);
        (*b)++;
        break;
    case 1:
        c = func_02188CB4((void *)x);
        func_021A3038(c, (struct VecFx32 *)v);
        v[0] = v[0] + w[1];
        v[1] = w[2] + (d_021F4130[((u8 *)w)[3]] << 12);
        func_021A3044(c, v);
        ((u8 *)w)[3] = ((u8 *)w)[3] + 1;
        if (((u8 *)w)[3] >= 8) {
            func_020061E4(0x6d3);
            return r;
        }
        break;
    }
    return 0;
}




void func_021F3FA8(char *a, u32 b, u32 c)
{
    func_021BE4B4(a, 0, 15, c);
    func_021BE4B4(a, 0, 10, c);
    func_021BE4B4(a, 0, 11, c);
    func_021BE4B4(a, 0, 12, c);
    func_021BE4B4(a, 0, 13, c);
    func_021BE4B4(a, 0, 14, c);
    func_021F4064(b, 4, c);
    func_021F4064(b, 5, c);
    func_021F4064(b, 9, c);
    func_021F4064(b, 6, c);
}




int func_021F4020(u32 a, int b)
{
    int s1 = 0;
    int s0;
    void *it = func_02188C7C((void *)a);

    while (func_0216DD1C(it, (struct Rec **)(&s0), (u32 *)(&s1)) == 1) {
        if (b == func_0216D588((void *)s0))
            return s0;
    }
    return 0;
}



void func_021F4064(u32 a,int b,u32 c) { u32 *p; p=(u32 *)func_021F4020(a,b); if(p) func_0216DAC8(p,c); }




/*
 * The table row is indexed inside the loop; the compiler hoists the
 * invariant row address (b's register reused for it). A `t = d[b][c]`
 * local before the loop colours b and the counter apart.
 * func_021BB3DC is ov021's thunk (reads r0-r2); ov214's label at the same
 * address is a different two-argument function.
 */
void func_021F4078(u32 a, int b, int c)
{
    int v1[6];
    int v2[6];
    u32 h = func_02188C5C((u8 *)a);
    int i;

    for (i = 0; i < 6; i++) {
        v1[i] = d_021F4430[b][c][i];
        v2[i] = 0;
    }
    if (c != 1) {
        v2[0] = 1;
        v2[1] = 1;
    }
    for (i = 0; i < 6; i++)
        func_021BB3DC((u32 *)h, v1[i], v2[i]);
}
