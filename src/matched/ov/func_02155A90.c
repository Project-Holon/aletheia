/*
 * function: IRC_BATTLE_ENTRY_GetGameSys
 * address:  0x02155A90
 * packet:   pkt_02155A90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word at p.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17616.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u32 IRC_BATTLE_ENTRY_GetGameSys(u8 *p)
{
    return ((struct Obj17616 *)p)->f0;
}

