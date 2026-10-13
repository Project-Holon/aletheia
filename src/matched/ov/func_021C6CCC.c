/*
 * function: FIELD_TASK_GetWork
 * address:  0x021C6CCC
 * packet:   pkt_021C6CCC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4 of the object.
 */
#include "../include/Obj18314.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_TASK_GetWork(u8 *p)
{
    return ((struct Obj18314 *)p)->f4;
}

