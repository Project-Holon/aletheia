/*
 * function: func_021ED058
 * address: 0x021ED058
 * packet: pkt_ov170_021ED058
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj02214.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned,u16);
extern unsigned func_02020E60(unsigned,unsigned);
typedef signed int     s32;
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern void func_02049238(void*);
void func_021ED058(u8*p){void*h;h=func_020490F4(25,76);*(void* *)&((struct Obj02214 *)p)->fA114=(void *)func_0204ABF0(h,func_02020E60(0,2),0,0x180,76);func_02049238(h);}
