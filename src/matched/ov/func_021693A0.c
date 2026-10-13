/*
 * function: FIELD_G3D_MAP_CloseArchive
 * address:  0x021693A0
 * packet:   pkt_021693A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj12053.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void ARC_TOOL_DeleteHandle(void *arc);

void FIELD_G3D_MAP_CloseArchive(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12053 *)t4)->f10;
    if (a0 == 0) goto loc_021693B2;
loc_021693AA:
    ARC_TOOL_DeleteHandle((void *)a0);
loc_021693AE:
a0 = 0;
((struct Obj12053 *)t4)->f10 = a0;
loc_021693B2:
    return;}
