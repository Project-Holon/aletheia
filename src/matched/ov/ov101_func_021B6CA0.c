/*
 * unit: yes
 * function: func_021B6CA0, func_021B6CF8
 * address: 0x021B6CA0
 * packet: pkt_ov101_021B6CA0
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
#include "../include/Obj05268.h"
#include "../include/Obj22115.h"
#include "../include/Obj22116.h"
typedef unsigned short u16;
extern char d_021B753C[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(int,int,unsigned);
extern void func_020307B0(void *p);
int func_021B6CA0(unsigned a,int *p) {
 int q;
 q=(int)func_02030734(a,0x14,0,d_021B753C,0x36e);
 func_02082BCC(q,0,0x14);
 ((struct Obj05268 *)q)->f0=*(int *)p[4];
 ((struct Obj05268 *)q)->f4=p[0];
 ((struct Obj05268 *)q)->f10=p[15];
 if(p[13]==1) {
  ((struct Obj05268 *)q)->f8=0;
  p[13]=0;
 } else {
  if(p[14]!=0) {
   p[14]=0;
   ((struct Obj05268 *)q)->f8=2;
  } else ((struct Obj05268 *)q)->f8=1;
 }
 return q;
}
void func_021B6CF8(int p,int q) {
 ((struct Obj22116 *)q)->f20=((struct Obj22115 *)p)->fC;
 func_020307B0((void *)p);
}
