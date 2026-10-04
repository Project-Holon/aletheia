/*
 * function: func_021FF67C
 * address: 0x021FF67C
 * packet: pkt_ov186_021FF67C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D73E0 0x021D73E0 thumb ov125
 */
#include "../include/Obj24858.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern unsigned long long func_021D73E0(void);
u32 func_021FF67C(u8*p,unsigned long long*out){u32 present;present=((struct Obj24858 *)p)->f5C0;if(present)*out=func_021D73E0();return present;}
