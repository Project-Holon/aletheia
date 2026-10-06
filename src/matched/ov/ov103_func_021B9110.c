/*
 * function: func_021B9110
 * address: 0x021B9110
 * packet: pkt_ov103_021B9110
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B793C 0x021B793C thumb ov103
 *   func_021B9184 0x021B9184 thumb ov103
 */
#include "../include/Obj07985.h"
typedef unsigned char u8;
extern void func_02082BCC(void *,int,int);
extern int func_021B793C(u8 *p, int i);
struct Obj;
extern void func_021B9184(u8 *p, struct Obj *q, int v, u8 w);
void func_021B9110(u8 *p,void *q,int a,int b,int c,u8 d) {
 int i;
 func_02082BCC(p,0,0x590);
 ((struct Obj07985 *)p)->f580=a;((struct Obj07985 *)p)->f584=b;
 ((struct Obj07985 *)p)->f588=0;((struct Obj07985 *)p)->f58C=10;
 for(i=0;i<32;i++)func_021B9184(p+i*0x2c,(struct Obj *)func_021B793C(q,c+i),b,d);
}
