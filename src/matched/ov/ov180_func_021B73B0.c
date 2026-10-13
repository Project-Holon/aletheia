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
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 */
#include "../include/Obj10720.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Obj;
extern u32 CLACT_GetActorAutoAnim(struct Obj *p);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void CLACT_DrawSystem(void);
void func_021B73B0(char *p){u32 i;char *q;for(i=0;i<33;i++){q=p+i*4;if(((struct Obj10720 *)q)->f9048&&CLACT_GetActorAutoAnim(((struct Obj10720 *)q)->f9048)!=1)CLACT_AddActorAnimFrame(((struct Obj10720 *)q)->f9048,4096);}CLACT_DrawSystem();}
