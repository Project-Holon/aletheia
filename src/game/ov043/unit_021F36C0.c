/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3938, func_021F395C, func_021F398C, func_021F3A28, func_021F3AC0, func_021F3D78, func_021F3ECC, func_021F3EEC, func_021F3F38, func_021F3FBC, func_021F3FE8, func_021F4174, func_021F41B8, func_021F4210
 * address:  0x021F36C0
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F4510     0x021F4510  data  a4
 *   d_021F4480     0x021F4480  data  a4
 *   d_021F4318     0x021F4318  data  a4
 *   d_021F4358     0x021F4358  data  a4
 *   d_021F434C     0x021F434C  data  a4
 *   d_021F4340     0x021F4340  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0218CEE0  0x0218CEE0  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021C0628  0x021C0628  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   sub_02030344   0x02030344  arm
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   d_021F4490    0x021F4490  data  a4
 *   func_020124E4  0x020124E4  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021C06C0  0x021C06C0  thumb  ov021
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   d_021F4328     0x021F4328  data  ov043
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_02188C68  0x02188C68  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 */
#include "../../matched/include/Obj02756.h"
#include "../../matched/include/Obj01223.h"

struct Big;
struct Ctx;
struct Obj00020;
struct Rec94;
struct VecFx32;
struct Desc;
struct Obj;
struct Rec;
struct Actor;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} EA;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int f10[2];
} BtnRect;

typedef signed int     s32;

typedef struct {
    int v[2];
    int pad[4];
} E;

typedef signed short s16;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

extern int func_02188D2C(int *p);
extern u32 func_02188C64(u8 *p);
extern void *func_02188C80(void *p);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C98(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_0218CEE0(void *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void  func_021C0628(u8 i, int a, int b, int c, int d, int e, int f, void *t);
extern void  func_021BE760(void *p, void *a, int b);
extern int func_021BE480(char *p, unsigned i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern int func_021BE748(u32 a);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int   func_021A01BC(u32 a, u32 b);
extern int   func_021A01B4(u32 a, u32 b);
extern void *sub_02030344(u32 heapId);
extern int *func_021897BC(char *, int);
extern void func_021897A0(u8 *, int);
extern void func_021BE418(u8 *, u16);
extern void func_021BE580(void *);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void *func_02188C58(void *p);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern Vec *func_0216D888(u32 o);
extern void func_0216D85C(void *p, int v);
extern void func_0216D89C(u32 o, Vec *v);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F05C(unsigned char *a);
extern void func_020061E4(u32 a);
extern int func_021BE6BC(int *p);
extern void func_021C06C0(u8 i, int v, int *p);
extern int func_021A0244(u8 *p);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern void func_0218EC30(u32 a, int v);
extern void func_021A3044(u8 *p, void *v);
extern int func_02006148(u32 a0);
extern void func_020061F8(int i);
extern u32 func_02188C68(u8 *p);
extern int func_021A03A4(int *p);
extern int func_021A03B8(int *p);
extern void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
extern void func_0218ECC4(int p, void *v);
extern void func_0218ECD4(int p, void *v);
void func_021F36C0(void *a0);
void func_021F3938(u8 *p);
void func_021F395C(u8 *p);
int func_021F398C(void *a, int b);
void func_021F3A28(void *a0, int a1);
int func_021F3AC0(void *a, int *b);
int func_021F3D78(void *a, int *b);
int func_021F3ECC(int *p);
int func_021F3EEC(u8 i, int x, int y);
void func_021F3F38(int *a, void *b, int c);
int func_021F3FBC(int *a, int i);
void func_021F3FE8(void *a);
void func_021F4174(void *p);
void func_021F41B8(int a0, int a1, int a2, int a3, u8 *s);
int func_021F4210(u8 *s);
extern const EA d_021F4510[];
extern const BtnRect d_021F4480[];
extern int d_021F4318;
extern const V d_021F4358[];
extern const V d_021F434C;
extern const V d_021F4340;
extern E d_021F4490[];
extern int d_021F4328[];




void func_021F36C0(void *a0)
{
    void *s;
    int *q;
    u32 g;
    void *w;
    V *e;
    void *b;
    int i;
    int k;
    u8 flag;
    u8 x;
    int pos[3];

    s = (void *)func_02188D2C(a0);
    g = func_02188C64(a0);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(a0))), 7);
    func_02189764(a0, 1, func_02188C84(a0), 0x58);
    w = func_0218CEE0((void *)func_02188C98(a0));
    for (i = 0; i < 8; i++) {
        func_021C0628(i, d_021F4510[i].f0, d_021F4510[i].f4, d_021F4510[i].f8,
                      d_021F4510[i].fc, d_021F4510[i].f10, 0x800000, w);
    }
    for (i = 0; i < 6; i++) {
        x = i + 8;
        if (q[i] != 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        func_021C0628(x, d_021F4480[i].x, d_021F4480[i].y, d_021F4480[i].w,
                      d_021F4480[i].h, d_021F4480[i].f10[flag], 0x800000, w);
    }
    func_021BE760(s, &d_021F4318, 0);
    for (i = 0; i < 6; i++) {
        e = (V *)func_021BE480((char *)s, 0, i);
        *e = d_021F4358[i];
        flag = q[i] ? 1 : 0;
        e->b = d_021F4480[i].f10[flag];
        func_021BE4A4(s, 0, (u16)i, 1);
        for (k = 0; k < 2; k++) {
            b = func_021BE674(s, 0, i, k);
            func_021BE6B8(b, 0);
            func_021BE6B0(b, 1);
        }
        func_021F3F38(q, s, i);
    }
    e = (V *)func_021BE480((char *)s, 0, 7);
    *e = d_021F434C;
    func_021BE4A4(s, 0, (u16)7, 1);
    for (k = 0; k < 2; k++) {
        b = func_021BE674(s, 0, 7, k);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
    }
    func_021F4174(s);
    e = (V *)func_021BE480((char *)s, 0, 6);
    *e = d_021F4340;
    func_021BE4A4(s, 0, (u16)6, 1);
    func_021BE700(s, 0, 6, 0, 1);
    b = func_021BE674(s, 0, 6, 0);
    func_021BE6B8(b, 0);
    func_021BE6B0(b, 1);
    if (q[6]) {
        func_021BE6CC((int)s, 0, 6, 0, func_021BE748((u32)b));
    }
    func_021A3038(func_02188CB4(a0), (struct VecFx32 *)pos);
    if (pos[1] <= -0x280000) {
        func_021A01BC(g, 0x7FDF);
        func_021A01B4(g, 9);
    }
    sub_02030344(0x15);
}



void func_021F3938(u8 *p)
{
    int x = func_02188D2C((int *)p);
    func_021897BC((char *)p, 1);
    func_021897A0(p, 1);
    func_021BE418((u8 *)x, 0);
}



void func_021F395C(u8 *p)
{
    int x = func_02188D2C((int *)p);
    func_021897BC((char *)p, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(p))), 7);
    func_021BE580((void *)x);
}




int func_021F398C(void *a, int b)
{
    void *s;
    int *q;
    int *p;
    int step;

    s = func_0201210C((void *)a);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    p = func_021897BC(s, 1);
    if (b >= 6) {
        return 0;
    }
    p[0] = b;
    if (q[b] != 0) {
        p[1] = d_021F4490[b].v[1];
        p[2] = d_021F4490[b].v[0];
    } else {
        p[1] = d_021F4490[b].v[0];
        p[2] = d_021F4490[b].v[1];
    }
    if (b == 5) {
        step = 0x8000;
        p[15] = 1;
    } else {
        step = 0x4000;
        p[15] = 0;
    }
    if (p[2] - p[1] < 0) {
        p[3] = -step;
    } else {
        p[3] = step;
    }
    p[16] = 0;
    return (int)func_020122C0(a, 0, func_021F3AC0, 0);
}




void func_021F3A28(void *a0, int a1)
{
    void *r6;
    int *r4;
    void *x;
    int d;

    r6 = func_0201210C(a0);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(r6))), 7);
    r4 = func_021897BC(r6, 1);
    r4[5] = a1;
    if (a1) {
        r4[1] = 0x320000;
        r4[2] = 0x370000;
    } else {
        r4[1] = 0x370000;
        r4[2] = 0x320000;
        x = (void *)func_02188D2C(r6);
        func_021BE700(x, 0, 7, 1, 1);
        func_021BE700(x, 0, 7, 0, 0);
    }
    d = r4[2] - r4[1];
    if (d < 0) {
        d = -0x2000;
    } else {
        d = 0x2000;
    }
    r4[3] = d;
    func_020122C0(a0, 0, func_021F3D78, 0);
}




int func_021F3AC0(void *a, int *b)
{
    Vec pos;
    Vec vec;
    Vec vec2;
    int it;
    u32 cur;
    void *t;
    void *s;
    void *r;
    int *w;
    u32 h;
    int *q;
    void *m;
    int n;
    int i;
    int x;
    int y;
    u32 o;
    int k;
    int f;
    void *e;
    int c;

    t = func_020124E4(a);
    s = func_0201210C(t);
    r = (void *)func_02188D2C(s);
    w = func_021897BC(s, 1);
    h = (u32)func_02188C58(s);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    switch (*b) {
    case 0:
        n = 0;
        it = 0;
        m = func_02188C7C((void *)s);
        for (i = 0; i < 5; i++) {
            w[17 + i] = 0;
        }
        func_021A3038(func_02188CB4((void *)s), (struct VecFx32 *)&pos);
        while (func_0216DD1C(m, (struct Rec **)(&cur), (u32 *)(&it)) == 1) {
            x = func_0216D83C((void *)cur);
            y = func_0216D86C((void *)cur);
            if (func_021F3EEC(w[0], x, y)) {
                func_0216D88C((const struct Actor *)cur, (struct VecFx32 *)&vec);
                if (pos.y - 0x10000 < vec.y && vec.y < pos.y + 0x10000 && n < 5) {
                    w[17 + n++] = cur;
                }
            }
        }
        func_021F41B8((u8)w[0], w[3], 1, (u32)h, (u8 *)(w + 8));
        (*b)++;
        break;
    case 1:
        if (func_021F4210((u8 *)(w + 8))) {
            (*b)++;
        }
        break;
    case 2:
        func_0218F0A8((u8 *)h);
        (*b)++;
        break;
    case 3:
        if (func_0218F0E8((u8 *)h) != 0) {
            break;
        }
        func_020061E4((int)0x6ca);
        (*b)++;
    case 4:
        if (w[6] == 0) {
            w[1] += w[3];
        }
        if (func_021F3ECC(w)) {
            w[1] = w[2];
            func_021F41B8((u8)w[0], w[3], 0, (u32)h, (u8 *)(w + 8));
            func_020061E4((int)0x6cb);
            (*b)++;
        }
        ((int *)func_021BE480(r, (int)0, (u16)w[0]))[1] = w[1];
        for (i = 0; i < 5; i++) {
            o = w[17 + i];
            if (o != 0) {
                vec2 = *func_0216D888(o);
                vec2.y = w[1];
                func_0216D85C((void *)o, (s16)((vec2.y >> 4) / 4096));
                func_0216D89C(o, &vec2);
            }
        }
        break;
    case 5:
        if (func_021F4210((u8 *)(w + 8))) {
            (*b)++;
        }
        break;
    case 6:
        func_0218F05C((unsigned char *)h);
        k = w[0];
        func_021BE6B0(func_021BE674(r, 0, (u16)k, (u16)func_021F3FBC(q, k)), 0);
        (*b)++;
        break;
    case 7:
        k = w[0];
        e = func_021BE674(r, 0, (u16)k, (u16)func_021F3FBC(q, k));
        f = 0;
        if (func_021BE6BC(e) == 0) {
            break;
        }
        if (q[w[0]]) {
            q[w[0]] = 0;
        } else {
            q[w[0]] = 1;
            f = 1;
        }
        c = (int)func_0218CEE0((void *)func_02188C98(s));
        func_021C06C0(w[0] + 8, d_021F4490[w[0]].v[f], (int *)c);
        func_021F3F38(q, r, w[0]);
        if (w[0] != 5) {
            return 1;
        }
        (*b)++;
        break;
    case 8:
        if (func_021A0244((u8 *)func_02188C64(s)) == 0) {
            return 1;
        }
        break;
    }
    func_021F3FE8(t);
    return 0;
}




int func_021F3D78(void *a, int *b)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    void *c;
    int v[3];

    s = func_0201210C(func_020124E4(a));
    r = (void *)func_02188D2C(s);
    w = func_021897BC(s, 1);
    h = (u32)func_02188C58(s);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    switch (*b) {
    case 0:
        if (w[5] != 0) {
            w[4] = func_0218EC5C((u8 *)h);
            func_0218EC54((u8 *)h);
        }
        func_020061E4(w[5] == 0 ? 0x6da : 0x6ca);
        (*b)++;
        break;
    case 1:
        w[1] += w[3];
        if (func_021F3ECC(w)) {
            w[1] = w[2];
            if (w[5] == 0) {
                func_021F41B8(0xff, w[3], 0, h, (u8 *)(w + 8));
                func_020061E4(0x6cb);
            }
            (*b)++;
        }
        ((int *)func_021BE480(r, 0, 7))[1] = w[1];
        c = func_02188CB4((void *)s);
        func_021A3038(c, (struct VecFx32 *)v);
        v[1] = w[1];
        func_021A3044(c, v);
        break;
    case 2:
        if (w[5] != 0) {
            return 1;
        }
        if (func_021F4210((u8 *)(w + 8))) {
            if (w[4] != 0) {
                func_0218EC30(h, w[4]);
            }
            func_021BE6B0(func_021BE674(r, 0, 7, 1), 0);
            (*b)++;
        }
        break;
    case 3:
        if (func_021BE6BC(func_021BE674(r, 0, 7, 1))) {
            func_021F4174(r);
            return 1;
        }
        break;
    }
    return 0;
}



int func_021F3ECC(int *p)
{
    if (p[3] < 0) {
        if (p[2] >= p[1]) {
            return 1;
        }
    } else {
        if (p[2] <= p[1]) {
            return 1;
        }
    }
    return 0;
}




/*
 * Unlabelled leaf called only from func_021F3AC0. Each field gets its own
 * pool word (d_021F4480 + 0/8/4/C). The loads must be written in field
 * order x, y, w, h: loading w before y swaps the index and value registers
 * (17 bytes).
 */
int func_021F3EEC(u8 i, int x, int y)
{
    int x0;
    int y0;
    int w;
    int h;

    x0 = d_021F4480[i].x;
    y0 = d_021F4480[i].y;
    w = d_021F4480[i].w;
    h = d_021F4480[i].h;
    if (x0 <= x && x <= x0 + w - 1 && y0 <= y && y <= y0 + h - 1) {
        return 1;
    }
    return 0;
}




void func_021F3F38(int *a, void *b, int c)
{
    int r4, r6;

    if (a[c]) {
        if (d_021F4328[c]) {
            r4 = 0;
            r6 = 1;
        } else {
            r4 = 1;
            r6 = 0;
        }
    } else {
        if (d_021F4328[c]) {
            r4 = 1;
            r6 = 0;
        } else {
            r4 = 0;
            r6 = 1;
        }
    }
    func_021BE700(b, 0, c, r4, 1);
    func_021BE700(b, 0, c, r6, 0);
    func_021BE6CC((int)b, 0, (u16)c, (u16)r4, 0);
    func_021BE6B0(func_021BE674(b, 0, c, r4), 1);
}




int func_021F3FBC(int *a, int i)
{
    int r;

    if (a[i]) {
        if (d_021F4328[i]) {
            r = 0;
        } else {
            r = 1;
        }
    } else {
        if (d_021F4328[i]) {
            r = 1;
        } else {
            r = 0;
        }
    }
    return r;
}




/*
 * func_02188C64's result is bound to t before the A01FC call: passed inline,
 * the ternary fourth argument is evaluated before the call.
 */
void func_021F3FE8(void *a)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    int *q;
    int flag;
    u32 t;
    int x;
    int y;

    s = func_0201210C((void *)a);
    r = (void *)func_02188D2C(s);
    w = func_021897BC(s, 1);
    h = (u32)func_02188C58(s);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    if (w[0] != 5) {
        return;
    }
    if (q[6] == 0 && w[1] <= -0x230000) {
        q[6] = 1;
        func_021BE6B0(func_021BE674(r, 0, 6, 0), 0);
        func_020061E4(0x6cd);
        w[1] = -0x230000;
        w[6] = 1;
        ((u16 *)w)[14] = 0;
        ((u16 *)w)[15] = 0;
        w[16] = 1;
    }
    if (w[6] != 0) {
        switch (((u16 *)w)[15]) {
        case 0:
            func_021F41B8((u8)w[0], w[3], 0, (u32)h, (u8 *)(w + 8));
            func_020061E4(0x6cb);
            ((u16 *)w)[15]++;
            break;
        case 1:
            if (func_021F4210((u8 *)(w + 8))) {
                ((u16 *)w)[14]++;
                if (((u16 *)w)[14] >= 100) {
                    w[3] = -0x2000;
                    w[6] = 0;
                    func_020061E4(0x6ca);
                }
            }
            break;
        }
    }
    if (w[15] != 0) {
        flag = 0;
        if (w[3] >= 0) {
            if (w[1] >= -0x2a0000) {
                t = func_02188C68(s);
                flag = 1;
                x = func_021A03A4((int *)t);
                y = func_021A03B8((int *)t);
            }
        } else {
            if (w[1] <= -0x310000) {
                flag = 1;
                x = 0x7fdf;
                y = 9;
            }
        }
        if (flag) {
            t = func_02188C64(s);
            func_021A01FC((u8 *)t, x, y, w[3] == -0x2000 ? 0x20 : 0x10);
            w[15] = 0;
        }
    }
    if (w[16] != 0) {
        if (w[16] == 1) {
            w[16] = 2;
            return;
        }
        if (func_021BE6BC(func_021BE674(r, 0, 6, 0))) {
            func_020061F8(func_02006148(0x6cd));
            w[16] = 0;
        }
    }
}




void func_021F4174(void *p)
{
    func_021BE700(p, 0, 7, 0, 1);
    func_021BE700(p, 0, 7, 1, 0);
    func_021BE6CC((int)p, 0, 7, 0, 0);
    p = func_021BE674(p, 0, 7, 0);
    func_021BE6B0(p, 1);
}




void func_021F41B8(int a0, int a1, int a2, int a3, u8 *s)
{
    s[0] = 0;
    s[1] = 0;
    ((struct Obj02756 *)s)->f8 = a3;
    ((struct Obj02756 *)s)->fC = func_0218EC5C((u8 *)a3);
    func_0218ECC4(a3, s + 0x10);
    if (a2) {
        ((struct Obj02756 *)s)->f4 = 0x1000;
        s[2] = 2;
    } else {
        if (a0 == 5) {
            ((struct Obj02756 *)s)->f4 = 0x4000;
        } else {
            ((struct Obj02756 *)s)->f4 = 0x2000;
        }
        s[2] = 4;
    }
    if (a1 < 0) {
        ((struct Obj02756 *)s)->f4 *= -1;
    }
}




int func_021F4210(u8 *s)
{
    int v[3];

    switch (s[0]) {
    case 0:
        func_0218EC54((u8 *)(((struct Obj01223 *)s)->f8));
        s[0]++;
    case 1:
        if (s[3] % 2 == 0) {
            func_0218ECC4(((struct Obj01223 *)s)->f8, v);
            v[1] = v[1] + ((struct Obj01223 *)s)->f4;
            func_0218ECD4(((struct Obj01223 *)s)->f8, v);
            ((struct Obj01223 *)s)->f4 *= -1;
            s[1]++;
            if (s[1] >= s[2] * 2) {
                if (((struct Obj01223 *)s)->fC) {
                    func_0218EC30(((struct Obj01223 *)s)->f8, ((struct Obj01223 *)s)->fC);
                }
                func_0218ECD4(((struct Obj01223 *)s)->f8, s + 0x10);
                return 1;
            }
        }
        s[3] = (s[3] + 1) % 2;
    }
    return 0;
}
