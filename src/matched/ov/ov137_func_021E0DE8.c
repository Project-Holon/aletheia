/*
 * function: GURU2_MAIN_CreateBounceEffectTask
 * address: 0x021E0DE8
 * packet: pkt_ov137_021E0DE8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   GURU2_MAIN_BounceEffectTask 0x021E0DC0 thumb ov137
 */
#include "../include/Obj14243.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx; struct Node;
extern void MI_CpuFill8(void *,int,u32);
extern struct Node *func_02030DA8(struct Ctx *,u32,u32,u32);
extern void GURU2_MAIN_BounceEffectTask(void *,char *);
void GURU2_MAIN_CreateBounceEffectTask(char *p) { MI_CpuFill8(p+2808,0,160); *(struct Node * *)&((struct Obj14243 *)p)->fD7C=func_02030DA8(*(struct Ctx * *)&((struct Obj14243 *)p)->fD98,(u32)GURU2_MAIN_BounceEffectTask,(u32)p,256); }
