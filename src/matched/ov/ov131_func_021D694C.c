/*
 * function: P_STA_SUB_DeleteObjects
 * address: 0x021D694C
 * packet: pkt_ov131_021D694C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj10507.h"
typedef unsigned char u8;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void P_STA_SUB_DeleteObjects(void *a,unsigned char *p) {
 u8 i;
 CLACT_DeleteActor(((struct Obj10507 *)p)->f48);
 CLACT_DeleteActor(((struct Obj10507 *)p)->f44);
 for(i=0;i<8;i++) CLACT_DeleteActor(*(void **)(p+0x24+i*4));
 CLACT_DeleteActor(((struct Obj10507 *)p)->f20);
}
