/*
 * function: FIELDMAP_SetCtrlWork
 * address:  0x02188CAC
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the 32-bit word into byte +0x10c of the object.
 */
#include "../include/Obj17868.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELDMAP_SetCtrlWork(u8 *p, u32 v)
{
    ((struct Obj17868 *)p)->f10C = v;
}

