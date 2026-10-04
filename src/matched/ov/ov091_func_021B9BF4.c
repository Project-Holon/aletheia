/*
 * function: func_021B9BF4
 * address: 0x021B9BF4
 * packet: pkt_ov091_021B9BF4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201B2B0 0x0201B2B0 thumb
 */
#include "../include/Obj00009.h"
#include "../include/Obj13241.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201B2B0(void *,void *,u32,u32,u8,u32 *,u16);
u32 func_021B9BF4(u8 *p, void *mon, u32 param) { u8 *s=*(u8 * *)&((struct Obj00009 *)p)->f280; return func_0201B2B0(((struct Obj13241 *)s)->f0,mon,3,param,s[0x5f],0,((struct Obj00009 *)p)->f0); }
