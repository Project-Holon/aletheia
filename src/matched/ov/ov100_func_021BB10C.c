/*
 * function: IRCBATTLEMATCH_IconAnimRight
 * address: 0x021BB10C
 * packet: pkt_ov100_021BB10C
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
#include "../include/Obj10220.h"
typedef unsigned short u16;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void IRCBATTLEMATCH_MoveActor(int a, int b, int c, int d);
extern void IRCBATTLEMATCH_CreateActor(int,int,int,int,int);
void IRCBATTLEMATCH_IconAnimRight(int a) {
 switch(CLACT_GetActorAnimSeq(((struct Obj10220 *)a)->f2D0)) {
 case 9:
  CLACT_SetActorAnimSeq(((struct Obj10220 *)a)->f2D0,10);
  IRCBATTLEMATCH_MoveActor(a,57,154,2);
  IRCBATTLEMATCH_CreateActor(a,128,77,5,3);
  return;
 case 10: break;
 default: CLACT_SetActorAnimSeq(((struct Obj10220 *)a)->f2D0,9); break;
 }
}
