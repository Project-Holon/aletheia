/*
 * function: func_021A8140
 * address:  0x021A8140
 * packet:   pkt_ov021_021A8140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3484  0x021A3484  thumb  ov021
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 */

typedef struct V {
    int x;
    int y;
    int z;
} V;

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *func_02188CB4(u8 *p);
extern u16 func_021A3050(u8 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3484(void *p, int k, V *out);
extern void func_0207CEE4(int a, V *b, V *c, V *d);
extern void *func_021A3074(u8 *p);
extern void func_02163E58(void *p, V *in, int *out);

void func_021A8140(void *a, V *out)
{
    void *ctx;
    int k;
    V v0;
    V v1;
    V v2;
    int t;

    ctx = func_02188CB4(a);
    k = func_021A3050(ctx);
    func_021A3038(ctx, (struct VecFx32 *)&v0);
    func_021A3484(ctx, k, &v1);
    func_0207CEE4(0x10000, &v1, &v0, &v2);
    func_02163E58(func_021A3074(ctx), &v2, &t);
    v2.y = t;
    *out = v2;
}
