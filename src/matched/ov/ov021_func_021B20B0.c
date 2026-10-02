/*
 * function: func_021B20B0
 * address:  0x021B20B0
 * packet:   pkt_ov021_021B20B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B83FC  0x021B83FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5EC(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_0216DE94(u32, u32);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern u32 func_0219E348(u32);
extern void func_021B83FC(u32, unsigned short *, unsigned short *, unsigned short *);

int func_021B20B0(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = func_0216DE94(func_0215A5EC(b), func_02159B10(a, b));
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    func_021B83FC(func_0219E348(h), x, y, z);
    return 0;
}
