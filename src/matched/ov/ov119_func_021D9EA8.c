/*
 * function: POKETRADE_PROC_SetDragTarget
 * address: 0x021D9EA8
 * packet: pkt_ov119_021D9EA8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 */
#include "../include/Obj00001.h"
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
void POKETRADE_PROC_SetDragTarget(char *p,int a,int b) {
 ((struct Obj00001 *)p)->fF74=a;
 ((struct Obj00001 *)p)->fF78=b;
 POKETRADE_PROC_RequestBoxRedraw(p);
}
