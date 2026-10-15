/*
 * function: MYSTERY_StartScroll
 * address: 0x021D9254
 * packet: pkt_ov121_021D9254
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UpdateScrollA 0x021D928C thumb ov121
 *   MYSTERY_UpdateScrollB 0x021D933C thumb ov121
 */
#include "../include/Obj05354.h"
typedef unsigned char  u8;
extern void MYSTERY_UpdateScrollA(u8 *p);
extern void MYSTERY_UpdateScrollB(u8 *p);
void MYSTERY_StartScroll(char *p,int n) {
 ((struct Obj05354 *)p)->f0=1;
 ((struct Obj05354 *)p)->f8=0;
 ((struct Obj05354 *)p)->f14=((struct Obj05354 *)p)->f10;
 switch(n) {case 0: ((struct Obj05354 *)p)->f11C=(unsigned)MYSTERY_UpdateScrollA;break;case 1:((struct Obj05354 *)p)->f11C=(unsigned)MYSTERY_UpdateScrollB;break;}
}
