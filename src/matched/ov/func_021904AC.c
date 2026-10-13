/*
 * function: FIELD_MSGBG_GetFont
 * address:  0x021904AC
 * packet:   pkt_0218FE70
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x8 of the object.
 */
#include "../include/Obj17923.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_MSGBG_GetFont(u8 *p)
{
    return ((struct Obj17923 *)p)->f8;
}

