/*
 * function: func_021BFD60
 * address: 0x021BFD60
 * packet: pkt_ov110_021BFD60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_021BF7EC 0x021BF7EC thumb ov110
 *   func_021BFDB0 0x021BFDB0 thumb ov110
 */
#include "../include/Obj13802.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021BC7DC(u8 *);
extern void func_021BF7EC(const u8 *,u16 *,u16 *);
extern void func_021BFDB0(u8 *,u32,u32);
int func_021BFD60(u8 *p) { u16 x,y; if(func_021BC7DC(p+0x6c)) { func_021BF7EC(*(const u8 * *)&((struct Obj13802 *)p)->f4,&x,&y); func_021BFDB0(p,x,y); return 1; } return 0; }
