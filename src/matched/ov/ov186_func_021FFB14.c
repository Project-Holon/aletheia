/*
 * function: BR_NET_CreateTask
 * address: 0x021FFB14
 * packet: pkt_ov186_021FFB14
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_NET_SetStep 0x021FFB68 thumb ov186
 *   gBrNetSourceFile 0x02200D8C data a1
 */
#include "../include/Obj24873.h"
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);extern void MI_CpuFill8(void *,int,unsigned);extern void BR_NET_SetStep(char *,int);extern const char gBrNetSourceFile[];
char *BR_NET_CreateTask(void *p,int f,unsigned heap) {char *q=func_02030734(heap,16,0,gBrNetSourceFile,0x44f);MI_CpuFill8(q,0,16);((struct Obj24873 *)q)->f8=p;BR_NET_SetStep(q,f);return q;}
