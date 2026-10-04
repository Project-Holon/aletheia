/*
 * function: func_021D7374
 * address: 0x021D7374
 * packet: pkt_ov120_021D7374
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021D72E8 0x021D72E8 thumb ov120
 */
#include "../include/Obj10400.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Pt { s16 x,y; } Pt;
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, unsigned int space);
extern void func_0204B404(void *,const Pt *,u32);
extern int func_021D72E8(void *,int,int);
int func_021D7374(char *p,int y,int count) { Pt pt; int result; result=0; if(((struct Obj10400 *)p)->f140) { func_0204B454(((struct Obj10400 *)p)->f140,(struct PtS *)&pt,1); pt.y=y; func_0204B404(((struct Obj10400 *)p)->f140,&pt,1); result=func_021D72E8(p,y,count); } return result; }
