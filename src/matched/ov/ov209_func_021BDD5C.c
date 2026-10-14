/*
 * function: ZUKAN_LIST_DeleteActorUnit
 * address: 0x021BDD5C
 * packet: pkt_ov209_021BDD5C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_DeleteActor 0x021BDD40 thumb ov209
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj25575.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; extern void ZUKAN_LIST_DeleteActor(char *,u32);extern void CLACT_DeleteUnit(struct Bank *);
void ZUKAN_LIST_DeleteActorUnit(char *p) {u32 i;for(i=0;i<60;i++) ZUKAN_LIST_DeleteActor(p,i);CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25575 *)p)->fA70);}
