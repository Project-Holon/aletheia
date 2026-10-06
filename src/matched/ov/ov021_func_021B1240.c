/*
 * function: func_021B1240
 * address:  0x021B1240
 * packet:   pkt_ov021_021B1240
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191BE8  0x02191BE8  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
typedef unsigned char  u8;
extern u32 func_02158F78(u8 *p);
extern int func_0215A61C(int a0);
extern u32 func_02191BE8(u32 *p, u32 b);

int func_021B1240(int a, int b)
{
    u32 x = func_02158F78(func_0215A5F4((void *)b));

    if (func_02191BE8((u32 *)func_0215A61C(b), x) == 1) {
        return 1;
    }
    return 0;
}
