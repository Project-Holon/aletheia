/*
 * function: func_021B8CB0
 * address: 0x021B8CB0
 * packet: pkt_ov103_021B8CB0
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0206E0C4 0x0206E0C4 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_021B7F50 0x021B7F50 thumb ov103
 */
#include "../include/Obj04430.h"
typedef unsigned char u8;
typedef struct {int x,y,z;} Vec;
extern void func_0206E0C4(int,int,Vec *,Vec *);
extern void func_0207CA00(Vec *,Vec *,Vec *);
extern void func_0207CCA4(Vec *,Vec *);
extern void func_0207CEE4(int,Vec *,Vec *,Vec *);
struct V3;
extern void func_021B7F50(char *p, struct V3 *q);
void func_021B8CB0(u8 *p,int i,int x,int y) {
 Vec a,b,c;
 switch(i) {
 case 0:
  func_0206E0C4(x,y,&a,&b);func_0207CA00(&b,&a,&c);func_0207CCA4(&c,&c);func_0207CEE4(0x40000,&c,&a,&a);func_021B7F50(*(void **)(p+i*4),(struct V3 *)(&a));((struct Obj04430 *)p)->f8=x;((struct Obj04430 *)p)->fC=y;break;
 case 1:
  func_0206E0C4(((struct Obj04430 *)p)->f8+(x-((struct Obj04430 *)p)->f8)*2,((struct Obj04430 *)p)->fC+(y-((struct Obj04430 *)p)->fC)*2,&a,&b);func_0207CA00(&b,&a,&c);func_0207CCA4(&c,&c);func_0207CEE4(0x40000,&c,&a,&a);func_021B7F50(*(void **)(p+i*4),(struct V3 *)(&a));break;
 }
}
