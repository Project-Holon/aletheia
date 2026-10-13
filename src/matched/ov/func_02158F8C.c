/*
 * function: SCRIPT_WORK_GetScriptId
 * address:  0x02158F8C
 * packet:   pkt_02158F8C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the halfword field at +0x4.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17635.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u16 SCRIPT_WORK_GetScriptId(u8 *p)
{
    return ((struct Obj17635 *)p)->f4;
}

