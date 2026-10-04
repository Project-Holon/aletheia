/*
 * unit: yes
 * function: func_021BAA0C, func_021BAA30
 * address: 0x021BAA0C
 * packet: pkt_ov110_021BAA0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCFBC 0x021BCFBC thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj22334.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_021BF71C(u8 *);
extern void func_021BCFBC(u8 *,u8,int);
extern void func_021B9CBC(u8 *);
void func_021BAA0C(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj00135 *)p)->f0; func_021BCFBC(*(u8 * *)&((struct Obj22334 *)q)->f64,func_021BF71C(*(u8 * *)&((struct Obj00135 *)p)->f4),1); func_021B9CBC(p); }
void func_021BAA30(int a,u8 *p) { func_021B9CBC(p); }
