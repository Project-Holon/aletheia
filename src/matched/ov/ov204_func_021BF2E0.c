/*
 * function: INTRO_MSG_GetPrintState
 * address: 0x021BF2E0
 * packet: pkt_ov204_021BF2E0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 */
#include "../include/Obj25386.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
u32 INTRO_MSG_GetPrintState(u8*p){u32 a=((struct Obj25386 *)p)->f14;if(a==0){return 2;}else{return PRINTSYS_PrintStreamGetState((void *)a);}}
