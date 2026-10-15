/*
 * function: STA_ACTING_CreateActObj
 * address: 0x021F8E58
 * packet: pkt_ov132_021F8E58
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_OBJ_Create 0x021F69E4 thumb ov112
 */
#include "../include/Obj10530.h"
typedef unsigned short u16;typedef unsigned int u32;
typedef struct Object Object;
extern Object *STA_ACT_OBJ_Create(u16,void *);
void STA_ACTING_CreateActObj(char *p){int tmp[3]={0};int i;for(i=0;i<5;i++)*(int *)((u32)p+i*4+0x58)=0;*(Object * *)&((struct Obj10530 *)p)->f54=STA_ACT_OBJ_Create(((struct Obj10530 *)p)->f0,((struct Obj10530 *)p)->fAC);}
