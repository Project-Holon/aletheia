/*
 * function: func_021BA650
 * address: 0x021BA650
 * packet: pkt_ov213_021BA650
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj04630.h"
struct Obj;
extern int func_021B9E50(unsigned);extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v),CLACT_SetActorAutoAnim(void *,unsigned);
void func_021BA650(char *p){func_021B9E50(((struct Obj04630 *)p)->f26);if(((struct Obj04630 *)p)->f24==30){CLACT_SetActorDrawEnable(((struct Obj04630 *)p)->f10,1);CLACT_SetActorAutoAnim(((struct Obj04630 *)p)->f10,1);CLACT_SetActorDrawEnable(((struct Obj04630 *)p)->f14,1);CLACT_SetActorAutoAnim(((struct Obj04630 *)p)->f14,1);}(((struct Obj04630 *)p)->f24)++;}
