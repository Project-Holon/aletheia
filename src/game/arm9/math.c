/*
 * file:     math.c
 * function: MATH_CountPopulation
 * address:  0x02080D24
 * packet:   pkt_02080D24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmath math.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Number of set
 * bits in a word, by the parallel pairwise sum.
 */

#include "../types.h"

u8 MATH_CountPopulation(u32 x)
{
    x -= (x >> 1) & 0x55555555;
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x += x >> 4;
    x &= 0x0F0F0F0F;
    x += x >> 8;
    x += x >> 16;
    return (u8)x;
}
