/*
 * function: func_021D9254
 * address: 0x021D9254
 * packet: pkt_ov121_021D9254
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D928C 0x021D928C thumb ov121
 *   func_021D933C 0x021D933C thumb ov121
 */
#include "../include/Obj05354.h"
typedef unsigned char  u8;
extern void func_021D928C(u8 *p);
extern void func_021D933C(u8 *p);
void func_021D9254(char *p,int n) {
 ((struct Obj05354 *)p)->f0=1;
 ((struct Obj05354 *)p)->f8=0;
 ((struct Obj05354 *)p)->f14=((struct Obj05354 *)p)->f10;
 switch(n) {case 0: ((struct Obj05354 *)p)->f11C=(unsigned)func_021D928C;break;case 1:((struct Obj05354 *)p)->f11C=(unsigned)func_021D933C;break;}
}
