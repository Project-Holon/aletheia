/*
 * function: FIELD_SUBPROC_GetWork
 * address:  0x021BBA6C
 * packet:   pkt_021BBA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj20098.h"

typedef unsigned int u32;

u32 FIELD_SUBPROC_GetWork(const void *p)
{
    return ((struct Obj20098 *)p)->f10;
}
