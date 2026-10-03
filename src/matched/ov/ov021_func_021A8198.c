/*
 * function: func_021A8198
 * address:  0x021A8198
 * packet:   pkt_ov021_021A8198
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021A36C8  0x021A36C8  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 */

typedef struct V {
    int x;
    int y;
    int z;
} V;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_02188CB4(u8 *p);
extern u16 func_021A3050(u8 *p);
extern void *func_02188C5C(void *p);
extern void *func_021BB480(void *p);
extern int func_021A36C8(u8 *p, u32 k, void *buf);
extern void func_021B7D38(void *p, int *in, V *out);

void func_021A8198(void *a, V *out)
{
    void *ctx;
    int k;
    void *h;
    V res;
    int in[2];

    ctx = func_02188CB4(a);
    k = func_021A3050(ctx);
    h = func_021BB480(func_02188C5C(a));
    func_021A36C8(ctx, k, in);
    func_021B7D38(h, in, &res);
    *out = res;
}
