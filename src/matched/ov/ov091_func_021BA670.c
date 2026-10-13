/*
 * function: POKELIST_RemoveBagItem
 * address: 0x021BA670
 * packet: pkt_ov091_021BA670
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02007F1C 0x02007F1C thumb
 */
#include "../include/Obj00009.h"
#include "../include/Obj20871.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02007F1C(u8 *, u16, u16, u16);
u32 POKELIST_RemoveBagItem(u8 *p, u16 id) { return func_02007F1C(*(u8 * *)&((struct Obj20871 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4,id,1,((struct Obj00009 *)p)->f0); }
