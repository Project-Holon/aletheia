/*
 * function: BR_POKESEARCH_Destroy
 * address: 0x021FFC6C
 * packet: pkt_ov186_021FFC6C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 */
#include "../include/Obj06638.h"
struct PrintSys;extern void func_020307B0(void *);extern void PRINTSYS_QUE_Delete(struct PrintSys *);
void BR_POKESEARCH_Destroy(char *p) {if(((struct Obj06638 *)p)->f88){func_020307B0(((struct Obj06638 *)p)->f88);((struct Obj06638 *)p)->f88=0;}func_020307B0(((struct Obj06638 *)p)->f80);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj06638 *)p)->f3C);func_020307B0(p);}
