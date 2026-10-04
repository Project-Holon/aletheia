/*
 * function: func_021ACB0C
 * address:  0x021ACB0C
 * packet:   pkt_ov021_021ACB0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct X { u32 f0; u16 h4; u16 h6; u16 h8; u16 ha; } X;

extern u32 func_021ABE18(u32 a);
extern void func_021C6628(u32 a, u32 b);
extern void func_021C6580(u8 *p, int i);

void func_021ACB0C(X *x)
{
    u32 h = func_021ABE18(x->f0);

    func_021C6628(h, x->h8);
    func_021C6628(h, x->ha);
    func_021C6580((u8 *)h, x->h4);
    func_021C6580((u8 *)h, x->h6);
}
