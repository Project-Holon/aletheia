/*
 * function: FLDMMDL_CheckCheckInfo
 * address:  0x0216E1C4
 * packet:   pkt_0216E1C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 */
#include "../include/Obj09168.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern u16 FLDMMDL_GetObjId(void *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern u16 FLDMMDL_GetZoneId(void *p);

int FLDMMDL_CheckCheckInfo(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a1 = 1;
t5 = a0 + 0;
t6 = 1;
    a0 = FLDMMDL_CheckStatusBit(a0, a1);
loc_0216E1D2:
    if (a0 == 0) goto loc_0216E1FE;
loc_0216E1D6:
a0 = t5 + 0;
    a0 = FLDMMDL_GetObjId((void *)a0);
loc_0216E1DC:
a1 = ((struct Obj09168 *)((char *)t4))->f0;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1E2:
a0 = t5 + 0;
    a0 = FLDMMDL_GetObjCode((void *)a0);
loc_0216E1E8:
a1 = ((struct Obj09168 *)t4)->f2;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1EE:
a0 = t5 + 0;
    a0 = FLDMMDL_GetZoneId((void *)a0);
loc_0216E1F4:
a1 = ((struct Obj09168 *)t4)->f4;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1FA:
a0 = t6 + 0;
    return a0;
loc_0216E1FE:
a0 = 0;
    return a0;}
