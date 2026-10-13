/*
 * function: func_021BA60C
 * address: 0x021BA60C
 * packet: pkt_ov091_021BA60C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NATSUKI_Calc 0x0201B7A0 thumb
 */
#include "../include/Obj00009.h"
#include "../include/Obj20869.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void NATSUKI_Calc(void *, int, int, int);
void func_021BA60C(u8 *p, void *q) { NATSUKI_Calc(q,7,((struct Obj20869 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f30,((struct Obj00009 *)p)->f0); }
