/*
 * unit: no
 * function: func_0220E25C
 * address: 0x0220E25C
 * packet: pkt_ov198_0220E25C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220B094 0x0220B094 thumb ov196
 *   func_0220E27C 0x0220E27C thumb ov198
 */
#include "../include/Obj03351.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void func_0220B094(char *,u8 *);extern void func_0220E27C(u8 *);
void func_0220E25C(u8 *p){func_0220B094((char *)p+0x1f70,*(u8 * *)&((struct Obj03351 *)p)->f253C);func_0220E27C(p);}
