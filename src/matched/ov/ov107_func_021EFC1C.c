/*
 * function: MB_COMM_SYS_UpdateSaveState
 * address: 0x021EFC1C
 * packet: pkt_ov107_021EFC1C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding after the return.
 * symbols:
 *   func_0200C1A4 0x0200C1A4 thumb
 *   func_0200C1B0 0x0200C1B0 thumb
 */
#include "../include/Obj07994.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Blk34;
extern u8 func_0200C1A4(struct Blk34 *p);
extern void func_0200C1B0(struct Blk34 *p, u32 v);
void MB_COMM_SYS_UpdateSaveState(u8 *p,int mode) {
 unsigned cur; int change;
 if(p[40]==0) {
 cur=func_0200C1A4(((struct Obj07994 *)p)->f4C);change=0;
 switch(mode) {
 case 0: if(cur!=1&&cur!=3&&cur!=5) change=1;break;
 case 1: if(cur!=3&&cur!=5) change=1;break;
 case 2: if(cur!=0&&cur!=1&&cur!=3&&cur!=5) change=1;break;
 case 3: change=1;if(((struct Obj07994 *)p)->f3C!=0) mode=5;break;
 case 4: if(cur!=2&&cur!=0&&cur!=1&&cur!=3&&cur!=5) change=1;break;
 }
 if(change==1) func_0200C1B0(((struct Obj07994 *)p)->f4C,mode);
 }
}
