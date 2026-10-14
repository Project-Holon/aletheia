/*
 * function: GURU2_MAIN_CreateSettleEffectTask
 * address: 0x021E0F20
 * packet: pkt_ov137_021E0F20
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   GURU2_MAIN_SettleEffectTask 0x021E0EFC thumb ov137
 */
#include "../include/Obj14244.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx; struct Node;
extern void MI_CpuFill8(void *,int,u32);
extern struct Node *func_02030DA8(struct Ctx *,u32,u32,u32);
extern void GURU2_MAIN_SettleEffectTask(void *,char *);
void GURU2_MAIN_CreateSettleEffectTask(char *p) { MI_CpuFill8(p+2968,0,100); *(struct Node * *)&((struct Obj14244 *)p)->fD80=func_02030DA8(*(struct Ctx * *)&((struct Obj14244 *)p)->fD98,(u32)GURU2_MAIN_SettleEffectTask,(u32)p,257); }
