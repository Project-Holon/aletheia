/*
 * function: func_021D5A7C
 * address: 0x021D5A7C
 * packet: pkt_ov123_021D5A7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 */
#include "../include/Obj04497.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
void func_021D5A7C(char *p){if(((struct Obj04497 *)p)->f7C){func_0202F038(((struct Obj04497 *)p)->f7C);((struct Obj04497 *)p)->f7C=0;}((struct Obj04497 *)p)->f7C=func_0202EE8C(((struct Obj04497 *)p)->f84,((struct Obj04497 *)p)->f44,15,16,((struct Obj04497 *)p)->fB0);}
