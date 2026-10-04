/*
 * function: func_021BEEF0
 * address: 0x021BEEF0
 * packet: pkt_ov204_021BEEF0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02008550 0x02008550 thumb
 */
#include "../include/Obj25378.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj*);
int func_021BEEF0(u8*p){if(!func_02008550(**(struct Sub0200852CObj** *)&((struct Obj25378 *)p)->f4))return 1;return 0;}
