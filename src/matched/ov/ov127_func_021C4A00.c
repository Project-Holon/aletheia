/*
 * function: WF2DMAP_OBJ_SetSlot
 * address:  0x021C4A00
 * packet:   pkt_021C4A00
 * region:   ov127
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj00535.h"

typedef unsigned char u8;
typedef unsigned short u16;

void WF2DMAP_OBJ_SetSlot(void *p, int i, int v)
{
    switch (i)
    {
    case 0:
        ((struct Obj00535 *)p)->f4 = (u16)v;
        break;
    case 1:
        ((struct Obj00535 *)p)->f6 = (u16)v;
        break;
    case 2:
        ((struct Obj00535 *)p)->f8 = (u16)v;
        break;
    case 3:
        ((struct Obj00535 *)p)->fA = (u16)v;
        break;
    case 4:
        ((struct Obj00535 *)p)->fC = (u16)v;
        break;
    case 5:
        ((struct Obj00535 *)p)->f15 = (u8)v;
        break;
    case 6:
        ((struct Obj00535 *)p)->f14 = (u8)v;
        break;
    case 7:
        ((struct Obj00535 *)p)->fE = (u16)v;
        break;
    case 8:
        ((struct Obj00535 *)p)->f10 = (u16)v;
        break;
    case 9:
        ((struct Obj00535 *)p)->f12 = (u16)v;
        break;
    case 10:
        ((struct Obj00535 *)p)->f16 = (u16)v;
        break;
    default:
        break;
    }
}
