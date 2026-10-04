/*
 * function: func_02197798
 * address:  0x02197798
 * packet:   pkt_ov021_02197798
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02197738  0x02197738  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int func_021975D0(u8 *p);
extern int func_02012DAC(int a0);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_02197738(u8 *a);

void func_02197798(u8 *a)
{
    if (func_021975D0(a) != 0) {
        func_02012DAC(((struct Obj00094 *)a)->f30);
        func_02196034(a, func_02197738, 0x78E);
    }
}
