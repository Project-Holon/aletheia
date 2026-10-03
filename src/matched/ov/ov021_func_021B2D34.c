/*
 * function: func_021B2D34
 * address:  0x021B2D34
 * packet:   pkt_ov021_021B2D34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218BACC  0x0218BACC  thumb  ov021
 * Addresses are Black-image addresses.
 */

extern unsigned short *func_02159AE8(void *a0, void *a1);
extern int func_02159B10(int a, int b);
extern void *func_0215A5DC(void *a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C98(u8 *p);
extern int func_0218DC6C(int a);
extern int func_0218C7D8(int a, int b, int *c);
extern int func_0218BACC(int a, int b);

int func_021B2D34(int a, int b)
{
    unsigned short *out = func_02159AE8((void *)a, (void *)b);
    int f = func_02159B10(a, b);
    int x = func_02159B10(a, b);
    int y = func_02159B10(a, b);
    int h;
    int buf[3];

    h = func_0218DC6C(func_02188C98(func_0201210C(func_0215A5DC((void *)b))));
    buf[0] = x << 16;
    buf[1] = 0;
    buf[2] = y << 16;
    *out = func_0218BACC(h, func_0218C7D8(h, f, buf));
    return 0;
}
