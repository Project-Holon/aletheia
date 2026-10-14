/*
 * function: PERCENTAGE_GetOnesDigit
 * address:  0x021C2894
 * packet:   pkt_021C2894
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
#include "../include/Obj26024.h"

typedef unsigned char u8;

extern int _s32_div_f(int, int);

u8 PERCENTAGE_GetOnesDigit(char *p)
{
    return (u8)(((struct Obj26024 *)p)->f2 % 10);
}
