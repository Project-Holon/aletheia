/*
 * function: func_021FFE70
 * address: 0x021FFE70
 * packet: pkt_ov186_021FFE70
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022000D0 0x022000D0 thumb ov186
 *   func_021FFFCC 0x021FFFCC thumb ov186
 *   func_021FFF1C 0x021FFF1C thumb ov186
 */
#include "../include/Obj14486.h"
typedef unsigned char  u8;
extern void func_022000D0(u8 *p);
extern void func_021FFFCC(u8 *p);
extern void func_021FFF1C(char *);
void func_021FFE70(char *p) {((struct Obj14486 *)p)->f6C=0;if(((struct Obj14486 *)p)->f70==1)func_022000D0((u8 *)p);else func_021FFFCC((u8 *)p);func_021FFF1C(p);}
