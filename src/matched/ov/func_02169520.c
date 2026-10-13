/*
 * function: FIELD_G3D_MAP_GetActiveRef
 * address:  0x02169520
 * packet:   pkt_02169520
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj17744.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int FIELD_G3D_MAP_GetActiveRef(int a0, int a1)
{

a0 = a0 + 0xb0;
((struct Obj17744 *)((char *)a1))->f0 = a0;
    return a0;}
