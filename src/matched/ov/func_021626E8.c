/*
 * function: EVENTDATA_SYSTEM_GetConnectExitType
 * address:  0x021626E8
 * packet:   pkt_021626E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the byte field at +0x5.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17715.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p)
{
    return ((struct Obj17715 *)p)->f5;
}

