/*
 * function: func_021B2070
 * address:  0x021B2070
 * packet:   pkt_ov021_021B2070
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B1E74  0x021B1E74  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B83FC  0x021B83FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021B1E74(u32);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern u32 func_0219E348(u32);
extern void func_021B83FC(u32, u32, u32, u32);

int func_021B2070(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = func_021B1E74(b);
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    func_021B83FC(func_0219E348(h), x, y, z);
    return 0;
}
