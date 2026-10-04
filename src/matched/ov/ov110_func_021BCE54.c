/*
 * function: func_021BCE54
 * address: 0x021BCE54
 * packet: pkt_ov110_021BCE54
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCE6E.
 * symbols:
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BCFBC 0x021BCFBC thumb ov110
 */
#include "../include/Obj10278.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021BF6DC(u8 *);
extern void func_021BCFBC(char *,u32,int);
void func_021BCE54(char *p) { if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4)==1) func_021BCFBC(p,1,1); }
