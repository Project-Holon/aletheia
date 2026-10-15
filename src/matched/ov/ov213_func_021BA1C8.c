/*
 * function: COMM_BTL_DEMO_MAIN_SetRowActorAnim
 * address: 0x021BA1C8
 * packet: pkt_ov213_021BA1C8
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   COMM_BTL_DEMO_MAIN_TypeToFrame 0x021B9EB0 thumb ov213
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 */
#include "../include/Obj25696.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern int COMM_BTL_DEMO_MAIN_TypeToFrame(void *,u32);
struct Obj;
extern void CLACT_ChangeActorAnimSeq(struct Obj *p, u16 v);
void COMM_BTL_DEMO_MAIN_SetRowActorAnim(char *p,void *list,const u8 *flags,int index) {void *entry=0;int value;if(index<(int)POKEPARTY_GetCount(list))entry=POKEPARTY_GetMember(((struct Obj25696 *)p)->f0,index);value=COMM_BTL_DEMO_MAIN_TypeToFrame(entry,flags[index]);CLACT_ChangeActorAnimSeq((struct Obj *)(*(u32 *)(p+12+index*4)),value);}
