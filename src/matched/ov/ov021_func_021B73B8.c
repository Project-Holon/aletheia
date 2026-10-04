/*
 * function: func_021B73B8
 * address:  0x021B73B8
 * packet:   pkt_ov021_021B73B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   func_021B7390  0x021B7390  thumb  ov021
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021D99DE     0x021D99DE  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern int func_021B7390(u32 a, int b);
extern u8 d_021D99DE[];

int func_021B73B8(u32 a, u32 b)
{
    u16 *out;
    void *h;
    u32 x;
    int y;

    out = func_02159AE8((void *)a, (void *)b);
    h = func_0215A5E4((void *)b);
    x = func_021690D0((int)h);
    y = func_021690E0((int)h);
    if (func_021B7390(x, y) == 1)
        *out = 10;
    else
        *out = d_021D99DE[y % 10];
    return 0;
}
