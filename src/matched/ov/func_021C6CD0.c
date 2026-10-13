/*
 * function: FIELD_TASK_IsFinished
 * address:  0x021C6CD0
 * packet:   pkt_021C6CD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18315.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_TASK_IsFinished(u32 a)
{
if (((struct Obj18315 *)((u8 *)(a)))->f0 == 2) {
    return 1;
}
return 0;
}

