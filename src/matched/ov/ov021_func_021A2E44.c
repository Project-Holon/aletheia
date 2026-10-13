/*
 * function: FIELDMAP_CTRL_GRID_SetBusy
 * address:  0x021A2E44
 * packet:   pkt_021A2E44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb
 */
#include "../include/Obj19761.h"

typedef unsigned int u32;

typedef unsigned char  u8;
u32 FIELDMAP_GetCtrlWork(u8 *p);

void FIELDMAP_CTRL_GRID_SetBusy(int a, u32 v)
{
    ((struct Obj19761 *)((char *)FIELDMAP_GetCtrlWork((u8 *)a)))->fC = v;
}
