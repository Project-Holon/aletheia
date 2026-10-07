/*
 * function: func_021B0808
 * address:  0x021B0808
 * packet:   pkt_ov021_021B0808
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The quotient is written back into z (the address-taken output local)
 * rather than a fresh q: with a separate local the divisor 12 and the
 * table stride 12 pool into r6 across the _u32_div_f call.
 *
 * symbols:
 *   func_021B0808  0x021B0808  thumb
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D9390     0x021D9390  data
 *   d_021D939C     0x021D939C  data
 */

typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 x, y, z; } VecFx32;

struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_02048B30(void *cam, VecFx32 *out);
extern void func_02048AE8(void *cam, VecFx32 *out);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0207CCA4(const VecFx32 *a, VecFx32 *out);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0206DF3C(VecFx32 *pos, u32 *x, u32 *z);

extern const VecFx32 d_021D9390;
extern const VecFx32 d_021D939C[2][4];

void func_021B0808(const VecFx32 *src, VecFx32 *out, void *cam)
{
    VecFx32 pos;
    VecFx32 c;
    VecFx32 d;
    VecFx32 e;
    VecFx32 f;
    VecFx32 b;
    VecFx32 a;
    u32 x;
    u32 z;
    u32 t;
    u32 r;

    pos = *src;
    func_02048AD0(cam);
    func_02048B30(cam, &a);
    func_02048AE8(cam, &b);
    func_0207CA00(&a, &b, &c);
    d = c;
    d.y = r = 0;
    func_0207CCA4(&d, &d);
    func_0207CAE8(&d, &d_021D9390, &e);
    func_0207CAE8(&c, &e, &f);
    func_0207CCA4(&f, &f);
    pos.x += f.x;
    pos.y += f.y;
    pos.z += f.z;
    func_0206DF3C(&pos, &x, &z);
    t = x >> 3;
    if (t < 10) {
        r = 0;
    } else if (t >= 10 && t <= 15) {
        r = 1;
    } else if (t >= 16 && t < 22) {
        r = 2;
    } else {
        r = 3;
    }
    z = (z >> 3) / 12;
    if (r < 4 && z < 2) {
        *out = d_021D939C[z][r];
    } else {
        VecFx32 zero = {0, 0, 0};
        *out = zero;
    }
}
