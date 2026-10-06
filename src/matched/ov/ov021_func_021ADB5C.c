/*
 * function: func_021ADB5C
 * address:  0x021ADB5C
 * packet:   pkt_ov021_021ADB5C
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

void func_021ADB5C(int a, int v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[3] = v;
}
