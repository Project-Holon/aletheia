/*
 * function: func_021CDF1C
 * address: 0x021CDF1C
 * packet: pkt_ov093_021CDF1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 * symbols:
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCommPos 0x021B86C0 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9920 0x021B9920 thumb ov093
 */
#include "../include/Obj04362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_MAIN_GetRule(void **);
extern u8 BTL_MAIN_GetCommPos(u8 **);
extern u32 func_021B9064(u8 *p, int k, int x);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
void *func_021CDF1C(u8 *p) { u8 side; if(BTL_MAIN_GetRule(*(void ** *)&((struct Obj04362 *)p)->f0)==0 && BTL_MAIN_GetCommPos(*(u8 ** *)&((struct Obj04362 *)p)->f0)==0) { side=func_021B9064(*(u8 * *)&((struct Obj04362 *)p)->f0,p[0x1a6],0); return func_021B9920(*(char * *)&((struct Obj04362 *)p)->f4,side,0); } return 0; }
