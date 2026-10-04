/*
 * function: func_021BA65C
 * address: 0x021BA65C
 * packet: pkt_ov091_021BA65C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007FB8 0x02007FB8 thumb
 */
#include "../include/Obj00009.h"
#include "../include/Obj20870.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02007FB8(u8 *, u16, u16);
u32 func_021BA65C(u8 *p, u16 id) { return func_02007FB8(*(u8 * *)&((struct Obj20870 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4, id, ((struct Obj00009 *)p)->f0); }
