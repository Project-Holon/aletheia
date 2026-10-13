/*
 * function: BSUBWAY_SCR_SetWinCount
 * address:  0x021CA238
 * packet:   pkt_021CA238
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0xe.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18346.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void BSUBWAY_SCR_SetWinCount(u8 *p, u16 v)
{
    ((struct Obj18346 *)p)->fE = v;
}
