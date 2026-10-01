/*
 * function: func_021AC66C
 * address:  0x021AC66C
 * packet:   pkt_ov021_021AC66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct X { u32 f0; u32 f4; u16 f8; } X;

extern u32 func_021C6694(u32 a, u32 b, u32 c);
extern void func_021AC154(u32 a);

void func_021AC66C(u32 a, X *x)
{
    if (func_021C6694(x->f4, x->f8, 0x1000) == 0)
        func_021AC154(a);
}
