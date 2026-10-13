/*
 * function: FIELDMAP_GetTaskManager
 * address:  0x02188D38
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x134 of the object.
 */
#include "../include/Obj17879.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELDMAP_GetTaskManager(u8 *p)
{
    return ((struct Obj17879 *)p)->f134;
}

