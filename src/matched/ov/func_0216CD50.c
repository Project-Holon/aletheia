/*
 * function: FLDMMDL_DeleteSysProc
 * address:  0x0216CD50
 * packet:   pkt_0216CD50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ACMD_DeleteDrawSys  0x02197C4C  thumb
 *   FLDMMDL_ReleaseSysProc  0x0216CD30  thumb  ov010
 */
#include "../include/Obj17770.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_ACMD_DeleteDrawSys();
extern int FLDMMDL_ReleaseSysProc();

int FLDMMDL_DeleteSysProc(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = FLDMMDL_ACMD_DeleteDrawSys(a0);
loc_0216CD58:
a0 = 0;
((struct Obj17770 *)t4)->f40 = a0;
a0 = t4 + 0;
    a0 = FLDMMDL_ReleaseSysProc(a0);
loc_0216CD62:
    return a0;}
