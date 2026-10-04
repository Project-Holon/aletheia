/*
 * function: func_0219E370
 * address:  0x0219E370
 * packet:   pkt_ov021_0219E370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219E938  0x0219E938  thumb  ov021
 *   func_0219E940  0x0219E940  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_0216D69C(void *p);
extern u32 func_0219E938(u32);
extern u32 func_0219E940(int x);
extern void func_021B80E0(void *p, u32 a, u32 b);

void func_0219E370(u32 a, u32 b, u32 c)
{
    u32 *p = func_0216D69C((void *)a);
    u32 x = func_0219E938(b);
    func_021B80E0((void *)*p, func_0219E940(c), x);
}
