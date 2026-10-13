/*
 * function: IRCBATTLEMATCH_IconAnimLeft
 * address: 0x021BB0C4
 * packet: pkt_ov100_021BB0C4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   IRCBATTLEMATCH_MoveActor 0x021B9800 thumb ov100
 *   IRCBATTLEMATCH_CreateActor 0x021B974C thumb ov100
 */
#include "../include/Obj10219.h"
typedef unsigned short u16;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void IRCBATTLEMATCH_MoveActor(int a, int b, int c, int d);
extern void IRCBATTLEMATCH_CreateActor(int,int,int,int,int);
void IRCBATTLEMATCH_IconAnimLeft(int a) {
 switch(CLACT_GetActorAnimSeq(((struct Obj10219 *)a)->f2C8)) {
 case 8:
  CLACT_SetActorAnimSeq(((struct Obj10219 *)a)->f2C8,11);
  IRCBATTLEMATCH_MoveActor(a,200,38,0);
  IRCBATTLEMATCH_CreateActor(a,128,113,4,2);
  return;
 case 11: break;
 default: CLACT_SetActorAnimSeq(((struct Obj10219 *)a)->f2C8,8); break;
 }
}
