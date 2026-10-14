/*
 * function: GURU2_COMM_RecvPartyData
 * address: 0x021DCBCC
 * packet: pkt_ov137_021DCBCC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_GetPartyCopy 0x021DCE00 thumb ov137
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj14205.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int GURU2_COMM_GetPartyCopy(char *,int);
extern void MI_CpuCopy8(void *,int,u32);
void GURU2_COMM_RecvPartyData(int i,int unused,void *q,char *p) {((struct Obj14205 *)p)->f46=((struct Obj14205 *)p)->f46|(s16)(1<<i);MI_CpuCopy8(q,GURU2_COMM_GetPartyCopy(p,i),1428);}
