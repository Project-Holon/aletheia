/*
 * function: func_021B1CB0
 * address:  0x021B1CB0
 * packet:   pkt_ov021_021B1CB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021A32A8  0x021A32A8  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern void *func_02188CB4(unsigned char *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021A32A8(u32, u32);
extern u16 func_0216D588(int);

int func_021B1CB0(u32 a, u32 b)
{
    void *h;
    u16 *p;
    u16 *q;
    int r;

    h = func_02188CB4(func_0201210C(func_0215A5DC((void *)b)));
    p = func_02159AE8((void *)a, (void *)b);
    q = func_02159AE8((void *)a, (void *)b);
    r = func_021A32A8(h, 0x8000);
    if (r != 0) {
        *q = 1;
        *p = func_0216D588(r);
    } else {
        *q = 0;
    }
    return 0;
}
