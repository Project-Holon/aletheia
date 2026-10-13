/*
 * function: SCRIPT_WORK_GetTempBuffer
 * address:  0x02158F7C
 * packet:   pkt_02158F7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x34.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17633.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u32 SCRIPT_WORK_GetTempBuffer(u8 *p)
{
    return ((struct Obj17633 *)p)->f34;
}

