/*
 * function: func_021B4BEC
 * address:  0x021B4BEC
 * packet:   pkt_ov021_021B4BEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021896F4  0x021896F4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012138(void *);
extern u16 func_021896F4(u32);

int func_021B4BEC(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_021896F4(func_02012138(d));
    return 1;
}
