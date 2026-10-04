/*
 * function: func_021BE770
 * address: 0x021BE770
 * packet: pkt_ov204_021BE770
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020083EC 0x020083EC thumb
 */
#include "../include/Obj25363.h"
#include "../include/Obj25365.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;
extern void func_020083EC(u16*,u32);
int func_021BE770(u8*p,u32 unused,u32*q){u16*obj=*(u16* *)&((struct Obj25365 *)(*(u8* *)&((struct Obj25363 *)p)->f4))->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_020083EC(obj,flag);return 1;}
