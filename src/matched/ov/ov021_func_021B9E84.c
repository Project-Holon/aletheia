/*
 * function: func_021B9E84
 * address:  0x021B9E84
 * packet:   pkt_ov021_021B9E84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds the 8-byte record for id `a` at pos between the two entries of
 * func_021B8230's link: horizontal distance and height offset scaled by
 * func_021B8248 and rounded by func_021B8378; returns 0 when out of range,
 * else 1 when the record round-trips unchanged through func_021B8250 and
 * func_021B7D38.
 * pos->x and pos->z go through locals: stored straight into m, the y = 0
 * stores interleave with them and the loads split; the out-of-range
 * `return 0` is the fall-out of an if around the rest (it sits after the
 * final epilogue). The spill slots follow h0, h1, L, dist, diff declared
 * in that order.
 *
 * symbols:
 *   func_021B8224  0x021B8224  thumb  ov021
 *   func_021B8230  0x021B8230  thumb  ov021
 *   func_021B823C  0x021B823C  thumb  ov021
 *   func_021B8248  0x021B8248  thumb  ov021
 *   func_021B8250  0x021B8250  thumb  ov021
 *   func_021B8378  0x021B8378  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021BAE7C  0x021BAE7C  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   _u32_div_f     0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;
typedef struct {
    u16 id;
    u8 f2;
    u8 f3;
    s16 f4;
    s16 f6;
} Rec;

int *func_021B8224(void *p, int k);
int *func_021B8230(void *p, int a);
int func_021B823C(void *p, int k);
u32 func_021B8248(u8 *p);
void func_021B8250(void *p, Rec *r, Rec *o);
int func_021B8378(int x);
int func_021B7D38(void *p, Rec *r, int c);
int func_021BAE7C(int *e0, int *e1, const V *pos, V *a, int *b, V *c);
int func_0207C768(int a, int b);
int func_0207CF3C(const V *a, const V *b);
int func_0203EFC8(const void *a, const void *b, u32 n);

int func_021B9E84(int a, void *p, const V *pos, Rec *out, int arg)
{
    V A;
    V C;
    V m;
    V n;
    int B;
    Rec buf;
    int *info;
    int k;
    int *e0;
    int *e1;
    int h0;
    int h1;
    u32 L;
    u32 dist;
    int diff;
    int i;
    int x;
    int z;

    info = func_021B8230(p, a);
    e0 = func_021B8224(p, info[0]);
    e1 = func_021B8224(p, info[1]);
    k = func_021B8248(p);
    if (func_021BAE7C(e0, e1, pos, &A, &B, &C) == 0) {
        return 0;
    }
    x = pos->x;
    z = pos->z;
    m.x = x;
    n.x = A.x;
    m.z = z;
    n.z = A.z;
    m.y = 0;
    n.y = 0;
    dist = func_0207C768(func_0207CF3C(&m, &n), k) >> 12;
    func_021B823C(p, info[3]);
    L = info[5] << 4;
    diff = L - (func_0207C768(B, k) >> 12);
    for (i = 0; i < 4; i++) {
        if (a == e0[i]) {
            h0 = e0[i + 8];
        }
        if (a == e1[i]) {
            h1 = e1[i + 8];
        }
    }
    if (dist <= h0 + (h1 - h0) * diff / L + 0x10) {
        out->id = a;
        out->f2 = 1;
        out->f3 = 3;
        if (C.y >= 0) {
            out->f4 = func_021B8378(dist);
        } else {
            out->f4 = -func_021B8378(dist);
        }
        out->f6 = func_021B8378(diff);
        func_021B8250(p, out, &buf);
        func_021B7D38(p, &buf, arg);
        if (func_0203EFC8(out, &buf, 8) == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}
