/*
 * function: FIELD_WFBC_SetMmdlSys
 * address:  0x02193AFC
 * packet:   pkt_02193920
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the 32-bit word into byte +0x140 of the object.
 */
#include "../include/Obj17940.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_WFBC_SetMmdlSys(u8 *p, u32 v)
{
    ((struct Obj17940 *)p)->f140 = v;
}

