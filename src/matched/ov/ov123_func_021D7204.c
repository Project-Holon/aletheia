/*
 * function: func_021D7204
 * address: 0x021D7204
 * packet: pkt_ov123_021D7204
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D63D4 0x021D63D4 thumb ov123
 */
#include "../include/Obj10444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D62BC(u8 *,int,u32);
extern void func_021D62B4(char *,int);
extern void func_021D63D4(u8 *);
void func_021D7204(u8 *p) { func_021D62BC(*(u8 * *)&((struct Obj10444 *)p)->f14,0,0); func_021D62B4(*(char * *)&((struct Obj10444 *)p)->f14,12); func_021D63D4(*(u8 * *)&((struct Obj10444 *)p)->f14); }
