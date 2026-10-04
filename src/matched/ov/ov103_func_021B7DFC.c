/*
 * function: func_021B7DFC
 * address: 0x021B7DFC
 * packet: pkt_ov103_021B7DFC
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Pointer prototypes and an element pointer retain the zero copied from the loop counter; 2-byte padding follows.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02046E24 0x02046E24 arm
 *   func_02046F50 0x02046F50 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_0204755C 0x0204755C arm
 *   func_02047564 0x02047564 arm
 *   func_0204767C 0x0204767C arm
 *   func_020477A4 0x020477A4 arm
 *   func_0206E5EC 0x0206E5EC arm
 *   func_0207ADC4 0x0207ADC4 arm
 */
#include "../include/Obj01708.h"
#include "../include/Obj10241.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_02082BCC(void *,int,int); extern void *func_02046E24(int,u16); extern int func_02046F50(void *,int); extern void func_02046FF8(void *); extern void *func_02047400(void *,unsigned,void *); extern int *func_0204755C(void *); extern void *func_02047564(void *,const void *,int); extern void *func_0204767C(void *,void *,int); extern void func_020477A4(void *,u16); extern void func_0206E5EC(int,int); extern void func_0207ADC4(void *);
void func_021B7DFC(u8 *p,int a,const u16 *t,int c) {int i,j; void *d=0; int *q; u8 *e; func_02082BCC(p,0,0x60); ((struct Obj01708 *)p)->f0=func_02046E24(a,t[0]); if(func_02046F50(((struct Obj01708 *)p)->f0,2)){d=((struct Obj01708 *)p)->f0; func_02046FF8(d);} if(func_02046F50(((struct Obj01708 *)p)->f0,1)) { i=0; ((struct Obj01708 *)p)->fC=func_02047400(((struct Obj01708 *)p)->f0,0,d); q=func_0204755C(((struct Obj01708 *)p)->fC); for(;i<2;i++) {e=p+i*4; ((struct Obj10241 *)e)->f4=func_02046E24(a,t[i+1]); ((struct Obj10241 *)e)->f14=func_02047564(((struct Obj01708 *)p)->fC,((struct Obj10241 *)e)->f4,0);} ((struct Obj01708 *)p)->f10=func_0204767C(((struct Obj01708 *)p)->fC,p+20,2); for(j=0;j<2;j++)func_020477A4(((struct Obj01708 *)p)->f10,j); func_0206E5EC(q[1],c); } func_0207ADC4(p+0x34); ((struct Obj01708 *)p)->f28=4096; ((struct Obj01708 *)p)->f2C=4096; ((struct Obj01708 *)p)->f30=4096; }
