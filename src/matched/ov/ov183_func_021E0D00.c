/*
 * function: func_021E0D00
 * address: 0x021E0D00
 * packet: pkt_ov183_021E0D00
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj02895.h"
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *,struct PtS *,unsigned int);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021E0D00(char *p,int i){short pos[2];void *obj;obj=*(void **)(p+i*28+12);((struct Obj02895 *)p)->f188=i;func_0204B454(obj,(struct PtS *)pos,1);pos[1]+=16;func_0204B404(((struct Obj02895 *)p)->f194,(const struct Vec2 *)pos,1);}
