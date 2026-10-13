/*
 * function: SCRIPT_WORK_GetTargetObj
 * address:  0x02158F90
 * packet:   pkt_02158F90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x8.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17636.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


void *SCRIPT_WORK_GetTargetObj(void *p)
{
    return ((struct Obj17636 *)p)->f8;
}

