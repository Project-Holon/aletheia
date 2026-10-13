/*
 * function: FLDMMDL_InitMoveProcList
 * address:  0x0216D230
 * packet:   pkt_0216D230
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 20 compiled 18
 *
 * symbols:
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetMoveProcList  0x0216E400  thumb  ov010
 */
#include "../include/Obj17772.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 FLDMMDL_GetMoveCode(void *p);
extern u32 FLDMMDL_GetMoveProcList(int i);

int FLDMMDL_InitMoveProcList(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = FLDMMDL_GetMoveCode((void *)a0);
loc_0216D238:
    a0 = FLDMMDL_GetMoveProcList(a0);
loc_0216D23C:
t4 = t4 + 0x8c;
((struct Obj17772 *)((char *)t4))->f0 = a0;
    return a0;}
