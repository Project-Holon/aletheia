/*
 * function: func_021B73B0
 * address: 0x021B73B0
 * packet: pkt_ov180_021B73B0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 */
#include "../include/Obj10720.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Obj;
extern u32 func_0204B944(struct Obj *p);
extern void func_0204B8D4(struct Obj *p, u32 arg);
extern void func_0204A600(void);
void func_021B73B0(char *p){u32 i;char *q;for(i=0;i<33;i++){q=p+i*4;if(((struct Obj10720 *)q)->f9048&&func_0204B944(((struct Obj10720 *)q)->f9048)!=1)func_0204B8D4(((struct Obj10720 *)q)->f9048,4096);}func_0204A600();}
