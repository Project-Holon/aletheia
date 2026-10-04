/*
 * function: func_021B8EB0
 * address: 0x021B8EB0
 * packet: pkt_ov104_021B8EB0
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B89DC 0x021B89DC thumb ov104
 */
#include "../include/Obj04434.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021B89DC(int,void *,int,int,u8,u16,u16);
void func_021B8EB0(u8 *p) {
 int a;
 if(((struct Obj04434 *)p)->fC && ((struct Obj04434 *)p)->f4) {
  a=((struct Obj04434 *)p)->f2+0x400;
  if(a>=0x10000) ((struct Obj04434 *)p)->f2=((struct Obj04434 *)p)->f2-0xfc00;
  else ((struct Obj04434 *)p)->f2=a;
  func_021B89DC(15,p,((struct Obj04434 *)p)->f2,5,3,0x6adf,0x55fe);
 }
}
