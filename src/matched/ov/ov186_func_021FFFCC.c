/*
 * function: func_021FFFCC
 * address: 0x021FFFCC
 * packet: pkt_ov186_021FFFCC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 */
#include "../include/Obj14487.h"
#include "../include/Obj24878.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FC734(void *);
extern void func_020409B4(u32 index);
extern void func_021FBDA4(int,unsigned);
void func_021FFFCC(u8 *p) { int i; for(i=0;i<9;i++) { u8 *q=p+(u32)i*4; func_021FC734(((struct Obj14487 *)q)->f40); *(u32 *)&((struct Obj14487 *)q)->f40=0; } func_020409B4(4); func_021FBDA4(((struct Obj24878 *)p)->f28,20); }
