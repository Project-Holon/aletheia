/*
 * function: func_021BF680
 * address: 0x021BF680
 * packet: pkt_ov110_021BF680
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 */
#include "../include/Obj08007.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct T;
extern int PMSI_PARAM_IsComplete(struct T *p, u32 a1);
int func_021BF680(u8 *p) {
    switch(((struct Obj08007 *)p)->f4) {
    case 0: if(((struct Obj08007 *)p)->f10!=65535) return 1; else return 0;
    case 1: if(((struct Obj08007 *)p)->f10!=65535 && ((struct Obj08007 *)p)->f12!=65535) return 1; else return 0;
    case 2: return PMSI_PARAM_IsComplete((struct T *)(p+8),42);
    }
    return 0;
}
