/*
 * function: func_021AF484
 * address:  0x021AF484
 * packet:   pkt_ov021_021AF484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0215A5DC(void *a0);
extern u32 func_02012134(void *a);
extern u32 func_0202B578(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern void func_0202C0E4(u32 a, u32 b);

int func_021AF484(u32 a, u32 b)
{
    u32 x = func_0202B578(func_02012134(func_0215A5DC((void *)b)));

    func_0202C0E4(x, func_02159B10(a, b));
    return 0;
}
