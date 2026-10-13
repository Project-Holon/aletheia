/*
 * function: IRC_COMPATIBLE_StepRunnerInit
 * address: 0x021B6BE4
 * packet: pkt_ov101_021B6BE4
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 */
#include "../include/Obj22112.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,u32);
extern void *PROCSYS_Create(int);
void IRC_COMPATIBLE_StepRunnerInit(u8 *p,int heap) { MI_CpuFill8(p,0,12); ((struct Obj22112 *)p)->f0=PROCSYS_Create(heap); }
