/*
 * function: FLDMMDL_MOVE_CanShowShadow
 * address:  0x021636A8
 * packet:   pkt_021636A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysIsDrawEnable  0x0216D98C  thumb  ov010
 */
#include "../include/Obj00113.h"
#include "../include/Obj17718.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysIsDrawEnable(int a0);

int FLDMMDL_MOVE_CanShowShadow(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
    a0 = (int)FLDMMDL_GetMmdlSys((void *)a0);
loc_021636B0:
    a0 = FLDMMDL_SysIsDrawEnable(a0);
loc_021636B4:
    if (a0 == 0) goto loc_021636C0;
loc_021636B8:
a0 = ((struct Obj17718 *)t4)->f10;
a0 = *(u8 *)&((struct Obj00113 *)a0)->f4;
    if (a0 != 0) goto loc_021636C4;
loc_021636C0:
a0 = 0;
    return a0;
loc_021636C4:
a0 = 1;
    return a0;}
