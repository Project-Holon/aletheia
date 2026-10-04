/*
 * function: func_021B8A88
 * address: 0x021B8A88
 * packet: pkt_ov104_021B8A88
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B7968 0x021B7968 thumb ov104
 *   func_021B8D08 0x021B8D08 thumb ov104
 */
#include "../include/Obj10248.h"
typedef unsigned char u8;
extern void func_02082BCC(void *,int,int);
extern int func_021B7968(u8 *p, int i);
extern void func_021B8D08(void *,void *,int);
void func_021B8A88(u8 *p,void *a,int b,int c,int d) {
 int i;
 func_02082BCC(p,0,0x534); ((struct Obj10248 *)p)->f528=b;
 ((struct Obj10248 *)p)->f52C=0; ((struct Obj10248 *)p)->f530=10;
 for(i=0;i<30;i++) func_021B8D08(p+i*0x2c,(void *)func_021B7968(a,c+i),d);
}
