/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F3AC0, func_021F3D78
 * address:  0x021F3AC0
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
 *   d_021F4490     0x021F4490  data  a4
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_021F3EEC  0x021F3EEC  thumb  ov043
 *   func_021F41B8  0x021F41B8  thumb  ov043
 *   func_021F4210  0x021F4210  thumb  ov043
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021F3ECC  0x021F3ECC  thumb  ov043
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021F3FBC  0x021F3FBC  thumb  ov043
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218CEE0  0x0218CEE0  thumb  ov021
 *   func_021C06C0  0x021C06C0  thumb  ov021
 *   func_021F3F38  0x021F3F38  thumb  ov043
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_021F3FE8  0x021F3FE8  thumb  ov043
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021F4174  0x021F4174  thumb  ov043
 */
struct Ctx;
struct Obj;
struct Rec;
struct Big;
struct Rec94;
struct Obj00020;
struct VecFx32;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {
    int v[2];
    int pad[4];
} E;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef signed int     s32;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C58(void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_02188C7C(unsigned char *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *v);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern Vec *func_0216D888(u32 o);
extern void func_0216D85C(void *p, int v);
extern void func_0216D89C(u32 o, Vec *v);
extern int func_021F3EEC(u8 i, int x, int y);
extern void func_021F41B8(int a0, int a1, int a2, int a3, u8 *s);
extern int func_021F4210(u8 *s);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F05C(unsigned char *a);
extern void func_020061E4(u32 a);
extern int func_021F3ECC(int *p);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern int func_021F3FBC(int *a, int i);
extern u32 func_02188C98(u8 *p);
extern void *func_0218CEE0(void *p);
extern void func_021C06C0(u8 i, int v, int *p);
extern void func_021F3F38(int *a, void *b, int c);
extern u32 func_02188C64(u8 *p);
extern int func_021A0244(u8 *p);
extern void func_021F3FE8(void *a);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern void func_0218EC30(u32 a, int v);
extern void func_021A3044(u8 *p, void *v);
extern void func_021F4174(void *p);
int func_021F3AC0(void *a, int *b);
int func_021F3D78(void *a, int *b);
extern E d_021F4490[];


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
