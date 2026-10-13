/*
 * function: P_STA_SKILL_HideMovesPage
 * address: 0x021DA8BC
 * packet: pkt_ov131_021DA8BC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SKILL_HideSlot 0x021DB9FC thumb ov131
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02041570 0x02041570 arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj10521.h"
#include "../include/Obj10522.h"
typedef unsigned char u8;
extern void P_STA_SKILL_HideSlot(void *,void *,u8 *);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_020409B4(unsigned);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_02041570(int channel, u16 val);
extern void func_02041B6C(unsigned);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void P_STA_SKILL_HideMovesPage(u8 *a,u8 *b) {
    u8 i;
    for(i=0;i<b[43];i++) P_STA_SKILL_HideSlot(a,b,b+176+i*24);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    func_02041570(4,0);
    func_02041B6C(4);
    CLACT_SetActorDrawEnable(((struct Obj10522 *)b)->f90,0);
    CLACT_SetActorDrawEnable(((struct Obj10522 *)b)->f94,0);
    CLACT_SetActorDrawEnable(((struct Obj10521 *)a)->f198,0);
    CLACT_SetActorDrawEnable(((struct Obj10521 *)a)->f19C,0);
    CLACT_SetActorAnimSeq(((struct Obj10521 *)a)->f17C,1);
}
