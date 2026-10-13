/*
 * function: BSUBWAY_SCR_ClearWinCount
 * address:  0x021CA250
 * packet:   pkt_021CA250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18347.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int BSUBWAY_SCR_ClearWinCount(u32 a)
{
((struct Obj18347 *)((u8 *)(a)))->fE = 0;
return a;
}

