/*
 * function: func_02195E70
 * address:  0x02195E70
 * packet:   pkt_ov021_02195E70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02195E54  0x02195E54  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; u32 x4; u32 x8; u32 xc; } Obj;
extern void func_02195E54(u32 a, u32 b, u8 c, u32 d);

void func_02195E70(u32 a, Obj *b)
{
    func_02195E54(a, b->xc, b->x3, 0);
}
