/*
 * function: func_021B7A84
 * address:  0x021B7A84
 * packet:   pkt_ov021_021B7A84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9510  0x021B9510  thumb  ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 *   func_021B8848  0x021B8848  thumb  ov021
 *   func_021B88B8  0x021B88B8  thumb  ov021
 *   func_021B9828  0x021B9828  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   d_021D9A00     0x021D9A00  data   a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { u16 a, b, c, d; } Rect4;

typedef struct Node {
    u8 pad[0x30];
    VecFx32 pos;
} Node;

typedef int (*HitFn)(int i, u8 *p, VecFx32 *hit, Rect4 *r, VecFx32 *out);

extern u32 *func_021B9510(u8 *a, u8 *b, int i);
extern Node *func_021B87D8(u8 *a, u32 b);
extern u32 *func_021B8848(u8 *a, u32 b);
extern HitFn func_021B88B8(u8 *a, u32 b);
extern int func_021B9828(VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *d, VecFx32 *e, VecFx32 *f);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern fx32 func_0207CF3C(const VecFx32 *v1, const VecFx32 *v2);
extern const VecFx32 d_021D9A00;

int func_021B7A84(u8 *p, const VecFx32 *pa, const VecFx32 *pb, Rect4 *r, VecFx32 *out)
{
    VecFx32 hit;
    VecFx32 d;
    VecFx32 n;
    VecFx32 up;
    VecFx32 bestPos;
    VecFx32 a;
    VecFx32 b;
    Rect4 bestR;
    int i;
    fx32 best;
    int found;
    u32 *t;
    Node *n0;
    Node *n1;
    u32 *m;
    HitFn f;
    fx32 dist;

    up = d_021D9A00;
    a = *pa;
    b = *pb;
    found = 0;
    for (i = 0; i < *(u16 *)(p + 0x22); i++) {
        t = func_021B9510(p + 0x50, p + 0x20, i);
        if (t == 0) {
            continue;
        }
        n0 = func_021B87D8(p + 0x20, t[0]);
        n1 = func_021B87D8(p + 0x20, t[1]);
        m = func_021B8848(p + 0x20, t[3]);
        func_0207CA00(&n0->pos, &n1->pos, &d);
        func_0207CAE8(&d, &up, &n);
        if (func_021B9828(&d, &n, &n1->pos, &a, &b, &hit) == 0) {
            continue;
        }
        f = func_021B88B8(p + 0x20, *m);
        if (f == 0) {
            continue;
        }
        if (f(i, p, &hit, r, out) == 0) {
            continue;
        }
        if (!found) {
            bestR = *r;
            bestPos = *out;
            best = func_0207CF3C(&a, out);
            found = 1;
        } else {
            dist = func_0207CF3C(&a, out);
            if (dist < best) {
                bestR = *r;
                bestPos = *out;
                best = dist;
            }
        }
    }
    if (found) {
        *r = bestR;
        *out = bestPos;
    }
    return found;
}
