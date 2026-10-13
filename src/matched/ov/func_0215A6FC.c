/*
 * function: SCRCMD_WORK_CheckAnimeTasks
 * address:  0x0215A6FC
 * packet:   pkt_0215A6FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb
 */
#include "../include/Obj05852.h"
#include "../include/Obj17665.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_ACMD_ListCheckEnd();
extern int FLDMMDL_ACMD_ListDelete();

u32 SCRCMD_WORK_CheckAnimeTasks(u32 a0, u32 a1, u32 a2, u32 a3)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t7 = 0;
t4 = 0;
loc_0215A704:
a0 = ((struct Obj05852 *)t5)->f20;
t6 = t4 << 2;
a0 = a0 + t6;
a0 = ((struct Obj05852 *)a0)->f14;
    if (a0 == 0) goto loc_0215A72E;
loc_0215A710:
    a0 = FLDMMDL_ACMD_ListCheckEnd(a0);
loc_0215A714:
    if (a0 != 1) goto loc_0215A72C;
loc_0215A718:
a0 = ((struct Obj05852 *)t5)->f20;
a0 = a0 + t6;
a0 = ((struct Obj05852 *)a0)->f14;
    a0 = FLDMMDL_ACMD_ListDelete(a0);
loc_0215A722:
a0 = ((struct Obj05852 *)t5)->f20;
a1 = a0 + t6;
a0 = 0;
((struct Obj17665 *)a1)->f14 = a0;
    goto loc_0215A72E;
loc_0215A72C:
t7 = 1;
loc_0215A72E:
t4 = t4 + 1;
    if (t4 < 8) goto loc_0215A704;
loc_0215A734:
a0 = t7 + 0;
    return a0;}
