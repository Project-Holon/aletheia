/*
 * function: func_021BE78C
 * address: 0x021BE78C
 * packet: pkt_ov204_021BE78C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * prototype: 0200854C widened to u32: original has no byte truncation; its u8 prototype added a shift pair.
 * symbols:
 *   func_0200854C 0x0200854C thumb
 */
#include "../include/Obj25366.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;
struct Sub0200852CObj;
extern void func_0200854C(struct Sub0200852CObj*,u32);
int func_021BE78C(u8*p,u32 unused,u32*q){struct Sub0200852CObj*obj=**(struct Sub0200852CObj** *)&((struct Obj25366 *)p)->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_0200854C(obj,flag);return 1;}
