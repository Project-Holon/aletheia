/*
 * function: FLDMMDL_GetCheckInfo
 * address:  0x0216E1A4
 * packet:   pkt_0216E1A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 */
#include "../include/Obj09167.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 FLDMMDL_GetObjId(void *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern u16 FLDMMDL_GetZoneId(void *p);

int FLDMMDL_GetCheckInfo(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = FLDMMDL_GetObjId((void *)a0);
loc_0216E1AE:
((struct Obj09167 *)((char *)t4))->f0 = a0;
a0 = t5 + 0;
    a0 = FLDMMDL_GetObjCode((void *)a0);
loc_0216E1B6:
((struct Obj09167 *)t4)->f2 = a0;
a0 = t5 + 0;
    a0 = FLDMMDL_GetZoneId((void *)a0);
loc_0216E1BE:
((struct Obj09167 *)t4)->f4 = a0;
    return a0;}
