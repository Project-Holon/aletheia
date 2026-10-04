/*
 * function: func_021ACBB8
 * address:  0x021ACBB8
 * packet:   pkt_ov021_021ACBB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int func_021AC1E0(u32 a);

void func_021ACBB8(u32 a, u8 v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[9] = v;
}
