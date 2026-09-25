/*
 * function: func_022119F8
 * address:  0x022119F8
 * packet:   pkt_022119F8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022119E8  0x022119E8  thumb  ov198
 *   func_02211998  0x02211998  thumb  ov198
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_022119E8(u8 *);
extern void func_02211998(u8 *, u32, u32);

void func_022119F8(u8 *p, u32 a, u32 b)
{
    func_022119E8(p);
    func_02211998(p, a, b);
}

