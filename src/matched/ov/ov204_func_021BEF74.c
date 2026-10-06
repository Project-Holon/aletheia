/*
 * function: func_021BEF74
 * address: 0x021BEF74
 * packet: pkt_ov204_021BEF74
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF1A4 0x021BF1A4 thumb ov204
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25382.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BF1A4(char*);
extern u32 func_020307B0(void *p);
void func_021BEF74(u8*p){func_021BF1A4(*(char* *)&((struct Obj25382 *)p)->f18);func_020307B0(p);}
