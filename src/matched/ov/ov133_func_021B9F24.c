/*
 * function: func_021B9F24
 * address: 0x021B9F24
 * packet: pkt_ov133_021B9F24
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj14154.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_021B9F24(unsigned char *p) {unsigned char i;for(i=0;i<8;i++)CLACT_DeleteActor(*(void **)((unsigned int)p+(unsigned int)i*4+0x1890));CLACT_DeleteActor(((struct Obj14154 *)p)->f18B4);CLACT_DeleteActor(((struct Obj14154 *)p)->f18B0);}
