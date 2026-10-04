/*
 * function: func_021F3AC0
 * address:  0x021F3AC0
 * packet:   pkt_ov043_021F3AC0
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callees 0x021F3EEC and 0x021F3FBC (ov043) and 0x0218CEE0 and 0x021C06C0
 * (ov021) are unlabelled leaves, filed under their own shards.
 * Levers from the first draft (311 bytes): bind func_0218CEE0's result to
 * c before the 06C0 call (inline, w[0] is loaded first and spilled, which
 * adds a frame slot); bind BE674's result to e and set f = 0 after it; write
 * `w[17 + n++] = cur`; and pass `vec2.y` rather than re-reading w[1].
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
 */

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

extern E d_021F4490[];

extern void *func_020124E4(void *a);
extern void *func_0201210C(void *a);
struct Big;
struct Ctx;
extern int func_02188D2C(int *p);
extern int *func_021897BC(void *a, int b);
extern void *func_02188C58(void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(u32 a, u32 b);
extern void *func_02188C7C(unsigned char *p);
extern void *func_02188CB4(unsigned char *p);
struct VecFx32;
extern void func_021A3038(unsigned char *a, struct VecFx32 *v);
extern int func_0216DD1C(void *m, u32 *cur, int *it);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern Vec *func_0216D888(u32 o);
extern void func_0216D85C(u32 o, s16 v);
extern void func_0216D89C(u32 o, Vec *v);
extern int func_021F3EEC(u8 i, int x, int y);
extern void func_021F41B8(u8 a0, int a1, int a2, u32 a3, void *s);
extern int func_021F4210(void *s);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F05C(unsigned char *a);
extern void func_020061E4(int id);
extern int func_021F3ECC(int *p);
extern int *func_021BE480(void *p, int i, u16 j);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B0(void *p, int v);
extern int func_021BE6BC(void *p);
extern int func_021F3FBC(int *a, int i);
extern u32 func_02188C98(u8 *p);
extern void *func_0218CEE0(void *p);
extern void func_021C06C0(u8 i, int v, int *p);
extern void func_021F3F38(int *a, void *b, int c);
extern u32 func_02188C64(void *a);
extern int func_021A0244(u32 a);
extern void func_021F3FE8(void *a);

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
    q = func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    switch (*b) {
    case 0:
        n = 0;
        it = 0;
        m = func_02188C7C((void *)s);
        for (i = 0; i < 5; i++) {
            w[17 + i] = 0;
        }
        func_021A3038(func_02188CB4((void *)s), (struct VecFx32 *)&pos);
        while (func_0216DD1C(m, &cur, &it) == 1) {
            x = func_0216D83C((void *)cur);
            y = func_0216D86C((void *)cur);
            if (func_021F3EEC(w[0], x, y)) {
                func_0216D88C((const struct Actor *)cur, (struct VecFx32 *)&vec);
                if (pos.y - 0x10000 < vec.y && vec.y < pos.y + 0x10000 && n < 5) {
                    w[17 + n++] = cur;
                }
            }
        }
        func_021F41B8(w[0], w[3], 1, h, w + 8);
        (*b)++;
        break;
    case 1:
        if (func_021F4210(w + 8)) {
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
        func_020061E4(0x6ca);
        (*b)++;
    case 4:
        if (w[6] == 0) {
            w[1] += w[3];
        }
        if (func_021F3ECC(w)) {
            w[1] = w[2];
            func_021F41B8(w[0], w[3], 0, h, w + 8);
            func_020061E4(0x6cb);
            (*b)++;
        }
        func_021BE480(r, 0, w[0])[1] = w[1];
        for (i = 0; i < 5; i++) {
            o = w[17 + i];
            if (o != 0) {
                vec2 = *func_0216D888(o);
                vec2.y = w[1];
                func_0216D85C(o, (vec2.y >> 4) / 4096);
                func_0216D89C(o, &vec2);
            }
        }
        break;
    case 5:
        if (func_021F4210(w + 8)) {
            (*b)++;
        }
        break;
    case 6:
        func_0218F05C((unsigned char *)h);
        k = w[0];
        func_021BE6B0(func_021BE674(r, 0, k, func_021F3FBC(q, k)), 0);
        (*b)++;
        break;
    case 7:
        k = w[0];
        e = func_021BE674(r, 0, k, func_021F3FBC(q, k));
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
        if (func_021A0244(func_02188C64(s)) == 0) {
            return 1;
        }
        break;
    }
    func_021F3FE8(t);
    return 0;
}
