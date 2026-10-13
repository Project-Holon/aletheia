/*
 * function: FIELD_G3D_MAPPER_GetWfbc
 * address:  0x0218DC70
 * packet:   pkt_0218DC6C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x6c of the object.
 */
#include "../include/Obj17897.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *FIELD_G3D_MAPPER_GetWfbc(u8 *p)
{
    return ((struct Obj17897 *)p)->f6C;
}

