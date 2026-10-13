/*
 * function: func_021C8A50
 * address: 0x021C8A50
 * packet: pkt_ov128_021C8A50
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C41BC 0x021C41BC thumb ov127
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj05380.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_021C41BC(u8 *p);
extern void CLACT_DeleteActor(struct Obj *p);
void func_021C8A50(char *p,int unused) {int i;char *q;for(i=0;i<8;i++) {q=p+i*4;if(((struct Obj05380 *)q)->fC){func_021C41BC(((struct Obj05380 *)q)->fC);*(u32 *)&((struct Obj05380 *)q)->fC=0;} if(((struct Obj05380 *)q)->f2C){CLACT_DeleteActor(((struct Obj05380 *)q)->f2C);*(u32 *)&((struct Obj05380 *)q)->f2C=0;}}}
