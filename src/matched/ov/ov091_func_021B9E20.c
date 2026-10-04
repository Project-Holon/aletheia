/*
 * unit: yes
 * function: func_021B9E20, func_021B9E3C
 * address: 0x021B9E20
 * packet: pkt_ov091_021B9E20
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021B7B98 0x021B7B98 thumb ov091
 */
#include "../include/Obj00009.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021B7B98(u8 *);
void func_021B9E20(u8 *p) { func_021BB7A4(p,(u32 *)(*(u32 *)&((struct Obj00009 *)p)->f150)); p[12]=2; func_021B7B98(p); }
void func_021B9E3C(u8 *p) { p[12]=19; }
