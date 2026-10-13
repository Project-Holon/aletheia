/*
 * function: FLDMMDL_SetDrawProcList
 * address:  0x0216E160
 * packet:   pkt_0216E160
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetDrawProcList  0x0216E40C  thumb  ov010
 */
#include "../include/Obj17853.h"
#include "../include/Obj17854.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetObjCodeParam(void *p);
extern u32 FLDMMDL_GetDrawProcList(int i);

int FLDMMDL_SetDrawProcList(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = FLDMMDL_GetObjCodeParam((void *)a0);
loc_0216E168:
a0 = ((struct Obj17854 *)p)->f3;
    a0 = FLDMMDL_GetDrawProcList(a0);
loc_0216E16E:
t4 = t4 + 0x90;
((struct Obj17853 *)((char *)t4))->f0 = a0;
    return a0;}
