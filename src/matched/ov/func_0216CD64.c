/*
 * function: FLDMMDL_UpdateSysProc
 * address:  0x0216CD64
 * packet:   pkt_0216CD64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCB_Main  0x02030D28  arm
 *   FLDMMDL_BLACT_Update  0x0219C5FC  thumb
 */
#include "../include/Obj01464.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int TCB_Main();
extern int FLDMMDL_BLACT_Update();

int FLDMMDL_UpdateSysProc(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj01464 *)t4)->f20;
    a0 = TCB_Main(a0);
loc_0216CD6E:
a0 = t4 + 0;
    a0 = FLDMMDL_BLACT_Update(a0);
loc_0216CD74:
    return a0;}
