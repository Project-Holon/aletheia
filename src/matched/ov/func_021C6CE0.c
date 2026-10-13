/*
 * function: FIELD_TASK_GetState
 * address:  0x021C6CE0
 * packet:   pkt_021C6CE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18316.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_TASK_GetState(u8 *p)
{
    return ((struct Obj18316 *)p)->f0;
}
