/*
 * function: func_021BEA3C
 * address:  0x021BEA3C
 * packet:   pkt_021BEA3C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14737.h"

typedef unsigned char u8;

extern int _s32_div_f(int, int);

void func_021BEA3C(char *p, int a)
{
    ((struct Obj14737 *)p)->f2B8 = (u8)((((struct Obj14737 *)p)->f2B8 + a + 3) % 3);
}
