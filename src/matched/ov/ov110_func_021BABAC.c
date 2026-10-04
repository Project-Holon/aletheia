/*
 * function: func_021BABAC
 * address: 0x021BABAC
 * packet: pkt_ov110_021BABAC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF784 0x021BF784 thumb ov110
 *   func_021C00AC 0x021C00AC thumb ov110
 *   func_021C00FC 0x021C00FC thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj10271.h"
#include "../include/Obj10272.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021BF784(u8 *);
extern void func_021C00AC(u8 *,unsigned);
extern int func_021C00FC(u8 *);
extern void func_021B9CBC(u8 *);
void func_021BABAC(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj10271 *)p)->f0; switch(((struct Obj10271 *)p)->f14) { case 0: func_021C00AC(*(u8 * *)&((struct Obj10272 *)q)->f5C,func_021BF784(*(u8 * *)&((struct Obj10272 *)q)->f18)); (((struct Obj10271 *)p)->f14)++; break; case 1: if(func_021C00FC(*(u8 * *)&((struct Obj10272 *)q)->f5C)) func_021B9CBC(p); break; } }
