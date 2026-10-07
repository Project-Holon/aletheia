/*
 * function: func_021BA680
 * address: 0x021BA680
 * packet: pkt_ov218_021BA680
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 2 zero alignment bytes at 021BA6BA.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../../../matched/include/Obj03959.h"
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct Actor;struct Obj;typedef struct PtS{s16 x,y;} PtS;extern void func_0204B454(struct Actor *,PtS *,u32);extern void func_0204B404(struct Obj *,const PtS *,u32);
void func_021BA680(char *p,int v){PtS pos;s16 y;void *o;o=((struct Obj03959 *)p)->f2CC;y=(s16)v;if(y<16)y=16;else if(y>152)y=152;func_0204B454(o,&pos,0);pos.y=y;func_0204B404(o,&pos,0);}
