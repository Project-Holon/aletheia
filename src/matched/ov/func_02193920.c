/*
 * function: FIELD_WFBC_IsBackPeople
 * address:  0x02193920
 * packet:   pkt_02193920
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at +0x1 of the object.
 */
#include "../include/Obj17939.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_WFBC_IsBackPeople(u8 *p)
{
    return ((struct Obj17939 *)p)->f1;
}

