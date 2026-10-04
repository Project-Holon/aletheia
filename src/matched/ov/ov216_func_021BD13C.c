/*
 * function: func_021BD13C
 * address: 0x021BD13C
 * packet: pkt_ov216_021BD13C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * prototype: 021BCE8C coordinate parameters are signed short: original uses asrs #16 before each call; same-overlay matched caller 021BD448 declares s16.
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_021BCE8C 0x021BCE8C thumb ov216
 */
#include "../include/Obj10948.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02040618(u32,u32,u32);
extern void func_021BCE8C(void*,short,short,int);
void func_021BD13C(u8*p,int a){func_02040618(p[0x7e],3,-a);func_021BCE8C(*(void* *)&((struct Obj10948 *)p)->f78,220,a+44,1);func_021BCE8C(*(void* *)&((struct Obj10948 *)p)->f74,200,a+80,1);}
