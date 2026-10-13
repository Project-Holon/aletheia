/*
 * function: FIELD_PLACE_NAME_GetMessageLength
 * address:  0x021BD138
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads the byte at byte +0x20 of the object.
 */
#include "../include/Obj18215.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_PLACE_NAME_GetMessageLength(u8 *p)
{
    return ((struct Obj18215 *)p)->f20;
}

