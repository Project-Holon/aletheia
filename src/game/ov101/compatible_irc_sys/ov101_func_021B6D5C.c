/*
 * unit: yes
 * function: func_021B6D5C, func_021B6D90
 * address: 0x021B6D5C
 * packet: pkt_ov101_021B6D5C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * d_021B753C 0x021B753C data a1
 */
#include "../../../matched/include/Obj10228.h"
#include "../../../matched/include/Obj10229.h"
#include "../../../matched/include/Obj10230.h"
#include "../../../matched/include/Obj10231.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern char d_021B753C[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(int,int,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int func_021B6D5C(unsigned a,int p) {
 int q;
 q=(int)func_02030734(a,0x18,0,d_021B753C,0x3e4);
 func_02082BCC(q,0,0x18);
 ((struct Obj10229 *)q)->f0=**(int * *)&((struct Obj10228 *)p)->f10;
 ((struct Obj10229 *)q)->f4=((struct Obj10228 *)p)->f0;
 ((struct Obj10229 *)q)->f8=((struct Obj10228 *)p)->f3C;
 return q;
}
void func_021B6D90(int p,int q) {
 ((struct Obj10231 *)q)->f28=((struct Obj10230 *)p)->fC;
 ((struct Obj10231 *)q)->f2C=((struct Obj10230 *)p)->f10;
 ((struct Obj10231 *)q)->f2D=((struct Obj10230 *)p)->f14;
 func_020307B0((void *)p);
}
