/*
 * function: func_021C93C0
 * address: 0x021C93C0
 * packet: pkt_ov128_021C93C0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_021C9D88 0x021C9D88 thumb ov128
 *   func_021C6E18 0x021C6E18 thumb ov128
 */
#include "../include/Obj08131.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_020061E4(u32 a);
extern void func_021CA3A0(char *p);
extern void func_021CA3C4(char *p);
extern int func_021C9D88(u8 *p, int direction);
extern void func_021C6E18(u8 *p, int i, u16 a);
int func_021C93C0(char *p,void *q,void *r,int n) {
 switch(n) {
 case 0:func_020061E4(0x551);func_021CA3A0(r);return 7;
 case 1:func_020061E4(0x556);func_021CA3C4(r);return 8;
 case 2:if(func_021C9D88(q,0)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=0;func_021C6E18(r,1,11);return 6;}break;
 case 3:if(func_021C9D88(q,1)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=1;func_021C6E18(r,0,10);return 6;}break;
 }
 return 2;
}
