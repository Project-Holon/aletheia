/*
 * function: GURU2_MAIN_CreateWobbleEffectTask
 * address: 0x021E104C
 * packet: pkt_ov137_021E104C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   GURU2_MAIN_WobbleEffectTask 0x021E1028 thumb ov137
 */
#include "../include/Obj14245.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx; struct Node;
extern void MI_CpuFill8(void *,int,u32);
extern struct Node *func_02030DA8(struct Ctx *,u32,u32,u32);
extern void GURU2_MAIN_WobbleEffectTask(void *,char *);
void GURU2_MAIN_CreateWobbleEffectTask(char *p) { MI_CpuFill8(p+3068,0,120); *(struct Node * *)&((struct Obj14245 *)p)->fD84=func_02030DA8(*(struct Ctx * *)&((struct Obj14245 *)p)->fD98,(u32)GURU2_MAIN_WobbleEffectTask,(u32)p,258); }
