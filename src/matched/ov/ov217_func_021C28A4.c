/*
 * function: PERCENTAGE_GetTensDigit
 * address:  0x021C28A4
 * packet:   pkt_021C28A4
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
#include "../include/Obj26025.h"

typedef unsigned char u8;

extern int _s32_div_f(int, int);

u8 PERCENTAGE_GetTensDigit(char *p)
{
    int t = ((struct Obj26025 *)p)->f2 % 100;
    return (u8)(t / 10);
}
