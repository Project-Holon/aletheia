/*
 * function: func_021F4AC8
 * address: 0x021F4AC8
 * packet: pkt_ov112_021F4AC8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_0204EDD0 0x0204EDD0 arm
 */
#include "../include/Obj22515.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021F4F70(int *);
extern void func_0204EDD0(int,u16 *,u16 *);
void func_021F4AC8(u8 *p,u8 *a,u8 *b) { u16 x,y; func_0204EDD0(func_021F4F70(*(int * *)&((struct Obj22515 *)p)->f20),&x,&y); *a=(u32)x>>5; *b=(u32)y>>5; }
